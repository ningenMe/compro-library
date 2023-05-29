#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"

#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
#include "../../lib/40-graph/PotentializedUnionFindTree.cpp"

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int N,Q; cin >> N >> Q;
    PotentializedUnionFindTree<int> uf(N);
    while(Q--) {
        int q; cin >> q;
        if(q) {
            int x,y; cin >> x >> y;
            if(uf.connected(y,x)) cout << uf.diff(x,y) << endl;
            else cout << "?" << endl;
        }
        else {
            int x,y,z; cin >> x >> y >> z;
            uf.merge(x,y,z);
        }
    }
}
