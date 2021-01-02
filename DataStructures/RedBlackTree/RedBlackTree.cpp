//Red Black Tree
//A single file, which contains days 105 to 112, as well as driver code to test the tree out.
#include <bits/stdc++.h>

using namespace std;

enum class Colour {
    Black,
    Red
};

template <typename T>
struct Node {
    T data;
    Node *parent;
    Node *left;
    Node *right;
    Colour col;
};

template <typename T>
class RBTree {
    private:
        Node<T> *root;
        Node<T> *null;

        void leftRotation(Node<T> *src);
        void rightRotation(Node<T> *src);
        void recolour(Node<T> *node);
        void colour(Node<T> *node, Colour newColour);

        Node<T> *search(T val);
        Node<T> *minimum(Node<T> *src);
        void transplant(Node<T> *u, Node<T> *v);
        void fixInsertion(Node<T> *node);
        void fixRemove(Node<T> *node);
        void inOrder(Node<T> *src, vector<T> &ret);
    public:
        RBTree();
        ~RBTree();
        void insert(T val);
        void remove(T val);
        bool contains(T val);
        vector<T> inOrder();
};

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
    Node<T> *res = search(val);
    if (res == null) return false;
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
    z->data = val;
    z->parent = y;
    z->left = null;
    z->right = null;
    z->col = Colour::Red;
    fixInsertion(z);
}

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
    delete z;
}

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

template <typename T>
RBTree<T>::~RBTree() {
    stack<Node<T>*> s;
    s.push(root);
    while (!s.empty()) {
        Node<T> *curr = s.top();
        s.pop();
        if (curr->left != null) s.push(curr->left);
        if (curr->right != null) s.push(curr->right);
        delete curr;
    }
    delete null;
}

template <typename T>
vector<T> RBTree<T>::inOrder() {
    vector<T> ret;
    inOrder(root, ret);
    return ret;
}

template <typename T>
void RBTree<T>::inOrder(Node<T> *src, vector<T> &ret) {
    if (src == null) return;
    inOrder(src->left, ret);
    ret.push_back(src->data);
    inOrder(src->right, ret);
}

/* Driver test code
int main() {
    RBTree<int> tree;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        tree.insert(temp);
    }

    for (auto a : tree.inOrder()) {
        cout << a << ' ';
    }
    cout << '\n';

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        tree.remove(temp);
    }

    for (auto a : tree.inOrder()) {
        cout << a << ' ';
    }
    cout << '\n';
}
*/