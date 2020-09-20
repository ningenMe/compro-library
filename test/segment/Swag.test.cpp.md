---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/segment/Swag.cpp
    title: Swag
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1036
    links:
    - https://yukicoder.me/problems/no/1036
  bundledCode: "#line 1 \"test/segment/Swag.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/1036\"\
    \n\n#include <vector>\n#include <iostream>\n#include <stack>\nusing namespace\
    \ std;\n#line 1 \"lib/segment/Swag.cpp\"\n/*\n * @title Swag\n */\ntemplate<class\
    \ Operator> class Swag{\npublic:\n\tusing TypeNode = typename Operator::TypeNode;\n\
    \tstack<pair<TypeNode,TypeNode>> pre,suf;\n\n\tSwag() {\n\t\t// do nothing\n\t\
    }\n\tTypeNode fold() {\n\t\tTypeNode res = Operator::unit_node;\n\t\tif(pre.size())\
    \ res = Operator::func_node(pre.top().second,res);\n\t\tif(suf.size()) res = Operator::func_node(res,suf.top().second);\n\
    \t\treturn res;\n\t}\n\tvoid push(TypeNode val) {\n\t\tTypeNode acc = val;\n\t\
    \tif(suf.size()) acc = Operator::func_node(suf.top().second,acc);\n\t\tsuf.emplace(val,acc);\n\
    \t}\n\tvoid pop() {\n\t\tif(pre.empty()) {\n\t\t\tTypeNode acc = Operator::unit_node;\n\
    \t\t\twhile(suf.size()) {\n\t\t\t\tauto [val,_] = suf.top();\n\t\t\t\tsuf.pop();\n\
    \t\t\t\tacc = Operator::func_node(val,acc);\n\t\t\t\tpre.emplace(val,acc);\n\t\
    \t\t}\n\t\t}\n\t\tif(pre.size()) pre.pop();\t\t\t\n\t}\n\tsize_t size(){\n\t\t\
    return pre.size()+suf.size();\n\t}\n};\n\ntemplate<class T> struct NodeGcd {\n\
    \tusing TypeNode = T;\n\tinline static constexpr TypeNode unit_node = 0;\n\tinline\
    \ static constexpr TypeNode func_node(TypeNode l,TypeNode r){return r?func_node(r,l%r):l;}\n\
    };\n\ntemplate<class T> struct NodeComposite {\n\tusing TypeNode = T;\n\tinline\
    \ static constexpr TypeNode unit_node = {1,0};\n\tinline static constexpr TypeNode\
    \ func_node(TypeNode l,TypeNode r){return {r.first*l.first,r.first*l.second+r.second};}\n\
    };\n#line 8 \"test/segment/Swag.test.cpp\"\n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\
    \tlong long N; cin >> N;\n\tvector<long long> A(N+1,1);\n\tfor(int i = 0; i <\
    \ N; ++i) cin >> A[i];\n\tSwag<NodeGcd<long long>> swag;\n\tlong long ans=0;\n\
    \tint r=0;\n\tswag.push(A[0]);\n\tfor(int i=0; i<N; i++){\n\t\twhile(r<i) {\n\t\
    \t\tr++;\n\t\t\tswag.push(A[r]);\n\t\t}\n\t\twhile(r<N){\n\t\t\tif(swag.fold()==1)\
    \ break;\n\t\t\tr++;\n\t\t\tswag.push(A[r]);\n\t\t}\n\t\tans+=N-r;\n\t\tswag.pop();\n\
    \t}\n\tcout << ans << endl;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1036\"\n\n#include <vector>\n\
    #include <iostream>\n#include <stack>\nusing namespace std;\n#include \"../../lib/segment/Swag.cpp\"\
    \n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\tlong long N;\
    \ cin >> N;\n\tvector<long long> A(N+1,1);\n\tfor(int i = 0; i < N; ++i) cin >>\
    \ A[i];\n\tSwag<NodeGcd<long long>> swag;\n\tlong long ans=0;\n\tint r=0;\n\t\
    swag.push(A[0]);\n\tfor(int i=0; i<N; i++){\n\t\twhile(r<i) {\n\t\t\tr++;\n\t\t\
    \tswag.push(A[r]);\n\t\t}\n\t\twhile(r<N){\n\t\t\tif(swag.fold()==1) break;\n\t\
    \t\tr++;\n\t\t\tswag.push(A[r]);\n\t\t}\n\t\tans+=N-r;\n\t\tswag.pop();\n\t}\n\
    \tcout << ans << endl;\n}"
  dependsOn:
  - lib/segment/Swag.cpp
  isVerificationFile: true
  path: test/segment/Swag.test.cpp
  requiredBy: []
  timestamp: '2020-08-15 20:43:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segment/Swag.test.cpp
layout: document
redirect_from:
- /verify/test/segment/Swag.test.cpp
- /verify/test/segment/Swag.test.cpp.html
title: test/segment/Swag.test.cpp
---
