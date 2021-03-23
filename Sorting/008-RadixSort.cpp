//RadixSort
//Make "Buckets" for each digit from left to right, and CountingSort respect to each digit.
//Best case complexity: O(k.n)
//Average case complexity: O(k.n)
//Worst case complexity: O(k.n)
#include <bits/stdc++.h>

using namespace std;

void CountingSort(vector<int>& v, int exp) {
    vector<int> freq(10, 0);
    for (auto c : v)
        freq[(c / exp) % 10]++;

    int n = (int)v.size();
    vector<int> out(n, 0);
    for (int i = 1; i < 10; i++)
        freq[i] += freq[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        out[--freq[(v[i] / exp) % 10]] = v[i];
    }
    v = out;
}

void RadixSort(vector<int>& v) {
    int maxNum = v[0];
    for (auto a : v)
        maxNum = max(maxNum, a);

    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        CountingSort(v, exp);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> elements(n);
    for (int i = 0; i < n; i++)
        cin >> elements[i];
    RadixSort(elements);
    cout << "Sorted array:\n";
    for (auto a : elements)
        cout << a << " ";
    cout << '\n';
}
