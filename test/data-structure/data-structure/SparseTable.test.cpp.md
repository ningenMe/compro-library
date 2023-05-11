---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data-structure/data-structure/SparseTable.cpp
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
  bundledCode: "#line 1 \"test/data-structure/data-structure/SparseTable.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include <vector>\n\
    #include <iostream>\nusing namespace std;\n#line 1 \"lib/data-structure/data-structure/SparseTable.cpp\"\
    \n/*\n * @title SparseTable\n * @docs md/data-structure/data-structure/SparseTable.md\n\
    \ */\ntemplate<class Operator> class SparseTable{\npublic:\n    using TypeNode\
    \ = typename Operator::TypeNode;\n    vector<TypeNode> node;\n    vector<int>\
    \ idx;\n    size_t depth;\n    size_t length;\n\n    SparseTable(const vector<TypeNode>&\
    \ vec) {\n        for(depth = 0;(1<<depth)<=vec.size();++depth);\n        length\
    \ = (1<<depth);\n        node.resize(depth*length);\n        for(int i = 0; i\
    \ < vec.size(); ++i) node[i] = vec[i];\n        for(int i = 1; i < depth; ++i)\
    \ for(int j = 0; j + (1<<i) < (1<<depth); ++j) node[i*length+j] = Operator::func_node(node[(i-1)*length+j],node[(i-1)*length+j\
    \ + (1 << (i-1))]);\n        idx.resize(vec.size()+1);\n        for(int i = 2;\
    \ i < vec.size()+1; ++i) idx[i] = idx[i>>1] + 1;\n    }\n\n    //[l,r)\n    TypeNode\
    \ get(int l,int r) {\n        int bit = idx[r-l];\n        return Operator::func_node(node[bit*length+l],node[bit*length+r\
    \ - (1<<bit)]);\n    }\n};\n\ntemplate<class T> struct NodeMin {\n    using TypeNode\
    \ = T;\n    inline static constexpr TypeNode unitNode = 1LL<<31;\n    inline static\
    \ constexpr TypeNode func_node(TypeNode l,TypeNode r){return min(l,r);}\n};\n\
    #line 7 \"test/data-structure/data-structure/SparseTable.test.cpp\"\n\nint main(void){\n\
    \tcin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; cin >> N >> Q;\n    vector<long\
    \ long> A(N);\n    for(int i = 0; i < N; ++i) {\n        cin >> A[i];\n    }\n\
    \    SparseTable<NodeMin<long long>> st(A);\n    while(Q--){\n        int l,r;\
    \ cin >> l >> r;\n        cout << st.get(l,r) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <vector>\n#include <iostream>\nusing namespace std;\n#include \"../../../lib/data-structure/data-structure/SparseTable.cpp\"\
    \n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; cin\
    \ >> N >> Q;\n    vector<long long> A(N);\n    for(int i = 0; i < N; ++i) {\n\
    \        cin >> A[i];\n    }\n    SparseTable<NodeMin<long long>> st(A);\n   \
    \ while(Q--){\n        int l,r; cin >> l >> r;\n        cout << st.get(l,r) <<\
    \ endl;\n    }\n}"
  dependsOn:
  - lib/data-structure/data-structure/SparseTable.cpp
  isVerificationFile: true
  path: test/data-structure/data-structure/SparseTable.test.cpp
  requiredBy: []
  timestamp: '2023-05-12 04:20:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/data-structure/SparseTable.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/data-structure/SparseTable.test.cpp
- /verify/test/data-structure/data-structure/SparseTable.test.cpp.html
title: test/data-structure/data-structure/SparseTable.test.cpp
---
