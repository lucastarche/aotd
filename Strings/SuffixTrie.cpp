//Copy of aotd#52
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
