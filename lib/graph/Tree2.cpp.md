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
    path: test/graph/Tree-hld-vertex.test.cpp
    title: test/graph/Tree-hld-vertex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-lca.test.cpp
    title: test/graph/Tree-lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-parent.test.cpp
    title: test/graph/Tree-parent.test.cpp
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
  bundledCode: "#line 1 \"lib/graph/Tree2.cpp\"\n/*\n * @title Tree - \u6728\n * @docs\
    \ md/graph/Tree.md\n */\ntemplate<class Operator> class TreeBuilder;\ntemplate<class\
    \ Operator> class Tree {\n\tusing TypeEdge = typename Operator::TypeEdge;\n\t\
    size_t num;\n\tsize_t ord;\n\tGraph<TypeEdge>& g;\n\tfriend TreeBuilder<Operator>;\n\
    \tTree(Graph<TypeEdge>& graph):\n\t\tg(graph),\n\t\tnum(graph.size()),\n\t\tdepth(graph.size(),-1),\n\
    \t\torder(graph.size()),\n\t\tedge_dist(graph.size()){\n\t}\n\t//for make_depth\n\
    \tvoid dfs(int curr, int prev){\n\t\tfor(const auto& e:g.edges[curr]){\n\t\t\t\
    const int& next = e.first;\n\t\t\tif(next==prev) continue;\n\t\t\tdepth[next]\
    \ = depth[curr] + 1;\n\t\t\tedge_dist[next]  = Operator::func_edge_merge(edge_dist[curr],e.second);\n\
    \t\t\tdfs(next,curr);\n\t\t\torder[ord++] = next;\n\t\t}\n\t}\n\t//for make_eulertour\n\
    \tvoid dfs(int from){\n\t\teulertour.push_back(from);\n\t\tfor(auto& e:child[from]){\n\
    \t\t\tint to = e.first;            \n\t\t\tdfs(to);        \n\t\t\teulertour.push_back(from);\n\
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
    \ path.front().first++;\n\t\treturn path;\n\t}\n\tsize_t lca_idx_impl(size_t u,size_t\
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
    \ {return rerooting_impl(rerootdp,rerootparent);}\n\t/**\n\t * O(logN) \n\t *\
    \ lca(u,v)=u \u3042\u308B\u3044\u306F lca(u,v)=v \u306E\u3068\u304D\u306F\u3001\
    \u6839\u5074\u304B\u3089\u9806\u65B9\u5411\u30D1\u30B9\u3092\u8FD4\u3057\u3066\
    \u304F\u308C\u308B \n\t */\n\tvector<pair<size_t,size_t>> vertex_set_on_path(size_t\
    \ u, size_t v) {return path_impl(u,v,0);}\n\t/**\n\t/**\n\t * O(logN) \n\t * lca(u,v)=u\
    \ \u3042\u308B\u3044\u306F lca(u,v)=v \u306E\u3068\u304D\u306F\u3001\u6839\u5074\
    \u304B\u3089\u9806\u65B9\u5411\u30D1\u30B9\u3092\u8FD4\u3057\u3066\u304F\u308C\
    \u308B \n\t */\n\tvector<pair<size_t,size_t>> edge_set_on_path(size_t u, size_t\
    \ v) {return path_impl(u,v,1);}\n\t/**\n\t * O(logN) ancestor\u306Elca\u3088\u308A\
    \u5B9A\u6570\u500D\u8EFD\u3081\u3002idx\u3060\u3051\n\t */\n\tsize_t lca_idx(size_t\
    \ u, size_t v) {return lca_idx_impl(u,v);}\n};\n \ntemplate<class Operator> class\
    \ TreeBuilder {\n\tbool is_root_made =false;\n\tbool is_child_made =false;\n\t\
    bool is_parent_made=false;\n\tbool is_subtree_size_made=false;\npublic:\n\tusing\
    \ TypeEdge = typename Operator::TypeEdge;\n\tTreeBuilder(Graph<TypeEdge>& g):tree(g){}\n\
    \tTreeBuilder& root(const int rt) { is_root_made=true; tree.make_root(rt); return\
    \ *this;}\n\tTreeBuilder& root() { is_root_made=true; tree.make_root(); return\
    \ *this;}\n\tTreeBuilder& child() { assert(is_root_made); is_child_made=true;\
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
    };\n//auto tree = Tree<TreeOperator<int>>::builder(g).build();\n"
  code: "/*\n * @title Tree - \u6728\n * @docs md/graph/Tree.md\n */\ntemplate<class\
    \ Operator> class TreeBuilder;\ntemplate<class Operator> class Tree {\n\tusing\
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
    \ path.front().first++;\n\t\treturn path;\n\t}\n\tsize_t lca_idx_impl(size_t u,size_t\
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
    \ {return rerooting_impl(rerootdp,rerootparent);}\n\t/**\n\t * O(logN) \n\t *\
    \ lca(u,v)=u \u3042\u308B\u3044\u306F lca(u,v)=v \u306E\u3068\u304D\u306F\u3001\
    \u6839\u5074\u304B\u3089\u9806\u65B9\u5411\u30D1\u30B9\u3092\u8FD4\u3057\u3066\
    \u304F\u308C\u308B \n\t */\n\tvector<pair<size_t,size_t>> vertex_set_on_path(size_t\
    \ u, size_t v) {return path_impl(u,v,0);}\n\t/**\n\t/**\n\t * O(logN) \n\t * lca(u,v)=u\
    \ \u3042\u308B\u3044\u306F lca(u,v)=v \u306E\u3068\u304D\u306F\u3001\u6839\u5074\
    \u304B\u3089\u9806\u65B9\u5411\u30D1\u30B9\u3092\u8FD4\u3057\u3066\u304F\u308C\
    \u308B \n\t */\n\tvector<pair<size_t,size_t>> edge_set_on_path(size_t u, size_t\
    \ v) {return path_impl(u,v,1);}\n\t/**\n\t * O(logN) ancestor\u306Elca\u3088\u308A\
    \u5B9A\u6570\u500D\u8EFD\u3081\u3002idx\u3060\u3051\n\t */\n\tsize_t lca_idx(size_t\
    \ u, size_t v) {return lca_idx_impl(u,v);}\n};\n \ntemplate<class Operator> class\
    \ TreeBuilder {\n\tbool is_root_made =false;\n\tbool is_child_made =false;\n\t\
    bool is_parent_made=false;\n\tbool is_subtree_size_made=false;\npublic:\n\tusing\
    \ TypeEdge = typename Operator::TypeEdge;\n\tTreeBuilder(Graph<TypeEdge>& g):tree(g){}\n\
    \tTreeBuilder& root(const int rt) { is_root_made=true; tree.make_root(rt); return\
    \ *this;}\n\tTreeBuilder& root() { is_root_made=true; tree.make_root(); return\
    \ *this;}\n\tTreeBuilder& child() { assert(is_root_made); is_child_made=true;\
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
    };\n//auto tree = Tree<TreeOperator<int>>::builder(g).build();"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/Tree2.cpp
  requiredBy: []
  timestamp: '2021-04-23 04:44:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/Tree-hld-vertex.test.cpp
  - test/graph/Tree-eulertour.test.cpp
  - test/graph/Tree-hld-path.test.cpp
  - test/graph/Tree-diameter.test.cpp
  - test/graph/Tree-size.test.cpp
  - test/graph/Tree-lca.test.cpp
  - test/graph/Tree-parent.test.cpp
documentation_of: lib/graph/Tree2.cpp
layout: document
redirect_from:
- /library/lib/graph/Tree2.cpp
- /library/lib/graph/Tree2.cpp.html
title: "Tree - \u6728"
---
##### api
- Tree(const int num)  
    - コンストラクタ
        - num: 頂点数
