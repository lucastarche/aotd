//PE 13: Large Sum
//Problem: Given a hundred 50-digit numbers, find the first ten digits of the sum of the numbers.
//Solution: We can take the first 15 digits (this is the biggest number such that we dont overflow a long long) from every number, and add them together.
//Then we return the first ten digits of said sum.
//Note that this can also be solved by using BigInteger addition.
//Runtime: O(n*m), where n is the number of strings, and m is the amount of digits.
#include "EulerUtils.hpp"

long long solve(vector<string> nums) {
    vector<long long> arr(100, 0LL);
    for (int i = 0; i < 100; i++) {
        arr[i] = stoll(nums[i].substr(0, 15));
    }

    long long ans = 0LL;
    for (auto a : arr)
        ans += a;

    while (ans > 10000000000LL) {
        ans /= 10LL;
    }

    return ans;
}

int main() {
    ifstream in("input-013.txt");
    vector<string> nums(100);
    for (int i = 0; i < 100; i++) {
        getline(in, nums[i]);
    }
    cout << solve(nums) << '\n';
}
