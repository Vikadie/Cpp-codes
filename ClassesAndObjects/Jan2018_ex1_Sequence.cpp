/*
Sequence
You are given a sequence of integer numbers.
Find the length of the longest subsequence of increasing numbers in the sequence
Input
The first line of the standard input will contain a single positive integer number N – the number of integers.
The second line of the standard input will contain exactly N integer values, separated by single spaces – the values.
Output
A single line, representing the length of the longest subsequence of increasing values.

*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector <int> sequence;

	for (int i = 0; i < N; i++) {
		int element;
		cin >> element;
		sequence.push_back(element);
	}

	int count = 1;
	int max = 1;
	for (int i = 1; i < N; i++) {
		if (sequence[i] >= sequence[i - 1]) {
			count++;
			if (count > max)
				max = count;
		}
		else
			count = 1;
	}

	cout << max;
	return 0;
}