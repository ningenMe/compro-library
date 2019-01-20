#include <bits/stdc++.h>
using namespace std;

//Eratosthenes O(N)
vector<bool> Eratosthenes(int N) {
    vector<bool> res(N + 1, true);
    res[0] = res[1%(N+1)] = false;
    for (int i = 1; i*i <= N; i++) if (res[i]) for (int j = 2 * i; j <= N; j += i) res[j] = false;
    return res;
}

//verify https://atcoder.jp/contests/abc084/tasks/abc084_d