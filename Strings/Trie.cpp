#include <bits/stdc++.h>

using namespace std;

class Trie {
protected:
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
            } else {
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
            } else {
                return false;
            }
        }
        return ending[curr];
    }
};
