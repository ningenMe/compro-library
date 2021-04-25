---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/segment/DynamicSegmentTree-rsq-1.test.cpp
    title: test/segment/DynamicSegmentTree-rsq-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment/DynamicSegmentTree-rsq-2.test.cpp
    title: test/segment/DynamicSegmentTree-rsq-2.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/segment/DynamicSegmentTree.md
    document_title: "DynamicSegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u52D5\
      \u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 1 \"lib/segment/DynamicSegmentTree.cpp\"\n/*\n * @title DynamicSegmentTree\
    \ - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\
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
    \ TypeNode func_merge(TypeNode l,TypeNode r){return l+r;}\n};\n"
  code: "/*\n * @title DynamicSegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u52D5\
    \u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @docs md/segment/DynamicSegmentTree.md\n\
    \ */\ntemplate<class Operator> class DynamicSegmentTree {\n    using TypeNode\
    \ = typename Operator::TypeNode; \n    using i64 = long long;\n\n    struct Node{\n\
    \        Node *left, *right;\n        TypeNode val;\n        i64 l,r;\n      \
    \  Node(i64 l,i64 r):left(nullptr),right(nullptr),val(Operator::unit_node),l(l),r(r)\
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
    \ TypeNode func_merge(TypeNode l,TypeNode r){return l+r;}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/segment/DynamicSegmentTree.cpp
  requiredBy: []
  timestamp: '2021-04-25 09:38:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segment/DynamicSegmentTree-rsq-1.test.cpp
  - test/segment/DynamicSegmentTree-rsq-2.test.cpp
documentation_of: lib/segment/DynamicSegmentTree.cpp
layout: document
redirect_from:
- /library/lib/segment/DynamicSegmentTree.cpp
- /library/lib/segment/DynamicSegmentTree.cpp.html
title: "DynamicSegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u52D5\u7684\u30BB\
  \u30B0\u30E1\u30F3\u30C8\u6728"
---
### DynamicSegmentTree
- 非再帰抽象化動的セグメント木
- ポインタベースで、必要な部分だけ作成するセグメント木
  - 普通のセグ木と違って、区間の幅を1e9で持ったり出来る
- 0-indexed
- モノイドのクラスをテンプレートで渡す必要がある
  - 下記が一例
```
//一点加算 区間総和
template<class T> struct NodeSumPointAdd {
	using TypeNode = T;
	inline static constexpr TypeNode unit_node = 0;
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return l+r;}
	inline static constexpr TypeNode func_merge(TypeNode l,TypeNode r){return l+r;}
};
```
- モノイドのクラスは、get,updateに対する演算と単位元を必要とする。

### コンストラクタ
- DynamicSegmentTree(const size_t num)
  - 単位元`unit_node`で初期化
  - $O(N)$
  - num:要素数(この大きさが、クエリの区間より大きくないといけない)

### メソッド
- void update(size_t idx, const TypeNode var)
  - `idx`番目のデータに値`var`を与える
  - $O(logN)$
  - idx:添字 0-indexed
  - var:値
  - 更新や加算などが乗る
- TypeNode get(int l, int r)
  - 半開区間`[l,r)`をfoldした値を返す
  - $O(logN)$
  - l,r:添字 0-indexed
  - 総和や最大などが乗る
- void print()
  - デバッグ用