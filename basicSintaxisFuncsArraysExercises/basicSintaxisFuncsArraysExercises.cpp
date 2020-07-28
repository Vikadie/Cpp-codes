#include <iostream>
#include <vector>
#include <string>
#include<stdlib.h>
#include <time.h>
using namespace std;

void problem2() {
    int size;
    vector<int>arr;

    cin >> size;

    while (size--) {
        int i;
        cin >> i;
        arr.push_back(i);
    }

    unsigned i;
    int key;

    cin >> key;

    for (i = 0; i < arr.size(); i++)
        if (arr[i] == key)
            break;

    cout << (i < arr.size() ? (int)i : -1); // (bool condition ? (if true) : (if false)) // (int) е необходим, за да определи какво ще отпечата като тикп и за с и за -1 (без него отпечатва (2^31 - 1))


}


void problem1(){

    int left, right;
    char op = 0;
    double result;
    cin >> left >> right;

    while (!op) {
        
        // cin.clear(); изчиства грешките напълно и при вкарване на string всеки char от него ще се третира като default
        cin.ignore(); // изчиства 1 грешка (1 char  от  string), останалите ги подава на default
        cin >> op;

        switch(op){
        case '+': result = (double)left + right; break; // transform left operator in (double) not to have warning conflict with the result
        case '-': result = (double)left - right; break; // transform left operator in (double) not to have warning conflict with the result
        case '*': result = (double)left * right; break; // transform left operator in (double) not to have warning conflict with the result
        case '/': result = (double)left / right; break; // transform left operator in (double) not to have integer for result as a result
        default: 
            op = 0;
            cout << "try again" << endl; break;
        }
    }

    cout << result;
}

void problem3() {
    int size;
    vector<int> arr;

    cin >> size;

    while (size--) {
        int i;
        cin >> i;
        arr.push_back(i);
    }

    int key;
    unsigned index;
    cin >> key;

    for (index = 0; index < arr.size(); index++) {
        if (arr[index] != key){
            cout << arr[index] << " ";
        
        }
    }

}

void problem4() {

    int num = 0;
    char symbol;

    do {
        cin >> symbol;
        if (symbol >= '0' && symbol <= '9') {
            num = num * 10 + (symbol - '0');
        }
    } while (symbol != '.');

    cout << sqrt(num);
    }
    
int ReafIntWithNoise(string str) {
    int num = 0;
    unsigned index = 0;

    for(index = 0; index < str.length(); index++){
        char symbol = str[index];
        if (symbol >= '0' && symbol <= '9') {
            num = num * 10 + (symbol - '0');
        }
        else if (symbol == '.')
            break;
    } 

    return num;

}

void problem5() {
    // init rand()
    srand((unsigned) time(NULL));

    int count = ((unsigned)rand()) % 65 + 1; // count in range (1, 65)

    string str;
    for (; count; count--)
        str.push_back((char)(rand() % 32 + 32));


    //getline() instead of cin
    cout << "Generated sequence" << endl;
    cout << str << endl;;
    cout << "=================" << endl;

    int result = ReafIntWithNoise(str);
    cout << "Our number is: " << result << endl;
    cout << "sqrt(result)" << sqrt(result) << endl;
}

void problem6() {
    int n;
    cin >> n;

    if (n > 26)
        n = 26; // to keep it in the alphabet
      
    for(int s1 = 0; s1 < n; s1++)
        for(int s2 = 0; s2 < n; s2++)
            for (int s3 = 0; s3 < n; s3++) {
                cout << (char)(s1 + 'a') << (char)(s2 + 'a') << (char)(s3 + 'a') << endl;
            }
    
}

string DigitToWord (int d4){
    switch (d4) {
    case 1: return "one"; break;
    case 2: return "two"; break;
    case 3: return "three"; break;
    case 4: return "four"; break;
    case 5: return "fif"; break;
    case 6: return "six"; break;
    case 7: return "seven"; break;
    case 8: return "eight"; break;
    case 9: return "nine"; break;
    default: return ""; break;
    }

}

void problem7() {

    int number;

    cin >> number;
    if (number == 0){
        cout << "zero";
        return;
        }
    
    if (number < 0 || number > 9999) {
        cout << "Error" << endl;
        return;
    }

    int d1, d2, d3, d4; // number is d1 d2 d3 d4 (1 2 4 5) ==> 1245

    d1 = number / 1000;
    d2 = (number % 1000) / 100;
    d3 = (number % 100) / 10;
    d4 = number % 10;


    if (d1)
        cout << d1 << " thousand ";
    if (d2)
        cout << d2 << " hundred ";
    if (d3)
        switch (d3) {
        case 1: cout << "ten"; break;
        case 2: cout << "twenty "; break;
        case 3: cout << "thirty "; break;
        case 4: cout << "fourty "; break;
        case 5: cout << "fifty "; break;
        case 6: cout << "sixty "; break;
        case 7: cout << "seventy "; break;
        case 8: cout << "eighty "; break;
        case 9: cout << "ninety "; break;
        }
    if (d4)
        cout << DigitToWord(d4);
 }
int main()
{
    problem5();
}

