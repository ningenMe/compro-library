---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/segment/ConvexHullTrickSegmentTree.md
    document_title: "ConvexHullTrickSegmentTree - \u975E\u5358\u8ABFCHT\u30BB\u30B0\
      \u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 1 \"lib/segment/ConvexHullTrickSegmentTree.cpp\"\n/*\n * @title\
    \ ConvexHullTrickSegmentTree - \u975E\u5358\u8ABFCHT\u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728\n * @docs md/segment/ConvexHullTrickSegmentTree.md\n * @see \n */\ntemplate<class\
    \ Operator> class ConvexHullTrickSegmentTree {\n\tusing TypeValue = typename Operator::TypeValue;\n\
    \tusing TypeNode = pair<TypeValue,TypeValue>;\n\tsize_t length;\n\tsize_t num;\n\
    \tvector<ConvexHullTrick<Operator>> node;\npublic:\n\tinline constexpr TypeValue\
    \ y(const TypeNode p, TypeValue x) {\n\t\treturn p.first*x+p.second;\n\t}\n\t\
    ConvexHullTrickSegmentTree(const size_t num): num(num) {\n\t\tfor (length = 1;\
    \ length <= num; length *= 2);\n\t\tnode.resize(2 * length);\n\t}\n\t//[idx,idx+1)\
    \ insert{ax+b}\n\tvoid update(size_t idx, const TypeValue a, const TypeValue b)\
    \ {\n\t\tif(idx < 0 || length <= idx) return;\n\t\tfor(idx+=length;idx;idx >>=\
    \ 1) node[idx].insert(a,b);\n\t}\n\t//[l,r)\n\tTypeValue get(int l, int r, TypeValue\
    \ x) {\n\t\tif (l < 0 || length <= l || r < 0 || length < r) return Operator::unit_value;\n\
    \t\tTypeValue vl =  Operator::unit_value, vr = Operator::unit_value;\n\t\tfor(l\
    \ += length, r += length; l < r; l >>=1, r >>=1) {\n\t\t\tif(l&1) {\n\t\t\t\t\
    auto tl=node[l++].get(x);                \n\t\t\t\tvl = (Operator::func_compare(vl,tl)?vl:tl);\n\
    \t\t\t}\n\t\t\tif(r&1) {\n\t\t\t\tauto tr=node[--r].get(x);                \n\t\
    \t\t\tvr = (Operator::func_compare(tr,vr)?tr:vr);\n\t\t\t}\n\t\t}\n\t\treturn\
    \ (Operator::func_compare(vl,vr)?vl:vr);\n\t}\n\t//[l,r)\n\tTypeNode get_line(int\
    \ l, int r, TypeValue x) {\n\t\tif (l < 0 || length <= l || r < 0 || length <\
    \ r) return {0,Operator::unit_value};\n\t\tTypeNode vl = {0,Operator::unit_value},\
    \ vr = {0,Operator::unit_value};\n\t\tfor(l += length, r += length; l < r; l >>=1,\
    \ r >>=1) {\n\t\t\tif(l&1) {\n\t\t\t\tauto tl=node[l++].get_line(x);         \
    \       \n\t\t\t\tvl = (Operator::func_compare(y(vl,x),y(tl,x))?vl:tl);\n\t\t\t\
    }\n\t\t\tif(r&1) {\n\t\t\t\tauto tr=node[--r].get_line(x);                \n\t\
    \t\t\tvr = (Operator::func_compare(y(tr,x),y(vr,x))?tr:vr);\n\t\t\t}\n\t\t}\n\t\
    \treturn (Operator::func_compare(y(vl,x),y(vr,x))?vl:vr);\n\t}\n\tvoid print(){\n\
    \t\tcout << \"node\" << endl;\n\t\tfor(int i = 1,j = 1; i < 2*length; ++i) {\n\
    \t\t\tnode[i].print();\n\t\t\tif(i==((1<<j)-1) && ++j) cout << endl;\n\t\t}  \
    \  \n\t}\n};\n"
  code: "/*\n * @title ConvexHullTrickSegmentTree - \u975E\u5358\u8ABFCHT\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\n * @docs md/segment/ConvexHullTrickSegmentTree.md\n\
    \ * @see \n */\ntemplate<class Operator> class ConvexHullTrickSegmentTree {\n\t\
    using TypeValue = typename Operator::TypeValue;\n\tusing TypeNode = pair<TypeValue,TypeValue>;\n\
    \tsize_t length;\n\tsize_t num;\n\tvector<ConvexHullTrick<Operator>> node;\npublic:\n\
    \tinline constexpr TypeValue y(const TypeNode p, TypeValue x) {\n\t\treturn p.first*x+p.second;\n\
    \t}\n\tConvexHullTrickSegmentTree(const size_t num): num(num) {\n\t\tfor (length\
    \ = 1; length <= num; length *= 2);\n\t\tnode.resize(2 * length);\n\t}\n\t//[idx,idx+1)\
    \ insert{ax+b}\n\tvoid update(size_t idx, const TypeValue a, const TypeValue b)\
    \ {\n\t\tif(idx < 0 || length <= idx) return;\n\t\tfor(idx+=length;idx;idx >>=\
    \ 1) node[idx].insert(a,b);\n\t}\n\t//[l,r)\n\tTypeValue get(int l, int r, TypeValue\
    \ x) {\n\t\tif (l < 0 || length <= l || r < 0 || length < r) return Operator::unit_value;\n\
    \t\tTypeValue vl =  Operator::unit_value, vr = Operator::unit_value;\n\t\tfor(l\
    \ += length, r += length; l < r; l >>=1, r >>=1) {\n\t\t\tif(l&1) {\n\t\t\t\t\
    auto tl=node[l++].get(x);                \n\t\t\t\tvl = (Operator::func_compare(vl,tl)?vl:tl);\n\
    \t\t\t}\n\t\t\tif(r&1) {\n\t\t\t\tauto tr=node[--r].get(x);                \n\t\
    \t\t\tvr = (Operator::func_compare(tr,vr)?tr:vr);\n\t\t\t}\n\t\t}\n\t\treturn\
    \ (Operator::func_compare(vl,vr)?vl:vr);\n\t}\n\t//[l,r)\n\tTypeNode get_line(int\
    \ l, int r, TypeValue x) {\n\t\tif (l < 0 || length <= l || r < 0 || length <\
    \ r) return {0,Operator::unit_value};\n\t\tTypeNode vl = {0,Operator::unit_value},\
    \ vr = {0,Operator::unit_value};\n\t\tfor(l += length, r += length; l < r; l >>=1,\
    \ r >>=1) {\n\t\t\tif(l&1) {\n\t\t\t\tauto tl=node[l++].get_line(x);         \
    \       \n\t\t\t\tvl = (Operator::func_compare(y(vl,x),y(tl,x))?vl:tl);\n\t\t\t\
    }\n\t\t\tif(r&1) {\n\t\t\t\tauto tr=node[--r].get_line(x);                \n\t\
    \t\t\tvr = (Operator::func_compare(y(tr,x),y(vr,x))?tr:vr);\n\t\t\t}\n\t\t}\n\t\
    \treturn (Operator::func_compare(y(vl,x),y(vr,x))?vl:vr);\n\t}\n\tvoid print(){\n\
    \t\tcout << \"node\" << endl;\n\t\tfor(int i = 1,j = 1; i < 2*length; ++i) {\n\
    \t\t\tnode[i].print();\n\t\t\tif(i==((1<<j)-1) && ++j) cout << endl;\n\t\t}  \
    \  \n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/segment/ConvexHullTrickSegmentTree.cpp
  requiredBy: []
  timestamp: '2021-04-21 01:30:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/segment/ConvexHullTrickSegmentTree.cpp
layout: document
redirect_from:
- /library/lib/segment/ConvexHullTrickSegmentTree.cpp
- /library/lib/segment/ConvexHullTrickSegmentTree.cpp.html
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
