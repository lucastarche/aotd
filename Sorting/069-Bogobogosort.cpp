//Bogobogosort
//The best sorting algorithm ever made. DESTROYS bogosort.
//Just kidding, it sucks. If you manage to sort more than ten elements, consider yourself lucky :D
//Runtime: hard to write. Estimated to O((n!)^n). More accurate would be O(1! x 2! x 3! x ... x (n - 1)! x n!)
#include <bits/stdc++.h>

using namespace std;

void Bogobogosort(vector<int> &v) {
    random_shuffle(v.begin(), v.end());
    if (v.size() == 1) return;
    int b = 2;
    while (!is_sorted(v.begin(), v.end())) {
        if (is_sorted(v.begin(), v.begin() + b)) {
            b++;
        }
        else {
            b = 2;
        }
        random_shuffle(v.begin(), v.begin() + b);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Bogobogosort(arr);

    cout << "Sorted array: ";
    for (auto a : arr) cout << a << " ";
    cout << '\n';
}
