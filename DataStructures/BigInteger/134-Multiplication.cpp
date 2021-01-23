//Big Integer: Multiplication
//This method uses the algorithm know as "long multiplication", which, unluckly, isnt very efficient on large inputs.
//To solve this, there also exist faster algorithms, such as Karatsuba multiplication.
//Runtime: O(n^2), where n is the sum of the number of digits between a and b.
#include "133-AdditionAndSubtraction.cpp"

BigInteger BigInteger::operator*(BigInteger other) {
    int n = (int)numStr.size();
    int m = (int)other.numStr.size();
    string ans((n + m), '0');

    for (int i = n - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = m - 1; j >= 0; j--) {
            ans[i + j + 1] += carry + (numStr[i] - '0') * (other.numStr[j] - '0');
            carry = (ans[i + j + 1] - '0') / 10;
            ans[i + j + 1] = (ans[i + j + 1] - '0') % 10 + '0';
        }
        ans[i] = carry + '0';
    }

    reverse(ans.begin(), ans.end());
    while (ans.back() == '0') ans.pop_back();
    if (isNegative != other.isNegative) {
        ans += '-';
    }
    reverse(ans.begin(), ans.end());
    return BigInteger(ans);
}