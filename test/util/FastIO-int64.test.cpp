#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"

#include <iostream>
using namespace std;
#include "../../lib/util/FastIO.cpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; read(t);
    while(t--) {
        long long x,y; read(x);read(y);
        cout << x+y << "\n";
    }
    return 0;
}
