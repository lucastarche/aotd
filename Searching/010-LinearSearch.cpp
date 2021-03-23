//Linear Search
//Iterate through each element of the array, until you find the element wanted or run out of elements.
//Best case complexity: O(1)
//Average case complexity: O(n)
//Worst case complexity: O(n)
#include <bits/stdc++.h>

using namespace std;

bool LinearSearch(const vector<int>& v, int val) {
    for (int i = 0; i < (int)v.size(); i++) {
        if (v[i] == val)
            return true;
    }
    return false;
}

int main() {
    int n, val;
    cin >> n;
    vector<int> elements(n);
    for (int i = 0; i < n; i++)
        cin >> elements[i];
    cin >> val;
    bool found = LinearSearch(elements, val);
    if (found)
        cout << val << " is in the array.\n";
    else
        cout << val << " is not in the array.\n";
}
