//Advertisement
//Problem: Given a row of sticks of height h_i, we want to mount a rectangular advertisement board along it
//Find the maximum area of said board, if its height must be at most the height of the lowest stick covered by the board
//Solution: This is a Dynammic Programming problem which we will have to solve in three steps
//The idea is the following: For each stick, we will get the nearest smaller element to the left and right.
//For example in 1 2 3 4 5 1 2, the nearest smaller element of 4 is 3 to the left, and 1 to the right.
//The idea to get it to the left and right is the same, so I will just explain to the left:
//We go from left to right, maintaining a stack with (value, index) pairs.
//To process the current element, we see whether the top element is bigger than our current one or not, and pop it if this is true
//If the stack is empty, it has no nearest smaller element, and otherwise its the smallest element still in the stack
//After this we push our current element, and note that this maintains the stack ordered from top to bottom
//We will then do the same but from right to left to get the other side
//Finally, for each element i we will get the smaller element to both left and right, say l_i and r_i
//This implies the range [l_i+1, r_i-1] has the smallest element in i, so the area will be the length between those sticks times the height in i
//Since all three times work in linear time, it runs in linear time
//Runtime: O(n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> height(n);
    for (int i = 0; i < n; i++)
        cin >> height[i];

    vector<long long> left(n), right(n);
    stack<pair<long long, long long>> s;
    left[0] = -1;
    s.push({ height[0], 0 });

    for (int i = 1; i < n; i++) {
        while (!s.empty() && s.top().first >= height[i]) {
            s.pop();
        }

        if (s.empty()) {
            left[i] = -1;
        } else {
            left[i] = s.top().second;
        }
        s.push({ height[i], i });
    }

    while (!s.empty())
        s.pop();

    right[n - 1] = n;
    s.push({ height[n - 1], n - 1 });
    for (int i = n - 2; i >= 0; i--) {
        while (!s.empty() && s.top().first >= height[i]) {
            s.pop();
        }

        if (s.empty()) {
            right[i] = n;
        } else {
            right[i] = s.top().second;
        }
        s.push({ height[i], i });
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long length = right[i] - left[i] - 1;

        if (length < 0)
            continue;

        ans = max(ans, length * height[i]);
    }

    cout << ans << '\n';
}