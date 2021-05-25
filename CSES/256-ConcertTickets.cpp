//Concert tickets
//Problem: Given a list of tickets, each with their own price, and a list of customers who are willing to pay up to a certain price
//determine how many each customer pays, or -1 if he can't buy any ticket. Each ticket may only be bought once.
//Solution: We can use a multiset ordered from greatest to lowest to find the most expensive ticket each customer is
//willing to buy. If he can buy it, we sell it and remove it from the multiset, else we go to the next customer.
//Runtime: O(n log n)

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    multiset<int, greater<int>> tickets;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        tickets.insert(temp);
    }

    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        auto lower = tickets.lower_bound(t);
        if (lower == tickets.end()) {
            cout << "-1\n";
            continue;
        } else {
            cout << *lower << '\n';
            tickets.erase(lower);
        }
    }
}