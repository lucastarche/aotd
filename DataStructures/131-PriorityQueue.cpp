//Priority Queue
//A data structure in which we sort its elements by a number (the "priority").
//Runtime: O(n) insertion and O(1) top retrieval
//There are data structures which allow for faster insertion, such as is the case of the Fibonacci heap, with O(1) insertion, and O(log n) retrieval.
#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct PQNode {
    T data;
    int priority;
};

template<typename T>
class PriorityQueue {
private:
    vector<PQNode<T>> nodes;

public:
    PriorityQueue() { }

    void push(T value, int priority) {
        PQNode<T> nextNode;
        nextNode.data = value;
        nextNode.priority = priority;

        int index = 0;
        for (PQNode<T> node : nodes) {
            if (node.priority < nextNode.priority) {
                nodes.insert(index, nextNode);
                return;
            }
            index++;
        }

        //If it has the worst priority so far, we push it in the end
        nodes.push_back(nextNode);
    }

    T top() {
        return nodes.back().data;
    }

    void pop() {
        nodes.pop_back();
    }

    bool empty() {
        return nodes.empty();
    }
}

int
main() {
    int n;
    cin >> n;
    PriorityQueue<int> pq;
    for (int i = 0; i < n; i++) {
        int temp, priority;
        cin >> temp >> priority;
        pq.push(temp, priority);
    }

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << '\n';
}
