//Red Black Tree: Fixing Removal
//The main idea is to "bubble up" the extra black node we have leftover.
//The loop ends when we get to the root, in which case we can simply "delete" the extra black node, or when we get to a red node, in which case we colour it black.
//Note that cases A and B are symmetrical 
//Runtime: O(log n)
#include "110-Removing.cpp"

template <typename T>
void RBTree<T>::fixRemove(Node<T> *src) {
    Node<T> *brother;
    while (src != root && src->col == Colour::Black) {
        //Case A: src is a left children
        if (src == src->parent->left) {
            brother = src->parent->right;
            //Case A.1: Brother node is red
            if (brother->col == Colour::Red) {
                brother->col = Colour::Black;
                src->parent->col = Colour::Red;
                leftRotation(src->parent);
                brother = src->parent->right;
            }
            
            //Case A.2: Brother node has two black children.
            if (brother->left->col == Colour::Black && brother->right->col == Colour::Black) {
                brother->col = Colour::Red;
                src = src->parent;
            }
            else {
                //Case A.3: Only the right child of the brother is black
                if (brother->right->col == Colour::Black) {
                    brother->left->col = Colour::Black;
                    brother->col = Colour::Red;
                    rightRotation(brother);
                    brother = src->parent->right;
                }
                //Case A.4: The right children of the brother is red
                brother->col = src->parent->col;
                src->parent->col = Colour::Black;
                brother->right->col = Colour::Black;
                leftRotation(src->parent);
                src = root;
            }
        }
        //Case B: src is a right children
        else {
            brother = src->parent->left;
            if (brother->col == Colour::Red) {
                brother->col = Colour::Black;
                src->parent->col = Colour::Red;
                rightRotation(src->parent);
                brother = src->parent->left;
            }
            
            if (brother->left->col == Colour::Black && brother->right->col == Colour::Black) {
                brother->col = Colour::Red;
                src = src->parent;
            }
            else {
                if (brother->left->col == Colour::Black) {
                    brother->right->col = Colour::Black;
                    brother->col = Colour::Red;
                    leftRotation(brother);
                    brother = src->parent->left;
                }
                brother->col = src->parent->col;
                src->parent->col = Colour::Black;
                brother->left->col = Colour::Black;
                rightRotation(src->parent);
                src = root;
            }
        }
    }

    src->col = Colour::Black;
}