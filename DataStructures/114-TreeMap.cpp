//TreeMap
//This is a data structure similar to a TreeSet, but in which we sort keys, and map those to their respective values.
//We can modify the RBTree to get a KeyedRBTree, in which each node maps a key to a value.
//Runtime: O(log n) insertion and deletion.
#include "RedBlackTree/KeyRedBlackTree.cpp"

template<typename T, typename S>
class TreeMap : public KeyedRBTree<T, S> {
public:
    S get(T key) {
        return KeyedRBTree<T, S>::search(key)->value;
    }
};

int main() {
    int n;
    cin >> n;
    TreeMap<int, string> m;
    for (int i = 0; i < n; i++) {
        int key;
        string value;
        cin >> key >> value;
        m.insert(key, value);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int query;
        cin >> query;
        cout << m.get(query) << '\n';
    }
}