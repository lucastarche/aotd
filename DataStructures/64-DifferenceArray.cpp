//Difference Array
//The main idea is to keep an array diff, in which diff[i] = arr[i] - arr[i - 1]. This allows for efficient addition and substraction of values in a range by the same element.
//This is very useful, because it allows us to update elements in a range in constant time, instead of doing (r - l) operations.
//Runtime: Building in O(n), and each query runs in O(1)
#include <bits/stdc++.h>

using namespace std;

class DiffArray {
    private:
        vector<int> arr;
    public:
        DiffArray(vector<int> in) {
            int n = (int)in.size();
            arr.resize(n + 1);
            arr[0] = in[0];
            arr[n] = 0;
            for (int i = 1; i < n; i++) {
                arr[i] = in[i] - in[i - 1];
            }
        }

        //Adds x to every element from l to r
        void update(int x, int l, int r) {
            arr[l] += x;
            arr[r + 1] -= x;
        }

        vector<int> getArray() {
            int n = (int)arr.size();
            vector<int> ans(n - 1);
            ans[0] = arr[0];
            for (int i = 1; i < n; i++) {
                ans[i] = arr[i] + ans[i - 1];
            }
            return ans;
        }
};

int main() {
    int n;
    cin >> n;
    vector<int> temp(n);
    for (int i = 0; i < n; i++)
        cin >> temp[i];

    DiffArray diff(temp);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, l, r;
        cin >> x >> l >> r;
        diff.update(x, l, r);
    }

    temp = diff.getArray();
    cout << "Resulting array: ";
    for (int i = 0; i < n; i++) {
        cout << temp[i] << " ";
    }
    cout << '\n';
}
