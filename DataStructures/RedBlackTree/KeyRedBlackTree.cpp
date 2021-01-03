#include <bits/stdc++.h>

using namespace std;

enum class Colour {
    Black,
    Red
};

template <typename T, typename S>
struct Node {
    T key;
    S value;
    Node *parent;
    Node *left;
    Node *right;
    Colour col;
};

template <typename T, typename S>
class KeyedRBTree {
    protected:
        Node<T, S> *root;
        Node<T, S> *null;

        void leftRotation(Node<T, S> *src);
        void rightRotation(Node<T, S> *src);
        void recolour(Node<T, S> *node);
        void colour(Node<T, S> *node, Colour newColour);

        Node<T, S> *search(T key);
        Node<T, S> *minimum(Node<T, S> *src);
        void transplant(Node<T, S> *u, Node<T, S> *v);
        void fixInsertion(Node<T, S> *node);
        void fixRemove(Node<T, S> *node);
        void inOrder(Node<T, S> *src, vector<pair<T, S>> &ret);
    public:
        KeyedRBTree();
        ~KeyedRBTree();
        void insert(T key, S val);
        void remove(T key);
        bool contains(T key);
        vector<pair<T, S>> inOrder();
};

template <typename T, typename S>
KeyedRBTree<T, S>::KeyedRBTree() {
    null = new Node<T, S>;
    null->col = Colour::Black;
    null->left = nullptr;
    null->right = nullptr;
    root = null;
}

template <typename T, typename S>
void KeyedRBTree<T, S>::recolour(Node<T, S> *node) {
    if (node->col == Colour::Black) node->col = Colour::Red;
    else node->col = Colour::Red;
}

template <typename T, typename S>
void KeyedRBTree<T, S>::colour(Node<T, S> *node, Colour newColour) {
    node->col = newColour;
}

template <typename T, typename S>
void KeyedRBTree<T, S>::leftRotation(Node<T, S> *src) {
    if (src->right == null) return;
    Node<T, S> *x = src;
    Node<T, S> *y = src->right;

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

template <typename T, typename S>
void KeyedRBTree<T, S>::rightRotation(Node<T, S> *src) {
    if (src->left == null) return;
    Node<T, S> *x = src;
    Node<T, S> *y = src->left;

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

template <typename T, typename S>
Node<T, S>* KeyedRBTree<T, S>::search(T key) {
    Node<T, S> *x = root;
    Node<T, S> *y = null;
    while (x != null) {
        y = x;
        if (key == x->key) return x;
        else if (key < x->key) x = x->left;
        else x = x->right;
    }
    return y;
}

template <typename T, typename S>
bool KeyedRBTree<T, S>::contains(T key) {
    Node<T, S> *res = search(key);
    if (res == null) return false;
    return search(key)->key == key;
}

template <typename T, typename S>
void KeyedRBTree<T, S>::insert(T key, S val) {
    if (contains(key)) return;
    Node<T, S> *y = search(key);
    Node<T, S> *z = new Node<T, S>;

    //Set z as a child of y
    if (y == null) root = z;
    else if (key < y->key) y->left = z;
    else y->right = z;

    //Complete initialization of z
    z->key = key;
    z->value = val;
    z->parent = y;
    z->left = null;
    z->right = null;
    z->col = Colour::Red;
    fixInsertion(z);
}

template <typename T, typename S>
void KeyedRBTree<T, S>::fixInsertion(Node<T, S> *src) {
    Node<T, S> *uncle;
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

template <typename T, typename S>
void KeyedRBTree<T, S>::transplant(Node<T, S> *u, Node<T, S> *v) {
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

template <typename T, typename S>
Node<T, S> *KeyedRBTree<T, S>::minimum(Node<T, S> *src) {
    while (src->left != null) src = src->left;
    return src;
}

template <typename T, typename S>
void KeyedRBTree<T, S>::remove(T key) {
    if (!contains(key)) return;
    Node<T, S> *z = search(key);
    Node<T, S> *x, *y = z;
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
    delete z;
}

template <typename T, typename S>
void KeyedRBTree<T, S>::fixRemove(Node<T, S> *src) {
    Node<T, S> *brother;
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

template <typename T, typename S>
KeyedRBTree<T, S>::~KeyedRBTree() {
    stack<Node<T, S>*> s;
    s.push(root);
    while (!s.empty()) {
        Node<T, S> *curr = s.top();
        s.pop();
        if (curr->left != null) s.push(curr->left);
        if (curr->right != null) s.push(curr->right);
        delete curr;
    }
    delete null;
}

template <typename T, typename S>
vector<pair<T, S>> KeyedRBTree<T, S>::inOrder() {
    vector<T> ret;
    inOrder(root, ret);
    return ret;
}

template <typename T, typename S>
void KeyedRBTree<T, S>::inOrder(Node<T, S> *src, vector<pair<T, S>> &ret) {
    if (src == null) return;
    inOrder(src->left, ret);
    ret.push_back({src->key, src->value});
    inOrder(src->right, ret);
}