#ifndef __COLUMN_H__
#define __COLUMN_H__

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <utility>

#include "columnTraits.h"

class Column {
	private:
		ColumnTraits traits;
	public:
		//Column(std::string && name, std::string && type) : traits(name, type) {}
		Column(ColumnTraits && _traits) : traits(std::forward<ColumnTraits>(_traits)) {}
		const std::string & getType(void) { return traits.getType(); }
		friend std::ostream & operator<< (std::ostream &, const Column &);
		virtual std::ostream & print(std::ostream &) const = 0;
		virtual std::ostream & print(std::ostream &, ushort) const = 0;
		virtual void push_back(std::string && value) = 0;
		virtual ushort size(void) const = 0;
		virtual void read_column(std::istream &) = 0;
};

std::unique_ptr<Column> make_column(const std::string &);

#endif