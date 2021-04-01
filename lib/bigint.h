/*
    bigint.h

    bigint Library for C++

    MIT License

    Created by Roshan Gupta on 16-10-2020
    Copyright (c) 2020 Roshan Gupta

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#pragma once

#include <limits>
#include <math.h>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Macros for Programmer(User) use cases.

#define big_abs bigint::_big_abs
#define big_max bigint::_big_max
#define big_min bigint::_big_min
#define big_pow bigint::_big_pow
#define big_sqrt bigint::_big_sqrt
#define big_log2 bigint::_big_log2
#define big_log10 bigint::_big_log10
#define big_logwithbase bigint::_big_logwithbase
#define big_antilog2 bigint::_big_antilog2
#define big_antilog10 bigint::_big_antilog10
#define big_swap bigint::_big_swap
#define big_reverse bigint::_big_reverse
#define big_gcd bigint::_big_gcd
#define big_lcm bigint::_big_lcm
#define big_fact bigint::_big_fact
#define big_isPrime bigint::_big_isPrime
#define big_isPalindrome bigint::_big_isPalindrome
#define to_bigint bigint::_to_bigint

// Big Integer Class

class bigint {
private:
    string str; // only data memeber for strong Big Integer as String. [For signed int, str[0] = '-']

    // Function Definitions for Internal Uses

    static string trim(string);
    static string add(string, string);
    static string subtract(string, string);
    static string multiply(string, string);
    static string divide(string, string);

    static string mod(string, string);
    static string shortDivide(string, unsigned long long int);
    static string maximum(string, string);
    static bool is_maximum(string, string);
    static bool is_strictlyMaximum(string, string);
    static string minimum(string, string);
    static bool is_minimum(string, string);
    static bool is_strictlyMinimum(string, string);
    static bool is_bigint(string);

    // Public Property

    static string abs(string);
    static string pow(string, string);
    static string sqrt(string);
    static string log2(string);
    static string log10(string);
    static string logwithbase(string, string);
    static string antilog2(string);
    static string antilog10(string);
    static void swap(string&, string&);
    static string reverse(string);
    static string gcd(string, string);
    static string lcm(string, string);
    static string fact(string);
    static bool isPalindrome(string);
    static bool isPrime(string);

public:
    // Constructors for big int.
    bigint() {
        str = '0'; //default value
    }
    bigint(string s) {
        if (!is_bigint(s))
            throw runtime_error("Invalid Big Integer has been fed."); // if the input string is not valid number.
        str = s;
    }
    bigint(long long int n) {
        str = to_string(n);
    }
    bigint(int n) {
        str = to_string(n);
    }
    bigint(long int n) {
        str = to_string(n);
    }
    bigint(const bigint& n) {
        str = n.str;
    }

    // operator overloading for output stream {<<}
    friend ostream& operator<<(ostream& stream, const bigint& n) {
        stream << n.str;
        return stream;
    }

    // operator overloading for input stream {>>}
    friend istream& operator>>(istream& stream, bigint& n) {
        stream >> n.str;
        return stream;
    }

    /* Operator {+} Overloadings, for different kind of 
        parameter for the programmer's convinience  */

    bigint operator+(bigint const& n) {
        bigint ans;
        ans.str = add(str, n.str);
        return ans;
    }
    friend bigint operator+(bigint const& n1, int n2) {
        bigint ans;
        ans.str = add(n1.str, to_string(n2));
        return ans;
    }
    friend bigint operator+(int n1, bigint const& n2) {
        bigint ans;
        ans.str = add(n2.str, to_string(n1));
        return ans;
    }
    friend bigint operator+(bigint const& n1, long int n2) {
        bigint ans;
        ans.str = add(n1.str, to_string(n2));
        return ans;
    }
    friend bigint operator+(long int n1, bigint const& n2) {
        bigint ans;
        ans.str = add(n2.str, to_string(n1));
        return ans;
    }
    friend bigint operator+(bigint const& n1, long long int n2) {
        bigint ans;
        ans.str = add(n1.str, to_string(n2));
        return ans;
    }
    friend bigint operator+(long long int n1, bigint const& n2) {
        bigint ans;
        ans.str = add(n2.str, to_string(n1));
        return ans;
    }

    // Extra shortcut feature

    bigint& operator+=(bigint const n) {
        (*this).str = add((*this).str, n.str);
        return (*this);
    }

    /* Operator {-} Overloadings, for different kind of 
        parameter for the programmer's convinience  */

    bigint operator-(bigint const& n) {
        bigint ans;
        ans.str = subtract(str, n.str);
        return ans;
    }

    friend bigint operator-(bigint const& n1, int n2) {
        bigint ans;
        ans.str = subtract(n1.str, to_string(n2));
        return ans;
    }
    friend bigint operator-(int n1, bigint const& n2) {
        bigint ans;
        ans.str = subtract(to_string(n1), n2.str);
        return ans;
    }
    friend bigint operator-(bigint const& n1, long int n2) {
        bigint ans;
        ans.str = subtract(n1.str, to_string(n2));
        return ans;
    }
    friend bigint operator-(long int n1, bigint const& n2) {
        bigint ans;
        ans.str = subtract(to_string(n1), n2.str);
        return ans;
    }
    friend bigint operator-(bigint const& n1, long long int n2) {
        bigint ans;
        ans.str = subtract(n1.str, to_string(n2));
        return ans;
    }
    friend bigint operator-(long long int n1, bigint const& n2) {
        bigint ans;
        ans.str = subtract(to_string(n1), n2.str);
        return ans;
    }

    // Extra shortcut feature

    bigint& operator-=(bigint const n) {
        (*this).str = subtract((*this).str, n.str);
        return (*this);
    }

    /* Operator {*} Overloadings, for different kind of 
        parameter for the programmer's convinience  */

    bigint operator*(bigint const& n) {
        bigint ans;
        ans.str = multiply(str, n.str);
        return ans;
    }
    friend bigint operator*(bigint const& n1, int n2) {
        bigint ans;
        ans.str = multiply(n1.str, to_string(n2));
        return ans;
    }
    friend bigint operator*(int n1, bigint const& n2) {
        bigint ans;
        ans.str = multiply(to_string(n1), n2.str);
        return ans;
    }
    friend bigint operator*(bigint const& n1, long int n2) {
        bigint ans;
        ans.str = multiply(n1.str, to_string(n2));
        return ans;
    }
    friend bigint operator*(long int n1, bigint const& n2) {
        bigint ans;
        ans.str = multiply(to_string(n1), n2.str);
        return ans;
    }
    friend bigint operator*(bigint const& n1, long long int n2) {
        bigint ans;
        ans.str = multiply(n1.str, to_string(n2));
        return ans;
    }
    friend bigint operator*(long long int n1, bigint const& n2) {
        bigint ans;
        ans.str = multiply(to_string(n1), n2.str);
        return ans;
    }
    // Extra shortcut feature

    bigint& operator*=(bigint const n) {
        (*this).str = multiply((*this).str, n.str);
        return (*this);
    }

    /* Operator {/} Overloadings, for different kind of 
        parameter for the programmer's convinience  */

    bigint operator/(bigint const& n) {
        bigint ans;
        ans.str = divide(str, n.str);
        return ans;
    }
    friend bigint operator/(bigint const& n1, int n2) {
        bigint ans;
        ans.str = divide(n1.str, to_string(n2));
        return ans;
    }
    friend bigint operator/(int n1, bigint const& n2) {
        bigint ans;
        ans.str = divide(to_string(n1), n2.str);
        return ans;
    }
    friend bigint operator/(bigint const& n1, long int n2) {
        bigint ans;
        ans.str = divide(n1.str, to_string(n2));
        return ans;
    }
    friend bigint operator/(long int n1, bigint const& n2) {
        bigint ans;
        ans.str = divide(to_string(n1), n2.str);
        return ans;
    }
    friend bigint operator/(bigint const& n1, long long int n2) {
        bigint ans;
        ans.str = divide(n1.str, to_string(n2));
        return ans;
    }
    friend bigint operator/(long long int n1, bigint const& n2) {
        bigint ans;
        ans.str = divide(to_string(n1), n2.str);
        return ans;
    }

    // Extra shortcut feature

    bigint& operator/=(bigint const n) {
        (*this).str = divide((*this).str, n.str);
        return (*this);
    }

    /* Operator {%} Overloadings, for different kind of 
        parameter for the programmer's convinience  */

    bigint operator%(bigint const& n) {
        bigint ans;
        ans.str = mod(str, n.str);
        return ans;
    }
    friend bigint operator%(bigint const& n1, int n2) {
        bigint ans;
        ans.str = mod(n1.str, to_string(n2));
        return ans;
    }
    friend bigint operator%(int n1, bigint const& n2) {
        bigint ans;
        ans.str = mod(to_string(n1), n2.str);
        return ans;
    }
    friend bigint operator%(bigint const& n1, long int n2) {
        bigint ans;
        ans.str = mod(n1.str, to_string(n2));
        return ans;
    }
    friend bigint operator%(long int n1, bigint const& n2) {
        bigint ans;
        ans.str = mod(to_string(n1), n2.str);
        return ans;
    }
    friend bigint operator%(bigint const& n1, long long int n2) {
        bigint ans;
        ans.str = mod(n1.str, to_string(n2));
        return ans;
    }
    friend bigint operator%(long long int n1, bigint const& n2) {
        bigint ans;
        ans.str = mod(to_string(n1), n2.str);
        return ans;
    }

    // Extra shortcut feature

    bigint& operator%=(bigint const n) {
        (*this).str = mod((*this).str, n.str);
        return (*this);
    }

    //-------------------------------------------------
    //------------Increment and Decrement--------------
    //-------------------------------------------------

    /* Operator {++} Overloadings
        for the pre incremention  */
    bigint& operator++() {
        (*this).str = add((*this).str, "1");
        return (*this);
    }
    /* Operator {++} Overloadings
        for the post incremention  */
    bigint operator++(int) {
        (*this).str = add((*this).str, "1");
        return (*this);
    }

    /* Operator {--} Overloadings
        for the pre decremention  */
    bigint& operator--() {
        (*this).str = subtract((*this).str, "1");
        return (*this);
    }

    /* Operator {--} Overloadings
        for the post incremention  */
    bigint operator--(int) {
        (*this).str = subtract((*this).str, "1");
        return (*this);
    }

    //-------------------------------------------------
    //------------Conditional Operators----------------
    //-------------------------------------------------

    /* Operator {>} Overloadings, for different kind of 
        parameter for the programmer's convinience  */

    bool operator>(bigint const& n) {
        return is_strictlyMaximum(str, n.str);
    }
    friend bool operator>(bigint const& n1, int n2) {
        return is_strictlyMaximum(n1.str, to_string(n2));
    }
    friend bool operator>(int n1, bigint const& n2) {
        return is_strictlyMaximum(to_string(n1), n2.str);
    }
    friend bool operator>(bigint const& n1, long int n2) {
        return is_strictlyMaximum(n1.str, to_string(n2));
    }
    friend bool operator>(long int n1, bigint const& n2) {
        return is_strictlyMaximum(to_string(n1), n2.str);
    }
    friend bool operator>(bigint const& n1, long long int n2) {
        return is_strictlyMaximum(n1.str, to_string(n2));
    }
    friend bool operator>(long long int n1, bigint const& n2) {
        return is_strictlyMaximum(to_string(n1), n2.str);
    }

    /* Operator {<} Overloadings, for different kind of 
        parameter for the programmer's convinience  */

    bool operator<(bigint const& n) {
        return is_strictlyMinimum(str, n.str);
    }
    friend bool operator<(bigint const& n1, int n2) {
        return is_strictlyMinimum(n1.str, to_string(n2));
    }
    friend bool operator<(int n1, bigint const& n2) {
        return is_strictlyMinimum(to_string(n1), n2.str);
    }
    friend bool operator<(bigint const& n1, long int n2) {
        return is_strictlyMinimum(n1.str, to_string(n2));
    }
    friend bool operator<(long int n1, bigint const& n2) {
        return is_strictlyMinimum(to_string(n1), n2.str);
    }
    friend bool operator<(bigint const& n1, long long int n2) {
        return is_strictlyMinimum(n1.str, to_string(n2));
    }
    friend bool operator<(long long int n1, bigint const& n2) {
        return is_strictlyMinimum(to_string(n1), n2.str);
    }

    /* Operator {>=} Overloadings, for different kind of 
        parameter for the programmer's convinience  */

    bool operator>=(bigint const& n) {
        return is_maximum(str, n.str);
    }
    friend bool operator>=(bigint const& n1, int n2) {
        return is_maximum(n1.str, to_string(n2));
    }
    friend bool operator>=(int n1, bigint const& n2) {
        return is_maximum(to_string(n1), n2.str);
    }
    friend bool operator>=(bigint const& n1, long int n2) {
        return is_maximum(n1.str, to_string(n2));
    }
    friend bool operator>=(long int n1, bigint const& n2) {
        return is_maximum(to_string(n1), n2.str);
    }
    friend bool operator>=(bigint const& n1, long long int n2) {
        return is_maximum(n1.str, to_string(n2));
    }
    friend bool operator>=(long long int n1, bigint const& n2) {
        return is_maximum(to_string(n1), n2.str);
    }

    /* Operator {<=} Overloadings, for different kind of 
        parameter for the programmer's convinience  */

    bool operator<=(bigint const& n) {
        return is_minimum(str, n.str);
    }
    friend bool operator<=(bigint const& n1, int n2) {
        return is_minimum(n1.str, to_string(n2));
    }
    friend bool operator<=(int n1, bigint const& n2) {
        return is_minimum(to_string(n1), n2.str);
    }
    friend bool operator<=(bigint const& n1, long int n2) {
        return is_minimum(n1.str, to_string(n2));
    }
    friend bool operator<=(long int n1, bigint const& n2) {
        return is_minimum(to_string(n1), n2.str);
    }
    friend bool operator<=(bigint const& n1, long long int n2) {
        return is_minimum(n1.str, to_string(n2));
    }
    friend bool operator<=(long long int n1, bigint const& n2) {
        return is_minimum(to_string(n1), n2.str);
    }

    /* Operator {==} Overloadings, for different kind of 
        parameter for the programmer's convinience  */

    bool operator==(bigint const& n) {
        return (*this).str == n.str;
    }
    friend bool operator==(bigint const& n1, int n2) {
        return n1.str == to_string(n2);
    }
    friend bool operator==(int n1, bigint const& n2) {
        return to_string(n1) == n2.str;
    }
    friend bool operator==(bigint const& n1, long int n2) {
        return n1.str == to_string(n2);
    }
    friend bool operator==(long int n1, bigint const& n2) {
        return to_string(n1) == n2.str;
    }
    friend bool operator==(bigint const& n1, long long int n2) {
        return n1.str == to_string(n2);
    }
    friend bool operator==(long long int n1, bigint const& n2) {
        return to_string(n1) == n2.str;
    }

    /* Operator {!=} Overloadings, for different kind of 
        parameter for the programmer's convinience  */

    bool operator!=(bigint const& n) {
        return (*this).str != n.str;
    }
    friend bool operator!=(bigint const& n1, int n2) {
        return n1.str != to_string(n2);
    }
    friend bool operator!=(int n1, bigint const& n2) {
        return to_string(n1) != n2.str;
    }
    friend bool operator!=(bigint const& n1, long int n2) {
        return n1.str != to_string(n2);
    }
    friend bool operator!=(long int n1, bigint const& n2) {
        return to_string(n1) != n2.str;
    }
    friend bool operator!=(bigint const& n1, long long int n2) {
        return n1.str != to_string(n2);
    }
    friend bool operator!=(long long int n1, bigint const& n2) {
        return to_string(n1) != n2.str;
    }

    //-----------------------------------------------------------
    //--------Function Definitions for External Uses-------------
    //-----------------------------------------------------------

    static bigint _big_max(bigint& a, bigint& b) { // returns the maximum value between two Big Integers.
        bigint ans;
        ans.str = maximum(a.str, b.str);
        return ans;
    }
    static bigint _big_min(bigint& a, bigint& b) { // returns the minimum value between two Big Integers.
        bigint ans;
        ans.str = minimum(a.str, b.str);
        return ans;
    }
    static bigint _big_abs(bigint& a) { // returns the absolute value of Big Integer.
        bigint ans;
        ans.str = abs(a.str);
        return ans;
    }
    static bigint _big_pow(bigint& a, bigint& b) { // returns the power value between two Big Integers i.e., a^b, ^ -> power
        bigint ans;
        ans.str = pow(a.str, b.str);
        return ans;
    }
    static bigint _big_sqrt(bigint& a) { // returns the square root value of Big Integer.
        bigint ans;
        ans.str = sqrt(a.str);
        return ans;
    }
    static bigint _big_log2(bigint& a) { // returns the log of Big Integer to the base of 2.
        bigint ans;
        ans.str = log2(a.str);
        return ans;
    }
    static bigint _big_log10(bigint& a) { // returns the log of Big Integer to the base of 10.
        bigint ans;
        ans.str = log10(a.str);
        return ans;
    }
    static bigint _big_logwithbase(bigint& a, bigint& b) { // returns the log of Big Integer(a) to the base of (b).
        bigint ans;
        ans.str = logwithbase(a.str, b.str);
        return ans;
    }
    static bigint _big_antilog2(bigint& a) { // returns the antilog of Big Integer to the base of 2.
        bigint ans;
        ans.str = antilog2(a.str);
        return ans;
    }
    static bigint _big_antilog10(bigint& a) { // returns the antilog of Big Integer to the base of 10.
        bigint ans;
        ans.str = antilog10(a.str);
        return ans;
    }
    static void _big_swap(bigint& a, bigint& b) { // swaps the two Big Integers.
        swap(a.str, b.str);
    }
    static bigint _big_reverse(bigint& a) { //Reverses the Big Integer.
        bigint ans;
        ans.str = reverse(a.str);
        return ans;
    }
    static bigint _big_gcd(bigint& a, bigint& b) { // returns the gcd of Big Integers a and b.
        bigint ans;
        ans.str = gcd(a.str, b.str);
        return ans;
    }
    static bigint _big_lcm(bigint& a, bigint& b) { // returns the lcm of Big Integers a and b.
        bigint ans;
        ans.str = lcm(a.str, b.str);
        return ans;
    }
    static bigint _big_fact(bigint& a) { // returns the factorial of Big Integer.
        bigint ans;
        ans.str = fact(a.str);
        return ans;
    }
    static bool _big_isPalindrome(bigint& a) { // Check if the Big Integer is Palindromic Integer.
        return isPalindrome(a.str);
    }
    static bool _big_isPrime(bigint& a) { // Check if the Big Integer is Prime Integer.
        return isPrime(a.str);
    }

    // to biginteger functions

    static bigint _to_bigint(string s) {
        bigint ans;
        ans.str = s;
        return ans;
    }
    static bigint _to_bigint(int n) {
        bigint ans;
        ans.str = to_string(n);
        return ans;
    }
    static bigint _to_bigint(long int n) {
        bigint ans;
        ans.str = to_string(n);
        return ans;
    }
    static bigint _to_bigint(long long int n) {
        bigint ans;
        ans.str = to_string(n);
        return ans;
    }
};

