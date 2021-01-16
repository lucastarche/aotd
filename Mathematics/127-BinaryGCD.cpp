//Binary Greatest Common Division
//A variation of Euclid's Algorithm, but instead of using divisions, it uses simpler arithmetic operations, such as addition, subtraction and bit shifts.
//Runtime: O(log n), assuming the arithmetic operations take constant time.
//Note that this fact does NOT hold for arbitrarily big integers, in which case the runtime is O(n^2)
#include <bits/stdc++.h>

using namespace std;

int BinaryGCD(int a, int b) {
    if (a == b) return a;
    else if (a == 0) return b;
    else if (b == 0) return a;

    if (a & 1) { //We can use this bittrick instead of using the modulo operator to get if a is odd.
        if (!(b & 1)) 
            return BinaryGCD(a, b >> 1); //Same as BinaryGCD(a, b / 2)
        else if (a > b) 
            return BinaryGCD((a - b) >> 1, b);
        else
            return BinaryGCD((b - a) >> 1, a);
    }
    else {
        if (b & 1) 
            return BinaryGCD(a >> 1, b);
        else 
            return BinaryGCD(a >> 1, b >> 1) << 1;
            //Same as 2 * BinaryGCD(a / 2, b / 2)
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << "GCD: " << BinaryGCD(a, b) << '\n';
}