//Tower of Hanoi
//One of the more classical recursive or backtracking algorithms. 
//The main idea is that we can solve the case with n elements by moving n - 1 elements to the intermediate stick,
//the last element to the destination, and then move every element in the intermediate disc to the destination.
//Runtime: O(2^n). This is because one needs at least 2^n - 1 moves to solve the puzzle (demonstration ommited).
#include <bits/stdc++.h>

using namespace std;

//s = source, d = destination, i = intermediate
void TowerOfHanoi(int count, char s, char d, char i, vector<pair<char, char>> &ans) {
    if (count == 1) ans.push_back({s, d});
    else {
        TowerOfHanoi(count - 1, s, i, d, ans);
        TowerOfHanoi(1, s, d, i, ans);
        TowerOfHanoi(count - 1, i, d, s, ans);
    }
}

vector<pair<char, char>> TowerOfHanoi(int count) {
    vector<pair<char, char>> ans;
    TowerOfHanoi(count, 'A', 'C', 'B', ans);
    return ans;
}

int main() {
    int n; 
    cin >> n;
    vector<pair<char, char>> ans = TowerOfHanoi(n);
    for (auto a : ans) {
        cout << "Move the top one from " << a.first << " to " << a.second << '\n';
    }
}