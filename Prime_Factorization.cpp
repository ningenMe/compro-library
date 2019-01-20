#include <bits/stdc++.h>
using namespace std;

//Prime Factorization O(sqrt(N))
vector<long long> Prime_Factorization(long long N) {
    vector<long long> ret;
    if (N == 1) ret.push_back(1);
    for (long long i = 2,M = N; i*i <= M; ++i) {
        if (N%i == 0) ret.push_back(i);
        while (N%i == 0) N /= i;
    }
    if (N != 1) ret.push_back(N);
    return ret;
}

//verify https://atcoder.jp/contests/abc110/tasks/abc110_d