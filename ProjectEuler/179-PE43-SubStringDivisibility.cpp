//PE 43: SubString Divisibility
//Problem: Find the sum of all 0 to 9 pandigital numbers such that, if d1 is the first digit, d2 the second, and so on, the number d2d3d4 is divisible by 2, d3d4d5 is divisible by 3, d4d5d6 is divisible by 5, and so on.
//Example: in 1406357289, 406 is divisible by 2, 063 is divisible by 3, 635 is divisible by 5, and so on.
//Solution: We can make a string with all the numbers 0 through 9, and check for each permutation if the property holds or not.
//Note that, since the original number may not start with trailing zeroes, we start by 1023456789.
//Runtime: O(n! * n), where n is the number of digits.
#include "EulerUtils.hpp"

long long solve() {
    string s = "1023456789";
    long long ans = 0LL;
    vector<int> divisors = {1, 2, 3, 5, 7, 11, 13, 17};
    do {
        bool possible = true;

        for (int i = 0; i < (int)divisors.size(); i++) {
            if (stoll(s.substr(i, 3)) % divisors[i] != 0) possible = false;
        }

        if (possible) ans += stoll(s);
    } while (next_permutation(s.begin(), s.end()));
    return ans;
}

int main() {
    cout << solve() << '\n';
}
