---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/data-structure/segment-tree/DynamicSegmentTree.md
    document_title: "DynamicSegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u52D5\
      \u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 1 \"lib/data-structure/segment-tree/DynamicSegmentTree.cpp\"\
    \n/*\n * @title DynamicSegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u52D5\
    \u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @docs md/data-structure/segment-tree/DynamicSegmentTree.md\n\
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
    \    }\n};\n"
  code: "/*\n * @title DynamicSegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u52D5\
    \u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @docs md/data-structure/segment-tree/DynamicSegmentTree.md\n\
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
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data-structure/segment-tree/DynamicSegmentTree.cpp
  requiredBy: []
  timestamp: '2021-09-21 03:50:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data-structure/segment-tree/DynamicSegmentTree.cpp
layout: document
redirect_from:
- /library/lib/data-structure/segment-tree/DynamicSegmentTree.cpp
- /library/lib/data-structure/segment-tree/DynamicSegmentTree.cpp.html
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
- DynamicSegmentTree()
  - 単位元`unit_node`で初期化

### メソッド
- void operate(size_t idx, const TypeNode var)
  - `idx`番目のデータに値`var`を作用させる
  - $O(logN)$
  - idx:添字 0-indexed
  - var:値
  - 更新や加算などが乗る
- TypeNode fold(int l, int r)
  - 半開区間`[l,r)`をfoldした値を返す
  - $O(logN)$
  - l,r:添字 0-indexed
  - 総和や最大などが乗る
- void print()
  - デバッグ用