bool bigint::is_bigint(string s) { // Checks if the feeded integer is valid Number or not.
    if (s[0] == '-')
        s.erase(0, 1);
    for (unsigned long long int i = 0; i < s.length(); ++i) {
        if (!((int)s[i] > 47 && (int)s[i] < 58))
            return false;
    }
    return true;
}

//---------------------------------------------------------
//--------Internal Arithmetic functions Definitions--------
//---------------------------------------------------------

/*
        ______________________________________________________
                        Addition Function
        ______________________________________________________
                      Algorithm Explanation

        Simple traversal from right to left in the longest string and adding each character 
        from each of both strings as integer and keeping track of carry and storing the result 
        into new String(sum). If the numbers are negative in either of the Strings provided 
        the respective Subtract function is called.

        Algorithmic Time Complexity : O(max(n, m))
        Algorithmic Space Complexity : O(max(n, m))
        where n ans m are the lengths of respective strings(Integers) provided.
*/

string bigint::add(string str1, string str2) { // returns arithmetic addition of str1+str2
    int str1_len = str1.length();
    int str2_len = str2.length();
    string sum = "";

    if (str1_len == 0 && str2_len == 0) {
        sum = "0";
    } else if (str1[0] == '-' && str2[0] == '-') {
        if (str1_len == 1 && str2_len == 1) {
            sum = "0";
        } else {
            sum = "-" + add(str1.erase(0, 1), str2.erase(0, 1));
        }
    } else if (str1[0] == '-') {
        sum = subtract(str2, str1.erase(0, 1));
    } else if (str2[0] == '-') {
        sum = subtract(str1, str2.erase(0, 1));
    } else {
        int i, j, track_sum, carry = 0;
        for (i = str1_len - 1, j = str2_len - 1; i >= 0 && j >= 0; --i, --j) {
            track_sum = ((int)str1[i]) - 48 + ((int)str2[j]) - 48 + carry;
            carry = track_sum / 10;
            sum = to_string(track_sum % 10) + sum;
        }
        if (i >= 0 && j < 0) {
            for (; i >= 0; --i) {
                track_sum = ((int)str1[i]) - 48 + carry;
                carry = track_sum / 10;
                sum = to_string(track_sum % 10) + sum;
            }
        } else if (j >= 0 && i < 0) {
            for (; j >= 0; --j) {
                track_sum = ((int)str2[j]) - 48 + carry;
                carry = track_sum / 10;
                sum = to_string(track_sum % 10) + sum;
            }
        }
        if (carry) {
            sum = to_string(carry) + sum;
        }
    }
    return trim(sum);
}

