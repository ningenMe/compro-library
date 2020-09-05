#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
#include "../../lib/graph/StronglyConnectedComponents.cpp"

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    string _; cin >> _ >> _;
    int N,M; cin >> N >> M;
    StronglyConnectedComponents scc(N,1);
    while(M--) {
        int u,v,t; cin >> u >> v >> t;
        int fu=1,fv=1;
        if(u<0) fu=0;
        if(v<0) fv=0;
        u = abs(u)-1;
        v = abs(v)-1;
        scc.make_condition(u,!fu,v,fv);
    }
    if(scc.solve()) {
        cout << "s SATISFIABLE\nv";
        for(int i = 0; i < N; ++i) {
            cout << " " << (2*scc.is_true(i)-1)*(i+1);
        }
        cout << " 0\n";
    }
    else {
        cout << "s UNSATISFIABLE\n";
    }

	return 0;
}
