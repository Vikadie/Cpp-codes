#include <iostream>
#include <sstream>
#include <map>

using namespace std;
/*Your task is to write program, which read a single string from the standard input (Maria’s essay). 
Then counts how many punctuation signs each sentence has and group the sentences by their punctuation count. 
Sentences with the same number of characters should be grouped together (see Examples). 
The punctuation occurrences should be sorted in ascending order. The end of each sentence will be marked by the “|” character (without the quotes). 
Important note: Do NOT count the separator symbol “|” as a punctuation. 
Symbols !"#$%&'()*+,-./:;<=>?@[]^_`{}~ are considered as punctuation. 
Hint: there is a build-in function in the C/C++ standard for this. 

Input
Read a single Line of data that will hold the whole essay.

Restrictions
Time limit: 250ms (0.25s) Memory limit: 16 MB

Examples
Input  
This is a test!|
Output
1 symbol sentences: 1

Input
Is this seriously the second exam?|This looks like a pice of cake!|Yum, yum, yum.|
Output
1 symbol sentences: 2
3 symbol sentences: 1
*/
int main() {

	string inputStr;
	map <int, int > input;

	getline(cin, inputStr);
	istringstream istr(inputStr);
	int count = 0;
	char letter;
	while (istr >> letter) {
		int sentence = 1;
		if (letter == '|') {
			sentence++;
			input[count]++;
			count = 0;
			continue;
		}
		if (ispunct(letter)) {
			count++;
		}
	}

	for (pair<int, int> element : input) {
		cout << element.first << " symbol sentences: " << element.second << endl;
	}
}