---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/graph/Tree-hld-vertex.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baa37bfd168b079b758c0db816f7295f">test/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/graph/Tree-hld-vertex.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-15 20:43:47+09:00


* see: <a href="https://yukicoder.me/problems/no/399">https://yukicoder.me/problems/no/399</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/graph/Tree.cpp.html">Tree</a>
* :heavy_check_mark: <a href="../../../library/lib/segment/LazySegmentTree.cpp.html">LazySegmentTree</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/399"

#include <vector>
#include <iostream>
#include <cassert>
#include <map>
#include <algorithm>
#include <stack>
#include <numeric>
#include <array>
using namespace std;
#include "../../lib/graph/Tree.cpp"
#include "../../lib/segment/LazySegmentTree.cpp"

int main(void){
	int N; cin >> N;
	Tree<TreeOperator<int>> tree(N);
	vector<pair<int,int>> edge(N-1);
	for(int i = 0; i < N-1; ++i) {
		int u,v; cin >> u >> v;
		u--,v--;
		tree.make_edge(u,v);
		tree.make_edge(v,u);
		edge[i] = {u,v};
	}
	tree.make_heavy_light_decomposition(0);
    LazySegmentTree<NodeSumRangeAdd<long long,long long>> seg(N);
    int Q; cin >> Q;
    long long ans = 0;
    for(int i = 0; i < Q; ++i) {
        int a,b; cin >> a >> b;
        a--,b--;
        auto path = tree.path(a,b);
        for(auto p:path){
            int l = p.first,r = p.second;
            seg.update(l,r+1,1);
            ans += seg.get(l,r+1);
        }
    }
    cout << ans << endl;
    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/Tree-hld-vertex.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/399"

#include <vector>
#include <iostream>
#include <cassert>
#include <map>
#include <algorithm>
#include <stack>
#include <numeric>
#include <array>
using namespace std;
#line 1 "lib/graph/Tree.cpp"
/*
 * @title Tree
 * @docs md/graph/Tree.md
 */
template<class Operator> class Tree {
	using TypeDist = typename Operator::TypeDist;
	size_t num;
	size_t ord;
	enum METHODS{
		MAKE_DEPTH,
		MAKE_CHILD,
		MAKE_PARENT,
		MAKE_SIZE,
		MAKE_SUBTREE,
		MAKE_ANCESTOR,
		MAKE_EOULERTOUR,
		MAKE_HEAVY_LIGHT_DECOMPOSITION,
		METHODS_SIZE,
	};
	array<int,METHODS_SIZE> executed_flag;
public:
	vector<vector<pair<size_t,TypeDist>>> edge;
	vector<size_t> depth;
	vector<size_t> order;
	vector<size_t> reorder;
	vector<TypeDist> dist;
	vector<pair<size_t,TypeDist>> parent;
	vector<vector<pair<size_t,TypeDist>>> child;
	vector<array<pair<size_t,TypeDist>,Operator::bit>> ancestor;
	vector<size_t> size;
	vector<vector<size_t>> subtree;
	vector<size_t> head;
	vector<size_t> hldorder;
	vector<size_t> eulertour;
	vector<pair<size_t,size_t>> eulertour_range;
	Tree(const int num):num(num),edge(num),depth(num,-1),order(num),dist(num),executed_flag(){}
	//O(1) anytime
	void make_edge(const int& from, const int& to, const TypeDist w = 1) {
		edge[from].push_back({to,w});
	}
	//O(N) anytime
	void make_depth(const int root) {
		if(executed_flag[MAKE_DEPTH]++) return;
		depth[root] = 0;
		dist[root] = Operator::unit_dist;
		ord = 0;
		dfs(root,-1);
		order[ord++] = root;
		reverse_copy(order.begin(),order.end(),back_inserter(reorder));
	}
	//O(N) anytime for forest
	void make_depth(void) {
		if(executed_flag[MAKE_DEPTH]++) return;
		ord = 0;
		for(size_t root = 0; root < num; ++root) {
			if(depth[root] != -1) continue;
			depth[root] = 0;
			dist[root] = Operator::unit_dist;
			dfs(root,-1);
			order[ord++] = root;
		}
		reverse_copy(order.begin(),order.end(),back_inserter(reorder));
	}
	//for make_depth
	void dfs(int curr, int prev){
		for(auto& e:edge[curr]){
			int next = e.first;
			if(next==prev) continue;
			depth[next] = depth[curr] + 1;
			dist[next]  = Operator::func_dist(dist[curr],e.second);
			dfs(next,curr);
			order[ord++] = next;
		}
	}
	//for make_eulertour
	void dfs(int from){
		eulertour.push_back(from);
		for(auto& e:child[from]){
			int to = e.first;            
			dfs(to);        
			eulertour.push_back(from);
		}
	}
	//O(N) after make_depth
	void make_parent(const int root = 0) {
		if(executed_flag[MAKE_PARENT]++) return;
		if(!executed_flag[MAKE_DEPTH]) make_depth(root);
		parent.resize(num,make_pair(num,Operator::unit_dist));
		for (size_t i = 0; i < num; ++i) for (auto& e : edge[i]) if (depth[i] > depth[e.first]) parent[i] = e;
	}
	//O(N) after make_depth
	void make_child(const int root = 0) {
		if(executed_flag[MAKE_CHILD]++) return;
		if(!executed_flag[MAKE_DEPTH]) make_depth(root);
		child.resize(num);
		for (size_t i = 0; i < num; ++i) for (auto& e : edge[i]) if (depth[i] < depth[e.first]) child[i].push_back(e);
	}
	//O(NlogN) after make_parent
	void make_ancestor(const int root = 0) {
		if(executed_flag[MAKE_ANCESTOR]++) return;
		if(!executed_flag[MAKE_PARENT]) make_parent(root);
		ancestor.resize(num);
		for (size_t i = 0; i < num; ++i) ancestor[i][0] = (parent[i].first!=num?parent[i]:make_pair(i,Operator::unit_lca));
		for (size_t j = 1; j < Operator::bit; ++j) {
			for (size_t i = 0; i < num; ++i) {
				size_t k = ancestor[i][j - 1].first;
				ancestor[i][j] = Operator::func_lca(ancestor[k][j - 1],ancestor[i][j - 1]);
			}
		}
	}
	//O(logN) after make_ancestor
	//return {lca,lca_dist} l and r must be connected
	pair<size_t,TypeDist> lca(size_t l, size_t r) {
		assert(executed_flag[MAKE_ANCESTOR]);
		if (depth[l] < depth[r]) swap(l, r);
		int diff = depth[l] - depth[r];
		auto ancl = make_pair(l,Operator::unit_lca);
		auto ancr = make_pair(r,Operator::unit_lca);
		for (int j = 0; j < Operator::bit; ++j) {
			if (diff & (1 << j)) {
				ancl = Operator::func_lca(ancestor[ancl.first][j],ancl);
			}
		}
		if(ancl.first==ancr.first) return ancl;
		for (int j = Operator::bit - 1; 0 <= j; --j) {
			if(ancestor[ancl.first][j].first!=ancestor[ancr.first][j].first) {
				ancl = Operator::func_lca(ancestor[ancl.first][j],ancl);
				ancr = Operator::func_lca(ancestor[ancr.first][j],ancr);
			}
		}
		ancl = Operator::func_lca(ancestor[ancl.first][0],ancl);
		ancr = Operator::func_lca(ancestor[ancr.first][0],ancr);
		return Operator::func_lca(ancl,ancr);
	}
	//O(N) anytime
	int diameter(void){
		make_depth(0);
		int tmp = max_element(depth.begin(), depth.end()) - depth.begin();
		make_depth(tmp);
		return *max_element(depth.begin(), depth.end());
	}
	//O(N^2) after make_depth
	void make_subtree(const int root = 0) {
		if(executed_flag[MAKE_SUBTREE]++) return;
		if(!executed_flag[MAKE_DEPTH]) make_depth(root);
		subtree.resize(num);
		for (size_t i = 0; i < num; ++i) subtree[i].push_back(i);
		for (size_t i = 0; i < num; ++i) for (auto& e : edge[order[i]]) if (depth[order[i]] < depth[e.first]) for(auto k: subtree[e.first]) subtree[order[i]].push_back(k);
	}
	//O(N) after make_child
	void make_size(const int root = 0) {
		if(executed_flag[MAKE_SIZE]++) return;
		if(!executed_flag[MAKE_CHILD]) make_child(root);
		size.resize(num,1);
		for (size_t i:order) for (auto e : child[i]) size[i] += size[e.first];
	}
	//(N) after make_depth and make_child
	template<class TypeReroot> vector<TypeReroot> rerooting(vector<TypeReroot> rerootdp,vector<TypeReroot> rerootparent) {
		assert(executed_flag[MAKE_CHILD]);
		for(size_t pa:order) for(auto& e:child[pa]) rerootdp[pa] = Operator::func_reroot(rerootdp[pa],rerootdp[e.first]);
		for(size_t pa:reorder) {
			if(depth[pa]) rerootdp[pa] = Operator::func_reroot(rerootdp[pa],rerootparent[pa]);
			size_t m = child[pa].size();
			for(int j = 0; j < m && depth[pa]; ++j){
				size_t ch = child[pa][j].first;
				rerootparent[ch] = Operator::func_reroot(rerootparent[ch],rerootparent[pa]);
			}
			if(m <= 1) continue;
			vector<TypeReroot> l(m),r(m);
			for(int j = 0; j < m; ++j) {
				size_t ch = child[pa][j].first;
				l[j] = rerootdp[ch];
				r[j] = rerootdp[ch];
			}
			for(int j = 1; j+1 < m; ++j) l[j] = Operator::func_reroot_merge(l[j],l[j-1]);
			for(int j = m-2; 0 <=j; --j) r[j] = Operator::func_reroot_merge(r[j],r[j+1]);
			size_t chl = child[pa].front().first;
			size_t chr = child[pa].back().first;
			rerootparent[chl] = Operator::func_reroot(rerootparent[chl],r[1]);
			rerootparent[chr] = Operator::func_reroot(rerootparent[chr],l[m-2]);
			for(int j = 1; j+1 < m; ++j) {
				size_t ch = child[pa][j].first;
				rerootparent[ch] = Operator::func_reroot(rerootparent[ch],l[j-1]);
				rerootparent[ch] = Operator::func_reroot(rerootparent[ch],r[j+1]);
			}
		}
		return rerootdp;
	}
	//O(N) after make_depth,make_parent,make_child
	void make_heavy_light_decomposition(const int root = 0){
		if(executed_flag[MAKE_HEAVY_LIGHT_DECOMPOSITION]++) return;
		if(!executed_flag[MAKE_SIZE]) make_size(root);
		if(!executed_flag[MAKE_PARENT]) make_parent(root);
		head.resize(num);
		hldorder.resize(num);
		iota(head.begin(),head.end(),0);
		for(size_t& pa:reorder) {
			pair<size_t,size_t> maxi = {0,num};
			for(auto& e:child[pa]) maxi = max(maxi,{size[e.first],e.first});
			if(maxi.first) head[maxi.second] = head[pa];
		}
		stack<size_t> st_head,st_sub;
		size_t cnt = 0;
		for(size_t& root:reorder){
			if(depth[root]) continue;
			st_head.push(root);
			while(st_head.size()){
				size_t h = st_head.top();
				st_head.pop();
				st_sub.push(h);
				while (st_sub.size()){
					size_t pa = st_sub.top();
					st_sub.pop();
					hldorder[pa] = cnt++;
					for(auto& e:child[pa]) {
						if(head[e.first]==head[pa]) st_sub.push(e.first);
						else st_head.push(e.first);
					}
				}				
			}
		}
	}
	//after hld type 0: vertex, 1: edge
	vector<pair<size_t,size_t>> path(size_t u,size_t v,int type = 0) {
		assert(executed_flag[MAKE_HEAVY_LIGHT_DECOMPOSITION]);
		vector<pair<size_t,size_t>> path;
		while(1){
			if(hldorder[u]>hldorder[v]) swap(u,v);
			if(head[u]!=head[v]) {
				path.push_back({hldorder[head[v]],hldorder[v]});
				v=parent[head[v]].first;
			}
			else {
				path.push_back({hldorder[u],hldorder[v]});
				break;
			}
		}
		reverse(path.begin(),path.end());
		if(type) path.front().first++;
		return path;
	}
	size_t hld_lca(size_t u,size_t v){
		assert(executed_flag[MAKE_HEAVY_LIGHT_DECOMPOSITION]);
		while(1){
			if(hldorder[u]>hldorder[v]) swap(u,v);
			if(head[u]==head[v]) return u;
			v=parent[head[v]].first;
		}
	}
	//O(N) after make_child and make_parent
	void make_eulertour(const int root = 0){
		if(executed_flag[MAKE_EOULERTOUR]++) return;
		if(!executed_flag[MAKE_CHILD]) make_child(root);
		if(!executed_flag[MAKE_PARENT]) make_parent(root);
		dfs(reorder.front());
		eulertour_range.resize(num);
		for(int i = 0; i < eulertour.size(); ++i) eulertour_range[eulertour[i]].second = i;
		for(int i = eulertour.size()-1; 0 <= i; --i) eulertour_range[eulertour[i]].first = i;
	}
};
//depth,dist
//https://atcoder.jp/contests/abc126/tasks/abc126_d
//child
//https://atcoder.jp/contests/abc133/tasks/abc133_e
//lca
//https://atcoder.jp/contests/abc014/tasks/abc014_4
//weighted lca
//https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h
//https://atcoder.jp/contests/cf16-tournament-round1-open/tasks/asaporo_c
//diameter
//https://atcoder.jp/contests/agc033/tasks/agc033_c
//subtree
//https://atcoder.jp/contests/code-thanks-festival-2018/tasks/code_thanks_festival_2018_f
//rerooting
//https://yukicoder.me/problems/no/922
//size
//https://yukicoder.me/problems/no/872
//eulerTour
//https://yukicoder.me/problems/no/900
//hld
//https://yukicoder.me/problems/no/399
//https://yukicoder.me/problems/no/650
template<class T> struct TreeOperator{
	using TypeDist = T;
	inline static constexpr size_t bit = 20;
	inline static constexpr TypeDist unit_dist = 0;
	inline static constexpr TypeDist unit_lca = 0;
	inline static constexpr TypeDist func_dist(const TypeDist& parent,const TypeDist& w){return parent+w;}
	inline static constexpr pair<size_t,TypeDist> func_lca(const pair<size_t,TypeDist>& l,const pair<size_t,TypeDist>& r){return make_pair(l.first,l.second+r.second);}
	template<class TypeReroot> inline static constexpr TypeReroot func_reroot(const TypeReroot& l,const TypeReroot& r) {
		return {l.first+r.first+r.second,l.second+r.second};
	}
	template<class TypeReroot> inline static constexpr TypeReroot func_reroot_merge(const TypeReroot& l,const TypeReroot& r) {
		return {l.first+r.first,l.second+r.second};
	}
};
//Tree<TreeOperator<ll>> tree(N);
#line 1 "lib/segment/LazySegmentTree.cpp"
/*
 * @title LazySegmentTree
 */
template<class Operator> class LazySegmentTree {
	using TypeNode = typename Operator::TypeNode;          
	using TypeLazy = typename Operator::TypeLazy;
	size_t num;      
	size_t length;                                   
	size_t height;                                   
	vector<TypeNode> node;                           
	vector<TypeLazy> lazy;                           
	vector<pair<size_t,size_t>> range;

	void propagate(int k) {
		if(lazy[k] == Operator::unit_lazy) return;
		node[k] = Operator::func_merge(node[k],lazy[k],range[k].second-range[k].first);
		if(k < length) lazy[2*k+0] = Operator::func_lazy(lazy[2*k+0],lazy[k]);
		if(k < length) lazy[2*k+1] = Operator::func_lazy(lazy[2*k+1],lazy[k]);
		lazy[k] = Operator::unit_lazy;
	}
public:

	//unitで初期化
	LazySegmentTree(const size_t num) : num(num) {
		for (length = 1,height = 0; length <= num; length *= 2, height++);
		node.resize(2 * length, Operator::unit_node);
		lazy.resize(2 * length, Operator::unit_lazy);
		for (int i = 0; i < num; ++i) node[i + length] = Operator::unit_node;
		for (int i = length - 1; i >= 0; --i) node[i] = Operator::func_node(node[(i<<1)+0],node[(i<<1)+1]);
		range.resize(2 * length);
		for (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);
		for (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);
	}

	// //同じinitで初期化
	LazySegmentTree(const size_t num, const TypeNode init) : num(num) {
		for (length = 1,height = 0; length <= num; length *= 2, height++);
		node.resize(2 * length, Operator::unit_node);
		lazy.resize(2 * length, Operator::unit_lazy);
		for (int i = 0; i < num; ++i) node[i + length] = init;
		for (int i = length - 1; i >= 0; --i) node[i] = Operator::func_node(node[(i<<1)+0],node[(i<<1)+1]);
		range.resize(2 * length);
		for (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);
		for (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);
	}

	//vectorで初期化
	LazySegmentTree(const vector<TypeNode>& vec) : num(vec.size()) {
		for (length = 1,height = 0; length <= vec.size(); length *= 2, height++);
		node.resize(2 * length, Operator::unit_node);
		lazy.resize(2 * length, Operator::unit_lazy);
		for (int i = 0; i < vec.size(); ++i) node[i + length] = vec[i];
		for (int i = length - 1; i >= 0; --i) node[i] = Operator::func_node(node[(i<<1)+0],node[(i<<1)+1]);
		range.resize(2 * length);
		for (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);
		for (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);
	}

	//update [a,b)
	void update(int a, int b, TypeLazy x) {
		int l = a + length, r = b + length - 1;
		for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
		for(r++; l < r; l >>=1, r >>=1) {
			if(l&1) lazy[l] = Operator::func_lazy(lazy[l],x), propagate(l),l++;
			if(r&1) --r,lazy[r] = Operator::func_lazy(lazy[r],x), propagate(r);
		}
		l = a + length, r = b + length - 1;
		while ((l>>=1),(r>>=1),l) {
			if(lazy[l] == Operator::unit_lazy) node[l] = Operator::func_node(Operator::func_merge(node[(l<<1)+0],lazy[(l<<1)+0],range[(l<<1)+0].second-range[(l<<1)+0].first),Operator::func_merge(node[(l<<1)+1],lazy[(l<<1)+1],range[(l<<1)+1].second-range[(l<<1)+1].first));
			if(lazy[r] == Operator::unit_lazy) node[r] = Operator::func_node(Operator::func_merge(node[(r<<1)+0],lazy[(r<<1)+0],range[(r<<1)+0].second-range[(r<<1)+0].first),Operator::func_merge(node[(r<<1)+1],lazy[(r<<1)+1],range[(r<<1)+1].second-range[(r<<1)+1].first));
		}
	}

	//get [a,b)
	TypeNode get(int a, int b) {
		int l = a + length, r = b + length - 1;
		for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
		TypeNode vl = Operator::unit_node, vr = Operator::unit_node;
		for(r++; l < r; l >>=1, r >>=1) {
			if(l&1) vl = Operator::func_node(vl,Operator::func_merge(node[l],lazy[l],range[l].second-range[l].first)),l++;
			if(r&1) r--,vr = Operator::func_node(Operator::func_merge(node[r],lazy[r],range[r].second-range[r].first),vr);
		}
		return Operator::func_node(vl,vr);
	}

	//return [0,length]
	int prefix_binary_search(TypeNode var) {
		int l = length, r = 2*length - 1;
		for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
		if(!Operator::func_check(node[1],var)) return num;
		TypeNode ret = Operator::unit_node;
		size_t idx = 2;
		for(; idx < 2*length; idx<<=1){
			if(!Operator::func_check(Operator::func_node(ret,Operator::func_merge(node[idx],lazy[idx],range[idx].second-range[idx].first)),var)) {
				ret = Operator::func_node(ret,Operator::func_merge(node[idx],lazy[idx],range[idx].second-range[idx].first));
				idx++;
			}
		}
		return min((idx>>1) - length,num);
	}

	//range[l,r) return [l,r]
	int binary_search(size_t l, size_t r, TypeNode var) {
		if (l < 0 || length <= l || r < 0 || length < r) return -1;
		for (int i = height; 0 < i; --i) propagate((l+length) >> i), propagate((r+length-1) >> i);
		TypeNode ret = Operator::unit_node;
		size_t off = l;
		for(size_t idx = l+length; idx < 2*length && off < r; ){
			if(range[idx].second<=r && !Operator::func_check(Operator::func_node(ret,Operator::func_merge(node[idx],lazy[idx],range[idx].second-range[idx].first)),var)) {
				ret = Operator::func_node(ret,Operator::func_merge(node[idx],lazy[idx],range[idx].second-range[idx].first));
				off = range[idx++].second;
				if(!(idx&1)) idx >>= 1;			
			}
			else{
				idx <<=1;
			}
		}
		return off;
	}

	void print(){
		// cout << "node" << endl;
		// for(int i = 1,j = 1; i < 2*length; ++i) {
		// 	cout << node[i] << " ";
		// 	if(i==((1<<j)-1) && ++j) cout << endl;
		// }
		// cout << "lazy" << endl;
		// for(int i = 1,j = 1; i < 2*length; ++i) {
		// 	cout << lazy[i] << " ";
		// 	if(i==((1<<j)-1) && ++j) cout << endl;
		// }
		cout << "vector" << endl;
		cout << "{ " << get(0,1);
		for(int i = 1; i < length; ++i) cout << ", " << get(i,i+1);
		cout << " }" << endl;
	}
};

//node:最小　lazy:加算
template<class T, class U> struct NodeMinRangeAdd {
	using TypeNode = T;
	using TypeLazy = U;
	inline static constexpr TypeNode unit_node = 1234567890;
	inline static constexpr TypeLazy unit_lazy = 0;
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return min(l,r);}
	inline static constexpr TypeLazy func_lazy(TypeLazy l,TypeLazy r){return l+r;}
	inline static constexpr TypeNode func_merge(TypeNode l,TypeLazy r,int len){return l+r;}
	// LazySegmentTree<NodeMinRangeAdd<ll,ll>> Seg(N,0);
};

