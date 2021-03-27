//PE 61: Cyclical Figurate Numbers
//Problem: Find the sum of the only ordered set of six cyclical 4-digit numbers for which each polynomial type (triangle, square, pentagon, hexagon, heptagon and octagon) is represented by a number in the set.
//Solution: First we will generate the figurate numbers in the range 1000-10000.
//After this, we can iterate through every possible set such that each member is a figurate number, and the set remains cyclic.
//Then it is just a matter of keeping track of which figures have already been used.
//Runtime: O(n^(7/2) * log n)
#include "EulerUtils.hpp"

array<set<long long>, 6> fig;

set<long long> generateFigurateNumbers(function<long long (long long)> f) {
    set<long long> curr;
    for (long long i = 0; f(i) < 10000; i++) {
        if (f(i) > 1000) curr.insert(f(i));
    }
    return curr;
}

bool isSomeFigure(long long n) {
    bool found = false;
    for (auto& a : fig) {
        if (a.count(n) > 0) {
            found = true;
        }
    }
    
    return found;
}

bool isFigurateSet(vector<long long> &curr, array<bool, 6> used) {
    int n = (int)curr.size();
    long long last = curr.back();

    if (n == 6) {
        if ((long long)(curr[0] / 100) != last % 100) return false;
        for (auto a : used) if (!a) return false;
        return true;
    }

    for (long long i = (last % 100) * 100; i < (last % 100 + 1) * 100; i++) {
        if (!isSomeFigure(i)) continue;
        for (int j = 0; j < 6; j++) {
            if (used[j]) continue;
            if (fig[j].count(i) > 0) {
                curr.push_back(i);
                used[j] = true;
                if (isFigurateSet(curr, used)) return true;
                curr.pop_back();
                used[j] = false;
            }
        }
    }

    return false;
}

long long solve() {
    vector<long long> buf;
    array<bool, 6> used;
    for (long long i = 1000; i < 10000; i++) {
        if (!isSomeFigure(i)) continue;
        for (int j = 0; j < 6; j++) {
            if (fig[j].count(i) > 0) {
                buf.push_back(i);
                used[j] = true;
                if (isFigurateSet(buf, used)) {
                    long long sum = 0;
                    for (auto a : buf) { 
                        sum += a;
                    }
                    return sum;
                }
                else buf.pop_back();
                used[j] = false;
            }
        }
    }

    return -1;
}

int main() {
    fig[0] = generateFigurateNumbers([](long long n) -> long long {return (n * (n + 1LL)) / 2LL;});
    fig[1] = generateFigurateNumbers([](long long n) -> long long {return (n * n);});
    fig[2] = generateFigurateNumbers([](long long n) -> long long {return (n * (3LL * n - 1LL)) / 2LL;});
    fig[3] = generateFigurateNumbers([](long long n) -> long long {return (n * (2LL * n - 1LL));});
    fig[4] = generateFigurateNumbers([](long long n) -> long long {return (n * (5LL * n - 3LL)) / 2LL;});
    fig[5] = generateFigurateNumbers([](long long n) -> long long {return (n * (3LL * n - 2LL));});

    cout << solve() << '\n';
}
