#include <iostream>
#include <fstream>
#include <string>

typedef unsigned short int ushort;

#include "dataframe.h"

int main (int argc, char * argv[]) {
	DataFrame df;
	std::ifstream in("../input/turmas20171.csv");
	in >> df;
	std::string out("persist.csv");
	df.persist(out);
}