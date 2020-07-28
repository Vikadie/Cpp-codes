#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <int> ReadArrEntry(unsigned numPipes) {
    vector <int> entryArr;
    for (unsigned i = 0; i < numPipes; i++) {
        int entry;
        cin >> entry;
        entryArr.push_back(entry);
    }
    return entryArr;
}

void PipeCalcul1() {
    unsigned N;

    cin >> N;

    vector <int> checkupY1 = ReadArrEntry(N);
    vector <int> installation = ReadArrEntry(N);


    for (unsigned i = 0; i < N; i++) {
        int corrode;
        corrode = installation[i] / (installation[i] - checkupY1[i]);

        cout << corrode << " ";
    }
}

void ModulatedSum() {
    unsigned numArr, sizeArr;
    cin >> numArr >> sizeArr;

    vector <int> arr;

    for (unsigned i = 0; i < numArr; i++) {
        vector <int> a = ReadArrEntry(sizeArr);
        arr.insert(arr.end(), a.begin(), a.end());
    }

    unsigned modulo;
    cin >> modulo;

    for (unsigned i = 0; i < sizeArr; i++) {
        int result = 0;
        for (unsigned j = 0; j < numArr; j++)
            result += arr[j * sizeArr + i];
        result %= modulo;

        cout << result << " ";
    }
}

void Bus() {
    unsigned numberOfBuses;
    cin >> numberOfBuses;

    vector <int> entryArr;
    for (unsigned i = 0; i < numberOfBuses; i++) {
        int entry;
        cin >> entry;
        entry = (entry / 100) * 60 + (entry % 100);
        entryArr.push_back(entry);
    }

    int trainTime;
    cin >> trainTime;

    trainTime = (trainTime / 100) * 60 + (trainTime % 100);
    unsigned index = -1;
    int minWait = 24 * 60;

    for (unsigned i = 0; i < numberOfBuses; i++) {

        if ((trainTime - entryArr[i] < minWait) && (trainTime >= entryArr[i])) {
            minWait = trainTime - entryArr[i];
            index = i;
        }
    }

    cout << index + 1;
}

void Roxette() {
    
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    string entry;
    cin >> entry;

    vector <string> str;

    for(unsigned i = 0; i < entry.size() - 5; i += 5) {
        string tempStr = "";
        tempStr = entry.substr(i, 5);
        str.push_back(tempStr);
    }

    string tempStr = "";

    for (unsigned i = 0; i < str.size(); i++) {
        unsigned j;
        for (j = 0; j < str.size(); j++) {
            if (i != j) {
                if (str[i] == str[j])
                {
                    tempStr.clear();
                    break;
                }
                else
                    tempStr = str[i];
            }
        }
        if (tempStr != "" && j == str.size())
            cout << tempStr;
            break;
    }
    
}

int main()
{
    // PipeCalcul1();
    // ModulatedSum();
    // Bus();
    Roxette();

}
