//QuickSort
//Select a random element of the array (the pivot), and place all the lower elements to its left, and the greaters to its right. Sort both sides and then join into one array.
//Best case complexity: O(n log n)
//Average case complexity: O(n log n)
//Worst case complexity: O(n^2)
//Becomes slow after n = 200000, and unusable after n = 1000000
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &v, int a, int b) {
    int pivot = v[b];
    int i = a - 1;
    for (int j = a; j < b; j++) {
        if (v[j] < pivot) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[b]);
    return i + 1;
}

void QuickSort(vector<int> &v, int a, int b) {
    if (b <= a) return;
    random_shuffle(v.begin() + a, v.begin() + b);
    int index = partition(v, a, b);
    QuickSort(v, a, index - 1);
    QuickSort(v, index + 1, b);
}

int main() {
    int n;
    cin >> n;
    vector<int> elements(n);
    for (int i = 0; i < n; i++) cin >> elements[i];
    QuickSort(elements, 0, n - 1);
    cout << "Sorted Array:\n";
    for (auto a : elements) cout << a << " ";
    cout << '\n';
}