/*
        ______________________________________________________
                      Subtraction Function
        ______________________________________________________
                      Algorithm Explanation

        Simple traversal from right to left in the longest string and subtracting each character 
        from second string fro  first string integer and keeping track of carry and storing the result 
        into new String(ans). If the both numbers are negative in the Strings provided the respective 
        Addition function is called.
        
        Algorithmic Time Complexity : O(max(n, m))
        Algorithmic Space Complexity : O(max(n, m))
        where n ans m are the lengths of respective strings(Integers) provided.
*/

string bigint::subtract(string str1, string str2) { // returns arithmetic subtraction of str1-str2
    int str1_len = str1.length();
    int str2_len = str2.length();
    string sum = "";
    if (str1 == str2) {
        return "0";
    } else if (str1[0] == '-' && str2[0] == '-') {
        if (str2_len == 1 && str1_len == 1) {
            sum = "0";
        } else {
            bigint t1(str1.erase(0, 1));
            bigint t2(str2.erase(0, 1));
            string temp = subtract(t2.str, t1.str);
            bigint mx = maximum(t2.str, t1.str);
            if (temp[0] != '-' && mx.str == t1.str)
                sum = "-" + temp;
            else
                sum = temp;
        }
    } else if (str1[0] == '-') {
        sum = "-" + add(str1.erase(0, 1), str2);
    } else if (str2[0] == '-') {
        sum = add(str1, str2.erase(0, 1));
    } else {
        //? Implement Subtract

        int i, j, track_sum, carry = 0;
        if (str1_len < str2_len) {
            string tp = str1;
            str1 = str2;
            str2 = tp;
            sum = "-" + subtract(str1, str2);
            return trim(sum);
        } else if (str1_len == str2_len) {
            bigint a(str1);
            bigint b(str2);
            bigint mx = maximum(a.str, b.str);
            if (mx.str == str2) {
                string tp = str1;
                str1 = str2;
                str2 = tp;
                bigint t1(str1);
                bigint t2(str2);
                bigint temp = subtract(str1, str2);
                sum = "-" + subtract(str1, str2);
                return trim(sum);
            }
        }
        int val1, val2;
        for (i = str1_len - 1, j = str2_len - 1; i >= 0 || j >= 0; --i, --j) {
            if (i >= 0) {
                val1 = (int)str1[i] - 48;
            } else {
                val1 = 0;
            }
            if (j >= 0) {
                val2 = (int)str2[j] - 48;
            } else {
                val2 = 0;
            }
            track_sum = val1 - val2 - carry;
            if (track_sum < 0) {
                track_sum += 10;
                carry = 1;
            } else {
                carry = 0;
            }
            sum = to_string(track_sum) + sum;
        }
    }
    return trim(sum);
}

