//PE 22: Names Scores
//Problem: Given a list of names, determine the sum of their scores.
//We will define the score of a name as the result of the sum of its letters, times its position if the list were sorted.
//Solution: We first sort the list, and then do as asked.
//Runtime: O(n log n)
//Note: This solution could be made even faster with Bucket Sort, but it is not needed, since we are given 5000 names.
#include "EulerUtils.hpp"

long long solve(vector<string> names) {
    long long ans = 0LL, index = 1LL;
    sort(names.begin(), names.end());

    for (auto name : names) {
        long long curr = 0;
        for (auto c : name) {
            long long letterValue = (long long)(c - 'A' + 1);
            curr += letterValue;
        }
        ans += index * curr;
        index++;
    }

    return ans;
}

int main() {
    string buf = "", curr = "";
    vector<string> names;
    ifstream in("input-022.txt");
    in >> buf;
    for (auto c : buf) {
        switch (c) {
        case '"':
            if (curr != "") {
                names.push_back(curr);
                curr = "";
            }
        case ',':
            break;
        default:
            curr += c;
        }
    }

    cout << solve(names) << '\n';
}
