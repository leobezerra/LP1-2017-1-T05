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
		NumColumn(const std::string &);
		std::ostream & print(std::ostream &) const;
		std::ostream & print(std::ostream &, ushort) const;
		void push_back(std::string &);
		ushort size(void) { return data.size(); }
};

#endif