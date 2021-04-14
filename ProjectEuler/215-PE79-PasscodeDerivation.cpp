//PE 79: Passcode Derivation
//Problem: Given three ordered digits of a password, find the minimal password such that every condition holds.
//Solution: We will assume that the password has at most one of every digit, and then sort them according to each and every condition.
//This is kind of a wild guess, so there is a way better solution using toposort.
//Runtime: O(n)
#include "EulerUtils.hpp"

long long solve(vector<array<int, 3>> attempts) {
    int n = (int)attempts.size();
    vector<int> index(10, -1);
    vector<int> passcode;

    for (auto a : attempts) {
        for (int i = 0; i < 3; i++) {
            if (index[a[i]] == -1) {
                index[a[i]] = passcode.size();
                passcode.push_back(a[i]);
            }
        }
    }

    for (auto a : attempts) {
        int left = index[a[0]];
        int middle = index[a[1]];
        int right = index[a[2]];

        if (left > middle) {
            swap(passcode[left], passcode[middle]);
            swap(index[a[0]], index[a[1]]);
            swap(left, middle);
        }
        if (middle > right) {
            swap(passcode[middle], passcode[right]);
            swap(index[a[1]], index[a[2]]);
            swap(middle, right);
        }
        if (left > right) {
            swap(passcode[left], passcode[right]);
            swap(index[a[0]], index[a[2]]);
            swap(left, right);
        }
    }

    long long ans = 0;
    for (auto a : passcode) {
        ans = ans * 10LL + a;
    }
    return ans;
}

int main() {
    ifstream in("input-079.txt");
    vector<array<int, 3>> attempts;
    for (int i; in >> i;) {
        attempts.push_back({ i / 100, (i / 10) % 10, i % 10 });
    }

    cout << solve(attempts) << '\n';
}