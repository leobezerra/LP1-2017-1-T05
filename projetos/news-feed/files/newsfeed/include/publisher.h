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
    bool operator<(const Publisher &other) const;
    ushort getID(void) const { return publisher_id; }
    const Datetime & getLastInteraction(void) const { return last_interaction; }
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

typedef bool (*cmp)(const Publisher &, const Publisher &); 
bool activeCmp (const Publisher & lhs, const Publisher & rhs) {
    return lhs.getLastInteraction() < rhs.getLastInteraction();
}

#endif