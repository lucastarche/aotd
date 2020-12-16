//Trie
//It is an special data structure which allows for efficient retrieval of strings. (hence it name, reTRIEval).
//However, it is quite space intensive, so it is recommended for when we have a large amount of short strings.
//We can add strings to the trie, and check if a string is in the trie in O(m), where m is the length of the string.
//The trie uses O(N*A) space, where N is the sum of all the string lengths, and A is the size of the alphabet (in ASCII, for example, it would be 256).
//This and similar data structures derived from it are used when computing stuff about the human genome, thanks to the fact that the alphabet is only four characters long (A, C, G, T).
#include <bits/stdc++.h>

using namespace std;

class Trie {
    private:
        vector<vector<int>> trie;
        vector<bool> ending;
        int size;
    public:
        Trie() {
            trie.resize(1, vector<int>(256, 0));
            ending.push_back(false);
            size = 1;
        }

        void add(string in) {
            int curr = 0;
            for (auto c : in) {
                if (trie[curr][c] > 0) {
                    curr = trie[curr][c];
                }
                else {
                    trie[curr][c] = size;
                    ending.push_back(false);
                    trie.push_back(vector<int>(256, 0));
                    curr = size;
                    size++;
                }
            }
            ending[curr] = true;
        }

        bool contains(string in) {
            int curr = 0;
            for (auto c : in) {
                if (trie[curr][c] > 0) {
                    curr = trie[curr][c];
                }
                else {
                    return false;
                }
            }
            return ending[curr];
        }
};

int main() {
    int n;
    cin >> n;
    vector<string> lst(n);
    for (int i = 0; i < n; i++) {
        cin >> lst[i];
    }

    Trie trie;
    for (auto s : lst) {
        trie.add(s);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string query;
        cin >> query;
        if (trie.contains(query)) {
            cout << query << " found in the trie." << '\n';
        }
        else {
            cout << query << " not found in the trie." << '\n';
        }
    }
}
