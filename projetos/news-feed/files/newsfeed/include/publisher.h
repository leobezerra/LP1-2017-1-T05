#ifndef __PUBLISHER_H__
#define __PUBLISHER_H__

#include <iostream>

#include "json/json-forwards.h"
#include "json/json.h"
#include "datetime.h"

class Publisher {
	private:
		ushort publisher_id, weekly, monthly, yearly;
		Datetime last_interaction;
	public:
		ushort getID(void) const { return publisher_id; }
		bool operator==(const Publisher &other) const {
			return publisher_id == other.publisher_id 
				&& weekly == other.weekly && monthly == other.monthly
   	            && yearly == other.yearly
   	            && last_interaction == last_interaction;
		}
		friend std::istream & operator>> (std::istream &, Publisher &);
		friend std::ostream & operator<< (std::ostream &, const Publisher &);
};

namespace std {

  template <>
  struct hash<Publisher>
  {
    std::size_t operator()(const Publisher& pbs) const
    {
      using std::hash;
      return hash<int>()(pbs.getID());
    }
  };

}

#endif