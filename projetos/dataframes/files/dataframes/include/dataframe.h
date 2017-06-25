#ifndef __DATAFRAME_H__
#define __DATAFRAME_H__

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

typedef unsigned short int ushort;

#include "column.h"
#include "stringColumn.h"
#include "numColumn.h"
#include "columnTraits.h"

class DataFrame {
	private:
		std::vector<ColumnTraits> header;
		std::unordered_map<std::string,std::unique_ptr<Column>> cols;
		ushort nrows, ncols;
	public:
		friend std::istream & operator>> (std::istream &, DataFrame &);
		friend std::ostream & operator<< (std::ostream &, const DataFrame &);
		const std::string & getColName(ushort idx) const { return header[idx].getName(); }
};

#endif