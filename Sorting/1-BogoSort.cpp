//BogoSort: the joke sort or stupid sort
//Consists of shuffling the array until it's sorted
//Best case Complexity: O(n)
//Average case Complexity: O(n * n!)
//Worst case Complexity: O(infinite) 
//Becomes slow after n = 15, and unusable after n = 20
#include <bits/stdc++.h>

using namespace std;

void BogoSort(vector<int> &v) {
    while (!is_sorted(v.begin(), v.end())) {
        random_shuffle(v.begin(), v.end());
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

    BogoSort(elements);

    //Output
    cout << "Sorted array:\n";
    for (auto i : elements) cout << i << " ";
    cout << '\n';
}
