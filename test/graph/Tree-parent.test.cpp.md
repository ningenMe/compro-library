---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/Graph.cpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: lib/graph/Tree2.cpp
    title: "Tree - \u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1308
    links:
    - https://yukicoder.me/problems/no/1308
  bundledCode: "#line 1 \"test/graph/Tree-parent.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/1308\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <algorithm>\n\
    #include <stack>\n#include <numeric>\n#include <array>\nusing namespace std;\n\
    #line 1 \"lib/graph/Graph.cpp\"\n/*\n * @title Graph\n * @docs md/graph/Graph.md\n\
    \ */\ntemplate<class T> class Graph{\nprivate:\n    const size_t N,H,W;\npublic:\n\
    \    vector<vector<pair<size_t,T>>> edges;\n    Graph(const size_t N):H(-1),W(-1),N(N),\
    \ edges(N) {}\n    Graph(const size_t H, const size_t W):H(H),W(W),N(H*W), edges(H*W)\
    \ {}\n    inline void make_edge(size_t from, size_t to, T w) {\n        edges[from].emplace_back(to,w);\n\
    \    }\n    //{from_y,from_x} -> {to_y,to_x} \n    inline void make_edge(pair<size_t,size_t>\
    \ from, pair<size_t,size_t> to, T w) {\n        make_edge(from.first*W+from.second,to.first*W+to.second,w);\n\
    \    }\n    inline void make_bidirectional_edge(size_t from, size_t to, T w) {\n\
    \        make_edge(from,to,w);\n        make_edge(to,from,w);\n    }\n    inline\
    \ void make_bidirectional_edge(pair<size_t,size_t> from, pair<size_t,size_t> to,\
    \ T w) {\n        make_edge(from.first*W+from.second,to.first*W+to.second,w);\n\
    \        make_edge(to.first*W+to.second,from.first*W+from.second,w);\n    }\n\
    \    inline size_t size(){return N;}\n    inline size_t idx(pair<size_t,size_t>\
    \ yx){return yx.first*W+yx.second;}\n};\n#line 1 \"lib/graph/Tree2.cpp\"\n/*\n\
    \ * @title Tree - \u6728\n * @docs md/graph/Tree.md\n */\ntemplate<class Operator>\
    \ class TreeBuilder;\ntemplate<class Operator> class Tree {\n\tusing TypeEdge\
    \ = typename Operator::TypeEdge;\n\tsize_t num;\n\tsize_t ord;\n\tGraph<TypeEdge>&\
    \ g;\n\tfriend TreeBuilder<Operator>;\n\t/**\n\t * constructor\n\t * O(N) \n\t\
    \ */\n\tTree(Graph<TypeEdge>& graph):\n\t\tg(graph),\n\t\tnum(graph.size()),\n\
    \t\tdepth(graph.size(),-1),\n\t\torder(graph.size()),\n\t\tedge_dist(graph.size()){\n\
    \t}\n\t//for make_depth\n\tvoid dfs(int curr, int prev){\n\t\tfor(const auto&\
    \ e:g.edges[curr]){\n\t\t\tconst int& next = e.first;\n\t\t\tif(next==prev) continue;\n\
    \t\t\tdepth[next] = depth[curr] + 1;\n\t\t\tedge_dist[next]  = Operator::func_edge_merge(edge_dist[curr],e.second);\n\
    \t\t\tdfs(next,curr);\n\t\t\torder[ord++] = next;\n\t\t}\n\t}\n\t/**\n\t * \u6839\
    \u4ED8\u304D\u6728\u3092\u4F5C\u308B\n\t * O(N) you can use anytime\n\t */\n\t\
    void make_root(const int root) {\n\t\tdepth[root] = 0;\n\t\tedge_dist[root] =\
    \ Operator::unit_edge;\n\t\tord = 0;\n\t\tdfs(root,-1);\n\t\torder[ord++] = root;\n\
    \t\treverse_copy(order.begin(),order.end(),back_inserter(reorder));\n\t}\n\t/**\n\
    \t * \u6839\u4ED8\u304D\u6728\u3092\u4F5C\u308B\n\t * O(N) you can use anytime\n\
    \t */\n\tvoid make_root() {\n        ord = 0;\n        for(int i=0;i<num;++i)\
    \ {\n            if(depth[i]!=-1) continue;\n            depth[i] = 0;\n     \
    \       edge_dist[i] = Operator::unit_edge;\n            dfs(i,-1);\n        \
    \    order[ord++] = i;\n        }\n\t\treverse_copy(order.begin(),order.end(),back_inserter(reorder));\n\
    \t}\n\t/**\n\t * \u5B50\u3092\u4F5C\u308B\n\t * O(N) after make_root\n\t */\n\t\
    void make_child(const int root = 0) {\n\t\tchild.resize(num);\n\t\tfor (size_t\
    \ i = 0; i < num; ++i) for (auto& e : g.edges[i]) if (depth[i] < depth[e.first])\
    \ child[i].push_back(e);\n\t}\n\t/**\n\t * \u90E8\u5206\u6728\u306E\u30B5\u30A4\
    \u30BA\u3092\u4F5C\u308B\n\t * O(N) after make_child\n\t */\n\tvoid make_subtree_size()\
    \ {\n\t\tsubtree_size.resize(num,1);\n\t\tfor (size_t i:order) for (auto e : child[i])\
    \ subtree_size[i] += subtree_size[e.first];\n\t}\n\t/**\n\t * \u89AA\u3092\u4F5C\
    \u308B\n\t * O(N) after make_root\n\t */\n\tvoid make_parent() {\n\t\tparent.resize(num,make_pair(num,Operator::unit_edge));\n\
    \t\tfor (size_t i = 0; i < num; ++i) for (auto& e : g.edges[i]) if (depth[i] >\
    \ depth[e.first]) parent[i] = e;\n\t}\n\tvoid make_ancestor() {\n\t\tancestor.resize(num);\n\
    \t\tfor (size_t i = 0; i < num; ++i) ancestor[i][0] = (parent[i].first!=num?parent[i]:make_pair(i,Operator::unit_lca_edge));\n\
    \t\tfor (size_t j = 1; j < Operator::bit; ++j) {\n\t\t\tfor (size_t i = 0; i <\
    \ num; ++i) {\n\t\t\t\tsize_t k = ancestor[i][j - 1].first;\n\t\t\t\tancestor[i][j]\
    \ = Operator::func_lca_edge_merge(ancestor[k][j - 1],ancestor[i][j - 1]);\n\t\t\
    \t}\n\t\t}\n\t}\n\tpair<size_t,TypeEdge> lca_impl(size_t l, size_t r) {\n\t\t\
    if (depth[l] < depth[r]) swap(l, r);\n\t\tint diff = depth[l] - depth[r];\n\t\t\
    auto ancl = make_pair(l,Operator::unit_lca_edge);\n\t\tauto ancr = make_pair(r,Operator::unit_lca_edge);\n\
    \t\tfor (int j = 0; j < Operator::bit; ++j) {\n\t\t\tif (diff & (1 << j)) ancl\
    \ = Operator::func_lca_edge_merge(ancestor[ancl.first][j],ancl);\n\t\t}\n\t\t\
    if(ancl.first==ancr.first) return ancl;\n\t\tfor (int j = Operator::bit - 1; 0\
    \ <= j; --j) {\n\t\t\tif(ancestor[ancl.first][j].first!=ancestor[ancr.first][j].first)\
    \ {\n\t\t\t\tancl = Operator::func_lca_edge_merge(ancestor[ancl.first][j],ancl);\n\
    \t\t\t\tancr = Operator::func_lca_edge_merge(ancestor[ancr.first][j],ancr);\n\t\
    \t\t}\n\t\t}\n\t\tancl = Operator::func_lca_edge_merge(ancestor[ancl.first][0],ancl);\n\
    \t\tancr = Operator::func_lca_edge_merge(ancestor[ancr.first][0],ancr);\n\t\t\
    return Operator::func_lca_edge_merge(ancl,ancr);\n\t}\n\tpair<TypeEdge,vector<size_t>>\
    \ diameter_impl() {\n\t\tTree tree = Tree::builder(g).build();\n\t\tsize_t root\
    \ = 0;\n\t\t{\n\t\t\ttree.make_root(0);\n\t\t}\n\t\troot = max_element(tree.edge_dist.begin(),tree.edge_dist.end())\
    \ - tree.edge_dist.begin();\n\t\t{\n\t\t\ttree.make_root(root);\n\t\t}\n\t\tsize_t\
    \ leaf = max_element(tree.edge_dist.begin(),tree.edge_dist.end()) - tree.edge_dist.begin();\n\
    \t\tTypeEdge sz = tree.edge_dist[leaf];\n\t\tvector<size_t> st;\n\t\t{\n\t\t\t\
    tree.make_parent();\n\t\t\twhile(leaf != root) {\n\t\t\t\tst.push_back(leaf);\n\
    \t\t\t\tleaf = tree.parent[leaf].first;\n\t\t\t}\n\t\t\tst.push_back(root);\n\t\
    \t}\n\t\treturn make_pair(sz,st);\n\t}\n\ttemplate<class TypeReroot> vector<TypeReroot>\
    \ rerooting_impl(vector<TypeReroot> rerootdp,vector<TypeReroot> rerootparent)\
    \ {\n\t\tfor(size_t pa:order) for(auto& e:child[pa]) rerootdp[pa] = Operator::func_reroot_dp(rerootdp[pa],rerootdp[e.first]);\n\
    \t\tfor(size_t pa:reorder) {\n\t\t\tif(depth[pa]) rerootdp[pa] = Operator::func_reroot_dp(rerootdp[pa],rerootparent[pa]);\n\
    \t\t\tsize_t m = child[pa].size();\n\t\t\tfor(int j = 0; j < m && depth[pa]; ++j){\n\
    \t\t\t\tsize_t ch = child[pa][j].first;\n\t\t\t\trerootparent[ch] = Operator::func_reroot_dp(rerootparent[ch],rerootparent[pa]);\n\
    \t\t\t}\n\t\t\tif(m <= 1) continue;\n\t\t\tvector<TypeReroot> l(m),r(m);\n\t\t\
    \tfor(int j = 0; j < m; ++j) {\n\t\t\t\tsize_t ch = child[pa][j].first;\n\t\t\t\
    \tl[j] = rerootdp[ch];\n\t\t\t\tr[j] = rerootdp[ch];\n\t\t\t}\n\t\t\tfor(int j\
    \ = 1; j+1 < m; ++j) l[j] = Operator::func_reroot_merge(l[j],l[j-1]);\n\t\t\t\
    for(int j = m-2; 0 <=j; --j) r[j] = Operator::func_reroot_merge(r[j],r[j+1]);\n\
    \t\t\tsize_t chl = child[pa].front().first;\n\t\t\tsize_t chr = child[pa].back().first;\n\
    \t\t\trerootparent[chl] = Operator::func_reroot_dp(rerootparent[chl],r[1]);\n\t\
    \t\trerootparent[chr] = Operator::func_reroot_dp(rerootparent[chr],l[m-2]);\n\t\
    \t\tfor(int j = 1; j+1 < m; ++j) {\n\t\t\t\tsize_t ch = child[pa][j].first;\n\t\
    \t\t\trerootparent[ch] = Operator::func_reroot_dp(rerootparent[ch],l[j-1]);\n\t\
    \t\t\trerootparent[ch] = Operator::func_reroot_dp(rerootparent[ch],r[j+1]);\n\t\
    \t\t}\n\t\t}\n\t\treturn rerootdp;\n\t}\npublic:\n\tvector<size_t> depth;\n\t\
    vector<size_t> order;\n\tvector<size_t> reorder;\n\tvector<size_t> subtree_size;\n\
    \tvector<pair<size_t,TypeEdge>> parent;\n\tvector<vector<pair<size_t,TypeEdge>>>\
    \ child;\n\tvector<TypeEdge> edge_dist;\n\tvector<array<pair<size_t,TypeEdge>,Operator::bit>>\
    \ ancestor;\n \n\t/**\n\t * O(N) builder\n\t */\n\tstatic TreeBuilder<Operator>\
    \ builder(Graph<TypeEdge>& graph) { return TreeBuilder<Operator>(graph);}\n\t\
    /**\n\t * O(logN) after make_ancestor\n\t * return {lca,lca_dist} l and r must\
    \ be connected \n\t */\n\tpair<size_t,TypeEdge> lca(size_t l, size_t r) {return\
    \ lca_impl(l,r);}\n\t/**\n\t * O(N) anytime\n\t * return {diameter size,diameter\
    \ set} \n\t */\n\tpair<TypeEdge,vector<size_t>> diameter(void){return diameter_impl();}\n\
    \t/**\n\t * O(N) after make_child\n\t */\n\ttemplate<class TypeReroot> vector<TypeReroot>\
    \ rerooting(const vector<TypeReroot>& rerootdp,const vector<TypeReroot>& rerootparent)\
    \ {return rerooting_impl(rerootdp,rerootparent);}\n};\n \ntemplate<class Operator>\
    \ class TreeBuilder {\n\tbool is_root_made =false;\n\tbool is_child_made =false;\n\
    \tbool is_parent_made=false;\npublic:\n\tusing TypeEdge = typename Operator::TypeEdge;\n\
    \tTreeBuilder(Graph<TypeEdge>& g):tree(g){}\n\tTreeBuilder& root(const int rt)\
    \ { is_root_made=true; tree.make_root(rt); return *this;}\n\tTreeBuilder& root()\
    \ { is_root_made=true; tree.make_root(); return *this;}\n\tTreeBuilder& child()\
    \ { assert(is_root_made); is_child_made=true;  tree.make_child();  return *this;}\n\
    \tTreeBuilder& parent() { assert(is_root_made); is_parent_made=true; tree.make_parent();\
    \ return *this;}\n\tTreeBuilder& subtree_size() { assert(is_child_made); tree.make_subtree_size();\
    \ return *this;}\n\tTreeBuilder& ancestor() { assert(is_parent_made); tree.make_ancestor();\
    \ return *this;}\n\tTree<Operator>&& build() {return move(tree);}\nprivate:\n\t\
    Tree<Operator> tree;\n}; \ntemplate<class T> struct TreeOperator{\n\tusing TypeEdge\
    \ = T;\n\tinline static constexpr size_t bit = 20;\n\tinline static constexpr\
    \ TypeEdge unit_edge = 0;\n\tinline static constexpr TypeEdge unit_lca_edge =\
    \ 0;\n\tinline static constexpr TypeEdge func_edge_merge(const TypeEdge& parent,const\
    \ TypeEdge& w){return parent+w;}\n\tinline static constexpr pair<size_t,TypeEdge>\
    \ func_lca_edge_merge(const pair<size_t,TypeEdge>& l,const pair<size_t,TypeEdge>&\
    \ r){return make_pair(l.first,l.second+r.second);}\n\ttemplate<class TypeReroot>\
    \ inline static constexpr TypeReroot func_reroot_dp(const TypeReroot& l,const\
    \ TypeReroot& r) {return {l.first+r.first+r.second,l.second+r.second};}\n\ttemplate<class\
    \ TypeReroot> inline static constexpr TypeReroot func_reroot_merge(const TypeReroot&\
    \ l,const TypeReroot& r) {return {l.first+r.first,l.second+r.second};}\n};\n//auto\
    \ tree = Tree<TreeOperator<int>>::builder(g).build();\n#line 13 \"test/graph/Tree-parent.test.cpp\"\
    \n\ntemplate<class T> void chmin(T& a,T b) {a=min(a,b);}\n\nint main(void){\n\
    \    long long N,Q,C; cin >> N >> Q >> C;\n    Graph<long long> g(N);\n    for(int\
    \ i=0;i+1<N;++i) {\n        int u,v,w; cin >> u >> v >> w;\n        u--,v--;\n\
    \        g.make_bidirectional_edge(u,v,w);\n    }\n    vector<int> X(Q);\n   \
    \ for(int i=0;i<Q;++i) cin >> X[i],X[i]--;\n\n    //dp_i,j := x_i\u306B\u3044\u3066\
    \u3001\u30B8\u30E3\u30F3\u30D7\u30D3\u30FC\u30B3\u30F3\u304Cj\u306B\u3042\u308B\
    \u3068\u304D\u306E\u6700\u5C0F\u5024\u3002j=N\u306F\u30D3\u30FC\u30B3\u30F3\u306A\
    \u3057\u3002\n\tvector<vector<long long>> dp(Q,vector<long long>(N+1,1e18));\n\
    \    dp[0][N]=0;\n    for(int i=1;i<Q;++i) {\n\n        auto tree = Tree<TreeOperator<long\
    \ long>>::builder(g).root(X[i]).parent().child().build();\n\n        //j\u306B\
    \u3042\u308B\u30B8\u30E3\u30F3\u30D7\u30D3\u30FC\u30B3\u30F3\u3092\u305D\u306E\
    \u307E\u307E\u306B\u3057\u3066\u3001X[i]\u3078\u5411\u304B\u3046\u3068\u304D\n\
    \        for(int j=0;j<=N;++j) {\n            chmin(dp[i][j],dp[i-1][j]+tree.edge_dist[X[i-1]]);\n\
    \        }\n        //j\u306B\u30B8\u30E3\u30F3\u30D7\u30D3\u30FC\u30B3\u30F3\u3092\
    \u7F6E\u3044\u3066\u3001X[i]\u3078\u5411\u304B\u3046\u3068\u304D\n        {\n\
    \            long long cost=tree.edge_dist[X[i-1]];\n            for(int j=X[i-1];\
    \ j != X[i]; j = tree.parent[j].first) {\n                chmin(dp[i][j],dp[i-1][N]+cost);\n\
    \            }\n        }\n        //\u30B8\u30E3\u30F3\u30D7\u30D3\u30FC\u30B3\
    \u30F3\u3092\u4F7F\u3063\u305F\u5F8C\u3001X[i]\u3078\u5411\u304B\u3046\u3068\u304D\
    \n        for(int j=0;j<N;++j){\n            chmin(dp[i][N],dp[i-1][j]+tree.edge_dist[j]+C);\n\
    \        }\n        //\u30B8\u30E3\u30F3\u30D7\u30D3\u30FC\u30B3\u30F3\u3092\u4F7F\
    \u3063\u305F\u5F8Cj\u306B\u30B8\u30E3\u30F3\u30D7\u30D3\u30FC\u30B3\u30F3\u3092\
    \u7F6E\u3044\u3066\u3001X[i]\u3078\u5411\u304B\u3046\u3068\u304D\n        //dp2_j\
    \ := \u9802\u70B9j\u306B\u3044\u308B\u3068\u304D\u306E\u6700\u5C0F\u5024\n   \
    \     vector<long long> dp2(N);\n        for(int j=0;j<N;++j) dp2[j]=dp[i-1][j]+(X[i-1]==j?0:C);\n\
    \n        for(int j:tree.order) {\n            long long cost=0;\n           \
    \ {\n                cost+=tree.edge_dist[j];\n            }\n            for(auto&\
    \ e:tree.child[j]) {\n                int ch = e.first;\n                chmin(dp2[j],dp2[ch]+e.second);\n\
    \            }\n            cost += dp2[j];\n            chmin(dp[i][j],cost);\n\
    \        }\n    }\n    cout << *min_element(dp.back().begin(),dp.back().end())\
    \ << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1308\"\n\n#include <vector>\n\
    #include <iostream>\n#include <cassert>\n#include <algorithm>\n#include <stack>\n\
    #include <numeric>\n#include <array>\nusing namespace std;\n#include \"../../lib/graph/Graph.cpp\"\
    \n#include \"../../lib/graph/Tree2.cpp\"\n\ntemplate<class T> void chmin(T& a,T\
    \ b) {a=min(a,b);}\n\nint main(void){\n    long long N,Q,C; cin >> N >> Q >> C;\n\
    \    Graph<long long> g(N);\n    for(int i=0;i+1<N;++i) {\n        int u,v,w;\
    \ cin >> u >> v >> w;\n        u--,v--;\n        g.make_bidirectional_edge(u,v,w);\n\
    \    }\n    vector<int> X(Q);\n    for(int i=0;i<Q;++i) cin >> X[i],X[i]--;\n\n\
    \    //dp_i,j := x_i\u306B\u3044\u3066\u3001\u30B8\u30E3\u30F3\u30D7\u30D3\u30FC\
    \u30B3\u30F3\u304Cj\u306B\u3042\u308B\u3068\u304D\u306E\u6700\u5C0F\u5024\u3002\
    j=N\u306F\u30D3\u30FC\u30B3\u30F3\u306A\u3057\u3002\n\tvector<vector<long long>>\
    \ dp(Q,vector<long long>(N+1,1e18));\n    dp[0][N]=0;\n    for(int i=1;i<Q;++i)\
    \ {\n\n        auto tree = Tree<TreeOperator<long long>>::builder(g).root(X[i]).parent().child().build();\n\
    \n        //j\u306B\u3042\u308B\u30B8\u30E3\u30F3\u30D7\u30D3\u30FC\u30B3\u30F3\
    \u3092\u305D\u306E\u307E\u307E\u306B\u3057\u3066\u3001X[i]\u3078\u5411\u304B\u3046\
    \u3068\u304D\n        for(int j=0;j<=N;++j) {\n            chmin(dp[i][j],dp[i-1][j]+tree.edge_dist[X[i-1]]);\n\
    \        }\n        //j\u306B\u30B8\u30E3\u30F3\u30D7\u30D3\u30FC\u30B3\u30F3\u3092\
    \u7F6E\u3044\u3066\u3001X[i]\u3078\u5411\u304B\u3046\u3068\u304D\n        {\n\
    \            long long cost=tree.edge_dist[X[i-1]];\n            for(int j=X[i-1];\
    \ j != X[i]; j = tree.parent[j].first) {\n                chmin(dp[i][j],dp[i-1][N]+cost);\n\
    \            }\n        }\n        //\u30B8\u30E3\u30F3\u30D7\u30D3\u30FC\u30B3\
    \u30F3\u3092\u4F7F\u3063\u305F\u5F8C\u3001X[i]\u3078\u5411\u304B\u3046\u3068\u304D\
    \n        for(int j=0;j<N;++j){\n            chmin(dp[i][N],dp[i-1][j]+tree.edge_dist[j]+C);\n\
    \        }\n        //\u30B8\u30E3\u30F3\u30D7\u30D3\u30FC\u30B3\u30F3\u3092\u4F7F\
    \u3063\u305F\u5F8Cj\u306B\u30B8\u30E3\u30F3\u30D7\u30D3\u30FC\u30B3\u30F3\u3092\
    \u7F6E\u3044\u3066\u3001X[i]\u3078\u5411\u304B\u3046\u3068\u304D\n        //dp2_j\
    \ := \u9802\u70B9j\u306B\u3044\u308B\u3068\u304D\u306E\u6700\u5C0F\u5024\n   \
    \     vector<long long> dp2(N);\n        for(int j=0;j<N;++j) dp2[j]=dp[i-1][j]+(X[i-1]==j?0:C);\n\
    \n        for(int j:tree.order) {\n            long long cost=0;\n           \
    \ {\n                cost+=tree.edge_dist[j];\n            }\n            for(auto&\
    \ e:tree.child[j]) {\n                int ch = e.first;\n                chmin(dp2[j],dp2[ch]+e.second);\n\
    \            }\n            cost += dp2[j];\n            chmin(dp[i][j],cost);\n\
    \        }\n    }\n    cout << *min_element(dp.back().begin(),dp.back().end())\
    \ << endl;\n    return 0;\n}"
  dependsOn:
  - lib/graph/Graph.cpp
  - lib/graph/Tree2.cpp
  isVerificationFile: true
  path: test/graph/Tree-parent.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 02:13:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/Tree-parent.test.cpp
layout: document
redirect_from:
- /verify/test/graph/Tree-parent.test.cpp
- /verify/test/graph/Tree-parent.test.cpp.html
title: test/graph/Tree-parent.test.cpp
---
