---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/binary-search-tree/LazyBinarySearchTree-insert-erase.test.cpp
    title: test/data-structure/binary-search-tree/LazyBinarySearchTree-insert-erase.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/binary-search-tree/LazyBinarySearchTree-rsqrafq.test.cpp
    title: test/data-structure/binary-search-tree/LazyBinarySearchTree-rsqrafq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/binary-search-tree/LazyBinarySearchTree-rsqraq.test.cpp
    title: test/data-structure/binary-search-tree/LazyBinarySearchTree-rsqraq.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/data-structure/binary-search-tree/LazyBinarySearchTree.md
    document_title: "LazyBinarySearchTree - \u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728"
    links: []
  bundledCode: "#line 1 \"lib/data-structure/binary-search-tree/LazyBinarySearchTree.cpp\"\
    \n/*\n * @title LazyBinarySearchTree - \u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728\
    \n * @docs md/data-structure/binary-search-tree/LazyBinarySearchTree.md\n */\n\
    template<class Monoid> class LazyBinarySearchTree {\n\tusing TypeNode = typename\
    \ Monoid::TypeNode;\n\tusing TypeLazy = typename Monoid::TypeLazy;\n\tunsigned\
    \ int x = 123456789, y = 362436069, z = 521288629, w = 88675123;\n\tunsigned int\
    \ xor_shift() {\n\t\tunsigned int t = (x ^ (x << 11)); x = y; y = z; z = w;\n\t\
    \treturn (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));\n\t}\n\tstruct Node {\n\tprivate:\n\
    \t\tvoid build() {left = right = nullptr;size = 1;lazy = range_lazy = Monoid::unit_lazy;}\n\
    \tpublic:\n\t\tNode *left, *right;\n\t\tTypeNode value, range_value;\n\t\tTypeLazy\
    \ lazy, range_lazy;\n\t\tint size;\n\t\tNode() : value(Monoid::unit_node), range_value(Monoid::unit_node)\
    \ {build();}\n\t\tNode(TypeNode v) : value(v), range_value(v) {build();}\n   \
    \     friend ostream &operator<<(ostream &os, const Node* node) {return os <<\
    \ \"{\" << node->value << \", \" << node->range_value << \", \" << node->range_lazy\
    \ << \", \" << node->size << \"}\";}\n\t};\n\tNode* root;\n\tinline int size(Node\
    \ *node) {return node==nullptr ? 0 : node->size;}\n    inline TypeNode range_value(Node\
    \ *node) {return node==nullptr ? Monoid::unit_node : node->range_value;}\n\tinline\
    \ TypeNode get(Node *node, size_t k) {\n\t\tif (node==nullptr) return Monoid::unit_node;\n\
    \        propagate(node);\n\t\tif (k == size(node->left)) return node->value;\n\
    \t\tif (k < size(node->left)) return get(node->left, k);\n\t\telse return get(node->right,\
    \ k-1 - size(node->left));\n\t}\n\tinline Node* update(Node *node) {\n\t\tnode->size\
    \ = size(node->left) + size(node->right) + 1;\n\t\tnode->range_value = Monoid::func_fold(Monoid::func_fold(range_value(node->left),node->value),range_value(node->right));\n\
    \t\treturn node;\n\t}\n\tinline void propagate(Node *node) {\n\t\tif(node==nullptr\
    \ || node->range_lazy == Monoid::unit_lazy) return;\n\t\tnode->range_value = Monoid::func_operate(node->range_value,node->range_lazy,0,node->size);\n\
    \t\tnode->value = Monoid::func_operate(node->value,node->range_lazy,0,1);\n\t\t\
    if(node->left !=nullptr) node->left->range_lazy  = Monoid::func_lazy(node->left->range_lazy,node->range_lazy);\n\
    \t\tif(node->right!=nullptr) node->right->range_lazy = Monoid::func_lazy(node->right->range_lazy,node->range_lazy);\n\
    \t\tnode->range_lazy = Monoid::unit_lazy;\n\t}\n    Node* merge(Node *left, Node\
    \ *right) {\n\t\tif (left==nullptr)  return right;\n\t\tif (right==nullptr) return\
    \ left;\n        propagate(left);\n        propagate(right);\n\t\tif (xor_shift()\
    \ % (left->size + right->size) < left->size) {\n\t\t\tleft->right = merge(left->right,\
    \ right);\n\t\t\treturn update(left);\n\t\t}\n\t\telse {\n\t\t\tright->left =\
    \ merge(left, right->left);\n\t\t\treturn update(right);\n\t\t}\n\t}\n\tpair<Node*,\
    \ Node*> split(Node* node, int k) {\n\t\tif (node==nullptr) return make_pair(nullptr,\
    \ nullptr);\n        propagate(node);\n\t\tif (k <= size(node->left)) {\n\t\t\t\
    pair<Node*, Node*> sub = split(node->left, k);\n\t\t\tnode->left = sub.second;\n\
    \t\t\treturn make_pair(sub.first, update(node));\n\t\t}\n\t\telse {\n\t\t\tpair<Node*,\
    \ Node*> sub = split(node->right, k - 1 - size(node->left));\n\t\t\tnode->right\
    \ = sub.first;\n\t\t\treturn make_pair(update(node), sub.second);\n\t\t}\n\t}\n\
    \tinline void operate(Node *node, int l, int r, TypeLazy lazy) {\n\t\tif(l < 0\
    \ || size(node) <= l || r <= 0 || r-l <= 0) return;\n\t\tif (l == 0 && r == size(node))\
    \ {\n\t\t\tnode->range_lazy = Monoid::func_lazy(node->range_lazy,lazy);\n\t\t\t\
    propagate(node);\n\t\t\treturn;\n\t\t}\n\t\tint sl = size(node->left);\n\t\tpropagate(node->left);\n\
    \t\tif(sl > l) operate(node->left,l,min(sl,r),lazy);\n\t\tl = max(l-sl,0), r -=\
    \ sl;\n\t\tif(l == 0 && r > 0) node->value = Monoid::func_operate(node->value,lazy,0,1);\n\
    \t\tl = max(l-1,0), r -= 1;\n\t\tpropagate(node->right);\n\t\tif(l >= 0 && r >\
    \ l) operate(node->right,l,r,lazy);\n\t\tupdate(node);\n\t}\n\tinline TypeNode\
    \ fold(Node *node, int l, int r) {\n        if (l < 0 || size(node) <= l || r<=0\
    \ || r-l <= 0) return Monoid::unit_node;\n\t\tpropagate(node);\n\t\tif (l == 0\
    \ && r == size(node)) return range_value(node);\n        TypeNode value = Monoid::unit_node;\n\
    \t\tint sl = size(node->left);\n\t\tif(sl > l) value = Monoid::func_fold(value,fold(node->left,l,min(sl,r)));\n\
    \t\tl = max(l-sl,0), r -= sl;\n\t\tif(l == 0 && r > 0) value = Monoid::func_fold(value,node->value);\n\
    \t\tl = max(l-1,0), r -= 1;\n\t\tif(l >= 0 && r > l) value = Monoid::func_fold(value,fold(node->right,l,r));\n\
    \t\treturn value;\n\t}\n\n\tLazyBinarySearchTree(Node* node):root(node){}\npublic:\n\
    \tLazyBinarySearchTree() : root(nullptr) {}\n\tinline int size() {return size(this->root);}\n\
    \tinline int empty(void) {return bool(size()==0);}\n\tinline TypeNode get(size_t\
    \ k) {return get(this->root, k);}\n\tinline void insert(const size_t k, const\
    \ TypeNode value) {pair<Node*, Node*> sub = split(this->root, k); this->root =\
    \ this->merge(this->merge(sub.first, new Node(value)), sub.second);}\n    inline\
    \ TypeNode fold(int l, int r) {return fold(this->root,l,r);}\n\tinline void operate(const\
    \ int l, const int r, const TypeLazy lazy) {propagate(this->root); operate(this->root,l,r,lazy);}\n\
    \    inline void erase(const size_t k) {\n        if(size(this->root) <= k) return;\n\
    \        auto sub = split(this->root,k);\n        this->root = merge(sub.first,\
    \ split(sub.second, 1).second);\n    }\n    void print() {\n\t\tqueue<pair<Node*,int>>\
    \ q1,q2;\n        q1.push({root,0});\n        while(q1.size()) {\n           \
    \ while(q1.size()) {\n                auto p = q1.front(); q1.pop();\n       \
    \         q2.push(p);\n            }\n            int flg = 1;\n            cout\
    \ << \"{\";\n            while(q2.size()) {\n                auto node = q2.front().first;\
    \ \n\t\t\t\tauto offs = q2.front().second;\n\t\t\t\tq2.pop();\n              \
    \  if(node==nullptr) {\n                    cout << \"{},\";\n               \
    \     q1.push({nullptr,-1});\n                    q1.push({nullptr,-1});\n   \
    \             }\n                else {\n\t\t\t\t\tpropagate(node);\n        \
    \            cout << offs + size(node->left) << \":\" << node << \",\";\n    \
    \                q1.push({node->left,offs});\n                    q1.push({node->right,offs\
    \ + size(node->left) + 1});\n                    flg &= 0;\n                }\n\
    \            }\n            cout << \"}\" << endl;\n            if(flg) break;\n\
    \        }\n    }\n};\n"
  code: "/*\n * @title LazyBinarySearchTree - \u5E73\u8861\u4E8C\u5206\u63A2\u7D22\
    \u6728\n * @docs md/data-structure/binary-search-tree/LazyBinarySearchTree.md\n\
    \ */\ntemplate<class Monoid> class LazyBinarySearchTree {\n\tusing TypeNode =\
    \ typename Monoid::TypeNode;\n\tusing TypeLazy = typename Monoid::TypeLazy;\n\t\
    unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;\n\tunsigned\
    \ int xor_shift() {\n\t\tunsigned int t = (x ^ (x << 11)); x = y; y = z; z = w;\n\
    \t\treturn (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));\n\t}\n\tstruct Node {\n\tprivate:\n\
    \t\tvoid build() {left = right = nullptr;size = 1;lazy = range_lazy = Monoid::unit_lazy;}\n\
    \tpublic:\n\t\tNode *left, *right;\n\t\tTypeNode value, range_value;\n\t\tTypeLazy\
    \ lazy, range_lazy;\n\t\tint size;\n\t\tNode() : value(Monoid::unit_node), range_value(Monoid::unit_node)\
    \ {build();}\n\t\tNode(TypeNode v) : value(v), range_value(v) {build();}\n   \
    \     friend ostream &operator<<(ostream &os, const Node* node) {return os <<\
    \ \"{\" << node->value << \", \" << node->range_value << \", \" << node->range_lazy\
    \ << \", \" << node->size << \"}\";}\n\t};\n\tNode* root;\n\tinline int size(Node\
    \ *node) {return node==nullptr ? 0 : node->size;}\n    inline TypeNode range_value(Node\
    \ *node) {return node==nullptr ? Monoid::unit_node : node->range_value;}\n\tinline\
    \ TypeNode get(Node *node, size_t k) {\n\t\tif (node==nullptr) return Monoid::unit_node;\n\
    \        propagate(node);\n\t\tif (k == size(node->left)) return node->value;\n\
    \t\tif (k < size(node->left)) return get(node->left, k);\n\t\telse return get(node->right,\
    \ k-1 - size(node->left));\n\t}\n\tinline Node* update(Node *node) {\n\t\tnode->size\
    \ = size(node->left) + size(node->right) + 1;\n\t\tnode->range_value = Monoid::func_fold(Monoid::func_fold(range_value(node->left),node->value),range_value(node->right));\n\
    \t\treturn node;\n\t}\n\tinline void propagate(Node *node) {\n\t\tif(node==nullptr\
    \ || node->range_lazy == Monoid::unit_lazy) return;\n\t\tnode->range_value = Monoid::func_operate(node->range_value,node->range_lazy,0,node->size);\n\
    \t\tnode->value = Monoid::func_operate(node->value,node->range_lazy,0,1);\n\t\t\
    if(node->left !=nullptr) node->left->range_lazy  = Monoid::func_lazy(node->left->range_lazy,node->range_lazy);\n\
    \t\tif(node->right!=nullptr) node->right->range_lazy = Monoid::func_lazy(node->right->range_lazy,node->range_lazy);\n\
    \t\tnode->range_lazy = Monoid::unit_lazy;\n\t}\n    Node* merge(Node *left, Node\
    \ *right) {\n\t\tif (left==nullptr)  return right;\n\t\tif (right==nullptr) return\
    \ left;\n        propagate(left);\n        propagate(right);\n\t\tif (xor_shift()\
    \ % (left->size + right->size) < left->size) {\n\t\t\tleft->right = merge(left->right,\
    \ right);\n\t\t\treturn update(left);\n\t\t}\n\t\telse {\n\t\t\tright->left =\
    \ merge(left, right->left);\n\t\t\treturn update(right);\n\t\t}\n\t}\n\tpair<Node*,\
    \ Node*> split(Node* node, int k) {\n\t\tif (node==nullptr) return make_pair(nullptr,\
    \ nullptr);\n        propagate(node);\n\t\tif (k <= size(node->left)) {\n\t\t\t\
    pair<Node*, Node*> sub = split(node->left, k);\n\t\t\tnode->left = sub.second;\n\
    \t\t\treturn make_pair(sub.first, update(node));\n\t\t}\n\t\telse {\n\t\t\tpair<Node*,\
    \ Node*> sub = split(node->right, k - 1 - size(node->left));\n\t\t\tnode->right\
    \ = sub.first;\n\t\t\treturn make_pair(update(node), sub.second);\n\t\t}\n\t}\n\
    \tinline void operate(Node *node, int l, int r, TypeLazy lazy) {\n\t\tif(l < 0\
    \ || size(node) <= l || r <= 0 || r-l <= 0) return;\n\t\tif (l == 0 && r == size(node))\
    \ {\n\t\t\tnode->range_lazy = Monoid::func_lazy(node->range_lazy,lazy);\n\t\t\t\
    propagate(node);\n\t\t\treturn;\n\t\t}\n\t\tint sl = size(node->left);\n\t\tpropagate(node->left);\n\
    \t\tif(sl > l) operate(node->left,l,min(sl,r),lazy);\n\t\tl = max(l-sl,0), r -=\
    \ sl;\n\t\tif(l == 0 && r > 0) node->value = Monoid::func_operate(node->value,lazy,0,1);\n\
    \t\tl = max(l-1,0), r -= 1;\n\t\tpropagate(node->right);\n\t\tif(l >= 0 && r >\
    \ l) operate(node->right,l,r,lazy);\n\t\tupdate(node);\n\t}\n\tinline TypeNode\
    \ fold(Node *node, int l, int r) {\n        if (l < 0 || size(node) <= l || r<=0\
    \ || r-l <= 0) return Monoid::unit_node;\n\t\tpropagate(node);\n\t\tif (l == 0\
    \ && r == size(node)) return range_value(node);\n        TypeNode value = Monoid::unit_node;\n\
    \t\tint sl = size(node->left);\n\t\tif(sl > l) value = Monoid::func_fold(value,fold(node->left,l,min(sl,r)));\n\
    \t\tl = max(l-sl,0), r -= sl;\n\t\tif(l == 0 && r > 0) value = Monoid::func_fold(value,node->value);\n\
    \t\tl = max(l-1,0), r -= 1;\n\t\tif(l >= 0 && r > l) value = Monoid::func_fold(value,fold(node->right,l,r));\n\
    \t\treturn value;\n\t}\n\n\tLazyBinarySearchTree(Node* node):root(node){}\npublic:\n\
    \tLazyBinarySearchTree() : root(nullptr) {}\n\tinline int size() {return size(this->root);}\n\
    \tinline int empty(void) {return bool(size()==0);}\n\tinline TypeNode get(size_t\
    \ k) {return get(this->root, k);}\n\tinline void insert(const size_t k, const\
    \ TypeNode value) {pair<Node*, Node*> sub = split(this->root, k); this->root =\
    \ this->merge(this->merge(sub.first, new Node(value)), sub.second);}\n    inline\
    \ TypeNode fold(int l, int r) {return fold(this->root,l,r);}\n\tinline void operate(const\
    \ int l, const int r, const TypeLazy lazy) {propagate(this->root); operate(this->root,l,r,lazy);}\n\
    \    inline void erase(const size_t k) {\n        if(size(this->root) <= k) return;\n\
    \        auto sub = split(this->root,k);\n        this->root = merge(sub.first,\
    \ split(sub.second, 1).second);\n    }\n    void print() {\n\t\tqueue<pair<Node*,int>>\
    \ q1,q2;\n        q1.push({root,0});\n        while(q1.size()) {\n           \
    \ while(q1.size()) {\n                auto p = q1.front(); q1.pop();\n       \
    \         q2.push(p);\n            }\n            int flg = 1;\n            cout\
    \ << \"{\";\n            while(q2.size()) {\n                auto node = q2.front().first;\
    \ \n\t\t\t\tauto offs = q2.front().second;\n\t\t\t\tq2.pop();\n              \
    \  if(node==nullptr) {\n                    cout << \"{},\";\n               \
    \     q1.push({nullptr,-1});\n                    q1.push({nullptr,-1});\n   \
    \             }\n                else {\n\t\t\t\t\tpropagate(node);\n        \
    \            cout << offs + size(node->left) << \":\" << node << \",\";\n    \
    \                q1.push({node->left,offs});\n                    q1.push({node->right,offs\
    \ + size(node->left) + 1});\n                    flg &= 0;\n                }\n\
    \            }\n            cout << \"}\" << endl;\n            if(flg) break;\n\
    \        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data-structure/binary-search-tree/LazyBinarySearchTree.cpp
  requiredBy: []
  timestamp: '2021-05-02 12:04:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/binary-search-tree/LazyBinarySearchTree-insert-erase.test.cpp
  - test/data-structure/binary-search-tree/LazyBinarySearchTree-rsqraq.test.cpp
  - test/data-structure/binary-search-tree/LazyBinarySearchTree-rsqrafq.test.cpp
documentation_of: lib/data-structure/binary-search-tree/LazyBinarySearchTree.cpp
layout: document
redirect_from:
- /library/lib/data-structure/binary-search-tree/LazyBinarySearchTree.cpp
- /library/lib/data-structure/binary-search-tree/LazyBinarySearchTree.cpp.html
title: "LazyBinarySearchTree - \u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728"
---
