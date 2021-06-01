//Collecting Numbers
//Problem: Given a list of numbers, we want to collect them in incereasing order. Find the number of passes we have to do to accomplish this
//Solution: We can keep a set of "stacks", on which we represent each pass.
//If we have the number before the current one we remove it, and either way we insert the current one.
//The number of passes is the size of the set.
//Runtime: O(n log n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    set<int> curr;
    for (int i = 0; i < n; i++) {
        if (curr.count(nums[i] - 1)) {
            curr.erase(nums[i] - 1);
        }
        curr.insert(nums[i]);
    }

    cout << curr.size() << '\n';
}