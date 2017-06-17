#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>

#include "sets.h"

std::istream & operator>> (std::istream & in, Set & set_) {
    while (!in.eof()) {
        Observation obs;
        in >> obs;
        set_.data.insert(obs);
    }
    return in;
}
std::ostream & operator<< (std::ostream & out, const Set & set_) {
    for (auto itr = set_.data.begin(); itr != set_.data.end(); itr++)
        out << *itr;
    return out;
}
