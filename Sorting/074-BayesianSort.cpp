//Bayesian Sort
//Given the theory of intelligent design and intrinsic universes, and the chance of an array is increasingly smaller, this means that the array is already in an intrinsic order, and then doesn't need to be sorted.
//Thanks to this reasoning, the algorithm manages to get a whopping O(1) runtime, which is only challenged by Void Sort.
//Runtime: O(1)
#include <bits/stdc++.h>

using namespace std;

void BayesianSort(vector<int>& arr) { }

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    BayesianSort(arr);

    cout << "Sorted array:\n";
    for (auto i : arr)
        cout << i << " ";
    cout << '\n';
}
