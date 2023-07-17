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
    path: test/queue/RadixHeap-32bit.test.cpp
    title: test/queue/RadixHeap-32bit.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/queue/RadixHeap-64bit.test.cpp
    title: test/queue/RadixHeap-64bit.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/queue/RadixHeap.md
    document_title: "RadixHeap - \u975E\u8CA0\u6574\u6570heap"
    links: []
  bundledCode: "#line 1 \"lib/15-queue/RadixHeap.cpp\"\n\n/*\n * @title RadixHeap\
    \ - \u975E\u8CA0\u6574\u6570heap\n * @docs md/queue/RadixHeap.md\n */\ntemplate<class\
    \ T, class Key = unsigned long long> class RadixHeap{\n    using TypeNode = pair<Key,\
    \ T>;\n    template<class InnerKey, class ZZ=InnerKey> class Inner{};\n    template<class\
    \ InnerKey> class Inner<InnerKey, unsigned long long>{\n        array<vector<TypeNode>,65>\
    \ vq;\n        unsigned long long size_num;\n        TypeNode last;\n        inline\
    \ int bit(unsigned long long a) { return a ? 64 - __builtin_clzll(a) : 0;}\n \
    \   public:\n        Inner(T mini) : size_num(0), last(make_pair(0, mini)) {}\n\
    \        inline bool empty() { return size_num == 0; }\n        inline size_t\
    \ size(){ return size_num; }\n        inline void push(TypeNode x){ ++size_num;\
    \ vq[bit(x.first^last.first)].push_back(x);}\n        inline void emplace(unsigned\
    \ long long key,T val){ ++size_num; vq[bit(key^last.first)].emplace_back(key,val);}\n\
    \        inline TypeNode pop() {\n            if(vq[0].empty()) {\n          \
    \      int i = 1;\n                while(vq[i].empty()) ++i;\n               \
    \ last = *min_element(vq[i].begin(),vq[i].end());\n                for(auto &p\
    \ : vq[i]) vq[bit(p.first ^ last.first)].push_back(p);\n                vq[i].clear();\n\
    \            }\n            --size_num;\n            auto res = vq[0].back();\
    \ vq[0].pop_back();\n            return res;\n        }\n    };\n    template<class\
    \ InnerKey> class Inner<InnerKey, unsigned int>{\n        array<vector<TypeNode>,33>\
    \ vq;\n        unsigned int size_num;\n        TypeNode last;\n        inline\
    \ int bit(unsigned int a) { return a ? 32 - __builtin_clz(a) : 0;}\n    public:\n\
    \        Inner(T mini) : size_num(0), last(make_pair(0, mini)) {}\n        inline\
    \ bool empty() { return size_num == 0; }\n        inline size_t size(){ return\
    \ size_num; }\n        inline void push(TypeNode x){ ++size_num; vq[bit(x.first^last.first)].push_back(x);}\n\
    \        inline void emplace(unsigned int key,T val){ ++size_num; vq[bit(key^last.first)].emplace_back(key,val);}\n\
    \        inline TypeNode pop() {\n            if(vq[0].empty()) {\n          \
    \      int i = 1;\n                while(vq[i].empty()) ++i;\n               \
    \ last = *min_element(vq[i].begin(),vq[i].end());\n                for(auto &p\
    \ : vq[i]) vq[bit(p.first ^ last.first)].push_back(p);\n                vq[i].clear();\n\
    \            }\n            --size_num;\n            auto res = vq[0].back();\
    \ vq[0].pop_back();\n            return res;\n        }\n    };\n    Inner<Key,Key>\
    \ inner;\npublic:\n    RadixHeap(T mini) : inner(mini) {}\n    inline bool empty()\
    \ { return inner.empty();}\n    inline size_t size(){ return inner.size();}\n\
    \    inline void push(TypeNode x){ inner.push(x);}\n    inline void emplace(unsigned\
    \ long long key,T val){ inner.emplace(key,val);}\n    inline TypeNode pop() {\
    \ return inner.pop(); }\n};\n"
  code: "\n/*\n * @title RadixHeap - \u975E\u8CA0\u6574\u6570heap\n * @docs md/queue/RadixHeap.md\n\
    \ */\ntemplate<class T, class Key = unsigned long long> class RadixHeap{\n   \
    \ using TypeNode = pair<Key, T>;\n    template<class InnerKey, class ZZ=InnerKey>\
    \ class Inner{};\n    template<class InnerKey> class Inner<InnerKey, unsigned\
    \ long long>{\n        array<vector<TypeNode>,65> vq;\n        unsigned long long\
    \ size_num;\n        TypeNode last;\n        inline int bit(unsigned long long\
    \ a) { return a ? 64 - __builtin_clzll(a) : 0;}\n    public:\n        Inner(T\
    \ mini) : size_num(0), last(make_pair(0, mini)) {}\n        inline bool empty()\
    \ { return size_num == 0; }\n        inline size_t size(){ return size_num; }\n\
    \        inline void push(TypeNode x){ ++size_num; vq[bit(x.first^last.first)].push_back(x);}\n\
    \        inline void emplace(unsigned long long key,T val){ ++size_num; vq[bit(key^last.first)].emplace_back(key,val);}\n\
    \        inline TypeNode pop() {\n            if(vq[0].empty()) {\n          \
    \      int i = 1;\n                while(vq[i].empty()) ++i;\n               \
    \ last = *min_element(vq[i].begin(),vq[i].end());\n                for(auto &p\
    \ : vq[i]) vq[bit(p.first ^ last.first)].push_back(p);\n                vq[i].clear();\n\
    \            }\n            --size_num;\n            auto res = vq[0].back();\
    \ vq[0].pop_back();\n            return res;\n        }\n    };\n    template<class\
    \ InnerKey> class Inner<InnerKey, unsigned int>{\n        array<vector<TypeNode>,33>\
    \ vq;\n        unsigned int size_num;\n        TypeNode last;\n        inline\
    \ int bit(unsigned int a) { return a ? 32 - __builtin_clz(a) : 0;}\n    public:\n\
    \        Inner(T mini) : size_num(0), last(make_pair(0, mini)) {}\n        inline\
    \ bool empty() { return size_num == 0; }\n        inline size_t size(){ return\
    \ size_num; }\n        inline void push(TypeNode x){ ++size_num; vq[bit(x.first^last.first)].push_back(x);}\n\
    \        inline void emplace(unsigned int key,T val){ ++size_num; vq[bit(key^last.first)].emplace_back(key,val);}\n\
    \        inline TypeNode pop() {\n            if(vq[0].empty()) {\n          \
    \      int i = 1;\n                while(vq[i].empty()) ++i;\n               \
    \ last = *min_element(vq[i].begin(),vq[i].end());\n                for(auto &p\
    \ : vq[i]) vq[bit(p.first ^ last.first)].push_back(p);\n                vq[i].clear();\n\
    \            }\n            --size_num;\n            auto res = vq[0].back();\
    \ vq[0].pop_back();\n            return res;\n        }\n    };\n    Inner<Key,Key>\
    \ inner;\npublic:\n    RadixHeap(T mini) : inner(mini) {}\n    inline bool empty()\
    \ { return inner.empty();}\n    inline size_t size(){ return inner.size();}\n\
    \    inline void push(TypeNode x){ inner.push(x);}\n    inline void emplace(unsigned\
    \ long long key,T val){ inner.emplace(key,val);}\n    inline TypeNode pop() {\
    \ return inner.pop(); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/15-queue/RadixHeap.cpp
  requiredBy: []
  timestamp: '2023-06-05 21:57:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/queue/RadixHeap-32bit.test.cpp
  - test/queue/RadixHeap-64bit.test.cpp
  - test/graph/MinimumDirectedClosedCircuit.test.cpp
  - test/graph/MinimumUndirectedClosedCircuit.test.cpp
documentation_of: lib/15-queue/RadixHeap.cpp
layout: document
redirect_from:
- /library/lib/15-queue/RadixHeap.cpp
- /library/lib/15-queue/RadixHeap.cpp.html
title: "RadixHeap - \u975E\u8CA0\u6574\u6570heap"
---
### RadixHeap
- 非負整数しかinsertできないが高速なpriority queue
- 最後にpushした値より大きな値しか挿入できないので、ほとんどダイクストラ用
