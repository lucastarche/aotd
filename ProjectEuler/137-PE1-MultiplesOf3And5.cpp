//PE1: Multiples of 3 and 5
//Shortened statement: Find the sum of all the multiples of 3 or 5 below 1000
//Solution: Easy problem, we can make an efficient (but not the fastest) algorithm by 
//just doing what we are said, that is, checking for each number whether or not it is a multiple of 3 or 5.
//Runtime: O(n)
#include <bits/stdc++.h>

using namespace std;

int solve() {
    int ans = 0;

    for (int i = 0; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) ans += i;
    }

    return ans;
}

int main() {
    cout << solve() << '\n';
}