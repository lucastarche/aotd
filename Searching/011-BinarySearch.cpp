//Binary Search
//Reduces the search space in half with every comparison, by taking advantage of the fact that the array is sorted. Needs O(n log n) preprocessing, but then always runs in O(log n).
//Best case complexity: O(1)
//Average case complexity: O(log n)
//Worst case complexity: O(log n)
#include <bits/stdc++.h>

using namespace std;

bool BinarySearch(const vector<int>& v, int val) {
    int n = (int)v.size();
    int a = 0, b = n - 1;
    while (a <= b) {
        int k = (a + b) / 2;
        if (v[k] == val) {
            return true;
        }
        if (v[k] < val)
            a = k + 1;
        else
            b = k - 1;
    }
    return false;
}

int BinarySearchWithIndex(const vector<pair<int, int>>& v, int val) {
    int n = (int)v.size();
    int a = 0, b = n - 1;
    while (a <= b) {
        int k = (a + b) / 2;
        if (v[k].first == val && (k == 0 || v[k - 1].first < val)) {
            return v[k].second;
        }
        if (v[k].first < val)
            a = k + 1;
        else
            b = k - 1;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> elements(n);
    for (int i = 0; i < n; i++)
        cin >> elements[i];
    vector<pair<int, int>> elementsWithIndex(n);
    for (int i = 0; i < n; i++)
        elementsWithIndex[i] = { elements[i], i };
    int k;
    cin >> k;
    sort(elements.begin(), elements.end());
    sort(elementsWithIndex.begin(), elementsWithIndex.end());
    if (BinarySearch(elements, k))
        cout << k << " found\n";
    else
        cout << k << " not found\n";
    int ans = BinarySearchWithIndex(elementsWithIndex, k);
    if (ans != -1)
        cout << k << " found at " << ans << '\n';
    else
        cout << k << " not found\n";
}
