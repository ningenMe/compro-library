---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/heap/RadixHeapInt.test.cpp
    title: test/heap/RadixHeapInt.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: RadixHeapInt
    links: []
  bundledCode: "#line 1 \"lib/heap/RadixHeapInt.cpp\"\n/*\n * @title RadixHeapInt\n\
    \ */\ntemplate<class T> class RadixHeapInt{\n\tusing TypeNode = pair<unsigned\
    \ int, T>;\n\tarray<vector<TypeNode>,33> vq;\n\tunsigned int size_num;\n\tTypeNode\
    \ last;\n\tinline int bit(int a) {\n\t\treturn a ? 32 - __builtin_clz(a) : 0;\n\
    \t}\npublic:\n\tRadixHeapInt(T mini) : size_num(0), last(make_pair(0,mini)) {\n\
    \t\t// do nothing\n\t}\n\tinline bool empty() {\n\t\treturn size_num == 0;\n\t\
    }\n\tinline size_t size(){\n\t\treturn size_num;\n\t}\n\tinline void push(TypeNode\
    \ x){\n\t\t++size_num;\n\t\tvq[bit(x.first^last.first)].push_back(x);\n\t}\n\t\
    inline void emplace(unsigned int key,T val){\n\t\t++size_num;\n\t\tvq[bit(key^last.first)].emplace_back(key,val);\n\
    \t}\n\tinline TypeNode pop() {\n\t\tif(vq[0].empty()) {\n\t\t\tint i = 1;\n\t\t\
    \twhile(vq[i].empty()) ++i;\n\t\t\tlast = *min_element(vq[i].begin(),vq[i].end());\n\
    \t\t\tfor(auto &p : vq[i]) vq[bit(p.first ^ last.first)].push_back(p);\n\t\t\t\
    vq[i].clear();\n\t\t}\n\t\t--size_num;\n\t\tauto res = vq[0].back();\n\t\tvq[0].pop_back();\n\
    \t\treturn res;\n\t}\n};\n"
  code: "/*\n * @title RadixHeapInt\n */\ntemplate<class T> class RadixHeapInt{\n\t\
    using TypeNode = pair<unsigned int, T>;\n\tarray<vector<TypeNode>,33> vq;\n\t\
    unsigned int size_num;\n\tTypeNode last;\n\tinline int bit(int a) {\n\t\treturn\
    \ a ? 32 - __builtin_clz(a) : 0;\n\t}\npublic:\n\tRadixHeapInt(T mini) : size_num(0),\
    \ last(make_pair(0,mini)) {\n\t\t// do nothing\n\t}\n\tinline bool empty() {\n\
    \t\treturn size_num == 0;\n\t}\n\tinline size_t size(){\n\t\treturn size_num;\n\
    \t}\n\tinline void push(TypeNode x){\n\t\t++size_num;\n\t\tvq[bit(x.first^last.first)].push_back(x);\n\
    \t}\n\tinline void emplace(unsigned int key,T val){\n\t\t++size_num;\n\t\tvq[bit(key^last.first)].emplace_back(key,val);\n\
    \t}\n\tinline TypeNode pop() {\n\t\tif(vq[0].empty()) {\n\t\t\tint i = 1;\n\t\t\
    \twhile(vq[i].empty()) ++i;\n\t\t\tlast = *min_element(vq[i].begin(),vq[i].end());\n\
    \t\t\tfor(auto &p : vq[i]) vq[bit(p.first ^ last.first)].push_back(p);\n\t\t\t\
    vq[i].clear();\n\t\t}\n\t\t--size_num;\n\t\tauto res = vq[0].back();\n\t\tvq[0].pop_back();\n\
    \t\treturn res;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/heap/RadixHeapInt.cpp
  requiredBy: []
  timestamp: '2020-05-13 02:48:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/heap/RadixHeapInt.test.cpp
documentation_of: lib/heap/RadixHeapInt.cpp
layout: document
redirect_from:
- /library/lib/heap/RadixHeapInt.cpp
- /library/lib/heap/RadixHeapInt.cpp.html
title: RadixHeapInt
---
