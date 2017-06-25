#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <cassert>

#include "dataframe.h"

std::istream & operator>> (std::istream & in, DataFrame & df) {
	std::string buffer;
	std::getline(in, buffer);

	std::string field;
	std::istringstream header_buffer(buffer);
	while (std::getline(header_buffer,field,';')) df.header.push_back(ColumnTraits(field));
	df.ncols = df.header.size();

	for (ushort i = 0; i < df.header.size(); i++) {
		std::cout << df.header[i];
		if (i+1 != df.ncols) std::cout << ';';
	}
	std::cout << std::endl;

	std::getline(in, buffer);
	std::istringstream line(buffer);
	for (ushort i = 0; std::getline(line,field,';'); i++) {
		bool is_string = field[0] == '\"';
		df.header[i].setType(is_string ? "string" : "numeric");
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
		df.cols.insert(std::make_pair(df.header[i].getName(),std::move(col)));
	}

	for (df.nrows = 1; std::getline(in, buffer); df.nrows++) {
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
			const std::string & field_type = df.header[i].getType();
			assert((field_type == "string" && is_string) || (field_type == "numeric" && !is_string));
			df.cols[df.header[i].getName()]->push_back(field);
		}
	}
	return in;
}

std::ostream & operator<< (std::ostream & out, const DataFrame & df) {
	for (ushort i = 0; i < df.nrows; i++) {
		for (ushort j = 0; j < df.ncols; j++) {
			df.cols.at(df.getColName(j))->print(std::cout, i);
			if (j+1 != df.ncols) out << ";";
		}
		out << std::endl;
	}
	return out;
}
