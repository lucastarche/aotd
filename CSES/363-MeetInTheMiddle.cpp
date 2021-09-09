//Meet in the Middle
//Problem: Given a list of n <= 40 numbers, find the number of subsets with sum equal to exactly x
//Solution: Doing a bruteforce which iterates through all 2^40 subsets will definitely not fit, so we have to come up with something faster
//The key is to notice that we can split our sum into a left subset and a right subset, and add them together
//We have 2^(n / 2) in the left, and 2^(n / 2) on the right half.
//We first start by adding every possible subset sum in the left set to a vector, which we then sort and convert to a binary-searchable list of pairs which holds the sum, and the amount of times it appears
//After this, we iterate through every possible right subset, and binary search in the vector we just generated for (x - sum)
//If this value is in the vector, we add the amount of times it appears to the answer, and do so for every subset on the right, yielding our answer
//Runtime: O(n * 2^(n / 2))
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int lower_half = n / 2;
    int higher_half = n / 2 + n % 2;

    vector<long long> lower_sums;
    for (int i = 0; i < (1 << lower_half); i++) {
        long long curr = 0LL;
        for (int j = 0; j < lower_half; j++) {
            if ((1 << j) & i) {
                curr += nums[j];
            }
        }
        lower_sums.push_back(curr);
    }

    sort(lower_sums.begin(), lower_sums.end());
    int x = (int)lower_sums.size();

    vector<pair<long long, long long>> lower_amount;
    long long curr = 1;
    for (int i = 1; i < x; i++) {
        if (lower_sums[i] == lower_sums[i - 1]) {
            curr++;
        } else {
            lower_amount.push_back({ lower_sums[i - 1], curr });
            curr = 1LL;
        }
    }
    lower_amount.push_back({ lower_sums[x - 1], curr });

    long long ans = 0LL;
    for (int i = 0; i < (1 << higher_half); i++) {
        long long curr = 0LL;
        for (int j = 0; j < higher_half; j++) {
            if ((1 << j) & i) {
                curr += nums[lower_half + j];
            }
        }

        long long diff = k - curr;
        int idx = lower_bound(lower_amount.begin(), lower_amount.end(), diff, [](const pair<long long, long long>& lhs, const long long& rhs) -> bool {
            return lhs.first < rhs;
        }) - lower_amount.begin();

        if (lower_amount[idx].first == diff) {
            ans += lower_amount[idx].second;
        }
    }

    cout << ans << '\n';
}