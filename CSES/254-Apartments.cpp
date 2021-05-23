//Apartments
//Problem: Given a list of apartments, a list of applicants, and a tolerance k, find the maximum number of applicants we can assign an appartment to.
//Solution: We can sort both lists, and increase a pointer depending on whether it is too small, too big, or just right.
//That is, we greedily try to assign the smallest apartment to the smallest applicant until we run out of either of them.
//Runtime: O(n log n + m log m)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> applicants(n), apartments(m);
    for (int i = 0; i < n; i++)
        cin >> applicants[i];

    for (int i = 0; i < m; i++)
        cin >> apartments[i];

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int i = 0, j = 0, ans = 0;
    while (i < n && j < m) {
        if (applicants[i] > apartments[j] + k)
            j++;
        else if (applicants[i] + k < apartments[j])
            i++;
        else {
            i++;
            j++;
            ans++;
        }
    }

    cout << ans << '\n';
}