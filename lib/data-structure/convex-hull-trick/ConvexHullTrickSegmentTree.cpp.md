---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/data-structure/convex-hull-trick/ConvexHullTrickSegmentTree.md
    document_title: "ConvexHullTrickSegmentTree - \u975E\u5358\u8ABFCHT\u30BB\u30B0\
      \u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 1 \"lib/data-structure/convex-hull-trick/ConvexHullTrickSegmentTree.cpp\"\
    \n/*\n * @title ConvexHullTrickSegmentTree - \u975E\u5358\u8ABFCHT\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\n * @docs md/data-structure/convex-hull-trick/ConvexHullTrickSegmentTree.md\n\
    \ */\ntemplate<class Operator> class ConvexHullTrickSegmentTree {\n    using TypeValue\
    \ = typename Operator::TypeValue;\n    using TypeNode = pair<TypeValue,TypeValue>;\n\
    \    size_t length;\n    size_t num;\n    vector<ConvexHullTrick<Operator>> node;\n\
    public:\n    inline constexpr TypeValue y(const TypeNode p, TypeValue x) {\n \
    \       return p.first*x+p.second;\n    }\n    ConvexHullTrickSegmentTree(const\
    \ size_t num): num(num) {\n        for (length = 1; length <= num; length *= 2);\n\
    \        node.resize(2 * length);\n    }\n    //[idx,idx+1) insert{ax+b}\n   \
    \ void update(size_t idx, const TypeValue a, const TypeValue b) {\n        if(idx\
    \ < 0 || length <= idx) return;\n        for(idx+=length;idx;idx >>= 1) node[idx].insert(a,b);\n\
    \    }\n    //[l,r)\n    TypeValue get(int l, int r, TypeValue x) {\n        if\
    \ (l < 0 || length <= l || r < 0 || length < r) return Operator::unit_value;\n\
    \        TypeValue vl =  Operator::unit_value, vr = Operator::unit_value;\n  \
    \      for(l += length, r += length; l < r; l >>=1, r >>=1) {\n            if(l&1)\
    \ {\n                auto tl=node[l++].get(x);\n                vl = (Operator::func_compare(vl,tl)?vl:tl);\n\
    \            }\n            if(r&1) {\n                auto tr=node[--r].get(x);\n\
    \                vr = (Operator::func_compare(tr,vr)?tr:vr);\n            }\n\
    \        }\n        return (Operator::func_compare(vl,vr)?vl:vr);\n    }\n   \
    \ //[l,r)\n    TypeNode get_line(int l, int r, TypeValue x) {\n        if (l <\
    \ 0 || length <= l || r < 0 || length < r) return {0,Operator::unit_value};\n\
    \        TypeNode vl = {0,Operator::unit_value}, vr = {0,Operator::unit_value};\n\
    \        for(l += length, r += length; l < r; l >>=1, r >>=1) {\n            if(l&1)\
    \ {\n                auto tl=node[l++].get_line(x);\n                vl = (Operator::func_compare(y(vl,x),y(tl,x))?vl:tl);\n\
    \            }\n            if(r&1) {\n                auto tr=node[--r].get_line(x);\n\
    \                vr = (Operator::func_compare(y(tr,x),y(vr,x))?tr:vr);\n     \
    \       }\n        }\n        return (Operator::func_compare(y(vl,x),y(vr,x))?vl:vr);\n\
    \    }\n    void print(){\n        cout << \"node\" << endl;\n        for(int\
    \ i = 1,j = 1; i < 2*length; ++i) {\n            node[i].print();\n          \
    \  if(i==((1<<j)-1) && ++j) cout << endl;\n        }\n    }\n};\n"
  code: "/*\n * @title ConvexHullTrickSegmentTree - \u975E\u5358\u8ABFCHT\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\n * @docs md/data-structure/convex-hull-trick/ConvexHullTrickSegmentTree.md\n\
    \ */\ntemplate<class Operator> class ConvexHullTrickSegmentTree {\n    using TypeValue\
    \ = typename Operator::TypeValue;\n    using TypeNode = pair<TypeValue,TypeValue>;\n\
    \    size_t length;\n    size_t num;\n    vector<ConvexHullTrick<Operator>> node;\n\
    public:\n    inline constexpr TypeValue y(const TypeNode p, TypeValue x) {\n \
    \       return p.first*x+p.second;\n    }\n    ConvexHullTrickSegmentTree(const\
    \ size_t num): num(num) {\n        for (length = 1; length <= num; length *= 2);\n\
    \        node.resize(2 * length);\n    }\n    //[idx,idx+1) insert{ax+b}\n   \
    \ void update(size_t idx, const TypeValue a, const TypeValue b) {\n        if(idx\
    \ < 0 || length <= idx) return;\n        for(idx+=length;idx;idx >>= 1) node[idx].insert(a,b);\n\
    \    }\n    //[l,r)\n    TypeValue get(int l, int r, TypeValue x) {\n        if\
    \ (l < 0 || length <= l || r < 0 || length < r) return Operator::unit_value;\n\
    \        TypeValue vl =  Operator::unit_value, vr = Operator::unit_value;\n  \
    \      for(l += length, r += length; l < r; l >>=1, r >>=1) {\n            if(l&1)\
    \ {\n                auto tl=node[l++].get(x);\n                vl = (Operator::func_compare(vl,tl)?vl:tl);\n\
    \            }\n            if(r&1) {\n                auto tr=node[--r].get(x);\n\
    \                vr = (Operator::func_compare(tr,vr)?tr:vr);\n            }\n\
    \        }\n        return (Operator::func_compare(vl,vr)?vl:vr);\n    }\n   \
    \ //[l,r)\n    TypeNode get_line(int l, int r, TypeValue x) {\n        if (l <\
    \ 0 || length <= l || r < 0 || length < r) return {0,Operator::unit_value};\n\
    \        TypeNode vl = {0,Operator::unit_value}, vr = {0,Operator::unit_value};\n\
    \        for(l += length, r += length; l < r; l >>=1, r >>=1) {\n            if(l&1)\
    \ {\n                auto tl=node[l++].get_line(x);\n                vl = (Operator::func_compare(y(vl,x),y(tl,x))?vl:tl);\n\
    \            }\n            if(r&1) {\n                auto tr=node[--r].get_line(x);\n\
    \                vr = (Operator::func_compare(y(tr,x),y(vr,x))?tr:vr);\n     \
    \       }\n        }\n        return (Operator::func_compare(y(vl,x),y(vr,x))?vl:vr);\n\
    \    }\n    void print(){\n        cout << \"node\" << endl;\n        for(int\
    \ i = 1,j = 1; i < 2*length; ++i) {\n            node[i].print();\n          \
    \  if(i==((1<<j)-1) && ++j) cout << endl;\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data-structure/convex-hull-trick/ConvexHullTrickSegmentTree.cpp
  requiredBy: []
  timestamp: '2023-05-12 01:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data-structure/convex-hull-trick/ConvexHullTrickSegmentTree.cpp
