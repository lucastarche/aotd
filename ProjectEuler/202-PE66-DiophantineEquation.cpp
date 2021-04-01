//PE 66: Diophantine Equation
//Problem: The interger diophantine equation x^2 - D * y^2 = 1 has solutions if D is not a perfect square.
//Find the value of D less than 1000 such that the minimal integral solution with x >= 1 and y >= 1 has the max value of x.
//Solution: This special equation is known as "Pell's equation", and the minimum solution will be one of the convergents of sqrt(D).
//Then it is just a matter of trying every convergent until we get to a result.
//Runtime: O(n^3) aprox (since we don't know how fast we can solve the equation).
//Note that we need to use BigIntegers to avoid overflow (and that i am using Roshan Gupta's library because mine was broken apparently)
#include "../lib/bigint.h"
#include "EulerUtils.hpp"

vector<long long> getPeriod(long long x) {
    long long sqrtx = (long long)sqrt(x);
    long long a = sqrtx;
    long long M = 0, D = 1;

    vector<long long> ans;
    while (a != 2 * sqrtx) {
        M = D * a - M;
        D = (x - M * M) / D;
        a = (sqrtx + M) / D;
        ans.push_back(a);
    }

    return ans;
}

long long solve() {
    queue<long long> squares;
    for (long long i = 2; i * i <= 1000; i++)
        squares.push(i * i);

    bigint ans_val = 0;
    long long ans_idx = 0;
    for (long long D = 2; D <= 1000; D++) {
        if (squares.front() == D) {
            squares.pop();
            continue;
        }

        vector<long long> period = getPeriod(D);

        int periodIndex = 0, periodLength = (int)period.size();

        bigint h_1 = (int)floor(sqrt(D)), h_2 = 1;
        bigint k_1 = 1, k_2 = 0;
        while (true) {
            if (h_1 * h_1 - k_1 * k_1 * bigint(D) == bigint(1)) {
                if (h_1 > ans_val) {
                    ans_val = h_1;
                    ans_idx = D;
                }
                break;
            }

            bigint h_0 = h_1 * bigint(period[periodIndex]) + h_2;
            bigint k_0 = k_1 * bigint(period[periodIndex]) + k_2;

            h_2 = h_1;
            h_1 = h_0;
            k_2 = k_1;
            k_1 = k_0;

            periodIndex = (periodIndex + 1) % periodLength;
        }
    }

    return ans_idx;
}

int main() {
    cout << solve() << '\n';
}