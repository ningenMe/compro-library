#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
#include "../../lib/graph/UnionFindTree.cpp"

int main(){
    int N,Q; cin >> N >> Q;
    UnionFindTree uf(N);
    while(Q--){
        int q,a,b; cin >> q >> a >> b;
        if(q) cout << uf.connected(a,b) << endl;
        else uf.merge(a,b);
    }
}
