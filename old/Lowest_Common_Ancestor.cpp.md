---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc014/tasks/abc014_4
  bundledCode: "#line 1 \"old/Lowest_Common_Ancestor.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nclass Lowest_Common_Ancestor {\npublic:\n\tint N, MAX_bit;\n\
    \tvector<vector<int>> edge;\n\tvector<int> depth;\n\tvector<vector<int>> parent;\n\
    \tvector<vector<int>> child;\n\tvector<vector<int>> descendant;\n\n\tLowest_Common_Ancestor(int\
    \ N, int MAX_bit = 20) :N(N), MAX_bit(MAX_bit), edge(N), depth(N, -1), parent(N,\
    \ vector<int>(MAX_bit)), child(N), descendant(N){\n\t\t//do nothing\n\t}\n\n\t\
    //O(1)\n\tvoid make_edge(int from, int to) {\n\t\tedge[from].push_back(to);\n\t\
    }\n\n\t//O(N)\n\tvoid make_depth(int root) {\n\t\tqueue<int> q;\n\t\tdepth[root]\
    \ = 0;\n\t\tq.push(root);\n\t\twhile (q.size()) {\n\t\t\tint from = q.front();\n\
    \t\t\tq.pop();\n\t\t\tfor (auto to : edge[from]) {\n\t\t\t\tif (depth[to] != -1)\
    \ continue;\n\t\t\t\tdepth[to] = depth[from] + 1;\n\t\t\t\tq.push(to);\n\t\t\t\
    }\n\t\t}\n\t}\n\n\t//O(MAX_bit*N)\n\tvoid make_parent() {\n\t\tfor (int i = 0;\
    \ i < N; ++i) parent[i][0] = i;\n\t\tfor (int i = 0; i < N; ++i) for (auto j :\
    \ edge[i]) if (depth[i] > depth[j]) parent[i][0] = j;\n\t\tfor (int bit = 1; bit\
    \ < MAX_bit; ++bit) for (int i = 0; i < N; ++i) parent[i][bit] = parent[parent[i][bit\
    \ - 1]][bit - 1];\n\t}\n\n\t//O(N)\n\tvoid make_child() {\n\t\tfor (int i = 0;\
    \ i < N; ++i) for (auto j : edge[i]) if (depth[i] < depth[j]) child[i].push_back(j);\n\
    \t}\n\n\t//O(N^2)\n\tvoid make_descendant() {\n\t\tvector<pair<int,int>> ord(N);\n\
    \t\tfor (int i = 0; i < N; ++i) ord[i] = {depth[i],i};\n\t\tsort(ord.begin(),ord.end(),greater<>());\n\
    \t\tfor (int i = 0; i < N; ++i) descendant[i].push_back(i);\n\t\tfor (int i =\
    \ 0; i < N; ++i) for (auto j : edge[ord[i].second]) if (depth[ord[i].second] <\
    \ depth[j]) for(auto k: descendant[j]) descendant[ord[i].second].push_back(k);\n\
    \t}\n\n\t//O(MAX_bit*logN)\n\tint lca(int l, int r) {\n\t\tif (depth[l] < depth[r])\
    \ swap(l, r);\n\t\tint diff = depth[l] - depth[r];\n\t\tfor (int bit = 0; bit\
    \ < MAX_bit; ++bit) if (diff & (1 << bit)) l = parent[l][bit];\n\t\tint ok = (1\
    \ << MAX_bit), ng = -1, md;\n\t\twhile (ok - ng>1) {\n\t\t\tmd = (ok + ng) / 2;\n\
    \t\t\tint x = l, y = r;\n\t\t\tfor (int bit = 0; bit < MAX_bit; ++bit) if (md\
    \ & (1 << bit)) x = parent[x][bit];\n\t\t\tfor (int bit = 0; bit < MAX_bit; ++bit)\
    \ if (md & (1 << bit)) y = parent[y][bit];\n\t\t\t(x == y ? ok : ng) = md;\n\t\
    \t}\n\t\tfor (int bit = 0; bit < MAX_bit; ++bit) if (ok & (1 << bit)) l = parent[l][bit];\n\
    \t\treturn l;\n\t}\n\n\tvoid print() {\n\t\tcout << \" depth { \" << depth[0];\n\
    \t\tfor (int i = 1; i < N; ++i) cout << \", \" << depth[i];\n\t\tcout << \" }\"\
    \ << endl;\n\n\t\tcout << \"parent { \" << parent[0][0];\n\t\tfor (int i = 1;\
    \ i < N; ++i) cout << \", \" << parent[i][0];\n\t\tcout << \" }\" << endl;\n\n\
    \t\tcout << \" child { \" << child[0];\n\t\tfor (int i = 1; i < N; ++i) cout <<\
    \ \", \" << child[i];\n\t\tcout << \" }\" << endl;\n\n\t\tcout << \"descen { \"\
    \ << descendant[0];\n\t\tfor (int i = 1; i < N; ++i) cout << \", \" << descendant[i];\n\
    \t\tcout << \" }\" << endl;\n\t}\n\n};\n\n//verify https://atcoder.jp/contests/abc014/tasks/abc014_4\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nclass Lowest_Common_Ancestor\
    \ {\npublic:\n\tint N, MAX_bit;\n\tvector<vector<int>> edge;\n\tvector<int> depth;\n\
    \tvector<vector<int>> parent;\n\tvector<vector<int>> child;\n\tvector<vector<int>>\
    \ descendant;\n\n\tLowest_Common_Ancestor(int N, int MAX_bit = 20) :N(N), MAX_bit(MAX_bit),\
    \ edge(N), depth(N, -1), parent(N, vector<int>(MAX_bit)), child(N), descendant(N){\n\
    \t\t//do nothing\n\t}\n\n\t//O(1)\n\tvoid make_edge(int from, int to) {\n\t\t\
    edge[from].push_back(to);\n\t}\n\n\t//O(N)\n\tvoid make_depth(int root) {\n\t\t\
    queue<int> q;\n\t\tdepth[root] = 0;\n\t\tq.push(root);\n\t\twhile (q.size()) {\n\
    \t\t\tint from = q.front();\n\t\t\tq.pop();\n\t\t\tfor (auto to : edge[from])\
    \ {\n\t\t\t\tif (depth[to] != -1) continue;\n\t\t\t\tdepth[to] = depth[from] +\
    \ 1;\n\t\t\t\tq.push(to);\n\t\t\t}\n\t\t}\n\t}\n\n\t//O(MAX_bit*N)\n\tvoid make_parent()\
    \ {\n\t\tfor (int i = 0; i < N; ++i) parent[i][0] = i;\n\t\tfor (int i = 0; i\
    \ < N; ++i) for (auto j : edge[i]) if (depth[i] > depth[j]) parent[i][0] = j;\n\
    \t\tfor (int bit = 1; bit < MAX_bit; ++bit) for (int i = 0; i < N; ++i) parent[i][bit]\
    \ = parent[parent[i][bit - 1]][bit - 1];\n\t}\n\n\t//O(N)\n\tvoid make_child()\
    \ {\n\t\tfor (int i = 0; i < N; ++i) for (auto j : edge[i]) if (depth[i] < depth[j])\
    \ child[i].push_back(j);\n\t}\n\n\t//O(N^2)\n\tvoid make_descendant() {\n\t\t\
    vector<pair<int,int>> ord(N);\n\t\tfor (int i = 0; i < N; ++i) ord[i] = {depth[i],i};\n\
    \t\tsort(ord.begin(),ord.end(),greater<>());\n\t\tfor (int i = 0; i < N; ++i)\
    \ descendant[i].push_back(i);\n\t\tfor (int i = 0; i < N; ++i) for (auto j : edge[ord[i].second])\
    \ if (depth[ord[i].second] < depth[j]) for(auto k: descendant[j]) descendant[ord[i].second].push_back(k);\n\
    \t}\n\n\t//O(MAX_bit*logN)\n\tint lca(int l, int r) {\n\t\tif (depth[l] < depth[r])\
    \ swap(l, r);\n\t\tint diff = depth[l] - depth[r];\n\t\tfor (int bit = 0; bit\
    \ < MAX_bit; ++bit) if (diff & (1 << bit)) l = parent[l][bit];\n\t\tint ok = (1\
    \ << MAX_bit), ng = -1, md;\n\t\twhile (ok - ng>1) {\n\t\t\tmd = (ok + ng) / 2;\n\
    \t\t\tint x = l, y = r;\n\t\t\tfor (int bit = 0; bit < MAX_bit; ++bit) if (md\
    \ & (1 << bit)) x = parent[x][bit];\n\t\t\tfor (int bit = 0; bit < MAX_bit; ++bit)\
    \ if (md & (1 << bit)) y = parent[y][bit];\n\t\t\t(x == y ? ok : ng) = md;\n\t\
    \t}\n\t\tfor (int bit = 0; bit < MAX_bit; ++bit) if (ok & (1 << bit)) l = parent[l][bit];\n\
    \t\treturn l;\n\t}\n\n\tvoid print() {\n\t\tcout << \" depth { \" << depth[0];\n\
    \t\tfor (int i = 1; i < N; ++i) cout << \", \" << depth[i];\n\t\tcout << \" }\"\
    \ << endl;\n\n\t\tcout << \"parent { \" << parent[0][0];\n\t\tfor (int i = 1;\
    \ i < N; ++i) cout << \", \" << parent[i][0];\n\t\tcout << \" }\" << endl;\n\n\
    \t\tcout << \" child { \" << child[0];\n\t\tfor (int i = 1; i < N; ++i) cout <<\
    \ \", \" << child[i];\n\t\tcout << \" }\" << endl;\n\n\t\tcout << \"descen { \"\
    \ << descendant[0];\n\t\tfor (int i = 1; i < N; ++i) cout << \", \" << descendant[i];\n\
    \t\tcout << \" }\" << endl;\n\t}\n\n};\n\n//verify https://atcoder.jp/contests/abc014/tasks/abc014_4\n"
  dependsOn: []
  isVerificationFile: false
  path: old/Lowest_Common_Ancestor.cpp
  requiredBy: []
  timestamp: '2020-01-09 00:30:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/Lowest_Common_Ancestor.cpp
layout: document
redirect_from:
- /library/old/Lowest_Common_Ancestor.cpp
- /library/old/Lowest_Common_Ancestor.cpp.html
title: old/Lowest_Common_Ancestor.cpp
---
