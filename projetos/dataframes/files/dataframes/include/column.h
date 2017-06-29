#ifndef __COLUMN_H__
#define __COLUMN_H__

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <utility>

typedef unsigned short int ushort;

class Cell {
	public:
		union DataType {
			std::string str;
			float num;
		}
	private: 
		DataType data;
	public:
		virtual DataType & getData() const = 0;
};

class StringCell : public Cell {
	public:
		DataType & getData() { return data.str; }
};

class Column {
	private:
		std::string name, type;
	public:
		Column(const std::string & _name, std::string && _type) : name(_name), type(_type) {}
		Column(std::string && _name, std::string && _type) : name(_name), type(_type) {}
		Column(const Column & col) : name(col.name), type(col.type) {}
		const std::string & getName(void) { return name; }
		const std::string & getType(void) { return type; }
		friend std::ostream & operator<< (std::ostream &, const Column &);
		virtual std::ostream & print(std::ostream &) const = 0;
		virtual std::ostream & print(std::ostream &, ushort) const = 0;
		virtual void push_back(std::string && value) = 0;
		virtual ushort size(void) const = 0;
		virtual void read_column(std::istream &) = 0;
};

typedef std::shared_ptr<Column> columnPtr;

columnPtr make_column(const std::string &);

#endif