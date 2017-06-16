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
    std::cout << portfwd;

    std::string fname(argv[1]);
    portfwd.parse_buffer(fname);

    std::priority_queue<Message> queue;
    queue.push(Message("Vanessa", 46));
    queue.push(Message("Julia", 0));
    queue.push(Message("Vana",46));
    queue.push(Message("Leo",0));
    queue.pop(); queue.pop();
    std::cout << queue.top() << std::endl;
    return 1;
}
