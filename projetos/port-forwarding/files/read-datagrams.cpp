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

std::string hex_to_string(const std::string& input)
{
    static const char* const lut = "0123456789abcdef";
    size_t len = input.length();
    if (len & 1) throw std::invalid_argument("odd length");

    std::string output;
    output.reserve(len / 2);
    for (size_t i = 0; i < len; i += 2)
    {
        char a = input[i];
        const char* p = std::lower_bound(lut, lut + 16, a);
        if (*p != a) throw std::invalid_argument("not a hex digit");

        char b = input[i + 1];
        const char* q = std::lower_bound(lut, lut + 16, b);
        if (*q != b) throw std::invalid_argument("not a hex digit");

        output.push_back(((p - lut) << 4) | (q - lut));
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
    std::cin.setf(std::ios::hex, std::ios::basefield);

    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream in(line);
        in.setf(std::ios::hex, std::ios::basefield);

        ushort ihl_, dscp_, total_1, total_2;
        in >> ihl_ >> dscp_ >> total_1 >> total_2;

        ushort ihl = ihl_ & 0x0f;
        ushort dscp = dscp_ >> 2;
        ushort total = (total_1 << 8) + total_2;

        std::cout << "ihl: " << ihl << ", dscp: " << dscp << ", total_length: " << total << std::endl;

        std::getline(std::cin, line);
        std::getline(std::cin, line);
        in.str(line);

        ushort ip1, ip2, ip3, ip4;
        in >> ip1 >> ip2 >> ip3 >> ip4;
        std::string ip = std::to_string(ip1) + "." + std::to_string(ip2) + "." + std::to_string(ip3) + "." + std::to_string(ip4);

        if (ihl > 5) {
            for (unsigned i = 5; i < ihl; i += 2) std::getline(std::cin, line);
            in.str(line);
            in.clear();
            if (ihl % 2) in.ignore(12);
        }
        in.ignore(6);
        ushort porta_1, porta_2;
        in >> porta_1 >> porta_2;
        ushort porta = (porta_1 << 8) + porta_2;

        std::cout << "ip: " << ip << ", port: " << porta << std::endl;
        
        short total_data = total - ihl * 4;
        std::string data_hex;
        std::ostringstream out;
        ushort tmp;
        if (ihl % 2) {
            std::getline(std::cin, line);
            in.str(line);
            in.clear();
            in.ignore(12);
            for (ushort i = 0; i < 4; i++) {
                in >> line;
                data_hex += line;
                total_data--;
            }
        }
        while (total_data > 0) {
            std::cin >> line;
            data_hex += line;
            total_data--;
        }
        std::string data = hex_to_string(data_hex);
        std::cout << "data: " << data << std::endl;
        std::getline(std::cin, line);
    }
    return 1;
}
