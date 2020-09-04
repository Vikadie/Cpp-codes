// Ranges
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

std::vector<int> fillRangesFromInput() {
    std::vector<int> ranges;
    std::string line;

    while (getline(std::cin, line) && line != ".") {
        int from, to;
        std::istringstream in(line);
        in >> from >> to;

        ranges.push_back(from);
        ranges.push_back(to);
    }

    return ranges;
}

bool checkIn(int input, std::vector<int>& ranges) {
    
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> bounds;

    bounds = std::equal_range(ranges.begin(), ranges.end(), input);
    
    if(bounds.first != bounds.second || ((bounds.first - ranges.begin()) % 2 != 0 && (bounds.second - ranges.begin()) % 2 != 0))
            return true;
    return false;
}

int main()
{
    std::cin.sync_with_stdio(false);
    std::cout.sync_with_stdio(false);

    std::vector<int> ranges = fillRangesFromInput();
    std::sort(ranges.begin(), ranges.end());
    
    int input;
    while (std::cin >> input) {
        if (checkIn(input, ranges)) {
            std::cout << "in" << std::endl;
        } else
            std::cout << "out" << std::endl;
    }
}
