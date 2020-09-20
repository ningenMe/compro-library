---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/segment/DisjointSparseTable.cpp
    title: DisjointSparseTable
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/segment/DisjointSparseTable.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#include <vector>\n\
    #include <iostream>\nusing namespace std;\n#line 1 \"lib/segment/DisjointSparseTable.cpp\"\
    \n/*\n * @title DisjointSparseTable\n */\ntemplate<class Operator> class DisjointSparseTable{\n\
    public:\n\tusing TypeNode = typename Operator::TypeNode;\n\tsize_t depth;\n\t\
    size_t length;\n\tvector<TypeNode> node;\n\tvector<size_t> msb;\n\n\tDisjointSparseTable(const\
    \ vector<TypeNode>& vec) {\n\t\tfor(depth = 0;(1<<depth)<=vec.size();++depth);\n\
    \t\tlength = (1<<depth);\n\t\t\n\t\t//msb\n\t\tmsb.resize(length,0);\n\t\tfor(int\
    \ i = 0; i < length; ++i) for(int j = 0; j < depth; ++j) if(i>>j) msb[i] = j;\n\
    \n\t\t//init value\n\t\tnode.resize(depth*length,Operator::unit_node);\n\t\tfor(int\
    \ i = 0; i < vec.size(); ++i) node[i] = vec[i];\n\n\t\tfor(int i = 1; i < depth;\
    \ ++i) {\n\t\t\tfor(int r = (1<<i),l = r-1; r < length; r += (2<<i),l = r-1){\n\
    \t\t\t\t//init accumulate\n\t\t\t\tnode[i*length+l] = node[l];\n\t\t\t\tnode[i*length+r]\
    \ = node[r];\n\t\t\t\t//accumulate\n\t\t\t\tfor(int k = 1; k < (1<<i); ++k) {\n\
    \t\t\t\t\tnode[i*length+l-k] = Operator::func_node(node[i*length+l-k+1],node[l-k]);\n\
    \t\t\t\t\tnode[i*length+r+k] = Operator::func_node(node[i*length+r+k-1],node[r+k]);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\t//[l,r)\n\tTypeNode get(int l,int r) {\n\t\
    \tr--;\n\t\treturn (l>r||l<0||length<=r) ? Operator::unit_node: (l==r ? node[l]\
    \ : Operator::func_node(node[msb[l^r]*length+l],node[msb[l^r]*length+r]));\n\t\
    }\n};\n\n//sum\ntemplate<class T> struct NodeSum {\n\tusing TypeNode = T;\n\t\
    inline static constexpr TypeNode unit_node = 0;\n\tinline static constexpr TypeNode\
    \ func_node(TypeNode l,TypeNode r){return l+r;}\n};\n#line 7 \"test/segment/DisjointSparseTable.test.cpp\"\
    \n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; cin\
    \ >> N >> Q;\n    vector<long long> A(N);\n    for(int i = 0; i < N; ++i) {\n\
    \        cin >> A[i];\n    }\n    DisjointSparseTable<NodeSum<long long>> st(A);\n\
    \    while(Q--){\n        int l,r; cin >> l >> r;\n        cout << st.get(l,r)\
    \ << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include <vector>\n#include <iostream>\nusing namespace std;\n#include \"../../lib/segment/DisjointSparseTable.cpp\"\
    \n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; cin\
    \ >> N >> Q;\n    vector<long long> A(N);\n    for(int i = 0; i < N; ++i) {\n\
    \        cin >> A[i];\n    }\n    DisjointSparseTable<NodeSum<long long>> st(A);\n\
    \    while(Q--){\n        int l,r; cin >> l >> r;\n        cout << st.get(l,r)\
    \ << endl;\n    }\n}"
  dependsOn:
  - lib/segment/DisjointSparseTable.cpp
  isVerificationFile: true
  path: test/segment/DisjointSparseTable.test.cpp
  requiredBy: []
  timestamp: '2020-05-13 02:48:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segment/DisjointSparseTable.test.cpp
layout: document
redirect_from:
- /verify/test/segment/DisjointSparseTable.test.cpp
- /verify/test/segment/DisjointSparseTable.test.cpp.html
title: test/segment/DisjointSparseTable.test.cpp
---
