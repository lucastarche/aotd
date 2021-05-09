//Increasing array
//Problem: Given an array of n numbers, find the number of times you gotta increase a number to get a non decreasing array.
//Solution: We can keep track of the previous number. If the new number if bigger than the current one, we change the current.
//Else, we add their difference to the result.
//Runtime: O(n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long result = 0, curr = 0;
    cin >> curr;
    for (int i = 0; i < n - 1; i++) {
        long long temp = 0;
        cin >> temp;
        if (temp > curr)
            curr = temp;
        else
            result += curr - temp;
    }

    cout << result << '\n';
}