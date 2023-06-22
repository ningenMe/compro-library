#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
#include <unordered_map>
using namespace std;
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/30-math/Prime.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    int T; read(T);
    while(T--) {
        long long x,y,m;
        read(x), read(y), read(m);
        long long k = Prime::discrete_logarithm(x,y,m);
        cout << k << "\n";
    }
    return 0;
}