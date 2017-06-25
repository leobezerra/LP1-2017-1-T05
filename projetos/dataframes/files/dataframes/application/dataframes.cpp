#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <cassert>

typedef unsigned short int ushort;

#include "column.h"
#include "stringColumn.h"
#include "numColumn.h"
#include "columnTraits.h"

int main (int argc, char * argv[]) {
	std::string buffer;
	std::getline(std::cin, buffer);

	std::vector<ColumnTraits> header;
	std::string field;
	std::istringstream header_buffer(buffer);
	while (std::getline(header_buffer,field,';')) header.push_back(ColumnTraits(field));
	ushort ncols = header.size();

	for (ushort i = 0; i < header.size(); i++) {
		std::cout << header[i];
		if (i+1 != header.size()) std::cout << ';';
	}
	std::cout << std::endl;

	std::getline(std::cin, buffer);
	std::istringstream line(buffer);
	std::vector<std::unique_ptr<Column>> cols;
	for (ushort i = 0; std::getline(line,field,';'); i++) {
		bool is_string = field[0] == '\"';
		header[i].setType(is_string ? "string" : "numeric");
		if (is_string) {
			std::string remaining;
			while (field.back() != '\"') {
				std::getline(line,remaining,';');
				field += remaining; 
			}
		}
		std::unique_ptr<Column> col;
		if (is_string)
			col = std::unique_ptr<Column>(new StringColumn(field));
		else
			col = std::unique_ptr<Column>(new NumColumn(field));
		cols.push_back(std::move(col));
	}

	ushort nrows;
	for (nrows = 1; std::getline(std::cin, buffer); nrows++) {
		std::istringstream line(buffer);
		for (ushort i = 0; std::getline(line,field,';'); i++) {
			bool is_string = field[0] == '\"';
			if (is_string) {
				std::string remaining;
				while (field.back() != '\"') {
					std::getline(line,remaining,';');
					field += ";" + remaining; 
				}
			}
			const std::string & field_type = header[i].getType();
			assert((field_type == "string" && is_string) || (field_type == "numeric" && !is_string));
			cols[i]->push_back(field);
		}
	}

	for (ushort i = 0; i < nrows; i++) {
		for (ushort j = 0; j < cols.size(); j++) {
			cols[j]->print(std::cout, i);
			if (j+1 != cols.size()) std::cout << ";";
		}
		std::cout << std::endl;
	}
}