//SelectionSort
//For each index, you swap the current element with the one with the minimum value
//Best case complexity: O(n^2)
//Average case complexity: O(n^2)
//Worst case complexity: O(n^2)
//Becomes slow after n = 2000, and unusable after n = 10000
#include <bits/stdc++.h>

using namespace std;

void SelectionSort(vector<int>& v) {
    int n = (int)v.size();
    for (int i = 0; i < n; i++) {
        int minElement = v[i];
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (minElement > v[j]) {
                minElement = v[j];
                minIndex = j;
            }
        }
        swap(v[i], v[minIndex]);
    }
}

int main() {
    //Input
    int n;
    cin >> n;
    vector<int> elements;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        elements.push_back(temp);
    }

    SelectionSort(elements);

    //Output
    cout << "Sorted array:\n";
    for (auto i : elements)
        cout << i << " ";
    cout << '\n';
}
