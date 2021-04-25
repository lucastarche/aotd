//PE 90: Cube Digit Pairs
//Problem: Find the number of ways one can choose digits in two cubes, such that you can form all 2 digit square numbers.
//Note that you can use the 6 as a 9 and viceversa.
//Solution: We can iterate through every possible first and second cube, and then just simply check if every condition holds or not.
//Runtime: O((n! / (n - k)! k !) ^ 2), where n is the number of digits, and k is the number of faces per cube.
#include "EulerUtils.hpp"

vector<pair<int, int>> conditions = {
    { 0, 1 },
    { 0, 4 },
    { 0, 9 },
    { 1, 6 },
    { 2, 5 },
    { 3, 6 },
    { 4, 9 },
    { 6, 4 },
    { 8, 1 }
};

bool areCubePair(const vector<bool>& lhs, const vector<bool>& rhs) {
    bool isCubePair = true;

    for (auto [first, second] : conditions) {
        if (first == 6 || first == 9) {
            if (!((lhs[second] && (rhs[9] | rhs[6]) || ((lhs[6] | lhs[9]) && rhs[second])))) {
                isCubePair = false;
            }
        } else if (second == 6 || second == 9) {
            if (!((lhs[first] && (rhs[9] | rhs[6]) || ((lhs[6] | lhs[9]) && rhs[first])))) {
                isCubePair = false;
            }
        } else {
            if (!((lhs[first] && rhs[second]) || (lhs[second] && rhs[first]))) {
                isCubePair = false;
            }
        }
    }

    return isCubePair;
}

long long solve() {
    vector<bool> firstCube { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1 };
    vector<bool> secondCube { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1 };

    long long ans = 0;
    do {
        do {
            ans += areCubePair(firstCube, secondCube);
        } while (next_permutation(secondCube.begin(), secondCube.end()));
    } while (next_permutation(firstCube.begin(), firstCube.end()));

    //Note: We divide by two because the cases (firstCube, secondCube) and (secondCube, firstCube) are the same.
    return ans / 2;
}

int main() {
    cout << solve() << '\n';
}
