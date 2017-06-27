#ifndef __STRINGCOLUMN_H__
#define __STRINGCOLUMN_H__

#include <iostream>
#include <string>
#include <vector>

#include "column.h"

class StringColumn : public Column {
	private:
		std::vector<std::string> data;
	public:
		StringColumn(const std::string & name, std::string && type) 
			: Column(name,std::forward<std::string>(type)) { }
		StringColumn(std::string && name, std::string && type) 
			: Column(std::forward<std::string>(name),std::forward<std::string>(type)) {}
		StringColumn(const StringColumn & col) : Column(col), data(col.data.begin(), col.data.end()) {}
		std::ostream & print(std::ostream &) const;
		std::ostream & print(std::ostream &, ushort) const;
		void push_back(std::string && value);
		ushort size(void) const { return data.size(); }
		void read_column(std::istream &);
};

#endif