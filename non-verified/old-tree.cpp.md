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
    links:
    - https://atcoder.jp/contests/abc014/tasks/abc014_4
    - https://atcoder.jp/contests/abc126/tasks/abc126_d
    - https://atcoder.jp/contests/abc133/tasks/abc133_e
    - https://atcoder.jp/contests/agc033/tasks/agc033_c
    - https://atcoder.jp/contests/cf16-tournament-round1-open/tasks/asaporo_c
    - https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h
    - https://atcoder.jp/contests/code-thanks-festival-2018/tasks/code_thanks_festival_2018_f
    - https://yukicoder.me/problems/no/399
    - https://yukicoder.me/problems/no/650
    - https://yukicoder.me/problems/no/872
    - https://yukicoder.me/problems/no/900
    - https://yukicoder.me/problems/no/922
  bundledCode: "#line 1 \"non-verified/old-tree.cpp\"\n/*\n * @title Tree - \u6728\
    \n * @docs md/graph/Tree.md\n */\ntemplate<class Operator> class Tree {\n\tusing\
    \ TypeDist = typename Operator::TypeDist;\n\tsize_t num;\n\tsize_t ord;\n\tenum\
    \ METHODS{\n\t\tMAKE_DEPTH,\n\t\tMAKE_CHILD,\n\t\tMAKE_PARENT,\n\t\tMAKE_SIZE,\n\
    \t\tMAKE_SUBTREE,\n\t\tMAKE_ANCESTOR,\n\t\tMAKE_EOULERTOUR,\n\t\tMAKE_HEAVY_LIGHT_DECOMPOSITION,\n\
    \t\tMETHODS_SIZE,\n\t};\n\tarray<int,METHODS_SIZE> executed_flag;\npublic:\n\t\
    vector<vector<pair<size_t,TypeDist>>> edge;\n\tvector<size_t> depth;\n\tvector<size_t>\
    \ order;\n\tvector<size_t> reorder;\n\tvector<TypeDist> dist;\n\tvector<pair<size_t,TypeDist>>\
    \ parent;\n\tvector<vector<pair<size_t,TypeDist>>> child;\n\tvector<array<pair<size_t,TypeDist>,Operator::bit>>\
    \ ancestor;\n\tvector<size_t> size;\n\tvector<vector<size_t>> subtree;\n\tvector<size_t>\
    \ head;\n\tvector<size_t> hldorder;\n\tvector<size_t> eulertour;\n\tvector<pair<size_t,size_t>>\
    \ eulertour_range;\n\tTree(const int num):num(num),edge(num),depth(num,-1),order(num),dist(num),executed_flag(){}\n\
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
    }\n};\n"
  code: "/*\n * @title Tree - \u6728\n * @docs md/graph/Tree.md\n */\ntemplate<class\
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
    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/old-tree.cpp
  requiredBy: []
  timestamp: '2021-04-23 05:33:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/old-tree.cpp
layout: document
redirect_from:
- /library/non-verified/old-tree.cpp
- /library/non-verified/old-tree.cpp.html
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