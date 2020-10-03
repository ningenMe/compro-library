---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/agc014/tasks/agc014_c
  bundledCode: "#line 1 \"old/Grid_Breadth_First_Search.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n\nclass Grid_Breadth_First_Dearch{\npublic:\n\tint H,W;\n\
    \tvector<string> S;\n\tvector<vector<int>> dist;\n\n\tGrid_Breadth_First_Dearch(int\
    \ H,int W):H(H),W(W),S(H),dist(H,vector<int>(W)){\n\t\t//do nothing\n\t}\n\n\t\
    void solve(int sy,int sx){\n\t\tfor(int i = 0; i < H; ++i) for(int j = 0; j <\
    \ W; ++j) dist[i][j] = -1;\n\t\tqueue<pair<int,int>> q;\n\t\tdist[sy][sx] = 0;\n\
    \t\tq.push({sy,sx});\n\t\twhile(q.size()){\n\t\t\tint y = q.front().first;\n\t\
    \t\tint x = q.front().second;\n\t\t\tq.pop();\n\n\t\t\tif(0 < y && S[y-1][x] ==\
    \ '.' && dist[y-1][x] == -1){\n\t\t\t\tdist[y-1][x] = dist[y][x] + 1;\n\t\t\t\t\
    q.push({y-1,x});\n\t\t\t}\n\t\t\tif(y < H - 1 && S[y+1][x] == '.' && dist[y+1][x]\
    \ == -1){\n\t\t\t\tdist[y+1][x] = dist[y][x] + 1;\n\t\t\t\tq.push({y+1,x});\n\t\
    \t\t}\n\t\t\tif(0 < x && S[y][x-1] == '.' && dist[y][x-1] == -1){\n\t\t\t\tdist[y][x-1]\
    \ = dist[y][x] + 1;\n\t\t\t\tq.push({y,x-1});\n\t\t\t}\n\t\t\tif(x < W - 1 &&\
    \ S[y][x+1] == '.' && dist[y][x+1] == -1){\n\t\t\t\tdist[y][x+1] = dist[y][x]\
    \ + 1;\n\t\t\t\tq.push({y,x+1});\n\t\t\t}\n\t\t}\n\t}\n};\n\n//verify https://atcoder.jp/contests/agc014/tasks/agc014_c\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n\nclass Grid_Breadth_First_Dearch{\n\
    public:\n\tint H,W;\n\tvector<string> S;\n\tvector<vector<int>> dist;\n\n\tGrid_Breadth_First_Dearch(int\
    \ H,int W):H(H),W(W),S(H),dist(H,vector<int>(W)){\n\t\t//do nothing\n\t}\n\n\t\
    void solve(int sy,int sx){\n\t\tfor(int i = 0; i < H; ++i) for(int j = 0; j <\
    \ W; ++j) dist[i][j] = -1;\n\t\tqueue<pair<int,int>> q;\n\t\tdist[sy][sx] = 0;\n\
    \t\tq.push({sy,sx});\n\t\twhile(q.size()){\n\t\t\tint y = q.front().first;\n\t\
    \t\tint x = q.front().second;\n\t\t\tq.pop();\n\n\t\t\tif(0 < y && S[y-1][x] ==\
    \ '.' && dist[y-1][x] == -1){\n\t\t\t\tdist[y-1][x] = dist[y][x] + 1;\n\t\t\t\t\
    q.push({y-1,x});\n\t\t\t}\n\t\t\tif(y < H - 1 && S[y+1][x] == '.' && dist[y+1][x]\
    \ == -1){\n\t\t\t\tdist[y+1][x] = dist[y][x] + 1;\n\t\t\t\tq.push({y+1,x});\n\t\
    \t\t}\n\t\t\tif(0 < x && S[y][x-1] == '.' && dist[y][x-1] == -1){\n\t\t\t\tdist[y][x-1]\
    \ = dist[y][x] + 1;\n\t\t\t\tq.push({y,x-1});\n\t\t\t}\n\t\t\tif(x < W - 1 &&\
    \ S[y][x+1] == '.' && dist[y][x+1] == -1){\n\t\t\t\tdist[y][x+1] = dist[y][x]\
    \ + 1;\n\t\t\t\tq.push({y,x+1});\n\t\t\t}\n\t\t}\n\t}\n};\n\n//verify https://atcoder.jp/contests/agc014/tasks/agc014_c"
  dependsOn: []
  isVerificationFile: false
  path: old/Grid_Breadth_First_Search.cpp
  requiredBy: []
  timestamp: '2020-01-09 00:30:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/Grid_Breadth_First_Search.cpp
layout: document
redirect_from:
- /library/old/Grid_Breadth_First_Search.cpp
- /library/old/Grid_Breadth_First_Search.cpp.html
title: old/Grid_Breadth_First_Search.cpp
---
