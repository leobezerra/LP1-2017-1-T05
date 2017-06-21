#ifndef __NEWSFEED_H__
#define __NEWSFEED_H__

#include <iostream>
#include <string>
#include <set>
#include <unordered_set>

#include "publisher.h"
#include "news.h"

class NewsFeed {
	private:
		std::string rank;
		ushort refresh_rate;
		std::unordered_set<Publisher> publishers;
		std::unordered_set<News> news;
		std::set<News> recent_news, active_news;
	public:
		friend std::istream & operator>> (std::istream &, NewsFeed &);
		friend std::ostream & operator<< (std::ostream &, const NewsFeed &);
		void read_buffer(const std::string &);
		void sort_recent(void);
		void sort_active(void);
		void render(void);
};

#endif