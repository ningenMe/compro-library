---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc014/tasks/abc014_4
    - https://atcoder.jp/contests/abc126/tasks/abc126_d
    - https://atcoder.jp/contests/abc133/tasks/abc133_e
    - https://atcoder.jp/contests/agc033/tasks/agc033_c
    - https://yukicoder.me/problems/no/900
  bundledCode: "#line 1 \"old/Tree.cpp\"\n\ntemplate<class T = int> class Tree {\n\
    public:\n\tint nodeNum;\n\tint isWeighted;\n\tint maxBit;\n\tint idx;\n\tvector<vector<int>>\
    \ edge;\n\tvector<vector<T>> weight;\n\tvector<int> depth;\n\tvector<int> order;\n\
    \tvector<T> dist;\n\t\n\tvector<int> parent;\n\tvector<T> parentDist;\n\t\n\t\
    vector<vector<int>> child;\n\tvector<vector<T>> childDist;\n \n\tvector<vector<int>>\
    \ ancestor;\n\tvector<vector<int>> descendant;\n\t\n\tvector<int> eulerTour;\n\
    \    vector<T> eulerTourDist;\n\tvector<int> eulerTourIdxL;\n\tvector<int> eulerTourIdxR;\n\
    \    vector<int> eulerTourDive,eulerTourFloat;\n    vector<T> eulerTourDiveDist,eulerTourFloatDist;\n\
    \tvector<int> eulerTourDiveIdxL,eulerTourFloatIdxL;\n\tvector<int> eulerTourDiveIdxR,eulerTourFloatIdxR;\n\
    \ \n\tTree(const int nodeNum, const int isWeighted = 0, const int maxBit = 20)\
    \ : \n\tnodeNum(nodeNum),\n\tisWeighted(isWeighted),\n\tmaxBit(maxBit),\n\tedge(nodeNum),\n\
    \tdepth(nodeNum),\n\torder(nodeNum)\n\t{\n\t\tif(isWeighted) weight.resize(nodeNum);\n\
    \t\tif(isWeighted) dist.resize(nodeNum);\n\t}\n \n\t//O(1) anytime\n\tvoid makeEdge(const\
    \ int& from, const int& to, const T& w = 0) {\n\t\tedge[from].push_back(to);\n\
    \t\tif(isWeighted)\tweight[from].push_back(w);\n\t}\n \n\t//O(N) anytime\n\tvoid\
    \ makeDepth(const int root) {\n\t\tdepth[root] = 0;\n\t\tif(isWeighted) dist[root]\
    \ = 0;\n\t\tidx = 0;\n\t\tdfs1(root);\n\t\torder[idx++] = root;\n\t}\n \n    //for\
    \ makeDepth\n\tvoid dfs1(int from, int prev = -1){\n\t\tfor(int i = 0; i < edge[from].size();\
    \ ++i){\n\t\t\tint to = edge[from][i];\n\t\t\tif(to==prev) continue;\n\t\t\tdepth[to]\
    \ = depth[from] + 1;\n\t\t\tif(isWeighted) dist[to] = dist[from] + weight[from][i];\n\
    \t\t\tdfs1(to,from);\n\t\t\torder[idx++] = to;\n\t\t}\n\t}\n \n    //O(N) anytime\n\
    \tint diameter(void){\n\t\tmakeDepth(0);\n\t\tint tmp = max_element(depth.begin(),\
    \ depth.end()) - depth.begin();\n\t\tmakeDepth(tmp);\n\t\treturn *max_element(depth.begin(),\
    \ depth.end());\n\t}\n \n\t//O(N) after makeDepth\n\tvoid makeParent(void) {\n\
    \t\tparent.resize(nodeNum);\n\t\tiota(parent.begin(),parent.end(),0);\n\t\tfor\
    \ (int i = 0; i < nodeNum; ++i) for (auto j : edge[i]) if (depth[i] > depth[j])\
    \ parent[i] = j;\n \n\t\tif(isWeighted) {\n\t\t\tparentDist.resize(nodeNum);\n\
    \t\t\tfor (int i = 0; i < nodeNum; ++i) for (int j = 0; j < edge[i].size(); ++j)\
    \ if (depth[i] > depth[edge[i][j]]) parentDist[i] = weight[i][j];\n\t\t}\n\t}\n\
    \ \n\t//O(N) after makeDepth\n\tvoid makeChild(void) {\n\t\tchild.resize(nodeNum);\n\
    \t\tfor (int i = 0; i < nodeNum; ++i) for (auto j : edge[i]) if (depth[i] < depth[j])\
    \ child[i].push_back(j);\n \n\t\tif(isWeighted) {\n\t\t\tchildDist.resize(nodeNum);\n\
    \t\t\tfor (int i = 0; i < nodeNum; ++i) for (int j = 0; j < edge[i].size(); ++j)\
    \ if (depth[i] < depth[edge[i][j]]) childDist[i].push_back(weight[i][j]);\n\t\t\
    }\n\t}\n \n\t//O(NlogN) after makeDepth\n\tvoid makeAncestor(void) {\n\t\tancestor.resize(nodeNum,vector<int>(maxBit));\n\
    \t\tfor (int i = 0; i < nodeNum; ++i) ancestor[i][0] = i;\n\t\tfor (int i = 0;\
    \ i < nodeNum; ++i) for (auto j : edge[i]) if (depth[i] > depth[j]) ancestor[i][0]\
    \ = j;\n\t\tfor (int bit = 1; bit < maxBit; ++bit) for (int i = 0; i < nodeNum;\
    \ ++i) ancestor[i][bit] = ancestor[ancestor[i][bit - 1]][bit - 1];\n\t}\n \n\t\
    //O(N^2) after makeDepth\n\tvoid makeDescendant(void) {\n\t\tdescendant.resize(nodeNum);\n\
    \t\tfor (int i = 0; i < nodeNum; ++i) descendant[i].push_back(i);\n\t\tfor (int\
    \ i = 0; i < nodeNum; ++i) for (auto j : edge[order[i]]) if (depth[order[i]] <\
    \ depth[j]) for(auto k: descendant[j]) descendant[order[i]].push_back(k);\n\t\
    }\n \n\t//O(logN) after makeAncestor\n\tint lca(int l, int r) {\n\t\tif (depth[l]\
    \ < depth[r]) swap(l, r);\n\t\tint diff = depth[l] - depth[r];\n\t\tfor (int bit\
    \ = 0; bit < maxBit; ++bit) if (diff & (1 << bit)) l = ancestor[l][bit];\n\t\t\
    if(l==r) return l;\n\t\tfor (int bit = maxBit - 1; 0 <= bit; --bit) if(ancestor[l][bit]!=ancestor[r][bit])\
    \ l = ancestor[l][bit], r = ancestor[r][bit];\n\t\treturn ancestor[l][0];\n\t\
    }\n \n\t//O(N) after makeChild and makeParent\n\tvoid makeEulerTour(void){\n \
    \       dfs2(order[nodeNum-1]);\n\t\teulerTourIdxL.resize(nodeNum);\n\t\teulerTourIdxR.resize(nodeNum);\n\
    \t\tfor(int i = 0; i < eulerTour.size(); ++i) eulerTourIdxR[eulerTour[i]] = i;\n\
    \t\tfor(int i = eulerTour.size()-1; 0 <= i; --i) eulerTourIdxL[eulerTour[i]] =\
    \ i;\n\t\treturn;\n\t}\n \n    //for makeEulerTour\n\tvoid dfs2(int from, int\
    \ prev = -1){\n\t\teulerTour.push_back(from);\n        if(isWeighted) eulerTourDist.push_back(parentDist[from]);\n\
    \ \n        for(int i = 0; i < child[from].size(); ++i){\n            int to =\
    \ child[from][i];            \n            dfs2(to,from);            \n    \t\t\
    eulerTour.push_back(from);\n            if(isWeighted) eulerTourDist.push_back(-childDist[from][i]);\n\
    \        }\n\t}\n\n\t//O(NlogN) after makeEulerTour\n\tvoid makeEulerTourEdge(void)\
    \ {\n\t\teulerTourDive.push_back(order[nodeNum-1]);\n\t\tif(isWeighted) eulerTourDiveDist.push_back(0);\n\
    \t\tfor(int i = 1; i < eulerTour.size(); ++i) {\n\t\t\tint l = eulerTour[i-1];\n\
    \t\t\tint r = eulerTour[i];\n\t\t\tif(depth[l] < depth[r]) {\n\t\t\t\teulerTourDive.push_back(i);\n\
    \t\t\t\tif(isWeighted) eulerTourDiveDist.push_back(eulerTourDist[i]);\n\t\t\t\
    }\n\t\t\telse {\n\t\t\t\teulerTourFloat.push_back(i);\n\t\t\t\tif(isWeighted)\
    \ eulerTourFloatDist.push_back(eulerTourDist[i]);\n\t\t\t}\n\t\t}\n\t\teulerTourDiveIdxL.resize(nodeNum);\n\
    \t\teulerTourDiveIdxR.resize(nodeNum);\n\t\teulerTourFloatIdxL.resize(nodeNum);\n\
    \t\teulerTourFloatIdxR.resize(nodeNum);\n\t\tfor(int i = 0; i < nodeNum; ++i)\
    \ {\n\t\t\tint l = eulerTourIdxL[i];\n\t\t\tint r = eulerTourIdxR[i];\n\t\t\t\
    eulerTourDiveIdxL[i]  =  upper_bound(eulerTourDive.begin() ,eulerTourDive.end()\
    \ ,l) - eulerTourDive.begin()     ;\n\t\t\teulerTourDiveIdxR[i]  = (upper_bound(eulerTourDive.begin()\
    \ ,eulerTourDive.end() ,r) - eulerTourDive.begin())  -1;\n\t\t\teulerTourFloatIdxL[i]\
    \ =  upper_bound(eulerTourFloat.begin(),eulerTourFloat.end(),l) - eulerTourFloat.begin()\
    \    ;\n\t\t\teulerTourFloatIdxR[i] = (upper_bound(eulerTourFloat.begin(),eulerTourFloat.end(),r)\
    \ - eulerTourFloat.begin()) -1;\n\t\t\teulerTourDiveIdxR[i]  = max(eulerTourDiveIdxL[i]-1\
    \ ,eulerTourDiveIdxR[i]);\n\t\t\teulerTourFloatIdxR[i] = max(eulerTourFloatIdxL[i]-1,eulerTourFloatIdxR[i]);\n\
    \t\t}\n\t}\n\t\t// i\u306E\u90E8\u5206\u6728\u306E\u9802\u70B9\u306B\u52A0\u7B97\
    \u3059\u308B\u3068\u304D\n\t\t// [ eulerTourIdxL[i]  ,eulerTourIdxR[i]  ]\u306B\
    \u3000+val\n\t\t// [i]\u306E\u9802\u70B9\u30AF\u30A8\u30EA\n\t\t// [eulerTourIdxL[i],eulerTourIdxL[i]]\n\
    \n\t\t// i\u306E\u90E8\u5206\u6728\u306E\u8FBA\u306B\u52A0\u7B97\u3059\u308B\u3068\
    \u304D\n\t\t// [ eulerTourDiveIdxL[i]  ,eulerTourDiveIdxR[i]  ]\u306B\u3000+val\n\
    \t\t// [ eulerTourFloatIdxL[i] ,eulerTourFloatIdxR[i] ]\u306B\u3000-val\n\t\t\
    // [0,i]\u306E\u30D1\u30B9\u30AF\u30A8\u30EA\n\t\t// [ 0, eulerTourDiveIdxL[i]\
    \ ) + [0, eulerTourFloatIdxL[i])\n \n};\n \n//depth,dist\n//https://atcoder.jp/contests/abc126/tasks/abc126_d\n\
    \ \n//lca\n//https://atcoder.jp/contests/abc014/tasks/abc014_4\n \n//child\n//https://atcoder.jp/contests/abc133/tasks/abc133_e\n\
    \n//diameter\n//https://atcoder.jp/contests/agc033/tasks/agc033_c\n\n//eulerTour\n\
    //https://yukicoder.me/problems/no/900\n\n"
  code: "\ntemplate<class T = int> class Tree {\npublic:\n\tint nodeNum;\n\tint isWeighted;\n\
    \tint maxBit;\n\tint idx;\n\tvector<vector<int>> edge;\n\tvector<vector<T>> weight;\n\
    \tvector<int> depth;\n\tvector<int> order;\n\tvector<T> dist;\n\t\n\tvector<int>\
    \ parent;\n\tvector<T> parentDist;\n\t\n\tvector<vector<int>> child;\n\tvector<vector<T>>\
    \ childDist;\n \n\tvector<vector<int>> ancestor;\n\tvector<vector<int>> descendant;\n\
    \t\n\tvector<int> eulerTour;\n    vector<T> eulerTourDist;\n\tvector<int> eulerTourIdxL;\n\
    \tvector<int> eulerTourIdxR;\n    vector<int> eulerTourDive,eulerTourFloat;\n\
    \    vector<T> eulerTourDiveDist,eulerTourFloatDist;\n\tvector<int> eulerTourDiveIdxL,eulerTourFloatIdxL;\n\
    \tvector<int> eulerTourDiveIdxR,eulerTourFloatIdxR;\n \n\tTree(const int nodeNum,\
    \ const int isWeighted = 0, const int maxBit = 20) : \n\tnodeNum(nodeNum),\n\t\
    isWeighted(isWeighted),\n\tmaxBit(maxBit),\n\tedge(nodeNum),\n\tdepth(nodeNum),\n\
    \torder(nodeNum)\n\t{\n\t\tif(isWeighted) weight.resize(nodeNum);\n\t\tif(isWeighted)\
    \ dist.resize(nodeNum);\n\t}\n \n\t//O(1) anytime\n\tvoid makeEdge(const int&\
    \ from, const int& to, const T& w = 0) {\n\t\tedge[from].push_back(to);\n\t\t\
    if(isWeighted)\tweight[from].push_back(w);\n\t}\n \n\t//O(N) anytime\n\tvoid makeDepth(const\
    \ int root) {\n\t\tdepth[root] = 0;\n\t\tif(isWeighted) dist[root] = 0;\n\t\t\
    idx = 0;\n\t\tdfs1(root);\n\t\torder[idx++] = root;\n\t}\n \n    //for makeDepth\n\
    \tvoid dfs1(int from, int prev = -1){\n\t\tfor(int i = 0; i < edge[from].size();\
    \ ++i){\n\t\t\tint to = edge[from][i];\n\t\t\tif(to==prev) continue;\n\t\t\tdepth[to]\
    \ = depth[from] + 1;\n\t\t\tif(isWeighted) dist[to] = dist[from] + weight[from][i];\n\
    \t\t\tdfs1(to,from);\n\t\t\torder[idx++] = to;\n\t\t}\n\t}\n \n    //O(N) anytime\n\
    \tint diameter(void){\n\t\tmakeDepth(0);\n\t\tint tmp = max_element(depth.begin(),\
    \ depth.end()) - depth.begin();\n\t\tmakeDepth(tmp);\n\t\treturn *max_element(depth.begin(),\
    \ depth.end());\n\t}\n \n\t//O(N) after makeDepth\n\tvoid makeParent(void) {\n\
    \t\tparent.resize(nodeNum);\n\t\tiota(parent.begin(),parent.end(),0);\n\t\tfor\
    \ (int i = 0; i < nodeNum; ++i) for (auto j : edge[i]) if (depth[i] > depth[j])\
    \ parent[i] = j;\n \n\t\tif(isWeighted) {\n\t\t\tparentDist.resize(nodeNum);\n\
    \t\t\tfor (int i = 0; i < nodeNum; ++i) for (int j = 0; j < edge[i].size(); ++j)\
    \ if (depth[i] > depth[edge[i][j]]) parentDist[i] = weight[i][j];\n\t\t}\n\t}\n\
    \ \n\t//O(N) after makeDepth\n\tvoid makeChild(void) {\n\t\tchild.resize(nodeNum);\n\
    \t\tfor (int i = 0; i < nodeNum; ++i) for (auto j : edge[i]) if (depth[i] < depth[j])\
    \ child[i].push_back(j);\n \n\t\tif(isWeighted) {\n\t\t\tchildDist.resize(nodeNum);\n\
    \t\t\tfor (int i = 0; i < nodeNum; ++i) for (int j = 0; j < edge[i].size(); ++j)\
    \ if (depth[i] < depth[edge[i][j]]) childDist[i].push_back(weight[i][j]);\n\t\t\
    }\n\t}\n \n\t//O(NlogN) after makeDepth\n\tvoid makeAncestor(void) {\n\t\tancestor.resize(nodeNum,vector<int>(maxBit));\n\
    \t\tfor (int i = 0; i < nodeNum; ++i) ancestor[i][0] = i;\n\t\tfor (int i = 0;\
    \ i < nodeNum; ++i) for (auto j : edge[i]) if (depth[i] > depth[j]) ancestor[i][0]\
    \ = j;\n\t\tfor (int bit = 1; bit < maxBit; ++bit) for (int i = 0; i < nodeNum;\
    \ ++i) ancestor[i][bit] = ancestor[ancestor[i][bit - 1]][bit - 1];\n\t}\n \n\t\
    //O(N^2) after makeDepth\n\tvoid makeDescendant(void) {\n\t\tdescendant.resize(nodeNum);\n\
    \t\tfor (int i = 0; i < nodeNum; ++i) descendant[i].push_back(i);\n\t\tfor (int\
    \ i = 0; i < nodeNum; ++i) for (auto j : edge[order[i]]) if (depth[order[i]] <\
    \ depth[j]) for(auto k: descendant[j]) descendant[order[i]].push_back(k);\n\t\
    }\n \n\t//O(logN) after makeAncestor\n\tint lca(int l, int r) {\n\t\tif (depth[l]\
    \ < depth[r]) swap(l, r);\n\t\tint diff = depth[l] - depth[r];\n\t\tfor (int bit\
    \ = 0; bit < maxBit; ++bit) if (diff & (1 << bit)) l = ancestor[l][bit];\n\t\t\
    if(l==r) return l;\n\t\tfor (int bit = maxBit - 1; 0 <= bit; --bit) if(ancestor[l][bit]!=ancestor[r][bit])\
    \ l = ancestor[l][bit], r = ancestor[r][bit];\n\t\treturn ancestor[l][0];\n\t\
    }\n \n\t//O(N) after makeChild and makeParent\n\tvoid makeEulerTour(void){\n \
    \       dfs2(order[nodeNum-1]);\n\t\teulerTourIdxL.resize(nodeNum);\n\t\teulerTourIdxR.resize(nodeNum);\n\
    \t\tfor(int i = 0; i < eulerTour.size(); ++i) eulerTourIdxR[eulerTour[i]] = i;\n\
    \t\tfor(int i = eulerTour.size()-1; 0 <= i; --i) eulerTourIdxL[eulerTour[i]] =\
    \ i;\n\t\treturn;\n\t}\n \n    //for makeEulerTour\n\tvoid dfs2(int from, int\
    \ prev = -1){\n\t\teulerTour.push_back(from);\n        if(isWeighted) eulerTourDist.push_back(parentDist[from]);\n\
    \ \n        for(int i = 0; i < child[from].size(); ++i){\n            int to =\
    \ child[from][i];            \n            dfs2(to,from);            \n    \t\t\
    eulerTour.push_back(from);\n            if(isWeighted) eulerTourDist.push_back(-childDist[from][i]);\n\
    \        }\n\t}\n\n\t//O(NlogN) after makeEulerTour\n\tvoid makeEulerTourEdge(void)\
    \ {\n\t\teulerTourDive.push_back(order[nodeNum-1]);\n\t\tif(isWeighted) eulerTourDiveDist.push_back(0);\n\
    \t\tfor(int i = 1; i < eulerTour.size(); ++i) {\n\t\t\tint l = eulerTour[i-1];\n\
    \t\t\tint r = eulerTour[i];\n\t\t\tif(depth[l] < depth[r]) {\n\t\t\t\teulerTourDive.push_back(i);\n\
    \t\t\t\tif(isWeighted) eulerTourDiveDist.push_back(eulerTourDist[i]);\n\t\t\t\
    }\n\t\t\telse {\n\t\t\t\teulerTourFloat.push_back(i);\n\t\t\t\tif(isWeighted)\
    \ eulerTourFloatDist.push_back(eulerTourDist[i]);\n\t\t\t}\n\t\t}\n\t\teulerTourDiveIdxL.resize(nodeNum);\n\
    \t\teulerTourDiveIdxR.resize(nodeNum);\n\t\teulerTourFloatIdxL.resize(nodeNum);\n\
    \t\teulerTourFloatIdxR.resize(nodeNum);\n\t\tfor(int i = 0; i < nodeNum; ++i)\
    \ {\n\t\t\tint l = eulerTourIdxL[i];\n\t\t\tint r = eulerTourIdxR[i];\n\t\t\t\
    eulerTourDiveIdxL[i]  =  upper_bound(eulerTourDive.begin() ,eulerTourDive.end()\
    \ ,l) - eulerTourDive.begin()     ;\n\t\t\teulerTourDiveIdxR[i]  = (upper_bound(eulerTourDive.begin()\
    \ ,eulerTourDive.end() ,r) - eulerTourDive.begin())  -1;\n\t\t\teulerTourFloatIdxL[i]\
    \ =  upper_bound(eulerTourFloat.begin(),eulerTourFloat.end(),l) - eulerTourFloat.begin()\
    \    ;\n\t\t\teulerTourFloatIdxR[i] = (upper_bound(eulerTourFloat.begin(),eulerTourFloat.end(),r)\
    \ - eulerTourFloat.begin()) -1;\n\t\t\teulerTourDiveIdxR[i]  = max(eulerTourDiveIdxL[i]-1\
    \ ,eulerTourDiveIdxR[i]);\n\t\t\teulerTourFloatIdxR[i] = max(eulerTourFloatIdxL[i]-1,eulerTourFloatIdxR[i]);\n\
    \t\t}\n\t}\n\t\t// i\u306E\u90E8\u5206\u6728\u306E\u9802\u70B9\u306B\u52A0\u7B97\
    \u3059\u308B\u3068\u304D\n\t\t// [ eulerTourIdxL[i]  ,eulerTourIdxR[i]  ]\u306B\
    \u3000+val\n\t\t// [i]\u306E\u9802\u70B9\u30AF\u30A8\u30EA\n\t\t// [eulerTourIdxL[i],eulerTourIdxL[i]]\n\
    \n\t\t// i\u306E\u90E8\u5206\u6728\u306E\u8FBA\u306B\u52A0\u7B97\u3059\u308B\u3068\
    \u304D\n\t\t// [ eulerTourDiveIdxL[i]  ,eulerTourDiveIdxR[i]  ]\u306B\u3000+val\n\
    \t\t// [ eulerTourFloatIdxL[i] ,eulerTourFloatIdxR[i] ]\u306B\u3000-val\n\t\t\
    // [0,i]\u306E\u30D1\u30B9\u30AF\u30A8\u30EA\n\t\t// [ 0, eulerTourDiveIdxL[i]\
    \ ) + [0, eulerTourFloatIdxL[i])\n \n};\n \n//depth,dist\n//https://atcoder.jp/contests/abc126/tasks/abc126_d\n\
    \ \n//lca\n//https://atcoder.jp/contests/abc014/tasks/abc014_4\n \n//child\n//https://atcoder.jp/contests/abc133/tasks/abc133_e\n\
    \n//diameter\n//https://atcoder.jp/contests/agc033/tasks/agc033_c\n\n//eulerTour\n\
    //https://yukicoder.me/problems/no/900\n\n"
  dependsOn: []
  isVerificationFile: false
  path: old/Tree.cpp
  requiredBy: []
  timestamp: '2020-04-26 03:48:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/Tree.cpp
layout: document
redirect_from:
- /library/old/Tree.cpp
- /library/old/Tree.cpp.html
title: old/Tree.cpp
---
