//Gauss Summation
//It turns out there is a constant way to get the termial. It is done by applying the formula n(n+1)/2.
//This formula comes from the fact that we can pair the first and last term to get n+1, second and second to last to get n+1, and so on.
//There are exactly n/2 of these terms.
//Runtime: O(1)
#include <bits/stdc++.h>

using namespace std;

int Gauss(int n) {
    return n * (n + 1) / 2;
}

int main() {
    int n;
    cin >> n;
    cout << Gauss(n) << '\n';
}