#include <iostream>
#include <fstream>
#include <memory>

#include "column.h"
#include "stringColumn.h"
#include "numColumn.h"

std::ostream & operator<< (std::ostream & out, const Column & col) {
	return col.print(out);
}

std::unique_ptr<Column> make_column(const std::string & fname) {
	std::ifstream in(fname);
	std::string tmp;
	std::getline(in, tmp);
	std::string colname(tmp.substr(1,tmp.size()-2));
	
 	bool is_string = (in.peek() == '\"');
	std::unique_ptr<Column> col;
	if (is_string)
		col = std::unique_ptr<Column>(new StringColumn(std::move(colname),"string"));
	else
		col = std::unique_ptr<Column>(new NumColumn(std::move(colname),"numeric"));
	col->read_column(in);
	return col;
}
