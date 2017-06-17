#ifndef __SETS_H__
#define __SETS_H__

#include <set>
#include <unordered_set>

#include "observation.h"

typedef std::pair<double,double> bound;

class Set : private std::unordered_set<Observation> {
    private:
        std::unordered_set<Observation> data;
    public:
        using std::unordered_set<Observation>::insert;
        using std::unordered_set<Observation>::erase;
        using std::unordered_set<Observation>::find;
        using std::unordered_set<Observation>::empty;
        using std::unordered_set<Observation>::begin;
        using std::unordered_set<Observation>::end;

        friend std::istream & operator>> (std::istream &, Set &);
        friend std::ostream & operator<< (std::ostream &, const Set &);

        bool contains(const Observation &) const;
        Set _union(const Set &) const;
        Set intersection(const Set &) const;
        Set difference(const Set &) const;

        std::set<Observation, obsCmp> sort(obsCmp cmp);

        std::vector<bound> getBounds(void);

        std::vector<ushort> cluster(void) {
            if (empty()) abort();
            ushort k = 3;
            std::vector<Observation> container(begin(), end());

            std::vector<bound> bounds = getBounds();
            std::vector<Observation> centroids;
            centroids.reserve(k);
            std::cout << "Initial centroids:" << std::endl; 
            for (ushort i = 0; i < k; i++) {
                centroids.push_back(Observation(bounds));
                std::cout << centroids[i];
            }

            std::vector<ushort> clusters(k);
            return clusters;
         }

};

#endif
