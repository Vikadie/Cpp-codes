#include <iostream>
#include <string>
#include <sstream>

#include "Tropico.h"

int main()
{
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::cin.clear();

    auto t = std::make_shared<Tropico>();
    int size = 0;

    for (int i = 0; i < n; i++) {
        std::string commands, command;
        getline(std::cin, commands);
        std::istringstream in(commands);
        in >> command;
        if (command == "build") {
            int width = 0;
            int length = 0;
            std::string type;
            
            in >> type >> width >> length;
            
            t->build(type, width, length);
            size++;
        }
        else if (command == "duplicate") {
            int idx1 = 0, idx2 = 0;
            in >> idx1 >> idx2;
            if (idx1 == idx2) {
                std::cout << "Invalid operation" << std::endl;
                continue;
            }
            t->duplicate(idx1, idx2);
        }
        else if (command == "replace") {
            int idx1 = 0, idx2 = 0;
            in >> idx1 >> idx2;
            if (idx1 >= idx2 || idx1 < 0 || idx2 < 0 || idx1 > size || idx2 > size) {
                std::cout << "Invalid operation" << std::endl;
                continue;
            }
            t->replace(idx1, idx2);
        }
        else if (command == "demolish") {
            int idx1 = 0;

            in >> idx1;
            t->demolish(idx1);
            size--;
        }
    }

    return 0;
}
