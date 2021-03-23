//PE8: Largest Product in a Series
//Problem: Given a 1000-digit number, find the product of the thirteen adjacent digits which yield the highest product.
//Solution: We can use a technique known as "sliding window" to process each number once, instead of calculating the product every time.
//For this, we maintain two indexes, which we increment in each iteration, and we can get the new product by dividing by the left pointer, and multiplying by the right pointer.
//Note that we keep a counter to make sure we never divide by zero.
//Runtime: O(n), where n is the number of digits.
#include "EulerUtils.hpp"

long long solve(string input) {
    int a = 0, b = 0, zeroes = 0;

    long long product = 1LL, ans = 1LL;
    while (b - a < 13) {
        if (input[b] == '0') {
            zeroes++;
        } else {
            product *= (long long)(input[b] - '0');
        }
        b++;
    }

    while (b < input.size()) {
        if (input[a] == '0') {
            zeroes--;
        } else {
            product /= (long long)(input[a] - '0');
        }
        if (input[b] == '0') {
            zeroes++;
        } else {
            product *= (long long)(input[b] - '0');
        }
        a++;
        b++;

        if (zeroes == 0)
            ans = max(ans, product);
    }

    return ans;
}

int main() {
    ifstream inputStream("input-008.txt");
    string in;
    inputStream >> in;
    cout << solve(in) << '\n';
}