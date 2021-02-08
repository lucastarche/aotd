//PE 14: Longest Collatz Sequence
//Problem: Find the number n under 1 million such that it generates the longest Collatz sequence. (f(n) = n / 2 if n is even, 3*n + 1 otherwise).
//Solution: We can keep track of the numbers that we already visited, and only calculate those which we didnt visit yet.
//This means that we will visit each number at most one time, and we can simply find the one which generates the longest sequence.
//Runtime: O(n)
#include "EulerUtils.hpp"

long long solve() {
	vector<long long> collatz(1000000, 0);
	collatz[0] = 0;
	collatz[1] = 1;
	for (long long i = 2LL; i < 1000000LL; i++) {
		if (collatz[i] != 0) continue;
		stack<long long> s;
		s.push(i);
		long long curr = i;
		while (curr >= 1000000LL || collatz[curr] == 0) {
			if (curr % 2LL == 0LL) {
				curr /= 2LL;
			}
			else {
				curr = curr * 3LL + 1LL;
			}
			s.push(curr);
		}
		
		curr = collatz[curr];
		while (!s.empty()) {
			long long j = s.top();
			s.pop();
			if (j < 1000000LL)
				collatz[j] = curr;
			curr++;
		}
	}

	long long ans = 0, currMax = 0;
	for (long long i = 0; i < 1000000LL; i++) {
		if (collatz[i] > currMax) {
			currMax = collatz[i];
			ans = i;
		}
	}
	return ans;
}

int main() {
	cout << solve() << '\n';
}
