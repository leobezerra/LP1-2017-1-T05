#include <iostream>
#include <fstream>
#include <string>

typedef unsigned short int ushort;

#include "dataframe.h"

int main (int argc, char * argv[]) {
	DataFrame df;
	std::ifstream in("../input/subset-turmas20171.csv");
	in >> df;
	std::unique_ptr<Column> col = make_column("../input/subset-horario.csv");
	std::unique_ptr<Column> col2 = make_column("../input/subset-local.csv");
	df.append(col);
	df.insert(col2, 2);
	std::string out("add.csv");	
	df.persist(out);
}