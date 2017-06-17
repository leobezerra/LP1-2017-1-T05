#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "observation.h"

std::istream & operator>> (std::istream & in, Observation & obs) {
    std::string line, tmp;
    std::getline(in, line);
    std::istringstream buffer(line);
    while (std::getline(buffer, tmp, ',')) obs.features.push_back(std::stof(tmp));
    return in;
}

std::ostream & operator<< (std::ostream & out, const Observation & obs) {
    for (ushort i = 0; i < obs.size(); i++)
        out << obs.features[i] << (i+1 == obs.size() ? "" : "\t");
    out << std::endl;
    return out;
}

bool Observation::operator==(const Observation & other) const {
    if (features.size() != other.features.size()) abort();
    for (ushort i = 0; i < features.size(); i++) 
        if (features[i] != other.features[i]) return false;
    return true; 
}

bool Observation::operator<(const Observation & other) const {
    if (features.size() != other.features.size()) abort();
    for (ushort i = 0; i < features.size(); i++) {
        if (features[i] == other.features[i]) continue;
        return features[i] < other.features[i];
        
    }
    return false;
}
