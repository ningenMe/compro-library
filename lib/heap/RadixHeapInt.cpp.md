---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/heap/RadixHeapInt.md
    document_title: "RadixHeapInt - 32bit\u578B\u975E\u8CA0\u6574\u6570heap"
    links: []
  bundledCode: "#line 1 \"lib/heap/RadixHeapInt.cpp\"\n/*\n * @title RadixHeapInt\
    \ - 32bit\u578B\u975E\u8CA0\u6574\u6570heap\n * @docs md/heap/RadixHeapInt.md\n\
    \ */\ntemplate<class T> class RadixHeapInt{\n    using TypeNode = pair<unsigned\
    \ int, T>;\n    array<vector<TypeNode>,33> vq;\n    unsigned int size_num;\n \
    \   TypeNode last;\n    inline int bit(int a) {\n        return a ? 32 - __builtin_clz(a)\
    \ : 0;\n    }\npublic:\n    RadixHeapInt(T mini) : size_num(0), last(make_pair(0,mini))\
    \ {\n        // do nothing\n    }\n    inline bool empty() {\n        return size_num\
    \ == 0;\n    }\n    inline size_t size(){\n        return size_num;\n    }\n \
    \   inline void push(TypeNode x){\n        ++size_num;\n        vq[bit(x.first^last.first)].push_back(x);\n\
    \    }\n    inline void emplace(unsigned int key,T val){\n        ++size_num;\n\
    \        vq[bit(key^last.first)].emplace_back(key,val);\n    }\n    inline TypeNode\
    \ pop() {\n        if(vq[0].empty()) {\n            int i = 1;\n            while(vq[i].empty())\
    \ ++i;\n            last = *min_element(vq[i].begin(),vq[i].end());\n        \
    \    for(auto &p : vq[i]) vq[bit(p.first ^ last.first)].push_back(p);\n      \
    \      vq[i].clear();\n        }\n        --size_num;\n        auto res = vq[0].back();\n\
    \        vq[0].pop_back();\n        return res;\n    }\n};\n"
  code: "/*\n * @title RadixHeapInt - 32bit\u578B\u975E\u8CA0\u6574\u6570heap\n *\
    \ @docs md/heap/RadixHeapInt.md\n */\ntemplate<class T> class RadixHeapInt{\n\
    \    using TypeNode = pair<unsigned int, T>;\n    array<vector<TypeNode>,33> vq;\n\
    \    unsigned int size_num;\n    TypeNode last;\n    inline int bit(int a) {\n\
    \        return a ? 32 - __builtin_clz(a) : 0;\n    }\npublic:\n    RadixHeapInt(T\
    \ mini) : size_num(0), last(make_pair(0,mini)) {\n        // do nothing\n    }\n\
    \    inline bool empty() {\n        return size_num == 0;\n    }\n    inline size_t\
    \ size(){\n        return size_num;\n    }\n    inline void push(TypeNode x){\n\
    \        ++size_num;\n        vq[bit(x.first^last.first)].push_back(x);\n    }\n\
    \    inline void emplace(unsigned int key,T val){\n        ++size_num;\n     \
    \   vq[bit(key^last.first)].emplace_back(key,val);\n    }\n    inline TypeNode\
    \ pop() {\n        if(vq[0].empty()) {\n            int i = 1;\n            while(vq[i].empty())\
    \ ++i;\n            last = *min_element(vq[i].begin(),vq[i].end());\n        \
    \    for(auto &p : vq[i]) vq[bit(p.first ^ last.first)].push_back(p);\n      \
    \      vq[i].clear();\n        }\n        --size_num;\n        auto res = vq[0].back();\n\
    \        vq[0].pop_back();\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/heap/RadixHeapInt.cpp
  requiredBy: []
  timestamp: '2023-05-12 01:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/heap/RadixHeapInt.cpp
layout: document
redirect_from:
- /library/lib/heap/RadixHeapInt.cpp
- /library/lib/heap/RadixHeapInt.cpp.html
title: "RadixHeapInt - 32bit\u578B\u975E\u8CA0\u6574\u6570heap"
---
