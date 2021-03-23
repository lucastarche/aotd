//Stalin Sort
//We iterate through the entire list once. If we see any element that isn't in the right order, we send it to Gülag and continue the pass.
//Unluckly, to accomplish this insanely good runtime, some elements had to give their lives, so think about them before using this algorithm.
//Runtime: O(n)
//Note: Provided are two different implementations: One with a temp buffer, and one which does it inplace.
#include <bits/stdc++.h>

using namespace std;

vector<int> StalinSort(vector<int> arr) {
    vector<int> ans = { arr[0] };
    for (int i = 1; i < (int)arr.size(); i++)
        if (ans[ans.size() - 1] <= arr[i])
            ans.push_back(arr[i]);
    return ans;
}

void StalinSortInplace(vector<int>& arr) {
    int lptr = 0, rptr = 1;
    while (rptr < (int)arr.size()) {
        if (arr[lptr] <= arr[rptr]) {
            lptr++;
            arr[lptr] = arr[rptr];
        }
        rptr++;
    }
    arr.resize(lptr + 1);
    arr.shrink_to_fit();
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    auto ans = StalinSort(arr);

    cout << "Sorted array: ";
    for (auto a : ans)
        cout << a << " ";
    cout << '\n';

    StalinSortInplace(arr);

    for (auto a : arr)
        cout << a << " ";
    cout << '\n';
}
