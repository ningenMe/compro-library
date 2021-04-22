---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/Graph.cpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: lib/graph/Tree.cpp
    title: "Tree - \u6728"
  - icon: ':heavy_check_mark:'
    path: lib/segment/LazySegmentTree.cpp
    title: "LazySegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u9045\u5EF6\u8A55\
      \u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/900
    links:
    - https://yukicoder.me/problems/no/900
  bundledCode: "#line 1 \"test/graph/Tree-eulertour.test.cpp\"\n#define PROBLEM \"\
    https://yukicoder.me/problems/no/900\"\n\n#include <vector>\n#include <iostream>\n\
    #include <cassert>\n#include <map>\n#include <algorithm>\n#include <stack>\n#include\
    \ <numeric>\n#include <array>\nusing namespace std;\n#line 1 \"lib/graph/Graph.cpp\"\
    \n/*\n * @title Graph\n * @docs md/graph/Graph.md\n */\ntemplate<class T> class\
    \ Graph{\nprivate:\n    const size_t N,H,W;\npublic:\n    vector<vector<pair<size_t,T>>>\
    \ edges;\n    Graph(const size_t N):H(-1),W(-1),N(N), edges(N) {}\n    Graph(const\
    \ size_t H, const size_t W):H(H),W(W),N(H*W), edges(H*W) {}\n    inline void make_edge(size_t\
    \ from, size_t to, T w) {\n        edges[from].emplace_back(to,w);\n    }\n  \
    \  //{from_y,from_x} -> {to_y,to_x} \n    inline void make_edge(pair<size_t,size_t>\
    \ from, pair<size_t,size_t> to, T w) {\n        make_edge(from.first*W+from.second,to.first*W+to.second,w);\n\
    \    }\n    inline void make_bidirectional_edge(size_t from, size_t to, T w) {\n\
    \        make_edge(from,to,w);\n        make_edge(to,from,w);\n    }\n    inline\
    \ void make_bidirectional_edge(pair<size_t,size_t> from, pair<size_t,size_t> to,\
    \ T w) {\n        make_edge(from.first*W+from.second,to.first*W+to.second,w);\n\
    \        make_edge(to.first*W+to.second,from.first*W+from.second,w);\n    }\n\
    \    inline size_t size(){return N;}\n    inline size_t idx(pair<size_t,size_t>\
    \ yx){return yx.first*W+yx.second;}\n};\n#line 1 \"lib/graph/Tree.cpp\"\n/*\n\
    \ * @title Tree - \u6728\n * @docs md/graph/Tree.md\n */\ntemplate<class Operator>\
    \ class TreeBuilder;\ntemplate<class Operator> class Tree {\n\tusing TypeEdge\
    \ = typename Operator::TypeEdge;\n\tsize_t num;\n\tsize_t ord;\n\tGraph<TypeEdge>&\
    \ g;\n\tfriend TreeBuilder<Operator>;\n\tTree(Graph<TypeEdge>& graph):\n\t\tg(graph),\n\
    \t\tnum(graph.size()),\n\t\tdepth(graph.size(),-1),\n\t\torder(graph.size()),\n\
    \t\tedge_dist(graph.size()){\n\t}\n\t//for make_depth\n\tvoid dfs(int curr, int\
    \ prev){\n\t\tfor(const auto& e:g.edges[curr]){\n\t\t\tconst int& next = e.first;\n\
    \t\t\tif(next==prev) continue;\n\t\t\tdepth[next] = depth[curr] + 1;\n\t\t\tedge_dist[next]\
    \  = Operator::func_edge_merge(edge_dist[curr],e.second);\n\t\t\tdfs(next,curr);\n\
    \t\t\torder[ord++] = next;\n\t\t}\n\t}\n\t//for make_eulertour\n\tvoid dfs(int\
    \ from){\n\t\teulertour.push_back(from);\n\t\tfor(auto& e:child[from]){\n\t\t\t\
    int to = e.first;            \n\t\t\tdfs(to);        \n\t\t\teulertour.push_back(from);\n\
    \t\t}\n\t}\n\tvoid make_root(const int root) {\n\t\tdepth[root] = 0;\n\t\tedge_dist[root]\
    \ = Operator::unit_edge;\n\t\tord = 0;\n\t\tdfs(root,-1);\n\t\torder[ord++] =\
    \ root;\n\t\treverse_copy(order.begin(),order.end(),back_inserter(reorder));\n\
    \t}\n\tvoid make_root() {\n        ord = 0;\n        for(int i=0;i<num;++i) {\n\
    \            if(depth[i]!=-1) continue;\n            depth[i] = 0;\n         \
    \   edge_dist[i] = Operator::unit_edge;\n            dfs(i,-1);\n            order[ord++]\
    \ = i;\n        }\n\t\treverse_copy(order.begin(),order.end(),back_inserter(reorder));\n\
    \t}\n\tvoid make_child(const int root = 0) {\n\t\tchild.resize(num);\n\t\tfor\
    \ (size_t i = 0; i < num; ++i) for (auto& e : g.edges[i]) if (depth[i] < depth[e.first])\
    \ child[i].push_back(e);\n\t}\n\tvoid make_subtree_size() {\n\t\tsubtree_size.resize(num,1);\n\
    \t\tfor (size_t i:order) for (auto e : child[i]) subtree_size[i] += subtree_size[e.first];\n\
    \t}\n\tvoid make_parent() {\n\t\tparent.resize(num,make_pair(num,Operator::unit_edge));\n\
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
    \t\t}\n\t\t}\n\t\treturn rerootdp;\n\t}\n\tvoid make_eulertour() {\n\t\tdfs(reorder.front());\n\
    \t\teulertour_range.resize(num);\n\t\tfor(int i = 0; i < eulertour.size(); ++i)\
    \ eulertour_range[eulertour[i]].second = i+1;\n\t\tfor(int i = eulertour.size()-1;\
    \ 0 <= i; --i) eulertour_range[eulertour[i]].first = i;\n\t}\n\tvoid make_heavy_light_decomposition(){\n\
    \t\thead.resize(num);\n\t\thld.resize(num);\n\t\tiota(head.begin(),head.end(),0);\n\
    \t\tfor(size_t& pa:reorder) {\n\t\t\tpair<size_t,size_t> maxi = {0,num};\n\t\t\
    \tfor(auto& p:child[pa]) maxi = max(maxi,{subtree_size[p.first],p.first});\n\t\
    \t\tif(maxi.first) head[maxi.second] = head[pa];\n\t\t}\n\t\tstack<size_t> st_head,st_sub;\n\
    \t\tsize_t cnt = 0;\n\t\t//\u6839\u306B\u8FD1\u3044\u65B9\u304B\u3089\u63A2\u7D22\
    \n\t\tfor(size_t& root:reorder){\n\t\t\tif(depth[root]) continue;\n\t\t\t//\u6839\
    \u3092push\n\t\t\tst_head.push(root);\n\t\t\twhile(st_head.size()){\n\t\t\t\t\
    size_t h = st_head.top();\n\t\t\t\tst_head.pop();\n\t\t\t\t//\u90E8\u5206\u6728\
    \u306E\u6839\u3092push\n\t\t\t\tst_sub.push(h);\n\t\t\t\twhile (st_sub.size()){\n\
    \t\t\t\t\tsize_t pa = st_sub.top();\n\t\t\t\t\tst_sub.pop();\n\t\t\t\t\t//\u90E8\
    \u5206\u6728\u3092\u30AB\u30A6\u30F3\u30C8\u3057\u3066\u3044\u304F\n\t\t\t\t\t\
    hld[pa] = cnt++;\n\t\t\t\t\t//\u5B50\u3092\u63A2\u7D22\n\t\t\t\t\tfor(auto& p:child[pa])\
    \ {\n\t\t\t\t\t\t//\u5B50\u306Ehead\u304C\u89AA\u3068\u540C\u3058\u306A\u3089\u3001\
    \u305D\u306E\u307E\u307E\u9032\u3080\n\t\t\t\t\t\tif(head[p.first]==head[pa])\
    \ st_sub.push(p.first);\n\t\t\t\t\t\t//\u305D\u3046\u3058\u3083\u306A\u3044\u5834\
    \u5408\u306F\u3001\u305D\u3053\u304B\u3089\u65B0\u3057\u304F\u90E8\u5206\u6728\
    \u3068\u3057\u3066\u307F\u306A\u3059\n\t\t\t\t\t\telse st_head.push(p.first);\n\
    \t\t\t\t\t}\n\t\t\t\t}\t\t\t\t\n\t\t\t}\n\t\t}\n\t}\n\t//type 0: vertex, 1: edge\n\
    \tvector<pair<size_t,size_t>> path_impl(size_t u,size_t v,int type = 0) {\n\t\t\
    vector<pair<size_t,size_t>> path;\n\t\twhile(1){\n\t\t\tif(hld[u]>hld[v]) swap(u,v);\n\
    \t\t\tif(head[u]!=head[v]) {\n\t\t\t\tpath.push_back({hld[head[v]],hld[v]});\n\
    \t\t\t\tv=parent[head[v]].first;\n\t\t\t}\n\t\t\telse {\n\t\t\t\tpath.push_back({hld[u],hld[v]});\n\
    \t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\treverse(path.begin(),path.end());\n\t\tif(type)\
    \ path.front().first++;\n\t\treturn path;\n\t}\n\tpair<vector<pair<size_t,size_t>>,vector<pair<size_t,size_t>>>\
    \ ordered_path_impl(size_t u,size_t v,int type = 0) {\n\t\tvector<pair<size_t,size_t>>\
    \ path_lca_to_u;\n\t\tvector<pair<size_t,size_t>> path_lca_to_v;\n\t\twhile(1){\n\
    \t\t\tif(head[u] == head[v]) {\n                if(depth[u] < depth[v]) path_lca_to_v.emplace_back(hld[u]+type,hld[v]);\n\
    \                else path_lca_to_u.emplace_back(hld[v]+type,hld[u]);\n\t\t\t\t\
    break;\n\t\t\t}\n            else if(hld[u] < hld[v]) {\n                path_lca_to_v.emplace_back(hld[head[v]],hld[v]);\n\
    \                v = parent[head[v]].first;\n            }\n            else if(hld[u]\
    \ > hld[v]) {\n                path_lca_to_u.emplace_back(hld[head[u]],hld[u]);\n\
    \                u = parent[head[u]].first;\n            }\n\t\t}\n\t\treverse(path_lca_to_v.begin(),path_lca_to_v.end());\n\
    \t\treturn {path_lca_to_u,path_lca_to_v};\n\t}\n\tsize_t lca_idx_impl(size_t u,size_t\
    \ v){\n\t\twhile(1){\n\t\t\tif(hld[u]>hld[v]) swap(u,v);\n\t\t\tif(head[u]==head[v])\
    \ return u;\n\t\t\tv=parent[head[v]].first;\n\t\t}\n\t}\n\tvector<size_t> head;\n\
    public:\n\tvector<size_t> depth;\n\tvector<size_t> order;\n\tvector<size_t> reorder;\n\
    \tvector<size_t> subtree_size;\n\tvector<pair<size_t,TypeEdge>> parent;\n\tvector<vector<pair<size_t,TypeEdge>>>\
    \ child;\n\tvector<TypeEdge> edge_dist;\n\tvector<array<pair<size_t,TypeEdge>,Operator::bit>>\
    \ ancestor;\n\tvector<size_t> eulertour;\n\tvector<pair<size_t,size_t>> eulertour_range;\n\
    \tvector<size_t> hld;\n\n\t/**\n\t * O(N) builder\n\t */\n\tstatic TreeBuilder<Operator>\
    \ builder(Graph<TypeEdge>& graph) { return TreeBuilder<Operator>(graph);}\n\t\
    /**\n\t * O(logN) after make_ancestor\n\t * return {lca,lca_dist} l and r must\
    \ be connected \n\t */\n\tpair<size_t,TypeEdge> lca(size_t l, size_t r) {return\
    \ lca_impl(l,r);}\n\t/**\n\t * O(N) anytime\n\t * return {diameter size,diameter\
    \ set} \n\t */\n\tpair<TypeEdge,vector<size_t>> diameter(void){return diameter_impl();}\n\
    \t/**\n\t * O(N) after make_child\n\t */\n\ttemplate<class TypeReroot> vector<TypeReroot>\
    \ rerooting(const vector<TypeReroot>& rerootdp,const vector<TypeReroot>& rerootparent)\
    \ {return rerooting_impl(rerootdp,rerootparent);}\n\t/**\n\t * O(logN) \n\t */\n\
    \tvector<pair<size_t,size_t>> vertex_set_on_path(size_t u, size_t v) {return path_impl(u,v,0);}\n\
    \t/**\n\t/**\n\t * O(logN) \n\t */\n\tvector<pair<size_t,size_t>> edge_set_on_path(size_t\
    \ u, size_t v) {return path_impl(u,v,1);}\n\t/**\n\t * O(logN) \n     * {lca to\
    \ u path,lca to v path}\n\t */\n\tpair<vector<pair<size_t,size_t>>,vector<pair<size_t,size_t>>>\
    \ vertex_ordered_set_on_path(size_t u, size_t v) {return ordered_path_impl(u,v,0);}\n\
    \t/**\n\t * O(logN) \n     * {lca to u path,lca to v path}\n\t */\n\tpair<vector<pair<size_t,size_t>>,vector<pair<size_t,size_t>>>\
    \ edge_ordered_set_on_path(size_t u, size_t v) {return ordered_path_impl(u,v,1);}\n\
    \t/**\n\t * O(logN) ancestor\u306Elca\u3088\u308A\u5B9A\u6570\u500D\u8EFD\u3081\
    \u3002idx\u3060\u3051\n\t */\n\tsize_t lca_idx(size_t u, size_t v) {return lca_idx_impl(u,v);}\n\
    };\n \ntemplate<class Operator> class TreeBuilder {\n\tbool is_root_made =false;\n\
    \tbool is_child_made =false;\n\tbool is_parent_made=false;\n\tbool is_subtree_size_made=false;\n\
    public:\n\tusing TypeEdge = typename Operator::TypeEdge;\n\tTreeBuilder(Graph<TypeEdge>&\
    \ g):tree(g){}\n\tTreeBuilder& root(const int rt) { is_root_made=true; tree.make_root(rt);\
    \ return *this;}\n\tTreeBuilder& root() { is_root_made=true; tree.make_root();\
    \ return *this;}\n\tTreeBuilder& child() { assert(is_root_made); is_child_made=true;\
    \  tree.make_child();  return *this;}\n\tTreeBuilder& parent() { assert(is_root_made);\
    \ is_parent_made=true; tree.make_parent(); return *this;}\n\tTreeBuilder& subtree_size()\
    \ { assert(is_child_made); is_subtree_size_made=true; tree.make_subtree_size();\
    \ return *this;}\n\tTreeBuilder& ancestor() { assert(is_parent_made); tree.make_ancestor();\
    \ return *this;}\n\tTreeBuilder& eulertour() { assert(is_child_made); tree.make_eulertour();\
    \ return *this;}\n\tTreeBuilder& heavy_light_decomposition() { assert(is_subtree_size_made);\
    \ assert(is_parent_made); tree.make_heavy_light_decomposition(); return *this;}\n\
    \tTree<Operator>&& build() {return move(tree);}\nprivate:\n\tTree<Operator> tree;\n\
    }; \ntemplate<class T> struct TreeOperator{\n\tusing TypeEdge = T;\n\tinline static\
    \ constexpr size_t bit = 20;\n\tinline static constexpr TypeEdge unit_edge = 0;\n\
    \tinline static constexpr TypeEdge unit_lca_edge = 0;\n\tinline static constexpr\
    \ TypeEdge func_edge_merge(const TypeEdge& parent,const TypeEdge& w){return parent+w;}\n\
    \tinline static constexpr pair<size_t,TypeEdge> func_lca_edge_merge(const pair<size_t,TypeEdge>&\
    \ l,const pair<size_t,TypeEdge>& r){return make_pair(l.first,l.second+r.second);}\n\
    \ttemplate<class TypeReroot> inline static constexpr TypeReroot func_reroot_dp(const\
    \ TypeReroot& l,const TypeReroot& r) {return {l.first+r.first+r.second,l.second+r.second};}\n\
    \ttemplate<class TypeReroot> inline static constexpr TypeReroot func_reroot_merge(const\
    \ TypeReroot& l,const TypeReroot& r) {return {l.first+r.first,l.second+r.second};}\n\
    };\n//auto tree = Tree<TreeOperator<int>>::builder(g).build();\n#line 1 \"lib/segment/LazySegmentTree.cpp\"\
    \n/*\n * @title LazySegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u9045\u5EF6\
    \u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @docs md/segment/LazySegmentTree.md\n\
    \ */\ntemplate<class Operator> class LazySegmentTree {\n\tusing TypeNode = typename\
    \ Operator::TypeNode;          \n\tusing TypeLazy = typename Operator::TypeLazy;\n\
    \tsize_t num;      \n\tsize_t length;                                   \n\tsize_t\
    \ height;                                   \n\tvector<TypeNode> node;       \
    \                    \n\tvector<TypeLazy> lazy;                           \n\t\
    vector<pair<size_t,size_t>> range;\n\n\tvoid propagate(int k) {\n\t\tif(lazy[k]\
    \ == Operator::unit_lazy) return;\n        node[k] = Operator::func_merge(node[k],lazy[k],range[k].first,range[k].second);\n\
    \t\tif(k < length) lazy[2*k+0] = Operator::func_lazy(lazy[2*k+0],lazy[k]);\n\t\
    \tif(k < length) lazy[2*k+1] = Operator::func_lazy(lazy[2*k+1],lazy[k]);\n\t\t\
    lazy[k] = Operator::unit_lazy;\n\t}\npublic:\n\n\t//unit\u3067\u521D\u671F\u5316\
    \n\tLazySegmentTree(const size_t num) : num(num) {\n\t\tfor (length = 1,height\
    \ = 0; length <= num; length *= 2, height++);\n\t\tnode.resize(2 * length, Operator::unit_node);\n\
    \t\tlazy.resize(2 * length, Operator::unit_lazy);\n\t\tfor (int i = 0; i < num;\
    \ ++i) node[i + length] = Operator::unit_node;\n\t\tfor (int i = length - 1; i\
    \ >= 0; --i) node[i] = Operator::func_node(node[(i<<1)+0],node[(i<<1)+1]);\n\t\
    \trange.resize(2 * length);\n\t\tfor (int i = 0; i < length; ++i) range[i+length]\
    \ = make_pair(i,i+1);\n\t\tfor (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \t}\n\n\t// //\u540C\u3058init\u3067\u521D\u671F\u5316\n\tLazySegmentTree(const\
    \ size_t num, const TypeNode init) : num(num) {\n\t\tfor (length = 1,height =\
    \ 0; length <= num; length *= 2, height++);\n\t\tnode.resize(2 * length, Operator::unit_node);\n\
    \t\tlazy.resize(2 * length, Operator::unit_lazy);\n\t\tfor (int i = 0; i < num;\
    \ ++i) node[i + length] = init;\n\t\tfor (int i = length - 1; i >= 0; --i) node[i]\
    \ = Operator::func_node(node[(i<<1)+0],node[(i<<1)+1]);\n\t\trange.resize(2 *\
    \ length);\n\t\tfor (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);\n\
    \t\tfor (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \t}\n\n\t//vector\u3067\u521D\u671F\u5316\n\tLazySegmentTree(const vector<TypeNode>&\
    \ vec) : num(vec.size()) {\n\t\tfor (length = 1,height = 0; length <= vec.size();\
    \ length *= 2, height++);\n\t\tnode.resize(2 * length, Operator::unit_node);\n\
    \t\tlazy.resize(2 * length, Operator::unit_lazy);\n\t\tfor (int i = 0; i < vec.size();\
    \ ++i) node[i + length] = vec[i];\n\t\tfor (int i = length - 1; i >= 0; --i) node[i]\
    \ = Operator::func_node(node[(i<<1)+0],node[(i<<1)+1]);\n\t\trange.resize(2 *\
    \ length);\n\t\tfor (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);\n\
    \t\tfor (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \t}\n\n\t//update [a,b)\n\tvoid update(int a, int b, TypeLazy x) {\n\t\tint l\
    \ = a + length, r = b + length - 1;\n\t\tfor (int i = height; 0 < i; --i) propagate(l\
    \ >> i), propagate(r >> i);\n\t\tfor(r++; l < r; l >>=1, r >>=1) {\n\t\t\tif(l&1)\
    \ lazy[l] = Operator::func_lazy(lazy[l],x), propagate(l),l++;\n\t\t\tif(r&1) --r,lazy[r]\
    \ = Operator::func_lazy(lazy[r],x), propagate(r);\n\t\t}\n\t\tl = a + length,\
    \ r = b + length - 1;\n\t\twhile ((l>>=1),(r>>=1),l) {\n            if(lazy[l]\
    \ == Operator::unit_lazy) node[l] = Operator::func_node(Operator::func_merge(node[(l<<1)+0],lazy[(l<<1)+0],range[(l<<1)+0].first,range[(l<<1)+0].second),Operator::func_merge(node[(l<<1)+1],lazy[(l<<1)+1],range[(l<<1)+1].first,range[(l<<1)+1].second));\n\
    \            if(lazy[r] == Operator::unit_lazy) node[r] = Operator::func_node(Operator::func_merge(node[(r<<1)+0],lazy[(r<<1)+0],range[(r<<1)+0].first,range[(r<<1)+0].second),Operator::func_merge(node[(r<<1)+1],lazy[(r<<1)+1],range[(r<<1)+1].first,range[(r<<1)+1].second));\n\
    \  \t\t}\n\t}\n\n\t//get [a,b)\n\tTypeNode get(int a, int b) {\n\t\tint l = a\
    \ + length, r = b + length - 1;\n\t\tfor (int i = height; 0 < i; --i) propagate(l\
    \ >> i), propagate(r >> i);\n\t\tTypeNode vl = Operator::unit_node, vr = Operator::unit_node;\n\
    \t\tfor(r++; l < r; l >>=1, r >>=1) {\n            if(l&1) vl = Operator::func_node(vl,Operator::func_merge(node[l],lazy[l],range[l].first,range[l].second)),l++;\n\
    \            if(r&1) r--,vr = Operator::func_node(Operator::func_merge(node[r],lazy[r],range[r].first,range[r].second),vr);\n\
    \ \t\t}\n\t\treturn Operator::func_node(vl,vr);\n\t}\n\n\t//return [0,length]\n\
    \tint prefix_binary_search(TypeNode var) {\n\t\tint l = length, r = 2*length -\
    \ 1;\n\t\tfor (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);\n\
    \t\tif(!Operator::func_check(node[1],var)) return num;\n\t\tTypeNode ret = Operator::unit_node;\n\
    \t\tsize_t idx = 2;\n\t\tfor(; idx < 2*length; idx<<=1){\n            if(!Operator::func_check(Operator::func_node(ret,Operator::func_merge(node[idx],lazy[idx],range[idx].first,range[idx].second)),var))\
    \ {\n                ret = Operator::func_node(ret,Operator::func_merge(node[idx],lazy[idx],range[idx].first,range[idx].second));\n\
    \                idx++;\n            }\n\t\t}\n\t\treturn min((idx>>1) - length,num);\n\
    \t}\n\n\t//range[l,r) return [l,r]\n\tint binary_search(size_t l, size_t r, TypeNode\
    \ var) {\n\t\tif (l < 0 || length <= l || r < 0 || length < r) return -1;\n\t\t\
    for (int i = height; 0 < i; --i) propagate((l+length) >> i), propagate((r+length-1)\
    \ >> i);\n\t\tTypeNode ret = Operator::unit_node;\n\t\tsize_t off = l;\n\t\tfor(size_t\
    \ idx = l+length; idx < 2*length && off < r; ){\n            if(range[idx].second<=r\
    \ && !Operator::func_check(Operator::func_node(ret,Operator::func_merge(node[idx],lazy[idx],range[idx].first,range[idx].second)),var))\
    \ {\n                ret = Operator::func_node(ret,Operator::func_merge(node[idx],lazy[idx],range[idx].first,range[idx].second));\n\
    \                off = range[idx++].second;\n                if(!(idx&1)) idx\
    \ >>= 1;\t\t\t\n            }\n            else{\n\t\t\t\tidx <<=1;\n\t\t\t}\n\
    \t\t}\n\t\treturn off;\n\t}\n\n\tvoid print(){\n\t\t// cout << \"node\" << endl;\n\
    \t\t// for(int i = 1,j = 1; i < 2*length; ++i) {\n\t\t// \tcout << node[i] <<\
    \ \" \";\n\t\t// \tif(i==((1<<j)-1) && ++j) cout << endl;\n\t\t// }\n\t\t// cout\
    \ << \"lazy\" << endl;\n\t\t// for(int i = 1,j = 1; i < 2*length; ++i) {\n\t\t\
    // \tcout << lazy[i] << \" \";\n\t\t// \tif(i==((1<<j)-1) && ++j) cout << endl;\n\
    \t\t// }\n\t\tcout << \"vector\" << endl;\n\t\tcout << \"{ \" << get(0,1);\n\t\
    \tfor(int i = 1; i < length; ++i) cout << \", \" << get(i,i+1);\n\t\tcout << \"\
    \ }\" << endl;\n\t}\n};\n\n//node:\u6700\u5C0F\u3000lazy:\u52A0\u7B97\ntemplate<class\
    \ T, class U> struct NodeMinRangeAdd {\n\tusing TypeNode = T;\n\tusing TypeLazy\
    \ = U;\n\tinline static constexpr TypeNode unit_node = 1234567890;\n\tinline static\
    \ constexpr TypeLazy unit_lazy = 0;\n\tinline static constexpr TypeNode func_node(TypeNode\
    \ l,TypeNode r){return min(l,r);}\n\tinline static constexpr TypeLazy func_lazy(TypeLazy\
    \ old_lazy,TypeLazy new_lazy){return old_lazy+new_lazy;}\n\tinline static constexpr\
    \ TypeNode func_merge(TypeNode node,TypeLazy lazy,int l, int r){return node+lazy;}\n\
    \t// LazySegmentTree<NodeMinRangeAdd<ll,ll>> Seg(N,0);\n};\n\n//node:\u7DCF\u548C\
    \u3000lazy:\u66F4\u65B0\ntemplate<class T, class U> struct NodeSumRangeUpdate\
    \ {\n\tusing TypeNode = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode\
    \ unit_node = 0;\n\tinline static constexpr TypeLazy unit_lazy = -2000;\n\tinline\
    \ static constexpr TypeNode func_node(TypeNode l,TypeNode r){return l+r;}\n\t\
    inline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return\
    \ new_lazy;}\n\tinline static constexpr TypeNode func_merge(TypeNode node,TypeLazy\
    \ lazy,int l, int r){return lazy!=-2000?lazy*(r-l):node;}\n\tinline static constexpr\
    \ bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}\n\t//\
    \ LazySegmentTree<NodeSumRangeUpdate<ll,ll>> Seg(N,0);\n};\n\n//node:\u7DCF\u548C\
    \u3000lazy:\u52A0\u7B97\ntemplate<class T, class U> struct NodeSumRangeAdd {\n\
    \tusing TypeNode = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode\
    \ unit_node = 0;\n\tinline static constexpr TypeLazy unit_lazy = 0;\n\tinline\
    \ static constexpr TypeNode func_node(TypeNode l,TypeNode r){return l+r;}\n\t\
    inline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return\
    \ old_lazy+new_lazy;}\n\tinline static constexpr TypeNode func_merge(TypeNode\
    \ node,TypeLazy lazy,int l, int r){return node+lazy*(r-l);}\n\tinline static constexpr\
    \ bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}\n\t//\
    \ LazySegmentTree<NodeSumRangeUpdate<ll,ll>> Seg(N,0);\n};\n\n//node:\u6700\u5C0F\
    \u3000lazy:\u7B49\u5DEE\u6570\u5217\u66F4\u65B0\ntemplate<class T, class U> struct\
    \ NodeMinRangeArithmeticUpdate {\n    using TypeNode = T;\n    using TypeLazy\
    \ = U;\n    inline static constexpr TypeNode unit_node = 1234567;\n    inline\
    \ static constexpr TypeLazy unit_lazy = {-2000,-2000};\n    inline static constexpr\
    \ TypeNode func_node(TypeNode l,TypeNode r){return min(l,r);}\n    inline static\
    \ constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return new_lazy;}\n\
    \    inline static constexpr TypeNode func_merge(TypeNode node,TypeLazy lazy,int\
    \ l,int r){ return (lazy.first==-2000?node:lazy.first + (l-lazy.second));}\n \
    \   inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return\
    \ var <= nodeVal;}\n};\n#line 15 \"test/graph/Tree-eulertour.test.cpp\"\n\n\n\
    //node:\u7DCF\u548C\u3000lazy:\u52A0\u7B97\ntemplate<class T, class U> struct\
    \ NodeEulerTourSumRangeAdd {\n\tusing TypeNode = T;\n\tusing TypeLazy = U;\n\t\
    inline static constexpr TypeNode unit_node = {0,0};\n\tinline static constexpr\
    \ TypeLazy unit_lazy = 0;\n\tinline static constexpr TypeNode func_node(TypeNode\
    \ l,TypeNode r){return {l.first+r.first,l.second+r.second};}\n\tinline static\
    \ constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return old_lazy+new_lazy;}\n\
    \tinline static constexpr TypeNode func_merge(TypeNode node,TypeLazy lazy,int\
    \ l, int r){return {node.first+node.second*lazy,node.second};}\n\tinline static\
    \ constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}\n\
    \t// LazySegmentTree<NodeSumRangeUpdate<ll,ll>> Seg(N,0);\n};\n\n\nint main(void){\n\
    \tint N; cin >> N;\n\tGraph<long long> g(N);\n\tfor(int i=0;i<N-1;++i) {\n\t\t\
    int u,v,w; cin >> u >> v >> w;\n\t\tg.make_bidirectional_edge(u,v,w);\n\t}\n\t\
    auto tree = Tree<TreeOperator<long long>>::builder(g).root(0).parent().child().eulertour().build();\n\
    \tint M = tree.eulertour.size();\n\tvector<pair<long long,long long>> init(M,{0,0});\n\
    \tfor(int i=1;i<M;++i) {\n\t\tint l=tree.eulertour[i-1], r = tree.eulertour[i],\
    \ sgn;\n\t\tlong long w;\n\t\tif(tree.depth[l]<tree.depth[r]) {\n\t\t\tw = tree.parent[r].second;\n\
    \t\t\tsgn = 1;\n\t\t}\n\t\telse {\n\t\t\tw = tree.parent[l].second;\n\t\t\tsgn\
    \ = -1;\n\t\t}\n\t\tinit[i] = {w*sgn,sgn};\n\t}\n\tLazySegmentTree<NodeEulerTourSumRangeAdd<pair<long\
    \ long,long long>,long long>> seg(init);\n\tint Q; cin >> Q;\n\twhile(Q--) {\n\
    \t\tint q; cin >> q;\n\t\tint a; cin >> a;\n\t\tint l = tree.eulertour_range[a].first;\n\
    \t\tint r = tree.eulertour_range[a].second;\n\t\tif(q==1) {\n\t\t\tlong long x;\
    \ cin >> x;\n\t\t\tseg.update(l+1,r,x);\n\t\t}\n\t\telse {\n\t\t\tcout << seg.get(0,l+1).first\
    \ << endl;\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/900\"\n\n#include <vector>\n\
    #include <iostream>\n#include <cassert>\n#include <map>\n#include <algorithm>\n\
    #include <stack>\n#include <numeric>\n#include <array>\nusing namespace std;\n\
    #include \"../../lib/graph/Graph.cpp\"\n#include \"../../lib/graph/Tree.cpp\"\n\
    #include \"../../lib/segment/LazySegmentTree.cpp\"\n\n\n//node:\u7DCF\u548C\u3000\
    lazy:\u52A0\u7B97\ntemplate<class T, class U> struct NodeEulerTourSumRangeAdd\
    \ {\n\tusing TypeNode = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode\
    \ unit_node = {0,0};\n\tinline static constexpr TypeLazy unit_lazy = 0;\n\tinline\
    \ static constexpr TypeNode func_node(TypeNode l,TypeNode r){return {l.first+r.first,l.second+r.second};}\n\
    \tinline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return\
    \ old_lazy+new_lazy;}\n\tinline static constexpr TypeNode func_merge(TypeNode\
    \ node,TypeLazy lazy,int l, int r){return {node.first+node.second*lazy,node.second};}\n\
    \tinline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return\
    \ var <= nodeVal;}\n\t// LazySegmentTree<NodeSumRangeUpdate<ll,ll>> Seg(N,0);\n\
    };\n\n\nint main(void){\n\tint N; cin >> N;\n\tGraph<long long> g(N);\n\tfor(int\
    \ i=0;i<N-1;++i) {\n\t\tint u,v,w; cin >> u >> v >> w;\n\t\tg.make_bidirectional_edge(u,v,w);\n\
    \t}\n\tauto tree = Tree<TreeOperator<long long>>::builder(g).root(0).parent().child().eulertour().build();\n\
    \tint M = tree.eulertour.size();\n\tvector<pair<long long,long long>> init(M,{0,0});\n\
    \tfor(int i=1;i<M;++i) {\n\t\tint l=tree.eulertour[i-1], r = tree.eulertour[i],\
    \ sgn;\n\t\tlong long w;\n\t\tif(tree.depth[l]<tree.depth[r]) {\n\t\t\tw = tree.parent[r].second;\n\
    \t\t\tsgn = 1;\n\t\t}\n\t\telse {\n\t\t\tw = tree.parent[l].second;\n\t\t\tsgn\
    \ = -1;\n\t\t}\n\t\tinit[i] = {w*sgn,sgn};\n\t}\n\tLazySegmentTree<NodeEulerTourSumRangeAdd<pair<long\
    \ long,long long>,long long>> seg(init);\n\tint Q; cin >> Q;\n\twhile(Q--) {\n\
    \t\tint q; cin >> q;\n\t\tint a; cin >> a;\n\t\tint l = tree.eulertour_range[a].first;\n\
    \t\tint r = tree.eulertour_range[a].second;\n\t\tif(q==1) {\n\t\t\tlong long x;\
    \ cin >> x;\n\t\t\tseg.update(l+1,r,x);\n\t\t}\n\t\telse {\n\t\t\tcout << seg.get(0,l+1).first\
    \ << endl;\n\t\t}\n\t}\n\treturn 0;\n}"
  dependsOn:
  - lib/graph/Graph.cpp
  - lib/graph/Tree.cpp
  - lib/segment/LazySegmentTree.cpp
  isVerificationFile: true
  path: test/graph/Tree-eulertour.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 06:30:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/Tree-eulertour.test.cpp
layout: document
redirect_from:
- /verify/test/graph/Tree-eulertour.test.cpp
- /verify/test/graph/Tree-eulertour.test.cpp.html
title: test/graph/Tree-eulertour.test.cpp
---
