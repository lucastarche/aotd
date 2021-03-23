//Suffix Trie
//This is a slightly modified version of a Trie. The regular trie is also known as a "Prefix Trie", given that there is a common prefix in two strings that go through a certain node.
//The idea is that we insert a string and all its suffixes, which will be useful for some other algorithms.
//This Data Structure is useful for things like checking if a certain pattern occurs in a text in O(m) after building the Suffix Trie.
//Runtime: insert in O(m^2), and querying in O(m).
#include "Trie.cpp"

class SuffixTrie : public Trie {
public:
    SuffixTrie() {
        Trie();
    }

    void add(string in) {
        for (int i = 0; i < in.length(); i++) {
            Trie::add(in.substr(i));
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> lst(n);
    for (int i = 0; i < n; i++) {
        cin >> lst[i];
    }

    SuffixTrie trie;
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
        } else {
            cout << query << " not found in the trie." << '\n';
        }
    }
}
