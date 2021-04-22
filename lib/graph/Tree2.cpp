/*
 * @title Tree - 木
 * @docs md/graph/Tree.md
 */
template<class Operator> class TreeBuilder;
template<class Operator> class Tree {
	using TypeEdge = typename Operator::TypeEdge;
	size_t num;
	size_t ord;
	Graph<TypeEdge>& g;
	friend TreeBuilder<Operator>;
	/**
	 * constructor
	 * O(N) 
	 */
	Tree(Graph<TypeEdge>& graph):
		g(graph),
		num(graph.size()),
		depth(graph.size(),-1),
		order(graph.size()),
		edge_dist(graph.size()){
	}
	//for make_depth
	void dfs(int curr, int prev){
		for(const auto& e:g.edges[curr]){
			const int& next = e.first;
			if(next==prev) continue;
			depth[next] = depth[curr] + 1;
			edge_dist[next]  = Operator::func_edge_merge(edge_dist[curr],e.second);
			dfs(next,curr);
			order[ord++] = next;
		}
	}
	/**
	 * 寝付き木を作る
	 * O(N) you can use anytime
	 */
	void make_root(const int root) {
		depth[root] = 0;
		edge_dist[root] = Operator::unit_edge;
		ord = 0;
		dfs(root,-1);
		order[ord++] = root;
		reverse_copy(order.begin(),order.end(),back_inserter(reorder));
	}
	/**
	 * 子を作る
	 * O(N) after make_root
	 */
	void make_child(const int root = 0) {
		child.resize(num);
		for (size_t i = 0; i < num; ++i) for (auto& e : g.edges[i]) if (depth[i] < depth[e.first]) child[i].push_back(e);
	}
	/**
	 * 部分木のサイズを作る
	 * O(N) after make_child
	 */
	void make_subtree_size() {
		subtree_size.resize(num,1);
		for (size_t i:order) for (auto e : child[i]) subtree_size[i] += subtree_size[e.first];
	}
	/**
	 * 親を作る
	 * O(N) after make_root
	 */
	void make_parent() {
		parent.resize(num,make_pair(num,Operator::unit_edge));
		for (size_t i = 0; i < num; ++i) for (auto& e : g.edges[i]) if (depth[i] > depth[e.first]) parent[i] = e;
	}
	void make_ancestor() {
		ancestor.resize(num);
		for (size_t i = 0; i < num; ++i) ancestor[i][0] = (parent[i].first!=num?parent[i]:make_pair(i,Operator::unit_lca_edge));
		for (size_t j = 1; j < Operator::bit; ++j) {
			for (size_t i = 0; i < num; ++i) {
				size_t k = ancestor[i][j - 1].first;
				ancestor[i][j] = Operator::func_lca_edge_merge(ancestor[k][j - 1],ancestor[i][j - 1]);
			}
		}
	}
	pair<size_t,TypeEdge> lca_impl(size_t l, size_t r) {
		if (depth[l] < depth[r]) swap(l, r);
		int diff = depth[l] - depth[r];
		auto ancl = make_pair(l,Operator::unit_lca_edge);
		auto ancr = make_pair(r,Operator::unit_lca_edge);
		for (int j = 0; j < Operator::bit; ++j) {
			if (diff & (1 << j)) ancl = Operator::func_lca_edge_merge(ancestor[ancl.first][j],ancl);
		}
		if(ancl.first==ancr.first) return ancl;
		for (int j = Operator::bit - 1; 0 <= j; --j) {
			if(ancestor[ancl.first][j].first!=ancestor[ancr.first][j].first) {
				ancl = Operator::func_lca_edge_merge(ancestor[ancl.first][j],ancl);
				ancr = Operator::func_lca_edge_merge(ancestor[ancr.first][j],ancr);
			}
		}
		ancl = Operator::func_lca_edge_merge(ancestor[ancl.first][0],ancl);
		ancr = Operator::func_lca_edge_merge(ancestor[ancr.first][0],ancr);
		return Operator::func_lca_edge_merge(ancl,ancr);
	}
	pair<TypeEdge,vector<size_t>> diameter_impl() {
		Tree tree = Tree::builder(g).build();
		size_t root = 0;
		{
			tree.make_root(0);
		}
		root = max_element(tree.edge_dist.begin(),tree.edge_dist.end()) - tree.edge_dist.begin();
		{
			tree.make_root(root);
		}
		size_t leaf = max_element(tree.edge_dist.begin(),tree.edge_dist.end()) - tree.edge_dist.begin();
		TypeEdge sz = tree.edge_dist[leaf];
		vector<size_t> st;
		{
			tree.make_parent();
			while(leaf != root) {
				st.push_back(leaf);
				leaf = tree.parent[leaf].first;
			}
			st.push_back(root);
		}
		return make_pair(sz,st);
	}
public:
	vector<size_t> depth;
	vector<size_t> order;
	vector<size_t> reorder;
	vector<size_t> subtree_size;
	vector<pair<size_t,TypeEdge>> parent;
	vector<vector<pair<size_t,TypeEdge>>> child;
	vector<TypeEdge> edge_dist;
	vector<array<pair<size_t,TypeEdge>,Operator::bit>> ancestor;
 
	/**
	 * O(N) builder
	 */
	static TreeBuilder<Operator> builder(Graph<TypeEdge>& graph) { return TreeBuilder<Operator>(graph);}
	/**
	 * O(logN) after make_ancestor
	 * return {lca,lca_dist} l and r must be connected 
	 */
	pair<size_t,TypeEdge> lca(size_t l, size_t r) {return lca_impl(l,r);}
	/**
	 * O(N) anytime
	 * return {diameter size,diameter set} 
	 */
	pair<TypeEdge,vector<size_t>> diameter(void){return diameter_impl();}
};
 
template<class Operator> class TreeBuilder {
	bool is_root_made =false;
	bool is_child_made =false;
	bool is_parent_made=false;
public:
	using TypeEdge = typename Operator::TypeEdge;
	TreeBuilder(Graph<TypeEdge>& g):tree(g){}
	TreeBuilder& root(const int rt) { is_root_made=true; tree.make_root(rt); return *this;}
	TreeBuilder& child() { assert(is_root_made); is_child_made=true;  tree.make_child();  return *this;}
	TreeBuilder& parent() { assert(is_root_made); is_parent_made=true; tree.make_parent(); return *this;}
	TreeBuilder& subtree_size() { assert(is_child_made); tree.make_subtree_size(); return *this;}
	TreeBuilder& ancestor() { assert(is_parent_made); tree.make_ancestor(); return *this;}
	Tree<Operator>&& build() {return move(tree);}
private:
	Tree<Operator> tree;
}; 
template<class T> struct TreeOperator{
	using TypeEdge = T;
	inline static constexpr size_t bit = 20;
	inline static constexpr TypeEdge unit_edge = 0;
	inline static constexpr TypeEdge unit_lca_edge = 0;
	inline static constexpr TypeEdge func_edge_merge(const TypeEdge& parent,const TypeEdge& w){return parent+w;}
	inline static constexpr pair<size_t,TypeEdge> func_lca_edge_merge(const pair<size_t,TypeEdge>& l,const pair<size_t,TypeEdge>& r){return make_pair(l.first,l.second+r.second);}
};
//using Op = TreeOperator<int>;
//Tree<Op> tree = Tree<Op>::builder(g).build();