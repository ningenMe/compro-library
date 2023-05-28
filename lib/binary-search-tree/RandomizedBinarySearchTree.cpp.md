---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/binary-search-tree/RandomizedBinarySearchTree-get.test.cpp
    title: test/binary-search-tree/RandomizedBinarySearchTree-get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/binary-search-tree/RandomizedBinarySearchTree-med.test.cpp
    title: test/binary-search-tree/RandomizedBinarySearchTree-med.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/binary-search-tree/RandomizedBinarySearchTree-pair.test.cpp
    title: test/binary-search-tree/RandomizedBinarySearchTree-pair.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/binary-search-tree/RandomizedBinarySearchTree.md
    document_title: "RandomizedBinarySearchTree - \u5E73\u8861\u4E8C\u5206\u63A2\u7D22\
      \u6728"
    links: []
  bundledCode: "#line 1 \"lib/binary-search-tree/RandomizedBinarySearchTree.cpp\"\n\
    /*\n * @title RandomizedBinarySearchTree - \u5E73\u8861\u4E8C\u5206\u63A2\u7D22\
    \u6728\n * @docs md/binary-search-tree/RandomizedBinarySearchTree.md\n */\ntemplate<class\
    \ Monoid> class RandomizedBinarySearchTree {\n    using TypeNode = typename Monoid::TypeNode;\n\
    \    unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;\n\
    \    unsigned int xor_shift() {\n        unsigned int t = (x ^ (x << 11)); x =\
    \ y; y = z; z = w;\n        return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));\n \
    \   }\n    struct Node {\n    private:\n        void build() {left = right = nullptr;size\
    \ = 1;}\n    public:\n        Node *left, *right;\n        TypeNode value, range_value;\n\
    \        int size;\n        Node() : value(Monoid::unit_node), range_value(Monoid::unit_node)\
    \ {build();}\n        Node(TypeNode v) : value(v), range_value(v) {build();}\n\
    \        friend ostream &operator<<(ostream &os, const Node* node) {return os\
    \ << \"{\" << node->value << \", \" << node->range_value << \", \" << node->size\
    \ << \"}\";}\n    };\n    Node* root;\n    inline int size(Node *node) {return\
    \ node==nullptr ? 0 : node->size;}\n    inline TypeNode range_value(Node *node)\
    \ {return node==nullptr ? Monoid::unit_node : node->range_value;}\n    inline\
    \ TypeNode get(Node *node, size_t k) {\n        if (node==nullptr) return Monoid::unit_node;\n\
    \        if (k == size(node->left)) return node->value;\n        if (k < size(node->left))\
    \ return get(node->left, k);\n        else return get(node->right, k-1 - size(node->left));\n\
    \    }\n    inline Node* update(Node *node) {\n        node->size = size(node->left)\
    \ + size(node->right) + 1;\n        node->range_value = Monoid::func_fold(Monoid::func_fold(range_value(node->left),node->value),range_value(node->right));\n\
    \        return node;\n    }\n    inline Node* merge_impl(Node *left, Node *right)\
    \ {\n        if (left==nullptr)  return right;\n        if (right==nullptr) return\
    \ left;\n        if (xor_shift() % (left->size + right->size) < left->size) {\n\
    \            left->right = merge_impl(left->right, right);\n            return\
    \ update(left);\n        }\n        else {\n            right->left = merge_impl(left,\
    \ right->left);\n            return update(right);\n        }\n    }\n    inline\
    \ pair<Node*, Node*> split_impl(Node* node, int k) {\n        if (node==nullptr)\
    \ return make_pair(nullptr, nullptr);\n        if (k <= size(node->left)) {\n\
    \            pair<Node*, Node*> sub = split_impl(node->left, k);\n           \
    \ node->left = sub.second;\n            return make_pair(sub.first, update(node));\n\
    \        }\n        else {\n            pair<Node*, Node*> sub = split_impl(node->right,\
    \ k - 1 - size(node->left));\n            node->right = sub.first;\n         \
    \   return make_pair(update(node), sub.second);\n        }\n    }\n    inline\
    \ TypeNode fold_impl(Node *node, int l, int r) {\n        if (l < 0 || size(node)\
    \ <= l || r<=0 || r-l <= 0) return Monoid::unit_node;\n        if (l == 0 && r\
    \ == size(node)) return range_value(node);\n        TypeNode value = Monoid::unit_node;\n\
    \        int sl = size(node->left);\n        if(sl > l) value = Monoid::func_fold(value,fold_impl(node->left,l,min(sl,r)));\n\
    \        l = max(l-sl,0), r -= sl;\n        if(l == 0 && r > 0) value = Monoid::func_fold(value,node->value);\n\
    \        l = max(l-1,0), r -= 1;\n        if(l >= 0 && r > l) value = Monoid::func_fold(value,fold_impl(node->right,l,r));\n\
    \        return value;\n    }\n    inline int lower_bound(Node *node, TypeNode\
    \ value) {\n        if (node==nullptr) return 0;\n        if (value <= node->value)\
    \ return lower_bound(node->left, value);\n        else return size(node->left)\
    \ + lower_bound(node->right, value) + 1;\n    }\n    inline int upper_bound(Node\
    \ *node, TypeNode value) {\n        if (node==nullptr) return 0;\n        if (value\
    \ < node->value) return upper_bound(node->left, value);\n        else return size(node->left)\
    \ + upper_bound(node->right, value) + 1;\n    }\n    inline void insert_impl(const\
    \ TypeNode value) {\n        pair<Node*, Node*> sub = split_impl(this->root, lower_bound(this->root,value));\n\
    \        this->root = this->merge_impl(this->merge_impl(sub.first, new Node(value)),\
    \ sub.second);\n    }\n    inline void erase_impl(const TypeNode value) {\n  \
    \      int k1 = lower_bound(value), k2 = upper_bound(value);\n        if(k1==k2)\
    \ return;\n        auto sub = split_impl(this->root,k1);\n        this->root =\
    \ merge_impl(sub.first, split_impl(sub.second, 1).second);\n    }\npublic:\n \
    \   RandomizedBinarySearchTree() : root(nullptr) {}\n    inline int size() {return\
    \ size(this->root);}\n    inline int empty(void) {return bool(size()==0);}\n \
    \   inline Node* merge(Node *left, Node *right) {return merge_impl(left,right);}\n\
    \    inline pair<Node*, Node*> split(int k) {return split_impl(this->root,k);}\n\
    \    inline void insert(const TypeNode value) {insert_impl(value);}\n    inline\
    \ void erase(const TypeNode value) {erase_impl(value);}\n    inline TypeNode get(size_t\
    \ k) {return get(this->root, k);}\n    inline TypeNode fold(int l, int r) {return\
    \ fold_impl(this->root,l,r);}\n    inline int lower_bound(TypeNode value) {return\
    \ lower_bound(this->root,value);}\n    inline int upper_bound(TypeNode value)\
    \ {return upper_bound(this->root,value);}\n    inline int count(TypeNode value)\
    \ {return upper_bound(value) - lower_bound(value);}\n    void print() {int m =\
    \ size(this->root); for(int i=0;i<m;++i) cout << get(i) << \" \\n\"[i==m-1];}\n\
    };\n"
  code: "/*\n * @title RandomizedBinarySearchTree - \u5E73\u8861\u4E8C\u5206\u63A2\
    \u7D22\u6728\n * @docs md/binary-search-tree/RandomizedBinarySearchTree.md\n */\n\
    template<class Monoid> class RandomizedBinarySearchTree {\n    using TypeNode\
    \ = typename Monoid::TypeNode;\n    unsigned int x = 123456789, y = 362436069,\
    \ z = 521288629, w = 88675123;\n    unsigned int xor_shift() {\n        unsigned\
    \ int t = (x ^ (x << 11)); x = y; y = z; z = w;\n        return (w = (w ^ (w >>\
    \ 19)) ^ (t ^ (t >> 8)));\n    }\n    struct Node {\n    private:\n        void\
    \ build() {left = right = nullptr;size = 1;}\n    public:\n        Node *left,\
    \ *right;\n        TypeNode value, range_value;\n        int size;\n        Node()\
    \ : value(Monoid::unit_node), range_value(Monoid::unit_node) {build();}\n    \
    \    Node(TypeNode v) : value(v), range_value(v) {build();}\n        friend ostream\
    \ &operator<<(ostream &os, const Node* node) {return os << \"{\" << node->value\
    \ << \", \" << node->range_value << \", \" << node->size << \"}\";}\n    };\n\
    \    Node* root;\n    inline int size(Node *node) {return node==nullptr ? 0 :\
    \ node->size;}\n    inline TypeNode range_value(Node *node) {return node==nullptr\
    \ ? Monoid::unit_node : node->range_value;}\n    inline TypeNode get(Node *node,\
    \ size_t k) {\n        if (node==nullptr) return Monoid::unit_node;\n        if\
    \ (k == size(node->left)) return node->value;\n        if (k < size(node->left))\
    \ return get(node->left, k);\n        else return get(node->right, k-1 - size(node->left));\n\
    \    }\n    inline Node* update(Node *node) {\n        node->size = size(node->left)\
    \ + size(node->right) + 1;\n        node->range_value = Monoid::func_fold(Monoid::func_fold(range_value(node->left),node->value),range_value(node->right));\n\
    \        return node;\n    }\n    inline Node* merge_impl(Node *left, Node *right)\
    \ {\n        if (left==nullptr)  return right;\n        if (right==nullptr) return\
    \ left;\n        if (xor_shift() % (left->size + right->size) < left->size) {\n\
    \            left->right = merge_impl(left->right, right);\n            return\
    \ update(left);\n        }\n        else {\n            right->left = merge_impl(left,\
    \ right->left);\n            return update(right);\n        }\n    }\n    inline\
    \ pair<Node*, Node*> split_impl(Node* node, int k) {\n        if (node==nullptr)\
    \ return make_pair(nullptr, nullptr);\n        if (k <= size(node->left)) {\n\
    \            pair<Node*, Node*> sub = split_impl(node->left, k);\n           \
    \ node->left = sub.second;\n            return make_pair(sub.first, update(node));\n\
    \        }\n        else {\n            pair<Node*, Node*> sub = split_impl(node->right,\
    \ k - 1 - size(node->left));\n            node->right = sub.first;\n         \
    \   return make_pair(update(node), sub.second);\n        }\n    }\n    inline\
    \ TypeNode fold_impl(Node *node, int l, int r) {\n        if (l < 0 || size(node)\
    \ <= l || r<=0 || r-l <= 0) return Monoid::unit_node;\n        if (l == 0 && r\
    \ == size(node)) return range_value(node);\n        TypeNode value = Monoid::unit_node;\n\
    \        int sl = size(node->left);\n        if(sl > l) value = Monoid::func_fold(value,fold_impl(node->left,l,min(sl,r)));\n\
    \        l = max(l-sl,0), r -= sl;\n        if(l == 0 && r > 0) value = Monoid::func_fold(value,node->value);\n\
    \        l = max(l-1,0), r -= 1;\n        if(l >= 0 && r > l) value = Monoid::func_fold(value,fold_impl(node->right,l,r));\n\
    \        return value;\n    }\n    inline int lower_bound(Node *node, TypeNode\
    \ value) {\n        if (node==nullptr) return 0;\n        if (value <= node->value)\
    \ return lower_bound(node->left, value);\n        else return size(node->left)\
    \ + lower_bound(node->right, value) + 1;\n    }\n    inline int upper_bound(Node\
    \ *node, TypeNode value) {\n        if (node==nullptr) return 0;\n        if (value\
    \ < node->value) return upper_bound(node->left, value);\n        else return size(node->left)\
    \ + upper_bound(node->right, value) + 1;\n    }\n    inline void insert_impl(const\
    \ TypeNode value) {\n        pair<Node*, Node*> sub = split_impl(this->root, lower_bound(this->root,value));\n\
    \        this->root = this->merge_impl(this->merge_impl(sub.first, new Node(value)),\
    \ sub.second);\n    }\n    inline void erase_impl(const TypeNode value) {\n  \
    \      int k1 = lower_bound(value), k2 = upper_bound(value);\n        if(k1==k2)\
    \ return;\n        auto sub = split_impl(this->root,k1);\n        this->root =\
    \ merge_impl(sub.first, split_impl(sub.second, 1).second);\n    }\npublic:\n \
    \   RandomizedBinarySearchTree() : root(nullptr) {}\n    inline int size() {return\
    \ size(this->root);}\n    inline int empty(void) {return bool(size()==0);}\n \
    \   inline Node* merge(Node *left, Node *right) {return merge_impl(left,right);}\n\
    \    inline pair<Node*, Node*> split(int k) {return split_impl(this->root,k);}\n\
    \    inline void insert(const TypeNode value) {insert_impl(value);}\n    inline\
    \ void erase(const TypeNode value) {erase_impl(value);}\n    inline TypeNode get(size_t\
    \ k) {return get(this->root, k);}\n    inline TypeNode fold(int l, int r) {return\
    \ fold_impl(this->root,l,r);}\n    inline int lower_bound(TypeNode value) {return\
    \ lower_bound(this->root,value);}\n    inline int upper_bound(TypeNode value)\
    \ {return upper_bound(this->root,value);}\n    inline int count(TypeNode value)\
    \ {return upper_bound(value) - lower_bound(value);}\n    void print() {int m =\
    \ size(this->root); for(int i=0;i<m;++i) cout << get(i) << \" \\n\"[i==m-1];}\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: lib/binary-search-tree/RandomizedBinarySearchTree.cpp
  requiredBy: []
  timestamp: '2023-05-29 03:23:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/binary-search-tree/RandomizedBinarySearchTree-pair.test.cpp
  - test/binary-search-tree/RandomizedBinarySearchTree-get.test.cpp
  - test/binary-search-tree/RandomizedBinarySearchTree-med.test.cpp
