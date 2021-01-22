//Big Integer: Additions and Subtractions
//This algorithms aren't hard to implement, but maybe a bit tedious because of all the string operations we have to do.
//These are implemented similar to how we add and subtract when we are in primary school, but generalized to computers.
//Runtime: O(n), where n is the length of the string, or equivalently, O(log m), where m is the integer.
#include "132-BigInteger.cpp"

//Unary minus
BigInteger BigInteger::operator-() {
    if (isNegative) {
        return BigInteger(numStr);
    }
    else {
        return BigInteger('-' + numStr);
    }
}

BigInteger BigInteger::operator+(BigInteger other) {
    if (!isNegative && !other.isNegative) {
        string ans = "";
        int carry = 0, index = 1, sum = 0;
        int n = (int)numStr.size(), m = (int)other.numStr.size();

        while (index <= n || index <= m) {
            if (index > n) 
                sum = other.numStr[m - index] - '0' + carry;
            else if (index > m) 
                sum = numStr[n - index] - '0' + carry;            
            else 
                sum = (numStr[n - index] - '0') + (other.numStr[m - index] - '0') + carry;

            ans += (char)((sum % 10) + '0');
            carry = (int)(sum / 10);
            index++;
        }

        if (carry != 0) ans += (char)(carry + '0');

        reverse(ans.begin(), ans.end());
        return BigInteger(ans);
    }
    else if (isNegative && other.isNegative) 
        return -((-(*this)) + (-other));
    else if (isNegative) 
        return other - *this;
    else 
        return *this - other;
}

BigInteger BigInteger::operator-(BigInteger other) {
    if (numStr < other.numStr) {
        return -(other - (*this));
    }

    if (!isNegative && !other.isNegative) {
        string ans = "";
        int carry = 0, index = 1, delta = 0;
        int n = (int)numStr.size(), m = (int)other.numStr.size();
        
        while (index <= n || index <= m) {
            if (index > n) 
                delta = other.numStr[m - index] - '0' - carry;
            else if (index > m) 
                delta = numStr[n - index] - '0' - carry;            
            else 
                delta = (numStr[n - index] - '0') - (other.numStr[m - index] - '0') - carry;

            ans += (char)((delta % 10) + '0');
            carry = (int)(delta / 10);
            index++;
        }

        reverse(ans.begin(), ans.end());
        int zeroes = 0;
        while (ans[zeroes] == '0') zeroes++;
        ans = ans.substr(zeroes);
        return BigInteger(ans);
    }
    else if (isNegative && other.isNegative) 
        return other - (*this);
    else if (isNegative) 
        return -((*this) + other);
    else 
        return (*this) + other;
}