//node:総和　lazy:更新
template<class T, class U> struct NodeSumRangeUpdate {
	using TypeNode = T;
	using TypeLazy = U;
	inline static constexpr TypeNode unit_node = 0;
	inline static constexpr TypeLazy unit_lazy = -2000;
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return l+r;}
	inline static constexpr TypeLazy func_lazy(TypeLazy l,TypeLazy r){return r;}
	inline static constexpr TypeNode func_merge(TypeNode l,TypeLazy r,int len){return r!=-2000?r*len:l;}
	inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}
	// LazySegmentTree<NodeSumRangeUpdate<ll,ll>> Seg(N,0);
};

//node:総和　lazy:更新
template<class T, class U> struct NodeSumRangeAdd {
	using TypeNode = T;
	using TypeLazy = U;
	inline static constexpr TypeNode unit_node = 0;
	inline static constexpr TypeLazy unit_lazy = 0;
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return l+r;}
	inline static constexpr TypeLazy func_lazy(TypeLazy l,TypeLazy r){return l+r;}
	inline static constexpr TypeNode func_merge(TypeNode l,TypeLazy r,int len){return l+r*len;}
	inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}
	// LazySegmentTree<NodeSumRangeUpdate<ll,ll>> Seg(N,0);
};
#line 14 "test/graph/Tree-hld-vertex.test.cpp"

int main(void){
	int N; cin >> N;
	Tree<TreeOperator<int>> tree(N);
	vector<pair<int,int>> edge(N-1);
	for(int i = 0; i < N-1; ++i) {
		int u,v; cin >> u >> v;
		u--,v--;
		tree.make_edge(u,v);
		tree.make_edge(v,u);
		edge[i] = {u,v};
	}
	tree.make_heavy_light_decomposition(0);
    LazySegmentTree<NodeSumRangeAdd<long long,long long>> seg(N);
    int Q; cin >> Q;
    long long ans = 0;
    for(int i = 0; i < Q; ++i) {
        int a,b; cin >> a >> b;
        a--,b--;
        auto path = tree.path(a,b);
        for(auto p:path){
            int l = p.first,r = p.second;
            seg.update(l,r+1,1);
            ans += seg.get(l,r+1);
        }
    }
    cout << ans << endl;
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

