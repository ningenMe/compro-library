---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/segment/SegmentTree.cpp
    title: SegmentTree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"test/segment/SegmentTree-rsq.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\n\n#include\
    \ <vector>\n#include <iostream>\n#include <cassert>\nusing namespace std;\n#line\
    \ 1 \"lib/segment/SegmentTree.cpp\"\n/*\n * @title SegmentTree\n */\ntemplate<class\
    \ Operator> class SegmentTree {\n\tusing TypeNode = typename Operator::TypeNode;\
    \ \n\tsize_t length;\n\tsize_t num;\n\tvector<TypeNode> node;\n\tvector<pair<int,int>>\
    \ range;\n    inline void build() {\n\t\tfor (int i = length - 1; i >= 0; --i)\
    \ node[i] = Operator::func_node(node[(i<<1)+0],node[(i<<1)+1]);\n        range.resize(2\
    \ * length);\n\t\tfor (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);\n\
    \t\tfor (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \    }\npublic:\n\n\t//unit\u3067\u521D\u671F\u5316\n\tSegmentTree(const size_t\
    \ num): num(num) {\n\t\tfor (length = 1; length <= num; length *= 2);\n\t\tnode.resize(2\
    \ * length, Operator::unit_node);\n        build();\n\t}\n\n\t//vector\u3067\u521D\
    \u671F\u5316\n\tSegmentTree(const vector<TypeNode> & vec) : num(vec.size()) {\n\
    \t\tfor (length = 1; length <= vec.size(); length *= 2);\n\t\tnode.resize(2 *\
    \ length, Operator::unit_node);\n\t\tfor (int i = 0; i < vec.size(); ++i) node[i\
    \ + length] = vec[i];\n        build();\n\t}\n \n\t//\u540C\u3058init\u3067\u521D\
    \u671F\u5316\n\tSegmentTree(const size_t num, const TypeNode init) : num(num)\
    \ {\n\t\tfor (length = 1; length <= num; length *= 2);\n\t\tnode.resize(2 * length,\
    \ Operator::unit_node);\n\t\tfor (int i = 0; i < length; ++i) node[i+length] =\
    \ init;\n        build();\n\t}\n\t\n\t//[idx,idx+1)\n\tvoid update(size_t idx,\
    \ const TypeNode var) {\n\t\tif(idx < 0 || length <= idx) return;\n\t\tidx +=\
    \ length;\n\t\tnode[idx] = Operator::func_merge(node[idx],var);\n\t\twhile(idx\
    \ >>= 1) node[idx] = Operator::func_node(node[(idx<<1)+0],node[(idx<<1)+1]);\n\
    \t}\n\n\t//[l,r)\n\tTypeNode get(int l, int r) {\n\t\tif (l < 0 || length <= l\
    \ || r < 0 || length < r) return Operator::unit_node;\n\t\tTypeNode vl = Operator::unit_node,\
    \ vr = Operator::unit_node;\n\t\tfor(l += length, r += length; l < r; l >>=1,\
    \ r >>=1) {\n\t\t\tif(l&1) vl = Operator::func_node(vl,node[l++]);\n\t\t\tif(r&1)\
    \ vr = Operator::func_node(node[--r],vr);\n\t\t}\n\t\treturn Operator::func_node(vl,vr);\n\
    \t}\n\n\t//range[l,r) return [l,r] search max right\n\tint prefix_binary_search(int\
    \ l, int r, TypeNode var) {\n\t\tassert(0 <= l && l < length && 0 < r && r <=\
    \ length);\n\t\tTypeNode ret = Operator::unit_node;\n\t\tsize_t off = l;\n\t\t\
    for(size_t idx = l+length; idx < 2*length && off < r; ){\n\t\t\tif(range[idx].second<=r\
    \ && !Operator::func_check(Operator::func_node(ret,node[idx]),var)) {\n\t\t\t\t\
    ret = Operator::func_node(ret,node[idx]);\n\t\t\t\toff = range[idx++].second;\n\
    \t\t\t\tif(!(idx&1)) idx >>= 1;\t\t\t\n\t\t\t}\n\t\t\telse{\n\t\t\t\tidx <<=1;\n\
    \t\t\t}\n\t\t}\n\t\treturn off;\n\t}\n\n\t//range(l,r] return [l,r] search max\
    \ left\n\tint suffix_binary_search(const int l, const int r, const TypeNode var)\
    \ {\n\t\tassert(-1 <= l && l < (int)length-1 && 0 <= r && r < length);\n\t\tTypeNode\
    \ ret = Operator::unit_node;\n\t\tint off = r;\n\t\tfor(size_t idx = r+length;\
    \ idx < 2*length && l < off; ){\n\t\t\tif(l < range[idx].first && !Operator::func_check(Operator::func_node(node[idx],ret),var))\
    \ {\n\t\t\t\tret = Operator::func_node(node[idx],ret);\n\t\t\t\toff = range[idx--].first-1;\n\
    \t\t\t\tif(idx&1) idx >>= 1;\n\t\t\t}\n\t\t\telse{\n\t\t\t\tidx = (idx<<1)+1;\n\
    \t\t\t}\n\t\t}\n\t\treturn off;\n\t}\n\n\tvoid print(){\n\t\t// cout << \"node\"\
    \ << endl;\n\t\t// for(int i = 1,j = 1; i < 2*length; ++i) {\n\t\t// \tcout <<\
    \ node[i] << \" \";\n\t\t// \tif(i==((1<<j)-1) && ++j) cout << endl;\n\t\t// }\n\
    \t\tcout << \"vector\" << endl;\n\t\tcout << \"{ \" << get(0,1);\n\t\tfor(int\
    \ i = 1; i < length; ++i) cout << \", \" << get(i,i+1);\n\t\tcout << \" }\" <<\
    \ endl;\n\t}\n};\n\n//\u4E00\u70B9\u66F4\u65B0 \u533A\u9593\u6700\u5C0F\ntemplate<class\
    \ T> struct NodeMinPointUpdate {\n\tusing TypeNode = T;\n\tinline static constexpr\
    \ TypeNode unit_node = (1LL<<31)-1;\n\tinline static constexpr TypeNode func_node(TypeNode\
    \ l,TypeNode r){return min(l,r);}\n\tinline static constexpr TypeNode func_merge(TypeNode\
    \ l,TypeNode r){return r;}\n\tinline static constexpr bool func_check(TypeNode\
    \ nodeVal,TypeNode var){return var == nodeVal;}\n};\n\n//\u4E00\u70B9\u52A0\u7B97\
    \ \u533A\u9593\u7DCF\u548C\ntemplate<class T> struct NodeSumPointAdd {\n\tusing\
    \ TypeNode = T;\n\tinline static constexpr TypeNode unit_node = 0;\n\tinline static\
    \ constexpr TypeNode func_node(TypeNode l,TypeNode r){return l+r;}\n\tinline static\
    \ constexpr TypeNode func_merge(TypeNode l,TypeNode r){return l+r;}\n\tinline\
    \ static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var ==\
    \ nodeVal;}\n};\n\n//\u4E00\u6B21\u95A2\u6570\ntemplate<class T> struct NodeCompositePointUpdate\
    \ {\n\tusing TypeNode = T;\n\tinline static constexpr TypeNode unit_node = make_pair(1,0);\n\
    \tinline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return {r.first*l.first,r.first*l.second+r.second};}\n\
    \tinline static constexpr TypeNode func_merge(TypeNode l,TypeNode r){return r;}\n\
    \tinline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return\
    \ var == nodeVal;}\n};\n#line 8 \"test/segment/SegmentTree-rsq.test.cpp\"\n\n\
    int main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\tint N,Q; cin >>\
    \ N >> Q;\n\tSegmentTree<NodeSumPointAdd<long long>> Seg(N,0);\n\twhile(Q--){\n\
    \t\tint q; cin >> q;\n\t\tif(q==0){\n\t\t\tint x,y; cin >> x >> y;\n\t\t\tx--;\n\
    \t\t\tSeg.update(x,y);\n\t\t}\n\t\telse{\n\t\t\tint x,y; cin >> x >> y;\n\t\t\t\
    x--;\n\t\t\tcout << Seg.get(x,y) << endl;\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\nusing namespace\
    \ std;\n#include \"../../lib/segment/SegmentTree.cpp\"\n\nint main(void){\n\t\
    cin.tie(0);ios::sync_with_stdio(false);\n\tint N,Q; cin >> N >> Q;\n\tSegmentTree<NodeSumPointAdd<long\
    \ long>> Seg(N,0);\n\twhile(Q--){\n\t\tint q; cin >> q;\n\t\tif(q==0){\n\t\t\t\
    int x,y; cin >> x >> y;\n\t\t\tx--;\n\t\t\tSeg.update(x,y);\n\t\t}\n\t\telse{\n\
    \t\t\tint x,y; cin >> x >> y;\n\t\t\tx--;\n\t\t\tcout << Seg.get(x,y) << endl;\n\
    \t\t}\n\t}\n}"
  dependsOn:
  - lib/segment/SegmentTree.cpp
  isVerificationFile: true
  path: test/segment/SegmentTree-rsq.test.cpp
  requiredBy: []
  timestamp: '2020-09-12 08:49:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segment/SegmentTree-rsq.test.cpp
layout: document
redirect_from:
- /verify/test/segment/SegmentTree-rsq.test.cpp
- /verify/test/segment/SegmentTree-rsq.test.cpp.html
title: test/segment/SegmentTree-rsq.test.cpp
---
