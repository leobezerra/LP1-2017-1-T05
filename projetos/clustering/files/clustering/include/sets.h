#ifndef __SETS_H__
#define __SETS_H__

#include "observation.h"

class Set {
    private:
        std::unordered_set<Observation> data;
    public:
        friend std::istream & operator>> (std::istream &, Set &);
        friend std::ostream & operator<< (std::ostream &, const Set &);
};

#endif
