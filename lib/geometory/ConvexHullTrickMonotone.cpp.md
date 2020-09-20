---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometory/ConvexHullTrickMonotone-min.test.cpp
    title: test/geometory/ConvexHullTrickMonotone-min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometory/ConvexHullTrickMonotone-max.test.cpp
    title: test/geometory/ConvexHullTrickMonotone-max.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: ConvexHullTrickMonotone
    links: []
  bundledCode: "#line 1 \"lib/geometory/ConvexHullTrickMonotone.cpp\"\n/*\n * @title\
    \ ConvexHullTrickMonotone\n */\ntemplate<class Operator> class ConvexHullTrickMonotone\
    \ {\nprivate:\n\tusing TypeValue = typename Operator::TypeValue;\n\n\t//front->back\u306B\
    \u5411\u304B\u3063\u3066\u50BE\u304D\u304Ca1<a2<...<aN\n\tdeque<pair<TypeValue,TypeValue>>\
    \ lines;\n\n\t//3\u76F4\u7DDA\u306B\u95A2\u3057\u3066line2\u304C\u5FC5\u8981\u304B\
    \u78BA\u8A8D (\u3053\u306E\u3068\u304D a1 < a2 < a3\u304C\u5FC5\u8981=deque\u306E\
    \u9806\u305D\u306E\u307E\u307E)\n\tinline int is_required(const pair<TypeValue,TypeValue>&\
    \ line1, const pair<TypeValue,TypeValue>& line2, const pair<TypeValue,TypeValue>&\
    \ line3) {\n\t\treturn Operator::func_compare((line2.second-line3.second)*(line2.first-line1.first),(line1.second-line2.second)*(line3.first-line2.first));\n\
    \t}\n\n\t//y=ax+b\u306E\u5024\n\tinline TypeValue y(const pair<TypeValue,TypeValue>\
    \ line, TypeValue x) {\n\t\treturn line.first * x + line.second;\n\t}\n\n\tinline\
    \ void insert_back(const pair<TypeValue,TypeValue> line){\n\t\t//\u50BE\u304D\u304C\
    \u540C\u3058\u3068\u304D\n\t\tif(lines.size() && lines.back().first == line.first){\n\
    \t\t\tif(Operator::func_compare(lines.back().second,line.second)) return;\n\t\t\
    \telse lines.pop_back();\n\t\t}\n\t\t//\u4E0D\u5FC5\u8981\u306A\u76F4\u7DDA\u3092\
    \u53D6\u308A\u9664\u304F\n\t\twhile (lines.size() > 1 && !is_required(lines[(int)lines.size()-2],\
    \ lines[(int)lines.size()-1],line)) lines.pop_back();\n\t\t//back\u306Binsert\n\
    \t\tlines.push_back(line);\n\t}\n\tinline void insert_front(const pair<TypeValue,TypeValue>\
    \ line){\n\t\t//\u50BE\u304D\u304C\u540C\u3058\u3068\u304D\n\t\tif(lines.size()\
    \ && lines.front().first == line.first){\n\t\t\tif(Operator::func_compare(lines.front().second,line.second))\
    \ return;\n\t\t\telse lines.pop_front();\n\t\t}\n\t\t//\u4E0D\u5FC5\u8981\u306A\
    \u76F4\u7DDA\u3092\u53D6\u308A\u9664\u304F\n\t\twhile (lines.size() > 1 && !is_required(line,\
    \ lines[0], lines[1])) lines.pop_front();\n\t\t//front\u306Binsert\n\t\tlines.push_front(line);\n\
    \t}\npublic:\n\tConvexHullTrickMonotone() {\n\t\t// do nothing\n\t} \n\tinline\
    \ void insert(const TypeValue a, const TypeValue b) {\n\t\tinsert({a,b});\n\t\
    }\n\t//\u50BE\u304D\u306E\u5927\u304D\u3055\u304C\u5E38\u306B\u6700\u5927or\u6700\
    \u5C0F\u306B\u306A\u308B\u3088\u3046\u306Binsert\u3059\u308B\n\tinline void insert(const\
    \ pair<TypeValue,TypeValue> line) {\n\t\tif(lines.empty() || line.first <= lines.front().first)\
    \ insert_front(line);\n\t\telse if(lines.back().first <= line.first) insert_back(line);\n\
    \t\telse assert(false);\n\t}\n\t//O(log(N))\n\tinline TypeValue get(TypeValue\
    \ x) {\n\t\tif(lines.empty()) return Operator::unit_value;\n\t\tint ng = -1, ok\
    \ = (int)lines.size()-1, md;\n\t\twhile (ok - ng > 1) {\n\t\t\tmd = (ok + ng)\
    \ >> 1;\n\t\t\t( Operator::func_compare(y(lines[md],x),y(lines[md+1],x)) ?ok:ng)=md;\n\
    \t\t}\n\t\treturn y(lines[ok],x);\n\t}\n\t//O(log(N))\n\tinline pair<TypeValue,TypeValue>\
    \ get_line(TypeValue x) {\n\t\tif(lines.empty()) return {0,Operator::unit_value};\n\
    \t\tint ng = -1, ok = (int)lines.size()-1, md;\n\t\twhile (ok - ng > 1) {\n\t\t\
    \tmd = (ok + ng) >> 1;\n\t\t\t( Operator::func_compare(y(lines[md],x),y(lines[md+1],x))\
    \ ?ok:ng)=md;\n\t\t}\n\t\treturn lines[ok];\n\t}\n\t//O(N)\n\tinline void clear(void)\
    \ {\n\t\tlines.clear();\n\t}\n};\n\n//\u6700\u5C0F\u5024\u30AF\u30A8\u30EA\ntemplate<class\
    \ T> struct ValueMin {\n\tusing TypeValue = T;\n\tinline static constexpr TypeValue\
    \ unit_value = 3e18;\n\tinline static constexpr bool func_compare(TypeValue l,TypeValue\
    \ r){return l<r;}\n};\n\n//\u6700\u5927\u5024\u30AF\u30A8\u30EA\ntemplate<class\
    \ T> struct ValueMax {\n\tusing TypeValue = T;\n\tinline static constexpr TypeValue\
    \ unit_value = -3e18;\n\tinline static constexpr bool func_compare(TypeValue l,TypeValue\
    \ r){return l>r;}\n};\n"
  code: "/*\n * @title ConvexHullTrickMonotone\n */\ntemplate<class Operator> class\
    \ ConvexHullTrickMonotone {\nprivate:\n\tusing TypeValue = typename Operator::TypeValue;\n\
    \n\t//front->back\u306B\u5411\u304B\u3063\u3066\u50BE\u304D\u304Ca1<a2<...<aN\n\
    \tdeque<pair<TypeValue,TypeValue>> lines;\n\n\t//3\u76F4\u7DDA\u306B\u95A2\u3057\
    \u3066line2\u304C\u5FC5\u8981\u304B\u78BA\u8A8D (\u3053\u306E\u3068\u304D a1 <\
    \ a2 < a3\u304C\u5FC5\u8981=deque\u306E\u9806\u305D\u306E\u307E\u307E)\n\tinline\
    \ int is_required(const pair<TypeValue,TypeValue>& line1, const pair<TypeValue,TypeValue>&\
    \ line2, const pair<TypeValue,TypeValue>& line3) {\n\t\treturn Operator::func_compare((line2.second-line3.second)*(line2.first-line1.first),(line1.second-line2.second)*(line3.first-line2.first));\n\
    \t}\n\n\t//y=ax+b\u306E\u5024\n\tinline TypeValue y(const pair<TypeValue,TypeValue>\
    \ line, TypeValue x) {\n\t\treturn line.first * x + line.second;\n\t}\n\n\tinline\
    \ void insert_back(const pair<TypeValue,TypeValue> line){\n\t\t//\u50BE\u304D\u304C\
    \u540C\u3058\u3068\u304D\n\t\tif(lines.size() && lines.back().first == line.first){\n\
    \t\t\tif(Operator::func_compare(lines.back().second,line.second)) return;\n\t\t\
    \telse lines.pop_back();\n\t\t}\n\t\t//\u4E0D\u5FC5\u8981\u306A\u76F4\u7DDA\u3092\
    \u53D6\u308A\u9664\u304F\n\t\twhile (lines.size() > 1 && !is_required(lines[(int)lines.size()-2],\
    \ lines[(int)lines.size()-1],line)) lines.pop_back();\n\t\t//back\u306Binsert\n\
    \t\tlines.push_back(line);\n\t}\n\tinline void insert_front(const pair<TypeValue,TypeValue>\
    \ line){\n\t\t//\u50BE\u304D\u304C\u540C\u3058\u3068\u304D\n\t\tif(lines.size()\
    \ && lines.front().first == line.first){\n\t\t\tif(Operator::func_compare(lines.front().second,line.second))\
    \ return;\n\t\t\telse lines.pop_front();\n\t\t}\n\t\t//\u4E0D\u5FC5\u8981\u306A\
    \u76F4\u7DDA\u3092\u53D6\u308A\u9664\u304F\n\t\twhile (lines.size() > 1 && !is_required(line,\
    \ lines[0], lines[1])) lines.pop_front();\n\t\t//front\u306Binsert\n\t\tlines.push_front(line);\n\
    \t}\npublic:\n\tConvexHullTrickMonotone() {\n\t\t// do nothing\n\t} \n\tinline\
    \ void insert(const TypeValue a, const TypeValue b) {\n\t\tinsert({a,b});\n\t\
    }\n\t//\u50BE\u304D\u306E\u5927\u304D\u3055\u304C\u5E38\u306B\u6700\u5927or\u6700\
    \u5C0F\u306B\u306A\u308B\u3088\u3046\u306Binsert\u3059\u308B\n\tinline void insert(const\
    \ pair<TypeValue,TypeValue> line) {\n\t\tif(lines.empty() || line.first <= lines.front().first)\
    \ insert_front(line);\n\t\telse if(lines.back().first <= line.first) insert_back(line);\n\
    \t\telse assert(false);\n\t}\n\t//O(log(N))\n\tinline TypeValue get(TypeValue\
    \ x) {\n\t\tif(lines.empty()) return Operator::unit_value;\n\t\tint ng = -1, ok\
    \ = (int)lines.size()-1, md;\n\t\twhile (ok - ng > 1) {\n\t\t\tmd = (ok + ng)\
    \ >> 1;\n\t\t\t( Operator::func_compare(y(lines[md],x),y(lines[md+1],x)) ?ok:ng)=md;\n\
    \t\t}\n\t\treturn y(lines[ok],x);\n\t}\n\t//O(log(N))\n\tinline pair<TypeValue,TypeValue>\
    \ get_line(TypeValue x) {\n\t\tif(lines.empty()) return {0,Operator::unit_value};\n\
    \t\tint ng = -1, ok = (int)lines.size()-1, md;\n\t\twhile (ok - ng > 1) {\n\t\t\
    \tmd = (ok + ng) >> 1;\n\t\t\t( Operator::func_compare(y(lines[md],x),y(lines[md+1],x))\
    \ ?ok:ng)=md;\n\t\t}\n\t\treturn lines[ok];\n\t}\n\t//O(N)\n\tinline void clear(void)\
    \ {\n\t\tlines.clear();\n\t}\n};\n\n//\u6700\u5C0F\u5024\u30AF\u30A8\u30EA\ntemplate<class\
    \ T> struct ValueMin {\n\tusing TypeValue = T;\n\tinline static constexpr TypeValue\
    \ unit_value = 3e18;\n\tinline static constexpr bool func_compare(TypeValue l,TypeValue\
    \ r){return l<r;}\n};\n\n//\u6700\u5927\u5024\u30AF\u30A8\u30EA\ntemplate<class\
    \ T> struct ValueMax {\n\tusing TypeValue = T;\n\tinline static constexpr TypeValue\
    \ unit_value = -3e18;\n\tinline static constexpr bool func_compare(TypeValue l,TypeValue\
    \ r){return l>r;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/geometory/ConvexHullTrickMonotone.cpp
  requiredBy: []
  timestamp: '2020-07-27 03:11:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometory/ConvexHullTrickMonotone-min.test.cpp
  - test/geometory/ConvexHullTrickMonotone-max.test.cpp
documentation_of: lib/geometory/ConvexHullTrickMonotone.cpp
layout: document
redirect_from:
- /library/lib/geometory/ConvexHullTrickMonotone.cpp
- /library/lib/geometory/ConvexHullTrickMonotone.cpp.html
title: ConvexHullTrickMonotone
---