documentation_of: lib/binary-search-tree/RandomizedBinarySearchTree.cpp
layout: document
redirect_from:
- /library/lib/binary-search-tree/RandomizedBinarySearchTree.cpp
- /library/lib/binary-search-tree/RandomizedBinarySearchTree.cpp.html
title: "RandomizedBinarySearchTree - \u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728"
---
### RandomizedBinarySearchTree
- setベースの平衡二分探索木
  - 0-indexed

### コンストラクタ
- RandomizedBinarySearchTree()
  - 引数なし

### メソッド
- size()
  - 列のサイズを返す
  - $O(1)$
- empty(void) 
  - 列が空かどうかを返す
  - $O(1)$
- merge(Node *left, Node *right) 
  - 2個のノードをマージする
  - $O(\log N)$
- split(int k)
  - ノードを[0,k),[k,N)の2個にsplitする
  - $O(\log N)$
- insert(const TypeNode value) 
  - valueを挿入する
  - $O(\log N)$
- erase(const TypeNode value)
  - valueを1つ削除する
  - 要素が存在しないときは何もしない
  - $O(\log N)$
- get(size_t k) 
  - k番目の値を返す(重複ありでk番目に小さいもの)
  - $O(\log N)$
- fold(int l, int r) 
  - 半開区間[l,r)をfoldした値を返す
  - $O(\log N)$
- lower_bound(TypeNode value)
  - value以上の値を持つindexを返す
  - $O(\log N)$
- upper_bound(TypeNode value)
  - valueより大きいの値を持つindexを返す
  - $O(\log N)$
- count(TypeNode value)
  - valueの要素数を返す
  - $O(\log N)$
- print() 
  - デバッグ用

### 参考資料
- [平衡二分木を使う問題](https://yosupo.hatenablog.com/entry/2014/12/09/222401)
- [C - データ構造](https://atcoder.jp/contests/arc033/tasks/arc033_3)
  - [提出](https://atcoder.jp/contests/arc033/submissions/22264114)
