//Red Black Tree: Fixing insertion
//This function restores the RBTree's properties. It is not hard, but there are quite some cases.
//Note that cases A and B are mirrored.
//Runtime: O(log n)
#include "108-Insertion.cpp"

template <typename T>
void RBTree<T>::fixInsertion(Node<T> *src) {
    Node<T> *uncle;
    while (src->parent->col == Colour::Red) {
        //Case A: the parent of src is a left children
        if (src->parent->parent->left == src->parent) {
            uncle = src->parent->parent->right;

            //Case A.1: the uncle is red
            if (uncle->col == Colour::Red) {
                src->parent->col = Colour::Black;
                uncle->col = Colour::Black;
                src->parent->parent->col = Colour::Red;
                src = src->parent->parent;
            }
            else {
                //Case A.2: uncle is black, src is a right children
                if (src == src->parent->right) {
                    src = src->parent;
                    leftRotation(src);
                }

                //Case A.3: uncle is black, src is a left children
                src->parent->col = Colour::Black;
                src->parent->parent->col = Colour::Red;
                rightRotation(src->parent->parent);
            }
        }
        //Case B: the parent of src is a right children
        else {
            uncle = src->parent->parent->left;

            //Case B.1: the uncle is red
            if (uncle->col == Colour::Red) {
                src->parent->col = Colour::Black;
                uncle->col = Colour::Black;
                src->parent->parent->col = Colour::Red;
                src = src->parent->parent;
            }
            else {
                //Case B.2: uncle is black, src is a left children
                if (src == src->parent->left) {
                    src = src->parent;
                    rightRotation(src);
                }

                //Case B.3: uncle is black, src is a right children
                src->parent->col = Colour::Black;
                src->parent->parent->col = Colour::Red;
                leftRotation(src->parent->parent);
            }
        }
    }

    //We ensure the root is black at the end of the function
    root->col = Colour::Black;
}