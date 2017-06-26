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
		StringColumn(ColumnTraits && traits) : Column(std::forward<ColumnTraits>(traits)) { }
		std::ostream & print(std::ostream &) const;
		std::ostream & print(std::ostream &, ushort) const;
		void push_back(std::string && value);
		ushort size(void) const { return data.size(); }
		void read_column(std::istream &);
};

#endif