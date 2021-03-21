#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

namespace tarche_num {
    class BigInteger {
        private:
            //MOD = 1e9
            const static int MOD = 1000000000;

            //The number is represented as a vector of base 1e9 digits
            //num[0] contains the LEAST significant digit
            std::vector<int> num;

            //Can either be 1 or -1. This is to make operations easier to implement
            int sign;

            void removeTrailingZeroes();
        public:
            BigInteger();
            BigInteger(int n);
            BigInteger(long long n);
            BigInteger(std::string s);

            bool operator==(const BigInteger &rhs) const;
            bool operator!=(const BigInteger &rhs) const;
            bool operator< (const BigInteger &rhs) const;
            bool operator> (const BigInteger &rhs) const;
            bool operator<=(const BigInteger &rhs) const;
            bool operator>=(const BigInteger &rhs) const;

            BigInteger operator-() const;
            BigInteger abs() const;

            void operator+=(const BigInteger &rhs);
            void operator-=(const BigInteger &rhs);
            void operator*=(const BigInteger &rhs);
            void operator/=(const BigInteger &rhs);
            void operator%=(const BigInteger &rhs);

            BigInteger operator++();
            BigInteger operator--();

            BigInteger operator++( int );
            BigInteger operator--( int );

            std::string toString() const;

            friend BigInteger operator+(BigInteger lhs, const BigInteger &rhs) {
                lhs += rhs;
                return lhs;
            }

            friend BigInteger operator-(BigInteger lhs, const BigInteger &rhs) {
                lhs -= rhs;
                return lhs;
            }

            friend BigInteger operator*(BigInteger lhs, const BigInteger &rhs) {
                lhs *= rhs;
                return lhs;
            }

            friend BigInteger operator/(BigInteger lhs, const BigInteger &rhs) {
                lhs /= rhs;
                return lhs;
            }

            friend BigInteger operator%(BigInteger lhs, const BigInteger &rhs) {
                lhs %= rhs;
                return lhs;
            }

            friend std::ostream &operator<<(std::ostream &output, const BigInteger &num) {
                output << num.toString();
                return output;
            }

            friend std::istream &operator>>(std::istream &input, BigInteger &num) {
                std::string s;
                input >> s;
                num = BigInteger(s);
                return input;
            }
    };

    BigInteger factorial(const BigInteger &n);

    BigInteger::BigInteger() {
        num = {0};
        sign = 1;
    }

    BigInteger::BigInteger(int n) {
        sign = (n < 0) ? -1 : 1;

        n = std::abs(n);
        if (n < MOD) 
            num = {n};
        else 
            num = {n % MOD, (int)n / MOD};
    }

    BigInteger::BigInteger(long long n) {
        sign = (n < 0) ? -1 : 1;
        n = std::abs(n);
        if (n == 0LL) {
            num = {0};
        }

        while (n > 0) {
            num.push_back((int)(n % (long long) MOD));
            n /= (long long) MOD;
        }
    }

    BigInteger::BigInteger(std::string s) {
        if (s[0] == '-') {
            sign = -1;
            s = s.substr(1);
        }
        else if (s[0] == '+') {
            sign = 1;
            s = s.substr(1);
        }
        else {
            sign = 1;
        }

        int n = (int)(s.size() / 9);
        int m = (int)(s.size() % 9);
        for (int i = n - 1; i >= 0; i--) {
            num.push_back(stoi(s.substr(i * 9 + m, 9)));
        }

        if (m != 0) num.push_back(stoi(s.substr(0, m)));
    }

    void BigInteger::removeTrailingZeroes() {
        while (num.size() > 1 && num.back() == 0) num.pop_back();
    }

    bool BigInteger::operator==(const BigInteger &rhs) const {
        return (sign == rhs.sign) && (num == rhs.num);
    }

    bool BigInteger::operator!=(const BigInteger &rhs) const {
        return !((*this) == rhs);
    }

    bool BigInteger::operator<(const BigInteger &rhs) const {
        if (sign != rhs.sign) return (sign < rhs.sign);
        if (sign == 1) {
            if (num.size() == rhs.num.size()) return num.back() < rhs.num.back();
            return (num.size() < rhs.num.size());
        }
        else {
            if (num.size() < rhs.num.size()) return false;
            return rhs.num.back() < num.back();
        }
    }

    bool BigInteger::operator>(const BigInteger &rhs) const {
        return !((*this) <= rhs);
    }

    bool BigInteger::operator<=(const BigInteger &rhs) const {
        return ((*this) < rhs) || ((*this) == rhs);
    }

    bool BigInteger::operator>=(const BigInteger &rhs) const {
        return !((*this) < rhs);
    }

    BigInteger BigInteger::operator-() const {
        BigInteger res = (*this);
        if ((*this) != BigInteger(0))
            res.sign = -sign;
        return res;
    }

    BigInteger BigInteger::abs() const {
        if ((*this) >= 0) return (*this);
        else return -(*this);
    }

