/*
Message
You are part of a SETI (that thing that’s supposed to find aliens but never does) team and you have just detected messages from a distant star system. 
The signal has been verified to indeed come from a star system, not from an Earth-orbiting satellite or any other sort of interference, and your team 
is certain the source is artificial. Your team wants to analyze the message, and for that they need to first identify the most-commonly encountered 
signals in the message.
The message has been converted to a sequence of English words (containing characters a-z and digits 0-9), separated by spaces. The message ends with a dot, 
preceded by a space (" .").
Your task is to write a program, which answers queries about the message in the form occurrenceCount index by finding all words which appear an occurenceCount 
number of times in the transmission, and printing out the word at position index in the lexicographical order of the (unique) words. If there are no words 
with that occurenceCount, print the dot character (".").
For example, if we have the message string:
"chug a mug of mead and another mug mead chug another mug of mead warrior ."
(What? Nobody said the aliens can’t be from Skyrim…)
and type in 3 0, the program should output mead – the words mead and mug each appear 3 times in the message, and ordered lexicographically they form the array {"mead", "mug"}, in which the element at the 0 index is the word mead.
If we instead type in 2 1, the program should output chug – the words that appear 2 times in the message are chug and another. If we sort them lexicographically we get {"another", "chug"}, and index 1 in that array is chug.
If we instead type in 4 0, the program should output . (a single dot character) – there is no word that appears 4 times in the text.
Write a program which reads in a message in the above-mentioned format, and queries in the above-mentioned format, and prints out the results for those queries
Input
The first line of the input will contain the message – a string containing English characters a-z, digits 0-9, spaces, and ending with a space and a dot (" ."). Words in that string are considered sequences of characters and/or digits separated by spaces.
The next line will contain a single integer N – the number of queries.
Each of the following lines will contain two positive integer numbers, separated by a single space – the occurrenceCount and index values of the query.
Output
N lines, each containing a single word, representing the answers to the queries in the same order the queries were given.

*/
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	string message;
	getline(cin, message);

	
	istringstream in(message); // loading the sentence in "in"

	map <string, int> messageMap; // initializing the map
	string str;
	while (in >> str) {
		if (str == ".")
			break;
		messageMap[str]++; // filling the map
	}

	map <int, vector <string> > repetitionWords; // inverting key, values to values, key of the map
	for (auto i : messageMap)
		repetitionWords[i.second].push_back(i.first);

	int queries;
	cin >> queries;
	vector <int> keys;
	vector <int> indexes;
	while (queries--) {
		int key;
		cin >> key;
		int index;
		cin >> index;
		keys.push_back(key); // creating vector for key
		indexes.push_back(index); // creating vector of indexes (by default) for searched word in the value vector 
	}

	
	bool found = false;
	unsigned k = 0; // k will serve as index for both "keys" and "indexes" vectors
	while (k < keys.size()) {
		for (auto i = repetitionWords.begin(); i != repetitionWords.end(); i++)
			if (keys[k] == i->first) {
				cout << i->second[indexes[k]] << endl;
				found = true;
			}
		if (!found) // if not found
			cout << "." << endl;
		k++; // not to forget to increment the key
		found = false; // not to forget to re-initialize the flag
	}
	return 0;
}