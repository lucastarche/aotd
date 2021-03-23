//Slowsort
//One of the original joke sorts. It is pretty bad, but not as bad as something like bogosort, given that the algorithm will eventually finish, without having to rely on luck. It will just do so quite slowly.
//Uses all the power of RECURSION and DIVIDE AND CONQUER to ensure the array is sorted correctly.
//Runtime: Hard to know, given that it does not run in polynomial time. Its best case is worse than O(n^2)
#include <bits/stdc++.h>

using namespace std;

void Slowsort(vector<int>& arr, int i, int j) {
    if (i >= j)
        return;
    int m = (i + j) / 2;
    Slowsort(arr, i, m);
    Slowsort(arr, m + 1, j);
    if (arr[j] < arr[m]) {
        swap(arr[j], arr[m]);
    }
    Slowsort(arr, i, j - 1);
}

void Slowsort(vector<int>& arr) {
    int j = (int)arr.size();
    Slowsort(arr, 0, j - 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Slowsort(arr);

    cout << "Sorted array: ";
    for (auto a : arr)
        cout << a << " ";
    cout << '\n';
}
