//PE 98: Anagramic Squares
//Problem: Given a list of words, find the maximum square that can be formed by replacing the letters in a word
//for numbers, and using the same replacements in another word to get a square which is a permutation of the first square
//Solution: We can iterate through every word, and try for each square to replace in the first word.
//If every condition holds, we see if the replacements for a square or not.
//Runtime: O(n^2 * k log k), where n is the number of words, and k the number of squares.
#include "EulerUtils.hpp"

map<string, string> sorted;
vector<long long> squares;

long long matchSquares(const string& lhs, const string& rhs) {
    long long ans = 0;

    for (auto i : squares) {
        string a = to_string(i);
        if (a.size() != lhs.size())
            continue;

        map<char, char> replacements;
        bool valid = true;
        for (int k = 0; k < (int)a.size(); k++) {
            if (replacements.count(a[k]) != 0 && replacements[a[k]] != lhs[k])
                valid = false;
            replacements[a[k]] = lhs[k];
        }

        set<char> used;
        for (auto a : replacements) {
            if (used.count(a.second) != 0)
                valid = false;
            used.insert(a.second);
        }

        if (!valid)
            continue;

        string lhsRebuilt;
        for (auto x : a) {
            lhsRebuilt += replacements[x];
        }

        if (lhsRebuilt != lhs)
            continue;

        string num;
        for (auto x : rhs) {
            bool found = false;
            for (int i = 0; i < 10; i++) {
                if (replacements[i + '0'] == x) {
                    found = true;
                    num += (char)(i + '0');
                    break;
                }
            }

            if (!found)
                valid = false;
        }

        if (!valid || num[0] == '0')
            continue;

        long long j = stoll(num);
        if (!binary_search(squares.begin(), squares.end(), j)) {
            continue;
        }

        ans = max(ans, i);
        ans = max(ans, j);
    }

    return ans;
}

long long solve(const vector<string>& words) {
    long long ans = 0;

    for (auto a : words) {
        for (auto b : words) {
            if (a == b)
                continue;
            if (sorted[a] != sorted[b])
                continue;
            ans = max(ans, matchSquares(a, b));
        }
    }

    return ans;
}

int main() {
    for (long long i = 0; i * i <= 1e10; i++) {
        squares.push_back(i * i);
    }

    ifstream in("input-098.txt");
    vector<string> words;
    string curr = "";
    bool inQuote = false;

    for (char c; in.get(c);) {
        if (inQuote) {
            if (c == '"') {
                words.push_back(curr);
                string copy = curr;
                sort(copy.begin(), copy.end());
                sorted[curr] = copy;
                curr = "";
                inQuote = false;
            } else {
                curr += c;
            }
        } else if (c == '"') {
            inQuote = true;
        }
    }

    cout << solve(words) << '\n';
}