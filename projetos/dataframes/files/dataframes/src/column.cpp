#include <iostream>

#include "column.h"

std::ostream & operator<< (std::ostream & out, const Column & col) {
	return col.print(out);
}