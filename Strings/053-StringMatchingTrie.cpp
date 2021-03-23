//String Mathching with Suffix Trie
//The idea behind this is that we can consider any string pattern as the prefix of a suffix of a word. This is because:
//If we want to get substring (n, m) we can first get the substring (n, len), which is a suffix, and the we can get the substring (0, m) of our first substring.
//If we use a Suffix Trie, we can check if we can reach the substring in the Trie, and if we can, the pattern appears at least once in the text.
//Runtime: O(m) after O(n^2) preprocessing.
#include "SuffixTrie.cpp"

class StringMatching : public SuffixTrie {
public:
    bool checkPattern(string pattern) {
        int curr = 0;
        for (auto c : pattern) {
            if (trie[curr][c] > 0)
                curr = trie[curr][c];
            else
                return false;
        }
        return true;
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> lst(n);
    for (int i = 0; i < n; i++) {
        cin >> lst[i];
    }

    StringMatching trie;
    for (auto s : lst) {
        trie.add(s);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string query;
        cin >> query;
        if (trie.checkPattern(query)) {
            cout << query << " appears in the text." << '\n';
        } else {
            cout << query << " does not appear in the text." << '\n';
        }
    }
}
