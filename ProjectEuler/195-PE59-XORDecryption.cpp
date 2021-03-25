//PE 59: XOR Decryption
//Problem: Given a message which was encrypted by XORing its characters with a three lowercase characters long, find the sum of the ASCII values of the original message.
//Solution: We can run a frequency analysis for each different character of the key, and then choose the one which has the higher number of spaces or 'e's.
//This is because ' ' and 'e' are the two most frequent characters in English, and should be the ones to appear with most frequency.
//Runtime: O(n), where k is the number of characters, and n is the number of characters.
//Note that this method only works if k is much smaller than n
#include "EulerUtils.hpp"

vector<int> decrypt(const vector<int>& message, int key, int r) {
    int n = (int)message.size();
    vector<int> res(n, 0);
    for (int i = r; i < n; i += 3) {
        res[i] = message[i] ^ key;
    }
    return res;
}

int countFreq(const vector<int>& message) {
    int res = 0;
    for (auto a : message) {
        if (a == ' ' || a == 'e')
            res++;
    }
    return res;
}

long long solve(vector<int>& message) {
    array<pair<int, int>, 3> key;
    for (int i = 0; i < 3; i++) {
        for (int j = 'a'; j <= 'z'; j++) {
            int freq = countFreq(decrypt(message, j, i));
            if (freq > key[i].first) {
                key[i] = { freq, j };
            }
        }
    }

    int n = (int)message.size();
    string res(n, ' ');
    long long ans = 0LL;
    for (int i = 0; i < n; i++) {
        char curr = (char)(key[i % 3].second ^ message[i]);
        res[i] = curr;
        ans += (long long)curr;
    }
    cout << res << '\n';

    return ans;
}

int main() {
    ifstream in("input-059.txt");
    string buf;
    getline(in, buf);

    int curr = 0;
    vector<int> message;
    for (auto c : buf) {
        if (c == ',') {
            message.push_back(curr);
            curr = 0;
        } else {
            curr *= 10;
            curr += c - '0';
        }
    }
    message.push_back(curr);

    cout << solve(message) << '\n';
}
