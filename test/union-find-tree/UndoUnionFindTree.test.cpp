#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include <vector>
#include <iostream>
#include <stack>
#include <array>
using namespace std;
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/41-union-find-tree/UndoUnionFindTree.cpp"


int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int N,Q; read(N), read(Q);
    vector<int> t(Q+1),k(Q+1),u(Q+1),v(Q+1);
    for(int i=1;i<=Q;++i) {
        read(t[i]), read(k[i]), read(u[i]), read(v[i]);
        k[i]++;
    }
    vector<vector<int>> edge(Q+1);
    vector<vector<int>> query(Q+1);
    vector<int> ans(Q+1,-1);
    UndoUnionFindTree uf(N);
    for(int i=1;i<=Q;++i) {
        if(t[i]==0) {
            edge[k[i]].push_back(i);
        }
        if(t[i]==1) {
            query[k[i]].push_back(i);
        }
    }
    auto dfs = [&](auto dfs, int pa) -> void {
        for(int i: query[pa]) {
            ans[i] = uf.connected(u[i],v[i]);
        }
        for(int i: edge[pa]) {
            uf.merge(u[i],v[i]);
            dfs(dfs,i);
            uf.undo();
        }
    };
    dfs(dfs,0);
    for(int i=1;i<=Q;++i) {
        if(ans[i]!=-1) cout << ans[i] << "\n"; 
    }

    return 0;
}