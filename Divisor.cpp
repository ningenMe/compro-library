#include <bits/stdc++.h>
using namespace std;

//divisor O(sqrt(N))
set<long long> Divisor(long long N) {
    set<long long> ret;
    for (long long i = 1; i*i <= N; ++i) {
        if (N%i == 0) {
            ret.insert(i);
            ret.insert(N / i);
        }
    }
    return ret;
}

//verify https://atcoder.jp/contests/abc112/tasks/abc112_d