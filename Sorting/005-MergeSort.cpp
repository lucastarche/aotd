//MergeSort
//Split the array in half until it's trivial to sort it, and then merge the smaller arrays into a sorted one.
//Best case complexity: O(n log n)
//Average case complexity: O(n log n)
//Worst case complexity: O(n log n)
//Becomes slow after n = 200000, and unusable after n = 1000000
#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &v, int a, int mid, int b) {
    vector<int> bufA, bufB;
    int aSize = 0, bSize = 0;
    for (int i = a; i <= mid; i++) {
        bufA.push_back(v[i]);
        aSize++;
    }
    for (int i = mid + 1; i <= b; i++) {
        bufB.push_back(v
[i]);
        bSize++;
    }
    int aInd = 0, bInd = 0, i = a;
    while (aInd < aSize && bInd < bSize) {
        if (bufA[aInd] <= bufB[bInd]) {
            v[i] = bufA[aInd];
            aInd++;
        }
        else {
            v[i] = bufB[bInd];
            bInd++;
        }
        i++;
    }

    while (aInd < aSize) {
        v[i] = bufA[aInd];
        aInd++;
        i++;
    }
    while (bInd < bSize) {
        v[i] = bufB[bInd];
        bInd++;
        i++;
    }
}

void MergeSort(vector<int> &v, int a, int b) {
    if (b <= a) return;
    int mid = (int)((a + b) / 2);
    MergeSort(v, a, mid);
    MergeSort(v, mid + 1, b);
    merge(v, a, mid, b);
}

int main() {
    int n;
    cin >> n;
    vector<int> elements(n);
    for (int i = 0; i < n; i++) cin >> elements[i];
    MergeSort(elements, 0, n - 1);
    cout << "Sorted Array:\n";
    for (auto a : elements) cout << a << " ";
    cout << '\n';
}
