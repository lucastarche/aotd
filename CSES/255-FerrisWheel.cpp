//Ferris Wheel
//Problem: Given an array of children and a maximum weight k, determine how many gondolas we need for the children, if
//each can fit at most two of them, and the sum of their weights can not exceed k.
//Solution: We can use a deque (double-ended queue) to store the children, and then sort it.
//After this, we take the first and last element, and if it is under k we use a gondola for both, else we fit the heavier
//in his own gondola.
//Runtime: O(n log n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    deque<int> children(n);
    for (int i = 0; i < n; i++)
        cin >> children[i];

    sort(children.begin(), children.end());

    int ans = 0;
    while (children.size() > 1) {
        if (children.front() + children.back() <= k) {
            ans++;
            children.pop_front();
        } else {
            ans++;
        }
        children.pop_back();
    }

    ans += (int)children.size();

    cout << ans << '\n';
}