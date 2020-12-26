//Red Black Tree: Constructor and Colouring
//Today we declare the constructor, which assigns a special Node, null, which will be the leaves, instead of using a nullptr.
//Runtime: we can construct and colour in O(1).
#include "105-RedBlackTree.cpp"

template <typename T>
RBTree<T>::RBTree() {
    null = new Node<T>;
    null->col = Colour::Black;
    null->left = nullptr;
    null->right = nullptr;
    root = null;
}

template <typename T>
void RBTree<T>::recolour(Node<T> *node) {
    if (node->col == Colour::Black) node->col = Colour::Red;
    else node->col = Colour::Red;
}

template <typename T>
void RBTree<T>::colour(Node<T> *node, Colour newColour) {
    node->col = newColour;
}