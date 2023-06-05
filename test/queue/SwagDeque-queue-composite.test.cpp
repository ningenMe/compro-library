#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include <vector>
#include <iostream>
#include <stack>
using namespace std;
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/00-util/ModInt.cpp"
#include "../../lib/15-queue/SwagDeque.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    int Q; read(Q);
    using modint = ModInt<MOD_998244353>;
    SwagDeque<NodeComposite<pair<modint,modint>>> swag;
    while(Q--) {
        int q; read(q);
        if(q==0) {
            int a,b; read(a); read(b);
            swag.push_back({a,b});
        }
        if(q==1) {
            swag.pop_front();
        }
        if(q==2) {
            int x; read(x);
            auto [a,b] = swag.fold();
            cout << a*x+b << "\n";
        }
    }

    return 0;
}