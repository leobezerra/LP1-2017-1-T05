#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

#include "json/json-forwards.h"
#include "json/json.h"

typedef unsigned short int ushort;

int main (int argc, char * argv[]) {
	std::string tmp;
	std::getline(std::cin, tmp);	
	std::istringstream line(tmp);

	Json::Value cfg;
	line >> cfg;

	std::string rank = cfg.get("rank", "top-news").asString();
	ushort refresh_rate = cfg.get("refresh_rate", "1").asInt();

	std::cout << "{\"rank\": \"" << rank << "\", \"refresh_rate\": " << refresh_rate << "}" << std::endl;

	Json::Value root;
	while (std::getline(std::cin, tmp)) {
		std::istringstream line(tmp);
		line >> root;
		ushort publisher_id = root.get("publisher_id", "0").asInt();
		if (publisher_id == 0) abort();
		std::string last_interaction = root.get("last_interaction", "").asString();
		if (last_interaction == "") abort();

		std::unordered_map<std::string,ushort> frequency;
		frequency["yearly"] = root["interaction_frequency"].get("yearly", 0).asInt();
		frequency["monthly"] = root["interaction_frequency"].get("monthly", 0).asInt();
		frequency["5day"] = root["interaction_frequency"].get("5day", 0).asInt();

		std::cout << "{\"publisher_id\": " << publisher_id << ", \"interaction_frequency\": "
			"{\"yearly\": " << frequency["yearly"] << ", \"monthly\": " << frequency["monthly"] << 
			", \"5day\": " << frequency["5day"] << "}" 
			<< ", \"last_interaction\": \"" << last_interaction << "\"}" <<  std::endl;
	} 

	return 1;
}