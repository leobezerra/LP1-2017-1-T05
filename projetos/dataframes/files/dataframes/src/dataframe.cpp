#include <iostream>
#include <fstream>
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
	while (std::getline(header_buffer,field,';')) df.header.push_back(std::move(field));
	df.ncols = df.header.size();

	std::getline(in, buffer);
	std::istringstream line(buffer);
	for (ushort i = 0; std::getline(line,field,';'); i++) {
		bool is_string = field[0] == '\"';
		if (is_string) {
			std::string remaining;
			while (field.back() != '\"') {
				std::getline(line,remaining,';');
				field += remaining; 
			}
		}
		std::unique_ptr<Column> col;
		if (is_string) 
			col = std::unique_ptr<Column>(new StringColumn(df.header[i],"string"));
		else
			col = std::unique_ptr<Column>(new NumColumn(df.header[i],"numeric"));
		col->push_back(std::move(field));
		df.cols.insert(std::make_pair(df.header[i],std::move(col)));
	}

	for (df.nrows = 1; std::getline(in, buffer); df.nrows++) {
		if (in.eof()) break;
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
			const std::string & field_type = df.cols[df.header[i]]->getType();
			assert((field_type == "string" && is_string) || (field_type == "numeric" && !is_string));
			df.cols[df.header[i]]->push_back(std::move(field));
		}
	}
	return in;
}

std::ostream & operator<< (std::ostream & out, const DataFrame & df) {
	df.print(out);
	return out;
}

void DataFrame::print(std::ostream & out, char sep) const {
	for (ushort i = 0; i < header.size(); i++) {
		out << header[i];
		if (i+1 != ncols) out << sep;
	}
	out << std::endl;
	for (ushort i = 0; i < nrows; i++) {
		for (ushort j = 0; j < ncols; j++) {
			cols.at(getColName(j))->print(out, i);
			if (j+1 != ncols) out << sep;
		}
		out << std::endl;
	}
}

void DataFrame::persist(const std::string & fname) const {
	std::ofstream out(fname);
	print(out,';');
}
