//BogoSort: the joke sort or stupid sort
//Average Complexity: O(n * n!)
//Becomes slow after n = 15, and unusable after n = 20
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
    while (!is_sorted(elements.begin(), elements.end())) {
        random_shuffle(elements.begin(), elements.end());
    }

    //Output
    cout << "Sorted array:\n";
    for (auto i : elements) cout << i << " ";
    cout << '\n';
}
