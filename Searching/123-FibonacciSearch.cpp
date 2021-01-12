//Fibonacci Search
//An algorithm similar to binary search, but that employs fibonacci numbers to partition the array. 
//Was more useful back in the day when division and multiplication, which are used for binary search, were more expensive.
//We assume that the elements are already sorted.
//Runtime: O(log n)
#include <bits/stdc++.h>

using namespace std;

int FibonacciSearch(const vector<int> &arr, int target) {
    int n = (int)arr.size();
    vector<int> fib = {0, 1};
    while (fib.back() < n) {
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    }

    int k = (int)fib.size() - 1;
    int offset = 0;
    while (k > 0) {
        if (arr[fib[k - 1] + offset] == target) {
            return fib[k - 1] + offset;
        }
        else if (arr[fib[k - 1] + offset] > target) {
            k--;
        }
        else {
            offset += fib[k - 1];
            k -= 2;
        }
    }
    
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i];

    int q;
    cin >> q;
    cout << FibonacciSearch(nums, q) << '\n';
}