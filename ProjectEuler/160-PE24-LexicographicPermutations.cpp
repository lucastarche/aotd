//PE 24: Lexicographic Permutation
//Problem: Find the millionth lexicographical permutation of the digits 0 through 9.
//Solution: Luckly, today C++'s stdlib has our back, so we can use the function next_permutation to get the desired answer.
//Runtime: O(n)
#include "EulerUtils.hpp"

long long solve() {
    std::string s = "0123456789";
    
    for (int i = 1; i < 1000000; i++) {
        next_permutation(s.begin(), s.end());
    }

    return stoll(s);
}

int main() {
    cout << solve() << '\n';
}
