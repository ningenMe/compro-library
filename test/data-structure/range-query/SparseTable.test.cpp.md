---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/00-util/FastIO.cpp
    title: FastIO
  - icon: ':heavy_check_mark:'
    path: lib/data-structure/range-query/SparseTable.cpp
    title: SparseTable
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/data-structure/range-query/SparseTable.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include <vector>\n\
    #include <iostream>\nusing namespace std;\n#line 1 \"lib/00-util/FastIO.cpp\"\n\
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
    #line 1 \"lib/data-structure/range-query/SparseTable.cpp\"\n/*\n * @title SparseTable\n\
    \ * @docs md/data-structure/range-query/SparseTable.md\n */\ntemplate<class Operator>\
    \ class SparseTable{\npublic:\n    using TypeNode = typename Operator::TypeNode;\n\
    \    vector<TypeNode> node;\n    vector<size_t> idx;\n    size_t depth;\n    size_t\
    \ length;\n\n    SparseTable(const vector<TypeNode>& vec) {\n        for(depth\
    \ = 0;(1<<depth)<=vec.size();++depth);\n        length = (1<<depth);\n       \
    \ node.resize(depth*length);\n        for(int i = 0; i < vec.size(); ++i) node[i]\
    \ = vec[i];\n        for(int i = 1; i < depth; ++i) for(int j = 0; j + (1<<i)\
    \ < (1<<depth); ++j) node[i*length+j] = Operator::func_fold(node[(i-1)*length+j],node[(i-1)*length+j\
    \ + (1 << (i-1))]);\n        idx.resize(vec.size()+1);\n        for(int i = 2;\
    \ i < vec.size()+1; ++i) idx[i] = idx[i>>1] + 1;\n    }\n\n    //[l,r)\n    TypeNode\
    \ fold(const int l,const int r) {\n        size_t bit = idx[r-l];\n        return\
    \ Operator::func_fold(node[bit*length+l],node[bit*length+r - (1<<bit)]);\n   \
    \ }\n};\n\ntemplate<class T> struct NodeMin {\n    using TypeNode = T;\n    inline\
    \ static constexpr TypeNode unitNode = 1LL<<31;\n    inline static constexpr TypeNode\
    \ func_fold(TypeNode l,TypeNode r){return min(l,r);}\n};\n#line 8 \"test/data-structure/range-query/SparseTable.test.cpp\"\
    \n\nint main(){\n\tcin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; \n\t\
    read(N); read(Q);\n    vector<long long> A(N);\n    for(int i = 0; i < N; ++i)\
    \ {\n        read(A[i]);\n    }\n    SparseTable<NodeMin<long long>> st(A);\n\
    \    while(Q--){\n        int l,r; \n\t\tread(l);read(r);\n        cout << st.fold(l,r)\
    \ << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <vector>\n#include <iostream>\nusing namespace std;\n#include \"../../../lib/00-util/FastIO.cpp\"\
    \n#include \"../../../lib/data-structure/range-query/SparseTable.cpp\"\n\nint\
    \ main(){\n\tcin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; \n\tread(N);\
    \ read(Q);\n    vector<long long> A(N);\n    for(int i = 0; i < N; ++i) {\n  \
    \      read(A[i]);\n    }\n    SparseTable<NodeMin<long long>> st(A);\n    while(Q--){\n\
    \        int l,r; \n\t\tread(l);read(r);\n        cout << st.fold(l,r) << \"\\\
    n\";\n    }\n}"
  dependsOn:
  - lib/00-util/FastIO.cpp
  - lib/data-structure/range-query/SparseTable.cpp
  isVerificationFile: true
  path: test/data-structure/range-query/SparseTable.test.cpp
  requiredBy: []
  timestamp: '2023-05-30 03:51:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/range-query/SparseTable.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/range-query/SparseTable.test.cpp
- /verify/test/data-structure/range-query/SparseTable.test.cpp.html
title: test/data-structure/range-query/SparseTable.test.cpp
---
