//Red Black Tree: Rotations
//The left and right rotations are two constant operations, which are used to balance the red black tree.
//This operations have the property that the Binary-Search property of the tree is maintained.
//Runtime: O(1)
#include "106-ConstructorAndColouring.cpp"

template <typename T>
void RBTree<T>::leftRotation(Node<T> *src) {
    if (src->right == null) return;
    Node<T> *x = src;
    Node<T> *y = src->right;

    //Make y's left subtree into x's right subtree
    x->right = y->left; 
    if (y->left != null) y->left->parent = x;

    //Fix y's parent
    y->parent = x->parent;

    //Fix x's parent
    if (x->parent == null) root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;

    //Put x to the left of y
    y->left = x;
    x->parent = y;
}

template <typename T>
void RBTree<T>::rightRotation(Node<T> *src) {
    if (src->left == null) return;
    Node<T> *x = src;
    Node<T> *y = src->left;

    //Make y's right subtree into x's left subtree
    x->left = y->right; 
    if (y->right != null) y->right->parent = x;

    //Fix y's parent
    y->parent = x->parent;

    //Fix x's parent
    if (x->parent == null) root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;

    //Put x to the left of y
    y->right = x;
    x->parent = y;
}