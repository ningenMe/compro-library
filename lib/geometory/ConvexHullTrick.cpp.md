---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometory/ConvexHullTrick-no-monotone.test.cpp
    title: test/geometory/ConvexHullTrick-no-monotone.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometory/ConvexHullTrick-min.test.cpp
    title: test/geometory/ConvexHullTrick-min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometory/ConvexHullTrick-max.test.cpp
    title: test/geometory/ConvexHullTrick-max.test.cpp
  - icon: ':x:'
    path: test/segment/ConvexHullTrickSegmentTree.test.cpp
    title: test/segment/ConvexHullTrickSegmentTree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: ConvexHullTrick
    links: []
  bundledCode: "#line 1 \"lib/geometory/ConvexHullTrick.cpp\"\n/*\n * @title ConvexHullTrick\n\
    \ */\ntemplate<class Operator> class ConvexHullTrick {\nprivate:\n\tusing TypeValue\
    \ = typename Operator::TypeValue;\n\tstruct NodePair {\n\t\tusing TypeNode = pair<TypeValue,TypeValue>;\n\
    \t\tinline static constexpr TypeNode unit_node = {0,Operator::unit_value};\n\t\
    \tinline static constexpr TypeNode func_node(TypeNode l,TypeNode c,TypeNode r){return\
    \ {0,0};}\n\t};\n\tRbst<NodePair> lines;\n\n\t//3\u76F4\u7DDA\u306B\u95A2\u3057\
    \u3066line2\u304C\u5FC5\u8981\u304B\u78BA\u8A8D (\u3053\u306E\u3068\u304D a1 <\
    \ a2 < a3\u304C\u5FC5\u8981=rbst\u306E\u9806\u305D\u306E\u307E\u307E)\n\tinline\
    \ int is_required(const pair<TypeValue,TypeValue>& line1, const pair<TypeValue,TypeValue>&\
    \ line2, const pair<TypeValue,TypeValue>& line3) {\n\t\treturn Operator::func_compare((line2.second-line3.second)*(line2.first-line1.first),(line1.second-line2.second)*(line3.first-line2.first));\n\
    \t}\n\t\n\t//y=ax+b\u306E\u5024\n\tinline TypeValue y(const pair<TypeValue,TypeValue>\
    \ line, TypeValue x) {\n\t\treturn line.first * x + line.second;\n\t}\n\npublic:\n\
    \tConvexHullTrick() {\n\t\t// do nothing\n\t} \n\n\t//ax+b\u3092\u8FFD\u52A0\n\
    \tvoid insert(const TypeValue a, const TypeValue b) {\n\t\tinsert({a,b});\n\t\
    }\n\t//ax+b\u3092\u8FFD\u52A0 armortized O(log(N))\n\tvoid insert(const pair<TypeValue,TypeValue>\
    \ line) {\n\t\tint i,flg=1;\n\t\ti=lines.lower_bound(line);\n\t\tauto l=lines.get(i-1);\n\
    \t\tauto r=lines.get(i);\n\t\t//l\u3068\u50BE\u304D\u304C\u540C\u3058\u306A\u3089\
    \u3001\u3069\u3061\u3089\u304B\u3092erase\n\t\tif(flg && l.second!=Operator::unit_value\
    \ && l.first==line.first) {\n\t\t\tif(Operator::func_compare(l.second,line.second))\
    \ return;\n\t\t\telse lines.erase(l),flg=0;\n\t\t}\t\n\t\t//r\u3068\u50BE\u304D\
    \u304C\u540C\u3058\u306A\u3089\u3001\u3069\u3061\u3089\u304B\u3092erase\n\t\t\
    if(flg && r.second!=Operator::unit_value && line.first==r.first) {\n\t\t\tif(Operator::func_compare(r.second,line.second))\
    \ return;\n\t\t\telse lines.erase(r),flg=0;\n\t\t}\t\n\t\t//\u81EA\u8EAB\u304C\
    \u5FC5\u8981\u304B\u5224\u5B9A\n\t\tif(flg && l.second!=Operator::unit_value &&\
    \ r.second!=Operator::unit_value && !is_required(l,line,r)) return;\n\t\t//\u50BE\
    \u304D\u304C\u5C0F\u3055\u3044\u5074\u306E\u4E0D\u5FC5\u8981\u306A\u76F4\u7DDA\
    \u3092\u53D6\u308A\u9664\u304F\n\t\tfor(i=lines.lower_bound(line);i>=2&&!is_required(lines.get(i-2),\
    \ lines.get(i-1), line);i=lines.lower_bound(line)) lines.erase(lines.get(i-1));\n\
    \t\t//\u50BE\u304D\u304C\u5927\u304D\u3044\u5074\u306E\u4E0D\u5FC5\u8981\u306A\
    \u76F4\u7DDA\u3092\u53D6\u308A\u9664\u304F\n\t\tfor(i=lines.lower_bound(line);i+1<lines.size()&&!is_required(line,lines.get(i),lines.get(i+1));i=lines.lower_bound(line))\
    \ lines.erase(lines.get(i));\n\t\tlines.insert(line);\n\t}\n\t\n\t//O(log(N)^2)\n\
    \tTypeValue get(TypeValue x) {\n\t\tint ng = -1, ok = (int)lines.size()-1, md;\n\
    \t\twhile (ok - ng > 1) {\n\t\t\tmd = (ok + ng) >> 1;\n\t\t\t( Operator::func_compare(y(lines.get(md),x),y(lines.get(md+1),x))\
    \ ?ok:ng)=md;\n\t\t}\n\t\treturn y(lines.get(ok),x);\n\t}\n\n\t//O(log(N)^2)\n\
    \tpair<TypeValue,TypeValue> get_line(TypeValue x) {\n\t\tint ng = -1, ok = (int)lines.size()-1,\
    \ md;\n\t\twhile (ok - ng > 1) {\n\t\t\tmd = (ok + ng) >> 1;\n\t\t\t( Operator::func_compare(y(lines.get(md),x),y(lines.get(md+1),x))\
    \ ?ok:ng)=md;\n\t\t}\n\t\treturn lines.get(ok);\n\t}\n\n\tvoid print() {\n\t\t\
    lines.print();\n\t}\n};\n\n//\u6700\u5C0F\u5024\u30AF\u30A8\u30EA\ntemplate<class\
    \ T> struct ValueMin {\n\tusing TypeValue = T;\n\tinline static constexpr TypeValue\
    \ unit_value = 3e18;\n\tinline static constexpr bool func_compare(TypeValue l,TypeValue\
    \ r){return l<r;}\n};\n\n//\u6700\u5927\u5024\u30AF\u30A8\u30EA\ntemplate<class\
    \ T> struct ValueMax {\n\tusing TypeValue = T;\n\tinline static constexpr TypeValue\
    \ unit_value = -3e18;\n\tinline static constexpr bool func_compare(TypeValue l,TypeValue\
    \ r){return l>r;}\n};\n"
  code: "/*\n * @title ConvexHullTrick\n */\ntemplate<class Operator> class ConvexHullTrick\
    \ {\nprivate:\n\tusing TypeValue = typename Operator::TypeValue;\n\tstruct NodePair\
    \ {\n\t\tusing TypeNode = pair<TypeValue,TypeValue>;\n\t\tinline static constexpr\
    \ TypeNode unit_node = {0,Operator::unit_value};\n\t\tinline static constexpr\
    \ TypeNode func_node(TypeNode l,TypeNode c,TypeNode r){return {0,0};}\n\t};\n\t\
    Rbst<NodePair> lines;\n\n\t//3\u76F4\u7DDA\u306B\u95A2\u3057\u3066line2\u304C\u5FC5\
    \u8981\u304B\u78BA\u8A8D (\u3053\u306E\u3068\u304D a1 < a2 < a3\u304C\u5FC5\u8981\
    =rbst\u306E\u9806\u305D\u306E\u307E\u307E)\n\tinline int is_required(const pair<TypeValue,TypeValue>&\
    \ line1, const pair<TypeValue,TypeValue>& line2, const pair<TypeValue,TypeValue>&\
    \ line3) {\n\t\treturn Operator::func_compare((line2.second-line3.second)*(line2.first-line1.first),(line1.second-line2.second)*(line3.first-line2.first));\n\
    \t}\n\t\n\t//y=ax+b\u306E\u5024\n\tinline TypeValue y(const pair<TypeValue,TypeValue>\
    \ line, TypeValue x) {\n\t\treturn line.first * x + line.second;\n\t}\n\npublic:\n\
    \tConvexHullTrick() {\n\t\t// do nothing\n\t} \n\n\t//ax+b\u3092\u8FFD\u52A0\n\
    \tvoid insert(const TypeValue a, const TypeValue b) {\n\t\tinsert({a,b});\n\t\
    }\n\t//ax+b\u3092\u8FFD\u52A0 armortized O(log(N))\n\tvoid insert(const pair<TypeValue,TypeValue>\
    \ line) {\n\t\tint i,flg=1;\n\t\ti=lines.lower_bound(line);\n\t\tauto l=lines.get(i-1);\n\
    \t\tauto r=lines.get(i);\n\t\t//l\u3068\u50BE\u304D\u304C\u540C\u3058\u306A\u3089\
    \u3001\u3069\u3061\u3089\u304B\u3092erase\n\t\tif(flg && l.second!=Operator::unit_value\
    \ && l.first==line.first) {\n\t\t\tif(Operator::func_compare(l.second,line.second))\
    \ return;\n\t\t\telse lines.erase(l),flg=0;\n\t\t}\t\n\t\t//r\u3068\u50BE\u304D\
    \u304C\u540C\u3058\u306A\u3089\u3001\u3069\u3061\u3089\u304B\u3092erase\n\t\t\
    if(flg && r.second!=Operator::unit_value && line.first==r.first) {\n\t\t\tif(Operator::func_compare(r.second,line.second))\
    \ return;\n\t\t\telse lines.erase(r),flg=0;\n\t\t}\t\n\t\t//\u81EA\u8EAB\u304C\
    \u5FC5\u8981\u304B\u5224\u5B9A\n\t\tif(flg && l.second!=Operator::unit_value &&\
    \ r.second!=Operator::unit_value && !is_required(l,line,r)) return;\n\t\t//\u50BE\
    \u304D\u304C\u5C0F\u3055\u3044\u5074\u306E\u4E0D\u5FC5\u8981\u306A\u76F4\u7DDA\
    \u3092\u53D6\u308A\u9664\u304F\n\t\tfor(i=lines.lower_bound(line);i>=2&&!is_required(lines.get(i-2),\
    \ lines.get(i-1), line);i=lines.lower_bound(line)) lines.erase(lines.get(i-1));\n\
    \t\t//\u50BE\u304D\u304C\u5927\u304D\u3044\u5074\u306E\u4E0D\u5FC5\u8981\u306A\
    \u76F4\u7DDA\u3092\u53D6\u308A\u9664\u304F\n\t\tfor(i=lines.lower_bound(line);i+1<lines.size()&&!is_required(line,lines.get(i),lines.get(i+1));i=lines.lower_bound(line))\
    \ lines.erase(lines.get(i));\n\t\tlines.insert(line);\n\t}\n\t\n\t//O(log(N)^2)\n\
    \tTypeValue get(TypeValue x) {\n\t\tint ng = -1, ok = (int)lines.size()-1, md;\n\
    \t\twhile (ok - ng > 1) {\n\t\t\tmd = (ok + ng) >> 1;\n\t\t\t( Operator::func_compare(y(lines.get(md),x),y(lines.get(md+1),x))\
    \ ?ok:ng)=md;\n\t\t}\n\t\treturn y(lines.get(ok),x);\n\t}\n\n\t//O(log(N)^2)\n\
    \tpair<TypeValue,TypeValue> get_line(TypeValue x) {\n\t\tint ng = -1, ok = (int)lines.size()-1,\
    \ md;\n\t\twhile (ok - ng > 1) {\n\t\t\tmd = (ok + ng) >> 1;\n\t\t\t( Operator::func_compare(y(lines.get(md),x),y(lines.get(md+1),x))\
    \ ?ok:ng)=md;\n\t\t}\n\t\treturn lines.get(ok);\n\t}\n\n\tvoid print() {\n\t\t\
    lines.print();\n\t}\n};\n\n//\u6700\u5C0F\u5024\u30AF\u30A8\u30EA\ntemplate<class\
    \ T> struct ValueMin {\n\tusing TypeValue = T;\n\tinline static constexpr TypeValue\
    \ unit_value = 3e18;\n\tinline static constexpr bool func_compare(TypeValue l,TypeValue\
    \ r){return l<r;}\n};\n\n//\u6700\u5927\u5024\u30AF\u30A8\u30EA\ntemplate<class\
    \ T> struct ValueMax {\n\tusing TypeValue = T;\n\tinline static constexpr TypeValue\
    \ unit_value = -3e18;\n\tinline static constexpr bool func_compare(TypeValue l,TypeValue\
    \ r){return l>r;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/geometory/ConvexHullTrick.cpp
  requiredBy: []
  timestamp: '2020-07-26 22:40:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/geometory/ConvexHullTrick-no-monotone.test.cpp
  - test/geometory/ConvexHullTrick-min.test.cpp
  - test/geometory/ConvexHullTrick-max.test.cpp
  - test/segment/ConvexHullTrickSegmentTree.test.cpp
documentation_of: lib/geometory/ConvexHullTrick.cpp
layout: document
redirect_from:
- /library/lib/geometory/ConvexHullTrick.cpp
- /library/lib/geometory/ConvexHullTrick.cpp.html
title: ConvexHullTrick
---
