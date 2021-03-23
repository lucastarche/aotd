//Cycle Sort
//Another quadratic time sorting algorithm, but with the added benefit that it reduces the number of times we write to the array.
//The algorithm uses a total of O(1) auxiliary memory, and writes to the array up to n times.
//Runtime: O(n^2)
#include <bits/stdc++.h>

using namespace std;

void CycleSort(vector<int>& arr) {
    int n = (int)arr.size();
    for (int cycleStart = 0; cycleStart < n - 1; cycleStart++) {
        int item = arr[cycleStart];

        int pos = cycleStart;
        for (int i = cycleStart + 1; i < n; i++) {
            if (arr[i] < item)
                pos++;
        }

        if (pos == cycleStart)
            continue;

        while (item == arr[pos])
            pos++;
        swap(arr[pos], item);

        while (pos != cycleStart) {
            pos = cycleStart;
            for (int i = cycleStart + 1; i < n; i++) {
                if (arr[i] < item)
                    pos++;
            }
            swap(arr[pos], item);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    CycleSort(arr);

    for (auto a : arr)
        cout << a << ' ';
    cout << '\n';
}