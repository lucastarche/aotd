//Binary To Decimal
//We can convert a number from binary to decimal by multiplying each number with 2^(position - 1)
//Runtime: O(log n), where n is the number in decimal.
#include <bits/stdc++.h>

using namespace std;

int BinaryToDecimal(string binaryString) {
    int n = (int)binaryString.size();
    int ans = 0, pow = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (binaryString[i] == '1') {
            ans += 1 << pow;
        }
        pow++;
    }
    return ans;
}

int main() {
    string n;
    cin >> n;
    cout << BinaryToDecimal(n) << '\n';
}