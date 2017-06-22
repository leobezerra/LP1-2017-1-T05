#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>

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
		feed.publishers.insert(std::make_pair(pbs.getID(),pbs)); 
	} 

	return in;
}

std::ostream & operator<< (std::ostream & out, const NewsFeed & feed) {
	out << "{\"rank\": \"" << feed.rank << "\", \"refresh_rate\": " << feed.refresh_rate << "}" << std::endl;
	for (auto itr = feed.publishers.begin(); itr != feed.publishers.end(); itr++)
		out << itr->second;
	for (auto itr = feed.news.begin(); itr != feed.news.end(); itr++)
		out << itr->second;
	return out;
}

void NewsFeed::read_buffer(const std::string & fname) {
	std::ifstream buffer(fname);
	while (!buffer.eof()) {
		News piece;
		buffer >> piece;
		if (buffer.eof()) break;
		news.insert(std::make_pair(publishers[piece.getPublisherID()],piece));
	}
}

void NewsFeed::sort_recent(void) {
	std::set<News> recent;
	std::transform(news.cbegin(), news.cend(),
               std::inserter(recent, recent.begin()),
               [] (const std::pair<Publisher, News> & entry)
               { return entry.second; });
	recent_news = recent;
} 

void NewsFeed::sort_active(void) {
	std::multimap<Publisher,News,activeCmp> active(news.begin(),news.end());
	active_news = active;
}

void NewsFeed::sort_top(void) {
	std::multimap<Publisher,News,topCmp> top(news.begin(),news.end());
	top_news = top;
}

void NewsFeed::render(void) {
	ushort count = 0;
	if (rank == "recent-news") {
		sort_recent();
		for (auto itr = recent_news.begin(); itr != recent_news.end() && count < 10; itr++, count++)
			std::cout << *itr;
	}
	else if (rank == "recent-active") {
		sort_active();
		for (auto itr = active_news.begin(); itr != active_news.end() && count < 10; itr++, count++)
			std::cout << itr->second;
	}
	else if (rank == "recent_publishers") {
		sort_top();
		for (auto itr = top_news.begin(); itr != top_news.end() && count < 10; itr++, count++)
			std::cout << itr->second;
	}
}