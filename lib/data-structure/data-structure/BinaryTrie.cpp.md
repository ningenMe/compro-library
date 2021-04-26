---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/data-structure/BinaryTrie-set-xor-min.test.cpp
    title: test/data-structure/data-structure/BinaryTrie-set-xor-min.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/data-structure/data-structure/BinaryTrie.md
    document_title: BinaryTrie
    links: []
  bundledCode: "#line 1 \"lib/data-structure/data-structure/BinaryTrie.cpp\"\n/*\n\
    \ * @title BinaryTrie\n * @docs md/data-structure/data-structure/BinaryTrie.md\n\
    \ */\ntemplate<class Operator, int bit=60> class BinaryTrie{\n\tusing TypeNode\
    \ = typename Operator::TypeNode; \npublic:\n\tvector<TypeNode> node;\n\tvector<vector<int>>\
    \ ch;\n\tBinaryTrie():node(1),ch(1,vector<int>(2,-1)){}\n\tvoid operate(long long\
    \ idx, const TypeNode var) {\n\t\tint curr=0;\n\t\tstack<int> st;\n\t\tfor(int\
    \ i=bit-1; 0 <= i; --i) {\n\t\t\tst.push(curr);\n\t\t\tint f=(idx>>i)&1;\n\t\t\
    \tif(ch[curr][f]==-1) {\n\t\t\t\tnode.push_back(Operator::unit_node);\n\t\t\t\t\
    ch.push_back(vector<int>(2,-1));\n\t\t\t\tch[curr][f] = (int)node.size()-1;\n\t\
    \t\t}\n\t\t\tcurr = ch[curr][f];\n\t\t}\n\t\tnode[curr] = Operator::func_operate(node[curr],var);\n\
    \t\twhile(st.size()) {\n\t\t\tcurr = st.top(); st.pop();\n\t\t\tnode[curr]=Operator::unit_node;\n\
    \t\t\tif(ch[curr][0]!=-1)\tnode[curr] = Operator::func_fold(node[ch[curr][0]],node[curr]);\n\
    \t\t\tif(ch[curr][1]!=-1)\tnode[curr] = Operator::func_fold(node[curr],node[ch[curr][1]]);\n\
    \t\t}\n\t}\n\tTypeNode fold(long long idx) {\n\t\tint curr=0;\n\t\tfor(int i=bit-1;\
    \ 0 <= i; --i) {\n\t\t\tint f=(idx>>i)&1;\n\t\t\tif(ch[curr][f]!=-1) curr = ch[curr][f];\n\
    \t\t\telse return Operator::unit_node;\n\t\t}\n\t\treturn node[curr];\n\t}\n\t\
    long long min_bitwise_xor(long long x) {\n\t\tint curr=0;\n\t\tlong long y=0;\n\
    \t\tfor(int i=bit-1; 0 <= i; --i) {\n\t\t\tlong long f=(x>>i)&1;\n\t\t\tif(!node[curr])\
    \ break;\n\t\t\tif(ch[curr][f]!=-1 && node[ch[curr][f]]) curr = ch[curr][f];\n\
    \t\t\telse curr = ch[curr][f^=1];\n\t\t\ty^=(f<<i);\n\t\t}\n\t\treturn y^x;\n\t\
    }\n};\n"
  code: "/*\n * @title BinaryTrie\n * @docs md/data-structure/data-structure/BinaryTrie.md\n\
    \ */\ntemplate<class Operator, int bit=60> class BinaryTrie{\n\tusing TypeNode\
    \ = typename Operator::TypeNode; \npublic:\n\tvector<TypeNode> node;\n\tvector<vector<int>>\
    \ ch;\n\tBinaryTrie():node(1),ch(1,vector<int>(2,-1)){}\n\tvoid operate(long long\
    \ idx, const TypeNode var) {\n\t\tint curr=0;\n\t\tstack<int> st;\n\t\tfor(int\
    \ i=bit-1; 0 <= i; --i) {\n\t\t\tst.push(curr);\n\t\t\tint f=(idx>>i)&1;\n\t\t\
    \tif(ch[curr][f]==-1) {\n\t\t\t\tnode.push_back(Operator::unit_node);\n\t\t\t\t\
    ch.push_back(vector<int>(2,-1));\n\t\t\t\tch[curr][f] = (int)node.size()-1;\n\t\
    \t\t}\n\t\t\tcurr = ch[curr][f];\n\t\t}\n\t\tnode[curr] = Operator::func_operate(node[curr],var);\n\
    \t\twhile(st.size()) {\n\t\t\tcurr = st.top(); st.pop();\n\t\t\tnode[curr]=Operator::unit_node;\n\
    \t\t\tif(ch[curr][0]!=-1)\tnode[curr] = Operator::func_fold(node[ch[curr][0]],node[curr]);\n\
    \t\t\tif(ch[curr][1]!=-1)\tnode[curr] = Operator::func_fold(node[curr],node[ch[curr][1]]);\n\
    \t\t}\n\t}\n\tTypeNode fold(long long idx) {\n\t\tint curr=0;\n\t\tfor(int i=bit-1;\
    \ 0 <= i; --i) {\n\t\t\tint f=(idx>>i)&1;\n\t\t\tif(ch[curr][f]!=-1) curr = ch[curr][f];\n\
    \t\t\telse return Operator::unit_node;\n\t\t}\n\t\treturn node[curr];\n\t}\n\t\
    long long min_bitwise_xor(long long x) {\n\t\tint curr=0;\n\t\tlong long y=0;\n\
    \t\tfor(int i=bit-1; 0 <= i; --i) {\n\t\t\tlong long f=(x>>i)&1;\n\t\t\tif(!node[curr])\
    \ break;\n\t\t\tif(ch[curr][f]!=-1 && node[ch[curr][f]]) curr = ch[curr][f];\n\
    \t\t\telse curr = ch[curr][f^=1];\n\t\t\ty^=(f<<i);\n\t\t}\n\t\treturn y^x;\n\t\
    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data-structure/data-structure/BinaryTrie.cpp
  requiredBy: []
  timestamp: '2021-04-26 22:51:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/data-structure/BinaryTrie-set-xor-min.test.cpp
documentation_of: lib/data-structure/data-structure/BinaryTrie.cpp
layout: document
redirect_from:
- /library/lib/data-structure/data-structure/BinaryTrie.cpp
- /library/lib/data-structure/data-structure/BinaryTrie.cpp.html
title: BinaryTrie
---
