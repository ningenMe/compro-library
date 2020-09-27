---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/Tree.cpp
    title: "Tree - \u6728"
  - icon: ':heavy_check_mark:'
    path: lib/segment/LazySegmentTree.cpp
    title: "LazySegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u9045\u5EF6\u8A55\
      \u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/399
    links:
    - https://yukicoder.me/problems/no/399
  bundledCode: "#line 1 \"test/graph/Tree-hld-vertex.test.cpp\"\n#define PROBLEM \"\
    https://yukicoder.me/problems/no/399\"\n\n#include <vector>\n#include <iostream>\n\
    #include <cassert>\n#include <map>\n#include <algorithm>\n#include <stack>\n#include\
    \ <numeric>\n#include <array>\nusing namespace std;\n#line 1 \"lib/graph/Tree.cpp\"\
    \n/*\n * @title Tree - \u6728\n * @docs md/graph/Tree.md\n */\ntemplate<class\
    \ Operator> class Tree {\n\tusing TypeDist = typename Operator::TypeDist;\n\t\
    size_t num;\n\tsize_t ord;\n\tenum METHODS{\n\t\tMAKE_DEPTH,\n\t\tMAKE_CHILD,\n\
    \t\tMAKE_PARENT,\n\t\tMAKE_SIZE,\n\t\tMAKE_SUBTREE,\n\t\tMAKE_ANCESTOR,\n\t\t\
    MAKE_EOULERTOUR,\n\t\tMAKE_HEAVY_LIGHT_DECOMPOSITION,\n\t\tMETHODS_SIZE,\n\t};\n\
    \tarray<int,METHODS_SIZE> executed_flag;\npublic:\n\tvector<vector<pair<size_t,TypeDist>>>\
    \ edge;\n\tvector<size_t> depth;\n\tvector<size_t> order;\n\tvector<size_t> reorder;\n\
    \tvector<TypeDist> dist;\n\tvector<pair<size_t,TypeDist>> parent;\n\tvector<vector<pair<size_t,TypeDist>>>\
    \ child;\n\tvector<array<pair<size_t,TypeDist>,Operator::bit>> ancestor;\n\tvector<size_t>\
    \ size;\n\tvector<vector<size_t>> subtree;\n\tvector<size_t> head;\n\tvector<size_t>\
    \ hldorder;\n\tvector<size_t> eulertour;\n\tvector<pair<size_t,size_t>> eulertour_range;\n\
    \tTree(const int num):num(num),edge(num),depth(num,-1),order(num),dist(num),executed_flag(){}\n\
    \t//O(1) anytime\n\tvoid make_edge(const int& from, const int& to, const TypeDist\
    \ w = 1) {\n\t\tedge[from].push_back({to,w});\n\t}\n\t//O(N) anytime\n\tvoid make_depth(const\
    \ int root) {\n\t\texecuted_flag[MAKE_DEPTH]++;\n\t\tdepth[root] = 0;\n\t\tdist[root]\
    \ = Operator::unit_dist;\n\t\tord = 0;\n\t\tdfs(root,-1);\n\t\torder[ord++] =\
    \ root;\n\t\treverse_copy(order.begin(),order.end(),back_inserter(reorder));\n\
    \t}\n\t//O(N) anytime for forest\n\tvoid make_depth(void) {\n\t\texecuted_flag[MAKE_DEPTH]++;\n\
    \t\tord = 0;\n\t\tfor(size_t root = 0; root < num; ++root) {\n\t\t\tif(depth[root]\
    \ != -1) continue;\n\t\t\tdepth[root] = 0;\n\t\t\tdist[root] = Operator::unit_dist;\n\
    \t\t\tdfs(root,-1);\n\t\t\torder[ord++] = root;\n\t\t}\n\t\treverse_copy(order.begin(),order.end(),back_inserter(reorder));\n\
    \t}\n\t//for make_depth\n\tvoid dfs(int curr, int prev){\n\t\tfor(auto& e:edge[curr]){\n\
    \t\t\tint next = e.first;\n\t\t\tif(next==prev) continue;\n\t\t\tdepth[next] =\
    \ depth[curr] + 1;\n\t\t\tdist[next]  = Operator::func_dist(dist[curr],e.second);\n\
    \t\t\tdfs(next,curr);\n\t\t\torder[ord++] = next;\n\t\t}\n\t}\n\t//for make_eulertour\n\
    \tvoid dfs(int from){\n\t\teulertour.push_back(from);\n\t\tfor(auto& e:child[from]){\n\
    \t\t\tint to = e.first;            \n\t\t\tdfs(to);        \n\t\t\teulertour.push_back(from);\n\
    \t\t}\n\t}\n\t//O(N) after make_depth\n\tvoid make_parent(const int root = 0)\
    \ {\n\t\tif(executed_flag[MAKE_PARENT]++) return;\n\t\tif(!executed_flag[MAKE_DEPTH])\
    \ make_depth(root);\n\t\tparent.resize(num,make_pair(num,Operator::unit_dist));\n\
    \t\tfor (size_t i = 0; i < num; ++i) for (auto& e : edge[i]) if (depth[i] > depth[e.first])\
    \ parent[i] = e;\n\t}\n\t//O(N) after make_depth\n\tvoid make_child(const int\
    \ root = 0) {\n\t\tif(executed_flag[MAKE_CHILD]++) return;\n\t\tif(!executed_flag[MAKE_DEPTH])\
    \ make_depth(root);\n\t\tchild.resize(num);\n\t\tfor (size_t i = 0; i < num; ++i)\
    \ for (auto& e : edge[i]) if (depth[i] < depth[e.first]) child[i].push_back(e);\n\
    \t}\n\t//O(NlogN) after make_parent\n\tvoid make_ancestor(const int root = 0)\
    \ {\n\t\tif(executed_flag[MAKE_ANCESTOR]++) return;\n\t\tif(!executed_flag[MAKE_PARENT])\
    \ make_parent(root);\n\t\tancestor.resize(num);\n\t\tfor (size_t i = 0; i < num;\
    \ ++i) ancestor[i][0] = (parent[i].first!=num?parent[i]:make_pair(i,Operator::unit_lca));\n\
    \t\tfor (size_t j = 1; j < Operator::bit; ++j) {\n\t\t\tfor (size_t i = 0; i <\
    \ num; ++i) {\n\t\t\t\tsize_t k = ancestor[i][j - 1].first;\n\t\t\t\tancestor[i][j]\
    \ = Operator::func_lca(ancestor[k][j - 1],ancestor[i][j - 1]);\n\t\t\t}\n\t\t\
    }\n\t}\n\t//O(logN) after make_ancestor\n\t//return {lca,lca_dist} l and r must\
    \ be connected\n\tpair<size_t,TypeDist> lca(size_t l, size_t r) {\n\t\tassert(executed_flag[MAKE_ANCESTOR]);\n\
    \t\tif (depth[l] < depth[r]) swap(l, r);\n\t\tint diff = depth[l] - depth[r];\n\
    \t\tauto ancl = make_pair(l,Operator::unit_lca);\n\t\tauto ancr = make_pair(r,Operator::unit_lca);\n\
    \t\tfor (int j = 0; j < Operator::bit; ++j) {\n\t\t\tif (diff & (1 << j)) {\n\t\
    \t\t\tancl = Operator::func_lca(ancestor[ancl.first][j],ancl);\n\t\t\t}\n\t\t\
    }\n\t\tif(ancl.first==ancr.first) return ancl;\n\t\tfor (int j = Operator::bit\
    \ - 1; 0 <= j; --j) {\n\t\t\tif(ancestor[ancl.first][j].first!=ancestor[ancr.first][j].first)\
    \ {\n\t\t\t\tancl = Operator::func_lca(ancestor[ancl.first][j],ancl);\n\t\t\t\t\
    ancr = Operator::func_lca(ancestor[ancr.first][j],ancr);\n\t\t\t}\n\t\t}\n\t\t\
    ancl = Operator::func_lca(ancestor[ancl.first][0],ancl);\n\t\tancr = Operator::func_lca(ancestor[ancr.first][0],ancr);\n\
    \t\treturn Operator::func_lca(ancl,ancr);\n\t}\n\t//O(N) anytime\n\t//pair<diameter,vertex_set>\n\
    \tpair<TypeDist,vector<int>> diameter(void){\n\t\tmake_depth(0);\n\t\tint root\
    \ = max_element(dist.begin(), dist.end()) - dist.begin();\n\t\tmake_depth(root);\n\
    \t\tint leaf = max_element(dist.begin(), dist.end()) - dist.begin();\n\t\tmake_parent();\n\
    \t\tTypeDist d = dist[leaf];\n\t\tvector<int> v;\n\t\twhile (leaf != root) {\n\
    \t\t\tv.push_back(leaf);\n\t\t\tleaf = parent[leaf].first;\n\t\t}\n\t\tv.push_back(root);\n\
    \t\treturn make_pair(d,v);\n\t}\n\t//O(N^2) after make_depth\n\tvoid make_subtree(const\
    \ int root = 0) {\n\t\tif(executed_flag[MAKE_SUBTREE]++) return;\n\t\tif(!executed_flag[MAKE_DEPTH])\
    \ make_depth(root);\n\t\tsubtree.resize(num);\n\t\tfor (size_t i = 0; i < num;\
    \ ++i) subtree[i].push_back(i);\n\t\tfor (size_t i = 0; i < num; ++i) for (auto&\
    \ e : edge[order[i]]) if (depth[order[i]] < depth[e.first]) for(auto k: subtree[e.first])\
    \ subtree[order[i]].push_back(k);\n\t}\n\t//O(N) after make_child\n\tvoid make_size(const\
    \ int root = 0) {\n\t\tif(executed_flag[MAKE_SIZE]++) return;\n\t\tif(!executed_flag[MAKE_CHILD])\
    \ make_child(root);\n\t\tsize.resize(num,1);\n\t\tfor (size_t i:order) for (auto\
    \ e : child[i]) size[i] += size[e.first];\n\t}\n\t//(N) after make_depth and make_child\n\
    \ttemplate<class TypeReroot> vector<TypeReroot> rerooting(vector<TypeReroot> rerootdp,vector<TypeReroot>\
    \ rerootparent) {\n\t\tassert(executed_flag[MAKE_CHILD]);\n\t\tfor(size_t pa:order)\
    \ for(auto& e:child[pa]) rerootdp[pa] = Operator::func_reroot(rerootdp[pa],rerootdp[e.first]);\n\
    \t\tfor(size_t pa:reorder) {\n\t\t\tif(depth[pa]) rerootdp[pa] = Operator::func_reroot(rerootdp[pa],rerootparent[pa]);\n\
    \t\t\tsize_t m = child[pa].size();\n\t\t\tfor(int j = 0; j < m && depth[pa]; ++j){\n\
    \t\t\t\tsize_t ch = child[pa][j].first;\n\t\t\t\trerootparent[ch] = Operator::func_reroot(rerootparent[ch],rerootparent[pa]);\n\
    \t\t\t}\n\t\t\tif(m <= 1) continue;\n\t\t\tvector<TypeReroot> l(m),r(m);\n\t\t\
    \tfor(int j = 0; j < m; ++j) {\n\t\t\t\tsize_t ch = child[pa][j].first;\n\t\t\t\
    \tl[j] = rerootdp[ch];\n\t\t\t\tr[j] = rerootdp[ch];\n\t\t\t}\n\t\t\tfor(int j\
    \ = 1; j+1 < m; ++j) l[j] = Operator::func_reroot_merge(l[j],l[j-1]);\n\t\t\t\
    for(int j = m-2; 0 <=j; --j) r[j] = Operator::func_reroot_merge(r[j],r[j+1]);\n\
    \t\t\tsize_t chl = child[pa].front().first;\n\t\t\tsize_t chr = child[pa].back().first;\n\
    \t\t\trerootparent[chl] = Operator::func_reroot(rerootparent[chl],r[1]);\n\t\t\
    \trerootparent[chr] = Operator::func_reroot(rerootparent[chr],l[m-2]);\n\t\t\t\
    for(int j = 1; j+1 < m; ++j) {\n\t\t\t\tsize_t ch = child[pa][j].first;\n\t\t\t\
    \trerootparent[ch] = Operator::func_reroot(rerootparent[ch],l[j-1]);\n\t\t\t\t\
    rerootparent[ch] = Operator::func_reroot(rerootparent[ch],r[j+1]);\n\t\t\t}\n\t\
    \t}\n\t\treturn rerootdp;\n\t}\n\t//O(N) after make_depth,make_parent,make_child\n\
    \tvoid make_heavy_light_decomposition(const int root = 0){\n\t\tif(executed_flag[MAKE_HEAVY_LIGHT_DECOMPOSITION]++)\
    \ return;\n\t\tif(!executed_flag[MAKE_SIZE]) make_size(root);\n\t\tif(!executed_flag[MAKE_PARENT])\
    \ make_parent(root);\n\t\thead.resize(num);\n\t\thldorder.resize(num);\n\t\tiota(head.begin(),head.end(),0);\n\
    \t\tfor(size_t& pa:reorder) {\n\t\t\tpair<size_t,size_t> maxi = {0,num};\n\t\t\
    \tfor(auto& e:child[pa]) maxi = max(maxi,{size[e.first],e.first});\n\t\t\tif(maxi.first)\
    \ head[maxi.second] = head[pa];\n\t\t}\n\t\tstack<size_t> st_head,st_sub;\n\t\t\
    size_t cnt = 0;\n\t\tfor(size_t& root:reorder){\n\t\t\tif(depth[root]) continue;\n\
    \t\t\tst_head.push(root);\n\t\t\twhile(st_head.size()){\n\t\t\t\tsize_t h = st_head.top();\n\
    \t\t\t\tst_head.pop();\n\t\t\t\tst_sub.push(h);\n\t\t\t\twhile (st_sub.size()){\n\
    \t\t\t\t\tsize_t pa = st_sub.top();\n\t\t\t\t\tst_sub.pop();\n\t\t\t\t\thldorder[pa]\
    \ = cnt++;\n\t\t\t\t\tfor(auto& e:child[pa]) {\n\t\t\t\t\t\tif(head[e.first]==head[pa])\
    \ st_sub.push(e.first);\n\t\t\t\t\t\telse st_head.push(e.first);\n\t\t\t\t\t}\n\
    \t\t\t\t}\t\t\t\t\n\t\t\t}\n\t\t}\n\t}\n\t//after hld type 0: vertex, 1: edge\n\
    \tvector<pair<size_t,size_t>> path(size_t u,size_t v,int type = 0) {\n\t\tassert(executed_flag[MAKE_HEAVY_LIGHT_DECOMPOSITION]);\n\
    \t\tvector<pair<size_t,size_t>> path;\n\t\twhile(1){\n\t\t\tif(hldorder[u]>hldorder[v])\
    \ swap(u,v);\n\t\t\tif(head[u]!=head[v]) {\n\t\t\t\tpath.push_back({hldorder[head[v]],hldorder[v]});\n\
    \t\t\t\tv=parent[head[v]].first;\n\t\t\t}\n\t\t\telse {\n\t\t\t\tpath.push_back({hldorder[u],hldorder[v]});\n\
    \t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\treverse(path.begin(),path.end());\n\t\tif(type)\
    \ path.front().first++;\n\t\treturn path;\n\t}\n\tsize_t hld_lca(size_t u,size_t\
    \ v){\n\t\tassert(executed_flag[MAKE_HEAVY_LIGHT_DECOMPOSITION]);\n\t\twhile(1){\n\
    \t\t\tif(hldorder[u]>hldorder[v]) swap(u,v);\n\t\t\tif(head[u]==head[v]) return\
    \ u;\n\t\t\tv=parent[head[v]].first;\n\t\t}\n\t}\n\t//O(N) after make_child and\
    \ make_parent\n\tvoid make_eulertour(const int root = 0){\n\t\tif(executed_flag[MAKE_EOULERTOUR]++)\
    \ return;\n\t\tif(!executed_flag[MAKE_CHILD]) make_child(root);\n\t\tif(!executed_flag[MAKE_PARENT])\
    \ make_parent(root);\n\t\tdfs(reorder.front());\n\t\teulertour_range.resize(num);\n\
    \t\tfor(int i = 0; i < eulertour.size(); ++i) eulertour_range[eulertour[i]].second\
    \ = i;\n\t\tfor(int i = eulertour.size()-1; 0 <= i; --i) eulertour_range[eulertour[i]].first\
    \ = i;\n\t}\n};\n//depth,dist\n//https://atcoder.jp/contests/abc126/tasks/abc126_d\n\
    //child\n//https://atcoder.jp/contests/abc133/tasks/abc133_e\n//lca\n//https://atcoder.jp/contests/abc014/tasks/abc014_4\n\
    //weighted lca\n//https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h\n\
    //https://atcoder.jp/contests/cf16-tournament-round1-open/tasks/asaporo_c\n//diameter\n\
    //https://atcoder.jp/contests/agc033/tasks/agc033_c\n//subtree\n//https://atcoder.jp/contests/code-thanks-festival-2018/tasks/code_thanks_festival_2018_f\n\
    //rerooting\n//https://yukicoder.me/problems/no/922\n//size\n//https://yukicoder.me/problems/no/872\n\
    //eulerTour\n//https://yukicoder.me/problems/no/900\n//hld\n//https://yukicoder.me/problems/no/399\n\
    //https://yukicoder.me/problems/no/650\ntemplate<class T> struct TreeOperator{\n\
    \tusing TypeDist = T;\n\tinline static constexpr size_t bit = 20;\n\tinline static\
    \ constexpr TypeDist unit_dist = 0;\n\tinline static constexpr TypeDist unit_lca\
    \ = 0;\n\tinline static constexpr TypeDist func_dist(const TypeDist& parent,const\
    \ TypeDist& w){return parent+w;}\n\tinline static constexpr pair<size_t,TypeDist>\
    \ func_lca(const pair<size_t,TypeDist>& l,const pair<size_t,TypeDist>& r){return\
    \ make_pair(l.first,l.second+r.second);}\n\ttemplate<class TypeReroot> inline\
    \ static constexpr TypeReroot func_reroot(const TypeReroot& l,const TypeReroot&\
    \ r) {\n\t\treturn {l.first+r.first+r.second,l.second+r.second};\n\t}\n\ttemplate<class\
    \ TypeReroot> inline static constexpr TypeReroot func_reroot_merge(const TypeReroot&\
    \ l,const TypeReroot& r) {\n\t\treturn {l.first+r.first,l.second+r.second};\n\t\
    }\n};\n#line 1 \"lib/segment/LazySegmentTree.cpp\"\n/*\n * @title LazySegmentTree\
    \ - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728\n * @docs md/segment/LazySegmentTree.md\n */\ntemplate<class\
    \ Operator> class LazySegmentTree {\n\tusing TypeNode = typename Operator::TypeNode;\
    \          \n\tusing TypeLazy = typename Operator::TypeLazy;\n\tsize_t num;  \
    \    \n\tsize_t length;                                   \n\tsize_t height; \
    \                                  \n\tvector<TypeNode> node;                \
    \           \n\tvector<TypeLazy> lazy;                           \n\tvector<pair<size_t,size_t>>\
    \ range;\n\n\tvoid propagate(int k) {\n\t\tif(lazy[k] == Operator::unit_lazy)\
    \ return;\n        node[k] = Operator::func_merge(node[k],lazy[k],range[k].first,range[k].second);\n\
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
    \ var <= nodeVal;}\n};\n#line 14 \"test/graph/Tree-hld-vertex.test.cpp\"\n\nint\
    \ main(void){\n\tint N; cin >> N;\n\tTree<TreeOperator<int>> tree(N);\n\tvector<pair<int,int>>\
    \ edge(N-1);\n\tfor(int i = 0; i < N-1; ++i) {\n\t\tint u,v; cin >> u >> v;\n\t\
    \tu--,v--;\n\t\ttree.make_edge(u,v);\n\t\ttree.make_edge(v,u);\n\t\tedge[i] =\
    \ {u,v};\n\t}\n\ttree.make_heavy_light_decomposition(0);\n    LazySegmentTree<NodeSumRangeAdd<long\
    \ long,long long>> seg(N);\n    int Q; cin >> Q;\n    long long ans = 0;\n   \
    \ for(int i = 0; i < Q; ++i) {\n        int a,b; cin >> a >> b;\n        a--,b--;\n\
    \        auto path = tree.path(a,b);\n        for(auto p:path){\n            int\
    \ l = p.first,r = p.second;\n            seg.update(l,r+1,1);\n            ans\
    \ += seg.get(l,r+1);\n        }\n    }\n    cout << ans << endl;\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/399\"\n\n#include <vector>\n\
    #include <iostream>\n#include <cassert>\n#include <map>\n#include <algorithm>\n\
    #include <stack>\n#include <numeric>\n#include <array>\nusing namespace std;\n\
    #include \"../../lib/graph/Tree.cpp\"\n#include \"../../lib/segment/LazySegmentTree.cpp\"\
    \n\nint main(void){\n\tint N; cin >> N;\n\tTree<TreeOperator<int>> tree(N);\n\t\
    vector<pair<int,int>> edge(N-1);\n\tfor(int i = 0; i < N-1; ++i) {\n\t\tint u,v;\
    \ cin >> u >> v;\n\t\tu--,v--;\n\t\ttree.make_edge(u,v);\n\t\ttree.make_edge(v,u);\n\
    \t\tedge[i] = {u,v};\n\t}\n\ttree.make_heavy_light_decomposition(0);\n    LazySegmentTree<NodeSumRangeAdd<long\
    \ long,long long>> seg(N);\n    int Q; cin >> Q;\n    long long ans = 0;\n   \
    \ for(int i = 0; i < Q; ++i) {\n        int a,b; cin >> a >> b;\n        a--,b--;\n\
    \        auto path = tree.path(a,b);\n        for(auto p:path){\n            int\
    \ l = p.first,r = p.second;\n            seg.update(l,r+1,1);\n            ans\
    \ += seg.get(l,r+1);\n        }\n    }\n    cout << ans << endl;\n    return 0;\n\
    }"
  dependsOn:
  - lib/graph/Tree.cpp
  - lib/segment/LazySegmentTree.cpp
  isVerificationFile: true
  path: test/graph/Tree-hld-vertex.test.cpp
  requiredBy: []
  timestamp: '2020-09-27 22:47:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/Tree-hld-vertex.test.cpp
layout: document
redirect_from:
- /verify/test/graph/Tree-hld-vertex.test.cpp
- /verify/test/graph/Tree-hld-vertex.test.cpp.html
title: test/graph/Tree-hld-vertex.test.cpp
---
