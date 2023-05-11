---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/Dinic.cpp
    title: "Dinic - Dinic\u30D5\u30ED\u30FC"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/904
    links:
    - https://yukicoder.me/problems/no/904
  bundledCode: "#line 1 \"test/graph/Dinic.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/904\"\
    \n\n#include <vector>\n#include <iostream>\n#include <queue>\nusing namespace\
    \ std;\n#line 1 \"lib/graph/Dinic.cpp\"\n/*\n * @title Dinic - Dinic\u30D5\u30ED\
    \u30FC\n * @docs md/graph/Dinic.md\n */\ntemplate <class T> class Dinic {\n  \
    \  struct info {\n        int to, rev;\n        T cap;\n    };\n    T ini, inf;\n\
    \    vector<vector<info>> edge;\n    vector<int> level, iter;\n\n    inline void\
    \ bfs(int start) {\n        for (int i = 0; i < level.size(); ++i) level[i] =\
    \ -1;\n        queue<int> q;\n        level[start] = 0;\n        q.push(start);\n\
    \        while (q.size()) {\n            int from = q.front();\n            q.pop();\n\
    \            for (auto& e : edge[from]) {\n                if (e.cap > 0 && level[e.to]\
    \ < 0) {\n                    level[e.to] = level[from] + 1;\n               \
    \     q.push(e.to);\n                }\n            }\n        }\n    }\n\n  \
    \  inline T dfs(int from, int goal, T flow) {\n        if (from == goal) return\
    \ flow;\n        for (int& i = iter[from]; i < edge[from].size(); ++i) {\n   \
    \         auto& e = edge[from][i];\n            if (e.cap <= 0 || level[from]\
    \ >= level[e.to]) continue;\n            T dflow = dfs(e.to, goal, min(flow, e.cap));\n\
    \            if (dflow <= 0) continue;\n            e.cap -= dflow;\n        \
    \    edge[e.to][e.rev].cap += dflow;\n            return dflow;\n        }\n \
    \       return ini;\n    }\n\npublic:\n    Dinic(int N, T ini, T inf) : edge(N),\
    \ level(N), iter(N), ini(ini), inf(inf) {\n        // do nothing\n    }\n\n  \
    \  inline void make_edge(int from, int to, T cap) {\n        edge[from].push_back({\
    \ to, (int)edge[to].size(), cap });\n        edge[to].push_back({ from, (int)edge[from].size()\
    \ - 1, ini });\n    }\n\n    inline T maxflow(int start, int goal) {\n       \
    \ T maxflow = ini;\n        while (1) {\n            bfs(start);\n           \
    \ if (level[goal] < 0) return maxflow;\n            for (int i = 0; i < iter.size();\
    \ ++i) iter[i] = 0;\n            T flow;\n            while ((flow = dfs(start,\
    \ goal, inf))>0) maxflow += flow;\n        }\n    }\n};\n\n//verify https://atcoder.jp/contests/arc085/tasks/arc085_c\n\
    \n#line 8 \"test/graph/Dinic.test.cpp\"\n\nint main() {\n\tint N; cin >> N;\n\t\
    vector<int> A(N),B(N);\n\tfor(int i = 1; i < N; ++i) cin >> A[i] >> B[i];\n\t\
    Dinic<int>  dinic(2*N,0,1234567);\n\tfor(int i = 1; i < N; ++i) {\n\t\tfor(int\
    \ j = 1; j < N; ++j) {\n\t\t\tif(i==j) continue;\n\t\t\tdinic.make_edge(i,j+N,1234567);\n\
    \t\t}\n\t}\n\tfor(int i = 1; i < N; ++i) dinic.make_edge(0,i,A[i]);\n\tfor(int\
    \ i = 1; i < N; ++i) dinic.make_edge(i+N,N,B[i]);\n\tcout << dinic.maxflow(0,N)+1\
    \ << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/904\"\n\n#include <vector>\n\
    #include <iostream>\n#include <queue>\nusing namespace std;\n#include \"../../lib/graph/Dinic.cpp\"\
    \n\nint main() {\n\tint N; cin >> N;\n\tvector<int> A(N),B(N);\n\tfor(int i =\
    \ 1; i < N; ++i) cin >> A[i] >> B[i];\n\tDinic<int>  dinic(2*N,0,1234567);\n\t\
    for(int i = 1; i < N; ++i) {\n\t\tfor(int j = 1; j < N; ++j) {\n\t\t\tif(i==j)\
    \ continue;\n\t\t\tdinic.make_edge(i,j+N,1234567);\n\t\t}\n\t}\n\tfor(int i =\
    \ 1; i < N; ++i) dinic.make_edge(0,i,A[i]);\n\tfor(int i = 1; i < N; ++i) dinic.make_edge(i+N,N,B[i]);\n\
    \tcout << dinic.maxflow(0,N)+1 << endl;\n    return 0;\n}"
  dependsOn:
  - lib/graph/Dinic.cpp
  isVerificationFile: true
  path: test/graph/Dinic.test.cpp
  requiredBy: []
  timestamp: '2023-05-12 02:35:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/Dinic.test.cpp
layout: document
redirect_from:
- /verify/test/graph/Dinic.test.cpp
- /verify/test/graph/Dinic.test.cpp.html
title: test/graph/Dinic.test.cpp
---
