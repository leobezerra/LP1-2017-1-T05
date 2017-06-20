#ifndef __DATETIME_H__
#define __DATETIME_H__

#include <iostream>

class Datetime {
	private:
		ushort years, months, days,	hours, minutes, seconds;
		unsigned micros;
		long long unsigned int elapsed;
	public:
		friend std::istream & operator>> (std::istream &, Datetime &);
		friend std::ostream & operator<< (std::ostream &, const Datetime &);		
};

#endif