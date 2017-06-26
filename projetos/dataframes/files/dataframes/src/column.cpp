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
	std::string colname;
	std::getline(in, colname);
	std::cout << "colname: "  << colname << ", eof: " << std::boolalpha << in.eof() << std::endl; 

	std::cout << "peek: " << (char) in.peek() << std::endl;
 	bool is_string = (in.peek() == '\"');
	std::unique_ptr<Column> col;
	if (is_string)
		col = std::unique_ptr<Column>(new StringColumn(std::move(colname),"string"));
	else
		col = std::unique_ptr<Column>(new NumColumn(std::move(colname),"numeric"));
	std::cout << "Jazz! " << col->getType() << std::endl;
	col->read_column(in);
	return col;
}
