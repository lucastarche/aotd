//Void Sort
//Sorting shouldn't be soooo slow. That is why I'm happy to introduce Void Sort: the first sorting algorithm with O(1) runtime AND O(1) extra space.
//However, please note that it may have some problems regarding data loss, but it sure makes up with its INCREDIBLE runtime, which may or may not be related to the fact that we sent all the elements to the void.
//Runtime: O(1)
#include <bits/stdc++.h>

using namespace std;

vector<int> VoidSort(vector<int> args) {
    return {};
}

void VoidSortInplace(vector<int> &args) {
    args.resize(0);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    auto ans = VoidSort(arr);

    cout << "Sorted array: ";
    for (auto a : ans) cout << a << " ";
    cout << '\n';

    VoidSortInplace(arr);

    for (auto a : arr) cout << a << " ";
    cout << '\n';
}
