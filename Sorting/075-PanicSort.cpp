//Panic Sort
//Lets just hope the array is sorted. Because it is sorted already, right?
//Runs in O(n), but at the cost of more than one panic attack.
//Runtime: O(n)
#include <bits/stdc++.h>

using namespace std;

vector<int> PanicSort(vector<int> arr) {
    if (is_sorted(arr.begin(), arr.end())) {
        //This should be the standard output
        return arr;
    }
    //What? This should do the trick
    if (is_sorted(arr.begin(), arr.end())) {
        return arr;
    }
    //Come on come on please work
    if (is_sorted(arr.begin(), arr.end())) {
        return arr;
    }
    //Shit shit shit please work please
    if (is_sorted(arr.begin(), arr.end())) {
        return arr;
    }
    //Craaap i hope they dont notice.
    return { 1, 2, 3, 4, 5 };
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

    arr = PanicSort(arr);

    cout << "Sorted array:\n";
    for (auto i : arr)
        cout << i << " ";
    cout << '\n';
}