/*
        ______________________________________________________
                     Multiplication Function
        ______________________________________________________
                      Algorithm Explanation

        Like naive way of Multiplication. Traversing from the left of first string and multiplying
        each character as integer to every character of second String as integer and tracking the
        value of carry and adding to the last of each iterations.
        
        Algorithmic Time Complexity : O(n*m)
        Algorithmic Space Complexity : O(n + m)
        where n ans m are the lengths of respective strings(Integers) provided.
*/

string bigint::multiply(string str1, string str2) { // return arithmetic multiplication of str1*str2
    bool toAddNeg = false;
    int str1_len = str1.length();
    int str2_len = str2.length();
    string ans = "";
    if (str1[0] == '-' && str2[0] == '-') {
        ans = multiply(str1.erase(0, 1), str2.erase(0, 1));
    } else if (str1[0] == '-') {
        toAddNeg = true;
        ans = multiply(str1.erase(0, 1), str2);
    } else if (str2[0] == '-') {
        toAddNeg = true;
        ans = multiply(str1, str2.erase(0, 1));
    } else {
        if (str1_len == 0 || str2_len == 0)
            return "0";
        vector<int> result(str1_len + str2_len, 0);
        int i_n1 = 0;
        int i_n2 = 0;
        for (int i = str1_len - 1; i >= 0; i--) {
            int carry = 0;
            int n1 = str1[i] - '0';
            i_n2 = 0;
            for (int j = str2_len - 1; j >= 0; j--) {
                int n2 = str2[j] - '0';
                int sum = n1 * n2 + result[i_n1 + i_n2] + carry;
                carry = sum / 10;
                result[i_n1 + i_n2] = sum % 10;
                i_n2++;
            }
            if (carry > 0)
                result[i_n1 + i_n2] += carry;
            i_n1++;
        }
        int i = result.size() - 1;
        while (i >= 0 && result[i] == 0)
            i--;
        if (i == -1)
            return "0";
        while (i >= 0)
            ans += std::to_string(result[i--]);
    }
    if (toAddNeg && ans[0] != '0') {
        ans = '-' + ans;
    }
    return ans;
}

