---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/segment/DynamicSegmentTree.cpp
    title: "DynamicSegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u52D5\u7684\u30BB\
      \u30B0\u30E1\u30F3\u30C8\u6728"
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
  bundledCode: "#line 1 \"test/segment/DynamicSegmentTree-rsq-2.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/789\"\n\n#include <vector>\n#include\
    \ <iostream>\n#include <cassert>\n#include <stack>\nusing namespace std;\n#line\
    \ 1 \"lib/segment/DynamicSegmentTree.cpp\"\n/*\n * @title DynamicSegmentTree -\
    \ \u975E\u518D\u5E30\u62BD\u8C61\u5316\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728\n * @docs md/segment/DynamicSegmentTree.md\n */\ntemplate<class Operator>\
    \ class DynamicSegmentTree {\n    using TypeNode = typename Operator::TypeNode;\
    \ \n    using i64 = long long;\n\n    struct Node{\n        Node *left, *right;\n\
    \        TypeNode val;\n        i64 l,r;\n        Node(i64 l,i64 r):left(nullptr),right(nullptr),val(Operator::unit_node),l(l),r(r)\
    \ {}\n    };\n    \n    i64 length;\n    Node *root;\n    void print(Node *node)\
    \ {\n        if (node==nullptr) return;\n        print(node->left);\n        cout\
    \ << node->val << \" \";\n        print(node->right);\n    }\npublic:\n\n    //unit\u3067\
    \u521D\u671F\u5316\n    DynamicSegmentTree(const i64 num) {\n        for (length\
    \ = 1; length <= num; length *= 2);\n        root = new Node(0,length);\n    }\n\
    \    ~DynamicSegmentTree() {\n        delete root;\n        root = nullptr;\n\
    \    }\n    \n    //[idx,idx+1)\n    void update(i64 idx, const TypeNode var)\
    \ {\n        if(idx < 0 || length <= idx) return;\n        Node *node = root;\n\
    \        node->val = Operator::func_merge(node->val,var);\n\n        i64 l = 0,\
    \ r = length, m;\n        while(r-l>1) {\n            m = (r+l)>>1;\n        \
    \    if(idx<m) {\n                r = m;\n                if(!node->left) node->left=new\
    \ Node(l,r);\n                node = node->left;\n            }\n            else\
    \ {\n                l = m;\n                if(!node->right) node->right = new\
    \ Node(l,r);\n                node = node->right;\n            }\n           \
    \ node->val = Operator::func_merge(node->val,var);\n        }\n    }\n\n    //[l,r)\n\
    \    TypeNode get(i64 l, i64 r) {\n        if (l < 0 || length <= l || r < 0 ||\
    \ length < r) return Operator::unit_node;\n        TypeNode val = Operator::unit_node;\n\
    \        stack<Node*> st;\n        st.push(root);\n        while(st.size()) {\n\
    \            Node *node = st.top(); st.pop();\n            if(l <= node->l &&\
    \ node->r <= r) {\n                val = Operator::func_node(val,node->val);\n\
    \            }\n            else if(!(node->r <= l) && !(r <= node->l)) {\n  \
    \              if(node->right) st.push(node->right);\n                if(node->left)\
    \ st.push(node->left);\n            }\n        }\n        return val;\n    }\n\
    \n    void print() {\n        cout << \"{\";\n        print(this->root);\n   \
    \     cout << \"}\" << endl;\n    }\n};\n\n//\u4E00\u70B9\u52A0\u7B97 \u533A\u9593\
    \u7DCF\u548C\ntemplate<class T> struct NodeSumPointAdd {\n    using TypeNode =\
    \ T;\n    inline static constexpr TypeNode unit_node = 0;\n    inline static constexpr\
    \ TypeNode func_node(TypeNode l,TypeNode r){return l+r;}\n    inline static constexpr\
    \ TypeNode func_merge(TypeNode l,TypeNode r){return l+r;}\n};\n#line 9 \"test/segment/DynamicSegmentTree-rsq-2.test.cpp\"\
    \n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    DynamicSegmentTree<NodeSumPointAdd<long\
    \ long>> seg(1000000010);\n    int N; cin >> N;\n    long long ans = 0;\n    while(N--)\
    \ {\n        int q,l,r; cin >> q >> l >> r;\n        if(q==0) seg.update(l,r);\n\
    \        else ans += seg.get(l,r+1);\n    }\n    cout << ans << endl;\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/789\"\n\n#include <vector>\n\
    #include <iostream>\n#include <cassert>\n#include <stack>\nusing namespace std;\n\
    #include \"../../lib/segment/DynamicSegmentTree.cpp\"\n\nint main(void){\n   \
    \ cin.tie(0);ios::sync_with_stdio(false);\n    DynamicSegmentTree<NodeSumPointAdd<long\
    \ long>> seg(1000000010);\n    int N; cin >> N;\n    long long ans = 0;\n    while(N--)\
    \ {\n        int q,l,r; cin >> q >> l >> r;\n        if(q==0) seg.update(l,r);\n\
    \        else ans += seg.get(l,r+1);\n    }\n    cout << ans << endl;\n    return\
    \ 0;\n}"
  dependsOn:
  - lib/segment/DynamicSegmentTree.cpp
  isVerificationFile: true
  path: test/segment/DynamicSegmentTree-rsq-2.test.cpp
  requiredBy: []
  timestamp: '2021-04-25 13:58:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segment/DynamicSegmentTree-rsq-2.test.cpp
layout: document
redirect_from:
- /verify/test/segment/DynamicSegmentTree-rsq-2.test.cpp
- /verify/test/segment/DynamicSegmentTree-rsq-2.test.cpp.html
title: test/segment/DynamicSegmentTree-rsq-2.test.cpp
---
