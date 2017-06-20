#ifndef __NEWS_H__
#define __NEWS_H__

#include <iostream>
#include <string>

#include "datetime.h"

class News {
	private:
		ushort publisher_id;
		Datetime tstamp;
		std::string msg;
	public:
		friend std::istream & operator>> (std::istream &, News &);
		friend std::ostream & operator<< (std::ostream &, const News &);
};

#endif