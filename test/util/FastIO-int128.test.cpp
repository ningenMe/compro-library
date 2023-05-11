#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb_128bit"

#include <iostream>
using namespace std;
#include "../../lib/util/FastIO.cpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; read(t);
    while(t--) {
        __int128 x,y; read(x);read(y);
        write(x+y);write('\n');
    }
    return 0;
}