/*
        ______________________________________________________
                        Division Function
        ______________________________________________________
                      Algorithm Explanation

        The divisor increases iteratively till it reaches the Dividend. For fast reaching, a 
        pre-determined limit is calculated depending upon the length difference of divisor
        and divident=d, and power of 10 is calculated for length of answer precision. Further simple
        addition is done till it reaches dividend.

        If the divisior can be strored in primitive type of Int. :
        As the dividend and result can be very large we store them in string. We first take 
        digits which are divisible by number. After this take each digit and store result in string.
        
        Algorithmic Time Complexity : O(log(val. of divisor))  , if divisor can be stored as primitive type
        Algorithmic Time Complexity : O((10^(len. diff.)) log(val. of divisor))
        Algorithmic Space Complexity : O(log(n-m))
        where n ans m are the lengths of respective strings(Integers) provided.
*/

string bigint::divide(string str1, string str2) { // return arithmetic division of str1/str2
    string ans = "";
    if (str2 == "0") {
        return "0";
    } else if (str1 == str2) {
        return "1";
    } else if (str1[0] == '-' && str2[0] == '-') {
        ans = divide(str1.erase(0, 1), str2.erase(0, 1));
    } else if (str1[0] == '-') {
        string temp = divide(str1.erase(0, 1), str2);
        if (temp == "0")
            ans = temp;
        else
            ans = '-' + temp;
    } else if (str2[0] == '-') {
        string temp = divide(str1, str2.erase(0, 1));
        if (temp == "0")
            ans = temp;
        else
            ans = '-' + temp;
    } else {
        if (str2 == "1")
            return str1;
        if (str2 == maximum(str1, str2))
            return "0";
        stringstream strstrm(str2);
        unsigned long long int int_str2 = 0;
        strstrm >> int_str2;
        if (int_str2 <= std::numeric_limits<unsigned long long>::max()) {
            ans = shortDivide(str1, int_str2);
        } else {
            string temp = str2;
            ans = "0";
            string count = "1";
            long long int len_diff = (long long int)str1.length() - str2.length();
            len_diff--;
            int lim = 1;
            if (str1[0] == '1' && str1[1] == '0')
                lim = 2;
            while (len_diff > lim) {
                count = add(count, pow("10", to_string(len_diff)));
                temp = add(multiply(str2, pow("10", to_string(len_diff))), temp);
                len_diff--;
            }
            while (str1 == maximum(temp, str1) && temp != str1) {
                temp = add(temp, str2);
                count = add(count, "1");
            }
            if (temp == str1)
                ans = count;
            else
                ans = subtract(count, "1");
        }
    }
    return ans;
}

