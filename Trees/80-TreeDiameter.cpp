//Tree Diameter
//Gets the longest path possible in the tree, also known as the diameter.
//The main idea is to note that each path has a highest point, that is, a node which is the closest to the root.
//We can then get the longest path whose highest point is x in O(1), by adding two to the sum of the two highest LongestRootedPaths.
//Runtime: O(n) if we store the values of RootedLongestPath(), O(n^2) if we don't.
#include <bits/stdc++.h>

using namespace std;

class Tree {
    private:
        int n;
        vector<int> parents;
        vector<vector<int>> children;
    public:
        Tree() {
            parents.resize(1, 0);
            children.resize(1);
            n = 1;
        }

        void insert(int parent) {
            parents.push_back(parent);
            children.push_back({});
            children[parent].push_back(n);
            n++;
        }

        int RootedLongestPath(int start) {
            int ans = 0;
            for (auto child : children[start]) {
                ans = max(ans, RootedLongestPath(child) + 1);
            }
            return ans;
        }

        int MaxLengthHighestPoint(int start) {
            if (children[start].size() == 0) 
                return 0;
            else if (children[start].size() == 1) 
                return RootedLongestPath(children[start][0]) + 1;
        
            int greatest = 0, secondGreatest = 0;    
            for (auto child : children[start]) {
                int val = RootedLongestPath(child);
                if (val > greatest) {
                    secondGreatest = greatest;
                    greatest = val;
                }
                else if (val > secondGreatest) {
                    secondGreatest = val;
                }
            }

            return greatest + secondGreatest + 2;
        }

        int TreeDiameter() {
            int ans = 0;
            for (int i = 0; i < n; i++) {
                ans = max(ans, MaxLengthHighestPoint(i));
            }
            return ans;
        }
};

int main() {
    int amount;
    cin >> amount;
    Tree tree;
    for (int i = 0; i < amount; i++) {
        int temp;
        cin >> temp;
        tree.insert(temp);
    }

    cout << tree.TreeDiameter() << '\n';
}