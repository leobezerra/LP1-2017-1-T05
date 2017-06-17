#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>

#include "observation.h"
#include "sets.h"

bool cmp (const Observation & lhs, const Observation & rhs) {
    return lhs < rhs;
}

int main(int argc, char * argv[]) {
    std::cout.precision(5);
    Set dataset;
    std::cin >> dataset;
    std::cout << dataset;

    std::set<Observation, obsCmp> sorted = dataset.sort(cmp);
    for (auto itr = sorted.begin(); itr != sorted.end(); itr++)
        std::cout << *itr;
}
