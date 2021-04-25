---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/segment/DynamicSegmentTree-rsq.test.cpp
    title: test/segment/DynamicSegmentTree-rsq.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/segment/DinamicSegmentTree.md
    document_title: "DinamicSegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u52D5\
      \u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 1 \"lib/segment/DinamicSegmentTree.cpp\"\n/*\n * @title DinamicSegmentTree\
    \ - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728\n * @docs md/segment/DinamicSegmentTree.md\n */\ntemplate<class Operator>\
    \ class DinamicSegmentTree {\n    using TypeNode = typename Operator::TypeNode;\
    \ \n    using i64 = long long;\n\n    struct Node{\n        Node *left, *right;\n\
    \        TypeNode val;\n        i64 l,r;\n        Node(i64 l,i64 r):left(nullptr),right(nullptr),val(Operator::unit_node),l(l),r(r)\
    \ {}\n    };\n    \n    i64 length;\n    Node *root;\n    void print(Node *node)\
    \ {\n        if (node==nullptr) return;\n        print(node->left);\n        cout\
    \ << node->val << \" \";\n        print(node->right);\n    }\npublic:\n\n    //unit\u3067\
    \u521D\u671F\u5316\n    DinamicSegmentTree(const i64 num) {\n        for (length\
    \ = 1; length <= num; length *= 2);\n        root = new Node(0,length);\n    }\n\
    \    ~DinamicSegmentTree() {\n        delete root;\n        root = nullptr;\n\
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
    \            }\n            else if(node->r <= l || r <= node->l) {\n        \
    \        continue;\n            }\n            else {\n                if(node->right)\
    \ st.push(node->right);\n                if(node->left) st.push(node->left);\n\
    \            }\n        }\n        return val;\n    }\n\n    void print() {\n\
    \        cout << \"{\";\n        print(this->root);\n        cout << \"}\" <<\
    \ endl;\n    }\n};\n\n//\u4E00\u70B9\u52A0\u7B97 \u533A\u9593\u7DCF\u548C\ntemplate<class\
    \ T> struct NodeSumPointAdd {\n    using TypeNode = T;\n    inline static constexpr\
    \ TypeNode unit_node = 0;\n    inline static constexpr TypeNode func_node(TypeNode\
    \ l,TypeNode r){return l+r;}\n    inline static constexpr TypeNode func_merge(TypeNode\
    \ l,TypeNode r){return l+r;}\n};\n"
  code: "/*\n * @title DinamicSegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u52D5\
    \u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @docs md/segment/DinamicSegmentTree.md\n\
    \ */\ntemplate<class Operator> class DinamicSegmentTree {\n    using TypeNode\
    \ = typename Operator::TypeNode; \n    using i64 = long long;\n\n    struct Node{\n\
    \        Node *left, *right;\n        TypeNode val;\n        i64 l,r;\n      \
    \  Node(i64 l,i64 r):left(nullptr),right(nullptr),val(Operator::unit_node),l(l),r(r)\
    \ {}\n    };\n    \n    i64 length;\n    Node *root;\n    void print(Node *node)\
    \ {\n        if (node==nullptr) return;\n        print(node->left);\n        cout\
    \ << node->val << \" \";\n        print(node->right);\n    }\npublic:\n\n    //unit\u3067\
    \u521D\u671F\u5316\n    DinamicSegmentTree(const i64 num) {\n        for (length\
    \ = 1; length <= num; length *= 2);\n        root = new Node(0,length);\n    }\n\
    \    ~DinamicSegmentTree() {\n        delete root;\n        root = nullptr;\n\
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
    \            }\n            else if(node->r <= l || r <= node->l) {\n        \
    \        continue;\n            }\n            else {\n                if(node->right)\
    \ st.push(node->right);\n                if(node->left) st.push(node->left);\n\
    \            }\n        }\n        return val;\n    }\n\n    void print() {\n\
    \        cout << \"{\";\n        print(this->root);\n        cout << \"}\" <<\
    \ endl;\n    }\n};\n\n//\u4E00\u70B9\u52A0\u7B97 \u533A\u9593\u7DCF\u548C\ntemplate<class\
    \ T> struct NodeSumPointAdd {\n    using TypeNode = T;\n    inline static constexpr\
    \ TypeNode unit_node = 0;\n    inline static constexpr TypeNode func_node(TypeNode\
    \ l,TypeNode r){return l+r;}\n    inline static constexpr TypeNode func_merge(TypeNode\
    \ l,TypeNode r){return l+r;}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/segment/DinamicSegmentTree.cpp
  requiredBy: []
  timestamp: '2021-04-25 09:10:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segment/DynamicSegmentTree-rsq.test.cpp
documentation_of: lib/segment/DinamicSegmentTree.cpp
layout: document
redirect_from:
- /library/lib/segment/DinamicSegmentTree.cpp
- /library/lib/segment/DinamicSegmentTree.cpp.html
title: "DinamicSegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u52D5\u7684\u30BB\
  \u30B0\u30E1\u30F3\u30C8\u6728"
---
