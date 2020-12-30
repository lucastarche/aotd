//Red Black Tree: Removal
//Removing nodes is a bit harder. The case in which the node to be removed has zero or one children is almost trivial.
//This is because removing a node with no children is just setting the parent's pointer to null.
//In the case of one children, we just move this children to the position of the original node.
//When we have two, we have to replace the original node with the minimum node of the right subtree.
//This node will maintain the binary-search property, because it is greater than the left subtree, and lower than the right subtree.
//If the node being removed is black, we have to fix the tree, because the red-black property has been broken. 
//Runtime: O(log n)
#include "109-FixInsertion.cpp"

template <typename T>
void RBTree<T>::transplant(Node<T> *u, Node<T> *v) {
    if (u->parent == nullptr || u->parent == null) {
        root = v;
    }
    else if (u == u->parent->left) {
        u->parent->left = v;
    }
    else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

template <typename T>
Node<T> *RBTree<T>::minimum(Node<T> *src) {
    while (src->left != null) src = src->left;
    return src;
}

template <typename T>
void RBTree<T>::remove(T val) {
    if (!contains(val)) return;
    Node<T> *z = search(val);
    Node<T> *x, *y = z;
    Colour y_original_colour = y->col;

    if (z->left == null) {
        x = z->right;
        transplant(z, x);
    }
    else if (z->right == null) {
        x = z->left;
        transplant(z, x);
    }
    else {
        y = minimum(z->right);
        y_original_colour = y->col;
        x = y->right;

        if (y->parent == z) {
            x->parent = y;
        }
        else {
            transplant(y, x);
            y->right = z->right;
            y->right->parent = y;
        }

        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->col = z->col;
    }

    if (y_original_colour == Colour::Black) {
        fixRemove(x);
    }
}