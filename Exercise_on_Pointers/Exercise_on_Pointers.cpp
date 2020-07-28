#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> readFromInput() {
    int numberFrom, numberTo;
    std::vector<int> toReturn;
    while (std::cin >> numberFrom >> numberTo){
        toReturn.push_back(numberFrom);
        toReturn.push_back(numberTo);
    }    
    return toReturn;
}

int main()
{
    std::cin.sync_with_stdio(false);
    std::cout.sync_with_stdio(false);
    std::vector <int> from_to = readFromInput();

    //clear the cin after '.' char
    std::cin.clear();
    std::cin.ignore();
    //////////////////////////////
    
    ///sort the vector
    std::sort(from_to.begin(), from_to.end());
    //////////////////

    int checknum;
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> bounds;
    while (std::cin >> checknum) {
        bounds = std::equal_range(from_to.begin(), from_to.end(), checknum);
        int index = bounds.second - from_to.begin();
        if (index > 0 && (index % 2 != 0 || *(--bounds.second) == checknum)) {
            std::cout << "in" << '\n';
        }
        else {
            std::cout << "out" << '\n';
        }
    }

    return 0;
}