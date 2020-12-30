//Red Black Tree
//One of the big boy data structures, so I decided to split the implementation across several days.
//A Red-Black Tree is a type of Self-Balancing Binary Tree, which allows for efficient insertion and deletion.
//Every Node is assigned a colour, which can be Black or Red. 
//The Red Black Tree maintains a property, that the path from the root to every leaf has the same amount of black nodes.
//To ensure this, we have the operations rotateLeft and rotateRight, as well as changing the colour of a Node.
//This kind of tree can be used to implement ordered sets and maps. 
//Runtime: insertion and deletion run both in O(log n). 
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
    public:
        RBTree();
        void insert(T val);
        void remove(T val);
        bool contains(T val);
};