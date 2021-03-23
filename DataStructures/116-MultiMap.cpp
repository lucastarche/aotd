//MultiMap
//A TreeMap which allows for a key to map to more than one value.
//We can implement it as a map, which maps each element to a vector of values.
//Runtime: O(log n) insertion and deletion.
#include "RedBlackTree/KeyRedBlackTree.cpp"

template<typename T, typename S>
class MultiMap : public KeyedRBTree<T, vector<S>> {
public:
    void insert(T key, S value) {
        if (contains(key)) {
            search(key)->value.push_back(value);
        } else
            KeyedRBTree<T, vector<S>>::insert(key, { value });
    }

    int count(T key) {
        if (contains(key)) {
            return search(key)->value.size();
        }
        return 0;
    }

    vector<S> get(T key) {
        return KeyedRBTree<T, vector<S>>::search(key)->value;
    }
};

int main() {
    MultiMap<int, string> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        string tempStr;
        cin >> temp >> tempStr;
        s.insert(temp, tempStr);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int temp;
        cin >> temp;
        cout << s.count(temp);
    }
}