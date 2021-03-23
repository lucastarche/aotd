//Linked List
//A simple list in which each node contains two values: its value, and a pointer to the next node.
//Average time finding the nth element: O(n)
//Average Insertion runtime: O(1) in the start and end, O(m) in the middle where m is the position in the list.
//Average Deletion runtime: same as insertion
#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct Node {
    T val;
    struct Node* next;
};

template<typename T>
class LinkedList {
private:
    Node<T>*head, *tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~LinkedList() {
        Node<T>* next;
        while (head != nullptr) {
            next = head->next;
            delete head;
            head = next;
        }
    }

    void append(int n) {
        Node<T>* temp = new Node<T>;
        temp->val = n;
        temp->next = nullptr;
        if (head == nullptr)
            head = tail = temp;
        else
            tail = tail->next = temp;
    }

    //Returns the value at the nth position, or the last one if there aren't enough nodes.
    int getValueAtPos(int n) {
        Node<T>* temp = head;
        while (temp != nullptr && n > 0) {
            temp = temp->next;
            n--;
        }
        return temp->val;
    }
};

int main() {
    int n;
    cin >> n;
    LinkedList<int>* list = new LinkedList<int>();
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        list->append(temp);
    }

    int pos;
    cin >> pos;
    cout << list->getValueAtPos(pos) << '\n';
}
