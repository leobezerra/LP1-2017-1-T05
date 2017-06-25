#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <cassert>

typedef unsigned short int ushort;

#include "dataframe.h"

int main (int argc, char * argv[]) {
	DataFrame df;
	std::cin >> df;
	std::cout << df;
}