---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"old/SegmentTree.cpp\"\ntemplate<class Operator> class SegmentTree\
    \ {\n\tOperator Op;                            \n\tusing typeNode = decltype(Op.unitNode);\
    \ \n\tsize_t length;\n\tsize_t num;\n\tvector<typeNode> node;\n\tvector<pair<size_t,size_t>>\
    \ range;\npublic:\n\n\t//unit\u3067\u521D\u671F\u5316\n\tSegmentTree(const size_t\
    \ num): num(num) {\n\t\tfor (length = 1; length < num; length *= 2);\n\t\tnode.resize(2\
    \ * length, Op.unitNode);\n\t\trange.resize(2 * length);\n\t\tfor (int i = 0;\
    \ i < length; ++i) range[i+length] = make_pair(i,i+1);\n\t\tfor (int i = length\
    \ - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \t}\n\n\t//vector\u3067\u521D\u671F\u5316\n\tSegmentTree(const vector<typeNode>\
    \ & vec) : num(vec.size()) {\n\t\tfor (length = 1; length < vec.size(); length\
    \ *= 2);\n\t\tnode.resize(2 * length, Op.unitNode);\n\t\tfor (int i = 0; i < vec.size();\
    \ ++i) node[i + length] = vec[i];\n\t\tfor (int i = length - 1; i >= 0; --i) node[i]\
    \ = Op.funcNode(node[(i<<1)+0],node[(i<<1)+1]);\n\t\trange.resize(2 * length);\n\
    \t\tfor (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);\n\t\t\
    for (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \t}\n \n\t//\u540C\u3058init\u3067\u521D\u671F\u5316\n\tSegmentTree(const size_t\
    \ num, const typeNode init) : num(num) {\n\t\tfor (length = 1; length < num; length\
    \ *= 2);\n\t\tnode.resize(2 * length, init);\n\t\trange.resize(2 * length);\n\t\
    \tfor (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);\n\t\tfor\
    \ (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \t}\n\t\n\t//[idx,idx+1)\n\tvoid update(size_t idx, const typeNode var) {\n\t\t\
    if(idx < 0 || length <= idx) return;\n\t\tidx += length;\n\t\tnode[idx] = Op.funcMerge(node[idx],var);\n\
    \t\twhile(idx >>= 1) node[idx] = Op.funcNode(node[(idx<<1)+0],node[(idx<<1)+1]);\n\
    \t}\n\n\t//[l,r)\n\ttypeNode get(int l, int r) {\n\t\tif (l < 0 || length <= l\
    \ || r < 0 || length < r) return Op.unitNode;\n\t\ttypeNode vl = Op.unitNode,\
    \ vr = Op.unitNode;\n\t\tfor(l += length, r += length; l < r; l >>=1, r >>=1)\
    \ {\n\t\t\tif(l&1) vl = Op.funcNode(vl,node[l++]);\n\t\t\tif(r&1) vr = Op.funcNode(node[--r],vr);\n\
    \t\t}\n\t\treturn Op.funcNode(vl,vr);\n\t}\n\n\t//return [0,length]\n\tint PrefixBinarySearch(typeNode\
    \ var) {\n\t\tif(!Op.funcCheck(node[1],var)) return num;\n\t\ttypeNode ret = Op.unitNode;\n\
    \t\tsize_t idx = 2;\n\t\tfor(; idx < 2*length; idx<<=1){\n\t\t\tif(!Op.funcCheck(Op.funcNode(ret,node[idx]),var))\
    \ {\n\t\t\t\tret = Op.funcNode(ret,node[idx]);\n\t\t\t\tidx++;\n\t\t\t}\n\t\t\
    }\n\t\treturn min((idx>>1) - length,num);\n\t}\n\n\t//range[l,r) return [l,r]\n\
    \tint BinarySearch(size_t l, size_t r, typeNode var) {\n\t\tif (l < 0 || length\
    \ <= l || r < 0 || length < r) return -1;\n\t\ttypeNode ret = Op.unitNode;\n\t\
    \tsize_t off = l;\n\t\tfor(size_t idx = l+length; idx < 2*length && off < r; ){\n\
    \t\t\tif(range[idx].second<=r && !Op.funcCheck(Op.funcNode(ret,node[idx]),var))\
    \ {\n\t\t\t\tret = Op.funcNode(ret,node[idx]);\n\t\t\t\toff = range[idx++].second;\n\
    \t\t\t\tif(!(idx&1)) idx >>= 1;\t\t\t\n\t\t\t}\n\t\t\telse{\n\t\t\t\tidx <<=1;\n\
    \t\t\t}\n\t\t}\n\t\treturn off;\n\t}\n\n\tvoid print(){\n\t\tcout << \"{ \" <<\
    \ get(0,1);\n\t\tfor(int i = 1; i < length; ++i) cout << \", \" << get(i,i+1);\n\
    \t\tcout << \" }\" << endl;\n\n\t\t// for(int i = 1,j = 1; i < 2*length; ++i)\
    \ {\n\t\t// \tcout << node[i] << \" \";\n\t\t// \tif(i==((1<<j)-1) && ++j) cout\
    \ << endl;\n\t\t// }\n\t}\n\n};\n\n//\u4E00\u70B9\u52A0\u7B97 \u533A\u9593\u6700\
    \u5927\ntemplate<class typeNode> struct nodeMaxPointAdd {\n\ttypeNode unitNode\
    \ = 0;\n\ttypeNode funcNode(typeNode l,typeNode r){return max(l,r);}\n\ttypeNode\
    \ funcMerge(typeNode l,typeNode r){return l+r;}\n};\n\n//\u4E00\u70B9\u52A0\u7B97\
    \ \u533A\u9593\u7DCF\u548C\ntemplate<class typeNode> struct nodeSumPointAdd {\n\
    \ttypeNode unitNode = 0;\n\ttypeNode funcNode(typeNode l,typeNode r){return l+r;}\n\
    \ttypeNode funcMerge(typeNode l,typeNode r){return l+r;}\n\t// Binary Search for\
    \ first index at where funcCheck is true\n\tbool funcCheck(typeNode nodeVal,typeNode\
    \ var){return var <= nodeVal;}\n};\n\n//\u4E00\u70B9\u66F4\u65B0 \u533A\u9593\u6700\
    \u5C0F\ntemplate<class typeNode> struct nodeMinPointUpdate {\n\ttypeNode unitNode\
    \ = (1LL<<31)-1;\n\ttypeNode funcNode(typeNode l,typeNode r){return min(l,r);}\n\
    \ttypeNode funcMerge(typeNode l,typeNode r){return r;}\n};\n\n//\u4E00\u70B9\u66F4\
    \u65B0 \u533A\u9593GCD\ntemplate<class typeNode> struct nodeGCDPointUpdate {\n\
    \ttypeNode unitNode = 0;\n\ttypeNode funcNode(typeNode l,typeNode r){return ((r\
    \ == 0) ? l : funcNode(r, l % r));}\n\ttypeNode funcMerge(typeNode l,typeNode\
    \ r){return r;}\n\t// Binary Search for first index at where funcCheck is true\n\
    \tbool funcCheck(typeNode nodeVal,typeNode var){return var == nodeVal;}\n};\n"
  code: "template<class Operator> class SegmentTree {\n\tOperator Op;            \
    \                \n\tusing typeNode = decltype(Op.unitNode); \n\tsize_t length;\n\
    \tsize_t num;\n\tvector<typeNode> node;\n\tvector<pair<size_t,size_t>> range;\n\
    public:\n\n\t//unit\u3067\u521D\u671F\u5316\n\tSegmentTree(const size_t num):\
    \ num(num) {\n\t\tfor (length = 1; length < num; length *= 2);\n\t\tnode.resize(2\
    \ * length, Op.unitNode);\n\t\trange.resize(2 * length);\n\t\tfor (int i = 0;\
    \ i < length; ++i) range[i+length] = make_pair(i,i+1);\n\t\tfor (int i = length\
    \ - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \t}\n\n\t//vector\u3067\u521D\u671F\u5316\n\tSegmentTree(const vector<typeNode>\
    \ & vec) : num(vec.size()) {\n\t\tfor (length = 1; length < vec.size(); length\
    \ *= 2);\n\t\tnode.resize(2 * length, Op.unitNode);\n\t\tfor (int i = 0; i < vec.size();\
    \ ++i) node[i + length] = vec[i];\n\t\tfor (int i = length - 1; i >= 0; --i) node[i]\
    \ = Op.funcNode(node[(i<<1)+0],node[(i<<1)+1]);\n\t\trange.resize(2 * length);\n\
    \t\tfor (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);\n\t\t\
    for (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \t}\n \n\t//\u540C\u3058init\u3067\u521D\u671F\u5316\n\tSegmentTree(const size_t\
    \ num, const typeNode init) : num(num) {\n\t\tfor (length = 1; length < num; length\
    \ *= 2);\n\t\tnode.resize(2 * length, init);\n\t\trange.resize(2 * length);\n\t\
    \tfor (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);\n\t\tfor\
    \ (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \t}\n\t\n\t//[idx,idx+1)\n\tvoid update(size_t idx, const typeNode var) {\n\t\t\
    if(idx < 0 || length <= idx) return;\n\t\tidx += length;\n\t\tnode[idx] = Op.funcMerge(node[idx],var);\n\
    \t\twhile(idx >>= 1) node[idx] = Op.funcNode(node[(idx<<1)+0],node[(idx<<1)+1]);\n\
    \t}\n\n\t//[l,r)\n\ttypeNode get(int l, int r) {\n\t\tif (l < 0 || length <= l\
    \ || r < 0 || length < r) return Op.unitNode;\n\t\ttypeNode vl = Op.unitNode,\
    \ vr = Op.unitNode;\n\t\tfor(l += length, r += length; l < r; l >>=1, r >>=1)\
    \ {\n\t\t\tif(l&1) vl = Op.funcNode(vl,node[l++]);\n\t\t\tif(r&1) vr = Op.funcNode(node[--r],vr);\n\
    \t\t}\n\t\treturn Op.funcNode(vl,vr);\n\t}\n\n\t//return [0,length]\n\tint PrefixBinarySearch(typeNode\
    \ var) {\n\t\tif(!Op.funcCheck(node[1],var)) return num;\n\t\ttypeNode ret = Op.unitNode;\n\
    \t\tsize_t idx = 2;\n\t\tfor(; idx < 2*length; idx<<=1){\n\t\t\tif(!Op.funcCheck(Op.funcNode(ret,node[idx]),var))\
    \ {\n\t\t\t\tret = Op.funcNode(ret,node[idx]);\n\t\t\t\tidx++;\n\t\t\t}\n\t\t\
    }\n\t\treturn min((idx>>1) - length,num);\n\t}\n\n\t//range[l,r) return [l,r]\n\
    \tint BinarySearch(size_t l, size_t r, typeNode var) {\n\t\tif (l < 0 || length\
    \ <= l || r < 0 || length < r) return -1;\n\t\ttypeNode ret = Op.unitNode;\n\t\
    \tsize_t off = l;\n\t\tfor(size_t idx = l+length; idx < 2*length && off < r; ){\n\
    \t\t\tif(range[idx].second<=r && !Op.funcCheck(Op.funcNode(ret,node[idx]),var))\
    \ {\n\t\t\t\tret = Op.funcNode(ret,node[idx]);\n\t\t\t\toff = range[idx++].second;\n\
    \t\t\t\tif(!(idx&1)) idx >>= 1;\t\t\t\n\t\t\t}\n\t\t\telse{\n\t\t\t\tidx <<=1;\n\
    \t\t\t}\n\t\t}\n\t\treturn off;\n\t}\n\n\tvoid print(){\n\t\tcout << \"{ \" <<\
    \ get(0,1);\n\t\tfor(int i = 1; i < length; ++i) cout << \", \" << get(i,i+1);\n\
    \t\tcout << \" }\" << endl;\n\n\t\t// for(int i = 1,j = 1; i < 2*length; ++i)\
    \ {\n\t\t// \tcout << node[i] << \" \";\n\t\t// \tif(i==((1<<j)-1) && ++j) cout\
    \ << endl;\n\t\t// }\n\t}\n\n};\n\n//\u4E00\u70B9\u52A0\u7B97 \u533A\u9593\u6700\
    \u5927\ntemplate<class typeNode> struct nodeMaxPointAdd {\n\ttypeNode unitNode\
    \ = 0;\n\ttypeNode funcNode(typeNode l,typeNode r){return max(l,r);}\n\ttypeNode\
    \ funcMerge(typeNode l,typeNode r){return l+r;}\n};\n\n//\u4E00\u70B9\u52A0\u7B97\
    \ \u533A\u9593\u7DCF\u548C\ntemplate<class typeNode> struct nodeSumPointAdd {\n\
    \ttypeNode unitNode = 0;\n\ttypeNode funcNode(typeNode l,typeNode r){return l+r;}\n\
    \ttypeNode funcMerge(typeNode l,typeNode r){return l+r;}\n\t// Binary Search for\
    \ first index at where funcCheck is true\n\tbool funcCheck(typeNode nodeVal,typeNode\
    \ var){return var <= nodeVal;}\n};\n\n//\u4E00\u70B9\u66F4\u65B0 \u533A\u9593\u6700\
    \u5C0F\ntemplate<class typeNode> struct nodeMinPointUpdate {\n\ttypeNode unitNode\
    \ = (1LL<<31)-1;\n\ttypeNode funcNode(typeNode l,typeNode r){return min(l,r);}\n\
    \ttypeNode funcMerge(typeNode l,typeNode r){return r;}\n};\n\n//\u4E00\u70B9\u66F4\
    \u65B0 \u533A\u9593GCD\ntemplate<class typeNode> struct nodeGCDPointUpdate {\n\
    \ttypeNode unitNode = 0;\n\ttypeNode funcNode(typeNode l,typeNode r){return ((r\
    \ == 0) ? l : funcNode(r, l % r));}\n\ttypeNode funcMerge(typeNode l,typeNode\
    \ r){return r;}\n\t// Binary Search for first index at where funcCheck is true\n\
    \tbool funcCheck(typeNode nodeVal,typeNode var){return var == nodeVal;}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: old/SegmentTree.cpp
  requiredBy: []
  timestamp: '2020-04-30 07:30:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/SegmentTree.cpp
layout: document
redirect_from:
- /library/old/SegmentTree.cpp
- /library/old/SegmentTree.cpp.html
title: old/SegmentTree.cpp
---
