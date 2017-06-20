#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <unordered_map>

#include "json/json-forwards.h"
#include "json/json.h"

#include "datetime.h"
#include "publisher.h"
#include "news.h"

int main (int argc, char * argv[]) {
	std::string tmp;
	std::getline(std::cin, tmp);	
	std::istringstream line(tmp);

	Json::Value cfg;
	line >> cfg;

	std::string rank = cfg.get("rank", "top-news").asString();
	ushort refresh_rate = cfg.get("refresh_rate", "1").asInt();

	std::cout << "{\"rank\": \"" << rank << "\", \"refresh_rate\": " << refresh_rate << "}" << std::endl;

	while (!std::cin.eof()) {
		Publisher pbs;
		std::cin >> pbs;
		if (std::cin.eof()) break; 
	} 

	if (argc < 2) abort();
	std::string fname(argv[1]);
	std::ifstream buffer(fname);

	while (!buffer.eof()) {
		News news;
		buffer >> news;
		if (buffer.eof()) break;
		std::cout << news;
	}

	return 1;
}