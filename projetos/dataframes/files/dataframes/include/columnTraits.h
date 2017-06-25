#ifndef __COLUMNTRAITS_H__
#define __COLUMNTRAITS_H__

#include <iostream>
#include <sstream>

class ColumnTraits {
	private:
		std::string name, type;
	public:
		ColumnTraits(std::string & name_) : name(name_), type("") {}
		friend std::ostream & operator<< (std::ostream &, const ColumnTraits &);
		void setType(std::string && value) { type = value; }
		const std::string & getName(void) const { return name; }
		const std::string & getType(void) const { return type; }
};

#endif