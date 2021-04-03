//PE 68: Magic 5-Gon Ring
//Problem: Hard to explain, but in short, we want to dispose the numbers 1-10 in a figure in such a way that the sum of every segment yields the same result.
//Solution: We can place ten in the first position, since it will always be in the outer row (else we get a 17-digit string).
//After this, we can iterate through every possible disposition of the numbers, and if it is a magic ring, we update the result.
//Runtime: O((2n)!), where n is the ring dimension (5 in this case).
#include "EulerUtils.hpp"

bool isMagicRing(const array<int, 10>& arr) {
    bool valid = true;
    int sum = arr[4] + arr[9] + arr[5];

    for (int i = 0; i < 4; i++) {
        int curr_sum = arr[i] + arr[i + 5] + arr[i + 6];
        if (sum != curr_sum)
            valid = false;
    }

    return valid;
}

string getDigitString(const array<int, 10>& arr) {
    int min_val = arr[0], min_idx = 0;
    for (int i = 1; i < 5; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
            min_idx = i;
        }
    }

    string res = "";
    for (int i = 0; i < 5; i++) {
        res += to_string(arr[min_idx]);
        res += to_string(arr[min_idx + 5]);
        if (min_idx != 4)
            res += to_string(arr[min_idx + 6]);
        else
            res += to_string(arr[5]);

        min_idx++;
        min_idx %= 5;
    }

    return res;
}

long long solve() {
    array<int, 10> nums = { 10, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    long long ans = 0;
    do {
        if (!isMagicRing(nums))
            continue;
        ans = max(ans, stoll(getDigitString(nums)));
    } while (next_permutation(nums.begin(), nums.end()));

    return ans;
}

int main() {
    cout << solve() << '\n';
}