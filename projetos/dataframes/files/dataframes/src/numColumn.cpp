#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <string>

#include "numColumn.h"

std::ostream & NumColumn::print(std::ostream & out) const {
	for (ushort i = 0; i < data.size(); i++)
		out << data[i];
	return out;
}

std::ostream & NumColumn::print(std::ostream & out, ushort idx) const {
	out << data[idx];
	return out;
}

void NumColumn::push_back(std::string && value) { 
	data.push_back(std::stof(value)); 
}

void NumColumn::read_column(std::istream & in) {
	std::string buffer, field;
	for (ushort rows = 0; std::getline(in, buffer); rows++) {
		std::istringstream line(buffer);
		for (ushort i = 0; std::getline(line,field,';'); i++) {
			assert(field[0] != '\"');
			push_back(std::move(field));
		}
	}
}
