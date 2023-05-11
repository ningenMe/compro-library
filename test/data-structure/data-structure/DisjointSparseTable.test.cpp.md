---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data-structure/data-structure/DisjointSparseTable.cpp
    title: DisjointSparseTable
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
  bundledCode: "#line 1 \"test/data-structure/data-structure/DisjointSparseTable.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#include\
    \ <vector>\n#include <iostream>\nusing namespace std;\n#line 1 \"lib/data-structure/data-structure/DisjointSparseTable.cpp\"\
    \n/*\n * @title DisjointSparseTable\n * @docs md/data-structure/data-structure/DisjointSparseTable.md\n\
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
    \ TypeNode func_fold(TypeNode l,TypeNode r){return l+r;}\n};\n#line 7 \"test/data-structure/data-structure/DisjointSparseTable.test.cpp\"\
    \n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; cin\
    \ >> N >> Q;\n    vector<long long> A(N);\n    for(int i = 0; i < N; ++i) {\n\
    \        cin >> A[i];\n    }\n    DisjointSparseTable<NodeSum<long long>> st(A);\n\
    \    while(Q--){\n        int l,r; cin >> l >> r;\n        cout << st.fold(l,r)\
    \ << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include <vector>\n#include <iostream>\nusing namespace std;\n#include \"../../../lib/data-structure/data-structure/DisjointSparseTable.cpp\"\
    \n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; cin\
    \ >> N >> Q;\n    vector<long long> A(N);\n    for(int i = 0; i < N; ++i) {\n\
    \        cin >> A[i];\n    }\n    DisjointSparseTable<NodeSum<long long>> st(A);\n\
    \    while(Q--){\n        int l,r; cin >> l >> r;\n        cout << st.fold(l,r)\
    \ << endl;\n    }\n}"
  dependsOn:
  - lib/data-structure/data-structure/DisjointSparseTable.cpp
  isVerificationFile: true
  path: test/data-structure/data-structure/DisjointSparseTable.test.cpp
  requiredBy: []
  timestamp: '2023-05-12 04:20:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/data-structure/DisjointSparseTable.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/data-structure/DisjointSparseTable.test.cpp
- /verify/test/data-structure/data-structure/DisjointSparseTable.test.cpp.html
title: test/data-structure/data-structure/DisjointSparseTable.test.cpp
---
