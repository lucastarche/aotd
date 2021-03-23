//Heap
//A useful data structure, in which we can extract the maximum or the minimum in logarithmic time.
//In this case, it is implemented as a min-heap with a binary tree.
//push() and extract() both work in O(log n)
//Also implemented heapsort with this homebrewed heap as a bonus.
#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Heap {
private:
    vector<T> tree;
    int size;

    int getLeft(int i) {
        if (i * 2 <= size)
            return i * 2;
        return -1;
    }

    int getRight(int i) {
        if (i * 2 + 1 <= size)
            return i * 2 + 1;
        return -1;
    }

    int getParent(int i) {
        if (i == 1)
            return -1;
        return i / 2;
    }

    void MinHeapify(int i) {
        int left = getLeft(i);
        int right = getRight(i);
        int smallest = i;

        if (left != -1 && tree[left] < tree[smallest]) {
            smallest = left;
        }
        if (right != -1 && tree[right] < tree[smallest]) {
            smallest = right;
        }

        if (smallest != i) {
            swap(tree[i], tree[smallest]);
            MinHeapify(smallest);
        }
    }

public:
    Heap() {
        tree.resize(1);
        size = 0;
    }

    void push(T val) {
        tree.push_back(val);
        size++;
        int curr = size;
        while (getParent(curr) != -1 && tree[curr] < tree[getParent(curr)]) {
            swap(tree[curr], tree[getParent(curr)]);
            curr = getParent(curr);
        }
    }

    T extract() {
        T ans = tree[1];
        tree[1] = tree[size];
        tree.pop_back();
        size--;
        MinHeapify(1);
        return ans;
    }

    bool empty() {
        return !size;
    }
};

int main() {
    int n;
    cin >> n;
    Heap<int> heap;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        heap.push(temp);
    }

    while (!heap.empty()) {
        cout << heap.extract() << " ";
    }
    cout << '\n';
}
