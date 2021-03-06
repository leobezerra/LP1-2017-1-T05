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

class DataFrame {
	private:
		std::vector<std::string> header;
		std::unordered_map<std::string,columnPtr> cols;
		ushort nrows, ncols;
	public:
		friend std::istream & operator>> (std::istream &, DataFrame &);
		friend std::ostream & operator<< (std::ostream &, const DataFrame &);
		const std::string & getColName(ushort idx) const { return header[idx]; }
		void print(std::ostream &, char sep='\t') const;
		void persist(const std::string &) const;
		void appendCol(columnPtr &);
		void insertCol(columnPtr &, ushort);
		void removeCol(const std::string &);
		void removeCol(ushort);
		columnPtr & atCol(const std::string &);
		columnPtr & atCol(ushort);
};

#endif