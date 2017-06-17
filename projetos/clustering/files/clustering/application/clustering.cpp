#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>

#include "observation.h"

class Set {
    private:
        std::unordered_set<Observation> data;
};

int main(int argc, char * argv[]) {
    std::cout.precision(5);
    std::vector<Observation> dataset;
    while (!std::cin.eof()) {
        Observation obs;
        std::cin >> obs;
        dataset.push_back(obs);
    }
    dataset.pop_back();
    for (ushort i = 0; i < dataset.size(); i++)
        std::cout << dataset[i];
}
