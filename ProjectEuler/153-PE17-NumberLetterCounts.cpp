//PE 17: Number Letter Counts
//Problem: Count the number of letters we would use if we wrote down all the numbers from 1 to 1000.
//Solution: Not much to say about this one. A bit tedious and annoying to implement, because there is a lot of hardcoding in the english language.
//Runtime: O(n), where n is the result of the problem.
#include "EulerUtils.hpp"

map<int, string> numString = {
    { 0, "zero" },
    { 1, "one" },
    { 2, "two" },
    { 3, "three" },
    { 4, "four" },
    { 5, "five" },
    { 6, "six" },
    { 7, "seven" },
    { 8, "eight" },
    { 9, "nine" },
    { 10, "ten" },
    { 11, "eleven" },
    { 12, "twelve" },
    { 13, "thirteen" },
    { 14, "fourteen" },
    { 15, "fifteen" },
    { 16, "sixteen" },
    { 17, "seventeen" },
    { 18, "eighteen" },
    { 19, "nineteen" },
    { 20, "twenty" },
    { 30, "thirty" },
    { 40, "forty" },
    { 50, "fifty" },
    { 60, "sixty" },
    { 70, "seventy" },
    { 80, "eighty" },
    { 90, "ninety" },
    { 100, "hundred" },
    { 1000, "thousand" }
};

//Note: This function will only work in the range [-1000, 1000].
string parseEnglish(int n) {
    if (n < 0)
        return "minus " + parseEnglish(-n);
    if (n < 20)
        return numString[n];
    if (n <= 90 && n % 10 == 0)
        return numString[n];
    if (n < 100)
        return numString[(int)(n / 10) * 10] + "-" + numString[n % 10];
    if (n <= 900 && n % 100 == 0)
        return numString[n / 100] + " " + numString[100];
    if (n < 1000)
        return parseEnglish((int)(n / 100) * 100) + " and " + parseEnglish(n % 100);
    if (n == 1000)
        return "one thousand";
    return "";
}

long long solve() {
    long long ans = 0LL;
    for (int i = 1; i <= 1000; i++) {
        string temp = parseEnglish(i);
        for (auto c : temp) {
            if (c != '-' && c != ' ')
                ans++;
        }
    }
    return ans;
}

int main() {
    cout << solve() << '\n';
}
