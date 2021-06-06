//Josephus Problem 1
//Problem: Given a round of n people, we delete every second person and keep going until there are no more people left.
//Find the order on which people leave the round.
//Solution: we can use a queue and a counter to keep track of how many people we have seen since our last deletion.
//If the counter reaches 2, we delete said person and print it, else we push it back to the start of the queue
//Runtime: O(nk), where k = 2
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    int ctr = 0;
    while (!q.empty()) {
        ctr++;
        ctr %= 2;
        int curr = q.front();
        q.pop();

        if (ctr == 0) {
            cout << curr << ' ';
        } else {
            q.push(curr);
        }
    }

    cout << '\n';
}