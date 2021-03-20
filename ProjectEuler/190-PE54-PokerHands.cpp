//PE 54: Poker Hands
//Problem: Given a number of poker hands, determine how many times player 1 won.
//Solution: Nothing of interest, just a hardcody problem.
//Runtime: O(n)
#include "EulerUtils.hpp"

struct Card {
    int value;
    char suit;
};

using Hand = array<Card, 5>;

bool operator<(const Card &lhs, const Card &rhs) {
    if (lhs.value == rhs.value) return lhs.suit < rhs.suit;
    return lhs.value < rhs.value;
}

ifstream& operator>>(ifstream& in, Card &card) {
    string s;
    in >> s;
    switch (s[0]) {
        case 'T':
            card.value = 10;
            break;
        case 'J':
            card.value = 11;
            break;
        case 'Q':
            card.value = 12;
            break;
        case 'K':
            card.value = 13;
            break;
        case 'A':
            card.value = 14;
            break;
        default:
            card.value = s[0] - '0';
    }

    card.suit = s[1];
    return in;
}

ifstream& operator>>(ifstream& in, Hand &hand) {
    for (int i = 0; i < 5; i++) {
        in >> hand[i];
    }

    sort(hand.begin(), hand.end());
    return in;
}

int straight(const Hand &h) {
    for (int i = 0; i < 4; i++) {
        if (h[i].value + 1 != h[i + 1].value) return -1;
    }
    return h[4].value;
}

int flush(const Hand &h) {
    char suit = h[0].suit;
    for (int i = 1; i <= 4; i++) {
        if (h[i].suit != suit) return -1;
    }
    return h[4].value;
}

int royalFlush(const Hand &h) {
    if (flush(h) > 0 && straight(h) == 14) return 14;
    return -1;
}

int straightFlush(const Hand &h) {
    if (flush(h) > 0 && straight(h) > 0) return flush(h);
    return -1;
}

vector<int> getFrequency(const Hand &h) {
    vector<int> freq(15, 0);
    for (auto a : h) freq[a.value]++;
    return freq;
}

int fourOfAKind(const Hand &h) {
    auto freq = getFrequency(h);
    for (int i = 0; i < 15; i++) {
        if (freq[i] == 4) return i;
    }
    return -1;
}

int threeOfAKind(const Hand &h) {
    auto freq = getFrequency(h);
    for (int i = 0; i < 15; i++) {
        if (freq[i] == 3) return i;
    }
    return -1;
}

int twoPairs(const Hand &h) {
    auto freq = getFrequency(h);
    bool foundPair = false;
    for (int i = 0; i < 15; i++) {
        if (freq[i] == 2) {
            if (foundPair) return i;
            foundPair = true;
        }
    }
    return -1;
}

int onePair(const Hand &h) {
    auto freq = getFrequency(h);
    for (int i = 0; i < 15; i++) {
        if (freq[i] == 2) return i;
    }
    return -1;
}

int fullHouse(const Hand &h) {
    if (threeOfAKind(h) > 0 && onePair(h) > 0) return max(threeOfAKind(h), onePair(h));
    return -1;
}

bool firstPlayerWon(const Hand &a, const Hand &b) {
    if (royalFlush(a) != royalFlush(b))             return royalFlush(a) > royalFlush(b);
    if (straightFlush(a) != straightFlush(b))       return straightFlush(a) > straightFlush(b);
    if (fourOfAKind(a) != fourOfAKind(b))           return fourOfAKind(a) > fourOfAKind(b);
    if (fullHouse(a) != fullHouse(b))               return fullHouse(a) > fullHouse(b);
    if (flush(a) != flush(b))                       return flush(a) > flush(b);
    if (straight(a) != straight(b))                 return straight(a) > straight(b);
    if (threeOfAKind(a) != threeOfAKind(b))         return threeOfAKind(a) > threeOfAKind(b);
    if (twoPairs(a) != twoPairs(b))                 return twoPairs(a) > twoPairs(b);
    if (onePair(a) != onePair(b))                   return onePair(a) > onePair(b);

    for (int i = 4; i >= 0; i--) {
        if (a[i].value != b[i].value) return a[i].value > b[i].value;
    }

    return false;
}

long long solve(const vector<pair<Hand, Hand>> &games) {
    long long ans = 0LL;
    for (auto& game : games) {
        if (firstPlayerWon(game.first, game.second)) ans++;
    }
    return ans;
}

int main() {
    ifstream in("input-054.txt");
    vector<pair<Hand, Hand>> games;

    for (pair<Hand, Hand> game; in >> game.first >> game.second;) {
        games.push_back(game);
    }

    cout << solve(games) << '\n';
}
