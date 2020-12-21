//Termial
//Analogous to factorial. Gives the sum of the integers from 1 to n. It is represented as n?
//Runtime: O(n)
#include <bits/stdc++.h>

using namespace std;

int Termial(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += i;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << Termial(n) << '\n';
}