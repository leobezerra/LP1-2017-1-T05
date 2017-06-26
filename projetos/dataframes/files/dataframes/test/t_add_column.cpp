#include <iostream>
#include <fstream>
#include <string>

typedef unsigned short int ushort;

#include "dataframe.h"

int main (int argc, char * argv[]) {
	DataFrame df;
	std::ifstream in("../input/subset-turmas20171.csv");
	in >> df;
	std::cerr << "Yes!" << std::endl;
	std::unique_ptr<Column> col = make_column("../input/subset-horario.csv");
	col->print(std::cout);
	std::cerr << "No!" << std::endl;
	std::string out("add.csv");	
	df.persist(out);
}