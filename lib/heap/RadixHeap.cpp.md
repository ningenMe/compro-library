---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/MinimumDirectedClosedCircuit.test.cpp
    title: test/graph/MinimumDirectedClosedCircuit.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/MinimumUndirectedClosedCircuit.test.cpp
    title: test/graph/MinimumUndirectedClosedCircuit.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/heap/RadixHeap.test.cpp
    title: test/heap/RadixHeap.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/heap/RadixHeap.md
    document_title: "RadixHeap - 64bit\u578B\u975E\u8CA0\u6574\u6570heap"
    links: []
  bundledCode: "#line 1 \"lib/heap/RadixHeap.cpp\"\n/*\n * @title RadixHeap - 64bit\u578B\
    \u975E\u8CA0\u6574\u6570heap\n * @docs md/heap/RadixHeap.md\n */\ntemplate<class\
    \ T> class RadixHeap{\n\tusing TypeNode = pair<unsigned long long, T>;\n\tarray<vector<TypeNode>,65>\
    \ vq;\n\tunsigned long long size_num;\n\tTypeNode last;\n\tinline int bit(unsigned\
    \ long long a) {\n\t\treturn a ? 64 - __builtin_clzll(a) : 0;\n\t}\npublic:\n\t\
    RadixHeap(T mini) : size_num(0), last(make_pair(0,mini)) {\n\t\t// do nothing\n\
    \t}\n\tinline bool empty() {\n\t\treturn size_num == 0;\n\t}\n\tinline size_t\
    \ size(){\n\t\treturn size_num;\n\t}\n\tinline void push(TypeNode x){\n\t\t++size_num;\n\
    \t\tvq[bit(x.first^last.first)].push_back(x);\n\t}\n\tinline void emplace(unsigned\
    \ long long key,T val){\n\t\t++size_num;\n\t\tvq[bit(key^last.first)].emplace_back(key,val);\n\
    \t}\n\tinline TypeNode pop() {\n\t\tif(vq[0].empty()) {\n\t\t\tint i = 1;\n\t\t\
    \twhile(vq[i].empty()) ++i;\n\t\t\tlast = *min_element(vq[i].begin(),vq[i].end());\n\
    \t\t\tfor(auto &p : vq[i]) vq[bit(p.first ^ last.first)].push_back(p);\n\t\t\t\
    vq[i].clear();\n\t\t}\n\t\t--size_num;\n\t\tauto res = vq[0].back();\n\t\tvq[0].pop_back();\n\
    \t\treturn res;\n\t}\n};\n"
  code: "/*\n * @title RadixHeap - 64bit\u578B\u975E\u8CA0\u6574\u6570heap\n * @docs\
    \ md/heap/RadixHeap.md\n */\ntemplate<class T> class RadixHeap{\n\tusing TypeNode\
    \ = pair<unsigned long long, T>;\n\tarray<vector<TypeNode>,65> vq;\n\tunsigned\
    \ long long size_num;\n\tTypeNode last;\n\tinline int bit(unsigned long long a)\
    \ {\n\t\treturn a ? 64 - __builtin_clzll(a) : 0;\n\t}\npublic:\n\tRadixHeap(T\
    \ mini) : size_num(0), last(make_pair(0,mini)) {\n\t\t// do nothing\n\t}\n\tinline\
    \ bool empty() {\n\t\treturn size_num == 0;\n\t}\n\tinline size_t size(){\n\t\t\
    return size_num;\n\t}\n\tinline void push(TypeNode x){\n\t\t++size_num;\n\t\t\
    vq[bit(x.first^last.first)].push_back(x);\n\t}\n\tinline void emplace(unsigned\
    \ long long key,T val){\n\t\t++size_num;\n\t\tvq[bit(key^last.first)].emplace_back(key,val);\n\
    \t}\n\tinline TypeNode pop() {\n\t\tif(vq[0].empty()) {\n\t\t\tint i = 1;\n\t\t\
    \twhile(vq[i].empty()) ++i;\n\t\t\tlast = *min_element(vq[i].begin(),vq[i].end());\n\
    \t\t\tfor(auto &p : vq[i]) vq[bit(p.first ^ last.first)].push_back(p);\n\t\t\t\
    vq[i].clear();\n\t\t}\n\t\t--size_num;\n\t\tauto res = vq[0].back();\n\t\tvq[0].pop_back();\n\
    \t\treturn res;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/heap/RadixHeap.cpp
  requiredBy: []
  timestamp: '2020-09-26 16:29:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/MinimumDirectedClosedCircuit.test.cpp
  - test/graph/MinimumUndirectedClosedCircuit.test.cpp
  - test/heap/RadixHeap.test.cpp
documentation_of: lib/heap/RadixHeap.cpp
layout: document
redirect_from:
- /library/lib/heap/RadixHeap.cpp
- /library/lib/heap/RadixHeap.cpp.html
title: "RadixHeap - 64bit\u578B\u975E\u8CA0\u6574\u6570heap"
---
