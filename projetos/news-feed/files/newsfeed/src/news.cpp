#include <iostream>
#include <sstream>
#include <string>

#include "json/json-forwards.h"
#include "json/json.h"

#include "news.h"

std::istream & operator>> (std::istream & in, News & news) {
	std::string tmp;
	std::getline(in, tmp);
	if (in.eof()) return in;
	std::istringstream line(tmp);

	Json::Value root;
	line >> root;
	news.publisher_id = root.get("publisher_id", "0").asInt();

	std::string dt_str = root.get("timestamp","").asString();
	std::istringstream dt_stream(dt_str);
	dt_stream >> news.tstamp;

	news.msg = root.get("msg", "").asString();
	return in;
}

std::ostream & operator<< (std::ostream & out, const News & news) {
	std::cout << "{\"publisher_id\": " << news.publisher_id
		<< ", \"timestamp\": \"" << news.tstamp
		<< "\", \"msg\": \"" << news.msg << "\"}" << std::endl;

	return out;
}
