//Big Integer
//This is a data structure which allows for numbers of arbitrarily long size (as long as the RAM can fit them).
//However, this comes with the disadvantage that arithmetic operations will take O(n) instead of O(1) in most cases.
//This is another mini-series, so the implementation will be split along multiple days.
#include <bits/stdc++.h>

using namespace std;

class BigInteger {
    private:
        string numStr;
        bool isNegative;
    public:
        BigInteger(string s) {
            isNegative = (s[0] == '-');
            if (s[0] == '-') {
                numStr = s.substr(1);
            }
            else if (s[0] == '+') {
                numStr = s.substr(1);
            }
            else {
                numStr = s;
            }
        }

        BigInteger(int num) {
            isNegative = (num < 0);
            if (num > 0) {
                numStr = to_string(num);
            }
            else {
                numStr = to_string(num).substr(1);
            }
        }

        //Arithmetic Operations
        BigInteger operator-(); //Unary Minus
        BigInteger operator+(BigInteger other);
        BigInteger operator-(BigInteger other);
        BigInteger operator*(BigInteger other);
        BigInteger operator/(BigInteger other);
        BigInteger operator%(BigInteger other);

        //Number Comparisons
        BigInteger operator==(BigInteger other);
        BigInteger operator<(BigInteger other);
        BigInteger operator<=(BigInteger other);
        BigInteger operator>(BigInteger other);
        BigInteger operator>=(BigInteger other);

        string toString() {
            if (isNegative) return '-' + numStr;
            return numStr;
        }
};