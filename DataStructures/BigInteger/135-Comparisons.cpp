//Big Integer: Comparisons
//Today we implement a way to compare two members of the BigInteger class, which will be useful when we implement division.
//Note that the comparison is slow, because it has to compare each string character by character in the worst case.
//Runtime: O(n)
#include "134-Multiplication.cpp"

bool BigInteger::operator==(BigInteger other) {
    return (
        numStr == other.numStr && 
        isNegative == other.isNegative
    );
}

bool BigInteger::operator<(BigInteger other) {
    if (!isNegative && !other.isNegative) {
        if (numStr.size() == other.numStr.size()) {
            return numStr < other.numStr;
        }
        else {
            return numStr.size() < other.numStr.size();
        }
    }
    else if (isNegative && other.isNegative) {
        if (numStr.size() == other.numStr.size()) {
            return numStr > other.numStr;
        }
        else {
            return numStr.size() > other.numStr.size();
        }
    }
    else if (isNegative) {
        return true;
    }
    else {
        return false;
    }
}

bool BigInteger::operator<=(BigInteger other) {
    return ((*this) < other) || ((*this) == other);
}

bool BigInteger::operator>(BigInteger other) {
    return !((*this) <= other);
}

bool BigInteger::operator>=(BigInteger other) {
    return !((*this) < other);
}