    void BigInteger::operator+=(const BigInteger &rhs) {
        if (sign == rhs.sign) {
            int n = (int)num.size();
            int m = (int)rhs.num.size();
            if (n < m) num.resize(m, 0);

            int carry = 0;
            for (int i = 0; i < m; i++) {
                num[i] += rhs.num[i] + carry;
                carry = (int)(num[i] / MOD);
                num[i] %= MOD;
            }

            if (carry != 0) {
                if (n <= m) {
                    num.push_back(carry);
                }
                else {
                    num[m] += carry;
                }
            }
        }
        else if (sign == 1) {
            //lhs >= 0, rhs < 0 -> lhs - (-rhs)
            (*this) -= -rhs;
        }
        else {
            //lhs < 0, rhs >= 0 -> -(-lhs - rhs)
            (*this) = -((-(*this)) - rhs);
        }
    }

    void BigInteger::operator-=(const BigInteger &rhs) {
        if (sign == rhs.sign) {
            int m = (int)rhs.num.size();
            int carry = 0;
            if ((*this) >= rhs) {
                for (int i = 0; i < m; i++) {
                    num[i] -= rhs.num[i] + carry;
                    carry = (num[i] < 0);
                    num[i] = (num[i] % MOD + MOD) % MOD;
                }
            }
            else {
                sign = -sign;
                num.resize(m, 0);
                for (int i = 0; i < m; i++) {
                    num[i] = rhs.num[i] - num[i] - carry;
                    carry = (num[i] < 0);
                    num[i] = (num[i] % MOD + MOD) % MOD;
                }
            }
            if (carry != 0) num[m] -= carry;
            removeTrailingZeroes();
        }
        else if (sign == 1) {
            (*this) += -rhs;
        }
        else {
            (*this) = -((-(*this) + rhs));
        }
    }

    void BigInteger::operator*=(const BigInteger &rhs) {
        int n = (int)num.size();
        int m = (int)rhs.num.size();
        BigInteger res;
        res.num.resize(n + m, 0);

        for (int j = 0; j < m; j++) {
            long long carry = 0;
            for (int i = 0; i < n; i++) {
                long long prod = (long long)num[i] * (long long)rhs.num[j] + carry;
                carry = prod / (long long)MOD;
                prod = prod % (long long)MOD;
                res.num[i + j] += (int)prod;
                res.num[i + j] %= MOD;
            }
            res.num[n + j] += carry;
            res.num[n + j] %= MOD;
        }

        res.sign = sign * rhs.sign;
        res.removeTrailingZeroes();
        (*this) = res;
    }

    void BigInteger::operator/=(const BigInteger &rhs) {
        if (rhs == 0) throw std::runtime_error("Error: can't divide by zero");

        if (rhs < BigInteger(MOD) && rhs > BigInteger(-MOD)) {
            int n = (int)num.size();
            int div = rhs.num[0];
            long long carry = 0LL;
            for (int i = n - 1; i >= 0; i--) {
                long long k = (long long)num[i] + (long long)MOD * carry;
                carry = k % (long long)div;
                num[i] = (int)(k / (long long)div);
            }

            removeTrailingZeroes();
            sign *= rhs.sign;
        }
        else {
            int tempSign = sign * rhs.sign;
            sign = 1;
            BigInteger div = rhs.abs();
            BigInteger lower, upper(*this), mid;

            while (upper - lower > 1) {
                mid = (lower + upper) / 2;
                BigInteger res = mid * div;
                if (res > (*this)) {
                    upper = mid;
                }
                else {
                    lower = mid;
                }
            }

            (*this) = lower;
            sign = tempSign;
        }
    }

    void BigInteger::operator%=(const BigInteger &rhs) {
        if (rhs == 0) throw std::runtime_error("Error: can't divide by zero");

        BigInteger q = (*this) / rhs;
        int tempSign = sign;
        sign = 1;
        (*this) -= (q * rhs).abs();
        sign = tempSign;
    }

    BigInteger BigInteger::operator++() {
        (*this) += BigInteger(1);
        return (*this);
    }

    BigInteger BigInteger::operator--() {
        (*this) -= BigInteger(1);
        return (*this);
    }

    BigInteger BigInteger::operator++( int ) {
        BigInteger copy(*this);
        ++(*this);
        return copy;
    }

    BigInteger BigInteger::operator--( int ) { 
        BigInteger copy(*this);
        --(*this);
        return copy;
    }

    std::string BigInteger::toString() const {
        std::string res = "";
        if (sign == -1) res += '-';
        res += std::to_string(num.back());
        for (int i = (int)num.size() - 2; i >= 0; i--) {
            std::string s = std::to_string(num[i]);
            if (s.size() < 9) res += std::string(9 - s.size(), '0');
            res += s;
        }
        return res;
    }

    BigInteger factorial(const BigInteger &n) {
        BigInteger res(1);

        for (BigInteger i = 1; i <= n; i++) {
            res *= i;
        }

        return res;
    }
}