string bigint::shortDivide(string s1, unsigned long long int divisor) { // return arithmetic division of str1/str2
    string ans;
    int idx = 0;
    long long int temp = s1[idx] - '0';

    while (temp < divisor) {
        temp = temp * 10 + (s1[++idx] - '0');
        if (idx >= s1.length())
            break;
    }
    while (s1.length() > idx) {
        ans += (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + s1[++idx] - '0';
    }

    if (ans.length() == 0)
        return "0";

    return ans;
}

string bigint::mod(string str1, string str2) { // return arithmetic modulos of str1%str2
    string ans = subtract(str1, multiply(divide(str1, str2), str2));
    if (ans[0] == '-')
        ans.erase(0, 1);
    return ans;
}

string bigint::maximum(string str1, string str2) { // return maximum of both strings.
    string max = "";
    bool bothNeg = false;
    bool isMax1 = false;
    bool isMax2 = false;
    if (str1[0] == '-' && str2[0] == '-') {
        bothNeg = true;
        str1.erase(0, 1);
        str2.erase(0, 1);
    } else if (str1[0] == '-') {
        return trim(str2);
    } else if (str2[0] == '-') {
        return trim(str1);
    }
    int str1_len = str1.length(), str2_len = str2.length();
    if (str1_len == str2_len) {
        for (int i = 0; i < str1_len; ++i) {
            if (str1[i] != str2[i]) {
                if (str1[i] > str2[i]) {
                    isMax1 = true;
                } else {
                    isMax2 = true;
                }
                break;
            }
        }
        if (!(isMax2 ^ isMax1)) {
            isMax1 = true;
        }
    } else if (str1_len > str2_len) {
        isMax1 = true;
    } else {
        isMax2 = true;
    }
    if (bothNeg) {
        if (isMax1)
            return ("-" + trim(str2));
        else
            return ("-" + trim(str1));
    } else {
        if (isMax1)
            return trim(str1);
        else
            return trim(str2);
    }
}

string bigint::minimum(string str1, string str2) { // return minimum of both strings.
    string ans = maximum(str1, str2);
    if (ans == str1)
        return str2;
    return str1;
}

bool bigint::is_maximum(string str1, string str2) { //checks if str1 >= str2, numerically
    if (str1 == maximum(str1, str2))
        return true;
    return false;
}

bool bigint::is_minimum(string str1, string str2) { //checks if str1 <= str2, numerically
    if (str2 == maximum(str1, str2))
        return true;
    return false;
}

bool bigint::is_strictlyMaximum(string str1, string str2) { //checks if str1 > str2, numerically
    if (str1 == str2)
        return false;
    if (str1 == maximum(str1, str2))
        return true;
    return false;
}

bool bigint::is_strictlyMinimum(string str1, string str2) { //checks if str1 < str2, numerically
    if (str1 == str2)
        return false;
    if (str2 == maximum(str1, str2))
        return true;
    return false;
}

string bigint::trim(string s) { // function to remove zeros
    if (s == "0")
        return s;
    if (s[0] == '-') {
        int i = 1;
        while (s[i] == '0') {
            s.erase(i, 1);
        }
        return s;
    } else if (s[0] == '0') {
        int i = 0;
        while (s[i] == '0') {
            s.erase(i, 1);
        }
        return s;
    }
    return s;
}

//____________________________________________________________________________________________

string bigint::abs(string s) { // returns absolute value of string
    if (s[0] == '-')
        s.erase(0, 1);
    return s;
}

/*
        ______________________________________________________
                        Power Function
        ______________________________________________________
                      Algorithm Explanation

        It multiplies str1, str2 times and updates the str1 value
        
        Algorithmic Time Complexity : O(m), except multiplication time complexity
        Algorithmic Space Complexity : O(1)
        where n ans m are the lengths of respective strings(Integers) provided.
*/

string bigint::pow(string str1, string str2) { // returns str1^str2, ^ -> power, numerically
    if (str2 == "0") {
        return "1";
    } else if (str1 == "0") {
        if (str2[0] == '-')
            return to_string((long long int)std::pow(0, -5));
        return "0";
    } else if (str1[0] == '-' && str2[0] == '-') {
        if (str1 == "-1" && str2 == "-1") {
            return "-1";
        } else if (str1 == "-1") {
            if ((((int)str2[str2.length() - 1]) - 48) & 1) {
                return "-1";
            } else {
                return "1";
            }
        } else {
            return "0";
        }
    } else if (str1[0] == '-') {
        if ((((int)str2[str2.length() - 1]) - 48) & 1)
            return '-' + pow(str1.erase(0, 1), str2);
        return pow(str1.erase(0, 1), str2);
    } else if (str2[0] == '-') {
        if (str1 == "1") {
            return str1;
        } else {
            return "0";
        }
    } else {
        string init_str1 = str1;
        while (str2 != "1") {
            str1 = multiply(str1, init_str1);
            str2 = subtract(str2, "1");
        }
        return str1;
    }
}

/*
        ______________________________________________________
                        Sqrt Function
        ______________________________________________________
                      Algorithm Explanation

        Since sqrt of a string(s) has length floor(s/2), if s's length is even and 
        ceil(s/2) if s's length is odd.
        So it performs binary Search in that answer's range.
        
        Algorithmic Time Complexity : O(log(val. of s)), except divide time complexity
        Algorithmic Space Complexity : O(s/2);
*/

string bigint::sqrt(string s) { // returns sqrt(s), numerically
    if (s[0] == '-')
        return s;
    if (s == "0")
        return "0";
    unsigned long long int s_len = s.length();
    string ans;
    string mid = "";
    string high, low, square;
    unsigned long long int ans_len = s_len >> 1;
    if (s_len & 1) {
        low = pow("10", to_string(ans_len));
        high = pow("10", to_string(ans_len + 1));
    } else {
        low = pow("10", to_string(ans_len - 1));
        high = pow("10", to_string(ans_len));
    }
    string prev;
    while (1) {
        mid = divide(add(high, low), "2");
        square = multiply(mid, mid);
        if (prev == mid || (maximum(add(square, mid), s) == add(square, mid) && maximum(square, s) == s) || high == low) {
            break;
        }
        if (maximum(square, s) == s) {
            low = mid;
        } else if (maximum(square, s) == square) {
            high = mid;
        }
        prev = mid;
    }
    ans = mid;
    return ans;
}

string bigint::log2(string s) { // returns log(s) to base of 2
    if (s == "0") {
        // throw new exception(std::out_of_range("log(0) is undefined"));
        return to_string(std::log2(0));
    }
    if (s[0] == '-') {
        // throw new exception(std::out_of_range("log(negative) is not allowed"));
        return to_string(std::log2(-1));
    }
    string logVal = "-1";
    while (s != "0") {
        logVal = add(logVal, "1");
        s = divide(s, "2");
    }
    return logVal;
}

string bigint::log10(string s) { // returns log(s) to base of 10
    if (s == "0") {
        // throw new exception(std::out_of_range("log(0) is undefined"));
        return to_string(std::log2(0));
    }
    if (s[0] == '-') {
        // throw new exception(std::out_of_range("log(negative) is not allowed"));
        return to_string(std::log2(-1));
    }
    return to_string(s.length() - 1);
}

string bigint::logwithbase(string val, string base) {
    return divide(log2(val), log2(base));
}

string bigint::antilog2(string s) {
    return pow("2", s);
}

string bigint::antilog10(string s) {
    return pow("10", s);
}

void bigint::swap(string& str1, string& str2) {
    string s;
    s = str1;
    str1 = str2;
    str2 = s;
}

string bigint::reverse(string s) { // reverses the string number, example: "7875" => "5787"
    bool fl = false;
    if (s[0] == '-') {
        s.erase(0, 1);
        fl = true;
    }
    unsigned long long int beg = 0, end = s.length() - 1;
    char ch;
    while (beg < end) {
        ch = s[beg];
        s[beg] = s[end];
        s[end] = ch;
        beg++;
        end--;
    }
    if (fl)
        s = '-' + s;
    return s;
}

/*
        ______________________________________________________
                        gcd Function
        ______________________________________________________
                      Algorithm Explanation

        It performs euclid method for finding greates common divisor
        
        Algorithmic Time Complexity : O(log(val. of str2)), except mod time complexity
        Algorithmic Space Complexity : O(log(str2)) in stack;
*/

string bigint::gcd(string str1, string str2) {
    if (is_strictlyMaximum(str2, str1))
        swap(str1, str2);
    string temp = "";
    while (is_strictlyMaximum(str2, "0")) {
        temp = mod(str1, str2);
        str1 = str2;
        str2 = temp;
    }
    return str1;
}

string bigint::lcm(string str1, string str2) { // return lcm of both str1 and str2
    return divide(multiply(str1, str2), gcd(str1, str2));
}

string bigint::fact(string s) { // returns the factorial of string s, numerically
    if (s[0] == '-') {
        throw runtime_error("Factorial of Negative Integer is not defined.");
    }
    if (s == "0")
        return "1";
    string ans = "1";
    while (s != "0") {
        ans = multiply(ans, s);
        s = subtract(s, "1");
    }
    return ans;
}

bool bigint::isPalindrome(string s) { // checks if the Integer as string, s is Palindrome no. or not
    if (s[0] == '-')
        s.erase(0, 1);
    unsigned long long int beg = 0, end = s.length() - 1;
    while (beg < end) {
        if (s[beg] != s[end])
            return false;
        beg++;
        end--;
    }
    return true;
}

bool bigint::isPrime(string s) { // checks if the String as Number is prime or not
    if (maximum(s, "2") != s)
        return false;
    string sqrt = bigint::sqrt(s);
    string i = "";
    for (i = "2"; is_maximum(sqrt, i); i = add(i, "1")) {
        if (mod(s, i) == "0")
            return false;
    }
    return true;
}
