---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/00-util/FastIO.cpp
    title: FastIO
  - icon: ':heavy_check_mark:'
    path: lib/15-heap/RadixHeap.cpp
    title: "RadixHeap - \u975E\u8CA0\u6574\u6570heap"
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
  bundledCode: "#line 1 \"test/heap/RadixHeap-64bit.test.cpp\"\n#define PROBLEM \"\
    https://yukicoder.me/problems/no/807\"\n\n#include <vector>\n#include <iostream>\n\
    #include <algorithm>\n#include <array>\nusing namespace std;\n#line 1 \"lib/00-util/FastIO.cpp\"\
    \n/*\n * @title FastIO\n * @docs md/util/FastIO.md\n */\nclass FastIO{\nprivate:\n\
    \    inline static constexpr int ch_0='0';\n    inline static constexpr int ch_9='9';\n\
    \    inline static constexpr int ch_n='-';\n    inline static constexpr int ch_s='\
    \ ';\n    inline static constexpr int ch_l='\\n';\n    inline static void endline_skip(char&\
    \ ch) {\n        while(ch==ch_l) ch=getchar();\n    }\n    template<typename T>\
    \ inline static void read_integer(T &x) {\n        int neg=0; char ch; x=0;\n\
    \        ch=getchar();\n        endline_skip(ch);\n        if(ch==ch_n) neg=1,ch=getchar();\n\
    \        for(;(ch_0 <= ch && ch <= ch_9); ch = getchar()) x = x*10 + (ch-ch_0);\n\
    \        if(neg) x*=-1;\n    }\n    template<typename T> inline static void read_unsigned_integer(T\
    \ &x) {\n        char ch; x=0;\n        ch=getchar();\n        endline_skip(ch);\n\
    \        for(;(ch_0 <= ch && ch <= ch_9); ch = getchar()) x = x*10 + (ch-ch_0);\n\
    \    }\n    inline static void read_string(string &x) {\n        char ch; x=\"\
    \";\n        ch=getchar();\n        endline_skip(ch);\n        for(;(ch != ch_s\
    \ && ch!=ch_l); ch = getchar()) x.push_back(ch);\n    }\n    inline static char\
    \ ar[40];\n    inline static char *ch_ar;\n    template<typename T> inline static\
    \ void write_integer(T x) {\n        ch_ar=ar;\n        if(x< 0) putchar(ch_n),\
    \ x=-x;\n        if(x==0) putchar(ch_0);\n        for(;x;x/=10) *ch_ar++=(ch_0+x%10);\n\
    \        while(ch_ar--!=ar) putchar(*ch_ar);\n    }\npublic:\n    inline static\
    \ void read(int &x) {read_integer<int>(x);}\n    inline static void read(long\
    \ long &x) {read_integer<long long>(x);}\n    inline static void read(unsigned\
    \ int &x) {read_unsigned_integer<unsigned int>(x);}\n    inline static void read(unsigned\
    \ long long &x) {read_unsigned_integer<unsigned long long>(x);}\n    inline static\
    \ void read(string &x) {read_string(x);}\n    inline static void read(__int128_t\
    \ &x) {read_integer<__int128_t>(x);}\n    inline static void write(__int128_t\
    \ x) {write_integer<__int128_t>(x);}\n    inline static void write(char x) {putchar(x);}\n\
    };\n#define read(arg) FastIO::read(arg)\n#define write(arg) FastIO::write(arg)\n\
    #line 1 \"lib/15-heap/RadixHeap.cpp\"\n\n/*\n * @title RadixHeap - \u975E\u8CA0\
    \u6574\u6570heap\n * @docs md/heap/RadixHeap.md\n */\ntemplate<class T, class\
    \ Key = unsigned long long> class RadixHeap{\n    using TypeNode = pair<Key, T>;\n\
    \    template<class InnerKey, class ZZ=InnerKey> class Inner{};\n    template<class\
    \ InnerKey> class Inner<InnerKey, unsigned long long>{\n        array<vector<TypeNode>,65>\
    \ vq;\n        unsigned long long size_num;\n        TypeNode last;\n        inline\
    \ int bit(unsigned long long a) { return a ? 64 - __builtin_clzll(a) : 0;}\n \
    \   public:\n        Inner(T mini) : size_num(0), last(make_pair(0, mini)) {}\n\
    \        inline bool empty() { return size_num == 0; }\n        inline size_t\
    \ size(){ return size_num; }\n        inline void push(TypeNode x){ ++size_num;\
    \ vq[bit(x.first^last.first)].push_back(x);}\n        inline void emplace(unsigned\
    \ long long key,T val){ ++size_num; vq[bit(key^last.first)].emplace_back(key,val);}\n\
    \        inline TypeNode pop() {\n            if(vq[0].empty()) {\n          \
    \      int i = 1;\n                while(vq[i].empty()) ++i;\n               \
    \ last = *min_element(vq[i].begin(),vq[i].end());\n                for(auto &p\
    \ : vq[i]) vq[bit(p.first ^ last.first)].push_back(p);\n                vq[i].clear();\n\
    \            }\n            --size_num;\n            auto res = vq[0].back();\
    \ vq[0].pop_back();\n            return res;\n        }\n    };\n    template<class\
    \ InnerKey> class Inner<InnerKey, unsigned int>{\n        array<vector<TypeNode>,33>\
    \ vq;\n        unsigned int size_num;\n        TypeNode last;\n        inline\
    \ int bit(unsigned int a) { return a ? 32 - __builtin_clz(a) : 0;}\n    public:\n\
    \        Inner(T mini) : size_num(0), last(make_pair(0, mini)) {}\n        inline\
    \ bool empty() { return size_num == 0; }\n        inline size_t size(){ return\
    \ size_num; }\n        inline void push(TypeNode x){ ++size_num; vq[bit(x.first^last.first)].push_back(x);}\n\
    \        inline void emplace(unsigned int key,T val){ ++size_num; vq[bit(key^last.first)].emplace_back(key,val);}\n\
    \        inline TypeNode pop() {\n            if(vq[0].empty()) {\n          \
    \      int i = 1;\n                while(vq[i].empty()) ++i;\n               \
    \ last = *min_element(vq[i].begin(),vq[i].end());\n                for(auto &p\
    \ : vq[i]) vq[bit(p.first ^ last.first)].push_back(p);\n                vq[i].clear();\n\
    \            }\n            --size_num;\n            auto res = vq[0].back();\
    \ vq[0].pop_back();\n            return res;\n        }\n    };\n    Inner<Key,Key>\
    \ inner;\npublic:\n    RadixHeap(T mini) : inner(mini) {}\n    inline bool empty()\
    \ { return inner.empty();}\n    inline size_t size(){ return inner.size();}\n\
    \    inline void push(TypeNode x){ inner.push(x);}\n    inline void emplace(unsigned\
    \ long long key,T val){ inner.emplace(key,val);}\n    inline TypeNode pop() {\
    \ return inner.pop(); }\n};\n#line 10 \"test/heap/RadixHeap-64bit.test.cpp\"\n\
    \n//Dijkstra\ntemplate<class T> class Dijkstra {\npublic:\n\tint N;\n\tT inf;\n\
    \tvector<T> cost;\n\tvector<vector<pair<T, int>>> edge;\n\n\tDijkstra(const int\
    \ N, T inf) : N(N), inf(inf), cost(N), edge(N) {\n\t}\n\n\tvoid make_edge(int\
    \ from, int to, T w) {\n\t\tedge[from].push_back({ w,to });\n\t}\n\n\tvoid solve(int\
    \ start) {\n\t\tfor (int i = 0; i < N; ++i) cost[i] = inf;\n\n\t\tRadixHeap<int,unsigned\
    \ long long> pq(0);\n\t\tcost[start] = 0;\n\t\tpq.push({ 0,start });\n\n\t\twhile\
    \ (!pq.empty()) {\n\t\t\tauto p = pq.pop();\n\t\t\tT v = p.first;\n\t\t\tint from\
    \ = p.second;\n\t\t\tif(cost[from]<v) continue;\n\t\t\tfor (auto u : edge[from])\
    \ {\n\t\t\t\tT w = v + u.first;\n\t\t\t\tint to = u.second;\n\t\t\t\tif (w < cost[to])\
    \ {\n\t\t\t\t\tcost[to] = w;\n\t\t\t\t\tpq.push({ w,to });\n\t\t\t\t}\n\t\t\t\
    }\n\t\t}\n\t\treturn;\n\t}\n};\n\nint main() {\n\tcin.tie(0);ios::sync_with_stdio(false);\n\
    \tint N, M; \n    read(N); read(M);\n\tDijkstra<long long> dijk(2*N, 1LL<<60);\n\
    \tfor(int i = 0; i < M; ++i){\n\t\tint a, b;\n\t\tlong long c;\n        read(a);\
    \ read(b); read(c);\n\t\ta--, b--;\n\t\tdijk.make_edge(a, b, c);\n\t\tdijk.make_edge(b,\
    \ a, c);\n\t\tdijk.make_edge(a+N, b+N, c);\n\t\tdijk.make_edge(b+N, a+N, c);\n\
    \t\tdijk.make_edge(a, b+N, 0);\n\t\tdijk.make_edge(b, a+N, 0);\n\t}\n\tdijk.solve(0);\n\
    \tdijk.cost[N]=0;\n\tfor (int i = 0; i < N; ++i) cout << dijk.cost[i]+dijk.cost[i+N]\
    \ << \"\\n\";\n\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/807\"\n\n#include <vector>\n\
    #include <iostream>\n#include <algorithm>\n#include <array>\nusing namespace std;\n\
    #include \"../../lib/00-util/FastIO.cpp\"\n#include \"../../lib/15-heap/RadixHeap.cpp\"\
    \n\n//Dijkstra\ntemplate<class T> class Dijkstra {\npublic:\n\tint N;\n\tT inf;\n\
    \tvector<T> cost;\n\tvector<vector<pair<T, int>>> edge;\n\n\tDijkstra(const int\
    \ N, T inf) : N(N), inf(inf), cost(N), edge(N) {\n\t}\n\n\tvoid make_edge(int\
    \ from, int to, T w) {\n\t\tedge[from].push_back({ w,to });\n\t}\n\n\tvoid solve(int\
    \ start) {\n\t\tfor (int i = 0; i < N; ++i) cost[i] = inf;\n\n\t\tRadixHeap<int,unsigned\
    \ long long> pq(0);\n\t\tcost[start] = 0;\n\t\tpq.push({ 0,start });\n\n\t\twhile\
    \ (!pq.empty()) {\n\t\t\tauto p = pq.pop();\n\t\t\tT v = p.first;\n\t\t\tint from\
    \ = p.second;\n\t\t\tif(cost[from]<v) continue;\n\t\t\tfor (auto u : edge[from])\
    \ {\n\t\t\t\tT w = v + u.first;\n\t\t\t\tint to = u.second;\n\t\t\t\tif (w < cost[to])\
    \ {\n\t\t\t\t\tcost[to] = w;\n\t\t\t\t\tpq.push({ w,to });\n\t\t\t\t}\n\t\t\t\
    }\n\t\t}\n\t\treturn;\n\t}\n};\n\nint main() {\n\tcin.tie(0);ios::sync_with_stdio(false);\n\
    \tint N, M; \n    read(N); read(M);\n\tDijkstra<long long> dijk(2*N, 1LL<<60);\n\
    \tfor(int i = 0; i < M; ++i){\n\t\tint a, b;\n\t\tlong long c;\n        read(a);\
    \ read(b); read(c);\n\t\ta--, b--;\n\t\tdijk.make_edge(a, b, c);\n\t\tdijk.make_edge(b,\
    \ a, c);\n\t\tdijk.make_edge(a+N, b+N, c);\n\t\tdijk.make_edge(b+N, a+N, c);\n\
    \t\tdijk.make_edge(a, b+N, 0);\n\t\tdijk.make_edge(b, a+N, 0);\n\t}\n\tdijk.solve(0);\n\
    \tdijk.cost[N]=0;\n\tfor (int i = 0; i < N; ++i) cout << dijk.cost[i]+dijk.cost[i+N]\
    \ << \"\\n\";\n\n\treturn 0;\n}\n"
  dependsOn:
  - lib/00-util/FastIO.cpp
  - lib/15-heap/RadixHeap.cpp
  isVerificationFile: true
  path: test/heap/RadixHeap-64bit.test.cpp
  requiredBy: []
  timestamp: '2023-05-31 03:07:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/heap/RadixHeap-64bit.test.cpp
layout: document
redirect_from:
- /verify/test/heap/RadixHeap-64bit.test.cpp
- /verify/test/heap/RadixHeap-64bit.test.cpp.html
title: test/heap/RadixHeap-64bit.test.cpp
---
