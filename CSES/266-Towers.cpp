//Towers
//Problem: Given a set of cubes in a certain order, find the minimum number of towers we can set them up, in such a way every tower has cubes in decreasing size.
//Solution: We can have a set of towers, and then use lower_bound() to find the smallest tower bigger than the current cube,
//and replace said cube with our current one, or create a new tower otherwise.
//The answer is the size of the set, that is, the number of towers.
//Runtime: O(n log n)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cubes(n);
    for (int i = 0; i < n; i++)
        cin >> cubes[i];

    set<int> towers;
    for (int i = 0; i < n; i++) {
        auto iter = towers.lower_bound(cubes[i]);
        if (iter == towers.end()) {
            towers.insert(iter, cubes[i]);
        } else {
            towers.erase(iter);
            towers.insert(cubes[i]);
        }
    }

    cout << (int)towers.size() << '\n';
}