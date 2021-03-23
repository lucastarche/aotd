//HeapSort
//Push all the elements to a max heap, and take out the elements one by one, and put them back to the vector.
//Heap implementation coming soon, for now I'll just use a priority queue, which is C++ standard implementation of one.
//Best case complexity: O(n log n)
//Average case complexity: O(n log n)
//Worst case complexity: O(n log n)
//Becomes slow after n = 200000, and unusable after n = 1000000
#include <bits/stdc++.h>

using namespace std;

void HeapSort(vector<int>& v) {
    priority_queue<int> heap;
    for (auto a : v)
        heap.push(a);
    int ctr = 0;
    while (!heap.empty()) {
        v[ctr] = heap.top();
        heap.pop();
        ctr++;
    }
    reverse(v.begin(), v.end());
}

int main() {
    int n;
    cin >> n;
    vector<int> elements(n);
    for (int i = 0; i < n; i++)
        cin >> elements[i];
    HeapSort(elements);
    cout << "Sorted Array:\n";
    for (auto a : elements)
        cout << a << " ";
    cout << '\n';
}
