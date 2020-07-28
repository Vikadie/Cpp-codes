#include <iostream>
#include <vector>
using namespace std;

void problem3() {
    int l_arr;

    vector <int> arr;

    cin >> l_arr;

    while(l_arr--) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    int remove;
    cin >> remove;

    for (unsigned i = 0; i < arr.size(); i++) {
        if (arr[i] != remove) {
            cout << arr[i] << " ";
        }
    }
}

int main()
{
    problem3();
}
