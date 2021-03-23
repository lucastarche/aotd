//Fast Inverse Square Root
//Computes the result of 1/sqrt(n)
//A relic from a past, in which computing the square root was more expensive than it is today.
//Its most notable usage was in Quake, to allow normalizing vectors quicker.
//Runtime: O(1) but with a smaller constant
//Note: Nowadays there is an assembly instruction which does this even quicker.
//Note 2: Today's code is taken directly from Quake 3: Arena's source code. Comments included ;)
#include <bits/stdc++.h>

using namespace std;

float Q_rsqrt(float number) {
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = *(long*)&y;            // evil floating point bit level hacking
    i = 0x5f3759df - (i >> 1); // what the fuck?
    y = *(float*)&i;
    y = y * (threehalfs - (x2 * y * y)); // 1st iteration
                                         //	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

    return y;
}

int main() {
    float n;
    cin >> n;
    cout << Q_rsqrt(n);
}