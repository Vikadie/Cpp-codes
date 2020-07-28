#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
Square Manipulator
Your task is to write a program, which for a given rectangle of numbers performs calculations for smaller squares(with given size) within that rectangle.
For each small square, in which the sum of numbers constructing it exceeds some given value -
output the average number for that square.
The average number for a square is calculated by the sum of all the numbers constructing it
divided by the count of the numbers.
NOTE: the result should be rounded down to the nearest integer.
Since they may be more than one small squares that fulfill the requirements you should
output all of their averages in sorted ascending order divided by a whitespace.
Example input:
> 3 2 (rectangle height and rectangle width)
   0 2
   6 4
   5 -1
> Square side: 2
> Target sum: 7
Example output:
3 3
Explanation:
Both squares 0 2 and 6 4  fulfill the requirements(their sum is bigger than target sum 7) and should be processed.
                        6 4         5 -1
0 + 2 + 6 + 4 = 12 / 4 = 3  
6 + 4 + 5 – 1 = 14 / 4 = 3
They are sorted in ascending order and the output is “3 3”
Input
First read two integers (Rows) and (Cols) indicating the size of the input rectangle.
Next read (Rows) lines of whitespace separated integers. Each row should contain exactly (Cols) integers.
On the last line read two integers (squareSize and targetSum).
*/
int main() {

    unsigned row, col;
    cin >> row >> col;
    vector < vector < int> > matrix;

    for (unsigned i = 0; i < row; i++) {
        vector <int> rowVector;
        for (unsigned j = 0; j < col; j++) {
            int ele;
            cin >> ele;
            rowVector.push_back(ele);
        }
        matrix.push_back(rowVector);
    }

    unsigned squareSide;
    cin >> squareSide;
    unsigned targetSum;
    cin >> targetSum;

    vector <unsigned> ans;
    
    for (unsigned k = 0; k <= row - squareSide; k++)
        for (unsigned v = 0; v <= col - squareSide; v++) {
        unsigned sum = 0;
        for (unsigned i = 0; i < squareSide; i++)
            for (unsigned j = 0; j < squareSide; j++)
                sum += matrix[i + k][j + v];

        if (sum >= targetSum) {
            sum = sum / (squareSide * squareSide);
            ans.push_back(sum);
        }
    }

    sort(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i << " ";

	return 0;
}