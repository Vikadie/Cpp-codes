#include <iostream>
#include <utility>
#include <map>
#include <sstream>

using namespace std;

int main_realNumers()
{// Count Real Numbers
    map <float, int> realNumbers;

    string input;
    getline(cin, input);

    istringstream in(input);
    float inpFloat;
    while (in >> inpFloat) {
        realNumbers[inpFloat]++;
    }

    for (auto i = realNumbers.begin(); i != realNumbers.end(); i++) {
        cout << i->first << " -> " << i->second << endl;
    }

    return 0;
}