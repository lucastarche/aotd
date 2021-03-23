//Binary Search Tree
//A Tree data structure in which the Binary Search property holds true. That means that every node to the left of every node is less than this node, and every node to the right is greater than itself.
//In theory, it should work in O(log n). However, given random insertions and deletions, in practice it works closer to O(sqrt n). This is because it is not a Self Balancing Binary Tree.
#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct Node {
    T val;
    Node<T>* parent;
    Node<T>* left;
    Node<T>* right;
};

template<typename T>
class BinarySearchTree {
private:
    Node<T>* root;

public:
    BinarySearchTree<T>() {
        root = nullptr;
    }

    void insert(T val) {
        if (root == nullptr) {
            root = new Node<T>;
            root->val = val;
            return;
        }
        Node<T>* curr = root;
        while (true) {
            T currVal = curr->val;
            if (currVal == val)
                return;
            if (currVal < val) {
                if (curr->left == nullptr) {
                    curr->left = new Node<T>;
                    curr->left->parent = curr;
                    curr->left->val = val;
                    return;
                } else
                    curr = curr->left;
            } else {
                if (curr->right == nullptr) {
                    curr->right = new Node<T>;
                    curr->right->parent = curr;
                    curr->right->val = val;
                    return;
                } else
                    curr = curr->right;
            }
        }
    }

    Node<T>* find(T val) {
        Node<T>* curr = root;
        while (curr != nullptr) {
            if (curr->val == val)
                return curr;
            if (curr->val < val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        return nullptr;
    }

    bool search(T val) {
        return find(val) != nullptr;
    }

    void replaceParent(Node<T>* curr, Node<T>* replacement) {
        if (curr->parent != nullptr) {
            if (curr == curr->parent->left)
                curr->parent->left = replacement;
            else
                curr->parent->right = replacement;
        }
    }

    void remove(T val) {
        Node<T>* node = find(val);
        if (node->left == nullptr && node->right == nullptr) {
            replaceParent(node, nullptr);
            delete node;
        } else if (node->left == nullptr) {
            replaceParent(node, node->right);
            delete node;
        } else if (node->right == nullptr) {
            replaceParent(node, node->left);
            delete node;
        } else {
            Node<T>* minmax = node->right;
            while (minmax->left != nullptr)
                minmax = minmax->left;
            if (minmax->parent != node)
                minmax->parent->left = nullptr;
            replaceParent(node, minmax);
            delete node;
        }
    }
};

int main() {
    int n;
    cin >> n;
    BinarySearchTree<int> BST;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        BST.insert(temp);
    }
    BST.remove(1);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int temp;
        cin >> temp;
        if (BST.search(temp)) {
            cout << temp << ": found\n";
        } else {
            cout << temp << ": not found\n";
        }
    }
}
