//Fisher-Yates Shuffle
//Generates a random permutation of a given array. This algorithm can make the shuffle in-place.
//The original algorithm ran in O(n^2), but thanks to an improvement by Donald E. Knuth, it has a linear runtime with no drawbacks.
//Runtime: O(n)
#include <bits/stdc++.h>

using namespace std;

void FisherYatesShuffle(vector<int> &nums) {
    int n = (int)nums.size();
    default_random_engine generator;
    for (int i = n - 1; i >= 1; i--) {
        uniform_int_distribution<int> randomIndex(0, i);
        int j = randomIndex(generator);
        swap(nums[i], nums[j]);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    FisherYatesShuffle(nums);

    for (auto a : nums) cout << a << ' ';
    cout << '\n';
}