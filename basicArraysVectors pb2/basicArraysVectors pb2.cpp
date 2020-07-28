#include <iostream>
#include <vector>
using namespace std;

void problem2() {
    int l_arr;
    cin >> l_arr;

    vector <int> arr;

    while (l_arr--) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    /*for (int i = 0; i < l_arr; i++) {
        int num;
        cin >> num; 
        arr.push_back(num);
    }*/
    int i; unsigned j;
    cin >> i;

    for (j = 0; j < arr.size(); j++) {
        if (arr[j] == i)
            break;
    }
    
    cout << (j < arr.size() ? (int)j : -1);
}

int main()
{
    problem2();
}
