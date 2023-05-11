---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/MinimumDirectedClosedCircuit.test.cpp
    title: test/graph/MinimumDirectedClosedCircuit.test.cpp
  - icon: ':x:'
    path: test/graph/MinimumUndirectedClosedCircuit.test.cpp
    title: test/graph/MinimumUndirectedClosedCircuit.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/heap/RadixHeap.test.cpp
    title: test/heap/RadixHeap.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: md/heap/RadixHeap.md
    document_title: "RadixHeap - 64bit\u578B\u975E\u8CA0\u6574\u6570heap"
    links: []
  bundledCode: "#line 1 \"lib/heap/RadixHeap.cpp\"\n/*\n * @title RadixHeap - 64bit\u578B\
    \u975E\u8CA0\u6574\u6570heap\n * @docs md/heap/RadixHeap.md\n */\ntemplate<class\
    \ T> class RadixHeap{\n    using TypeNode = pair<unsigned long long, T>;\n   \
    \ array<vector<TypeNode>,65> vq;\n    unsigned long long size_num;\n    TypeNode\
    \ last;\n    inline int bit(unsigned long long a) {\n        return a ? 64 - __builtin_clzll(a)\
    \ : 0;\n    }\npublic:\n    RadixHeap(T mini) : size_num(0), last(make_pair(0,mini))\
    \ {\n        // do nothing\n    }\n    inline bool empty() {\n        return size_num\
    \ == 0;\n    }\n    inline size_t size(){\n        return size_num;\n    }\n \
    \   inline void push(TypeNode x){\n        ++size_num;\n        vq[bit(x.first^last.first)].push_back(x);\n\
    \    }\n    inline void emplace(unsigned long long key,T val){\n        ++size_num;\n\
    \        vq[bit(key^last.first)].emplace_back(key,val);\n    }\n    inline TypeNode\
    \ pop() {\n        if(vq[0].empty()) {\n            int i = 1;\n            while(vq[i].empty())\
    \ ++i;\n            last = *min_element(vq[i].begin(),vq[i].end());\n        \
    \    for(auto &p : vq[i]) vq[bit(p.first ^ last.first)].push_back(p);\n      \
    \      vq[i].clear();\n        }\n        --size_num;\n        auto res = vq[0].back();\n\
    \        vq[0].pop_back();\n        return res;\n    }\n};\n"
  code: "/*\n * @title RadixHeap - 64bit\u578B\u975E\u8CA0\u6574\u6570heap\n * @docs\
    \ md/heap/RadixHeap.md\n */\ntemplate<class T> class RadixHeap{\n    using TypeNode\
    \ = pair<unsigned long long, T>;\n    array<vector<TypeNode>,65> vq;\n    unsigned\
    \ long long size_num;\n    TypeNode last;\n    inline int bit(unsigned long long\
    \ a) {\n        return a ? 64 - __builtin_clzll(a) : 0;\n    }\npublic:\n    RadixHeap(T\
    \ mini) : size_num(0), last(make_pair(0,mini)) {\n        // do nothing\n    }\n\
    \    inline bool empty() {\n        return size_num == 0;\n    }\n    inline size_t\
    \ size(){\n        return size_num;\n    }\n    inline void push(TypeNode x){\n\
    \        ++size_num;\n        vq[bit(x.first^last.first)].push_back(x);\n    }\n\
    \    inline void emplace(unsigned long long key,T val){\n        ++size_num;\n\
    \        vq[bit(key^last.first)].emplace_back(key,val);\n    }\n    inline TypeNode\
    \ pop() {\n        if(vq[0].empty()) {\n            int i = 1;\n            while(vq[i].empty())\
    \ ++i;\n            last = *min_element(vq[i].begin(),vq[i].end());\n        \
    \    for(auto &p : vq[i]) vq[bit(p.first ^ last.first)].push_back(p);\n      \
    \      vq[i].clear();\n        }\n        --size_num;\n        auto res = vq[0].back();\n\
    \        vq[0].pop_back();\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/heap/RadixHeap.cpp
  requiredBy: []
  timestamp: '2021-09-21 09:57:46+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/heap/RadixHeap.test.cpp
  - test/graph/MinimumUndirectedClosedCircuit.test.cpp
  - test/graph/MinimumDirectedClosedCircuit.test.cpp
documentation_of: lib/heap/RadixHeap.cpp
layout: document
redirect_from:
- /library/lib/heap/RadixHeap.cpp
- /library/lib/heap/RadixHeap.cpp.html
title: "RadixHeap - 64bit\u578B\u975E\u8CA0\u6574\u6570heap"
---
