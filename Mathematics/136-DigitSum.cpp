//Digit Sum
//Sums all the digits of a given number n.
//Runtime: O(log n)
#include <bits/stdc++.h>

using namespace std;

int DigitSum(int n) {
    n = abs(n);
    int ans = 0;
    while (n > 0) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << DigitSum(n) << '\n';
}