//Bozosort
//A variant to bogosort. Instead of shuffling the entire array, it randomly swaps any two elements until it is sorted.
//This means that it can sometimes run faster in arrays that are already partially sorted, but it will not make too much significant improvements.
//Runtime: Average case of O(n!)
#include <bits/stdc++.h>

using namespace std;

void Bozosort(vector<int>& arr) {
    srand(time(NULL)); //Seed the RNG
    int n = (int)arr.size();
    while (!is_sorted(arr.begin(), arr.end())) {
        int i = rand() % n;
        int j = rand() % n;
        swap(arr[i], arr[j]);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    Bozosort(arr);

    cout << "Sorted array:\n";
    for (auto i : arr)
        cout << i << " ";
    cout << '\n';
}
