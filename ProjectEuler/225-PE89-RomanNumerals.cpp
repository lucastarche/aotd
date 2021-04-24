//PE 89: Roman Numerals
//Problem: Given a list of valid (but not minimal) roman numbers, find the number of characters saved by reducing them to the minimal form possible.
//Solution: Another hardcody one :(. Just parse the unminimized numbers to decimal, and then parse them to minimal roman.
//Runtime: O(n), where n is the number of characters in the input.
#include "EulerUtils.hpp"

long long romanToDecimal(string s) {
    int n = (int)s.size();
    long long curr = 0;
    for (int i = 0; i < n; i++) {
        switch (s[i]) {
        case 'M':
            curr += 1000;
            break;
        case 'D':
            curr += 500;
            break;
        case 'C':
            if (i != n - 1 && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
                if (s[i + 1] == 'D')
                    curr += 400;
                else
                    curr += 900;
                i++;
            } else {
                curr += 100;
            }
            break;
        case 'L':
            curr += 50;
            break;
        case 'X':
            if (i != n - 1 && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
                if (s[i + 1] == 'L')
                    curr += 40;
                else
                    curr += 90;
                i++;
            } else {
                curr += 10;
            }
            break;
        case 'V':
            curr += 5;
            break;
        case 'I':
            if (i != n - 1 && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
                if (s[i + 1] == 'V')
                    curr += 4;
                else
                    curr += 9;
                i++;
            } else {
                curr += 1;
            }
            break;
        }
    }

    return curr;
}

//Note: they have negative values in order to traverse them from greater to smaller
const map<long long, string> values = {
    { -1000, "M" },
    { -900, "CM" },
    { -500, "D" },
    { -400, "CD" },
    { -100, "C" },
    { -90, "XC" },
    { -50, "L" },
    { -40, "XL" },
    { -10, "X" },
    { -9, "IX" },
    { -5, "V" },
    { -4, "IV" },
    { -1, "I" }
};

string decimalToMinimalRoman(long long n) {
    if (n == 0)
        return "";
    for (auto [num, str] : values) {
        long long val = -num;
        if (val <= n) {
            return str + decimalToMinimalRoman(n - val);
        }
    }

    return "";
}

long long solve(vector<string> lines) {
    vector<long long> nums;
    long long characters = 0;
    for (auto s : lines) {
        characters += (long long)s.size();
        nums.push_back(romanToDecimal(s));
    }

    long long ans = 0;
    for (auto n : nums) {
        cout << n << ' ' << decimalToMinimalRoman(n) << '\n';
        ans += (long long)decimalToMinimalRoman(n).size();
    }

    return characters - ans;
}

int main() {
    ifstream in("input-089.txt");

    vector<string> lines;
    for (string s; getline(in, s);) {
        lines.push_back(s);
    }

    cout << solve(lines) << '\n';
}