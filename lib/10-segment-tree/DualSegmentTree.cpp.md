---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/segment-tree/DualSegmentTree-pcq.test.cpp
    title: test/segment-tree/DualSegmentTree-pcq.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/segment-tree/DualSegmentTree.md
    document_title: "DualSegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u53CC\u5BFE\
      \u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 1 \"lib/10-segment-tree/DualSegmentTree.cpp\"\n/*\n * @title\
    \ DualSegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u53CC\u5BFE\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\n * @docs md/segment-tree/DualSegmentTree.md\n */\ntemplate<class\
    \ Monoid> class DualSegmentTree {\n    using TypeNode = typename Monoid::TypeNode;\n\
    \    using TypeLazy = typename Monoid::TypeLazy;\n    size_t length;\n    size_t\
    \ height;\n    vector<TypeNode> node;\n    vector<TypeLazy> lazy;\n\n    void\
    \ propagate(int k) {\n        if(lazy[k] == Monoid::unit_lazy) return;\n     \
    \   if(k >=length) node[k-length] = Monoid::func_operate(node[k-length],lazy[k],k-length,k-length+1);\n\
    \        if(k < length) lazy[2*k+0] = Monoid::func_lazy(lazy[2*k+0],lazy[k]);\n\
    \        if(k < length) lazy[2*k+1] = Monoid::func_lazy(lazy[2*k+1],lazy[k]);\n\
    \        lazy[k] = Monoid::unit_lazy;\n    }\n    void build(const size_t num)\
    \ {\n        for (length = 1,height = 0; length <= num; length *= 2, height++);\n\
    \        node.resize(1 * length, Monoid::unit_node);\n        lazy.resize(2 *\
    \ length, Monoid::unit_lazy);\n    }\n\npublic:\n\n    //unit\u3067\u521D\u671F\
    \u5316\n    DualSegmentTree(const size_t num) {\n        build(num);\n    }\n\
    \    // //\u540C\u3058init\u3067\u521D\u671F\u5316\n    DualSegmentTree(const\
    \ size_t num, const TypeNode init) {\n        build(num);\n        for (int i\
    \ = 0; i < num; ++i) node[i] = init;\n    }\n    //vector\u3067\u521D\u671F\u5316\
    \n    DualSegmentTree(const vector<TypeNode>& vec) {\n        build(vec.size());\n\
    \        for (int i = 0; i < vec.size(); ++i) node[i] = vec[i];\n    }\n\n   \
    \ //operate [a,b)\n    void operate(int a, int b, TypeLazy x) {\n        int l\
    \ = a + length, r = b + length - 1;\n        for (int i = height; 0 < i; --i)\
    \ propagate(l >> i), propagate(r >> i);\n        for(r++; l < r; l >>=1, r >>=1)\
    \ {\n            if(l&1) lazy[l] = Monoid::func_lazy(lazy[l],x), propagate(l),l++;\n\
    \            if(r&1) --r,lazy[r] = Monoid::func_lazy(lazy[r],x), propagate(r);\n\
    \        }\n    }\n\n    //fold [a,a+1)\n    TypeNode fold(int a) {\n        int\
    \ l = a + length;\n        for (int i = height; 0 <= i; --i) propagate(l >> i);\n\
    \        return node[a];\n    }\n\n    void print(){\n        cout << \"lazy\"\
    \ << endl;\n        for(int i = 1,j = 1; i < 2*length; ++i) {\n        \tcout\
    \ << lazy[i] << \" \";\n        \tif(i==((1<<j)-1) && ++j) cout << endl;\n   \
    \     }\n        cout << \"vector\" << endl;\n        cout << \"{ \" << fold(0);\n\
    \        for(int i = 1; i < length; ++i) cout << \", \" << fold(i);\n        cout\
    \ << \" }\" << endl;\n    }\n};\n"
  code: "/*\n * @title DualSegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u53CC\
    \u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @docs md/segment-tree/DualSegmentTree.md\n\
    \ */\ntemplate<class Monoid> class DualSegmentTree {\n    using TypeNode = typename\
    \ Monoid::TypeNode;\n    using TypeLazy = typename Monoid::TypeLazy;\n    size_t\
    \ length;\n    size_t height;\n    vector<TypeNode> node;\n    vector<TypeLazy>\
    \ lazy;\n\n    void propagate(int k) {\n        if(lazy[k] == Monoid::unit_lazy)\
    \ return;\n        if(k >=length) node[k-length] = Monoid::func_operate(node[k-length],lazy[k],k-length,k-length+1);\n\
    \        if(k < length) lazy[2*k+0] = Monoid::func_lazy(lazy[2*k+0],lazy[k]);\n\
    \        if(k < length) lazy[2*k+1] = Monoid::func_lazy(lazy[2*k+1],lazy[k]);\n\
    \        lazy[k] = Monoid::unit_lazy;\n    }\n    void build(const size_t num)\
    \ {\n        for (length = 1,height = 0; length <= num; length *= 2, height++);\n\
    \        node.resize(1 * length, Monoid::unit_node);\n        lazy.resize(2 *\
    \ length, Monoid::unit_lazy);\n    }\n\npublic:\n\n    //unit\u3067\u521D\u671F\
    \u5316\n    DualSegmentTree(const size_t num) {\n        build(num);\n    }\n\
    \    // //\u540C\u3058init\u3067\u521D\u671F\u5316\n    DualSegmentTree(const\
    \ size_t num, const TypeNode init) {\n        build(num);\n        for (int i\
    \ = 0; i < num; ++i) node[i] = init;\n    }\n    //vector\u3067\u521D\u671F\u5316\
    \n    DualSegmentTree(const vector<TypeNode>& vec) {\n        build(vec.size());\n\
    \        for (int i = 0; i < vec.size(); ++i) node[i] = vec[i];\n    }\n\n   \
    \ //operate [a,b)\n    void operate(int a, int b, TypeLazy x) {\n        int l\
    \ = a + length, r = b + length - 1;\n        for (int i = height; 0 < i; --i)\
    \ propagate(l >> i), propagate(r >> i);\n        for(r++; l < r; l >>=1, r >>=1)\
    \ {\n            if(l&1) lazy[l] = Monoid::func_lazy(lazy[l],x), propagate(l),l++;\n\
    \            if(r&1) --r,lazy[r] = Monoid::func_lazy(lazy[r],x), propagate(r);\n\
    \        }\n    }\n\n    //fold [a,a+1)\n    TypeNode fold(int a) {\n        int\
    \ l = a + length;\n        for (int i = height; 0 <= i; --i) propagate(l >> i);\n\
    \        return node[a];\n    }\n\n    void print(){\n        cout << \"lazy\"\
    \ << endl;\n        for(int i = 1,j = 1; i < 2*length; ++i) {\n        \tcout\
    \ << lazy[i] << \" \";\n        \tif(i==((1<<j)-1) && ++j) cout << endl;\n   \
    \     }\n        cout << \"vector\" << endl;\n        cout << \"{ \" << fold(0);\n\
    \        for(int i = 1; i < length; ++i) cout << \", \" << fold(i);\n        cout\
    \ << \" }\" << endl;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/10-segment-tree/DualSegmentTree.cpp
  requiredBy: []
  timestamp: '2023-07-03 02:09:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segment-tree/DualSegmentTree-pcq.test.cpp
documentation_of: lib/10-segment-tree/DualSegmentTree.cpp
layout: document
redirect_from:
- /library/lib/10-segment-tree/DualSegmentTree.cpp
- /library/lib/10-segment-tree/DualSegmentTree.cpp.html
title: "DualSegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u53CC\u5BFE\u30BB\u30B0\
  \u30E1\u30F3\u30C8\u6728"
---
