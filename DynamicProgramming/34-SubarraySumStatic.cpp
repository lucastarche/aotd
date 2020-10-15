//Subarray Sum (Static Version)
//The main idea is to precalculate all the values of the sums [0, i) for each i. Then, we can calculate the sums in O(1), by using the formula: sum(from, to) = sum(0, to) - sum(0, from).
//The runtime is O(q), where q is the number of queries, after O(n) preprocessing, where n is the number of elements.
#include <bits/stdc++.h>

using namespace std;

class SubarraySum {
    private:
        vector<int> prefix;
    public:
        SubarraySum(vector<int> &input) {
            int n = (int)input.size();
            prefix.resize(n + 1);
            for (int i = 0; i < n; i++) {
                prefix[i + 1] = input[i] + prefix[i];
            }
        }

        int query(int from, int to) {
            return prefix[to] - prefix[from];
        }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    SubarraySum subarrSum(arr);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int from, to;
        cin >> from >> to;
        cout << subarrSum.query(from, to) << '\n';
    }
}
