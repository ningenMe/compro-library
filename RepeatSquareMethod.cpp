#include <bits/stdc++.h>
using namespace std;

//Repeat Square Method x^n MOD O(log(N))
long long RSM(long long x, long long n, long long MOD) {
    long long y = 1;
    for (; n > 0; n >>= 1, (x *= x) %= MOD) if (n & 1) (y *= x) %= MOD;
    return y;
}