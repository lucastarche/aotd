//Inorder Traversal (+ RBTree Destructor)
//The main idea to get the ordered RBTree is to first print the entire left subtree, then the source node, and then the entire right subtree.
//This can be easily implemented by using a recursive function.
//Runtime: O(n)
#include "111-FixRemoving.cpp"

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