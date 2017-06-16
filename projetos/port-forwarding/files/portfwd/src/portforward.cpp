#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <string>

#include "portforward.h"
#include "datagrams.h"
#include "messages.h"

std::istream& operator>> (std::istream & stin, PortForward & pf) {
    std::string ip;
    ushort pid, port;

    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream in(line);
        std::string field;
        if (std::getline(in, field, ',')) pid = std::stoi(field);
        if (std::getline(in, field, ',')) port = std::stoi(field);
        if (std::getline(in, field, ',')) ip = field;
        TableEntry entry(ip, port, pid);
        pf.portTable.insert(entry);
    }

    return stin; 
}

std::ostream & operator<< (std::ostream & out, const TableEntry & entry) {
    out << entry.pid << "," << entry.port << "," << entry.ip;
    return out;
}

void PortForward::parse_buffer(const std::string & fname) {
    std::ifstream in(fname);
    std::vector<Datagram> msgs;
    ushort i = 0;
    do {
        Datagram msg;
        in >> msg;
        if (in.eof()) break;
        msgs.push_back(msg);
    }
    while (1);
    for (ushort i = 0; i < msgs.size(); i++) 
        std::cout << msgs[i] << std::endl;
}

std::ostream & operator<< (std::ostream & out, PortForward & pf) {
    for (std::unordered_set<TableEntry>::iterator itr = pf.portTable.begin(); itr != pf.portTable.end(); itr++)
        std::cout << *itr << std::endl;
    return out;
}
