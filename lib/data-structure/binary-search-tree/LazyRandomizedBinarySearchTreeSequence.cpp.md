---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/data-structure/binary-search-tree/LazyRandomizedBinarySearchTreeSequence.md
    document_title: "LazyRandomizedBinarySearchTreeSequence - \u9045\u5EF6\u8A55\u4FA1\
      \u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728\u5217"
    links: []
  bundledCode: "#line 1 \"lib/data-structure/binary-search-tree/LazyRandomizedBinarySearchTreeSequence.cpp\"\
    \n/*\n * @title LazyRandomizedBinarySearchTreeSequence - \u9045\u5EF6\u8A55\u4FA1\
    \u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728\u5217\n * @docs md/data-structure/binary-search-tree/LazyRandomizedBinarySearchTreeSequence.md\n\
    \ */\ntemplate<class Monoid> class LazyRandomizedBinarySearchTreeSequence {\n\
    \    using TypeNode = typename Monoid::TypeNode;\n    using TypeLazy = typename\
    \ Monoid::TypeLazy;\n    unsigned int x = 123456789, y = 362436069, z = 521288629,\
    \ w = 88675123;\n    unsigned int xor_shift() {\n        unsigned int t = (x ^\
    \ (x << 11)); x = y; y = z; z = w;\n        return (w = (w ^ (w >> 19)) ^ (t ^\
    \ (t >> 8)));\n    }\n    struct Node {\n    private:\n        void build() {left\
    \ = right = nullptr;size = 1; rev=0; range_lazy = Monoid::unit_lazy;}\n    public:\n\
    \        Node *left, *right;\n        TypeNode value, range_value;\n        TypeLazy\
    \ range_lazy;\n        int size,rev;\n        Node() : value(Monoid::unit_node),\
    \ range_value(Monoid::unit_node) {build();}\n        Node(TypeNode v) : value(v),\
    \ range_value(v) {build();}\n        friend ostream &operator<<(ostream &os, const\
    \ Node* node) {return os << \"{\" << node->value << \", \" << node->range_value\
    \ << \", \" << node->range_lazy << \", \" << node->size << \"}\";}\n    };\n \
    \   Node* root;\n    inline int size(Node *node) {return node==nullptr ? 0 : node->size;}\n\
    \    inline TypeNode range_value(Node *node) {return node==nullptr ? Monoid::unit_node\
    \ : node->range_value;}\n    inline TypeNode get(Node *node, size_t k) {\n   \
    \     if (node==nullptr) return Monoid::unit_node;\n        propagate(node);\n\
    \        if (k == size(node->left)) return node->value;\n        if (k < size(node->left))\
    \ return get(node->left, k);\n        else return get(node->right, k-1 - size(node->left));\n\
    \    }\n    inline Node* update(Node *node) {\n        node->size = size(node->left)\
    \ + size(node->right) + 1;\n        node->range_value = Monoid::func_fold(Monoid::func_fold(range_value(node->left),node->value),range_value(node->right));\n\
    \        return node;\n    }\n    inline void propagate(Node *node) {\n      \
    \  if(node==nullptr || (node->range_lazy == Monoid::unit_lazy && node->rev ==\
    \ 0)) return;\n        node->range_value = Monoid::func_operate(node->range_value,node->range_lazy,0,node->size);\n\
    \        node->value = Monoid::func_operate(node->value,node->range_lazy,0,1);\n\
    \        if(node->left !=nullptr) node->left->range_lazy  = Monoid::func_lazy(node->left->range_lazy,node->range_lazy),\
    \ node->left->rev ^= node->rev;\n        if(node->right!=nullptr) node->right->range_lazy\
    \ = Monoid::func_lazy(node->right->range_lazy,node->range_lazy), node->right->rev\
    \ ^= node->rev;\n        if(node->rev) swap(node->left,node->right), node->rev\
    \ = 0;\n        node->range_lazy = Monoid::unit_lazy;\n    }\n    inline Node*\
    \ merge_impl(Node *left, Node *right) {\n        propagate(left);\n        propagate(right);\n\
    \        if (left==nullptr)  return right;\n        if (right==nullptr) return\
    \ left;\n        if (xor_shift() % (left->size + right->size) < left->size) {\n\
    \            left->right = merge_impl(left->right, right);\n            return\
    \ update(left);\n        }\n        else {\n            right->left = merge_impl(left,\
    \ right->left);\n            return update(right);\n        }\n    }\n    inline\
    \ pair<Node*, Node*> split_impl(Node* node, int k) {\n        if (node==nullptr)\
    \ return make_pair(nullptr, nullptr);\n        propagate(node);\n        if (k\
    \ <= size(node->left)) {\n            propagate(node->right);\n            pair<Node*,\
    \ Node*> sub = split_impl(node->left, k);\n            node->left = sub.second;\n\
    \            return make_pair(sub.first, update(node));\n        }\n        else\
    \ {\n            propagate(node->left);\n            pair<Node*, Node*> sub =\
    \ split_impl(node->right, k - 1 - size(node->left));\n            node->right\
    \ = sub.first;\n            return make_pair(update(node), sub.second);\n    \
    \    }\n    }\n    inline void operate_impl(Node *node, int l, int r, TypeLazy\
    \ lazy) {\n        if(l < 0 || size(node) <= l || r <= 0 || r-l <= 0) return;\n\
    \        if (l == 0 && r == size(node)) {\n            node->range_lazy = Monoid::func_lazy(node->range_lazy,lazy);\n\
    \            propagate(node);\n            return;\n        }\n        int sl\
    \ = size(node->left);\n        propagate(node->left);\n        propagate(node->right);\n\
    \        if(sl > l) operate_impl(node->left,l,min(sl,r),lazy);\n        l = max(l-sl,0),\
    \ r -= sl;\n        if(l == 0 && r > 0) node->value = Monoid::func_operate(node->value,lazy,0,1);\n\
    \        l = max(l-1,0), r -= 1;\n        if(l >= 0 && r > l) operate_impl(node->right,l,r,lazy);\n\
    \        update(node);\n    }\n    inline TypeNode fold_impl(Node *node, int l,\
    \ int r) {\n        if (l < 0 || size(node) <= l || r<=0 || r-l <= 0) return Monoid::unit_node;\n\
    \        propagate(node);\n        if (l == 0 && r == size(node)) return range_value(node);\n\
    \        TypeNode value = Monoid::unit_node;\n        int sl = size(node->left);\n\
    \        if(sl > l) value = Monoid::func_fold(value,fold_impl(node->left,l,min(sl,r)));\n\
    \        l = max(l-sl,0), r -= sl;\n        if(l == 0 && r > 0) value = Monoid::func_fold(value,node->value);\n\
    \        l = max(l-1,0), r -= 1;\n        if(l >= 0 && r > l) value = Monoid::func_fold(value,fold_impl(node->right,l,r));\n\
    \        return value;\n    }\n    inline void reverse_impl(int l, int r) {\n\
    \        pair<Node*,Node*> tmp1 = split_impl(this->root,l);\n        pair<Node*,Node*>\
    \ tmp2 = split_impl(tmp1.second,r-l);\n        Node* nl = tmp1.first;\n      \
    \  Node* nc = tmp2.first;\n        Node* nr = tmp2.second;\n        nc->rev ^=\
    \ 1;\n        this->root = merge_impl(merge_impl(nl,nc),nr);\n    }\n    inline\
    \ void insert_impl(const size_t k, const TypeNode value) {\n        pair<Node*,\
    \ Node*> sub = split_impl(this->root, k);\n        this->root = this->merge_impl(this->merge_impl(sub.first,\
    \ new Node(value)), sub.second);\n    }\n    inline void erase_impl(const size_t\
    \ k) {\n        if(size(this->root) <= k) return;\n        auto sub = split_impl(this->root,k);\n\
    \        this->root = merge_impl(sub.first, split_impl(sub.second, 1).second);\n\
    \    }\npublic:\n    LazyRandomizedBinarySearchTreeSequence() : root(nullptr)\
    \ {}\n    inline int size() {return size(this->root);}\n    inline int empty(void)\
    \ {return bool(size()==0);}\n    inline Node* merge(Node *left, Node *right) {return\
    \ merge_impl(left,right);}\n    inline pair<Node*, Node*> split(int k) {return\
    \ split_impl(this->root,k);}\n    inline void insert(const size_t k, const TypeNode\
    \ value) {insert_impl(k,value);}\n    inline void erase(const size_t k) {erase_impl(k);}\n\
    \    inline TypeNode get(size_t k) {return get(this->root, k);}\n    inline void\
    \ operate(const int l, const int r, const TypeLazy lazy) {propagate(this->root);\
    \ operate_impl(this->root,l,r,lazy);}\n    inline TypeNode fold(int l, int r)\
    \ {return fold_impl(this->root,l,r);}\n    inline void reverse(int l, int r) {reverse_impl(l,r);}\n\
    \    void print() {int m = size(this->root); for(int i=0;i<m;++i) cout << get(i)\
    \ << \" \\n\"[i==m-1];}\n};\n"
  code: "/*\n * @title LazyRandomizedBinarySearchTreeSequence - \u9045\u5EF6\u8A55\
    \u4FA1\u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728\u5217\n * @docs md/data-structure/binary-search-tree/LazyRandomizedBinarySearchTreeSequence.md\n\
    \ */\ntemplate<class Monoid> class LazyRandomizedBinarySearchTreeSequence {\n\
    \    using TypeNode = typename Monoid::TypeNode;\n    using TypeLazy = typename\
    \ Monoid::TypeLazy;\n    unsigned int x = 123456789, y = 362436069, z = 521288629,\
    \ w = 88675123;\n    unsigned int xor_shift() {\n        unsigned int t = (x ^\
    \ (x << 11)); x = y; y = z; z = w;\n        return (w = (w ^ (w >> 19)) ^ (t ^\
    \ (t >> 8)));\n    }\n    struct Node {\n    private:\n        void build() {left\
    \ = right = nullptr;size = 1; rev=0; range_lazy = Monoid::unit_lazy;}\n    public:\n\
    \        Node *left, *right;\n        TypeNode value, range_value;\n        TypeLazy\
    \ range_lazy;\n        int size,rev;\n        Node() : value(Monoid::unit_node),\
    \ range_value(Monoid::unit_node) {build();}\n        Node(TypeNode v) : value(v),\
    \ range_value(v) {build();}\n        friend ostream &operator<<(ostream &os, const\
    \ Node* node) {return os << \"{\" << node->value << \", \" << node->range_value\
    \ << \", \" << node->range_lazy << \", \" << node->size << \"}\";}\n    };\n \
    \   Node* root;\n    inline int size(Node *node) {return node==nullptr ? 0 : node->size;}\n\
    \    inline TypeNode range_value(Node *node) {return node==nullptr ? Monoid::unit_node\
    \ : node->range_value;}\n    inline TypeNode get(Node *node, size_t k) {\n   \
    \     if (node==nullptr) return Monoid::unit_node;\n        propagate(node);\n\
    \        if (k == size(node->left)) return node->value;\n        if (k < size(node->left))\
    \ return get(node->left, k);\n        else return get(node->right, k-1 - size(node->left));\n\
    \    }\n    inline Node* update(Node *node) {\n        node->size = size(node->left)\
    \ + size(node->right) + 1;\n        node->range_value = Monoid::func_fold(Monoid::func_fold(range_value(node->left),node->value),range_value(node->right));\n\
    \        return node;\n    }\n    inline void propagate(Node *node) {\n      \
    \  if(node==nullptr || (node->range_lazy == Monoid::unit_lazy && node->rev ==\
    \ 0)) return;\n        node->range_value = Monoid::func_operate(node->range_value,node->range_lazy,0,node->size);\n\
    \        node->value = Monoid::func_operate(node->value,node->range_lazy,0,1);\n\
    \        if(node->left !=nullptr) node->left->range_lazy  = Monoid::func_lazy(node->left->range_lazy,node->range_lazy),\
    \ node->left->rev ^= node->rev;\n        if(node->right!=nullptr) node->right->range_lazy\
    \ = Monoid::func_lazy(node->right->range_lazy,node->range_lazy), node->right->rev\
    \ ^= node->rev;\n        if(node->rev) swap(node->left,node->right), node->rev\
    \ = 0;\n        node->range_lazy = Monoid::unit_lazy;\n    }\n    inline Node*\
    \ merge_impl(Node *left, Node *right) {\n        propagate(left);\n        propagate(right);\n\
    \        if (left==nullptr)  return right;\n        if (right==nullptr) return\
    \ left;\n        if (xor_shift() % (left->size + right->size) < left->size) {\n\
    \            left->right = merge_impl(left->right, right);\n            return\
    \ update(left);\n        }\n        else {\n            right->left = merge_impl(left,\
    \ right->left);\n            return update(right);\n        }\n    }\n    inline\
    \ pair<Node*, Node*> split_impl(Node* node, int k) {\n        if (node==nullptr)\
    \ return make_pair(nullptr, nullptr);\n        propagate(node);\n        if (k\
    \ <= size(node->left)) {\n            propagate(node->right);\n            pair<Node*,\
    \ Node*> sub = split_impl(node->left, k);\n            node->left = sub.second;\n\
    \            return make_pair(sub.first, update(node));\n        }\n        else\
    \ {\n            propagate(node->left);\n            pair<Node*, Node*> sub =\
    \ split_impl(node->right, k - 1 - size(node->left));\n            node->right\
    \ = sub.first;\n            return make_pair(update(node), sub.second);\n    \
    \    }\n    }\n    inline void operate_impl(Node *node, int l, int r, TypeLazy\
    \ lazy) {\n        if(l < 0 || size(node) <= l || r <= 0 || r-l <= 0) return;\n\
    \        if (l == 0 && r == size(node)) {\n            node->range_lazy = Monoid::func_lazy(node->range_lazy,lazy);\n\
    \            propagate(node);\n            return;\n        }\n        int sl\
    \ = size(node->left);\n        propagate(node->left);\n        propagate(node->right);\n\
    \        if(sl > l) operate_impl(node->left,l,min(sl,r),lazy);\n        l = max(l-sl,0),\
    \ r -= sl;\n        if(l == 0 && r > 0) node->value = Monoid::func_operate(node->value,lazy,0,1);\n\
    \        l = max(l-1,0), r -= 1;\n        if(l >= 0 && r > l) operate_impl(node->right,l,r,lazy);\n\
    \        update(node);\n    }\n    inline TypeNode fold_impl(Node *node, int l,\
    \ int r) {\n        if (l < 0 || size(node) <= l || r<=0 || r-l <= 0) return Monoid::unit_node;\n\
    \        propagate(node);\n        if (l == 0 && r == size(node)) return range_value(node);\n\
    \        TypeNode value = Monoid::unit_node;\n        int sl = size(node->left);\n\
    \        if(sl > l) value = Monoid::func_fold(value,fold_impl(node->left,l,min(sl,r)));\n\
    \        l = max(l-sl,0), r -= sl;\n        if(l == 0 && r > 0) value = Monoid::func_fold(value,node->value);\n\
    \        l = max(l-1,0), r -= 1;\n        if(l >= 0 && r > l) value = Monoid::func_fold(value,fold_impl(node->right,l,r));\n\
    \        return value;\n    }\n    inline void reverse_impl(int l, int r) {\n\
    \        pair<Node*,Node*> tmp1 = split_impl(this->root,l);\n        pair<Node*,Node*>\
    \ tmp2 = split_impl(tmp1.second,r-l);\n        Node* nl = tmp1.first;\n      \
    \  Node* nc = tmp2.first;\n        Node* nr = tmp2.second;\n        nc->rev ^=\
    \ 1;\n        this->root = merge_impl(merge_impl(nl,nc),nr);\n    }\n    inline\
    \ void insert_impl(const size_t k, const TypeNode value) {\n        pair<Node*,\
    \ Node*> sub = split_impl(this->root, k);\n        this->root = this->merge_impl(this->merge_impl(sub.first,\
    \ new Node(value)), sub.second);\n    }\n    inline void erase_impl(const size_t\
    \ k) {\n        if(size(this->root) <= k) return;\n        auto sub = split_impl(this->root,k);\n\
    \        this->root = merge_impl(sub.first, split_impl(sub.second, 1).second);\n\
    \    }\npublic:\n    LazyRandomizedBinarySearchTreeSequence() : root(nullptr)\
    \ {}\n    inline int size() {return size(this->root);}\n    inline int empty(void)\
    \ {return bool(size()==0);}\n    inline Node* merge(Node *left, Node *right) {return\
    \ merge_impl(left,right);}\n    inline pair<Node*, Node*> split(int k) {return\
    \ split_impl(this->root,k);}\n    inline void insert(const size_t k, const TypeNode\
    \ value) {insert_impl(k,value);}\n    inline void erase(const size_t k) {erase_impl(k);}\n\
    \    inline TypeNode get(size_t k) {return get(this->root, k);}\n    inline void\
    \ operate(const int l, const int r, const TypeLazy lazy) {propagate(this->root);\
    \ operate_impl(this->root,l,r,lazy);}\n    inline TypeNode fold(int l, int r)\
    \ {return fold_impl(this->root,l,r);}\n    inline void reverse(int l, int r) {reverse_impl(l,r);}\n\
    \    void print() {int m = size(this->root); for(int i=0;i<m;++i) cout << get(i)\
    \ << \" \\n\"[i==m-1];}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data-structure/binary-search-tree/LazyRandomizedBinarySearchTreeSequence.cpp
  requiredBy: []
  timestamp: '2023-05-12 01:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data-structure/binary-search-tree/LazyRandomizedBinarySearchTreeSequence.cpp
