//Brent's Cycle Finding Algorithm
//This is an improved version of the Tortoise and Hare algorithm.
//It has the same complexity as the former, but has a smaller constant factor, as it visits the cycle only once.
//Runtime: O(mu + lambda), with O(1) extra memory space.
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

    pair<int, int> cycleFinding(int start) {
        int tortoise = start, hare = succ(start);
        int power = 1, lambda = 1;

        while (tortoise != hare) {
            if (power == lambda) {
                tortoise = hare;
                power *= 2;
                lambda = 0;
            }
            hare = succ(hare);
            lambda++;
        }

        tortoise = hare = start;
        for (int i = 0; i < lambda; i++)
            hare = succ(hare);

        int mu = 0;
        while (tortoise != hare) {
            tortoise = succ(tortoise);
            hare = succ(hare);
            mu++;
        }

        return { mu, lambda };
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
        pair<int, int> ans = g.cycleFinding(a);
        cout << ans.first << " " << ans.second << '\n';
    }
}