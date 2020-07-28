#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;
/*Reporter:
You are a reporter for the local sports newspaper. At the moment you are taking an interview from a hockey player. 
At some point during the interview he begins to stutter and repeats some of the words twice and even three times.
The player must be in a shock after the heavy game because he also repeats whole phrases within the same sentence.
At the end of the interview the player asks you to “clear” the interview of his stutter and repeats of whole phrases before you publish it.
In the input interview they may be more than one sentences. Each sentence is constructed from whitespace delimited words and ends with a ‘.’ (dot) symbol. 
The dot symbol is also whitespace delimited from neighbor words.
Your program should eliminate the duplicate words within each sentence – only the first occurrence of any word should be kept.
NOTE: two sentences can have the same word in them.
Example input: You You did a great job You . You too
Example output: You did a great job . You too

Input
First read a single integer (N) indicating how many lines of data you should read.
Next read N lines of data that will hold the whole interview.
NOTE: end of the line does Not mean end of sentence. The symbol ‘.’(dot) marks the end of sentence.
NOTE2: The ‘.’ (dot) symbol is Not assured to be present for the last sentence.

*/
int main() {
	size_t lines;
	cin >> lines;
	cin.ignore();

	vector <string> sentence;
	vector <string> aLine;
	//stringstream ss;
	while(lines--) {
		string str;
		getline(cin, str);
		istringstream in(str);

		string word;
		while (in >> word) {
			vector<string>::iterator it = aLine.begin();
			for (it; it != aLine.end(); it++)
				if (word == *it)
					break;

			if (it == aLine.end())
				aLine.push_back(word);

			/*if ("." == word) {
				for (auto i : aLine)
					sentence.emplace(sentence.end(), i);
				aLine.clear();
			}*/
			if (word == ".") {
				sentence.insert(sentence.end(), aLine.begin(), aLine.end());
				aLine.clear();
			}
		}
	}
	/*for (auto i : aLine)
			sentence.emplace(sentence.end(), i);*/
	sentence.insert(sentence.end(), aLine.begin(), aLine.end());
	
	for (auto i : sentence)
		cout << i << " ";
		

	return 0;
}