#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <cassert>

#include "stringColumn.h"

StringColumn::StringColumn(std::string & value) { 
	if (value.size() == 2)
		data.push_back("");
	else
		data.push_back(value.substr(1,value.size()-2)); 
}
std::ostream & StringColumn::print(std::ostream & out) const {
	for (ushort i = 0; i < data.size(); i++)
		out << "\"" << data[i] << "\"";
	return out;
}
std::ostream & StringColumn::print(std::ostream & out, ushort idx) const {
	out << "\"" << data[idx] << "\"";
	return out;
}
void StringColumn::push_back(std::string & value) { 
	if (value.size() == 2)
		data.push_back("");
	else
		data.push_back(value.substr(1,value.size()-2)); 
}