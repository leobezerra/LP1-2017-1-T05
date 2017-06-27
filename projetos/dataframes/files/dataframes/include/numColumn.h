#ifndef __NUMCOLUMN_H__
#define __NUMCOLUMN_H__

#include <iostream>
#include <string>
#include <vector>

#include "column.h"

class NumColumn : public Column {
	private:
		std::vector<float> data;
	public:
		NumColumn(const std::string & name, std::string && type) 
			: Column(name,std::forward<std::string>(type)) { }
		NumColumn(std::string && name, std::string && type) 
			: Column(std::forward<std::string>(name),std::forward<std::string>(type)) { }
		NumColumn(const NumColumn & col) : Column(col), data(col.data.begin(), col.data.end()) {}
		std::ostream & print(std::ostream &) const;
		std::ostream & print(std::ostream &, ushort) const;
		void push_back(std::string &&);
		ushort size(void) const { return data.size(); }
		void read_column(std::istream &);
};

#endif