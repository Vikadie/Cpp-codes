#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    size_t lines;
    cin >> lines >> ws;

    vector<string> sentence;
    stringstream ss;

    while (lines--) {
        string str;
        getline(cin, str);
        istringstream in(str);

        string word;
        while (in >> word) {

            if (find(sentence.begin(), sentence.end(), word) == sentence.end()) {
                sentence.push_back(word);
            }

            if ("." == word) {
                move(sentence.begin(), sentence.end(), ostream_iterator<string>(ss, " "));
                sentence.clear();
            }
        }
    }

    move(sentence.begin(), sentence.end(), ostream_iterator<string>(ss, " "));

    cout << ss.str() << endl;

    return 0;
}