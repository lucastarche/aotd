//Binary Tree
//A simple tree structure, in which each node has two children, one in the left and one in the right, and a parent (except for the root).
//It is implemented using a dynamic array, to take advantage of the fact that we can get all connected nodes in O(1), without needing to use extra space.
//add() works in O(1)
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class BinaryTree {
    private:
        vector<T> tree;
        int size;

    public:
        BinaryTree() {
            tree.resize(1);
            size = 0;
        }

        T operator[](int i) {
            return tree[i];
        }

        int getLeft(int i) {
            if (i * 2 <= size) return i * 2;
            return -1;
        }

        int getRight(int i) {
            if (i * 2 + 1 <= size) return i * 2 + 1;
            return -1;
        }

        int getParent(int i) {
            if (i == 1) return -1;
            return i / 2;
        }

        void add(T val) {
            tree.push_back(val);
            size++;
        }
};

int main() {
    int n;
    cin >> n;
    BinaryTree<int> tree;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        tree.add(temp);
    }
    //This example prints all the nodes in the left.
    int curr = 1;
    while (curr != -1) {
        cout << tree[curr] << ' ';
        curr = tree.getLeft(curr);
    }
    cout << '\n';
}
