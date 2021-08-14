//Salary Queries
//Problem: Given a list of n workers, each with an initial salary, answer q queries of the form
//"Change the salary of worker i to x" or "Return the number of workers with a salary between a and b"
//Solution: We can use coordinate compression to map the salaries that are used from the range [0, 1e9] to an index, which will be in the range [0, 6e5], since we have at most n = 2e5, q = 2e5
//After this, it is just a matter of counting the number of elements in the range [a, b], which can be done quickly with a Fenwick Tree,
//on which the update queries remove one from an index, and add one to another index
//Runtime: O(n log n + q log n)
//Note that without coordinate compression, it would be O(x log x + q log x), with x the maximum value for the salary!
#include <bits/stdc++.h>

using namespace std;

struct Query {
    int type;
    int a, b;
};

inline int lsOne(int n) {
    return n & (-n);
}

void adjust(vector<long long>& fenwick, int idx, long long delta) {
    int n = (int)fenwick.size();
    while (idx < n) {
        fenwick[idx] += delta;
        idx += lsOne(idx);
    }
}

long long sum(vector<long long>& fenwick, int idx) {
    long long ans = 0;
    while (idx >= 1) {
        ans += fenwick[idx];
        idx -= lsOne(idx);
    }
    return ans;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> nums(n + 1), coord_compress = { 0 };
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        coord_compress.push_back(nums[i]);
    }

    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        char type;
        cin >> type >> queries[i].a >> queries[i].b;
        queries[i].type = (type == '?') ? 1 : 2;
        coord_compress.push_back(queries[i].a);
        coord_compress.push_back(queries[i].b);
    }

    sort(coord_compress.begin(), coord_compress.end());
    auto ans = unique(coord_compress.begin(), coord_compress.end());
    coord_compress.erase(ans, coord_compress.end());

    vector<long long> fenwick((int)coord_compress.size());
    for (int i = 1; i <= n; i++) {
        nums[i] = lower_bound(coord_compress.begin(), coord_compress.end(), nums[i]) - coord_compress.begin();
        adjust(fenwick, nums[i], 1);
    }

    for (int i = 0; i < q; i++) {
        queries[i].b = lower_bound(coord_compress.begin(), coord_compress.end(), queries[i].b) - coord_compress.begin();

        if (queries[i].type == 1) {
            queries[i].a = lower_bound(coord_compress.begin(), coord_compress.end(), queries[i].a) - coord_compress.begin();
            cout << sum(fenwick, queries[i].b) - sum(fenwick, queries[i].a - 1) << '\n';
        } else {
            adjust(fenwick, nums[queries[i].a], -1);
            adjust(fenwick, queries[i].b, 1);
            nums[queries[i].a] = queries[i].b;
        }
    }
}