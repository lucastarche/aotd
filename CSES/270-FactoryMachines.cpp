//Factory Machines
//Problem: Given a list of machines, each of which take a time t to make a product, and we want to make k products, find the minimum amount of time needed.
//Solution: We can binary search the answer by checking whether we can get k products or not in (high + low) / 2 units of time.
//Runtime: O(n log n)
#include <bits/stdc++.h>

using namespace std;

bool valid(const vector<long long>& machines, long long k, long long t) {
    long long curr = 0;
    for (auto m : machines) {
        curr += (long long)(t / m);
    }
    return curr >= k;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> machines(n);
    for (int i = 0; i < n; i++) {
        cin >> machines[i];
    }

    sort(machines.begin(), machines.end());

    long long low = 0, high = k * machines[0];
    while (high - low > 1) {
        long long mid = (low + high) / 2;
        if (valid(machines, k, mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }

    cout << high << '\n';
}