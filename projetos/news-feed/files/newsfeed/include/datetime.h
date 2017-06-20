#ifndef __DATETIME_H__
#define __DATETIME_H__

#include <iostream>

class Datetime {
	private:
		ushort years, months, days,	hours, minutes, seconds;
		unsigned micros;
		long long unsigned int elapsed;
	public:
		bool operator==(const Datetime &other) const {
			return years == other.years && months == other.months
				&& days == other.days && hours == other.hours
				&& minutes == other.minutes && seconds == other.seconds
				&& micros == other.micros && elapsed == other.elapsed;	
		}
		friend std::istream & operator>> (std::istream &, Datetime &);
		friend std::ostream & operator<< (std::ostream &, const Datetime &);		
};

#endif