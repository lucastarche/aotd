//Stick Game
//Problem: We have a game where there are n sticks, and k possible moves of the form "remove exactly k_i sticks"
//Find for every i <= n whether player one wins or loses if they start moving
//Solution: We can use a recursive minmax algorithm, keeping track of the states we already visited
//This works efficiently given there are only n different states to visit, one for each number of sticks
//Runtime: O(n)
#include <bits/stdc++.h>

using namespace std;

int minmax(const vector<int>& moves, vector<int>& state, int curr) {
    if (curr == 0)
        return -1;
    if (state[curr] != 0)
        return state[curr];

    int res = -1;
    for (auto move : moves) {
        if (curr >= move) {
            res = max(res, -minmax(moves, state, curr - move));
        }
    }
    state[curr] = res;
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> moves(k), state(n + 1);
    for (int i = 0; i < k; i++)
        cin >> moves[i];

    minmax(moves, state, n);
    for (int i = 1; i <= n; i++) {
        if (state[i] == 1)
            cout << 'W';
        else
            cout << 'L';
    }
    cout << '\n';
}