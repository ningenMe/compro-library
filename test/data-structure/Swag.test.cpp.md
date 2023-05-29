---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/14-data-structure/Swag.cpp
    title: Swag
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1036
    links:
    - https://yukicoder.me/problems/no/1036
  bundledCode: "#line 1 \"test/data-structure/Swag.test.cpp\"\n#define PROBLEM \"\
    https://yukicoder.me/problems/no/1036\"\n\n#include <vector>\n#include <iostream>\n\
    #include <stack>\nusing namespace std;\n#line 1 \"lib/14-data-structure/Swag.cpp\"\
    \n/*\n * @title Swag\n * @docs md/data-structure/Swag.md\n */\ntemplate<class\
    \ Operator> class Swag{\npublic:\n    using TypeNode = typename Operator::TypeNode;\n\
    \    stack<pair<TypeNode,TypeNode>> pre,suf;\n\n    Swag() {\n        // do nothing\n\
    \    }\n    TypeNode fold() {\n        TypeNode res = Operator::unit_node;\n \
    \       if(pre.size()) res = Operator::func_node(pre.top().second,res);\n    \
    \    if(suf.size()) res = Operator::func_node(res,suf.top().second);\n       \
    \ return res;\n    }\n    void push(TypeNode val) {\n        TypeNode acc = val;\n\
    \        if(suf.size()) acc = Operator::func_node(suf.top().second,acc);\n   \
    \     suf.emplace(val,acc);\n    }\n    void pop() {\n        if(pre.empty())\
    \ {\n            TypeNode acc = Operator::unit_node;\n            while(suf.size())\
    \ {\n                auto [val,_] = suf.top();\n                suf.pop();\n \
    \               acc = Operator::func_node(val,acc);\n                pre.emplace(val,acc);\n\
    \            }\n        }\n        if(pre.size()) pre.pop();\n    }\n    size_t\
    \ size(){\n        return pre.size()+suf.size();\n    }\n};\n\ntemplate<class\
    \ T> struct NodeGcd {\n    using TypeNode = T;\n    inline static constexpr TypeNode\
    \ unit_node = 0;\n    inline static constexpr TypeNode func_node(TypeNode l,TypeNode\
    \ r){return r?func_node(r,l%r):l;}\n};\n\ntemplate<class T> struct NodeComposite\
    \ {\n    using TypeNode = T;\n    inline static constexpr TypeNode unit_node =\
    \ {1,0};\n    inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return\
    \ {r.first*l.first,r.first*l.second+r.second};}\n};\n#line 8 \"test/data-structure/Swag.test.cpp\"\
    \n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\tlong long N;\
    \ cin >> N;\n\tvector<long long> A(N+1,1);\n\tfor(int i = 0; i < N; ++i) cin >>\
    \ A[i];\n\tSwag<NodeGcd<long long>> swag;\n\tlong long ans=0;\n\tint r=0;\n\t\
    swag.push(A[0]);\n\tfor(int i=0; i<N; i++){\n\t\twhile(r<i) {\n\t\t\tr++;\n\t\t\
    \tswag.push(A[r]);\n\t\t}\n\t\twhile(r<N){\n\t\t\tif(swag.fold()==1) break;\n\t\
    \t\tr++;\n\t\t\tswag.push(A[r]);\n\t\t}\n\t\tans+=N-r;\n\t\tswag.pop();\n\t}\n\
    \tcout << ans << endl;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1036\"\n\n#include <vector>\n\
    #include <iostream>\n#include <stack>\nusing namespace std;\n#include \"../../lib/14-data-structure/Swag.cpp\"\
    \n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\tlong long N;\
    \ cin >> N;\n\tvector<long long> A(N+1,1);\n\tfor(int i = 0; i < N; ++i) cin >>\
    \ A[i];\n\tSwag<NodeGcd<long long>> swag;\n\tlong long ans=0;\n\tint r=0;\n\t\
    swag.push(A[0]);\n\tfor(int i=0; i<N; i++){\n\t\twhile(r<i) {\n\t\t\tr++;\n\t\t\
    \tswag.push(A[r]);\n\t\t}\n\t\twhile(r<N){\n\t\t\tif(swag.fold()==1) break;\n\t\
    \t\tr++;\n\t\t\tswag.push(A[r]);\n\t\t}\n\t\tans+=N-r;\n\t\tswag.pop();\n\t}\n\
    \tcout << ans << endl;\n}"
  dependsOn:
  - lib/14-data-structure/Swag.cpp
  isVerificationFile: true
  path: test/data-structure/Swag.test.cpp
  requiredBy: []
  timestamp: '2023-05-30 05:01:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/Swag.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/Swag.test.cpp
- /verify/test/data-structure/Swag.test.cpp.html
title: test/data-structure/Swag.test.cpp
---
