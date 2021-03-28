//PE 62: Cubic Permutations
//Problem: Find the smallest cube number such that exactly five of the permutations of its digits are also cube.
//Solution: For each cube number under a certain bound, we can sort its digits, and increase that permutation's cube frequency by one.
//Then we can simply iterate through every permutation's frequency, until we find the one which has frequency of five.
//Runtime: O(n log (n log n))
#include "EulerUtils.hpp"

long long solve() {
    map<string, int> freq;
    vector<pair<string, long long>> cubes;
    for (long long i = 1; i < 100000; i++) {
        long long cube = i * i * i;
        string cubeStr = to_string(cube);
        sort(cubeStr.begin(), cubeStr.end());
        freq[cubeStr]++;
        cubes.push_back({cubeStr, cube});
    }

    for (auto cube : cubes) {
        if (freq[cube.first] == 5) return cube.second;
    }

    return -1;
}

int main() {
    cout << solve() << '\n';
}
