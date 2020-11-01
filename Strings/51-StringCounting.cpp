//String Counting
//This is a better method for counting the number of occurences of a complete string in a text. This is way better than checking every string, because now we can answer queries in O(m), where m is the length of the string, after an initial O(N) preprocessing, where N is the total sum of the string lengths.
//The main idea is to modify a Trie in such a way that every time we add a string to the trie, we keep a counter with the number of times it appears.
//Runtime: O(m) per query after O(N) initial preprocessing.
#include "Trie.cpp"

class StringCounting : public Trie {
    private:
        vector<int> counter;
    public:
        StringCounting() {
            Trie();
            counter.resize(1, 0);
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
                    counter.push_back(0);
                    curr = size;
                    size++;
                }
            }
            counter[curr]++;
            ending[curr] = true;
        }

        int count(string in) {
            int curr = 0;
            for (auto c : in) {
                if (trie[curr][c] > 0) {
                    curr = trie[curr][c];
                }
                else {
                    return 0;
                }
            }
            return counter[curr];
        }
};

int main() {
    int n;
    cin >> n;
    vector<string> lst(n);
    for (int i = 0; i < n; i++) {
        cin >> lst[i];
    }

    StringCounting trie;
    for (auto s : lst) {
        trie.add(s);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string query;
        cin >> query;
        cout << query << " found " << trie.count(query) << " times.\n";
    }
}
