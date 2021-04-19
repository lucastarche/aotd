//PE 84: Monopoly Odds
//Problem: Find the three most visited squares in a monopoly board if we roll two D4 on each turn.
//Solution: Nothing too interesting, we just simulate a ton of turns and keep track of which squares we visited, and then return the three highest ones.
//Runtime: O(n + m log m), where n is the amount of turns, and m is the amount of squares.
#include "EulerUtils.hpp"

pair<int, bool> rollTwoD4() {
    static default_random_engine generator;
    static uniform_int_distribution<int> distribution(1, 4);
    static auto dice = bind(distribution, generator);
    int roll1 = dice();
    int roll2 = dice();
    return { roll1 + roll2, roll1 == roll2 };
}

int rollCard() {
    static default_random_engine generator;
    static uniform_int_distribution<int> distribution(1, 16);
    static auto card = bind(distribution, generator);
    return card();
}

void communityChest(int& position) {
    int card = rollCard();
    if (card == 1)
        position = 0; //Go to GO
    if (card == 2)
        position = 10; //Go to JAIL
}

void chance(int& position) {
    int card = rollCard();
    switch (card) {
    case 1:
        position = 0;
        break;
    case 2:
        position = 10;
        break;
    case 3:
        position = 11;
        break;
    case 4:
        position = 24;
        break;
    case 5:
        position = 39;
        break;
    case 6:
        position = 5;
        break;
    case 7:
    case 8:
        if (position <= 5)
            position = 5;
        else if (position <= 15)
            position = 15;
        else if (position <= 25)
            position = 25;
        else if (position <= 35)
            position = 35;
        else
            position = 5;
        break;
    case 9:
        if (position < 12)
            position = 12;
        else if (position < 28)
            position = 28;
        else
            position = 12;
        break;
    case 10:
        position -= 3;
        position = (position + 40) % 40;
        break;
    }
}

string solve() {
    const int runs = 1e7;
    vector<int> visited(40, 0);

    int position = 0, doubles = 0;
    for (int i = 0; i < runs; i++) {
        auto roll = rollTwoD4();
        position = (position + roll.first) % 40;
        if (roll.second) {
            doubles++;
            if (doubles == 3)
                position = 10; // Three doubles, goes to jail
        } else {
            doubles = 0;
        }

        if (position == 30)
            position = 10; // Go to Jail
        else if (position == 7 || position == 22 || position == 36)
            chance(position);
        else if (position == 2 || position == 17 || position == 33)
            communityChest(position);

        visited[position]++;
    }

    vector<pair<int, int>> amount;
    for (int i = 0; i < 40; i++) {
        amount.push_back({ visited[i], i });
    }
    sort(amount.rbegin(), amount.rend());

    string ans = "";
    for (int i = 0; i < 3; i++) {
        if (amount[i].second < 10)
            ans += '0';
        ans += to_string(amount[i].second);
    }

    return ans;
}

int main() {
    cout << solve() << '\n';
}