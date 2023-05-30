---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/10-segment-tree/LazySegmentTree.cpp
    title: "LazySegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u9045\u5EF6\u8A55\
      \u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: lib/40-graph/Graph.cpp
    title: Graph
  - icon: ':heavy_check_mark:'
    path: lib/40-graph/Tree.cpp
    title: "Tree - \u6728"
  - icon: ':heavy_check_mark:'
    path: lib/99-operator/monoid-lazy/MonoidRangeFoldEulerTourSumRangeOperateAdd.cpp
    title: "MonoidRangeEulerTourSumRangeAdd - fold:\u533A\u9593\u30AA\u30A4\u30E9\u30FC\
      \u30C4\u30A2\u30FC\u548C, operate:\u533A\u9593\u52A0\u7B97"
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
    \ <numeric>\n#include <array>\nusing namespace std;\n#line 1 \"lib/40-graph/Graph.cpp\"\
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
    \ yx){return yx.first*W+yx.second;}\n};\n#line 1 \"lib/40-graph/Tree.cpp\"\n/*\n\
    \ * @title Tree - \u6728\n * @docs md/graph/Tree.md\n */\ntemplate<class Operator>\
    \ class TreeBuilder;\ntemplate<class Operator> class Tree {\nprivate:\n    using\
    \ TypeEdge = typename Operator::TypeEdge;\n    size_t num;\n    size_t ord;\n\
    \    Graph<TypeEdge>& g;\n    friend TreeBuilder<Operator>;\n    Tree(Graph<TypeEdge>&\
    \ graph):\n            g(graph),\n            num(graph.size()),\n           \
    \ depth(graph.size(),-1),\n            order(graph.size()),\n            edge_dist(graph.size()){\n\
    \    }\n    //for make_depth\n    void dfs(int curr, int prev){\n        for(const\
    \ auto& e:g.edges[curr]){\n            const int& next = e.first;\n          \
    \  if(next==prev) continue;\n            depth[next] = depth[curr] + 1;\n    \
    \        edge_dist[next]  = Operator::func_edge_merge(edge_dist[curr],e.second);\n\
    \            dfs(next,curr);\n            order[ord++] = next;\n        }\n  \
    \  }\n    //for make_eulertour\n    void dfs(int from){\n        eulertour.push_back(from);\n\
    \        for(auto& e:child[from]){\n            int to = e.first;\n          \
    \  dfs(to);\n            eulertour.push_back(from);\n        }\n    }\n    void\
    \ make_root(const int root) {\n        depth[root] = 0;\n        edge_dist[root]\
    \ = Operator::unit_edge;\n        ord = 0;\n        dfs(root,-1);\n        order[ord++]\
    \ = root;\n        reverse_copy(order.begin(),order.end(),back_inserter(reorder));\n\
    \    }\n    void make_root() {\n        ord = 0;\n        for(int i=0;i<num;++i)\
    \ {\n            if(depth[i]!=-1) continue;\n            depth[i] = 0;\n     \
    \       edge_dist[i] = Operator::unit_edge;\n            dfs(i,-1);\n        \
    \    order[ord++] = i;\n        }\n        reverse_copy(order.begin(),order.end(),back_inserter(reorder));\n\
    \    }\n    void make_child(const int root = 0) {\n        child.resize(num);\n\
    \        for (size_t i = 0; i < num; ++i) for (auto& e : g.edges[i]) if (depth[i]\
    \ < depth[e.first]) child[i].push_back(e);\n    }\n    void make_subtree_size()\
    \ {\n        subtree_size.resize(num,1);\n        for (size_t i:order) for (auto\
    \ e : child[i]) subtree_size[i] += subtree_size[e.first];\n    }\n    void make_parent()\
    \ {\n        parent.resize(num,make_pair(num,Operator::unit_edge));\n        for\
    \ (size_t i = 0; i < num; ++i) for (auto& e : g.edges[i]) if (depth[i] > depth[e.first])\
    \ parent[i] = e;\n    }\n    void make_ancestor() {\n        ancestor.resize(num);\n\
    \        for (size_t i = 0; i < num; ++i) ancestor[i][0] = (parent[i].first!=num?parent[i]:make_pair(i,Operator::unit_lca_edge));\n\
    \        for (size_t j = 1; j < Operator::bit; ++j) {\n            for (size_t\
    \ i = 0; i < num; ++i) {\n                size_t k = ancestor[i][j - 1].first;\n\
    \                ancestor[i][j] = Operator::func_lca_edge_merge(ancestor[k][j\
    \ - 1],ancestor[i][j - 1]);\n            }\n        }\n    }\n    pair<size_t,TypeEdge>\
    \ lca_impl(size_t l, size_t r) {\n        if (depth[l] < depth[r]) swap(l, r);\n\
    \        int diff = depth[l] - depth[r];\n        auto ancl = make_pair(l,Operator::unit_lca_edge);\n\
    \        auto ancr = make_pair(r,Operator::unit_lca_edge);\n        for (int j\
    \ = 0; j < Operator::bit; ++j) {\n            if (diff & (1 << j)) ancl = Operator::func_lca_edge_merge(ancestor[ancl.first][j],ancl);\n\
    \        }\n        if(ancl.first==ancr.first) return ancl;\n        for (int\
    \ j = Operator::bit - 1; 0 <= j; --j) {\n            if(ancestor[ancl.first][j].first!=ancestor[ancr.first][j].first)\
    \ {\n                ancl = Operator::func_lca_edge_merge(ancestor[ancl.first][j],ancl);\n\
    \                ancr = Operator::func_lca_edge_merge(ancestor[ancr.first][j],ancr);\n\
    \            }\n        }\n        ancl = Operator::func_lca_edge_merge(ancestor[ancl.first][0],ancl);\n\
    \        ancr = Operator::func_lca_edge_merge(ancestor[ancr.first][0],ancr);\n\
    \        return Operator::func_lca_edge_merge(ancl,ancr);\n    }\n    pair<TypeEdge,vector<size_t>>\
    \ diameter_impl() {\n        Tree tree = Tree::builder(g).build();\n        size_t\
    \ root = 0;\n        {\n            tree.make_root(0);\n        }\n        root\
    \ = max_element(tree.edge_dist.begin(),tree.edge_dist.end()) - tree.edge_dist.begin();\n\
    \        {\n            tree.make_root(root);\n        }\n        size_t leaf\
    \ = max_element(tree.edge_dist.begin(),tree.edge_dist.end()) - tree.edge_dist.begin();\n\
    \        TypeEdge sz = tree.edge_dist[leaf];\n        vector<size_t> st;\n   \
    \     {\n            tree.make_parent();\n            while(leaf != root) {\n\
    \                st.push_back(leaf);\n                leaf = tree.parent[leaf].first;\n\
    \            }\n            st.push_back(root);\n        }\n        return make_pair(sz,st);\n\
    \    }\n    template<class TypeReroot> vector<TypeReroot> rerooting_impl(vector<TypeReroot>\
    \ rerootdp,vector<TypeReroot> rerootparent) {\n        for(size_t pa:order) for(auto&\
    \ e:child[pa]) rerootdp[pa] = Operator::func_reroot_dp(rerootdp[pa],rerootdp[e.first]);\n\
    \        for(size_t pa:reorder) {\n            if(depth[pa]) rerootdp[pa] = Operator::func_reroot_dp(rerootdp[pa],rerootparent[pa]);\n\
    \            size_t m = child[pa].size();\n            for(int j = 0; j < m &&\
    \ depth[pa]; ++j){\n                size_t ch = child[pa][j].first;\n        \
    \        rerootparent[ch] = Operator::func_reroot_dp(rerootparent[ch],rerootparent[pa]);\n\
    \            }\n            if(m <= 1) continue;\n            vector<TypeReroot>\
    \ l(m),r(m);\n            for(int j = 0; j < m; ++j) {\n                size_t\
    \ ch = child[pa][j].first;\n                l[j] = rerootdp[ch];\n           \
    \     r[j] = rerootdp[ch];\n            }\n            for(int j = 1; j+1 < m;\
    \ ++j) l[j] = Operator::func_reroot_merge(l[j],l[j-1]);\n            for(int j\
    \ = m-2; 0 <=j; --j) r[j] = Operator::func_reroot_merge(r[j],r[j+1]);\n      \
    \      size_t chl = child[pa].front().first;\n            size_t chr = child[pa].back().first;\n\
    \            rerootparent[chl] = Operator::func_reroot_dp(rerootparent[chl],r[1]);\n\
    \            rerootparent[chr] = Operator::func_reroot_dp(rerootparent[chr],l[m-2]);\n\
    \            for(int j = 1; j+1 < m; ++j) {\n                size_t ch = child[pa][j].first;\n\
    \                rerootparent[ch] = Operator::func_reroot_dp(rerootparent[ch],l[j-1]);\n\
    \                rerootparent[ch] = Operator::func_reroot_dp(rerootparent[ch],r[j+1]);\n\
    \            }\n        }\n        return rerootdp;\n    }\n    void make_eulertour()\
    \ {\n        dfs(reorder.front());\n        eulertour_range.resize(num);\n   \
    \     for(int i = 0; i < eulertour.size(); ++i) eulertour_range[eulertour[i]].second\
    \ = i+1;\n        for(int i = eulertour.size()-1; 0 <= i; --i) eulertour_range[eulertour[i]].first\
    \ = i;\n    }\n    void make_heavy_light_decomposition(){\n        head.resize(num);\n\
    \        hld.resize(num);\n        iota(head.begin(),head.end(),0);\n        for(size_t&\
    \ pa:reorder) {\n            pair<size_t,size_t> maxi = {0,num};\n           \
    \ for(auto& p:child[pa]) maxi = max(maxi,{subtree_size[p.first],p.first});\n \
    \           if(maxi.first) head[maxi.second] = head[pa];\n        }\n        stack<size_t>\
    \ st_head,st_sub;\n        size_t cnt = 0;\n        //\u6839\u306B\u8FD1\u3044\
    \u65B9\u304B\u3089\u63A2\u7D22\n        for(size_t& root:reorder){\n         \
    \   if(depth[root]) continue;\n            //\u6839\u3092push\n            st_head.push(root);\n\
    \            while(st_head.size()){\n                size_t h = st_head.top();\n\
    \                st_head.pop();\n                //\u90E8\u5206\u6728\u306E\u6839\
    \u3092push\n                st_sub.push(h);\n                while (st_sub.size()){\n\
    \                    size_t pa = st_sub.top();\n                    st_sub.pop();\n\
    \                    //\u90E8\u5206\u6728\u3092\u30AB\u30A6\u30F3\u30C8\u3057\u3066\
    \u3044\u304F\n                    hld[pa] = cnt++;\n                    //\u5B50\
    \u3092\u63A2\u7D22\n                    for(auto& p:child[pa]) {\n           \
    \             //\u5B50\u306Ehead\u304C\u89AA\u3068\u540C\u3058\u306A\u3089\u3001\
    \u305D\u306E\u307E\u307E\u9032\u3080\n                        if(head[p.first]==head[pa])\
    \ st_sub.push(p.first);\n                            //\u305D\u3046\u3058\u3083\
    \u306A\u3044\u5834\u5408\u306F\u3001\u305D\u3053\u304B\u3089\u65B0\u3057\u304F\
    \u90E8\u5206\u6728\u3068\u3057\u3066\u307F\u306A\u3059\n                     \
    \   else st_head.push(p.first);\n                    }\n                }\n  \
    \          }\n        }\n    }\n    //type 0: vertex, 1: edge\n    vector<pair<size_t,size_t>>\
    \ path_impl(size_t u,size_t v,int type = 0) {\n        vector<pair<size_t,size_t>>\
    \ path;\n        while(1){\n            if(hld[u]>hld[v]) swap(u,v);\n       \
    \     if(head[u]!=head[v]) {\n                path.push_back({hld[head[v]],hld[v]});\n\
    \                v=parent[head[v]].first;\n            }\n            else {\n\
    \                path.push_back({hld[u],hld[v]});\n                break;\n  \
    \          }\n        }\n        reverse(path.begin(),path.end());\n        if(type)\
    \ path.front().first++;\n        return path;\n    }\n    pair<vector<pair<size_t,size_t>>,vector<pair<size_t,size_t>>>\
    \ ordered_path_impl(size_t u,size_t v,int type = 0) {\n        vector<pair<size_t,size_t>>\
    \ path_lca_to_u;\n        vector<pair<size_t,size_t>> path_lca_to_v;\n       \
    \ while(1){\n            if(head[u] == head[v]) {\n                if(depth[u]\
    \ < depth[v]) path_lca_to_v.emplace_back(hld[u]+type,hld[v]);\n              \
    \  else path_lca_to_u.emplace_back(hld[v]+type,hld[u]);\n                break;\n\
    \            }\n            else if(hld[u] < hld[v]) {\n                path_lca_to_v.emplace_back(hld[head[v]],hld[v]);\n\
    \                v = parent[head[v]].first;\n            }\n            else if(hld[u]\
    \ > hld[v]) {\n                path_lca_to_u.emplace_back(hld[head[u]],hld[u]);\n\
    \                u = parent[head[u]].first;\n            }\n        }\n      \
    \  reverse(path_lca_to_v.begin(),path_lca_to_v.end());\n        return {path_lca_to_u,path_lca_to_v};\n\
    \    }\n    size_t lca_idx_impl(size_t u,size_t v){\n        while(1){\n     \
    \       if(hld[u]>hld[v]) swap(u,v);\n            if(head[u]==head[v]) return\
    \ u;\n            v=parent[head[v]].first;\n        }\n    }\n    vector<size_t>\
    \ head;\npublic:\n    vector<size_t> depth;\n    vector<size_t> order;\n    vector<size_t>\
    \ reorder;\n    vector<size_t> subtree_size;\n    vector<pair<size_t,TypeEdge>>\
    \ parent;\n    vector<vector<pair<size_t,TypeEdge>>> child;\n    vector<TypeEdge>\
    \ edge_dist;\n    vector<array<pair<size_t,TypeEdge>,Operator::bit>> ancestor;\n\
    \    vector<size_t> eulertour;\n    vector<pair<size_t,size_t>> eulertour_range;\n\
    \    vector<size_t> hld;\n\n    /**\n     * O(N) builder\n     */\n    static\
    \ TreeBuilder<Operator> builder(Graph<TypeEdge>& graph) { return TreeBuilder<Operator>(graph);}\n\
    \    /**\n     * O(logN) after make_ancestor\n     * return {lca,lca_dist} l and\
    \ r must be connected\n     */\n    pair<size_t,TypeEdge> lca(size_t l, size_t\
    \ r) {return lca_impl(l,r);}\n    /**\n     * O(N) anytime\n     * return {diameter\
    \ size,diameter set}\n     */\n    pair<TypeEdge,vector<size_t>> diameter(void){return\
    \ diameter_impl();}\n    /**\n     * O(N) after make_child\n     */\n    template<class\
    \ TypeReroot> vector<TypeReroot> rerooting(const vector<TypeReroot>& rerootdp,const\
    \ vector<TypeReroot>& rerootparent) {return rerooting_impl(rerootdp,rerootparent);}\n\
    \    /**\n     * O(logN)\n     */\n    vector<pair<size_t,size_t>> vertex_set_on_path(size_t\
    \ u, size_t v) {return path_impl(u,v,0);}\n    /**\n    /**\n     * O(logN)\n\
    \     */\n    vector<pair<size_t,size_t>> edge_set_on_path(size_t u, size_t v)\
    \ {return path_impl(u,v,1);}\n    /**\n     * O(logN)\n     * {lca to u path,lca\
    \ to v path}\n     */\n    pair<vector<pair<size_t,size_t>>,vector<pair<size_t,size_t>>>\
    \ vertex_ordered_set_on_path(size_t u, size_t v) {return ordered_path_impl(u,v,0);}\n\
    \    /**\n     * O(logN)\n     * {lca to u path,lca to v path}\n     */\n    pair<vector<pair<size_t,size_t>>,vector<pair<size_t,size_t>>>\
    \ edge_ordered_set_on_path(size_t u, size_t v) {return ordered_path_impl(u,v,1);}\n\
    \    /**\n     * O(logN) ancestor\u306Elca\u3088\u308A\u5B9A\u6570\u500D\u8EFD\
    \u3081\u3002idx\u3060\u3051\n     */\n    size_t lca_idx(size_t u, size_t v) {return\
    \ lca_idx_impl(u,v);}\n};\n\ntemplate<class Operator> class TreeBuilder {\n  \
    \  bool is_root_made =false;\n    bool is_child_made =false;\n    bool is_parent_made=false;\n\
    \    bool is_subtree_size_made=false;\npublic:\n    using TypeEdge = typename\
    \ Operator::TypeEdge;\n    TreeBuilder(Graph<TypeEdge>& g):tree(g){}\n    TreeBuilder&\
    \ root(const int rt) { is_root_made=true; tree.make_root(rt); return *this;}\n\
    \    TreeBuilder& root() { is_root_made=true; tree.make_root(); return *this;}\n\
    \    TreeBuilder& child() { assert(is_root_made); is_child_made=true;  tree.make_child();\
    \  return *this;}\n    TreeBuilder& parent() { assert(is_root_made); is_parent_made=true;\
    \ tree.make_parent(); return *this;}\n    TreeBuilder& subtree_size() { assert(is_child_made);\
    \ is_subtree_size_made=true; tree.make_subtree_size(); return *this;}\n    TreeBuilder&\
    \ ancestor() { assert(is_parent_made); tree.make_ancestor(); return *this;}\n\
    \    TreeBuilder& eulertour() { assert(is_child_made); tree.make_eulertour();\
    \ return *this;}\n    TreeBuilder& heavy_light_decomposition() { assert(is_subtree_size_made);\
    \ assert(is_parent_made); tree.make_heavy_light_decomposition(); return *this;}\n\
    \    Tree<Operator>&& build() {return move(tree);}\nprivate:\n    Tree<Operator>\
    \ tree;\n};\ntemplate<class T> struct TreeOperator{\n    using TypeEdge = T;\n\
    \    inline static constexpr size_t bit = 20;\n    inline static constexpr TypeEdge\
    \ unit_edge = 0;\n    inline static constexpr TypeEdge unit_lca_edge = 0;\n  \
    \  inline static constexpr TypeEdge func_edge_merge(const TypeEdge& parent,const\
    \ TypeEdge& w){return parent+w;}\n    inline static constexpr pair<size_t,TypeEdge>\
    \ func_lca_edge_merge(const pair<size_t,TypeEdge>& l,const pair<size_t,TypeEdge>&\
    \ r){return make_pair(l.first,l.second+r.second);}\n    template<class TypeReroot>\
    \ inline static constexpr TypeReroot func_reroot_dp(const TypeReroot& l,const\
    \ TypeReroot& r) {return {l.first+r.first+r.second,l.second+r.second};}\n    template<class\
    \ TypeReroot> inline static constexpr TypeReroot func_reroot_merge(const TypeReroot&\
    \ l,const TypeReroot& r) {return {l.first+r.first,l.second+r.second};}\n};\n//auto\
    \ tree = Tree<TreeOperator<int>>::builder(g).build();\n#line 1 \"lib/10-segment-tree/LazySegmentTree.cpp\"\
    \n/*\n * @title LazySegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u9045\u5EF6\
    \u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @docs md/segment-tree/LazySegmentTree.md\n\
    \ */\ntemplate<class Monoid> class LazySegmentTree {\n    using TypeNode = typename\
    \ Monoid::TypeNode;\n    using TypeLazy = typename Monoid::TypeLazy;\n    size_t\
    \ num;\n    size_t length;\n    size_t height;\n    vector<TypeNode> node;\n \
    \   vector<TypeLazy> lazy;\n    vector<pair<size_t,size_t>> range;\n\n    void\
    \ propagate(int k) {\n        if(lazy[k] == Monoid::unit_lazy) return;\n     \
    \   node[k] = Monoid::func_operate(node[k],lazy[k],range[k].first,range[k].second);\n\
    \        if(k < length) lazy[2*k+0] = Monoid::func_lazy(lazy[2*k+0],lazy[k]);\n\
    \        if(k < length) lazy[2*k+1] = Monoid::func_lazy(lazy[2*k+1],lazy[k]);\n\
    \        lazy[k] = Monoid::unit_lazy;\n    }\n\n    void build() {\n        for\
    \ (int i = length - 1; i >= 0; --i) node[i] = Monoid::func_fold(node[(i<<1)+0],node[(i<<1)+1]);\n\
    \        range.resize(2 * length);\n        for (int i = 0; i < length; ++i) range[i+length]\
    \ = make_pair(i,i+1);\n        for (int i = length - 1; i >= 0; --i) range[i]\
    \ = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n    }\npublic:\n\
    \n    //unit\u3067\u521D\u671F\u5316\n    LazySegmentTree(const size_t num) :\
    \ num(num) {\n        for (length = 1,height = 0; length <= num; length *= 2,\
    \ height++);\n        node.resize(2 * length, Monoid::unit_node);\n        lazy.resize(2\
    \ * length, Monoid::unit_lazy);\n        for (int i = 0; i < num; ++i) node[i\
    \ + length] = Monoid::unit_node;\n        build();\n    }\n\n    // //\u540C\u3058\
    init\u3067\u521D\u671F\u5316\n    LazySegmentTree(const size_t num, const TypeNode\
    \ init) : num(num) {\n        for (length = 1,height = 0; length <= num; length\
    \ *= 2, height++);\n        node.resize(2 * length, Monoid::unit_node);\n    \
    \    lazy.resize(2 * length, Monoid::unit_lazy);\n        for (int i = 0; i <\
    \ num; ++i) node[i + length] = init;\n        build();\n    }\n\n    //vector\u3067\
    \u521D\u671F\u5316\n    LazySegmentTree(const vector<TypeNode>& vec) : num(vec.size())\
    \ {\n        for (length = 1,height = 0; length <= vec.size(); length *= 2, height++);\n\
    \        node.resize(2 * length, Monoid::unit_node);\n        lazy.resize(2 *\
    \ length, Monoid::unit_lazy);\n        for (int i = 0; i < vec.size(); ++i) node[i\
    \ + length] = vec[i];\n        build();\n    }\n\n    //operate [a,b)\n    void\
    \ operate(int a, int b, TypeLazy x) {\n        int l = a + length, r = b + length\
    \ - 1;\n        for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r\
    \ >> i);\n        for(r++; l < r; l >>=1, r >>=1) {\n            if(l&1) lazy[l]\
    \ = Monoid::func_lazy(lazy[l],x), propagate(l),l++;\n            if(r&1) --r,lazy[r]\
    \ = Monoid::func_lazy(lazy[r],x), propagate(r);\n        }\n        l = a + length,\
    \ r = b + length - 1;\n        while ((l>>=1),(r>>=1),l) {\n            if(lazy[l]\
    \ == Monoid::unit_lazy) node[l] = Monoid::func_fold(Monoid::func_operate(node[(l<<1)+0],lazy[(l<<1)+0],range[(l<<1)+0].first,range[(l<<1)+0].second),Monoid::func_operate(node[(l<<1)+1],lazy[(l<<1)+1],range[(l<<1)+1].first,range[(l<<1)+1].second));\n\
    \            if(lazy[r] == Monoid::unit_lazy) node[r] = Monoid::func_fold(Monoid::func_operate(node[(r<<1)+0],lazy[(r<<1)+0],range[(r<<1)+0].first,range[(r<<1)+0].second),Monoid::func_operate(node[(r<<1)+1],lazy[(r<<1)+1],range[(r<<1)+1].first,range[(r<<1)+1].second));\n\
    \        }\n    }\n\n    //fold [a,b)\n    TypeNode fold(int a, int b) {\n   \
    \     int l = a + length, r = b + length - 1;\n        for (int i = height; 0\
    \ < i; --i) propagate(l >> i), propagate(r >> i);\n        TypeNode vl = Monoid::unit_node,\
    \ vr = Monoid::unit_node;\n        for(r++; l < r; l >>=1, r >>=1) {\n       \
    \     if(l&1) vl = Monoid::func_fold(vl,Monoid::func_operate(node[l],lazy[l],range[l].first,range[l].second)),l++;\n\
    \            if(r&1) r--,vr = Monoid::func_fold(Monoid::func_operate(node[r],lazy[r],range[r].first,range[r].second),vr);\n\
    \        }\n        return Monoid::func_fold(vl,vr);\n    }\n\n    //return [0,length]\n\
    \    int prefix_binary_search(TypeNode var) {\n        int l = length, r = 2*length\
    \ - 1;\n        for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r\
    \ >> i);\n        if(!Monoid::func_check(node[1],var)) return num;\n        TypeNode\
    \ ret = Monoid::unit_node;\n        size_t idx = 2;\n        for(; idx < 2*length;\
    \ idx<<=1){\n            if(!Monoid::func_check(Monoid::func_fold(ret,Monoid::func_operate(node[idx],lazy[idx],range[idx].first,range[idx].second)),var))\
    \ {\n                ret = Monoid::func_fold(ret,Monoid::func_operate(node[idx],lazy[idx],range[idx].first,range[idx].second));\n\
    \                idx++;\n            }\n        }\n        return min((idx>>1)\
    \ - length,num);\n    }\n\n    //range[l,r) return [l,r]\n    int binary_search(size_t\
    \ l, size_t r, TypeNode var) {\n        if (l < 0 || length <= l || r < 0 || length\
    \ < r) return -1;\n        for (int i = height; 0 < i; --i) propagate((l+length)\
    \ >> i), propagate((r+length-1) >> i);\n        TypeNode ret = Monoid::unit_node;\n\
    \        size_t off = l;\n        for(size_t idx = l+length; idx < 2*length &&\
    \ off < r; ){\n            if(range[idx].second<=r && !Monoid::func_check(Monoid::func_fold(ret,Monoid::func_operate(node[idx],lazy[idx],range[idx].first,range[idx].second)),var))\
    \ {\n                ret = Monoid::func_fold(ret,Monoid::func_operate(node[idx],lazy[idx],range[idx].first,range[idx].second));\n\
    \                off = range[idx++].second;\n                if(!(idx&1)) idx\
    \ >>= 1;\n            }\n            else{\n                idx <<=1;\n      \
    \      }\n        }\n        return off;\n    }\n\n    void print(){\n       \
    \ // cout << \"node\" << endl;\n        // for(int i = 1,j = 1; i < 2*length;\
    \ ++i) {\n        // \tcout << node[i] << \" \";\n        // \tif(i==((1<<j)-1)\
    \ && ++j) cout << endl;\n        // }\n        // cout << \"lazy\" << endl;\n\
    \        // for(int i = 1,j = 1; i < 2*length; ++i) {\n        // \tcout << lazy[i]\
    \ << \" \";\n        // \tif(i==((1<<j)-1) && ++j) cout << endl;\n        // }\n\
    \        cout << \"vector\" << endl;\n        cout << \"{ \" << fold(0,1);\n \
    \       for(int i = 1; i < length; ++i) cout << \", \" << fold(i,i+1);\n     \
    \   cout << \" }\" << endl;\n    }\n};\n#line 1 \"lib/99-operator/monoid-lazy/MonoidRangeFoldEulerTourSumRangeOperateAdd.cpp\"\
    \n/*\n * @title MonoidRangeEulerTourSumRangeAdd - fold:\u533A\u9593\u30AA\u30A4\
    \u30E9\u30FC\u30C4\u30A2\u30FC\u548C, operate:\u533A\u9593\u52A0\u7B97\n * @docs\
    \ md/operator/monoid-lazy/MonoidRangeEulerTourSumRangeAdd.md\n */\ntemplate<class\
    \ T, class U> struct MonoidRangeFoldEulerTourSumRangeOperateAdd {\n\tusing TypeNode\
    \ = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode unit_node =\
    \ {0,0};\n\tinline static constexpr TypeLazy unit_lazy = 0;\n\tinline static constexpr\
    \ TypeNode func_fold(TypeNode l,TypeNode r){return {l.first+r.first,l.second+r.second};}\n\
    \tinline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return\
    \ old_lazy+new_lazy;}\n\tinline static constexpr TypeNode func_operate(TypeNode\
    \ node,TypeLazy lazy,int l, int r){return {node.first+node.second*lazy,node.second};}\n\
    \tinline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return\
    \ var <= nodeVal;}\n\t// LazySegmentTree<NodeSumRangeUpdate<ll,ll>> Seg(N,0);\n\
    };\n#line 16 \"test/graph/Tree-eulertour.test.cpp\"\n\nint main(void){\n\tint\
    \ N; cin >> N;\n\tGraph<long long> g(N);\n\tfor(int i=0;i<N-1;++i) {\n\t\tint\
    \ u,v,w; cin >> u >> v >> w;\n\t\tg.make_bidirectional_edge(u,v,w);\n\t}\n\tauto\
    \ tree = Tree<TreeOperator<long long>>::builder(g).root(0).parent().child().eulertour().build();\n\
    \tint M = tree.eulertour.size();\n\tvector<pair<long long,long long>> init(M,{0,0});\n\
    \tfor(int i=1;i<M;++i) {\n\t\tint l=tree.eulertour[i-1], r = tree.eulertour[i],\
    \ sgn;\n\t\tlong long w;\n\t\tif(tree.depth[l]<tree.depth[r]) {\n\t\t\tw = tree.parent[r].second;\n\
    \t\t\tsgn = 1;\n\t\t}\n\t\telse {\n\t\t\tw = tree.parent[l].second;\n\t\t\tsgn\
    \ = -1;\n\t\t}\n\t\tinit[i] = {w*sgn,sgn};\n\t}\n\tLazySegmentTree<MonoidRangeFoldEulerTourSumRangeOperateAdd<pair<long\
    \ long,long long>,long long>> seg(init);\n\tint Q; cin >> Q;\n\twhile(Q--) {\n\
    \t\tint q; cin >> q;\n\t\tint a; cin >> a;\n\t\tint l = tree.eulertour_range[a].first;\n\
    \t\tint r = tree.eulertour_range[a].second;\n\t\tif(q==1) {\n\t\t\tlong long x;\
    \ cin >> x;\n\t\t\tseg.operate(l+1,r,x);\n\t\t}\n\t\telse {\n\t\t\tcout << seg.fold(0,l+1).first\
    \ << endl;\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/900\"\n\n#include <vector>\n\
    #include <iostream>\n#include <cassert>\n#include <map>\n#include <algorithm>\n\
    #include <stack>\n#include <numeric>\n#include <array>\nusing namespace std;\n\
    #include \"../../lib/40-graph/Graph.cpp\"\n#include \"../../lib/40-graph/Tree.cpp\"\
    \n#include \"../../lib/10-segment-tree/LazySegmentTree.cpp\"\n#include \"../../lib/99-operator/monoid-lazy/MonoidRangeFoldEulerTourSumRangeOperateAdd.cpp\"\
    \n\nint main(void){\n\tint N; cin >> N;\n\tGraph<long long> g(N);\n\tfor(int i=0;i<N-1;++i)\
    \ {\n\t\tint u,v,w; cin >> u >> v >> w;\n\t\tg.make_bidirectional_edge(u,v,w);\n\
    \t}\n\tauto tree = Tree<TreeOperator<long long>>::builder(g).root(0).parent().child().eulertour().build();\n\
    \tint M = tree.eulertour.size();\n\tvector<pair<long long,long long>> init(M,{0,0});\n\
    \tfor(int i=1;i<M;++i) {\n\t\tint l=tree.eulertour[i-1], r = tree.eulertour[i],\
    \ sgn;\n\t\tlong long w;\n\t\tif(tree.depth[l]<tree.depth[r]) {\n\t\t\tw = tree.parent[r].second;\n\
    \t\t\tsgn = 1;\n\t\t}\n\t\telse {\n\t\t\tw = tree.parent[l].second;\n\t\t\tsgn\
    \ = -1;\n\t\t}\n\t\tinit[i] = {w*sgn,sgn};\n\t}\n\tLazySegmentTree<MonoidRangeFoldEulerTourSumRangeOperateAdd<pair<long\
    \ long,long long>,long long>> seg(init);\n\tint Q; cin >> Q;\n\twhile(Q--) {\n\
    \t\tint q; cin >> q;\n\t\tint a; cin >> a;\n\t\tint l = tree.eulertour_range[a].first;\n\
    \t\tint r = tree.eulertour_range[a].second;\n\t\tif(q==1) {\n\t\t\tlong long x;\
    \ cin >> x;\n\t\t\tseg.operate(l+1,r,x);\n\t\t}\n\t\telse {\n\t\t\tcout << seg.fold(0,l+1).first\
    \ << endl;\n\t\t}\n\t}\n\treturn 0;\n}"
  dependsOn:
  - lib/40-graph/Graph.cpp
  - lib/40-graph/Tree.cpp
  - lib/10-segment-tree/LazySegmentTree.cpp
  - lib/99-operator/monoid-lazy/MonoidRangeFoldEulerTourSumRangeOperateAdd.cpp
  isVerificationFile: true
  path: test/graph/Tree-eulertour.test.cpp
  requiredBy: []
  timestamp: '2023-05-31 02:01:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/Tree-eulertour.test.cpp
layout: document
redirect_from:
- /verify/test/graph/Tree-eulertour.test.cpp
- /verify/test/graph/Tree-eulertour.test.cpp.html
title: test/graph/Tree-eulertour.test.cpp
---
