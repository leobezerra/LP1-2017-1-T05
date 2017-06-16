#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <queue>

#include "portforward.h"
#include "messages.h"

int main (int argc, char * argv[]) {
    PortForward portfwd;
    std::cin >> portfwd;
    //std::cout << portfwd;

    std::string fname(argv[1]);
    portfwd.parse_buffer(fname);
    std::cout << portfwd;
    return 1;
}
