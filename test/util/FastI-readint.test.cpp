#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"

#include <iostream>
using namespace std;
#include "../../lib/util/FastI.cpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; FastI::read(t);
    while(t--) {
        long long x,y; FastI::read(x);FastI::read(y);
        cout << x + y << "\n";
    }
    return 0;
}
