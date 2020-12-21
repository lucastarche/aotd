//Termial
//Analogous to factorial. Gives the sum of the numbers from 1 to n.
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