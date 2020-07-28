/*
Emails)
Captain Grant is a Scottish naval officer, and, as you might know, has a lot of paperwork to do. He especially hates reading emails – 
he gets a lot of irrelevant stuff in his inbox, and he’d much rather spend some quality time with the bottles in his cabinet than by sorting 
through thousands of emails. He needs a program which, given a search word, prints messages containing that word, ordered by how many times 
the word appears in them.
Your task is to write a program, which, given a search word S (a sequence of lowercase English letters), a page size P (a positive integer 
number) and a set of email messages in the captain’s inbox (single-line strings of words consisting lowercase English letters, separated by spaces), 
prints out at most P messages, ordered by the number of times the search word appears in them (don’t print out messages which don’t contain the 
search word). A word is considered to match the search word only if all the characters of both words are equal and the words are of equal length.
For example, if the captain is searching for messages containing the search word "speed", specifies a page size of 2 (e.g. he only has time to read 
the 2 most-relevant emails), and has the messages:
- speed give me what I need yeaaaah
- speedy gonzales is speedier than a speeder from from star wars
- a crucial part of any naval engagement is speed speed speed
- the speed of hms daring is lower than the speed of your ship
the program should output messages 3 and 4 (in that order). If the page size P was 4, then the program should output messages 3, 4 and 1 only (the other 
message doesn’t contain the word "speed" at all – message 2 has words which have "speed" as a sub-word, but that doesn’t count as a match, as described above).

Input

The first line of the standard input contains the search word S (sequence of a-z characters).
The second line of the standard input contains a single positive integer number – the page size P.
Each of the following lines is a message – words (sequences of a-z characters) separated by spaces.
The last line of the input contains only the dot character ("."), signaling the end of the input
Output
At most P lines, containing the most-relevant messages (those with the most occurrences of the search word), in descending order (i.e. those with 
more occurrences of the search word come before those with less occurrences of the search word).
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
#include <regex>

using namespace std;

int main() {
	cin.sync_with_stdio(false);
	string search;
	cin >> search;
	unsigned P;
	cin >> P >> ws;

	string input;
	getline(cin, input);

	map <int, vector<string>, greater <int> > table;
	vector <string> inputVec;
	while (input != ".") {
		string str;
		size_t count = 0;
		istringstream in(input);
		while (in >> str) {
			if (str == search)
				count++;
		}
		if (count > 0)
			table[count].push_back(input);
		if (table.size() > P) {
			auto it = table.end();
			it--;
			table.erase(it);
		}

		getline(cin, input);
	}

	//sorted as it is a map
	for (map <int, vector<string>, greater <int> >::iterator i = table.begin(); i != table.end(); i++) {
		for (auto j : i->second)
			cout << j << endl;
	}
	return 0;
}