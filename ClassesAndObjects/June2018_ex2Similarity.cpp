#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	getline(cin, str);
	
	string word;
	int P;
	cin >> word >> P;
	unsigned size = word.size();

	int wordsOK = 0;
	string words;
	int i = 0;
	while (i < str.size()) {
		char w = str[i];
		if (!(w == '.' ||
			  w == ',' ||
			  w == ';' ||
			  w == '!' ||
			  w == '?' ||
			  w == ' ') )
			words += w;
		else {
			unsigned size_words = words.size();
			if (size == size_words && words[0] == word[0]) {
				int count = 1;
				for (unsigned j = 1; j < size; j++)
						if (word[j] == words[j]) {
							count++;
						}
				if (100 * count / size_words >= P)
					wordsOK++;
			}
			words = "";
		}
		i++;
	}

	cout << wordsOK;
	
	return 0;
}