//Tortoise and Hare algorithm (also known as Floyd's Cycle Finding algorithm)
//We can prove that any successor graph ends in a cycle, given the fact that at least one of the indices will appear more than once, or the entire graph is the cycle.
//We mantain two pointers, the turtle, which moves at one node per iteration, and the hare, which moves twice as fast.
//This allows us to find mu and lambda in three main parts.
//Runtime: O(mu + lambda), with O(1) extra space. 
//Mu is the length to the cycle, and lambda is the cycle length.
#include <bits/stdc++.h>

using namespace std;

class SuccessorGraph {
    private:
        vector<int> next;
    public:
        SuccessorGraph(vector<int> next) : next{next} { }

        int succ(int x) {
            return next[x];
        }

        int size() {
            return (int)next.size();
        }

        pair<int, int> cycleFinding(int start) {
            //Part 1: Finding k*lambda for some k.
            int tortoise = succ(start), hare = succ(succ(start));
            while (tortoise != hare) {
                tortoise = succ(tortoise);
                hare = succ(succ(hare));
            }
            //Part 2: Finding mu. Both pointers now move at same speed.
            //We keep tortoise at its position, and hare is reset.
            int mu = 0, hare = start;
            while (tortoise != hare) {
                tortoise = succ(tortoise);
                hare = succ(hare);
                mu++;
            }
            //Part 3: Finding lambda. Given that we are at the start of the loop now,
            //we just move one of the pointers until they meet.
            int lambda = 1, hare = succ(tortoise);
            while (tortoise != hare) {
                hare = succ(hare);
                lambda++;
            }
            return {mu, lambda};
        }
};

int main() {
    int n;
    cin >> n;
    vector<int> next(n);
    for (int i = 0; i < n; i++) cin >> next[i];

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