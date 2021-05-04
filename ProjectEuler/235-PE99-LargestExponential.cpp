//PE 99: Largest Exponential
//Problem: Given a list of numbers n_i and m_i, find the index which has the greatest value of n_i ^ m_i
//Solution: Since we have n_i^m_i < n_j^m_j => ln(n_i^m_i) < ln(n_j^m_j), we can apply the natural log on both
//sides and fit the result into a double. Then we just find the maximum of these values and return its index.
//Note that ln(n_i ^ m_i) = m_i * ln(n_i) as well.
//Runtime: O(n)
#include "EulerUtils.hpp"

long long solve(const vector<pair<long long, long long>>& nums) {
    double curr = 0.0;
    long long index = -1;

    long long idx = 1;
    for (auto p : nums) {
        double val = log(p.first) * p.second;
        if (val > curr) {
            curr = val;
            index = idx;
        }
        idx++;
    }
    return index;
}

int main() {
    ifstream in("input-099.txt");
    vector<pair<long long, long long>> nums(1000);
    for (int i = 0; i < 1000; i++) {
        string curr;
        getline(in, curr);

        long long num = 0;
        for (auto c : curr) {
            if (c == ',') {
                nums[i].first = num;
                num = 0;
            } else {
                num *= 10LL;
                num += (c - '0');
            }
        }
        nums[i].second = num;
    }
    cout << solve(nums) << '\n';
}