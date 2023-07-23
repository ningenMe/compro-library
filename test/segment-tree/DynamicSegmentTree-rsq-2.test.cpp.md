---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/10-segment-tree/DynamicSegmentTree.cpp
    title: "DynamicSegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u52D5\u7684\u30BB\
      \u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: lib/99-operator/monoid/MonoidRangeSumPointAdd.cpp
    title: "MonoidRangeSumPointAdd - [\u533A\u9593\u548C, \u4E00\u70B9\u52A0\u7B97\
      ]"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/789
    links:
    - https://yukicoder.me/problems/no/789
  bundledCode: "#line 1 \"test/segment-tree/DynamicSegmentTree-rsq-2.test.cpp\"\n\
    #define PROBLEM \"https://yukicoder.me/problems/no/789\"\n\n#include <vector>\n\
    #include <iostream>\n#include <cassert>\n#include <stack>\nusing namespace std;\n\
    #line 1 \"lib/10-segment-tree/DynamicSegmentTree.cpp\"\n/*\n * @title DynamicSegmentTree\
    \ - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728\n * @docs md/segment-tree/DynamicSegmentTree.md\n */\ntemplate<class Monoid>\
    \ class DynamicSegmentTree {\n    using TypeNode = typename Monoid::TypeNode;\n\
    \    using i64 = long long;\n\n    struct Node{\n        Node *left, *right;\n\
    \        TypeNode val;\n        Node():left(nullptr),right(nullptr),val(Monoid::unit_node)\
    \ {}\n    };\n\n    TypeNode dfs(i64 l,i64 r,i64 nl,i64 nr,Node* node) {\n   \
    \     if(l <= nl && nr <= r) return node->val;\n        if(nr <= l || r <= nl)\
    \ return Monoid::unit_node;\n        TypeNode vl=Monoid::unit_node, vr=Monoid::unit_node;\n\
    \        i64 m = (nl+nr)>>1;\n        if(node->left)  vl = dfs(l,r,nl,m,node->left);\n\
    \        if(node->right) vr = dfs(l,r,m,nr,node->right);\n        return Monoid::func_fold(vl,vr);\n\
    \    }\n\n    i64 length;\n    Node *root;\npublic:\n    //unit\u3067\u521D\u671F\
    \u5316\n    DynamicSegmentTree() : length(1) {\n        root = new Node();\n \
    \   }\n    //[idx,idx+1)\n    void operate(i64 idx, const TypeNode val) {\n  \
    \      if(idx < 0) return;\n        for (;length <= idx; length *= 2) {\n    \
    \        Node *new_root = new Node();\n            TypeNode val = root->val;\n\
    \            new_root->left = root;\n            root = new_root;\n          \
    \  root->val = val;\n        }\n        Node* node = root;\n        i64 l = 0,\
    \ r = length, m;\n\t\tstack<Node*> st;\n\n        while(r-l>1) {\n\t\t\tst.push(node);\n\
    \            m = (r+l)>>1;\n            if(idx<m) {\n                r = m;\n\
    \                if(!node->left) node->left=new Node();\n                node\
    \ = node->left;\n            }\n            else {\n                l = m;\n \
    \               if(!node->right) node->right = new Node();\n                node\
    \ = node->right;\n            }\n        }\n        node->val = Monoid::func_operate(node->val,val);\n\
    \t\twhile(st.size()) {\n\t\t\tnode = st.top(); st.pop();\n\t\t\tTypeNode vl=Monoid::unit_node,\
    \ vr=Monoid::unit_node;\n\t\t\tif(node->left)  vl = node->left->val;\n\t\t\tif(node->right)\
    \ vr = node->right->val;\n\t\t\tnode->val = Monoid::func_fold(vl,vr);\n\t\t}\n\
    \    }\n\n    //[l,r)\n    TypeNode fold(i64 l, i64 r) {\n        if (l < 0 ||\
    \ length <= l || r < 0) return Monoid::unit_node;\n        return dfs(l,r,0,length,root);\n\
    \    }\n};\n#line 1 \"lib/99-operator/monoid/MonoidRangeSumPointAdd.cpp\"\n/*\n\
    \ * @title MonoidRangeSumPointAdd - [\u533A\u9593\u548C, \u4E00\u70B9\u52A0\u7B97\
    ]\n * @docs md/operator/monoid/MonoidRangeSumPointAdd.md\n */\ntemplate<class\
    \ T> struct MonoidRangeSumPointAdd {\n    using TypeNode = T;\n    inline static\
    \ constexpr TypeNode unit_node = 0;\n    inline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return l+r;}\n    inline static constexpr TypeNode func_operate(TypeNode\
    \ l,TypeNode r){return l+r;}\n    inline static constexpr bool func_check(TypeNode\
    \ nodeVal,TypeNode var){return var == nodeVal;}\n};\n#line 10 \"test/segment-tree/DynamicSegmentTree-rsq-2.test.cpp\"\
    \n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    DynamicSegmentTree<MonoidRangeSumPointAdd<long\
    \ long>> seg;\n    int N; cin >> N;\n    long long ans = 0;\n    while(N--) {\n\
    \        int q,l,r; cin >> q >> l >> r;\n        if(q==0) seg.operate(l,r);\n\
    \        else ans += seg.fold(l,r+1);\n    }\n    cout << ans << endl;\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/789\"\n\n#include <vector>\n\
    #include <iostream>\n#include <cassert>\n#include <stack>\nusing namespace std;\n\
    #include \"../../lib/10-segment-tree/DynamicSegmentTree.cpp\"\n#include \"../../lib/99-operator/monoid/MonoidRangeSumPointAdd.cpp\"\
    \n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    DynamicSegmentTree<MonoidRangeSumPointAdd<long\
    \ long>> seg;\n    int N; cin >> N;\n    long long ans = 0;\n    while(N--) {\n\
    \        int q,l,r; cin >> q >> l >> r;\n        if(q==0) seg.operate(l,r);\n\
    \        else ans += seg.fold(l,r+1);\n    }\n    cout << ans << endl;\n    return\
    \ 0;\n}"
  dependsOn:
  - lib/10-segment-tree/DynamicSegmentTree.cpp
  - lib/99-operator/monoid/MonoidRangeSumPointAdd.cpp
  isVerificationFile: true
  path: test/segment-tree/DynamicSegmentTree-rsq-2.test.cpp
  requiredBy: []
  timestamp: '2023-07-02 23:40:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segment-tree/DynamicSegmentTree-rsq-2.test.cpp
layout: document
redirect_from:
- /verify/test/segment-tree/DynamicSegmentTree-rsq-2.test.cpp
- /verify/test/segment-tree/DynamicSegmentTree-rsq-2.test.cpp.html
title: test/segment-tree/DynamicSegmentTree-rsq-2.test.cpp
---