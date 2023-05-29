---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/data-structure/BinaryTrie.md
    document_title: BinaryTrie
    links: []
  bundledCode: "#line 1 \"lib/14-data-structure/BinaryTrie.cpp\"\n/*\n * @title BinaryTrie\n\
    \ * @docs md/data-structure/BinaryTrie.md\n */\ntemplate<class Operator, int bit=60>\
    \ class BinaryTrie{\n    using TypeNode = typename Operator::TypeNode;\npublic:\n\
    \    vector<TypeNode> node;\n    vector<vector<int>> ch;\n    BinaryTrie():node(1),ch(1,vector<int>(2,-1)){}\n\
    \    void operate(long long idx, const TypeNode var) {\n        int curr=0;\n\
    \        stack<int> st;\n        for(int i=bit-1; 0 <= i; --i) {\n           \
    \ st.push(curr);\n            int f=(idx>>i)&1;\n            if(ch[curr][f]==-1)\
    \ {\n                node.push_back(Operator::unit_node);\n                ch.push_back(vector<int>(2,-1));\n\
    \                ch[curr][f] = (int)node.size()-1;\n            }\n          \
    \  curr = ch[curr][f];\n        }\n        node[curr] = Operator::func_operate(node[curr],var);\n\
    \        while(st.size()) {\n            curr = st.top(); st.pop();\n        \
    \    node[curr]=Operator::unit_node;\n            if(ch[curr][0]!=-1)\tnode[curr]\
    \ = Operator::func_fold(node[ch[curr][0]],node[curr]);\n            if(ch[curr][1]!=-1)\t\
    node[curr] = Operator::func_fold(node[curr],node[ch[curr][1]]);\n        }\n \
    \   }\n    TypeNode fold(long long idx) {\n        int curr=0;\n        for(int\
    \ i=bit-1; 0 <= i; --i) {\n            int f=(idx>>i)&1;\n            if(ch[curr][f]!=-1)\
    \ curr = ch[curr][f];\n            else return Operator::unit_node;\n        }\n\
    \        return node[curr];\n    }\n    long long min_bitwise_xor(long long x)\
    \ {\n        int curr=0;\n        long long y=0;\n        for(int i=bit-1; 0 <=\
    \ i; --i) {\n            long long f=(x>>i)&1;\n            if(!node[curr]) break;\n\
    \            if(ch[curr][f]!=-1 && node[ch[curr][f]]) curr = ch[curr][f];\n  \
    \          else curr = ch[curr][f^=1];\n            y^=(f<<i);\n        }\n  \
    \      return y^x;\n    }\n};\n"
  code: "/*\n * @title BinaryTrie\n * @docs md/data-structure/BinaryTrie.md\n */\n\
    template<class Operator, int bit=60> class BinaryTrie{\n    using TypeNode = typename\
    \ Operator::TypeNode;\npublic:\n    vector<TypeNode> node;\n    vector<vector<int>>\
    \ ch;\n    BinaryTrie():node(1),ch(1,vector<int>(2,-1)){}\n    void operate(long\
    \ long idx, const TypeNode var) {\n        int curr=0;\n        stack<int> st;\n\
    \        for(int i=bit-1; 0 <= i; --i) {\n            st.push(curr);\n       \
    \     int f=(idx>>i)&1;\n            if(ch[curr][f]==-1) {\n                node.push_back(Operator::unit_node);\n\
    \                ch.push_back(vector<int>(2,-1));\n                ch[curr][f]\
    \ = (int)node.size()-1;\n            }\n            curr = ch[curr][f];\n    \
    \    }\n        node[curr] = Operator::func_operate(node[curr],var);\n       \
    \ while(st.size()) {\n            curr = st.top(); st.pop();\n            node[curr]=Operator::unit_node;\n\
    \            if(ch[curr][0]!=-1)\tnode[curr] = Operator::func_fold(node[ch[curr][0]],node[curr]);\n\
    \            if(ch[curr][1]!=-1)\tnode[curr] = Operator::func_fold(node[curr],node[ch[curr][1]]);\n\
    \        }\n    }\n    TypeNode fold(long long idx) {\n        int curr=0;\n \
    \       for(int i=bit-1; 0 <= i; --i) {\n            int f=(idx>>i)&1;\n     \
    \       if(ch[curr][f]!=-1) curr = ch[curr][f];\n            else return Operator::unit_node;\n\
    \        }\n        return node[curr];\n    }\n    long long min_bitwise_xor(long\
    \ long x) {\n        int curr=0;\n        long long y=0;\n        for(int i=bit-1;\
    \ 0 <= i; --i) {\n            long long f=(x>>i)&1;\n            if(!node[curr])\
    \ break;\n            if(ch[curr][f]!=-1 && node[ch[curr][f]]) curr = ch[curr][f];\n\
    \            else curr = ch[curr][f^=1];\n            y^=(f<<i);\n        }\n\
    \        return y^x;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/14-data-structure/BinaryTrie.cpp
  requiredBy: []
  timestamp: '2023-05-30 05:01:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/14-data-structure/BinaryTrie.cpp
layout: document
redirect_from:
- /library/lib/14-data-structure/BinaryTrie.cpp
- /library/lib/14-data-structure/BinaryTrie.cpp.html
title: BinaryTrie
---
