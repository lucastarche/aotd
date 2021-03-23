//Binary Increment
//Increments a vector of bits by one, in which the bits are ordered with the most significant bits first.
//Runtime: O(n)
//Note that the increment of all ones in all zeroes.
#include <bits/stdc++.h>

using namespace std;

void binaryIncrement(vector<int>& bits) {
    int carry = true;
    for (int i = (int)bits.size() - 1; i >= 0; i--) {
        int temp = bits[i] ^ carry;
        carry = bits[i] & carry;
        bits[i] = temp;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> bits(n);
    for (int i = 0; i < n; i++)
        cin >> bits[i];

    binaryIncrement(bits);

    for (int i = 0; i < n; i++)
        cout << bits[i] << " ";
    cout << '\n';
}