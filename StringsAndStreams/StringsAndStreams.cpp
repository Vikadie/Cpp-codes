#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

bool problem1() {
    string str1, str2;
    
    bool compare = true;

    getline(cin, str1);
    getline(cin, str2);
       
    return(str1 == str2) ? (compare) : (!compare);
}

int CountChar(string str, char c) {
    int foundCharIndex = str.find(c);
    int count = 0;

    while (foundCharIndex != string::npos) {
        count++;
        foundCharIndex = str.find(c, foundCharIndex + 1);
    }

    return count;
}

bool problem2() {
    string str1;

    getline(cin, str1);

    int countOpenBracket = CountChar(str1, '(');
    int countCloseBracket = CountChar(str1, ')');

    // cout << "Openbr :  " << countOpenBracket << "Closebr :  " << countCloseBracket << endl;

    int pairCount = countOpenBracket - countCloseBracket;
    
    return(pairCount == 0) ? true : false;    

}

void problem3() {
    string text;

    getline(cin, text);

    /* This way would work but we miss the first letter
    for(unsigned i = 1; i < text.size() - 1; i++)
        if (isalpha(text[i]) && !isalpha(text[i-1]))
                text[i] = toupper(text[i]);
     */
    // This way works and capitalize all the words without exception
    int i = 0, check = 0;

    while (text[i]) {
        if (check == 0 && isalpha(text[i])) {
            text[i] = toupper(text[i]);
            check = 1;
        }
        else if (!isalpha(text[i]))
            check = 0;
        i++;
    }
    
    cout << text;
    /*
    while (text[i]) {
        if (text[i] >= 97 && text[i] <= 122)
            cout << text[i] << "=====>" << (char)(text[i] - 32) << endl;;
        i++;
    }*/
}

void problem4() {
    string str, findStr, replaceStr;

    getline(cin, str);
    getline(cin, findStr);
    getline(cin, replaceStr);

    size_t foundIndex = str.find(findStr);

    while (foundIndex != string::npos) {
        str.replace(foundIndex, findStr.size(), replaceStr);
        foundIndex = str.find(findStr, foundIndex + 1);
    }

    cout << str;

}

void problem5() {
    string strTemp;

    getline(cin, strTemp);

    istringstream in(strTemp);

    vector <int> numbers;
    vector <string> str;

    int numElement;
    string strElement;

    while (!in.eof()) {
        in >> strElement;
        if (istringstream(strElement) >> numElement)
            numbers.push_back(numElement);
        else
            str.push_back(strElement);
    }
    int sum = 0;
    for (size_t i = 0; i < numbers.size(); i++)
        sum += numbers[i];

    cout << sum << endl;

    for (size_t i = 0; i < str.size(); i++)
        cout << str[i] << " ";

}

void problem6() {
    string str;

    getline(cin, str);

    istringstream in(str);

    string stringTemp;
    int one = 0, two = 0;

    while (!in.eof()) {
        in >> stringTemp;
        
        for (size_t i = 0; i < stringTemp.size(); i++) {
            if (isdigit(stringTemp[i]))
                one = one * 10 + stringTemp[i] - 48;
        }
        if (one > two) {
            two = one;
            one = 0;
        }
        else
            one = 0;
        }
    cout << two;
}
void problem7() {
    string str;
    getline(cin, str);

    istringstream in(str);

    string stringTemp;
    string answer = "";

    while (!in.eof()) {
        in >> stringTemp;
               
        string noise = "";

        for (size_t i = 0; i < stringTemp.size(); i++) {
            if (!isdigit(stringTemp[i]))
                noise += stringTemp[i];
        }

        if (noise.size() > answer.size())
            answer = noise;
        else if (noise.size() == answer.size())
            if (answer > noise)
                answer = noise;
    }
    
    if (answer.size() > 0)
        cout << answer;
    else
        cout << "no noise";
}

int main()
{
    // problem1() ? cout << "equal" : cout << "not equal"; // Compare Arrays Again
    // problem2() ? cout << "correct" : cout << "incorrect";
    // problem3(); // capitalize all the words without exception
    // problem4(); // Replace all (given string) in a (string) by (another string)
    // problem5(); // Invalid Input
    // problem6(); // The signal and the noise
    problem7(); // The Noise and the Signal

    return 0;
 }
