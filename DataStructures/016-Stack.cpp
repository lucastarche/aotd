//Stack
//A Last In, First Out (LIFO) data structure. It is used in problems such as bracket matching, or for making calculations in either Polish or Reverse Polish Notation, for example. This implementation uses a Double Linked List, but it can be more space efficient with a Reversed Linked List.
//Both push() and pop() work in O(1)
#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct Node {
    T val;
    struct Node* next;
    struct Node* prev;
};

template<typename T>
class Stack {
private:
    Node<T>*head, *tail;

public:
    Stack() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int val) {
        Node<T>* temp = new Node<T>;
        temp->val = val;
        temp->next = nullptr;
        temp->prev = tail;
        if (head == nullptr)
            head = tail = temp;
        else
            tail = tail->next = temp;
    }

    int pop() {
        if (head == nullptr)
            throw length_error("The container is empty");
        int ans = tail->val;
        Node<T>* temp = tail;
        tail = tail->prev;
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
    Stack<int>* s = new Stack<int>();
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        s->push(temp);
    }

    while (!s->empty()) {
        cout << s->pop() << ' ';
    }
    cout << '\n';
}