layout: document
redirect_from:
- /library/lib/data-structure/binary-search-tree/LazyRandomizedBinarySearchTreeSequence.cpp
- /library/lib/data-structure/binary-search-tree/LazyRandomizedBinarySearchTreeSequence.cpp.html
title: "LazyRandomizedBinarySearchTreeSequence - \u9045\u5EF6\u8A55\u4FA1\u5E73\u8861\
  \u4E8C\u5206\u63A2\u7D22\u6728\u5217"
---
### LazyRandomizedBinarySearchTreeSequence
- 列ベースの、遅延伝播平衡二分探索木
  - 0-indexed

### コンストラクタ
- LazyRandomizedBinarySearchTreeSequence()
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
- insert(const size_t k, const TypeNode value) 
  - k番目の値の手前に、valueを挿入する
    - k=0のときは、一番前に挿入される
    - k=Nのときは、一番後に挿入される
  - $O(\log N)$
- erase(const size_t k)
  - k番目の値を削除する
- get(size_t k) 
  - k番目の値を返す(単純に前からk番目。k番目に小さいものではない)
  - $O(\log N)$
- operate(const int l, const int r, const TypeLazy lazy)
  - 半開区間[l,r)にlazyを作用させる
  - $O(\log N)$
- fold(int l, int r) 
  - 半開区間[l,r)をfoldした値を返す
  - $O(\log N)$
- reverse(int l, int r) 
  - 半開区間[l,r)をreverseする
  - $O(\log N)$
- print() 
  - デバッグ用



### 参考資料
- [平衡二分木を使う問題](https://yosupo.hatenablog.com/entry/2014/12/09/222401)
- [B - カッコつけ](https://atcoder.jp/contests/code-festival-2014-exhibition-open/tasks/code_festival_exhibition_b)
  - [提出](https://atcoder.jp/contests/code-festival-2014-exhibition-open/submissions/22250302)
