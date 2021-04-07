---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/segment/BinaryTrie-set-xor-min.test.cpp
    title: test/segment/BinaryTrie-set-xor-min.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/segment/BinaryTrie.md
    document_title: BinaryTrie
    links: []
  bundledCode: "#line 1 \"lib/segment/BinaryTrie.cpp\"\n/*\n * @title BinaryTrie\n\
    \ * @docs md/segment/BinaryTrie.md\n */\ntemplate<class Operator, int bit=60>\
    \ class BinaryTrie{\n\tusing TypeNode = typename Operator::TypeNode; \npublic:\n\
    \tvector<TypeNode> node;\n\tvector<vector<int>> ch;\n\tBinaryTrie():node(1),ch(1,vector<int>(2,-1)){}\n\
    \tvoid update(long long idx, const TypeNode var) {\n\t\tint curr=0;\n\t\tstack<int>\
    \ st;\n\t\tfor(int i=bit-1; 0 <= i; --i) {\n\t\t\tst.push(curr);\n\t\t\tint f=(idx>>i)&1;\n\
    \t\t\tif(ch[curr][f]==-1) {\n\t\t\t\tnode.push_back(Operator::unit_node);\n\t\t\
    \t\tch.push_back(vector<int>(2,-1));\n\t\t\t\tch[curr][f] = (int)node.size()-1;\n\
    \t\t\t}\n\t\t\tcurr = ch[curr][f];\n\t\t}\n\t\tnode[curr] = Operator::func_merge(node[curr],var);\n\
    \t\twhile(st.size()) {\n\t\t\tcurr = st.top(); st.pop();\n\t\t\tnode[curr]=Operator::unit_node;\n\
    \t\t\tif(ch[curr][0]!=-1)\tnode[curr] = Operator::func_node(node[ch[curr][0]],node[curr]);\n\
    \t\t\tif(ch[curr][1]!=-1)\tnode[curr] = Operator::func_node(node[curr],node[ch[curr][1]]);\n\
    \t\t}\n\t}\n\tTypeNode get(long long idx) {\n\t\tint curr=0;\n\t\tfor(int i=bit-1;\
    \ 0 <= i; --i) {\n\t\t\tint f=(idx>>i)&1;\n\t\t\tif(ch[curr][f]!=-1) curr = ch[curr][f];\n\
    \t\t\telse return Operator::unit_node;\n\t\t}\n\t\treturn node[curr];\n\t}\n\t\
    long long min_bitwise_xor(long long x) {\n\t\tint curr=0;\n\t\tlong long y=0;\n\
    \t\tfor(int i=bit-1; 0 <= i; --i) {\n\t\t\tlong long f=(x>>i)&1;\n\t\t\tif(!node[curr])\
    \ break;\n\t\t\tif(ch[curr][f]!=-1 && node[ch[curr][f]]) curr = ch[curr][f];\n\
    \t\t\telse curr = ch[curr][f^=1];\n\t\t\ty^=(f<<i);\n\t\t}\n\t\treturn y^x;\n\t\
    }\n};\n\n//\u4E00\u70B9\u52A0\u7B97 \u533A\u9593\u548C\ntemplate<class T> struct\
    \ NodeSumPointAdd {\n\tusing TypeNode = T;\n\tinline static constexpr TypeNode\
    \ unit_node = 0;\n\tinline static constexpr TypeNode func_node(TypeNode l,TypeNode\
    \ r){return l+r;}\n\tinline static constexpr TypeNode func_merge(TypeNode l,TypeNode\
    \ r){return l+r;}\n};\n"
  code: "/*\n * @title BinaryTrie\n * @docs md/segment/BinaryTrie.md\n */\ntemplate<class\
    \ Operator, int bit=60> class BinaryTrie{\n\tusing TypeNode = typename Operator::TypeNode;\
    \ \npublic:\n\tvector<TypeNode> node;\n\tvector<vector<int>> ch;\n\tBinaryTrie():node(1),ch(1,vector<int>(2,-1)){}\n\
    \tvoid update(long long idx, const TypeNode var) {\n\t\tint curr=0;\n\t\tstack<int>\
    \ st;\n\t\tfor(int i=bit-1; 0 <= i; --i) {\n\t\t\tst.push(curr);\n\t\t\tint f=(idx>>i)&1;\n\
    \t\t\tif(ch[curr][f]==-1) {\n\t\t\t\tnode.push_back(Operator::unit_node);\n\t\t\
    \t\tch.push_back(vector<int>(2,-1));\n\t\t\t\tch[curr][f] = (int)node.size()-1;\n\
    \t\t\t}\n\t\t\tcurr = ch[curr][f];\n\t\t}\n\t\tnode[curr] = Operator::func_merge(node[curr],var);\n\
    \t\twhile(st.size()) {\n\t\t\tcurr = st.top(); st.pop();\n\t\t\tnode[curr]=Operator::unit_node;\n\
    \t\t\tif(ch[curr][0]!=-1)\tnode[curr] = Operator::func_node(node[ch[curr][0]],node[curr]);\n\
    \t\t\tif(ch[curr][1]!=-1)\tnode[curr] = Operator::func_node(node[curr],node[ch[curr][1]]);\n\
    \t\t}\n\t}\n\tTypeNode get(long long idx) {\n\t\tint curr=0;\n\t\tfor(int i=bit-1;\
    \ 0 <= i; --i) {\n\t\t\tint f=(idx>>i)&1;\n\t\t\tif(ch[curr][f]!=-1) curr = ch[curr][f];\n\
    \t\t\telse return Operator::unit_node;\n\t\t}\n\t\treturn node[curr];\n\t}\n\t\
    long long min_bitwise_xor(long long x) {\n\t\tint curr=0;\n\t\tlong long y=0;\n\
    \t\tfor(int i=bit-1; 0 <= i; --i) {\n\t\t\tlong long f=(x>>i)&1;\n\t\t\tif(!node[curr])\
    \ break;\n\t\t\tif(ch[curr][f]!=-1 && node[ch[curr][f]]) curr = ch[curr][f];\n\
    \t\t\telse curr = ch[curr][f^=1];\n\t\t\ty^=(f<<i);\n\t\t}\n\t\treturn y^x;\n\t\
    }\n};\n\n//\u4E00\u70B9\u52A0\u7B97 \u533A\u9593\u548C\ntemplate<class T> struct\
    \ NodeSumPointAdd {\n\tusing TypeNode = T;\n\tinline static constexpr TypeNode\
    \ unit_node = 0;\n\tinline static constexpr TypeNode func_node(TypeNode l,TypeNode\
    \ r){return l+r;}\n\tinline static constexpr TypeNode func_merge(TypeNode l,TypeNode\
    \ r){return l+r;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/segment/BinaryTrie.cpp
  requiredBy: []
  timestamp: '2020-09-26 17:01:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segment/BinaryTrie-set-xor-min.test.cpp
documentation_of: lib/segment/BinaryTrie.cpp
layout: document
redirect_from:
- /library/lib/segment/BinaryTrie.cpp
- /library/lib/segment/BinaryTrie.cpp.html
title: BinaryTrie
---
