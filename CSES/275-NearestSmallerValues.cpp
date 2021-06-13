//Nearest Smaller Values
//Problem: Given an array of numbers, find the index of the first smallest value to the left, or 0 if there is none.
//Solution: We can start with an empty stack. For each number, if the stack is empty there is no smaller value, and we push the current one.
//Else we can see for every value in the stack if it is smaller than our number or not.
//If it is smaller, we found our number, else we pop the top and keep searching until we run out of stack or find one.
//This works because, given the nature of how we form our stack, it is always in increasing order, and if we popped every
//value in the stack, we found the smallest value so far, and we can simply pop off the rest
//Runtime: O(n), since every value is pushed to the stack at most once
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n), nearest(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty()) {
            if (s.top().first < nums[i]) {
                nearest[i] = s.top().second;
                break;
            }
            s.pop();
        }

        s.push({ nums[i], i + 1 });
    }

    for (auto a : nearest)
        cout << a << ' ';
    cout << '\n';
}