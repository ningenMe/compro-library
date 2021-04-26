---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data-structure/segment-tree/SegmentTree.cpp
    title: "SegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u30BB\u30B0\u30E1\u30F3\
      \u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: lib/graph/Graph.cpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: lib/graph/Tree.cpp
    title: "Tree - \u6728"
  - icon: ':heavy_check_mark:'
    path: lib/operator/monoid/MonoidRangeSumPointAdd.cpp
    title: "MonoidRangeSumPointAdd - [\u533A\u9593\u548C, \u4E00\u70B9\u66F4\u65B0\
      ]"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/graph/Tree-hld-vertex-2.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\n#include <vector>\n\
    #include <iostream>\n#include <cassert>\n#include <map>\n#include <algorithm>\n\
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
    \ yx){return yx.first*W+yx.second;}\n};\n#line 1 \"lib/graph/Tree.cpp\"\n/*\n\
    \ * @title Tree - \u6728\n * @docs md/graph/Tree.md\n */\ntemplate<class Operator>\
    \ class TreeBuilder;\ntemplate<class Operator> class Tree {\nprivate:\n\tusing\
    \ TypeEdge = typename Operator::TypeEdge;\n\tsize_t num;\n\tsize_t ord;\n\tGraph<TypeEdge>&\
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
    };\n//auto tree = Tree<TreeOperator<int>>::builder(g).build();\n#line 1 \"lib/data-structure/segment-tree/SegmentTree.cpp\"\
    \n/*\n * @title SegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\n * @docs md/data-structure/segment-tree/SegmentTree.md\n\
    \ */\ntemplate<class Monoid> class SegmentTree {\n    using TypeNode = typename\
    \ Monoid::TypeNode; \n    size_t length;\n    size_t num;\n    vector<TypeNode>\
    \ node;\n    vector<pair<int,int>> range;\n    inline void build() {\n       \
    \ for (int i = length - 1; i >= 0; --i) node[i] = Monoid::func_fold(node[(i<<1)+0],node[(i<<1)+1]);\n\
    \        range.resize(2 * length);\n        for (int i = 0; i < length; ++i) range[i+length]\
    \ = make_pair(i,i+1);\n        for (int i = length - 1; i >= 0; --i) range[i]\
    \ = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n    }\npublic:\n\
    \n    //unit\u3067\u521D\u671F\u5316\n    SegmentTree(const size_t num): num(num)\
    \ {\n        for (length = 1; length <= num; length *= 2);\n        node.resize(2\
    \ * length, Monoid::unit_node);\n        build();\n    }\n\n    //vector\u3067\
    \u521D\u671F\u5316\n    SegmentTree(const vector<TypeNode> & vec) : num(vec.size())\
    \ {\n        for (length = 1; length <= vec.size(); length *= 2);\n        node.resize(2\
    \ * length, Monoid::unit_node);\n        for (int i = 0; i < vec.size(); ++i)\
    \ node[i + length] = vec[i];\n        build();\n    }\n \n    //\u540C\u3058init\u3067\
    \u521D\u671F\u5316\n    SegmentTree(const size_t num, const TypeNode init) : num(num)\
    \ {\n        for (length = 1; length <= num; length *= 2);\n        node.resize(2\
    \ * length, Monoid::unit_node);\n        for (int i = 0; i < length; ++i) node[i+length]\
    \ = init;\n        build();\n    }\n    \n    //[idx,idx+1)\n    void operate(size_t\
    \ idx, const TypeNode var) {\n        if(idx < 0 || length <= idx) return;\n \
    \       idx += length;\n        node[idx] = Monoid::func_operate(node[idx],var);\n\
    \        while(idx >>= 1) node[idx] = Monoid::func_fold(node[(idx<<1)+0],node[(idx<<1)+1]);\n\
    \    }\n\n    //[l,r)\n    TypeNode fold(int l, int r) {\n        if (l < 0 ||\
    \ length <= l || r < 0 || length < r) return Monoid::unit_node;\n        TypeNode\
    \ vl = Monoid::unit_node, vr = Monoid::unit_node;\n        for(l += length, r\
    \ += length; l < r; l >>=1, r >>=1) {\n            if(l&1) vl = Monoid::func_fold(vl,node[l++]);\n\
    \            if(r&1) vr = Monoid::func_fold(node[--r],vr);\n        }\n      \
    \  return Monoid::func_fold(vl,vr);\n    }\n\n    //range[l,r) return [l,r] search\
    \ max right\n    int prefix_binary_search(int l, int r, TypeNode var) {\n    \
    \    assert(0 <= l && l < length && 0 < r && r <= length);\n        TypeNode ret\
    \ = Monoid::unit_node;\n        size_t off = l;\n        for(size_t idx = l+length;\
    \ idx < 2*length && off < r; ){\n            if(range[idx].second<=r && !Monoid::func_check(Monoid::func_fold(ret,node[idx]),var))\
    \ {\n                ret = Monoid::func_fold(ret,node[idx]);\n               \
    \ off = range[idx++].second;\n                if(!(idx&1)) idx >>= 1;\t\t\t\n\
    \            }\n            else{\n                idx <<=1;\n            }\n\
    \        }\n        return off;\n    }\n\n    //range(l,r] return [l,r] search\
    \ max left\n    int suffix_binary_search(const int l, const int r, const TypeNode\
    \ var) {\n        assert(-1 <= l && l < (int)length-1 && 0 <= r && r < length);\n\
    \        TypeNode ret = Monoid::unit_node;\n        int off = r;\n        for(size_t\
    \ idx = r+length; idx < 2*length && l < off; ){\n            if(l < range[idx].first\
    \ && !Monoid::func_check(Monoid::func_fold(node[idx],ret),var)) {\n          \
    \      ret = Monoid::func_fold(node[idx],ret);\n                off = range[idx--].first-1;\n\
    \                if(idx&1) idx >>= 1;\n            }\n            else{\n    \
    \            idx = (idx<<1)+1;\n            }\n        }\n        return off;\n\
    \    }\n\n    void print(){\n        // cout << \"node\" << endl;\n        //\
    \ for(int i = 1,j = 1; i < 2*length; ++i) {\n        // \tcout << node[i] << \"\
    \ \";\n        // \tif(i==((1<<j)-1) && ++j) cout << endl;\n        // }\n   \
    \     cout << \"vector\" << endl;\n        cout << \"{ \" << fold(0,1);\n    \
    \    for(int i = 1; i < length; ++i) cout << \", \" << fold(i,i+1);\n        cout\
    \ << \" }\" << endl;\n    }\n};\n#line 1 \"lib/operator/monoid/MonoidRangeSumPointAdd.cpp\"\
    \n/*\n * @title MonoidRangeSumPointAdd - [\u533A\u9593\u548C, \u4E00\u70B9\u66F4\
    \u65B0]\n * @docs md/operator/monoid/MonoidRangeSumPointAdd.md\n */\ntemplate<class\
    \ T> struct MonoidRangeSumPointAdd {\n    using TypeNode = T;\n    inline static\
    \ constexpr TypeNode unit_node = 0;\n    inline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return l+r;}\n    inline static constexpr TypeNode func_operate(TypeNode\
    \ l,TypeNode r){return l+r;}\n    inline static constexpr bool func_check(TypeNode\
    \ nodeVal,TypeNode var){return var == nodeVal;}\n};\n#line 16 \"test/graph/Tree-hld-vertex-2.test.cpp\"\
    \n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n\tint N,Q; cin\
    \ >> N >> Q;\n\tGraph<int> g(N);\n\tvector<long long> a(N);\n\tfor(int i=0;i<N;++i)\
    \ cin >> a[i];\n\tfor(int i=0;i<(N-1);++i){\n\t\tint u,v; cin >> u >> v;\n\t\t\
    g.make_bidirectional_edge(u,v,1);\n\t}\n\tauto tree = Tree<TreeOperator<int>>::builder(g).root(0).parent().child().subtree_size().heavy_light_decomposition().build();\n\
    \tSegmentTree<MonoidRangeSumPointAdd<long long>> seg(N);\n\tfor(int i=0;i<N;++i)\
    \ seg.operate(tree.hld[i],a[i]);\n\twhile(Q--){\n\t\tint q,s,t; cin >> q >> s\
    \ >> t;\n\t\tif(q) {\n\t\t\tlong long ans=0;\n\t\t\tauto v = tree.vertex_set_on_path(s,t);\n\
    \t\t\tfor(auto& e:v) ans += seg.fold(e.first,e.second+1);\n\t\t\tcout << ans <<\
    \ endl;\n\t\t}\n\t\telse {\n\t\t\tseg.operate(tree.hld[s],t);\n\t\t}\n\t}\n  \
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <map>\n\
    #include <algorithm>\n#include <stack>\n#include <numeric>\n#include <array>\n\
    using namespace std;\n#include \"../../lib/graph/Graph.cpp\"\n#include \"../../lib/graph/Tree.cpp\"\
    \n#include \"../../lib/data-structure/segment-tree/SegmentTree.cpp\"\n#include\
    \ \"../../lib/operator/monoid/MonoidRangeSumPointAdd.cpp\"\n\nint main(void){\n\
    \    cin.tie(0);ios::sync_with_stdio(false);\n\tint N,Q; cin >> N >> Q;\n\tGraph<int>\
    \ g(N);\n\tvector<long long> a(N);\n\tfor(int i=0;i<N;++i) cin >> a[i];\n\tfor(int\
    \ i=0;i<(N-1);++i){\n\t\tint u,v; cin >> u >> v;\n\t\tg.make_bidirectional_edge(u,v,1);\n\
    \t}\n\tauto tree = Tree<TreeOperator<int>>::builder(g).root(0).parent().child().subtree_size().heavy_light_decomposition().build();\n\
    \tSegmentTree<MonoidRangeSumPointAdd<long long>> seg(N);\n\tfor(int i=0;i<N;++i)\
    \ seg.operate(tree.hld[i],a[i]);\n\twhile(Q--){\n\t\tint q,s,t; cin >> q >> s\
    \ >> t;\n\t\tif(q) {\n\t\t\tlong long ans=0;\n\t\t\tauto v = tree.vertex_set_on_path(s,t);\n\
    \t\t\tfor(auto& e:v) ans += seg.fold(e.first,e.second+1);\n\t\t\tcout << ans <<\
    \ endl;\n\t\t}\n\t\telse {\n\t\t\tseg.operate(tree.hld[s],t);\n\t\t}\n\t}\n  \
    \  return 0;\n}"
  dependsOn:
  - lib/graph/Graph.cpp
  - lib/graph/Tree.cpp
  - lib/data-structure/segment-tree/SegmentTree.cpp
  - lib/operator/monoid/MonoidRangeSumPointAdd.cpp
  isVerificationFile: true
  path: test/graph/Tree-hld-vertex-2.test.cpp
  requiredBy: []
  timestamp: '2021-04-26 17:56:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/Tree-hld-vertex-2.test.cpp
layout: document
redirect_from:
- /verify/test/graph/Tree-hld-vertex-2.test.cpp
- /verify/test/graph/Tree-hld-vertex-2.test.cpp.html
title: test/graph/Tree-hld-vertex-2.test.cpp
---
