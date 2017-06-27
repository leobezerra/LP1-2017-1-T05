#include <iostream>
#include <fstream>
#include <string>

typedef unsigned short int ushort;

#include "dataframe.h"

int main (int argc, char * argv[]) {
	DataFrame df;
	std::ifstream in("../input/subset-turmas20171.csv");
	in >> df;
	columnPtr col = make_column("../input/subset-horario.csv");
	columnPtr col2 = make_column("../input/subset-local.csv");
	df.appendCol(col);
	df.insertCol(col2, 2);
	std::string out("add_column.csv");	
	df.persist(out);
}