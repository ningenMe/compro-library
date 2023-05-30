---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/10-segment-tree/SegmentTree.cpp
    title: "SegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u30BB\u30B0\u30E1\u30F3\
      \u30C8\u6728"
  - icon: ':question:'
    path: lib/99-operator/monoid/MonoidRangeSumPointAdd.cpp
    title: "MonoidRangeSumPointAdd - [\u533A\u9593\u548C, \u4E00\u70B9\u52A0\u7B97\
      ]"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"test/segment-tree/SegmentTree-rsq.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\n\n#include\
    \ <vector>\n#include <iostream>\n#include <cassert>\nusing namespace std;\n#line\
    \ 1 \"lib/10-segment-tree/SegmentTree.cpp\"\n/*\n * @title SegmentTree - \u975E\
    \u518D\u5E30\u62BD\u8C61\u5316\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @docs md/segment-tree/SegmentTree.md\n\
    \ */\ntemplate<class Monoid> class SegmentTree {\n    using TypeNode = typename\
    \ Monoid::TypeNode;\n    size_t length;\n    size_t num;\n    vector<TypeNode>\
    \ node;\n    vector<pair<int,int>> range;\n    inline void build() {\n       \
    \ for (int i = length - 1; i >= 0; --i) node[i] = Monoid::func_fold(node[(i<<1)+0],node[(i<<1)+1]);\n\
    \        range.resize(2 * length);\n        for (int i = 0; i < length; ++i) range[i+length]\
    \ = make_pair(i,i+1);\n        for (int i = length - 1; i >= 0; --i) range[i]\
    \ = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n    }\npublic:\n\
    \n    //unit\u3067\u521D\u671F\u5316\n    SegmentTree(const size_t num): num(num)\
    \ {\n        for (length = 1; length <= num; length *= 2);\n        node.resize(2\
    \ * length, Monoid::unit_node);\n        build();\n    }\n\n    //vector\u3067\
    \u521D\u671F\u5316\n    SegmentTree(const vector<TypeNode> & vec) : num(vec.size())\
    \ {\n        for (length = 1; length <= vec.size(); length *= 2);\n        node.resize(2\
    \ * length, Monoid::unit_node);\n        for (int i = 0; i < vec.size(); ++i)\
    \ node[i + length] = vec[i];\n        build();\n    }\n\n    //\u540C\u3058init\u3067\
    \u521D\u671F\u5316\n    SegmentTree(const size_t num, const TypeNode init) : num(num)\
    \ {\n        for (length = 1; length <= num; length *= 2);\n        node.resize(2\
    \ * length, Monoid::unit_node);\n        for (int i = 0; i < length; ++i) node[i+length]\
    \ = init;\n        build();\n    }\n\n    //[idx,idx+1)\n    void operate(size_t\
    \ idx, const TypeNode var) {\n        if(idx < 0 || length <= idx) return;\n \
    \       idx += length;\n        node[idx] = Monoid::func_operate(node[idx],var);\n\
    \        while(idx >>= 1) node[idx] = Monoid::func_fold(node[(idx<<1)+0],node[(idx<<1)+1]);\n\
    \    }\n\n    //[l,r)\n    TypeNode fold(int l, int r) {\n        if (l < 0 ||\
    \ length <= l || r < 0 || length < r) return Monoid::unit_node;\n        TypeNode\
    \ vl = Monoid::unit_node, vr = Monoid::unit_node;\n        for(l += length, r\
    \ += length; l < r; l >>=1, r >>=1) {\n            if(l&1) vl = Monoid::func_fold(vl,node[l++]);\n\
    \            if(r&1) vr = Monoid::func_fold(node[--r],vr);\n        }\n      \
    \  return Monoid::func_fold(vl,vr);\n    }\n\n    //range[l,r) return [l,r] search\
    \ max right\n    int prefix_binary_search(int l, int r, TypeNode var) {\n    \
    \    assert(0 <= l && l < length && 0 < r && r <= length);\n        TypeNode ret\
    \ = Monoid::unit_node;\n        size_t off = l;\n        for(size_t idx = l+length;\
    \ idx < 2*length && off < r; ){\n            if(range[idx].second<=r && !Monoid::func_check(Monoid::func_fold(ret,node[idx]),var))\
    \ {\n                ret = Monoid::func_fold(ret,node[idx]);\n               \
    \ off = range[idx++].second;\n                if(!(idx&1)) idx >>= 1;\n      \
    \      }\n            else{\n                idx <<=1;\n            }\n      \
    \  }\n        return off;\n    }\n\n    //range(l,r] return [l,r] search max left\n\
    \    int suffix_binary_search(const int l, const int r, const TypeNode var) {\n\
    \        assert(-1 <= l && l < (int)length-1 && 0 <= r && r < length);\n     \
    \   TypeNode ret = Monoid::unit_node;\n        int off = r;\n        for(size_t\
    \ idx = r+length; idx < 2*length && l < off; ){\n            if(l < range[idx].first\
    \ && !Monoid::func_check(Monoid::func_fold(node[idx],ret),var)) {\n          \
    \      ret = Monoid::func_fold(node[idx],ret);\n                off = range[idx--].first-1;\n\
    \                if(idx&1) idx >>= 1;\n            }\n            else{\n    \
    \            idx = (idx<<1)+1;\n            }\n        }\n        return off;\n\
    \    }\n\n    void print(){\n        // cout << \"node\" << endl;\n        //\
    \ for(int i = 1,j = 1; i < 2*length; ++i) {\n        // \tcout << node[i] << \"\
    \ \";\n        // \tif(i==((1<<j)-1) && ++j) cout << endl;\n        // }\n   \
    \     cout << \"vector\" << endl;\n        cout << \"{ \" << fold(0,1);\n    \
    \    for(int i = 1; i < length; ++i) cout << \", \" << fold(i,i+1);\n        cout\
    \ << \" }\" << endl;\n    }\n};\n#line 1 \"lib/99-operator/monoid/MonoidRangeSumPointAdd.cpp\"\
    \n/*\n * @title MonoidRangeSumPointAdd - [\u533A\u9593\u548C, \u4E00\u70B9\u52A0\
    \u7B97]\n * @docs md/operator/monoid/MonoidRangeSumPointAdd.md\n */\ntemplate<class\
    \ T> struct MonoidRangeSumPointAdd {\n    using TypeNode = T;\n    inline static\
    \ constexpr TypeNode unit_node = 0;\n    inline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return l+r;}\n    inline static constexpr TypeNode func_operate(TypeNode\
    \ l,TypeNode r){return l+r;}\n    inline static constexpr bool func_check(TypeNode\
    \ nodeVal,TypeNode var){return var == nodeVal;}\n};\n#line 9 \"test/segment-tree/SegmentTree-rsq.test.cpp\"\
    \n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\tint N,Q; cin\
    \ >> N >> Q;\n\tSegmentTree<MonoidRangeSumPointAdd<long long>> Seg(N,0);\n\twhile(Q--){\n\
    \t\tint q; cin >> q;\n\t\tif(q==0){\n\t\t\tint x,y; cin >> x >> y;\n\t\t\tx--;\n\
    \t\t\tSeg.operate(x,y);\n\t\t}\n\t\telse{\n\t\t\tint x,y; cin >> x >> y;\n\t\t\
    \tx--;\n\t\t\tcout << Seg.fold(x,y) << endl;\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\nusing namespace\
    \ std;\n#include \"../../lib/10-segment-tree/SegmentTree.cpp\"\n#include \"../../lib/99-operator/monoid/MonoidRangeSumPointAdd.cpp\"\
    \n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\tint N,Q; cin\
    \ >> N >> Q;\n\tSegmentTree<MonoidRangeSumPointAdd<long long>> Seg(N,0);\n\twhile(Q--){\n\
    \t\tint q; cin >> q;\n\t\tif(q==0){\n\t\t\tint x,y; cin >> x >> y;\n\t\t\tx--;\n\
    \t\t\tSeg.operate(x,y);\n\t\t}\n\t\telse{\n\t\t\tint x,y; cin >> x >> y;\n\t\t\
    \tx--;\n\t\t\tcout << Seg.fold(x,y) << endl;\n\t\t}\n\t}\n}"
  dependsOn:
  - lib/10-segment-tree/SegmentTree.cpp
  - lib/99-operator/monoid/MonoidRangeSumPointAdd.cpp
  isVerificationFile: true
  path: test/segment-tree/SegmentTree-rsq.test.cpp
  requiredBy: []
  timestamp: '2023-05-31 01:48:55+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/segment-tree/SegmentTree-rsq.test.cpp
layout: document
redirect_from:
- /verify/test/segment-tree/SegmentTree-rsq.test.cpp
- /verify/test/segment-tree/SegmentTree-rsq.test.cpp.html
title: test/segment-tree/SegmentTree-rsq.test.cpp
---
