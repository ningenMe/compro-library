---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/segment/ConvexHullTrickSegmentTree.test.cpp
    title: test/segment/ConvexHullTrickSegmentTree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: md/segment/ConvexHullTrickSegmentTree.md
    document_title: "ConvexHullTrickSegmentTree - \u975E\u5358\u8ABFCHT\u30BB\u30B0\
      \u30E1\u30F3\u30C8\u6728"
    links:
    - https://atcoder.jp/contests/wupc2019/tasks/wupc2019_i
  bundledCode: "#line 1 \"lib/segment/ConvexHullTrickSegmentTree.cpp\"\n/*\n * @title\
    \ ConvexHullTrickSegmentTree - \u975E\u5358\u8ABFCHT\u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728\n * @docs md/segment/ConvexHullTrickSegmentTree.md\n * @see https://atcoder.jp/contests/wupc2019/tasks/wupc2019_i\n\
    \ */\ntemplate<class Operator> class ConvexHullTrickSegmentTree {\n\tusing TypeValue\
    \ = typename Operator::TypeValue;\n\tusing TypeNode = pair<TypeValue,TypeValue>;\n\
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
    \  \n\t}\n};\n"
  code: "/*\n * @title ConvexHullTrickSegmentTree - \u975E\u5358\u8ABFCHT\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\n * @docs md/segment/ConvexHullTrickSegmentTree.md\n\
    \ * @see https://atcoder.jp/contests/wupc2019/tasks/wupc2019_i\n */\ntemplate<class\
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
    \  \n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/segment/ConvexHullTrickSegmentTree.cpp
  requiredBy: []
  timestamp: '2020-09-26 17:01:19+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/segment/ConvexHullTrickSegmentTree.test.cpp
documentation_of: lib/segment/ConvexHullTrickSegmentTree.cpp
layout: document
redirect_from:
- /library/lib/segment/ConvexHullTrickSegmentTree.cpp
- /library/lib/segment/ConvexHullTrickSegmentTree.cpp.html
title: "ConvexHullTrickSegmentTree - \u975E\u5358\u8ABFCHT\u30BB\u30B0\u30E1\u30F3\
  \u30C8\u6728"
---
