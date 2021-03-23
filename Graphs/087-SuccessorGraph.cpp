//Succesor Graph
//Also known as a functional graph, or surjection graph.
//Each node only has one successor (also noted as f(x)), but can have more than one parent.
//Runtime: building runs in O(n).
#include <bits/stdc++.h>

using namespace std;

class SuccessorGraph {
private:
    vector<int> next;

public:
    SuccessorGraph(vector<int> next)
        : next { next } { }

    int succ(int x) {
        return next[x];
    }

    int size() {
        return (int)next.size();
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> next(n);
    for (int i = 0; i < n; i++)
        cin >> next[i];

    SuccessorGraph g(next);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        cout << g.succ(a) << '\n';
    }
}