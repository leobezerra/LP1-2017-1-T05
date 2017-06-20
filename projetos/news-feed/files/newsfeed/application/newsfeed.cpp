#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <unordered_set>

#include "json/json-forwards.h"
#include "json/json.h"

#include "datetime.h"
#include "publisher.h"
#include "news.h"

class NewsFeed {
	private:
		std::string rank;
		ushort refresh_rate;
		std::unordered_set<Publisher> publishers;
//		std::unordered_set<News> news;
	public:
		friend std::istream & operator>> (std::istream &, NewsFeed &);
		friend std::ostream & operator<< (std::ostream &, const NewsFeed &);
};

std::istream & operator>> (std::istream & in, NewsFeed & feed) {
	std::string tmp;
	std::getline(in, tmp);	
	std::istringstream line(tmp);

	Json::Value cfg;
	line >> cfg;

	feed.rank = cfg.get("rank", "top-news").asString();
	feed.refresh_rate = cfg.get("refresh_rate", "1").asInt();

	while (!in.eof()) {
		Publisher pbs;
		in >> pbs;
		if (in.eof()) break;
		feed.publishers.insert(pbs); 
	} 

	return in;
}

std::ostream & operator<< (std::ostream & out, const NewsFeed & feed) {
	out << "{\"rank\": \"" << feed.rank << "\", \"refresh_rate\": " << feed.refresh_rate << "}" << std::endl;
	for (auto itr = feed.publishers.begin(); itr != feed.publishers.end(); itr++)
		out << *itr;
	return out;
}

int main (int argc, char * argv[]) {
	NewsFeed feed;
	std::cin >> feed;

	if (argc < 2) abort();
	std::string fname(argv[1]);
	std::ifstream buffer(fname);

	//std::cout << feed;

	while (!buffer.eof()) {
		News news;
		buffer >> news;
		if (buffer.eof()) break;
		//std::cout << news;
	}

	return 1;
}