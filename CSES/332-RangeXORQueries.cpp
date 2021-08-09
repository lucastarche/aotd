//Range XOR Queries
//Problem: Given an array of n numbers, respond to q queries of the form "What is the XOR of all elements in the range [l, r]?"
//Solution: Similar to Static Range Sum Queries, we can use the same idea for XOR, thanks to the fact that it is associative and has an inverse
//We will store in prefix[i] the XOR of all numbers in [1, i), which lets us answer each query by doing prefix[r] ^ prefix[l - 1]
//Runtime: O(n + q)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> prefix(n + 1);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] ^ nums[i];
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << (prefix[r] ^ prefix[l - 1]) << '\n';
    }
}