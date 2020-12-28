//Red Black Tree: Insertion
//Today we implement searching and insertion, which both run linearly with the height of a tree.
//Given the balancing property of the Red Black Tree, they both run in logarithmic time.
//Note that the insertion may violate some of the RBTree properties, hence why we will implement the fixInsertion() method.
//Runtime: O(log n) for both search and insert
#include "107-Rotations.cpp"

template <typename T>
Node<T>* RBTree<T>::search(T val) {
    Node<T> *x = root;
    Node<T> *y = null;
    while (x != null) {
        y = x;
        if (val == x->data) return x;
        else if (val < x->data) x = x->left;
        else x = x->right;
    }
    return y;
}

template <typename T>
bool RBTree<T>::contains(T val) {
    return search(val)->data == val;
}

template <typename T>
void RBTree<T>::insert(T val) {
    if (contains(val)) return;
    Node<T> *y = search(val);
    Node<T> *z = new Node<T>;

    //Set z as a child of y
    if (y == null) root = z;
    else if (val < y->data) y->left = z;
    else y->right = z;

    //Complete initialization of z
    z->parent = y;
    z->left = null;
    z->right = null;
    z->col = Colour::Red;
    fixInsertion(z);
}