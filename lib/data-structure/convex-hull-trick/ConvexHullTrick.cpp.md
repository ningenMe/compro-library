---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/convex-hull-trick/ConvexHullTrick-max.test.cpp
    title: test/data-structure/convex-hull-trick/ConvexHullTrick-max.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/convex-hull-trick/ConvexHullTrick-min.test.cpp
    title: test/data-structure/convex-hull-trick/ConvexHullTrick-min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/convex-hull-trick/ConvexHullTrick-no-monotone.test.cpp
    title: test/data-structure/convex-hull-trick/ConvexHullTrick-no-monotone.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/data-structure/convex-hull-trick/ConvexHullTrick.md
    document_title: "ConvexHullTrick - \u975E\u5358\u8ABFCHT"
    links: []
  bundledCode: "#line 1 \"lib/data-structure/convex-hull-trick/ConvexHullTrick.cpp\"\
    \n/*\n * @title ConvexHullTrick - \u975E\u5358\u8ABFCHT\n * @docs md/data-structure/convex-hull-trick/ConvexHullTrick.md\n\
    \ */\ntemplate<class Operator> class ConvexHullTrick {\nprivate:\n\tusing TypeValue\
    \ = typename Operator::TypeValue;\n\tusing Line = pair<TypeValue,TypeValue>;\n\
    \tstruct Monoid {\n\t\tusing TypeNode = Line;\n\t\tinline static constexpr TypeNode\
    \ unit_node = {0,0};\n\t\tinline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return {0,0};}\n\t};\n\tRandomizedBinarySearchTree<Monoid> lines;\n\
    \n\t//3\u76F4\u7DDA\u306B\u95A2\u3057\u3066line2\u304C\u5FC5\u8981\u304B\u78BA\
    \u8A8D (\u3053\u306E\u3068\u304D a1 < a2 < a3\u304C\u5FC5\u8981=rbst\u306E\u9806\
    \u305D\u306E\u307E\u307E)\n\tinline int is_required(const Line& line1, const Line&\
    \ line2, const Line& line3) {\n\t\treturn Operator::func_compare((line2.second-line3.second)*(line2.first-line1.first),(line1.second-line2.second)*(line3.first-line2.first));\n\
    \t}\n\t\n\t//y=ax+b\u306E\u5024\n\tinline TypeValue y(const Line line, TypeValue\
    \ x) {\n\t\treturn line.first * x + line.second;\n\t}\n\npublic:\n\tConvexHullTrick()\
    \ {\n\t\t// do nothing\n\t} \n\n\t//ax+b\u3092\u8FFD\u52A0\n\tvoid insert(const\
    \ TypeValue a, const TypeValue b) {\n\t\tinsert({a,b});\n\t}\n\t//ax+b\u3092\u8FFD\
    \u52A0 armortized O(log(N))\n\tvoid insert(const Line line) {\n\t\tint k=lines.lower_bound(line),\
    \ flg=1;\n\t\tLine l,r;\n\t\tif(0 <= k-1) {\n\t\t\tl = lines.get(k-1);\n\t\t\t\
    //l\u3068\u50BE\u304D\u304C\u540C\u3058\u306A\u3089\u3001\u3069\u3061\u3089\u304B\
    \u3092erase\n\t\t\tif(l.first==line.first) {\n\t\t\t\tif(Operator::func_compare(l.second,line.second))\
    \ return;\n\t\t\t\telse lines.erase(l);\n\t\t\t}\n\t\t}\n\t\tif(k < lines.size())\
    \ {\n\t\t\tr = lines.get(k);\n\t\t\t//r\u3068\u50BE\u304D\u304C\u540C\u3058\u306A\
    \u3089\u3001\u3069\u3061\u3089\u304B\u3092erase\n\t\t\tif(r.first==line.first)\
    \ {\n\t\t\t\tif(Operator::func_compare(r.second,line.second)) return;\n\t\t\t\t\
    else lines.erase(r);\n\t\t\t}\t\n\t\t}\n\t\t//\u81EA\u8EAB\u304C\u5FC5\u8981\u304B\
    \u5224\u5B9A\n\t\tif(0 <= k-1 && k < lines.size() && !is_required(l,line,r)) return;\n\
    \t\t//\u50BE\u304D\u304C\u5C0F\u3055\u3044\u5074\u306E\u4E0D\u5FC5\u8981\u306A\
    \u76F4\u7DDA\u3092\u53D6\u308A\u9664\u304F\n\t\tfor(k=lines.lower_bound(line);k>=2&&!is_required(lines.get(k-2),\
    \ lines.get(k-1), line);k=lines.lower_bound(line)) lines.erase(lines.get(k-1));\n\
    \t\t//\u50BE\u304D\u304C\u5927\u304D\u3044\u5074\u306E\u4E0D\u5FC5\u8981\u306A\
    \u76F4\u7DDA\u3092\u53D6\u308A\u9664\u304F\n\t\tfor(k=lines.lower_bound(line);k+1<lines.size()&&!is_required(line,lines.get(k),lines.get(k+1));k=lines.lower_bound(line))\
    \ lines.erase(lines.get(k));\n\t\tlines.insert(line);\n\t}\n\t\n\t//O(log(N)^2)\n\
    \tTypeValue get(TypeValue x) {\n\t\tint ng = -1, ok = (int)lines.size()-1, md;\n\
    \t\twhile (ok - ng > 1) {\n\t\t\tmd = (ok + ng) >> 1;\n\t\t\t( Operator::func_compare(y(lines.get(md),x),y(lines.get(md+1),x))\
    \ ?ok:ng)=md;\n\t\t}\n\t\treturn y(lines.get(ok),x);\n\t}\n\n\t//O(log(N)^2)\n\
    \tLine get_line(TypeValue x) {\n\t\tint ng = -1, ok = (int)lines.size()-1, md;\n\
    \t\twhile (ok - ng > 1) {\n\t\t\tmd = (ok + ng) >> 1;\n\t\t\t( Operator::func_compare(y(lines.get(md),x),y(lines.get(md+1),x))\
    \ ?ok:ng)=md;\n\t\t}\n\t\treturn lines.get(ok);\n\t}\n\n\tvoid print() {\n\t\t\
    lines.print();\n\t}\n};\n"
  code: "/*\n * @title ConvexHullTrick - \u975E\u5358\u8ABFCHT\n * @docs md/data-structure/convex-hull-trick/ConvexHullTrick.md\n\
    \ */\ntemplate<class Operator> class ConvexHullTrick {\nprivate:\n\tusing TypeValue\
    \ = typename Operator::TypeValue;\n\tusing Line = pair<TypeValue,TypeValue>;\n\
    \tstruct Monoid {\n\t\tusing TypeNode = Line;\n\t\tinline static constexpr TypeNode\
    \ unit_node = {0,0};\n\t\tinline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return {0,0};}\n\t};\n\tRandomizedBinarySearchTree<Monoid> lines;\n\
    \n\t//3\u76F4\u7DDA\u306B\u95A2\u3057\u3066line2\u304C\u5FC5\u8981\u304B\u78BA\
    \u8A8D (\u3053\u306E\u3068\u304D a1 < a2 < a3\u304C\u5FC5\u8981=rbst\u306E\u9806\
    \u305D\u306E\u307E\u307E)\n\tinline int is_required(const Line& line1, const Line&\
    \ line2, const Line& line3) {\n\t\treturn Operator::func_compare((line2.second-line3.second)*(line2.first-line1.first),(line1.second-line2.second)*(line3.first-line2.first));\n\
    \t}\n\t\n\t//y=ax+b\u306E\u5024\n\tinline TypeValue y(const Line line, TypeValue\
    \ x) {\n\t\treturn line.first * x + line.second;\n\t}\n\npublic:\n\tConvexHullTrick()\
    \ {\n\t\t// do nothing\n\t} \n\n\t//ax+b\u3092\u8FFD\u52A0\n\tvoid insert(const\
    \ TypeValue a, const TypeValue b) {\n\t\tinsert({a,b});\n\t}\n\t//ax+b\u3092\u8FFD\
    \u52A0 armortized O(log(N))\n\tvoid insert(const Line line) {\n\t\tint k=lines.lower_bound(line),\
    \ flg=1;\n\t\tLine l,r;\n\t\tif(0 <= k-1) {\n\t\t\tl = lines.get(k-1);\n\t\t\t\
    //l\u3068\u50BE\u304D\u304C\u540C\u3058\u306A\u3089\u3001\u3069\u3061\u3089\u304B\
    \u3092erase\n\t\t\tif(l.first==line.first) {\n\t\t\t\tif(Operator::func_compare(l.second,line.second))\
    \ return;\n\t\t\t\telse lines.erase(l);\n\t\t\t}\n\t\t}\n\t\tif(k < lines.size())\
    \ {\n\t\t\tr = lines.get(k);\n\t\t\t//r\u3068\u50BE\u304D\u304C\u540C\u3058\u306A\
    \u3089\u3001\u3069\u3061\u3089\u304B\u3092erase\n\t\t\tif(r.first==line.first)\
    \ {\n\t\t\t\tif(Operator::func_compare(r.second,line.second)) return;\n\t\t\t\t\
    else lines.erase(r);\n\t\t\t}\t\n\t\t}\n\t\t//\u81EA\u8EAB\u304C\u5FC5\u8981\u304B\
    \u5224\u5B9A\n\t\tif(0 <= k-1 && k < lines.size() && !is_required(l,line,r)) return;\n\
    \t\t//\u50BE\u304D\u304C\u5C0F\u3055\u3044\u5074\u306E\u4E0D\u5FC5\u8981\u306A\
    \u76F4\u7DDA\u3092\u53D6\u308A\u9664\u304F\n\t\tfor(k=lines.lower_bound(line);k>=2&&!is_required(lines.get(k-2),\
    \ lines.get(k-1), line);k=lines.lower_bound(line)) lines.erase(lines.get(k-1));\n\
    \t\t//\u50BE\u304D\u304C\u5927\u304D\u3044\u5074\u306E\u4E0D\u5FC5\u8981\u306A\
    \u76F4\u7DDA\u3092\u53D6\u308A\u9664\u304F\n\t\tfor(k=lines.lower_bound(line);k+1<lines.size()&&!is_required(line,lines.get(k),lines.get(k+1));k=lines.lower_bound(line))\
    \ lines.erase(lines.get(k));\n\t\tlines.insert(line);\n\t}\n\t\n\t//O(log(N)^2)\n\
    \tTypeValue get(TypeValue x) {\n\t\tint ng = -1, ok = (int)lines.size()-1, md;\n\
    \t\twhile (ok - ng > 1) {\n\t\t\tmd = (ok + ng) >> 1;\n\t\t\t( Operator::func_compare(y(lines.get(md),x),y(lines.get(md+1),x))\
    \ ?ok:ng)=md;\n\t\t}\n\t\treturn y(lines.get(ok),x);\n\t}\n\n\t//O(log(N)^2)\n\
    \tLine get_line(TypeValue x) {\n\t\tint ng = -1, ok = (int)lines.size()-1, md;\n\
    \t\twhile (ok - ng > 1) {\n\t\t\tmd = (ok + ng) >> 1;\n\t\t\t( Operator::func_compare(y(lines.get(md),x),y(lines.get(md+1),x))\
    \ ?ok:ng)=md;\n\t\t}\n\t\treturn lines.get(ok);\n\t}\n\n\tvoid print() {\n\t\t\
    lines.print();\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data-structure/convex-hull-trick/ConvexHullTrick.cpp
  requiredBy: []
  timestamp: '2021-05-03 04:46:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/convex-hull-trick/ConvexHullTrick-max.test.cpp
  - test/data-structure/convex-hull-trick/ConvexHullTrick-min.test.cpp
  - test/data-structure/convex-hull-trick/ConvexHullTrick-no-monotone.test.cpp
documentation_of: lib/data-structure/convex-hull-trick/ConvexHullTrick.cpp
layout: document
redirect_from:
- /library/lib/data-structure/convex-hull-trick/ConvexHullTrick.cpp
- /library/lib/data-structure/convex-hull-trick/ConvexHullTrick.cpp.html
title: "ConvexHullTrick - \u975E\u5358\u8ABFCHT"
---
