#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>

#include "observation.h"
#include "sets.h"

int main(int argc, char * argv[]) {
    std::cout.precision(5);
    Set dataset;
    std::cin >> dataset;
    std::cout << dataset;
}
