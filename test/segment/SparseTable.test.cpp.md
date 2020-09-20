---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/segment/SparseTable.cpp
    title: SparseTable
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/segment/SparseTable.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/staticrmq\"\n\n#include <vector>\n#include <iostream>\n\
    using namespace std;\n#line 1 \"lib/segment/SparseTable.cpp\"\n/*\n * @title SparseTable\n\
    \ */\ntemplate<class Operator> class SparseTable{\npublic:\n\tusing TypeNode =\
    \ typename Operator::TypeNode;\n\tvector<TypeNode> node;\n\tvector<int> idx;\n\
    \tsize_t depth;\n\tsize_t length;\n\n\tSparseTable(const vector<TypeNode>& vec)\
    \ {\n\t\tfor(depth = 0;(1<<depth)<=vec.size();++depth);\n\t\tlength = (1<<depth);\n\
    \t\tnode.resize(depth*length);\n\t\tfor(int i = 0; i < vec.size(); ++i) node[i]\
    \ = vec[i];\n\t\tfor(int i = 1; i < depth; ++i) for(int j = 0; j + (1<<i) < (1<<depth);\
    \ ++j) node[i*length+j] = Operator::func_node(node[(i-1)*length+j],node[(i-1)*length+j\
    \ + (1 << (i-1))]);\n\t\tidx.resize(vec.size()+1);\n\t\tfor(int i = 2; i < vec.size()+1;\
    \ ++i) idx[i] = idx[i>>1] + 1;\n\t}\n\n\t//[l,r)\n\tTypeNode get(int l,int r)\
    \ {\n\t\tint bit = idx[r-l];\n\t\treturn Operator::func_node(node[bit*length+l],node[bit*length+r\
    \ - (1<<bit)]);\n\t}\n};\n\ntemplate<class T> struct NodeMin {\n\tusing TypeNode\
    \ = T;\n\tinline static constexpr TypeNode unitNode = 1LL<<31;\n\tinline static\
    \ constexpr TypeNode func_node(TypeNode l,TypeNode r){return min(l,r);}\n};\n\
    #line 7 \"test/segment/SparseTable.test.cpp\"\n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\
    \    int N,Q; cin >> N >> Q;\n    vector<long long> A(N);\n    for(int i = 0;\
    \ i < N; ++i) {\n        cin >> A[i];\n    }\n    SparseTable<NodeMin<long long>>\
    \ st(A);\n    while(Q--){\n        int l,r; cin >> l >> r;\n        cout << st.get(l,r)\
    \ << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <vector>\n#include <iostream>\nusing namespace std;\n#include \"../../lib/segment/SparseTable.cpp\"\
    \n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; cin\
    \ >> N >> Q;\n    vector<long long> A(N);\n    for(int i = 0; i < N; ++i) {\n\
    \        cin >> A[i];\n    }\n    SparseTable<NodeMin<long long>> st(A);\n   \
    \ while(Q--){\n        int l,r; cin >> l >> r;\n        cout << st.get(l,r) <<\
    \ endl;\n    }\n}"
  dependsOn:
  - lib/segment/SparseTable.cpp
  isVerificationFile: true
  path: test/segment/SparseTable.test.cpp
  requiredBy: []
  timestamp: '2020-05-13 02:48:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segment/SparseTable.test.cpp
layout: document
redirect_from:
- /verify/test/segment/SparseTable.test.cpp
- /verify/test/segment/SparseTable.test.cpp.html
title: test/segment/SparseTable.test.cpp
---
