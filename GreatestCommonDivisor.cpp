#include <bits/stdc++.h>
using namespace std;

//Greatest Common Divisor
long long GCD(long long a, long long b) {
    return ((b == 0) ? a : GCD(b, a % b));
}

//Least Common Multiple
long long LCM(long long a, long long b) {
    return ((a*b == 0) ? 0 : (a / GCD(a, b)*b));
}

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) return x = 1, y = 0, a;
    long long d = extGCD(b, a%b, y, x);
    return y -= a / b * x, d;
}