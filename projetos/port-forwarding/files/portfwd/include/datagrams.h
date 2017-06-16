#include <iostream>
#include <string>

typedef unsigned short int ushort;

class Datagram {
    private:
        ushort ihl, dscp, total, porta;
        std::string data, ip;
    public:
        friend std::istream& operator>> (std::istream &, Datagram &);
        friend std::ostream& operator<< (std::ostream &, const Datagram &);
};

