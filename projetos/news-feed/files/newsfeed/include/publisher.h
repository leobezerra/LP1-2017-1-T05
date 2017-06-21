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
		friend std::istream & operator>> (std::istream &, Publisher &);
		friend std::ostream & operator<< (std::ostream &, const Publisher &);
		bool operator==(const Publisher &other) const;
		ushort getID(void) const { return publisher_id; }
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