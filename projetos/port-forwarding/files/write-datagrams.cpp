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

void write_datagram(const std::string & ip, ushort porta, ushort pid) {
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
    std::cout.setf(std::ios::hex, std::ios::basefield);

    std::vector<std::string> ips;
    std::vector<ushort> apps;
    std::vector<ushort> ports;

    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream in(line);
        std::string field;
        if (std::getline(in, field, ',')) ips.push_back(field);
        if (std::getline(in, field, ',')) apps.push_back(std::stoi(field));
        if (std::getline(in, field, ',')) ports.push_back(std::stoi(field));
    }

    for (ushort i = 0; i < ips.size(); i++) 
        std::cout << ips[i] << "," << apps[i] << ","  << ports[i] << std::endl;

    return 1;
}
