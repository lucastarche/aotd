//CountingSort
//Make a frequency analysis of the elements. Only works if the values are in a small range, since it uses a number for each possible value, but compensates with a really quick runtime. It is great for sorting strings, for example.
//Best case complexity: O(n)
//Average case complexity: O(n)
//Worst case complexity: O(n)
#include <bits/stdc++.h>

using namespace std;

void CountingSort(string &v) {
    vector<int> freq(260, 0);
    for (auto c : v) freq[c]++;
    int index = 0;
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < freq[i]; j++) {
            v[index] = (char)i;
            index++;
        }
    }
}

int main() {
    string input;
    cin >> input;
    CountingSort(input);
    cout << "Sorted string: " << input << '\n';
}
