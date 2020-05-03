#define PROBLEM "https://yukicoder.me/problems/no/1023"

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
#include "../../lib/graph/UnionFindTree.cpp"
#include "../../lib/graph/StronglyConnectedComponents.cpp"

int main(){
    int N,M; cin >> N >> M;
    vector<pair<int,int>> edge;
    vector<pair<int,int>> bedge;
    for(int i = 0; i < M; ++i) {
        int a,b; cin >> a >> b;
        a--,b--;
        int c; cin >> c;
        if(c==1){
            bedge.push_back({a,b});
        }
        else{
            edge.push_back({a,b});
        }
    }
    UnionFindTree uf(N);
    for(auto& e:bedge){
        int a = e.first,b = e.second;
        if(uf.same(a,b)){
            cout << "Yes" << endl;
            return 0;
        }
        uf.unite(a,b);
    }
    StronglyConnectedComponents scc(N);
    for(auto& e:edge){
        int a = e.first,b = e.second;
        if(uf.same(a,b)){
            cout << "Yes" << endl;
            return 0;
        }
        scc.makeEdge(uf.root(a),uf.root(b));
    }
    scc.solve();
    vector<int> cnt(N,0);
    for(int i = 0; i < N; ++i) cnt[scc[i]]++;
    for(int i = 0; i < N; ++i) if(cnt[i] > 1){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl; 
    return 0;
}
