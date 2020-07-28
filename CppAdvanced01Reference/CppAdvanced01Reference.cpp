// CppAdvanced01Reference.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>

using namespace std;

void removeNegative(list<int>& numbers) {
    auto i = numbers.begin();
    while (i != numbers.end()) {
        if (*i < 0)
            i = numbers.erase(i);
        else i++;
    }
}

int main()
{
    list <int> values{ 1, -69, -4, 42, -2, 13, -9 };
    removeNegative(values);
    for (auto i : values)
        cout << i << " ";

    string s = "hello"; string* ptrS = &s;
    s.insert(0, "world "); ptrS->append("!!!");
    cout << s;

    int num = 42;
    int* ptrNum = &num;
    cout << endl << "==========" << endl << "num: " << num << "; *ptr: " << *ptrNum << "; ptr: " << ptrNum << endl;
    (*ptrNum)++;
    cout << "==========" << endl << "num: " << num << "; *ptr: " << *ptrNum << "; ptr: " << ptrNum << endl;
}
