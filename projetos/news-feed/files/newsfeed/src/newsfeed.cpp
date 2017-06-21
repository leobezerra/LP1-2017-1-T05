#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "json/json-forwards.h"
#include "json/json.h"

#include "publisher.h"
#include "news.h"
#include "newsfeed.h"

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
	for (auto itr = feed.news.begin(); itr != feed.news.end(); itr++)
		out << *itr;
	return out;
}

void NewsFeed::read_buffer(const std::string & fname) {
	std::ifstream buffer(fname);
	while (!buffer.eof()) {
		News piece;
		buffer >> piece;
		if (buffer.eof()) break;
		news.insert(piece);
	}

}

void NewsFeed::sort_recent(void) {
	std::set<News> recent(news.begin(), news.end());
	recent_news = recent;
} 

void NewsFeed::sort_active(void) {
	std::set<Publisher> active(publishers.begin(), publishers.end());
//	std::unordered_multiset<News,publisherHash> group(news.begin(), news.end());
	// std::multimap<Publisher,News,cmp> group;
	// for (auto itr = news.begin(); itr != news.end(); itr++)
	// 	group.insert();
	// (news.begin(), news.end(), activeCmp);
//	for (auto itr = group.begin(); itr != group.end(); itr++)
//		std::cout << *itr;	
	// active_news = active;
}

void NewsFeed::render(void) {
	if (rank == "recent-news") {
		sort_recent();
		ushort count = 0;
		for (auto itr = recent_news.begin(); itr != recent_news.end() && count < 10; itr++, count++)
			std::cout << *itr;
	}
	if (rank == "recent-active") {
		sort_active();
	}
}