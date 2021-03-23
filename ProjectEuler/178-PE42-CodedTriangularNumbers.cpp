//PE 42: Coded Triangle Numbers
//Problem: We define the triangular numbers as the sequence of the form: t_n = 1/2 * n * (n + 1).
//By converting each letter in a word to a number corresponding to its alphabet position (A = 1, B = 2, etc), count the number of words which encode to a triangular number in the input file.
//Solution: First we can build a set with a reasonable amount of triangular numbers, and then we check for each word if its corresponding number is triangular or not.
//Runtime: O(n log n + m log n), where n is the amount of triangular numbers, and m is the amount of words.
#include "EulerUtils.hpp"

long long solve(vector<string> words) {
    long long ans = 0LL;
    set<long long> triangleNumbers;
    for (long long i = 1LL; i <= 100LL; i++) {
        triangleNumbers.insert((i * (i + 1LL)) / 2LL);
    }

    for (auto word : words) {
        long long val = 0LL;
        for (auto c : word)
            val += (long long)(c - 'A' + 1);
        if (triangleNumbers.count(val))
            ans++;
    }

    return ans;
}

int main() {
    vector<string> words;
    ifstream in("input-042.txt");
    string buf;
    char curr;
    while (in >> curr) {
        switch (curr) {
        case '"':
            if (buf != "") {
                words.push_back(buf);
                buf = "";
            }
        case ' ':
        case ',':
            break;
        default:
            buf += curr;
        }
    }

    cout << solve(words) << '\n';
}
