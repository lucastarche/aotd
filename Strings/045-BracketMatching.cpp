//Bracket Matching
//It determines whether an expression composed of brackets (), [], {}; is properly balanced and ordered or not.
//Examples of valid expressions: ([]{})()[], {()}, ()()()()
//Examples of invalid expressions: ()(, [(]), {{{{)}}}
//The idea is that we keep a queue of brackets, in which we push the openings, and check if they match in the closing brackets, or inform the expression is not valid if they differ.
//The algorithm runs in O(n), because it makes a linear scan through the expression.
#include <bits/stdc++.h>

using namespace std;

bool BracketMatching(string sequence) {
    stack<char> brackets;

    for (auto a : sequence) {
        if (a == '(' || a == '[' || a == '{') {
            brackets.push(a);
        } else if (a == ')') {
            if (!brackets.empty() && brackets.top() == '(')
                brackets.pop();
            else
                return false;
        } else if (a == ']') {
            if (!brackets.empty() && brackets.top() == '[')
                brackets.pop();
            else
                return false;
        } else if (a == '}') {
            if (!brackets.empty() && brackets.top() == '{')
                brackets.pop();
            else
                return false;
        } else
            continue;
    }

    return true;
}

int main() {
    string in;
    cin >> in;
    if (BracketMatching(in)) {
        cout << "The expression is valid" << '\n';
    } else
        cout << "The expression is not valid" << '\n';
}
