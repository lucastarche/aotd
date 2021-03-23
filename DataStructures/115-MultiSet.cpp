//MultiSet
//A TreeSet which allows for more than one appearance of an element.
//We can implement it as a map, which maps each element to the amount of appearances.
//Runtime: O(log n) insertion and deletion.
#include "RedBlackTree/KeyRedBlackTree.cpp"

template<typename T>
class MultiSet : public KeyedRBTree<T, int> {
public:
    void insert(T key) {
        if (contains(key)) {
            search(key)->value++;
        } else
            KeyedRBTree<T, int>::insert(key, 1);
    }

    void remove(T key) {
        if (contains(key)) {
            Node<T, int>* node = search(key);
            if (node->value == 1) {
                KeyedRBTree<T, int>::remove(key);
            } else {
                node->value--;
            }
        }
    }

    int count(T key) {
        if (contains(key)) {
            return search(key)->value;
        }
        return 0;
    }
};

int main() {
    MultiSet<int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        s.insert(temp);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int temp;
        cin >> temp;
        cout << s.count(temp);
    }
}