---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"old/SegmentTree2.cpp\"\ntemplate<class Operator> class SegmentTree\
    \ {\n\tusing TypeNode = typename Operator::TypeNode; \n\tsize_t length;\n\tsize_t\
    \ num;\n\tvector<TypeNode> node;\n\tvector<pair<size_t,size_t>> range;\npublic:\n\
    \n\t//unit\u3067\u521D\u671F\u5316\n\tSegmentTree(const size_t num): num(num)\
    \ {\n\t\tfor (length = 1; length < num; length *= 2);\n\t\tnode.resize(2 * length,\
    \ Operator::unit_node);\n\t\trange.resize(2 * length);\n\t\tfor (int i = 0; i\
    \ < length; ++i) range[i+length] = make_pair(i,i+1);\n\t\tfor (int i = length\
    \ - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \t}\n\n\t//vector\u3067\u521D\u671F\u5316\n\tSegmentTree(const vector<TypeNode>\
    \ & vec) : num(vec.size()) {\n\t\tfor (length = 1; length < vec.size(); length\
    \ *= 2);\n\t\tnode.resize(2 * length, Operator::unit_node);\n\t\tfor (int i =\
    \ 0; i < vec.size(); ++i) node[i + length] = vec[i];\n\t\tfor (int i = length\
    \ - 1; i >= 0; --i) node[i] = Operator::funcNode(node[(i<<1)+0],node[(i<<1)+1]);\n\
    \t\trange.resize(2 * length);\n\t\tfor (int i = 0; i < length; ++i) range[i+length]\
    \ = make_pair(i,i+1);\n\t\tfor (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \t}\n \n\t//\u540C\u3058init\u3067\u521D\u671F\u5316\n\tSegmentTree(const size_t\
    \ num, const TypeNode init) : num(num) {\n\t\tfor (length = 1; length < num; length\
    \ *= 2);\n\t\tnode.resize(2 * length, Operator::unit_node);\n\t\trange.resize(2\
    \ * length);\n\t\tfor (int i = 0; i < length; ++i) node[i+length] = init;\n\t\t\
    for (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);\n\t\tfor\
    \ (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \t}\n\t\n\t//[idx,idx+1)\n\tvoid update(size_t idx, const TypeNode var) {\n\t\t\
    if(idx < 0 || length <= idx) return;\n\t\tidx += length;\n\t\tnode[idx] = Operator::funcMerge(node[idx],var);\n\
    \t\twhile(idx >>= 1) node[idx] = Operator::funcNode(node[(idx<<1)+0],node[(idx<<1)+1]);\n\
    \t}\n\n\t//[l,r)\n\tTypeNode get(int l, int r) {\n\t\tif (l < 0 || length <= l\
    \ || r < 0 || length < r) return Operator::unit_node;\n\t\tTypeNode vl = Operator::unit_node,\
    \ vr = Operator::unit_node;\n\t\tfor(l += length, r += length; l < r; l >>=1,\
    \ r >>=1) {\n\t\t\tif(l&1) vl = Operator::funcNode(vl,node[l++]);\n\t\t\tif(r&1)\
    \ vr = Operator::funcNode(node[--r],vr);\n\t\t}\n\t\treturn Operator::funcNode(vl,vr);\n\
    \t}\n\n\t//return [0,length]\n\tint prefixBinarySearch(TypeNode var) {\n\t\tif(!Operator::funcCheck(node[1],var))\
    \ return num;\n\t\tTypeNode ret = Operator::unit_node;\n\t\tsize_t idx = 2;\n\t\
    \tfor(; idx < 2*length; idx<<=1){\n\t\t\tif(!Operator::funcCheck(Operator::funcNode(ret,node[idx]),var))\
    \ {\n\t\t\t\tret = Operator::funcNode(ret,node[idx]);\n\t\t\t\tidx++;\n\t\t\t\
    }\n\t\t}\n\t\treturn min((idx>>1) - length,num);\n\t}\n\n\t//range[l,r) return\
    \ [l,r]\n\tint binarySearch(size_t l, size_t r, TypeNode var) {\n\t\tif (l < 0\
    \ || length <= l || r < 0 || length < r) return -1;\n\t\tTypeNode ret = Operator::unit_node;\n\
    \t\tsize_t off = l;\n\t\tfor(size_t idx = l+length; idx < 2*length && off < r;\
    \ ){\n\t\t\tif(range[idx].second<=r && !Operator::funcCheck(Operator::funcNode(ret,node[idx]),var))\
    \ {\n\t\t\t\tret = Operator::funcNode(ret,node[idx]);\n\t\t\t\toff = range[idx++].second;\n\
    \t\t\t\tif(!(idx&1)) idx >>= 1;\t\t\t\n\t\t\t}\n\t\t\telse{\n\t\t\t\tidx <<=1;\n\
    \t\t\t}\n\t\t}\n\t\treturn off;\n\t}\n};\n\ntemplate<class T> struct nodeGcdPointUpdate\
    \ {\n\tusing TypeNode = T;\n\tinline static constexpr TypeNode unit_node = 0;\n\
    \tinline static constexpr TypeNode funcNode(TypeNode l,TypeNode r){return Gcd::gcd(l,r);}\n\
    \tinline static constexpr TypeNode funcMerge(TypeNode l,TypeNode r){return r;}\n\
    \tinline static constexpr bool funcCheck(TypeNode nodeVal,TypeNode var){return\
    \ var == nodeVal;}\n};\n"
  code: "template<class Operator> class SegmentTree {\n\tusing TypeNode = typename\
    \ Operator::TypeNode; \n\tsize_t length;\n\tsize_t num;\n\tvector<TypeNode> node;\n\
    \tvector<pair<size_t,size_t>> range;\npublic:\n\n\t//unit\u3067\u521D\u671F\u5316\
    \n\tSegmentTree(const size_t num): num(num) {\n\t\tfor (length = 1; length < num;\
    \ length *= 2);\n\t\tnode.resize(2 * length, Operator::unit_node);\n\t\trange.resize(2\
    \ * length);\n\t\tfor (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);\n\
    \t\tfor (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \t}\n\n\t//vector\u3067\u521D\u671F\u5316\n\tSegmentTree(const vector<TypeNode>\
    \ & vec) : num(vec.size()) {\n\t\tfor (length = 1; length < vec.size(); length\
    \ *= 2);\n\t\tnode.resize(2 * length, Operator::unit_node);\n\t\tfor (int i =\
    \ 0; i < vec.size(); ++i) node[i + length] = vec[i];\n\t\tfor (int i = length\
    \ - 1; i >= 0; --i) node[i] = Operator::funcNode(node[(i<<1)+0],node[(i<<1)+1]);\n\
    \t\trange.resize(2 * length);\n\t\tfor (int i = 0; i < length; ++i) range[i+length]\
    \ = make_pair(i,i+1);\n\t\tfor (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \t}\n \n\t//\u540C\u3058init\u3067\u521D\u671F\u5316\n\tSegmentTree(const size_t\
    \ num, const TypeNode init) : num(num) {\n\t\tfor (length = 1; length < num; length\
    \ *= 2);\n\t\tnode.resize(2 * length, Operator::unit_node);\n\t\trange.resize(2\
    \ * length);\n\t\tfor (int i = 0; i < length; ++i) node[i+length] = init;\n\t\t\
    for (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);\n\t\tfor\
    \ (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \t}\n\t\n\t//[idx,idx+1)\n\tvoid update(size_t idx, const TypeNode var) {\n\t\t\
    if(idx < 0 || length <= idx) return;\n\t\tidx += length;\n\t\tnode[idx] = Operator::funcMerge(node[idx],var);\n\
    \t\twhile(idx >>= 1) node[idx] = Operator::funcNode(node[(idx<<1)+0],node[(idx<<1)+1]);\n\
    \t}\n\n\t//[l,r)\n\tTypeNode get(int l, int r) {\n\t\tif (l < 0 || length <= l\
    \ || r < 0 || length < r) return Operator::unit_node;\n\t\tTypeNode vl = Operator::unit_node,\
    \ vr = Operator::unit_node;\n\t\tfor(l += length, r += length; l < r; l >>=1,\
    \ r >>=1) {\n\t\t\tif(l&1) vl = Operator::funcNode(vl,node[l++]);\n\t\t\tif(r&1)\
    \ vr = Operator::funcNode(node[--r],vr);\n\t\t}\n\t\treturn Operator::funcNode(vl,vr);\n\
    \t}\n\n\t//return [0,length]\n\tint prefixBinarySearch(TypeNode var) {\n\t\tif(!Operator::funcCheck(node[1],var))\
    \ return num;\n\t\tTypeNode ret = Operator::unit_node;\n\t\tsize_t idx = 2;\n\t\
    \tfor(; idx < 2*length; idx<<=1){\n\t\t\tif(!Operator::funcCheck(Operator::funcNode(ret,node[idx]),var))\
    \ {\n\t\t\t\tret = Operator::funcNode(ret,node[idx]);\n\t\t\t\tidx++;\n\t\t\t\
    }\n\t\t}\n\t\treturn min((idx>>1) - length,num);\n\t}\n\n\t//range[l,r) return\
    \ [l,r]\n\tint binarySearch(size_t l, size_t r, TypeNode var) {\n\t\tif (l < 0\
    \ || length <= l || r < 0 || length < r) return -1;\n\t\tTypeNode ret = Operator::unit_node;\n\
    \t\tsize_t off = l;\n\t\tfor(size_t idx = l+length; idx < 2*length && off < r;\
    \ ){\n\t\t\tif(range[idx].second<=r && !Operator::funcCheck(Operator::funcNode(ret,node[idx]),var))\
    \ {\n\t\t\t\tret = Operator::funcNode(ret,node[idx]);\n\t\t\t\toff = range[idx++].second;\n\
    \t\t\t\tif(!(idx&1)) idx >>= 1;\t\t\t\n\t\t\t}\n\t\t\telse{\n\t\t\t\tidx <<=1;\n\
    \t\t\t}\n\t\t}\n\t\treturn off;\n\t}\n};\n\ntemplate<class T> struct nodeGcdPointUpdate\
    \ {\n\tusing TypeNode = T;\n\tinline static constexpr TypeNode unit_node = 0;\n\
    \tinline static constexpr TypeNode funcNode(TypeNode l,TypeNode r){return Gcd::gcd(l,r);}\n\
    \tinline static constexpr TypeNode funcMerge(TypeNode l,TypeNode r){return r;}\n\
    \tinline static constexpr bool funcCheck(TypeNode nodeVal,TypeNode var){return\
    \ var == nodeVal;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: old/SegmentTree2.cpp
  requiredBy: []
  timestamp: '2020-04-30 07:30:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/SegmentTree2.cpp
layout: document
redirect_from:
- /library/old/SegmentTree2.cpp
- /library/old/SegmentTree2.cpp.html
title: old/SegmentTree2.cpp
---
