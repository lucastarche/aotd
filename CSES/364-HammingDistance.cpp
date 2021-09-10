//Hamming Distance
//Problem: Given n binary strings with <32 characters, find the minimum hamming distance between any two of them (number of different bits)
//Solution: We can make a quadratic algorithm fit despite n being quite big
//The idea is to use bit operations to speed it up, since the Hamming Distance from a to b is just the number of 1 bits in (a^b)
//For this, we can use __builtin_popcount(), which does exactly this in about a single operation
//Runtime: O(n^2)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            nums[i] = nums[i] * 2 + getchar() - '0';
        }
        getchar();
    }

    int ans = 100;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = min(ans, __builtin_popcount(nums[i] ^ nums[j]));
        }
    }
    printf("%d\n", ans);
}