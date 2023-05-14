#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
#include "../../lib/util/FastIO.cpp"
#include "../../lib/graph/UnionFindTree.cpp"


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N,Q; 
    read(N); read(Q);
    UnionFindTree uf(N);
    while(Q--){
        int q,a,b; 
        read(q);read(a);read(b);
        if(q) cout << uf.connected(a,b) << "\n";
        else uf.merge(a,b);
    }
}
