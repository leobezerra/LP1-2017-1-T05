#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <vector>

typedef unsigned short int ushort;

void write_random_byte(ushort size, bool end = false) {
    for (ushort i = 0; i < size; i++) 
        std::cout << (rand() % 256) << (end ? "" : " ");
    if (end) std::cout << std::endl;
}

void write_datagram(const std::string & ip, ushort pid, ushort port) {
    write_random_byte(2);
}

void write_ihl_word(ushort ihl) {
    char iword = (char) 4;
    iword = iword << 4;
    iword += ihl;
    std::cout << (int) iword << " "; 
}

int main (int argc, char * argv[]) {
    std::cout.width(2);
    std::cout.fill('0');
    //std::cout.setf(std::ios::hex, std::ios::basefield);

    std::vector<std::string> ips;
    std::vector<ushort> pids;
    std::vector<ushort> ports;

    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream in(line);
        std::string field;
        if (std::getline(in, field, ',')) pids.push_back(std::stoi(field));
        if (std::getline(in, field, ',')) ports.push_back(std::stoi(field));
        if (std::getline(in, field, ',')) ips.push_back(field);
    }

    for (ushort i = 0; i < ips.size(); i++)
        std::cout << pids[i] << "," << ports[i] << "," << ips[i] << std::endl;
    std::cout << std::endl;
    return 1;

    srand(1);
    ushort buffer_size = std::atoi(argv[1]);
    for (ushort i = 0; i < buffer_size; i++) {
        ushort idx = rand() % ips.size();
        write_datagram(ips[idx], pids[idx], ports[idx]);
    }

    return 1;
}
