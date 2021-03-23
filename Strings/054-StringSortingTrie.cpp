//String Sorting with Trie
//We can sort a list of strings using a Trie, thanks to the fact that we keep the neighbours of a node in order.
//This can be done by exploring the trie recursively, and adding each string to the answer if it ends there.
//It runs in O(N * A) time, because we explore each node once, and we run a loop which iterates for each neighbour in every node.
//This means it is very useful if we have either: a lot of short strings, a small alphabet, or a lot of string with prefixes in common.
#include "Trie.cpp"

class StringSorter : public Trie {
private:
    void sorted(int node, string prefix, vector<string>& ans) {
        if (ending[node])
            ans.push_back(prefix);
        for (int i = 0; i < (int)trie[node].size(); i++) {
            if (trie[node][i] > 0) {
                string newPrefix = prefix + (char)i;
                sorted(trie[node][i], newPrefix, ans);
            }
        }
    }

public:
    vector<string> sorted() {
        vector<string> ans;
        sorted(0, "", ans);
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> lst(n);
    for (int i = 0; i < n; i++) {
        cin >> lst[i];
    }

    StringSorter sorter;
    for (auto s : lst) {
        sorter.add(s);
    }

    vector<string> ans = sorter.sorted();
    for (auto a : ans)
        cout << a << '\n';
}
