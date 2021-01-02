//TreeSet
//It is a direct implementation of the Red-Black Tree, so we don't need to add any extra code to it.
//We can, however, use this class as a sort of "wrapper", to which we can add extra functionality.
//Runtime: O(log n) insertion and deletion. 
#include "RedBlackTree/RedBlackTree.cpp"

template <typename T>
class TreeSet : public RBTree<T> { };

int main() {
    TreeSet<int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        s.insert(temp);
    }

    for (auto a : s.inOrder()) {
        cout << a << ' ';
    }
    cout << '\n';

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        s.remove(temp);
    }

    for (auto a : s.inOrder()) {
        cout << a << ' ';
    }
    cout << '\n';
}