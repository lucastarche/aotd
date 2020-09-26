//Linked List
//A simple list in which each node contains two values: its value, and a pointer to the next node.
//Average time finding the nth element: O(n)
//Average Insertion runtime: O(1) in the start and end, O(m) in the middle where m is the position in the list.
//Average Deletion runtime: same as insertion
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    struct Node *next;
};

class LinkedList {
    private:
        Node *head, *tail;
    public:
        LinkedList() {
            head = nullptr;
            tail = nullptr;
        }

        void append(int n) {
            Node* temp = new Node;
            temp->val = n;
            temp->next = nullptr;
            if (head == nullptr) head = tail = temp;
            else tail = tail->next = temp;
        }

        //Returns the value at the nth position, or the last one if there aren't enough nodes.
        int getValueAtPos(int n) {
            Node* temp = head;
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
    LinkedList *list = new LinkedList();
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        list->append(temp);
    }

    int pos;
    cin >> pos;
    cout << list->getValueAtPos(pos) << '\n';
}
