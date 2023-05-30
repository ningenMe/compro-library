---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-diameter.test.cpp
    title: test/graph/Tree-diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-eulertour.test.cpp
    title: test/graph/Tree-eulertour.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-hld-path.test.cpp
    title: test/graph/Tree-hld-path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-hld-vertex-1.test.cpp
    title: test/graph/Tree-hld-vertex-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-hld-vertex-2.test.cpp
    title: test/graph/Tree-hld-vertex-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-hld-vertex-3.test.cpp
    title: test/graph/Tree-hld-vertex-3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-lca-idx.test.cpp
    title: test/graph/Tree-lca-idx.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-lca.test.cpp
    title: test/graph/Tree-lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-parent.test.cpp
    title: test/graph/Tree-parent.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-rerooting.test.cpp
    title: test/graph/Tree-rerooting.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-size.test.cpp
    title: test/graph/Tree-size.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/graph/Tree.md
    document_title: "Tree - \u6728"
    links: []
  bundledCode: "#line 1 \"lib/40-graph/Tree.cpp\"\n/*\n * @title Tree - \u6728\n *\
    \ @docs md/graph/Tree.md\n */\ntemplate<class Operator> class TreeBuilder;\ntemplate<class\
    \ Operator> class Tree {\nprivate:\n    using TypeEdge = typename Operator::TypeEdge;\n\
    \    size_t num;\n    size_t ord;\n    Graph<TypeEdge>& g;\n    friend TreeBuilder<Operator>;\n\
    \    Tree(Graph<TypeEdge>& graph):\n            g(graph),\n            num(graph.size()),\n\
    \            depth(graph.size(),-1),\n            order(graph.size()),\n     \
    \       edge_dist(graph.size()){\n    }\n    //for make_depth\n    void dfs(int\
    \ curr, int prev){\n        for(const auto& e:g.edges[curr]){\n            const\
    \ int& next = e.first;\n            if(next==prev) continue;\n            depth[next]\
    \ = depth[curr] + 1;\n            edge_dist[next]  = Operator::func_edge_merge(edge_dist[curr],e.second);\n\
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
    \ tree = Tree<TreeOperator<int>>::builder(g).build();\n"
  code: "/*\n * @title Tree - \u6728\n * @docs md/graph/Tree.md\n */\ntemplate<class\
    \ Operator> class TreeBuilder;\ntemplate<class Operator> class Tree {\nprivate:\n\
    \    using TypeEdge = typename Operator::TypeEdge;\n    size_t num;\n    size_t\
    \ ord;\n    Graph<TypeEdge>& g;\n    friend TreeBuilder<Operator>;\n    Tree(Graph<TypeEdge>&\
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
    \ tree = Tree<TreeOperator<int>>::builder(g).build();"
  dependsOn: []
  isVerificationFile: false
  path: lib/40-graph/Tree.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:49:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/Tree-diameter.test.cpp
  - test/graph/Tree-lca-idx.test.cpp
  - test/graph/Tree-eulertour.test.cpp
  - test/graph/Tree-rerooting.test.cpp
  - test/graph/Tree-hld-path.test.cpp
  - test/graph/Tree-hld-vertex-3.test.cpp
  - test/graph/Tree-hld-vertex-2.test.cpp
  - test/graph/Tree-lca.test.cpp
  - test/graph/Tree-size.test.cpp
  - test/graph/Tree-parent.test.cpp
  - test/graph/Tree-hld-vertex-1.test.cpp
documentation_of: lib/40-graph/Tree.cpp
layout: document
redirect_from:
- /library/lib/40-graph/Tree.cpp
- /library/lib/40-graph/Tree.cpp.html
title: "Tree - \u6728"
---
### Tree
- 木ライブラリ
  - 根つき木
    - dfsしてトポロジカルソート順を列挙
    - 根からの辺の累積和を列挙
    - 子頂点を列挙
    - 親頂点を列挙
  - lca
    - 祖先をダブリングで列挙
    - lca(最小共通祖先)を取得できる
    - lcaまでの辺の累積和を取得できる
  - 直径
    - 直径の大きさ、頂点集合を列挙
  - オイラーツアー
    - オイラーツアー順を列挙
    - オイラーツアー上の、ある頂点を根とした部分木の範囲を列挙
  - heavy-light分解
    - hld順を列挙
    - 木のパス上における頂点集合を縮約した形で取得できる
    - 木のパス上における頂点集合を、順序付きで縮約した形で取得できる
    - 木のパス上における辺集合を縮約した形で取得できる
    - 木のパス上における辺集合を、順序付きで縮約した形で取得できる
    - lcaを取得できる
  - 全方位木dpの抽象化

### コンストラクタ
- なし。ビルダーを用意している。  
下記のように、グラフを最初に渡し、前計算したいものを指定してビルドを行う。
```
auto tree = Tree<TreeOperator<int>>::builder(g).root(0).child().parent().build();
```

### メソッド
- いつか書く

### TODO
- 辺/頂点lcaの演算のverify
- hldの順序付きの辺集合のverify
- hldのlcaのverify