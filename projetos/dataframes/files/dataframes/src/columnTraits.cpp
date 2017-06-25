#include <iostream>
#include <string>

#include "columnTraits.h"

std::ostream & operator<< (std::ostream & out, const ColumnTraits & col) {
	out << col.name;
	return out;
}
