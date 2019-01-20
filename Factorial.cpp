#include <bits/stdc++.h>
using namespace std;

//Factorial
vector<long long> Factorial(long long N, long long mod) {
    vector<long long> res(N + 1, 1);
    for (long long i = 1; i <= N; ++i) res[i] = (res[i - 1] * i) % mod;
    return res;
}