---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/00-util/FastIO.cpp
    title: FastIO
  - icon: ':heavy_check_mark:'
    path: lib/40-graph/UnionFindTree.cpp
    title: "UnionFindTree - Union Find \u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/graph/UnionFindTree.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/unionfind\"\n\n#include <vector>\n#include <iostream>\n\
    #include <numeric>\nusing namespace std;\n#line 1 \"lib/00-util/FastIO.cpp\"\n\
    /*\n * @title FastIO\n * @docs md/util/FastIO.md\n */\nclass FastIO{\nprivate:\n\
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
    #line 1 \"lib/40-graph/UnionFindTree.cpp\"\n/*\n * @title UnionFindTree - Union\
    \ Find \u6728\n * @docs md/graph/UnionFindTree.md\n */\nclass UnionFindTree {\n\
    \    vector<int> parent,maxi,mini;\n    inline int root(int n) {\n        return\
    \ (parent[n]<0?n:parent[n] = root(parent[n]));\n    }\npublic:\n    UnionFindTree(const\
    \ int N = 1) : parent(N,-1),maxi(N),mini(N){\n        iota(maxi.begin(),maxi.end(),0);\n\
    \        iota(mini.begin(),mini.end(),0);\n    }\n    inline bool connected(const\
    \ int n, const int m) {\n        return root(n) == root(m);\n    }\n    inline\
    \ void merge(int n,int m) {\n        n = root(n);\n        m = root(m);\n    \
    \    if (n == m) return;\n        if(parent[n]>parent[m]) swap(n, m);\n      \
    \  parent[n] += parent[m];\n        parent[m] = n;\n        maxi[n] = std::max(maxi[n],maxi[m]);\n\
    \        mini[n] = std::min(mini[n],mini[m]);\n    }\n    inline int min(const\
    \ int n) {\n        return mini[root(n)];\n    }\n    inline int max(const int\
    \ n) {\n        return maxi[root(n)];\n    }\n    inline int size(const int n){\n\
    \        return (-parent[root(n)]);\n    }\n    inline int operator[](const int\
    \ n) {\n        return root(n);\n    }\n    inline void print() {\n        for(int\
    \ i = 0; i < parent.size(); ++i) cout << root(i) << \" \";\n        cout << endl;\n\
    \    }\n};\n#line 9 \"test/graph/UnionFindTree.test.cpp\"\n\n\nint main(){\n \
    \   cin.tie(0)->sync_with_stdio(0);\n    int N,Q; \n    read(N); read(Q);\n  \
    \  UnionFindTree uf(N);\n    while(Q--){\n        int q,a,b; \n        read(q);read(a);read(b);\n\
    \        if(q) cout << uf.connected(a,b) << \"\\n\";\n        else uf.merge(a,b);\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <vector>\n#include <iostream>\n#include <numeric>\nusing namespace std;\n#include\
    \ \"../../lib/00-util/FastIO.cpp\"\n#include \"../../lib/40-graph/UnionFindTree.cpp\"\
    \n\n\nint main(){\n    cin.tie(0)->sync_with_stdio(0);\n    int N,Q; \n    read(N);\
    \ read(Q);\n    UnionFindTree uf(N);\n    while(Q--){\n        int q,a,b; \n \
    \       read(q);read(a);read(b);\n        if(q) cout << uf.connected(a,b) << \"\
    \\n\";\n        else uf.merge(a,b);\n    }\n}\n"
  dependsOn:
  - lib/00-util/FastIO.cpp
  - lib/40-graph/UnionFindTree.cpp
  isVerificationFile: true
  path: test/graph/UnionFindTree.test.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:49:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/UnionFindTree.test.cpp
layout: document
redirect_from:
- /verify/test/graph/UnionFindTree.test.cpp
- /verify/test/graph/UnionFindTree.test.cpp.html
title: test/graph/UnionFindTree.test.cpp
---
