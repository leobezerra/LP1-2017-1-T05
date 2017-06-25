#include <iostream>
#include <string>

#include "numColumn.h"

NumColumn::NumColumn(const std::string & value) { 
	data.push_back(std::stof(value)); 
}
std::ostream & NumColumn::print(std::ostream & out) const {
	for (ushort i = 0; i < data.size(); i++)
		out << data[i];
	return out;
}
std::ostream & NumColumn::print(std::ostream & out, ushort idx) const {
	out << data[idx];
	return out;
}
void NumColumn::push_back(std::string & value) { 
	data.push_back(std::stof(value)); 
}