#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

int main_SortWords()
{// Short Words
	string textInput;
	getline(cin, textInput);

	istringstream in(textInput);
	
	map <string, int> wordMap;
	string words;
	while (in >> words) {
		
		if (words.size() < 5) { // show interest only in words with less than 5 characters
			// transforming it into lowercases checking char by char
			for (size_t i = 0; i < words.size(); i++) {
				if (words[i] >= 'A' && words[i] <= 'Z')
					words[i] = words[i] - 'A' + 'a';
			}

			// adding it to map where they now order alphabetically with lesser function for string
			wordMap[words]++;
		}
	}

	//printing using iterator and whole loop in order to stop after the last word without printing unnecessary comma
	map<string, int>::iterator i = wordMap.begin();
	while (1) {
		cout << i->first;
		i++;
		if (i == wordMap.end())
			break;
		cout << ", ";
		
	}
	


	return 0;
}