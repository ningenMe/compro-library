---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/00-util/FastIO.cpp
    title: FastIO
  - icon: ':heavy_check_mark:'
    path: lib/41-union-find-tree/UndoUnionFindTree.cpp
    title: "UndoUnionFindTree - Undo\u3064\u304D Union Find Tree"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"test/union-find-tree/UndoUnionFindTree.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\n#include\
    \ <vector>\n#include <iostream>\n#include <stack>\n#include <array>\nusing namespace\
    \ std;\n#line 1 \"lib/00-util/FastIO.cpp\"\n/*\n * @title FastIO\n * @docs md/util/FastIO.md\n\
    \ */\nclass FastIO{\nprivate:\n    inline static constexpr int ch_0='0';\n   \
    \ inline static constexpr int ch_9='9';\n    inline static constexpr int ch_n='-';\n\
    \    inline static constexpr int ch_s=' ';\n    inline static constexpr int ch_l='\\\
    n';\n    inline static void endline_skip(char& ch) {\n        while(ch==ch_l)\
    \ ch=getchar();\n    }\n    template<typename T> inline static void read_integer(T\
    \ &x) {\n        int neg=0; char ch; x=0;\n        ch=getchar();\n        endline_skip(ch);\n\
    \        if(ch==ch_n) neg=1,ch=getchar();\n        for(;(ch_0 <= ch && ch <= ch_9);\
    \ ch = getchar()) x = x*10 + (ch-ch_0);\n        if(neg) x*=-1;\n    }\n    template<typename\
    \ T> inline static void read_unsigned_integer(T &x) {\n        char ch; x=0;\n\
    \        ch=getchar();\n        endline_skip(ch);\n        for(;(ch_0 <= ch &&\
    \ ch <= ch_9); ch = getchar()) x = x*10 + (ch-ch_0);\n    }\n    inline static\
    \ void read_string(string &x) {\n        char ch; x=\"\";\n        ch=getchar();\n\
    \        endline_skip(ch);\n        for(;(ch != ch_s && ch!=ch_l); ch = getchar())\
    \ x.push_back(ch);\n    }\n    inline static char ar[40];\n    inline static char\
    \ *ch_ar;\n    template<typename T> inline static void write_integer(T x) {\n\
    \        ch_ar=ar;\n        if(x< 0) putchar(ch_n), x=-x;\n        if(x==0) putchar(ch_0);\n\
    \        for(;x;x/=10) *ch_ar++=(ch_0+x%10);\n        while(ch_ar--!=ar) putchar(*ch_ar);\n\
    \    }\npublic:\n    inline static void read(int &x) {read_integer<int>(x);}\n\
    \    inline static void read(long long &x) {read_integer<long long>(x);}\n   \
    \ inline static void read(unsigned int &x) {read_unsigned_integer<unsigned int>(x);}\n\
    \    inline static void read(unsigned long long &x) {read_unsigned_integer<unsigned\
    \ long long>(x);}\n    inline static void read(string &x) {read_string(x);}\n\
    \    inline static void read(__int128_t &x) {read_integer<__int128_t>(x);}\n \
    \   inline static void write(__int128_t x) {write_integer<__int128_t>(x);}\n \
    \   inline static void write(char x) {putchar(x);}\n};\n#define read(arg) FastIO::read(arg)\n\
    #define write(arg) FastIO::write(arg)\n#line 1 \"lib/41-union-find-tree/UndoUnionFindTree.cpp\"\
    \n/*\n * @title UndoUnionFindTree - Undo\u3064\u304D Union Find Tree\n * @docs\
    \ md/union-find-tree/UndoUnionFindTree.md\n */\nclass UndoUnionFindTree {\n  \
    \  vector<int> parent;\n    stack<array<int,2>> history;\n    inline int root(int\
    \ n) {\n        return (parent[n]<0?n:root(parent[n]));\n    }\npublic:\n    UndoUnionFindTree(const\
    \ int N = 1) : parent(N,-1){\n    }\n    inline bool connected(const int n, const\
    \ int m) {\n        return root(n) == root(m);\n    }\n    inline void merge(int\
    \ n,int m) {\n        n = root(n);\n        m = root(m);\n        history.push({n,parent[n]});\n\
    \        history.push({m,parent[m]});\n        if (n == m) return;\n        if(parent[n]>parent[m])\
    \ swap(n, m);\n        parent[n] += parent[m];\n        parent[m] = n;\n    }\n\
    \    inline int size(const int n){\n        return (-parent[root(n)]);\n    }\n\
    \    inline int operator[](const int n) {\n        return root(n);\n    }\n  \
    \  inline void print() {\n        for(int i = 0; i < parent.size(); ++i) cout\
    \ << root(i) << \" \";\n        cout << endl;\n    }\n    inline void undo() {\n\
    \        for(int i=0;i<2;++i) {\n            auto ar=history.top(); history.pop();\n\
    \            parent[ar[0]]=ar[1];\n        }\n    }\n};\n#line 10 \"test/union-find-tree/UndoUnionFindTree.test.cpp\"\
    \n\n\nint main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N,Q;\
    \ read(N), read(Q);\n    vector<int> t(Q+1),k(Q+1),u(Q+1),v(Q+1);\n    for(int\
    \ i=1;i<=Q;++i) {\n        read(t[i]), read(k[i]), read(u[i]), read(v[i]);\n \
    \       k[i]++;\n    }\n    vector<vector<int>> edge(Q+1);\n    vector<vector<int>>\
    \ query(Q+1);\n    vector<int> ans(Q+1,-1);\n    UndoUnionFindTree uf(N);\n  \
    \  for(int i=1;i<=Q;++i) {\n        if(t[i]==0) {\n            edge[k[i]].push_back(i);\n\
    \        }\n        if(t[i]==1) {\n            query[k[i]].push_back(i);\n   \
    \     }\n    }\n    auto dfs = [&](auto dfs, int pa) -> void {\n        for(int\
    \ i: query[pa]) {\n            ans[i] = uf.connected(u[i],v[i]);\n        }\n\
    \        for(int i: edge[pa]) {\n            uf.merge(u[i],v[i]);\n          \
    \  dfs(dfs,i);\n            uf.undo();\n        }\n    };\n    dfs(dfs,0);\n \
    \   for(int i=1;i<=Q;++i) {\n        if(ans[i]!=-1) cout << ans[i] << \"\\n\"\
    ; \n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    \n#include <vector>\n#include <iostream>\n#include <stack>\n#include <array>\n\
    using namespace std;\n#include \"../../lib/00-util/FastIO.cpp\"\n#include \"../../lib/41-union-find-tree/UndoUnionFindTree.cpp\"\
    \n\n\nint main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N,Q;\
    \ read(N), read(Q);\n    vector<int> t(Q+1),k(Q+1),u(Q+1),v(Q+1);\n    for(int\
    \ i=1;i<=Q;++i) {\n        read(t[i]), read(k[i]), read(u[i]), read(v[i]);\n \
    \       k[i]++;\n    }\n    vector<vector<int>> edge(Q+1);\n    vector<vector<int>>\
    \ query(Q+1);\n    vector<int> ans(Q+1,-1);\n    UndoUnionFindTree uf(N);\n  \
    \  for(int i=1;i<=Q;++i) {\n        if(t[i]==0) {\n            edge[k[i]].push_back(i);\n\
    \        }\n        if(t[i]==1) {\n            query[k[i]].push_back(i);\n   \
    \     }\n    }\n    auto dfs = [&](auto dfs, int pa) -> void {\n        for(int\
    \ i: query[pa]) {\n            ans[i] = uf.connected(u[i],v[i]);\n        }\n\
    \        for(int i: edge[pa]) {\n            uf.merge(u[i],v[i]);\n          \
    \  dfs(dfs,i);\n            uf.undo();\n        }\n    };\n    dfs(dfs,0);\n \
    \   for(int i=1;i<=Q;++i) {\n        if(ans[i]!=-1) cout << ans[i] << \"\\n\"\
    ; \n    }\n\n    return 0;\n}"
  dependsOn:
  - lib/00-util/FastIO.cpp
  - lib/41-union-find-tree/UndoUnionFindTree.cpp
  isVerificationFile: true
  path: test/union-find-tree/UndoUnionFindTree.test.cpp
  requiredBy: []
  timestamp: '2023-06-19 01:52:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/union-find-tree/UndoUnionFindTree.test.cpp
layout: document
redirect_from:
- /verify/test/union-find-tree/UndoUnionFindTree.test.cpp
- /verify/test/union-find-tree/UndoUnionFindTree.test.cpp.html
title: test/union-find-tree/UndoUnionFindTree.test.cpp
---
