#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int main()
{
    bool valid = true;
    stack <char> brackets;
    string str;
    getline(cin, str);
    istringstream in(str);
    char bracketType;

    while (in >> bracketType) {        
        if (bracketType == '{' || bracketType == '[' || bracketType == '(') { // input bracketType in stack
            if (bracketType == '{') {
                if (!brackets.empty() && (brackets.top() == '[' || brackets.top() == '(')) { // if priority scheme for '{' not OK
                    valid = false; break;
                }
            }
            else if (bracketType == '[') {
                if (!brackets.empty() && brackets.top() == '(') { // if priority scheme for '[' not OK
                    valid = false; break;
                }
            }
            brackets.push(bracketType);
        }
        else { // removing bracketType from stack if correct
            if (bracketType == ')') {
                if (brackets.top() != '(') {
                    valid = false; break;
                }
                else brackets.pop();
            }
            if (bracketType == ']') {
                if (brackets.top() != '[') {
                    valid = false; break;
                }
                else brackets.pop();
            }
            if (bracketType == '}') {
                if (brackets.top() != '{') {
                    valid = false; break;
                }
                else brackets.pop();
            }
        }
    }

    (valid) ? cout << "valid" : cout << "invalid";

    return 0;
}
