//Square Root
//We can use a modified binary search (a technique known as binary searching the answer), to find out the square root of a number.
//Runtime: O(log(n/eps)), where eps is the maximum allowed error.
#include <bits/stdc++.h>

using namespace std;

const double long EPS = 1e-9;

double long SquareRoot(double long n) {
    double long left = 0, right = n, mid = n / 2.0;
    while (abs(mid * mid - n) > EPS) {
        if (mid * mid > n) {
            right = mid;
        } else {
            left = mid;
        }
        mid = (left + right) / 2.0;
    }
    return mid;
}

int main() {
    double long n;
    cin >> n;
    cout << setprecision(10) << SquareRoot(n) << '\n';
}