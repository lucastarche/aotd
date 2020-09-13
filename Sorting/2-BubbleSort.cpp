//BubbleSort: easy to implement, but a bit slow
//Average Complexity: O(n^2)
//Becomes slow after n = 2000, and unusable after n = 10000
#include <bits/stdc++.h>

using namespace std;

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

    //Sorting
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (elements[i] > elements[j]) {
                swap(elements[i], elements[j]);
            }
        }
    }

    //Output
    cout << "Sorted array:\n";
    for (auto i : elements) cout << i << " ";
    cout << '\n';
}
