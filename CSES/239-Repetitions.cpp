//Repetitions
//Problem: Given a string of n characters, find the longest number of equal characters next to one another
//Solution: Nothing too hard, just keep a max and a current amount
//If the character is the same, increase the current counter, else start again and change the character.
//Runtime: O(n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    char curr = s[0];
    int amount = 1;
    int best = 0;
    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i] == curr)
            amount++;
        else {
            best = max(best, amount);
            amount = 1;
            curr = s[i];
        }
    }

    cout << max(best, amount) << '\n';
}