//Sieve of Eratosthenes
//This is an algorithm which preprocesses whether a number x is a prime or not in a range from 0 to n.
//The idea is that, once we find a prime number, all the numbers of the form kp aren't prime, and we can just skip them.
//Runtime: O(n log log n), which is almost O(n). After that, each query runs in O(1).
#include <bits/stdc++.h>

using namespace std;

vector<bool> Sieve(int n) {
    vector<bool> ans(n + 1, true);
    ans[0] = false;
    ans[1] = false;
    for (int x = 2; x <= n; x++) {
        if (!ans[x]) continue;
        for (int i = 2*x; i <= n; i++) {
            ans[i] = false;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    auto ans = Sieve(n);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int num;
        cin >> num;
        if (num > n) cout << "Num out of range" << '\n';
        else if (ans[num]) cout << num << " is a prime" << '\n';
        else cout << num << " is not a prime" << '\n';
    }
}
