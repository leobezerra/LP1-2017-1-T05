#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <string>

#include "stringColumn.h"

std::ostream & StringColumn::print(std::ostream & out) const {
	for (ushort i = 0; i < data.size(); i++)
		out << "\"" << data[i] << "\"" << std::endl;
	return out;
}

std::ostream & StringColumn::print(std::ostream & out, ushort idx) const {
	out << "\"" << data[idx] << "\"";
	return out;
}

void StringColumn::push_back(std::string && value) { 
	if (value.size() == 2)
		data.push_back("");
	else
		data.push_back(value.substr(1,value.size()-2)); 
}

void StringColumn::read_column(std::istream & in) {
	std::string buffer, field;
	for (ushort rows = 0; std::getline(in, buffer); rows++) {
		std::istringstream line(buffer);
		for (ushort i = 0; std::getline(line,field,';'); i++) {
			assert(field[0] == '\"');
			push_back(std::move(field));
		}
	}
}