layout: document
redirect_from:
- /library/lib/data-structure/convex-hull-trick/ConvexHullTrickSegmentTree.cpp
- /library/lib/data-structure/convex-hull-trick/ConvexHullTrickSegmentTree.cpp.html
title: "ConvexHullTrickSegmentTree - \u975E\u5358\u8ABFCHT\u30BB\u30B0\u30E1\u30F3\
  \u30C8\u6728"
---
### ConvexHullTrickSegmentTree
- セグ木にchtをのせたもの
- 内部でrbstを利用してるので、傾き、クエリの単調性がいらない

### コンストラクタ
- ConvexHullTrickSegmentTree(const size_t num)
  - numの長さで確保する

### メソッド
- update(size_t idx, const TypeValue a, const TypeValue b)
  - 区間[idx,idx+1)に直線ax+bを追加
  - $O(\log(N)^2)$
- get(int l, int r, TypeValue x)
  - 区間[l,r)におけるxにおける最大/最小値を取得
  - $O(\log(N)^2)$
- get_line(int l, int r, TypeValue x)
  - 区間[l,r)におけるxにおける最大/最小値をとる直線を取得
  - $O(\log(N)^2)$


### 参考資料
- [Problem B](https://onlinejudge.u-aizu.ac.jp/beta/room.html#ACPC2020Day2/problems/B)
- [I - Ramen](https://atcoder.jp/contests/wupc2019/tasks/wupc2019_i)
