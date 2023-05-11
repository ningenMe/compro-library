---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data-structure/segment-tree/DynamicSegmentTree.cpp
    title: "DynamicSegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u52D5\u7684\u30BB\
      \u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: lib/operator/monoid/MonoidRangeSumPointAdd.cpp
    title: "MonoidRangeSumPointAdd - [\u533A\u9593\u548C, \u4E00\u70B9\u52A0\u7B97\
      ]"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/data-structure/segment-tree/DynamicSegmentTree-rsq-1.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#include\
    \ <vector>\n#include <iostream>\n#include <cassert>\n#include <stack>\nusing namespace\
    \ std;\n#line 1 \"lib/data-structure/segment-tree/DynamicSegmentTree.cpp\"\n/*\n\
    \ * @title DynamicSegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u52D5\u7684\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @docs md/data-structure/segment-tree/DynamicSegmentTree.md\n\
    \ */\ntemplate<class Monoid> class DynamicSegmentTree {\n    using TypeNode =\
    \ typename Monoid::TypeNode;\n    using i64 = long long;\n\n    struct Node{\n\
    \        Node *left, *right;\n        TypeNode val;\n        Node():left(nullptr),right(nullptr),val(Monoid::unit_node)\
    \ {}\n    };\n\n    TypeNode dfs(i64 l,i64 r,i64 nl,i64 nr,Node* node) {\n   \
    \     if(l <= nl && nr <= r) return node->val;\n        if(nr <= l || r <= nl)\
    \ return Monoid::unit_node;\n        TypeNode vl=Monoid::unit_node, vr=Monoid::unit_node;\n\
    \        i64 m = (nl+nr)>>1;\n        if(node->left)  vl = dfs(l,r,nl,m,node->left);\n\
    \        if(node->right) vr = dfs(l,r,m,nr,node->right);\n        return Monoid::func_fold(vl,vr);\n\
    \    }\n\n    i64 length;\n    Node *root;\npublic:\n\n    //unit\u3067\u521D\u671F\
    \u5316\n    DynamicSegmentTree() : length(1) {\n        root = new Node();\n \
    \   }\n\n    //[idx,idx+1)\n    void operate(i64 idx, const TypeNode var) {\n\
    \        if(idx < 0) return;\n        for (;length <= idx; length *= 2) {\n  \
    \          Node *new_root = new Node();\n            TypeNode val = root->val;\n\
    \            new_root->left = root;\n            root = new_root;\n          \
    \  root->val = val;\n        }\n\n        Node *node = root;\n        node->val\
    \ = Monoid::func_operate(node->val,var);\n\n        i64 l = 0, r = length, m;\n\
    \        while(r-l>1) {\n            m = (r+l)>>1;\n            if(idx<m) {\n\
    \                r = m;\n                if(!node->left) node->left=new Node();\n\
    \                node = node->left;\n            }\n            else {\n     \
    \           l = m;\n                if(!node->right) node->right = new Node();\n\
    \                node = node->right;\n            }\n            node->val = Monoid::func_operate(node->val,var);\n\
    \        }\n    }\n\n    //[l,r)\n    TypeNode fold(i64 l, i64 r) {\n        if\
    \ (l < 0 || length <= l || r < 0) return Monoid::unit_node;\n        return dfs(l,r,0,length,root);\n\
    \    }\n};\n#line 1 \"lib/operator/monoid/MonoidRangeSumPointAdd.cpp\"\n/*\n *\
    \ @title MonoidRangeSumPointAdd - [\u533A\u9593\u548C, \u4E00\u70B9\u52A0\u7B97\
    ]\n * @docs md/operator/monoid/MonoidRangeSumPointAdd.md\n */\ntemplate<class\
    \ T> struct MonoidRangeSumPointAdd {\n    using TypeNode = T;\n    inline static\
    \ constexpr TypeNode unit_node = 0;\n    inline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return l+r;}\n    inline static constexpr TypeNode func_operate(TypeNode\
    \ l,TypeNode r){return l+r;}\n    inline static constexpr bool func_check(TypeNode\
    \ nodeVal,TypeNode var){return var == nodeVal;}\n};\n#line 10 \"test/data-structure/segment-tree/DynamicSegmentTree-rsq-1.test.cpp\"\
    \n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    DynamicSegmentTree<MonoidRangeSumPointAdd<long\
    \ long>> dseg;\n    int N,Q; cin >> N >> Q;\n    for(int i=0;i<N;++i) {\n    \
    \    int a; cin >> a;\n        dseg.operate(i,a);\n    }\n    while(Q--) {\n \
    \       int l,r; cin >> l >> r;\n        cout << dseg.fold(l,r) << endl;\n   \
    \ }\n    return 0;\n\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include <vector>\n#include <iostream>\n#include <cassert>\n#include <stack>\n\
    using namespace std;\n#include \"../../../lib/data-structure/segment-tree/DynamicSegmentTree.cpp\"\
    \n#include \"../../../lib/operator/monoid/MonoidRangeSumPointAdd.cpp\"\n\nint\
    \ main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    DynamicSegmentTree<MonoidRangeSumPointAdd<long\
    \ long>> dseg;\n    int N,Q; cin >> N >> Q;\n    for(int i=0;i<N;++i) {\n    \
    \    int a; cin >> a;\n        dseg.operate(i,a);\n    }\n    while(Q--) {\n \
    \       int l,r; cin >> l >> r;\n        cout << dseg.fold(l,r) << endl;\n   \
    \ }\n    return 0;\n\n}"
  dependsOn:
  - lib/data-structure/segment-tree/DynamicSegmentTree.cpp
  - lib/operator/monoid/MonoidRangeSumPointAdd.cpp
  isVerificationFile: true
  path: test/data-structure/segment-tree/DynamicSegmentTree-rsq-1.test.cpp
  requiredBy: []
  timestamp: '2023-05-12 02:44:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/segment-tree/DynamicSegmentTree-rsq-1.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/segment-tree/DynamicSegmentTree-rsq-1.test.cpp
- /verify/test/data-structure/segment-tree/DynamicSegmentTree-rsq-1.test.cpp.html
title: test/data-structure/segment-tree/DynamicSegmentTree-rsq-1.test.cpp
---
