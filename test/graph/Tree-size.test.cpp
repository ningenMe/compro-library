#define PROBLEM "https://yukicoder.me/problems/no/872"

#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <stack>
#include <numeric>
#include <array>
using namespace std;
#include "../../lib/graph/Tree.cpp"

int main(void){
    int N;
	cin >> N;
	Tree<TreeOperator<long long>> tree(N);
	for(int i = 0; i < N-1; ++i){
		int u,v,w;
		cin >> u >> v >> w;
		u--,v--;
		tree.make_edge(u,v,w);
		tree.make_edge(v,u,w);
	}
	tree.make_size();
	long long ans = 0;
	for(int pa:tree.order) for(auto e:tree.child[pa]) ans += e.second*tree.size[e.first]*(N-tree.size[e.first])*2LL;
	cout << ans << endl;
	return 0;
}