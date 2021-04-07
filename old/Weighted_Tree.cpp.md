---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"old/Weighted_Tree.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate<class T> class Weighted_Tree {\npublic:\n\tint N,\
    \ MAX_bit;\n\tT ini;\n\tvector<vector<pair<T,int>>> edge;\n\tvector<pair<T,int>>\
    \ depth;\n\tvector<int> order;\n\tvector<vector<pair<T,int>>> parent;\n\tvector<vector<pair<T,int>>>\
    \ child;\n\n\tWeighted_Tree(const int N,  T ini, const int MAX_bit = 20) : N(N),\
    \ ini(ini) MAX_bit(MAX_bit), edge(N), depth(N, {-1,-1}), order(N, -1), parent(N,\
    \ vector<pair<T,int>>(MAX_bit)), child(N) {\n\t\t//do nothing\n\t}\n\n\t//O(1)\n\
    \tvoid make_edge(const int& from, const int& to, const T& w) {\n\t\tedge[from].push_back({w,to});\n\
    \t}\n\n\t//O(N)\n\tvoid make_depth(const int& root) {\n\t\tqueue<int> q;\n\t\t\
    depth[root] = {0,0};\n\t\tq.push(root);\n\t\twhile (q.size()) {\n\t\t\tint from\
    \ = q.front();\n\t\t\tq.pop();\n\t\t\tfor (auto& e : edge[from]) {\n\t\t\t\tT\
    \ w = e.first;\n\t\t\t\tint to = e.second;\n\t\t\t\tif (depth[to].second != -1)\
    \ continue;\n\t\t\t\tdepth[to] = {depth[from].first + w, depth[from].second +\
    \ 1};\n\t\t\t\tq.push(to);\n\t\t\t}\n\t\t}\n\t}\n\n\t//O(NlogN)\n\tvoid make_order(){\n\
    \t\tvector<pair<int,int>> tmp(N);\n\t\tfor (int i = 0; i < N; ++i) tmp[i] = {depth[i].second,i};\n\
    \t\tsort(tmp.begin(),tmp.end(),greater<>());\n\t\tfor (int i = 0; i < N; ++i)\
    \ order[i] = tmp[i].second;\n\t}\n\n\t//O(MAX_bit*N)\n\tvoid make_parent() {\n\
    \t\tfor (int i = 0; i < N; ++i) parent[i][0] = {ini,i};\n\t\tfor (int i = 0; i\
    \ < N; ++i)\tfor (auto j : edge[i]) {\n\t\t\tif (depth[i].second > depth[j.second].second)\
    \ parent[i][0] = j;\n\t\t}\n\t\tfor (int bit = 1; bit < MAX_bit; ++bit) for (int\
    \ i = 0; i < N; ++i) parent[i][bit] = parent[parent[i][bit - 1].second][bit -\
    \ 1];\n\t}\n\n\t//O(N)\n\t// void make_child() {\n\t// \tfor (int i = 0; i < N;\
    \ ++i) for (auto j : edge[i]) if (depth[i] < depth[j]) child[i].push_back(j);\n\
    \t// }\n\n\tvoid print() {\n\t\tcout << \" depth { \" << depth[0];\n\t\tfor (int\
    \ i = 1; i < N; ++i) cout << \", \" << depth[i];\n\t\tcout << \" }\" << endl;\n\
    \n\t\tcout << \"parent { \" << parent[0][0];\n\t\tfor (int i = 1; i < N; ++i)\
    \ cout << \", \" << parent[i][0];\n\t\tcout << \" }\" << endl;\n\n\t\tcout <<\
    \ \" child { \" << child[0];\n\t\tfor (int i = 1; i < N; ++i) cout << \", \" <<\
    \ child[i];\n\t\tcout << \" }\" << endl;\n\t}\n\n};\n//verify \n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<class T> class\
    \ Weighted_Tree {\npublic:\n\tint N, MAX_bit;\n\tT ini;\n\tvector<vector<pair<T,int>>>\
    \ edge;\n\tvector<pair<T,int>> depth;\n\tvector<int> order;\n\tvector<vector<pair<T,int>>>\
    \ parent;\n\tvector<vector<pair<T,int>>> child;\n\n\tWeighted_Tree(const int N,\
    \  T ini, const int MAX_bit = 20) : N(N), ini(ini) MAX_bit(MAX_bit), edge(N),\
    \ depth(N, {-1,-1}), order(N, -1), parent(N, vector<pair<T,int>>(MAX_bit)), child(N)\
    \ {\n\t\t//do nothing\n\t}\n\n\t//O(1)\n\tvoid make_edge(const int& from, const\
    \ int& to, const T& w) {\n\t\tedge[from].push_back({w,to});\n\t}\n\n\t//O(N)\n\
    \tvoid make_depth(const int& root) {\n\t\tqueue<int> q;\n\t\tdepth[root] = {0,0};\n\
    \t\tq.push(root);\n\t\twhile (q.size()) {\n\t\t\tint from = q.front();\n\t\t\t\
    q.pop();\n\t\t\tfor (auto& e : edge[from]) {\n\t\t\t\tT w = e.first;\n\t\t\t\t\
    int to = e.second;\n\t\t\t\tif (depth[to].second != -1) continue;\n\t\t\t\tdepth[to]\
    \ = {depth[from].first + w, depth[from].second + 1};\n\t\t\t\tq.push(to);\n\t\t\
    \t}\n\t\t}\n\t}\n\n\t//O(NlogN)\n\tvoid make_order(){\n\t\tvector<pair<int,int>>\
    \ tmp(N);\n\t\tfor (int i = 0; i < N; ++i) tmp[i] = {depth[i].second,i};\n\t\t\
    sort(tmp.begin(),tmp.end(),greater<>());\n\t\tfor (int i = 0; i < N; ++i) order[i]\
    \ = tmp[i].second;\n\t}\n\n\t//O(MAX_bit*N)\n\tvoid make_parent() {\n\t\tfor (int\
    \ i = 0; i < N; ++i) parent[i][0] = {ini,i};\n\t\tfor (int i = 0; i < N; ++i)\t\
    for (auto j : edge[i]) {\n\t\t\tif (depth[i].second > depth[j.second].second)\
    \ parent[i][0] = j;\n\t\t}\n\t\tfor (int bit = 1; bit < MAX_bit; ++bit) for (int\
    \ i = 0; i < N; ++i) parent[i][bit] = parent[parent[i][bit - 1].second][bit -\
    \ 1];\n\t}\n\n\t//O(N)\n\t// void make_child() {\n\t// \tfor (int i = 0; i < N;\
    \ ++i) for (auto j : edge[i]) if (depth[i] < depth[j]) child[i].push_back(j);\n\
    \t// }\n\n\tvoid print() {\n\t\tcout << \" depth { \" << depth[0];\n\t\tfor (int\
    \ i = 1; i < N; ++i) cout << \", \" << depth[i];\n\t\tcout << \" }\" << endl;\n\
    \n\t\tcout << \"parent { \" << parent[0][0];\n\t\tfor (int i = 1; i < N; ++i)\
    \ cout << \", \" << parent[i][0];\n\t\tcout << \" }\" << endl;\n\n\t\tcout <<\
    \ \" child { \" << child[0];\n\t\tfor (int i = 1; i < N; ++i) cout << \", \" <<\
    \ child[i];\n\t\tcout << \" }\" << endl;\n\t}\n\n};\n//verify \n"
  dependsOn: []
  isVerificationFile: false
  path: old/Weighted_Tree.cpp
  requiredBy: []
  timestamp: '2020-01-09 00:30:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/Weighted_Tree.cpp
layout: document
redirect_from:
- /library/old/Weighted_Tree.cpp
- /library/old/Weighted_Tree.cpp.html
title: old/Weighted_Tree.cpp
---
