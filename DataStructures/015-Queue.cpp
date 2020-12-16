//Queue
//A First In, First Out (FIFO) data structure. Is useful for keeping things in a certain order, like when implementing an algorithm such as BFS. This specific implementation is similar to a Linked List.
//Both push() and pop() work in O(1)
#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct Node {
    T val;
    struct Node *next;
};

template <typename T>
class Queue {
    private:
        Node<T> *head, *tail;
    public:
        Queue() {
            head = nullptr;
            tail = nullptr;
        }

        void push(int val) {
            Node<T> *temp = new Node<T>;
            temp->val = val;
            temp->next = nullptr;
            if (head == nullptr) head = tail = temp;
            else tail = tail->next = temp;
        }

        int pop() {
            if (head == nullptr) throw length_error("The container is empty");
            int ans = head->val;
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            return ans;
        }

        bool empty() {
            return head == nullptr;
        }
};

int main() {
    int n;
    cin >> n;
    Queue<int> *q = new Queue<int>();
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        q->push(temp);
    }

    while (!q->empty()) {
        cout << q->pop() << ' ';
    }
    cout << '\n';
}
