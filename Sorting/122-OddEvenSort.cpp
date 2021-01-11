//Odd-Even Sort
//Another sorting algorithm similar to bubble sort, but with the potential of being parallelizable
//One processor can sort the odd pairs, while the other sorts the even pairs.
//Runtime: O(n^2)
#include <bits/stdc++.h>

using namespace std;

void OddEvenSort(vector<int> &arr) {
    int n = (int)arr.size();
    bool swapped = true;
    while (swapped) {
        swapped = false;

        for (int i = 1; i < n; i += 2) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        for (int i = 0; i < n; i += 2) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i];

    OddEvenSort(arr);

    for (auto a : arr) cout << a << ' ';
    cout << '\n';
}