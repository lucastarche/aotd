//PE 93: Arithmetic Expressions
//Problem: Find the largest set of positive integer results that can be obtained with four different digits a, b, c, d, + - * /, and parenthesis/
//Solution: This is an ugly one, but in short we iterate through every digit, operation and parenthesis expression.
//Runtime: O(d^4 * ops^3 * par), where par is the number of valid parenthesis expressions
#include "EulerUtils.hpp"

string ops = "+-*/";

double op(double lhs, double rhs, char c) {
    switch (c) {
    case '+':
        return lhs + rhs;
    case '-':
        return lhs - rhs;
    case '*':
        return lhs * rhs;
    case '/':
        return lhs / rhs;
    }
    return 0;
}

vector<long long> evaluate(vector<int> nums, vector<char> exp) {
    vector<long long> ret;

    do {
        vector<double> values = {
            op(op(op(nums[0], nums[1], exp[0]), nums[2], exp[1]), nums[3], exp[2]),
            op(op(nums[0], op(nums[1], nums[2], exp[1]), exp[0]), nums[3], exp[2]),
            op(nums[0], op(op(nums[1], nums[2], exp[1]), nums[3], exp[2]), exp[0]),
            op(nums[0], op(nums[1], op(nums[2], nums[3], exp[2]), exp[1]), exp[0]),
            op(op(nums[0], nums[1], exp[0]), op(nums[2], nums[3], exp[2]), exp[1])
        };
        for (auto v : values) {
            if (abs(v - floor(v)) < 1e-4) {
                if (v > 0) {
                    ret.push_back(floor(v));
                } else if (v < 0) {
                    ret.push_back(floor(-v));
                }
            }
        }
    } while (next_permutation(nums.begin(), nums.end()));

    return ret;
}

long long solve(int a, int b, int c, int d) {
    bitset<9 * 8 * 7 * 6 + 1> possible;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                for (auto n : evaluate({ a, b, c, d }, { ops[i], ops[j], ops[k] })) {
                    possible[n] = true;
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 1;; i++) {
        if (possible[i]) {
            ans++;
        } else {
            return ans;
        }
    }
}

long long solve() {
    long long ans_val = 0, ans = 0;
    for (int a = 0; a <= 9; a++) {
        for (int b = a + 1; b <= 9; b++) {
            for (int c = b + 1; c <= 9; c++) {
                for (int d = c + 1; d <= 9; d++) {
                    long long temp = solve(a, b, c, d);
                    if (temp > ans_val) {
                        ans_val = temp;
                        ans = a * 1000 + b * 100 + c * 10 + d;
                    }
                }
            }
        }
    }

    return ans;
}

int main() {
    cout << solve() << '\n';
}