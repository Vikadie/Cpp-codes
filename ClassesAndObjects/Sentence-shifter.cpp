#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// 1.Sentence Shifter
class MyClass {
private:
    string sentence;
    vector <string> sentenceVec;
    int keySwitch;
public:
    MyClass(string input ): sentence(input) 
    {
        istringstream in(sentence);
        string str;
        keySwitch = 0; //initializing the keySwitch

        while (in >> str) { //initializing the vector
            sentenceVec.push_back(str);
        }
    }

    void getShiftedSentence(int switchKey) {
        keySwitch = switchKey;
        int j = sentenceVec.size();
        for (size_t i = 0; i < j; i++) { //for priniting cycle
            if (keySwitch == 0) // when reaching the end of the vector, 
                keySwitch = j; // start from the beginning
            cout << sentenceVec[j - keySwitch] << endl; //printing the word starting from the key
            keySwitch--; //moving to the next word
        }
    }
};

int main()
{
    string input;
    int switchKey;

    getline(cin, input);
    cin >> switchKey;

    MyClass task(input);
    task.getShiftedSentence(switchKey);

    return 0;
}
