//Planet Queries 1
//Problem: Given a functional graph, answer q queries of the form "Which node will I get to if I start in node i and travel through k edges?"
//Solution: We can use binary lifting to answer the queries in O(log k) time. This idea is that we precalculate the answer for all queries (i, 2^j),
//and then reconstruct the solution by doing binary jumps to reconstruct the asked k.
//For example, for k = 11 we would do a jump of 8, one of 2 and one of 1.
//We can compute these jumps efficiently by using the fact that jumping 2^j times is the same as jumping twice 2^(j - 1) times
//Runtime: O(n log k + q log k), where n is the number of nodes, k is the maximum distance value, and q is the number of queries.
//Note that we need Fast I/O for this problem
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
int next_val[MAXN + 10][31];

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    for (int i = 1; i <= n; i++) {
        cin >> next_val[i][0];
    }

    for (int j = 1; j < 31; j++) {
        for (int i = 1; i <= n; i++) {
            next_val[i][j] = next_val[next_val[i][j - 1]][j - 1];
        }
    }

    for (int q_i = 0; q_i < q; q_i++) {
        int x, k;
        scanf("%d %d", &x, &k);

        for (int j = 0; j < 31; j++) {
            if (k & (1 << j)) {
                x = next_val[x][j];
            }
        }

        printf("%d\n", x);
    }
}