#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

void problem3() {
    vector<int> A;
    vector<int> B;

    string str;
    getline(cin, str);
    istringstream ain(str);
    while (!ain.eof()) {
        int elementNum;
        ain >> elementNum;
        A.push_back(elementNum);
    }

    getline(cin, str);
    istringstream bin(str);
    while (!bin.eof()) {
        int elementNum;
        bin >> elementNum;
        B.push_back(elementNum);
    }

    queue<int> endResult;
    size_t a = A.size();
    size_t b = B.size();

    while (1) {
        if (A[a - 1] < B[b - 1]) {
            cout << "A";
            endResult.push(A[a - 1]);
            if (a > 0)
                a--;
        }
        else {
            cout << "B";
            endResult.push(B[b - 1]);
            if (b > 0)
                b--;
        }
        if (a == 0) {
            for (; b > 0; b--) {
                cout << "B";
                endResult.push(B[b - 1]);
            }
        }
        else if (b == 0) {
            for (; a > 0; a--) {
                cout << "A";
                endResult.push(A[a - 1]);
            }
        }
        if (a == 0 && b == 0){
            cout << endl;
            break;
        }
    }


    while(!endResult.empty()){
        cout << endResult.front() << " ";
        endResult.pop();
    }
}

int main()
{
    problem3();
}
