#include <iostream>
#include <string>

#include "dataframe.h"

int main (int argc, char * argv[]) {
	DataFrame df;
	std::cin >> df;

	if (argc == 2) {
		std::string fname(argv[1]);
		df.persist(fname);
	}
	else
		std::cout << df;
}