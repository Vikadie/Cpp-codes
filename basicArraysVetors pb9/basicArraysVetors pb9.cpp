#include <iostream>
#include <vector>
using namespace std;

void problem9() {
    unsigned size;
    vector <int> arr;
    int j;
    cin >> size;

    for (unsigned i = 0; i < size; i++) {
        cin >> j;
        arr.push_back(j);
    }

    vector <int> temp;

    while (1) {
        for (unsigned i = 0; i < arr.size(); i++) {
            if (i < arr.size() - 1 && arr[i] == arr[i + 1]) {
                temp.push_back(arr[i] * 2);
                i++;
            } else
                temp.push_back(arr[i]);
        }
        if (arr.size() == temp.size())
            break;
        arr = temp;
        temp.clear();
    }

    for (unsigned i = 0; i < arr.size(); i++)
        cout << arr[i]  << " ";
}

int main()
{
    problem9();
}
