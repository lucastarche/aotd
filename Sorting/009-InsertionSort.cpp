//InsertionSort
//Find the appropiate place in a sorted array for the next element, and insert it into that position.
//Best case complexity: O(n)
//Average case complexity: O(n^2)
//Worst case complexity: O(n^2)
//Becomes slow after n = 2000, and unusable after n = 10000.
//Since each insertion works in O(n), it is better to use this algorithm when we have an already sorted array, and just want to add more values.
#include <bits/stdc++.h>

using namespace std;

void InsertionSort(vector<int>& v, int sortedEnd) {
    int i = sortedEnd;
    while (i < (int)v.size()) {
        int j = i;
        while (j > 0 && v[j - 1] > v[j]) {
            swap(v[j], v[j - 1]);
            j--;
        }
        i++;
    }
}

void InsertionSort(vector<int>& v) {
    InsertionSort(v, 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> elements(n);
    for (int i = 0; i < n; i++)
        cin >> elements[i];
    InsertionSort(elements);
    cout << "Sorted array:\n";
    for (auto a : elements)
        cout << a << ' ';
    cout << '\n';
}
