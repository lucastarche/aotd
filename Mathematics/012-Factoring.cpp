//Factoring
//Searches all the factors of a given number, by trying with all possible numbers between 2 and sqrt(n)
//Best case complexity: O(sqrt(n))
//Average case complexity: O(sqrt(n))
//Worst case complexity: O(sqrt(n))
#include <bits/stdc++.h>

using namespace std;

vector<long long> Factor(long long n) {
    vector<long long> ans;
    while (n % 2 == 0) {
        ans.push_back(2);
        n /= 2;
    }
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            ans.push_back(i);
            n /= i;
        }
    }
    if (n > 2)
        ans.push_back(n);
    return ans;
}

int main() {
    long long n;
    cin >> n;
    vector<long long> ans = Factor(n);

    cout << "Factors: ";
    for (auto a : ans)
        cout << a << " ";
    cout << '\n';
}
