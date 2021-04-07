---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/heap/RadixHeap.cpp
    title: "RadixHeap - 64bit\u578B\u975E\u8CA0\u6574\u6570heap"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/807
    links:
    - https://yukicoder.me/problems/no/807
  bundledCode: "#line 1 \"test/heap/RadixHeap.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/807\"\
    \n\n#include <vector>\n#include <iostream>\n#include <algorithm>\n#include <array>\n\
    using namespace std;\n#line 1 \"lib/heap/RadixHeap.cpp\"\n/*\n * @title RadixHeap\
    \ - 64bit\u578B\u975E\u8CA0\u6574\u6570heap\n * @docs md/heap/RadixHeap.md\n */\n\
    template<class T> class RadixHeap{\n\tusing TypeNode = pair<unsigned long long,\
    \ T>;\n\tarray<vector<TypeNode>,65> vq;\n\tunsigned long long size_num;\n\tTypeNode\
    \ last;\n\tinline int bit(unsigned long long a) {\n\t\treturn a ? 64 - __builtin_clzll(a)\
    \ : 0;\n\t}\npublic:\n\tRadixHeap(T mini) : size_num(0), last(make_pair(0,mini))\
    \ {\n\t\t// do nothing\n\t}\n\tinline bool empty() {\n\t\treturn size_num == 0;\n\
    \t}\n\tinline size_t size(){\n\t\treturn size_num;\n\t}\n\tinline void push(TypeNode\
    \ x){\n\t\t++size_num;\n\t\tvq[bit(x.first^last.first)].push_back(x);\n\t}\n\t\
    inline void emplace(unsigned long long key,T val){\n\t\t++size_num;\n\t\tvq[bit(key^last.first)].emplace_back(key,val);\n\
    \t}\n\tinline TypeNode pop() {\n\t\tif(vq[0].empty()) {\n\t\t\tint i = 1;\n\t\t\
    \twhile(vq[i].empty()) ++i;\n\t\t\tlast = *min_element(vq[i].begin(),vq[i].end());\n\
    \t\t\tfor(auto &p : vq[i]) vq[bit(p.first ^ last.first)].push_back(p);\n\t\t\t\
    vq[i].clear();\n\t\t}\n\t\t--size_num;\n\t\tauto res = vq[0].back();\n\t\tvq[0].pop_back();\n\
    \t\treturn res;\n\t}\n};\n#line 9 \"test/heap/RadixHeap.test.cpp\"\n\n//Dijkstra\n\
    template<class T> class Dijkstra {\npublic:\n\tint N;\n\tT inf;\n\tvector<T> cost;\n\
    \tvector<vector<pair<T, int>>> edge;\n\n\tDijkstra(const int N, T inf) : N(N),\
    \ inf(inf), cost(N), edge(N) {\n\t}\n\n\tvoid make_edge(int from, int to, T w)\
    \ {\n\t\tedge[from].push_back({ w,to });\n\t}\n\n\tvoid solve(int start) {\n\t\
    \tfor (int i = 0; i < N; ++i) cost[i] = inf;\n\n\t\tRadixHeap<int> pq(0);\n\t\t\
    cost[start] = 0;\n\t\tpq.push({ 0,start });\n\n\t\twhile (!pq.empty()) {\n\t\t\
    \tauto p = pq.pop();\n\t\t\tT v = p.first;\n\t\t\tint from = p.second;\n\t\t\t\
    if(cost[from]<v) continue;\n\t\t\tfor (auto u : edge[from]) {\n\t\t\t\tT w = v\
    \ + u.first;\n\t\t\t\tint to = u.second;\n\t\t\t\tif (w < cost[to]) {\n\t\t\t\t\
    \tcost[to] = w;\n\t\t\t\t\tpq.push({ w,to });\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\t\
    return;\n\t}\n};\n\nint main() {\n\tcin.tie(0);ios::sync_with_stdio(false);\n\t\
    int N, M; cin >> N >> M;\n\tDijkstra<long long> dijk(2*N, 1LL<<60);\n\tfor(int\
    \ i = 0; i < M; ++i){\n\t\tint a, b;\n\t\tlong long c;\n\t\tcin >> a >> b >> c;\n\
    \t\ta--, b--;\n\t\tdijk.make_edge(a, b, c);\n\t\tdijk.make_edge(b, a, c);\n\t\t\
    dijk.make_edge(a+N, b+N, c);\n\t\tdijk.make_edge(b+N, a+N, c);\n\t\tdijk.make_edge(a,\
    \ b+N, 0);\n\t\tdijk.make_edge(b, a+N, 0);\n\t}\n\tdijk.solve(0);\n\tdijk.cost[N]=0;\n\
    \tfor (int i = 0; i < N; ++i) cout << dijk.cost[i]+dijk.cost[i+N] << endl;\n\n\
    \treturn 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/807\"\n\n#include <vector>\n\
    #include <iostream>\n#include <algorithm>\n#include <array>\nusing namespace std;\n\
    #include \"../../lib/heap/RadixHeap.cpp\"\n\n//Dijkstra\ntemplate<class T> class\
    \ Dijkstra {\npublic:\n\tint N;\n\tT inf;\n\tvector<T> cost;\n\tvector<vector<pair<T,\
    \ int>>> edge;\n\n\tDijkstra(const int N, T inf) : N(N), inf(inf), cost(N), edge(N)\
    \ {\n\t}\n\n\tvoid make_edge(int from, int to, T w) {\n\t\tedge[from].push_back({\
    \ w,to });\n\t}\n\n\tvoid solve(int start) {\n\t\tfor (int i = 0; i < N; ++i)\
    \ cost[i] = inf;\n\n\t\tRadixHeap<int> pq(0);\n\t\tcost[start] = 0;\n\t\tpq.push({\
    \ 0,start });\n\n\t\twhile (!pq.empty()) {\n\t\t\tauto p = pq.pop();\n\t\t\tT\
    \ v = p.first;\n\t\t\tint from = p.second;\n\t\t\tif(cost[from]<v) continue;\n\
    \t\t\tfor (auto u : edge[from]) {\n\t\t\t\tT w = v + u.first;\n\t\t\t\tint to\
    \ = u.second;\n\t\t\t\tif (w < cost[to]) {\n\t\t\t\t\tcost[to] = w;\n\t\t\t\t\t\
    pq.push({ w,to });\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn;\n\t}\n};\n\nint main()\
    \ {\n\tcin.tie(0);ios::sync_with_stdio(false);\n\tint N, M; cin >> N >> M;\n\t\
    Dijkstra<long long> dijk(2*N, 1LL<<60);\n\tfor(int i = 0; i < M; ++i){\n\t\tint\
    \ a, b;\n\t\tlong long c;\n\t\tcin >> a >> b >> c;\n\t\ta--, b--;\n\t\tdijk.make_edge(a,\
    \ b, c);\n\t\tdijk.make_edge(b, a, c);\n\t\tdijk.make_edge(a+N, b+N, c);\n\t\t\
    dijk.make_edge(b+N, a+N, c);\n\t\tdijk.make_edge(a, b+N, 0);\n\t\tdijk.make_edge(b,\
    \ a+N, 0);\n\t}\n\tdijk.solve(0);\n\tdijk.cost[N]=0;\n\tfor (int i = 0; i < N;\
    \ ++i) cout << dijk.cost[i]+dijk.cost[i+N] << endl;\n\n\treturn 0;\n}\n"
  dependsOn:
  - lib/heap/RadixHeap.cpp
  isVerificationFile: true
  path: test/heap/RadixHeap.test.cpp
  requiredBy: []
  timestamp: '2020-09-26 16:29:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/heap/RadixHeap.test.cpp
layout: document
redirect_from:
- /verify/test/heap/RadixHeap.test.cpp
- /verify/test/heap/RadixHeap.test.cpp.html
title: test/heap/RadixHeap.test.cpp
---
