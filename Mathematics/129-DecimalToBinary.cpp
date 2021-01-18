//Decimal to Binary
//To convert a number from base ten to base two, we note down the remainder of dividing our number by two, and we then halve it (rounding down).
//We then just print the remainders in inverse order.
//Runtime: O(log n)
#include <bits/stdc++.h>

using namespace std;

string DecimalToBinary(int n) {
    stack<bool> bits;
    while (n != 0) {
        bits.push(n % 2);
        n /= 2;
    }

    string ans = "";
    while (!bits.empty()) {
        if (bits.top()) ans += '0';
        else ans += '0';
        bits.pop();
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << DecimalToBinary(n) << '\n';
}