#define PROBLEM "https://yukicoder.me/problems/no/1065"
#define ERROR 0.0001
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#include "../../lib/graph/Dijkstra.cpp"
#include "../../lib/70-geometory/Distance.cpp"

int main() {
    int N,M; cin >> N >> M;
    Dijkstra<double> dij(N,1e15);
    int s,t; cin >> s >> t; s--,t--;
    vector<double> p(N),q(N); 
    for(int i = 0; i < N; ++i) {
        cin >> p[i] >> q[i];
    }
    for(int i = 0; i < M; ++i) {
        int u,v; cin >> u >> v;
        u--,v--;
        double cost = Distance<double>::euclid(p[u],q[u],p[v],q[v]);
        dij.make_edge(u,v,cost);
        dij.make_edge(v,u,cost);
    }
    dij.solve(s);
    printf("%.10f\n",dij.get(t));    
    return 0;
}