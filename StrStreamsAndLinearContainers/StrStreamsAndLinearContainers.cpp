#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility> // for using the swap function

using namespace std;

void swapMatrixRows(vector < vector <char> > & Words, size_t i, size_t j) {
    if (i == 0) {
        Words[i][0] -= 'A' - 'a';
        Words[j][0] += 'A' - 'a';
    }
    swap(Words[i], Words[j]);
}

void findDuplicates(vector <int> & index, vector < vector <char> > & Words) {
    size_t size = index.size();
    for (size_t i = 0; i < size; i++) {
        if (index[i] > 0) {
            for (size_t j = size - 1; j > i + 1; j--) {
                if (index[i] == index[j]){
                // swap matrix vectors with indexes i and j
                    swapMatrixRows(Words, i, j);
                    index[j] = 0;
                    break;
                }
            }
        }
    }
}

int main()
{
    vector < vector <char> > Words; // matrix of vectors word
    vector <char> word; // vector of chars word
    vector <int> index; // vector for memorizing the index of words' lengths (sizes)

    string str;
    getline(cin, str);
    istringstream in(str);

    char punctuationArray[] = { '.', '!', '?', ',', '-'}; // punctiation array to check existing punctuation

    // enter the sentence in a vector matrix of chars with each word on a separate vector of chars 
    // along with their lenght in the index vector
    while (in >> str) {
        bool specific = false;
        istringstream charIn(str);
        char letter;

        while (charIn >> letter) {
            if (find(punctuationArray, punctuationArray + 5, letter) != punctuationArray + 5 ) { 
                // specific signs are inputed as separate vectors in the matrix
                specific = true; break;
            }
            word.push_back(letter);
        }
        Words.push_back(word);
        index.push_back(word.size()); // inserting the length
        word = {};
        if (specific) { // specific signs are inputed as separate vectors in the matrix
            word.push_back(letter);
            Words.push_back(word);
            index.push_back(0); // do not count the lenght of special signs
            word = {};
        }
    }

    // discovering the words of the same size in the vector index and their positions
    findDuplicates(index, Words);

    // printing the matrix of vectors
    for (size_t i = 0; i < Words.size(); i++) {
        for (size_t j = 0; j < Words[i].size(); j++)
            cout << Words[i][j];
        if (i < Words.size() - 1 && Words[i+1].size() > 0 && 
            find(punctuationArray, punctuationArray + 4, Words[i + 1][0]) == punctuationArray + 4) 
            // adding the spaces between words
            cout << " ";
    }

    return 0;
}