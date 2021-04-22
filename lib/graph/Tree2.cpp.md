---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/graph/Tree.md
    document_title: "Tree - \u6728"
    links: []
  bundledCode: "#line 1 \"lib/graph/Tree2.cpp\"\n/*\n * @title Tree - \u6728\n * @docs\
    \ md/graph/Tree.md\n */\ntemplate<class Operator> class TreeBuilder;\ntemplate<class\
    \ Operator> class Tree {\n\tusing TypeEdge = typename Operator::TypeEdge;\n\t\
    size_t num;\n\tsize_t ord;\n\tGraph<TypeEdge>& g;\n\tfriend TreeBuilder<Operator>;\n\
    \t/**\n\t * constructor\n\t * O(N) \n\t */\n\tTree(Graph<TypeEdge>& graph):\n\t\
    \tg(graph),\n\t\tnum(graph.size()),\n\t\tdepth(graph.size(),-1),\n\t\torder(graph.size()),\n\
    \t\tedge_dist(graph.size()){\n\t}\n\t//for make_depth\n\tvoid dfs(int curr, int\
    \ prev){\n\t\tfor(const auto& e:g.edges[curr]){\n\t\t\tconst int& next = e.first;\n\
    \t\t\tif(next==prev) continue;\n\t\t\tdepth[next] = depth[curr] + 1;\n\t\t\tedge_dist[next]\
    \  = Operator::func_edge_merge(edge_dist[curr],e.second);\n\t\t\tdfs(next,curr);\n\
    \t\t\torder[ord++] = next;\n\t\t}\n\t}\n\t/**\n\t * \u5BDD\u4ED8\u304D\u6728\u3092\
    \u4F5C\u308B\n\t * O(N) you can use anytime\n\t */\n\tvoid make_root(const int\
    \ root) {\n\t\tdepth[root] = 0;\n\t\tedge_dist[root] = Operator::unit_edge;\n\t\
    \tord = 0;\n\t\tdfs(root,-1);\n\t\torder[ord++] = root;\n\t\treverse_copy(order.begin(),order.end(),back_inserter(reorder));\n\
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
    \t}\n\t\treturn make_pair(sz,st);\n\t}\npublic:\n\tvector<size_t> depth;\n\tvector<size_t>\
    \ order;\n\tvector<size_t> reorder;\n\tvector<size_t> subtree_size;\n\tvector<pair<size_t,TypeEdge>>\
    \ parent;\n\tvector<vector<pair<size_t,TypeEdge>>> child;\n\tvector<TypeEdge>\
    \ edge_dist;\n\tvector<array<pair<size_t,TypeEdge>,Operator::bit>> ancestor;\n\
    \ \n\t/**\n\t * O(N) builder\n\t */\n\tstatic TreeBuilder<Operator> builder(Graph<TypeEdge>&\
    \ graph) { return TreeBuilder<Operator>(graph);}\n\t/**\n\t * O(logN) after make_ancestor\n\
    \t * return {lca,lca_dist} l and r must be connected \n\t */\n\tpair<size_t,TypeEdge>\
    \ lca(size_t l, size_t r) {return lca_impl(l,r);}\n\t/**\n\t * O(N) anytime\n\t\
    \ * return {diameter size,diameter set} \n\t */\n\tpair<TypeEdge,vector<size_t>>\
    \ diameter(void){return diameter_impl();}\n};\n \ntemplate<class Operator> class\
    \ TreeBuilder {\n\tbool is_root_made =false;\n\tbool is_child_made =false;\n\t\
    bool is_parent_made=false;\npublic:\n\tusing TypeEdge = typename Operator::TypeEdge;\n\
    \tTreeBuilder(Graph<TypeEdge>& g):tree(g){}\n\tTreeBuilder& root(const int rt)\
    \ { is_root_made=true; tree.make_root(rt); return *this;}\n\tTreeBuilder& child()\
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
    \ r){return make_pair(l.first,l.second+r.second);}\n};\n//using Op = TreeOperator<int>;\n\
    //Tree<Op> tree = Tree<Op>::builder(g).build();\n"
  code: "/*\n * @title Tree - \u6728\n * @docs md/graph/Tree.md\n */\ntemplate<class\
    \ Operator> class TreeBuilder;\ntemplate<class Operator> class Tree {\n\tusing\
    \ TypeEdge = typename Operator::TypeEdge;\n\tsize_t num;\n\tsize_t ord;\n\tGraph<TypeEdge>&\
    \ g;\n\tfriend TreeBuilder<Operator>;\n\t/**\n\t * constructor\n\t * O(N) \n\t\
    \ */\n\tTree(Graph<TypeEdge>& graph):\n\t\tg(graph),\n\t\tnum(graph.size()),\n\
    \t\tdepth(graph.size(),-1),\n\t\torder(graph.size()),\n\t\tedge_dist(graph.size()){\n\
    \t}\n\t//for make_depth\n\tvoid dfs(int curr, int prev){\n\t\tfor(const auto&\
    \ e:g.edges[curr]){\n\t\t\tconst int& next = e.first;\n\t\t\tif(next==prev) continue;\n\
    \t\t\tdepth[next] = depth[curr] + 1;\n\t\t\tedge_dist[next]  = Operator::func_edge_merge(edge_dist[curr],e.second);\n\
    \t\t\tdfs(next,curr);\n\t\t\torder[ord++] = next;\n\t\t}\n\t}\n\t/**\n\t * \u5BDD\
    \u4ED8\u304D\u6728\u3092\u4F5C\u308B\n\t * O(N) you can use anytime\n\t */\n\t\
    void make_root(const int root) {\n\t\tdepth[root] = 0;\n\t\tedge_dist[root] =\
    \ Operator::unit_edge;\n\t\tord = 0;\n\t\tdfs(root,-1);\n\t\torder[ord++] = root;\n\
    \t\treverse_copy(order.begin(),order.end(),back_inserter(reorder));\n\t}\n\t/**\n\
    \t * \u5B50\u3092\u4F5C\u308B\n\t * O(N) after make_root\n\t */\n\tvoid make_child(const\
    \ int root = 0) {\n\t\tchild.resize(num);\n\t\tfor (size_t i = 0; i < num; ++i)\
    \ for (auto& e : g.edges[i]) if (depth[i] < depth[e.first]) child[i].push_back(e);\n\
    \t}\n\t/**\n\t * \u90E8\u5206\u6728\u306E\u30B5\u30A4\u30BA\u3092\u4F5C\u308B\n\
    \t * O(N) after make_child\n\t */\n\tvoid make_subtree_size() {\n\t\tsubtree_size.resize(num,1);\n\
    \t\tfor (size_t i:order) for (auto e : child[i]) subtree_size[i] += subtree_size[e.first];\n\
    \t}\n\t/**\n\t * \u89AA\u3092\u4F5C\u308B\n\t * O(N) after make_root\n\t */\n\t\
    void make_parent() {\n\t\tparent.resize(num,make_pair(num,Operator::unit_edge));\n\
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
    \t}\n\t\treturn make_pair(sz,st);\n\t}\npublic:\n\tvector<size_t> depth;\n\tvector<size_t>\
    \ order;\n\tvector<size_t> reorder;\n\tvector<size_t> subtree_size;\n\tvector<pair<size_t,TypeEdge>>\
    \ parent;\n\tvector<vector<pair<size_t,TypeEdge>>> child;\n\tvector<TypeEdge>\
    \ edge_dist;\n\tvector<array<pair<size_t,TypeEdge>,Operator::bit>> ancestor;\n\
    \ \n\t/**\n\t * O(N) builder\n\t */\n\tstatic TreeBuilder<Operator> builder(Graph<TypeEdge>&\
    \ graph) { return TreeBuilder<Operator>(graph);}\n\t/**\n\t * O(logN) after make_ancestor\n\
    \t * return {lca,lca_dist} l and r must be connected \n\t */\n\tpair<size_t,TypeEdge>\
    \ lca(size_t l, size_t r) {return lca_impl(l,r);}\n\t/**\n\t * O(N) anytime\n\t\
    \ * return {diameter size,diameter set} \n\t */\n\tpair<TypeEdge,vector<size_t>>\
    \ diameter(void){return diameter_impl();}\n};\n \ntemplate<class Operator> class\
    \ TreeBuilder {\n\tbool is_root_made =false;\n\tbool is_child_made =false;\n\t\
    bool is_parent_made=false;\npublic:\n\tusing TypeEdge = typename Operator::TypeEdge;\n\
    \tTreeBuilder(Graph<TypeEdge>& g):tree(g){}\n\tTreeBuilder& root(const int rt)\
    \ { is_root_made=true; tree.make_root(rt); return *this;}\n\tTreeBuilder& child()\
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
    \ r){return make_pair(l.first,l.second+r.second);}\n};\n//using Op = TreeOperator<int>;\n\
    //Tree<Op> tree = Tree<Op>::builder(g).build();"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/Tree2.cpp
  requiredBy: []
  timestamp: '2021-04-22 21:27:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
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
