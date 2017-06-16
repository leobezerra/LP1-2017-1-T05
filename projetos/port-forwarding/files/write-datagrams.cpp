#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <vector>

typedef unsigned short int ushort;

std::string string_to_hex(const std::string& input)
{
    static const char* const lut = "0123456789abcdef";
    size_t len = input.length();

    std::string output;
    output.reserve(2 * len);
    for (size_t i = 0; i < len; ++i)
    {
        const unsigned char c = input[i];
        output.push_back(lut[c >> 4]);
        output.push_back(lut[c & 15]);
    }
    return output;
}

void write_random_byte(ushort size, bool end = false) {
    //std::cout << std::setw(2) << (rand() % 256);
    for (ushort i = 0; i < size; i++) 
        std::cout << std::setw(2) << (rand() % 256) << (i + 1 == size ? "" : " ");
    if (end) std::cout << std::endl;
    else std::cout << " ";
}

void write_ihl_word(ushort ihl, ushort total_length) {
    char iword = (char) 4;
    iword = iword << 4;
    iword += ihl;
    std::cout << (int) iword << " "; 

    char dscp = ((rand() % 10) < 3 ? 46 : 0);
    char ecn = rand() % 4;
    char dscp_ecn = (dscp << 2) + ecn;
    std::cout << std::setw(2) << (int) (dscp_ecn & 0xff) << " "; 

    std::cout << std::setw(2) << (total_length >> 8) << " ";
    std::cout << std::setw(2) << (total_length & 0xff)<< " ";
    write_random_byte(4, true);

    std::cerr << "ihl: " << ihl;
    std::cerr << ", dscp: " << (int) dscp;
    std::cerr << ", total_length: " << total_length << std::endl;
}

void write_ip(const std::string & ip) {
    std::istringstream in(ip);
    std::string tmp;
    while (std::getline(in, tmp, '.')) 
        std::cout << std::setw(2) << std::stoi(tmp) << " ";
}

void write_udp(ushort port, bool breakpoint = false) {
    write_random_byte(2);
    std::cout << std::setw(2) << (port >> 8) << " ";
    std::cout << std::setw(2) << (port & 0xff);
    if (breakpoint) std::cout << std::endl;
    else std::cout << " ";

    write_random_byte(4, !breakpoint);
}

void write_options(ushort ihl) {
    if (ihl > 5) 
        write_random_byte(4, true);
    for (ushort i = 7; i < ihl; i += 2) write_random_byte(8, true);
    if (ihl > 6 && ihl % 2) write_random_byte(4);
}

void write_hex(const std::string & str, ushort start, ushort size, ushort offset = 0) {
    for (ushort i = start * 2; i < (start + size) * 2; i += 2)
        std::cout << str[i] << str[i+1] << ((i/2 + 1 + offset) % 8 ? " " : "\n");
}

void write_data(ushort ihl, ushort total_length) {
    std::string str;
    for (ushort i = ihl * 4; i < total_length; i++)
        str.push_back((char) ((rand() % 94) + 32));
    std::cerr << "data: " << str << std::endl;
    std::string hex = string_to_hex(str); 

    ushort offset = 0;
    if (ihl % 2) {
        if (total_length >= ihl * 4 + 4) {
            write_hex(hex, 0, 4, 4);
            offset = 4;
        }
        else {
            offset = total_length - ihl * 4;
            write_hex(hex, 0, offset);
        }
    }

    ushort remaining_data = total_length - (ihl * 4 + offset);
    if (!remaining_data) return;
    ushort total_words = remaining_data / 8;
    for (ushort i = 0; i < total_words; i++)
        write_hex(hex, i * 8 + offset, 8, offset);
    if (remaining_data % total_words)
        write_hex(hex, total_words * 8 + offset, remaining_data % total_words, offset);
}

void write_datagram(const std::string & ip, ushort port) {
    ushort ihl = (rand() % 3) + 5;
    ushort total_length = (rand() % 50) + 40;
    write_ihl_word(ihl, total_length);
    write_random_byte(8, true);

    std::cerr << "ip: " << ip << ", port: " << port << std::endl;
    write_ip(ip);
    write_options(ihl);
    write_udp(port, ihl % 2);

    write_data(ihl, total_length);
}

int main (int argc, char * argv[]) {
    std::cout.width(2);
    std::cout.fill('0');
    std::cout.setf(std::ios::hex, std::ios::basefield);

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

    srand(1);
    ushort buffer_size = std::atoi(argv[1]);
    for (ushort i = 0; i < buffer_size; i++) {
        ushort idx = rand() % ips.size();
        write_datagram(ips[idx], ports[idx]);
    }

    return 1;
}
