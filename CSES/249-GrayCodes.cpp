//Gray Codes
//Problem: Given a number n < 16, print the corresponding gray code of lenght n.
//A gray code of length 2 is: 00, 01, 10, 11, since it has every binary string of length 2,
//and there is a single character of difference between any two consecutive strings.
//Solution: We can build the gray code recursively, by getting the gray code of length n - 1, and adding its inverse.
//After this, we add a 0 to the start of the first half, and a 1 to the start of the second half.
//Runtime: O(2^n)
#include <bits/stdc++.h>

using namespace std;

vector<string> grayCode(int n) {
    if (n == 1)
        return { "0", "1" };

    vector<string> half = grayCode(n - 1);

    vector<string> copy = half;
    reverse(copy.begin(), copy.end());

    for (int i = 0; i < (int)half.size(); i++) {
        half[i] = '0' + half[i];
        copy[i] = '1' + copy[i];
    }

    half.reserve((int)half.size() * 2);
    half.insert(half.end(), copy.begin(), copy.end());
    return half;
}

int main() {
    int n;
    cin >> n;
    auto code = grayCode(n);

    for (auto a : code) {
        cout << a << '\n';
    }
}