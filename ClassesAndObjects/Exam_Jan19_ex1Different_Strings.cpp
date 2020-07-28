#include <iostream>
#include <string>

using namespace std;
/*
Different Strings
Software developers often need to compare text and find differences between one string and another – this comes up from things like source control, 
checking test results, and even automating error correction. So, having a tool that indicates the differences between two strings – 
often called a diff tool – is very useful for these situations.
You task is to write a program, which – given two lines of text of the same length containing English letters, digits, and punctuation – 
prints a diff line that indicates the differences between the two input lines. The program should also print the number of differences.
The diff line should have the same length as the input lines. For each symbol at a position i of the diff line:
If both input lines have the same character at position i, print that character
If both input lines have the same English letter (a-z or A-Z) at position i, but one has it as uppercase and the other has it as a lowercase, 
print the uppercase letter (don’t consider this as a difference)
If the character is at position i is different between the two lines (i.e. none of the above is true), print the character # and count a difference

Input
The first line of the standard input will contain a single positive integer number – the number of symbols in each of the following two lines.
The next two lines on the standard input, containing punctuation, digits, and English letters (no spaces), each line with no more than 150 characters.
Output
The first line of the standard output should be the diff between the two input lines.
The second line of the standard output should be the number of differences between the two input lines.
The third line of the standard output should be the number of same characters.
The fourth line of the standard output should be the sum of the digits.

*/
int main() {
	
	int len;
	cin >> len;

	string str1;
	string str2;
	cin >> str1;
	cin >> str2;
	
	bool OK = true;
	if (str1.size() == str2.size())
		OK = true;

	string diff;
	int diffCount = 0;
	int sameCount = 0;
	int digitSum = 0;
	for (unsigned i = 0; i < len; i++) {
		if (str1[i] == str2[i]) {
			diff += str1[i];
			sameCount++;
		}
		else if (str1[i] == toupper(str2[i]) || toupper(str1[i]) == str2[i])
		{
			diff += toupper(str1[i]);
			sameCount++;
		}
		else { 
			diff += '#'; 
			diffCount++;
		}
		if (str1[i] < '9' && str1[i] > '0')
			digitSum = digitSum + (int)(str1[i] - '0');
		if (str2[i] < '9' && str2[i] > '0')
			digitSum = digitSum + (int)(str2[i] - '0');
	}

	cout << diff << endl
		<< diffCount << endl
		<< sameCount << endl
		<< digitSum << endl;
	return 0;
}