#ifndef __COLUMN_H__
#define __COLUMN_H__

#include <iostream>
#include <string>
#include <vector>

class Column {
	public:
		explicit Column (void) = default;
		Column(const Column & other) = delete;
		Column& operator=(const Column&) = delete;
		friend std::ostream & operator<< (std::ostream &, const Column &);
		virtual std::ostream & print(std::ostream &) const = 0;
		virtual std::ostream & print(std::ostream &, ushort) const = 0;
		virtual void push_back(std::string & value) = 0;
		virtual ushort size(void) const = 0;
};

#endif