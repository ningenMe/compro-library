---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data-structure/range-query/DisjointSparseTable.cpp
    title: DisjointSparseTable
  - icon: ':heavy_check_mark:'
    path: lib/util/FastIO.cpp
    title: FastIO
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/data-structure/range-query/DisjointSparseTable.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#include\
    \ <vector>\n#include <iostream>\nusing namespace std;\n#line 1 \"lib/util/FastIO.cpp\"\
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
    #line 1 \"lib/data-structure/range-query/DisjointSparseTable.cpp\"\n/*\n * @title\
    \ DisjointSparseTable\n * @docs md/data-structure/range-query/DisjointSparseTable.md\n\
    \ */\ntemplate<class Operator> class DisjointSparseTable{\npublic:\n    using\
    \ TypeNode = typename Operator::TypeNode;\n    size_t depth;\n    size_t length;\n\
    \    vector<TypeNode> node;\n    vector<size_t> msb;\n\n    DisjointSparseTable(const\
    \ vector<TypeNode>& vec) {\n        for(depth = 0;(1<<depth)<=vec.size();++depth);\n\
    \        length = (1<<depth);\n\n        //msb\n        msb.resize(length,0);\n\
    \        for(int i = 0; i < length; ++i) for(int j = 0; j < depth; ++j) if(i>>j)\
    \ msb[i] = j;\n\n        //init value\n        node.resize(depth*length,Operator::unit_node);\n\
    \        for(int i = 0; i < vec.size(); ++i) node[i] = vec[i];\n\n        for(int\
    \ i = 1; i < depth; ++i) {\n            for(int r = (1<<i),l = r-1; r < length;\
    \ r += (2<<i),l = r-1){\n                //init accumulate\n                node[i*length+l]\
    \ = node[l];\n                node[i*length+r] = node[r];\n                //accumulate\n\
    \                for(int k = 1; k < (1<<i); ++k) {\n                    node[i*length+l-k]\
    \ = Operator::func_fold(node[i*length+l-k+1],node[l-k]);\n                   \
    \ node[i*length+r+k] = Operator::func_fold(node[i*length+r+k-1],node[r+k]);\n\
    \                }\n            }\n        }\n    }\n\n    //[l,r)\n    TypeNode\
    \ fold(int l,int r) {\n        r--;\n        return (l>r||l<0||length<=r) ? Operator::unit_node:\
    \ (l==r ? node[l] : Operator::func_fold(node[msb[l^r]*length+l],node[msb[l^r]*length+r]));\n\
    \    }\n};\n\n//sum\ntemplate<class T> struct NodeSum {\n    using TypeNode =\
    \ T;\n    inline static constexpr TypeNode unit_node = 0;\n    inline static constexpr\
    \ TypeNode func_fold(TypeNode l,TypeNode r){return l+r;}\n};\n#line 8 \"test/data-structure/range-query/DisjointSparseTable.test.cpp\"\
    \n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; \n\
    \tread(N); read(Q);\n    vector<long long> A(N);\n    for(int i = 0; i < N; ++i)\
    \ {\n        read(A[i]);\n    }\n    DisjointSparseTable<NodeSum<long long>> st(A);\n\
    \    while(Q--){\n\t\tint l,r;\n\t\tread(l); read(r);\n        cout << st.fold(l,r)\
    \ << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include <vector>\n#include <iostream>\nusing namespace std;\n#include \"../../../lib/util/FastIO.cpp\"\
    \n#include \"../../../lib/data-structure/range-query/DisjointSparseTable.cpp\"\
    \n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; \n\
    \tread(N); read(Q);\n    vector<long long> A(N);\n    for(int i = 0; i < N; ++i)\
    \ {\n        read(A[i]);\n    }\n    DisjointSparseTable<NodeSum<long long>> st(A);\n\
    \    while(Q--){\n\t\tint l,r;\n\t\tread(l); read(r);\n        cout << st.fold(l,r)\
    \ << \"\\n\";\n    }\n}"
  dependsOn:
  - lib/util/FastIO.cpp
  - lib/data-structure/range-query/DisjointSparseTable.cpp
  isVerificationFile: true
  path: test/data-structure/range-query/DisjointSparseTable.test.cpp
  requiredBy: []
  timestamp: '2023-05-15 02:45:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/range-query/DisjointSparseTable.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/range-query/DisjointSparseTable.test.cpp
- /verify/test/data-structure/range-query/DisjointSparseTable.test.cpp.html
title: test/data-structure/range-query/DisjointSparseTable.test.cpp
---
