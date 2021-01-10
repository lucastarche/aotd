//Cocktail Shaker Sort
//A constant time improvement over bubble sort, but that still pales with large arrays.
//Despite being (on average) twice as fast as bubble sort, it still runs in quadratic time.
//Runtime: O(n^2)
#include <bits/stdc++.h>

using namespace std;

void CocktailShakerSort(vector<int> &arr) {
    int n = (int)arr.size();
    bool swapped = true;
    while (swapped) {
        swapped = false;
        
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
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

    CocktailShakerSort(arr);

    for (auto a : arr) cout << a << ' ';
    cout << '\n';
}