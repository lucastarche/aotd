//PE 19: Counting Sundays
//Problem: Count the amount of sundays that were the first day of the month 
//Solution: A simple bruteforce will suffice, since the numbers are small.
//There is a faster algorithm, using Zeller's Congruence, which will run in constant time.
//Runtime: O(n), where n is the amount of years.
#include "EulerUtils.hpp"

vector<int> days = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

bool isLeapYear(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}

long long solve() {
    //0: Sunday, 1: Monday, etc
    int currentDay = 1;
    //0: January, 1: February, etc
    int currentMonth = 0;
    int currentYear = 1900;

    while (currentMonth < 12) {
        if (currentMonth == 1 && isLeapYear(currentYear)) currentDay += 29;
        else currentDay += days[currentMonth];
        currentDay %= 7;
        currentMonth++;
    }

    long long ans = 0;
    for (currentYear = 1901; currentYear < 2001; currentYear++) {
        for (currentMonth = 0; currentMonth < 12; currentMonth++) {
            if (currentMonth == 1 && isLeapYear(currentYear)) currentDay++;
            else currentDay += days[currentMonth];
            currentDay %= 7;
            if (currentDay == 0) ans++;
        }
    }

    return ans;
}

int main() {
    cout << solve() << '\n';
}