#include <iostream>
#include <sstream>
#include <set>

using namespace std;

int main_Largest3()
{// Largest 3
    string mainInput;
    getline(cin, mainInput);

    istringstream in(mainInput);
    
    set <float, greater <float> > numSet;
    float number;
    while (in >> number) {
        numSet.insert(number);
    }
    int countTo3 = 0;
    for (set<float>::iterator i = numSet.begin(); i != numSet.end(); i++) {
        cout << *i << " ";
        if (countTo3 == 2)
            break;
        countTo3++;
    }

    return 0;
}
