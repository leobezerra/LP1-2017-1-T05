#ifndef __COLUMN_H__
#define __COLUMN_H__

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <utility>

class Column {
	private:
		std::string name, type;
	public:
		Column(const std::string & _name, std::string && _type) : name(_name), type(_type) {}
		Column(std::string && _name, std::string && _type) : name(_name), type(_type) {}
		const std::string & getName(void) { return name; }
		const std::string & getType(void) { return type; }
		friend std::ostream & operator<< (std::ostream &, const Column &);
		virtual std::ostream & print(std::ostream &) const = 0;
		virtual std::ostream & print(std::ostream &, ushort) const = 0;
		virtual void push_back(std::string && value) = 0;
		virtual ushort size(void) const = 0;
		virtual void read_column(std::istream &) = 0;
};

std::unique_ptr<Column> make_column(const std::string &);

#endif