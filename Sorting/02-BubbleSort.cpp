//BubbleSort: easy to implement, but a bit slow
//Consists of n iterations from start to finish, and swapping two elements if the first is less than the second
//Best case Complexity: O(n^2)
//Average case Complexity: O(n^2)
//Worst case Complexity: O(n^2)
//Becomes slow after n = 2000, and unusable after n = 10000
#include <bits/stdc++.h>

using namespace std;

void BubbleSort(vector<int> &v) {
    int n = (int)v.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] > v[j]) {
                swap(v[i], v[j]);
            }
        }
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

    BubbleSort(elements);

    //Output
    cout << "Sorted array:\n";
    for (auto i : elements) cout << i << " ";
    cout << '\n';
}
