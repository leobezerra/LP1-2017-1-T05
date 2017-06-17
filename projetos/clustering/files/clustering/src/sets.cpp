#include <iostream>
#include <string>
#include <vector>
#include <set>

#include "sets.h"

std::istream & operator>> (std::istream & in, Set & set_) {
    while (!in.eof()) {
        Observation obs;
        in >> obs;
        if (in.eof()) break;
        set_.insert(obs);
    }
    return in;
}
std::ostream & operator<< (std::ostream & out, const Set & set_) {
    for (auto itr = set_.begin(); itr != set_.end(); itr++)
        out << *itr;
    return out;
}

bool Set::contains (const Observation & obs) const {
    return find(obs) != end();
}

Set Set::_union(const Set & _set) const {
    Set result;
    for (auto itr = begin(); itr != end(); itr++)
        result.insert(*itr); 
    for (auto itr = _set.begin(); itr != _set.end(); itr++)
        result.insert(*itr); 
    return result;
}

Set Set::intersection(const Set & _set) const {
    Set result;
    for (auto itr = begin(); itr != end(); itr++)
        if (_set.contains(*itr)) result.insert(*itr); 
    return result;
}

Set Set::difference(const Set & _set) const {
    Set result;
    for (auto itr = begin(); itr != end(); itr++)
        if (!_set.contains(*itr)) result.insert(*itr); 
    return result;
}

std::set<Observation, obsCmp> Set::sort(obsCmp cmp) {
    std::set<Observation, obsCmp> sequence(begin(), end(), cmp);
    return sequence;
}

std::vector<bound> Set::getBounds(void) const {
    auto itr = begin();
    std::vector<bound> bounds;

    for (unsigned i = 0; i < itr->size(); i++)
        bounds.push_back(std::make_pair((*itr)[i], (*itr)[i]));

    for (itr++; itr != end(); itr++) {
        for (unsigned i = 0; i < bounds.size(); i++) {
            if ((*itr)[i] < bounds[i].first) bounds[i].first = (*itr)[i];
            if ((*itr)[i] > bounds[i].second) bounds[i].second = (*itr)[i];
        }
    }

    return bounds;
}