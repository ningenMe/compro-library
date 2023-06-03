---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/binary-search-tree/LazySplayTreeSequence-insert-erase.test.cpp
    title: test/binary-search-tree/LazySplayTreeSequence-insert-erase.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/binary-search-tree/LazySplayTreeSequence-reverse.test.cpp
    title: test/binary-search-tree/LazySplayTreeSequence-reverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/binary-search-tree/LazySplayTreeSequence-reverse2.test.cpp
    title: test/binary-search-tree/LazySplayTreeSequence-reverse2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/binary-search-tree/LazySplayTreeSequence-rmq.test.cpp
    title: test/binary-search-tree/LazySplayTreeSequence-rmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/binary-search-tree/LazySplayTreeSequence-rsqrafq.test.cpp
    title: test/binary-search-tree/LazySplayTreeSequence-rsqrafq.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/binary-search-tree/LazySplayTreeSequence.md
    document_title: "LazySplayTreeSequence - \u9045\u5EF6\u8A55\u4FA1SplayTree\u5217"
    links: []
  bundledCode: "#line 1 \"lib/12-binary-search-tree/LazySplayTreeSequence.cpp\"\n\
    /*\n * @title LazySplayTreeSequence - \u9045\u5EF6\u8A55\u4FA1SplayTree\u5217\n\
    \ * @docs md/binary-search-tree/LazySplayTreeSequence.md\n */\ntemplate<class\
    \ Monoid> class LazySplayTreeSequence {\n    using TypeNode = typename Monoid::TypeNode;\n\
    \    using TypeLazy = typename Monoid::TypeLazy;\n    struct Node {\n    private:\n\
    \        void build() {left = right = nullptr;size = 1;rev=0;range_lazy = Monoid::unit_lazy;}\n\
    \    public:\n        Node *left, *right, *parent;\n        TypeNode value, range_value;\n\
    \        TypeLazy range_lazy;\n        int size,rev;\n        Node() : value(Monoid::unit_node),\
    \ range_value(Monoid::unit_node), parent(parent) {build();}\n        Node(const\
    \ TypeNode v) : value(v),range_value(v) {build();}\n        friend ostream &operator<<(ostream\
    \ &os, const Node* node) {return os << \"{\" << node->value << \", \" << node->size\
    \ << \"}\";}\n    };\n    Node* root;\n    inline int size(Node *node) {return\
    \ node==nullptr ? 0 : node->size;}\n    inline TypeNode range_value(Node *node)\
    \ {return node==nullptr ? Monoid::unit_node : node->range_value;}\n    inline\
    \ void update(Node *node) {\n        if(node==nullptr) return;\n\t\tif(node->left\
    \ != nullptr) propagate(node->left);\n\t\tif(node->right != nullptr) propagate(node->right);\n\
    \        node->size = size(node->left) + size(node->right) + 1;\n        node->range_value\
    \ = Monoid::func_fold(Monoid::func_fold(range_value(node->left),node->value),range_value(node->right));\n\
    \    }\n    inline void propagate(Node *node) {\n        if(node==nullptr || (node->range_lazy\
    \ == Monoid::unit_lazy && node->rev == 0)) return;\n        node->range_value\
    \ = Monoid::func_operate(node->range_value,node->range_lazy,0,node->size);\n \
    \       node->value = Monoid::func_operate(node->value,node->range_lazy,0,1);\n\
    \        if(node->left !=nullptr) node->left->range_lazy  = Monoid::func_lazy(node->left->range_lazy,node->range_lazy),\
    \ node->left->rev ^= node->rev;\n        if(node->right!=nullptr) node->right->range_lazy\
    \ = Monoid::func_lazy(node->right->range_lazy,node->range_lazy), node->right->rev\
    \ ^= node->rev;\n        if(node->rev) swap(node->left,node->right), node->rev\
    \ = 0;\n        node->range_lazy = Monoid::unit_lazy;\n    }\n    inline void\
    \ rotate_left(Node* node){\n        Node* parent = node->parent;\n        if(parent->parent\
    \ == nullptr) root = node;\n        else if (parent->parent->left == parent) parent->parent->left\
    \ = node;\n        else parent->parent->right = node;\n\n        node->parent\
    \ = parent->parent;\n        parent->parent = node;\n        if(node->left !=\
    \ nullptr) node->left->parent = parent; \n        parent->right = node->left;\n\
    \        node->left = parent;\n    }\n    inline void rotate_right(Node* node){\n\
    \        Node* parent = node->parent;\n        if(parent->parent == nullptr) root\
    \ = node;\n        else if (parent->parent->left == parent) parent->parent->left\
    \ = node;\n        else parent->parent->right = node;\n\n        node->parent\
    \ = parent->parent;\n        parent->parent = node;\n        if(node->right !=\
    \ nullptr) node->right->parent = parent; \n        parent->left = node->right;\n\
    \        node->right = parent;\n    }\n    inline void splay(Node* node){\n  \
    \      propagate(node);\n        while(node->parent != nullptr){\n           \
    \ Node* parent = node->parent;\n            Node* grand_parent = parent->parent;\n\
    \            propagate(grand_parent);\n            propagate(parent);\n      \
    \      propagate(node);\n            if(parent->left == node){\n             \
    \   if(grand_parent == nullptr){ rotate_right(node); }\n                else if(grand_parent->left\
    \  == parent){ rotate_right(parent); rotate_right(node); }\n                else\
    \ if(grand_parent->right == parent){ rotate_right(node); rotate_left(node); }\n\
    \            }\n            else{\n                if(grand_parent == nullptr){\
    \ rotate_left(node); }\n                else if(grand_parent->left  == parent){\
    \ rotate_left(node); rotate_right(node); }\n                else if(grand_parent->right\
    \ == parent){ rotate_left(parent); rotate_left(node); }\n            }\n     \
    \       update(grand_parent);\n            update(parent);\n            update(node);\n\
    \        }\n        update(node);\n    }\n    Node* get_impl(size_t k) {\n   \
    \     Node* node = root;\n        while(1) {\n            propagate(node);\n \
    \           if(size(node->left) == k) break;\n            if(size(node->left)\
    \ > k) {\n                node = node->left;\n            }\n            else\
    \ {\n                k -= size(node->left) + 1;\n                node = node->right;\n\
    \            }\n        }\n        splay(node);\n        return node;\n    }\n\
    \    //[l,r)\n    Node* get_range_impl(const size_t l, const size_t r) {\n   \
    \     if(r-l==size(root)) return root;\n        if(l==0) return get_impl(r)->left;\n\
    \        if(r==size(root)) return get_impl(l-1)->right;\n        Node* target_right\
    \ = get_impl(r);\n        Node* target_left = target_right->left;\n        root\
    \ = target_left;\n\n        target_left->parent = nullptr;\n        target_left\
    \ = get_impl(l-1);\n        root=target_right;\n\n        target_right->left=target_left;\n\
    \        target_left->parent=target_right;\n        update(target_right);\n  \
    \      return target_left->right;\n    }\n    void insert_impl(const size_t k,\
    \ const TypeNode value) {\n        Node* node = new Node(value);\n        if(k\
    \ == 0){\n            node->right = root;\n            if(root != nullptr) root->parent\
    \ = node;\n            root = node;\n            update(node);\n            return;\n\
    \        }\n        if(k == size(root)){\n            node->left = root;\n   \
    \         root->parent = node;\n            root = node;\n            update(node);\n\
    \            return;\n        }\n        Node* target = get_impl(k);\n       \
    \ node->left = target->left;\n        node->right = target;\n        root = node;\n\
    \        target->left->parent = node;\n        target->parent = node;\n      \
    \  target->left = nullptr;\n        update(target);\n        update(node);\n \
    \   }\n    void erase_impl(const size_t k){\n        Node* target = get_impl(k);\n\
    \        if(k == 0){\n            root = target->right;\n            if(root !=\
    \ nullptr) root->parent = nullptr;\n            return;\n        }\n        else\
    \ if(k+1 == size(root)){\n            root = target->left;\n            if(root\
    \ != nullptr) root->parent = nullptr;\n            return;\n        }\n      \
    \  Node* target_left = target->left;\n        Node* target_right = target->right;\n\
    \        target_right->parent = nullptr;\n        root = target_right;\n     \
    \   get_impl(0);\n        target_right = root;  \n        target_right->left =\
    \ target_left;\n        target_left->parent = target_right;\n        update(target_right);\n\
    \    }\n    inline TypeNode fold_impl(int l, int r) {\n        if (l < 0 || size(root)\
    \ <= l || r<=0 || r-l <= 0) return Monoid::unit_node;\n\t\tNode* node=get_range_impl(l,r);\n\
    \t\tpropagate(node);\n\t\tupdate(node);\n        return range_value(node);\n \
    \   }\n    void operate_impl(int l, int r, TypeLazy lazy) {\n        if(l < 0\
    \ || size(root) <= l || r <= 0 || r-l <= 0) return;\n        Node* node=get_range_impl(l,r);\n\
    \        node->range_lazy = Monoid::func_lazy(node->range_lazy,lazy);\n      \
    \  splay(node);\n    }\n    void reverse_impl(int l, int r) {\n        if (l <\
    \ 0 || size(root) <= l || r<=0 || r-l <= 0) return;\n        Node* node=get_range_impl(l,r);\n\
    \        node->rev ^= 1;\n        splay(node);\n    }\n    void print_impl() {\n\
    \        int M=5;\n        vector<vector<Node*>> vv(M);\n        vv[0].push_back(root);\n\
    \        for(int i=0;i+1<M;++i) {\n            for(int j=0;j<vv[i].size();++j)\
    \ {\n                auto le = (vv[i][j]==nullptr ? nullptr : vv[i][j]->left);\n\
    \                auto ri = (vv[i][j]==nullptr ? nullptr : vv[i][j]->right);\n\
    \                vv[i+1].push_back(le);\n                vv[i+1].push_back(ri);\n\
    \            }\n        }\n        for(int i=0;i<M;++i) {\n            int MM\
    \ = vv[i].size();\n            for(int j=0;j<MM;++j) {\n\t\t\t\tif(vv[i][j]==nullptr)\
    \ {\n\t\t\t\t\tcout << \"{:},\";\n\t\t\t\t}\n\t\t\t\telse {\n\t\t\t\t\tcout <<\
    \ \"{\" << vv[i][j]->value << \":\" << vv[i][j]->range_lazy << \"}, \";\n\t\t\t\
    \t}\n            }\n            cout << endl;\n        }\n    }\npublic:\n   \
    \ LazySplayTreeSequence(): root(nullptr) {}\n    inline TypeNode get(const size_t\
    \ k) {return get_impl(k)->value; }\n    inline int size() {return size(root);\
    \ }\n    inline void insert(const size_t k, const TypeNode value) {insert_impl(k,value);}\n\
    \    inline void erase(const size_t k) { erase_impl(k);}\n    inline void operate(const\
    \ int l, const int r, const TypeLazy lazy) {operate_impl(l,r,lazy);}\n    inline\
    \ TypeNode fold(int l, int r) {return fold_impl(l,r);}\n    inline void reverse(int\
    \ l, int r) {reverse_impl(l,r);}\n    void print() {print_impl();}\n};\n"
  code: "/*\n * @title LazySplayTreeSequence - \u9045\u5EF6\u8A55\u4FA1SplayTree\u5217\
    \n * @docs md/binary-search-tree/LazySplayTreeSequence.md\n */\ntemplate<class\
    \ Monoid> class LazySplayTreeSequence {\n    using TypeNode = typename Monoid::TypeNode;\n\
    \    using TypeLazy = typename Monoid::TypeLazy;\n    struct Node {\n    private:\n\
    \        void build() {left = right = nullptr;size = 1;rev=0;range_lazy = Monoid::unit_lazy;}\n\
    \    public:\n        Node *left, *right, *parent;\n        TypeNode value, range_value;\n\
    \        TypeLazy range_lazy;\n        int size,rev;\n        Node() : value(Monoid::unit_node),\
    \ range_value(Monoid::unit_node), parent(parent) {build();}\n        Node(const\
    \ TypeNode v) : value(v),range_value(v) {build();}\n        friend ostream &operator<<(ostream\
    \ &os, const Node* node) {return os << \"{\" << node->value << \", \" << node->size\
    \ << \"}\";}\n    };\n    Node* root;\n    inline int size(Node *node) {return\
    \ node==nullptr ? 0 : node->size;}\n    inline TypeNode range_value(Node *node)\
    \ {return node==nullptr ? Monoid::unit_node : node->range_value;}\n    inline\
    \ void update(Node *node) {\n        if(node==nullptr) return;\n\t\tif(node->left\
    \ != nullptr) propagate(node->left);\n\t\tif(node->right != nullptr) propagate(node->right);\n\
    \        node->size = size(node->left) + size(node->right) + 1;\n        node->range_value\
    \ = Monoid::func_fold(Monoid::func_fold(range_value(node->left),node->value),range_value(node->right));\n\
    \    }\n    inline void propagate(Node *node) {\n        if(node==nullptr || (node->range_lazy\
    \ == Monoid::unit_lazy && node->rev == 0)) return;\n        node->range_value\
    \ = Monoid::func_operate(node->range_value,node->range_lazy,0,node->size);\n \
    \       node->value = Monoid::func_operate(node->value,node->range_lazy,0,1);\n\
    \        if(node->left !=nullptr) node->left->range_lazy  = Monoid::func_lazy(node->left->range_lazy,node->range_lazy),\
    \ node->left->rev ^= node->rev;\n        if(node->right!=nullptr) node->right->range_lazy\
    \ = Monoid::func_lazy(node->right->range_lazy,node->range_lazy), node->right->rev\
    \ ^= node->rev;\n        if(node->rev) swap(node->left,node->right), node->rev\
    \ = 0;\n        node->range_lazy = Monoid::unit_lazy;\n    }\n    inline void\
    \ rotate_left(Node* node){\n        Node* parent = node->parent;\n        if(parent->parent\
    \ == nullptr) root = node;\n        else if (parent->parent->left == parent) parent->parent->left\
    \ = node;\n        else parent->parent->right = node;\n\n        node->parent\
    \ = parent->parent;\n        parent->parent = node;\n        if(node->left !=\
    \ nullptr) node->left->parent = parent; \n        parent->right = node->left;\n\
    \        node->left = parent;\n    }\n    inline void rotate_right(Node* node){\n\
    \        Node* parent = node->parent;\n        if(parent->parent == nullptr) root\
    \ = node;\n        else if (parent->parent->left == parent) parent->parent->left\
    \ = node;\n        else parent->parent->right = node;\n\n        node->parent\
    \ = parent->parent;\n        parent->parent = node;\n        if(node->right !=\
    \ nullptr) node->right->parent = parent; \n        parent->left = node->right;\n\
    \        node->right = parent;\n    }\n    inline void splay(Node* node){\n  \
    \      propagate(node);\n        while(node->parent != nullptr){\n           \
    \ Node* parent = node->parent;\n            Node* grand_parent = parent->parent;\n\
    \            propagate(grand_parent);\n            propagate(parent);\n      \
    \      propagate(node);\n            if(parent->left == node){\n             \
    \   if(grand_parent == nullptr){ rotate_right(node); }\n                else if(grand_parent->left\
    \  == parent){ rotate_right(parent); rotate_right(node); }\n                else\
    \ if(grand_parent->right == parent){ rotate_right(node); rotate_left(node); }\n\
    \            }\n            else{\n                if(grand_parent == nullptr){\
    \ rotate_left(node); }\n                else if(grand_parent->left  == parent){\
    \ rotate_left(node); rotate_right(node); }\n                else if(grand_parent->right\
    \ == parent){ rotate_left(parent); rotate_left(node); }\n            }\n     \
    \       update(grand_parent);\n            update(parent);\n            update(node);\n\
    \        }\n        update(node);\n    }\n    Node* get_impl(size_t k) {\n   \
    \     Node* node = root;\n        while(1) {\n            propagate(node);\n \
    \           if(size(node->left) == k) break;\n            if(size(node->left)\
    \ > k) {\n                node = node->left;\n            }\n            else\
    \ {\n                k -= size(node->left) + 1;\n                node = node->right;\n\
    \            }\n        }\n        splay(node);\n        return node;\n    }\n\
    \    //[l,r)\n    Node* get_range_impl(const size_t l, const size_t r) {\n   \
    \     if(r-l==size(root)) return root;\n        if(l==0) return get_impl(r)->left;\n\
    \        if(r==size(root)) return get_impl(l-1)->right;\n        Node* target_right\
    \ = get_impl(r);\n        Node* target_left = target_right->left;\n        root\
    \ = target_left;\n\n        target_left->parent = nullptr;\n        target_left\
    \ = get_impl(l-1);\n        root=target_right;\n\n        target_right->left=target_left;\n\
    \        target_left->parent=target_right;\n        update(target_right);\n  \
    \      return target_left->right;\n    }\n    void insert_impl(const size_t k,\
    \ const TypeNode value) {\n        Node* node = new Node(value);\n        if(k\
    \ == 0){\n            node->right = root;\n            if(root != nullptr) root->parent\
    \ = node;\n            root = node;\n            update(node);\n            return;\n\
    \        }\n        if(k == size(root)){\n            node->left = root;\n   \
    \         root->parent = node;\n            root = node;\n            update(node);\n\
    \            return;\n        }\n        Node* target = get_impl(k);\n       \
    \ node->left = target->left;\n        node->right = target;\n        root = node;\n\
    \        target->left->parent = node;\n        target->parent = node;\n      \
    \  target->left = nullptr;\n        update(target);\n        update(node);\n \
    \   }\n    void erase_impl(const size_t k){\n        Node* target = get_impl(k);\n\
    \        if(k == 0){\n            root = target->right;\n            if(root !=\
    \ nullptr) root->parent = nullptr;\n            return;\n        }\n        else\
    \ if(k+1 == size(root)){\n            root = target->left;\n            if(root\
    \ != nullptr) root->parent = nullptr;\n            return;\n        }\n      \
    \  Node* target_left = target->left;\n        Node* target_right = target->right;\n\
    \        target_right->parent = nullptr;\n        root = target_right;\n     \
    \   get_impl(0);\n        target_right = root;  \n        target_right->left =\
    \ target_left;\n        target_left->parent = target_right;\n        update(target_right);\n\
    \    }\n    inline TypeNode fold_impl(int l, int r) {\n        if (l < 0 || size(root)\
    \ <= l || r<=0 || r-l <= 0) return Monoid::unit_node;\n\t\tNode* node=get_range_impl(l,r);\n\
    \t\tpropagate(node);\n\t\tupdate(node);\n        return range_value(node);\n \
    \   }\n    void operate_impl(int l, int r, TypeLazy lazy) {\n        if(l < 0\
    \ || size(root) <= l || r <= 0 || r-l <= 0) return;\n        Node* node=get_range_impl(l,r);\n\
    \        node->range_lazy = Monoid::func_lazy(node->range_lazy,lazy);\n      \
    \  splay(node);\n    }\n    void reverse_impl(int l, int r) {\n        if (l <\
    \ 0 || size(root) <= l || r<=0 || r-l <= 0) return;\n        Node* node=get_range_impl(l,r);\n\
    \        node->rev ^= 1;\n        splay(node);\n    }\n    void print_impl() {\n\
    \        int M=5;\n        vector<vector<Node*>> vv(M);\n        vv[0].push_back(root);\n\
    \        for(int i=0;i+1<M;++i) {\n            for(int j=0;j<vv[i].size();++j)\
    \ {\n                auto le = (vv[i][j]==nullptr ? nullptr : vv[i][j]->left);\n\
    \                auto ri = (vv[i][j]==nullptr ? nullptr : vv[i][j]->right);\n\
    \                vv[i+1].push_back(le);\n                vv[i+1].push_back(ri);\n\
    \            }\n        }\n        for(int i=0;i<M;++i) {\n            int MM\
    \ = vv[i].size();\n            for(int j=0;j<MM;++j) {\n\t\t\t\tif(vv[i][j]==nullptr)\
    \ {\n\t\t\t\t\tcout << \"{:},\";\n\t\t\t\t}\n\t\t\t\telse {\n\t\t\t\t\tcout <<\
    \ \"{\" << vv[i][j]->value << \":\" << vv[i][j]->range_lazy << \"}, \";\n\t\t\t\
    \t}\n            }\n            cout << endl;\n        }\n    }\npublic:\n   \
    \ LazySplayTreeSequence(): root(nullptr) {}\n    inline TypeNode get(const size_t\
    \ k) {return get_impl(k)->value; }\n    inline int size() {return size(root);\
    \ }\n    inline void insert(const size_t k, const TypeNode value) {insert_impl(k,value);}\n\
    \    inline void erase(const size_t k) { erase_impl(k);}\n    inline void operate(const\
    \ int l, const int r, const TypeLazy lazy) {operate_impl(l,r,lazy);}\n    inline\
    \ TypeNode fold(int l, int r) {return fold_impl(l,r);}\n    inline void reverse(int\
    \ l, int r) {reverse_impl(l,r);}\n    void print() {print_impl();}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/12-binary-search-tree/LazySplayTreeSequence.cpp
  requiredBy: []
  timestamp: '2023-06-03 15:39:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/binary-search-tree/LazySplayTreeSequence-rmq.test.cpp
  - test/binary-search-tree/LazySplayTreeSequence-reverse2.test.cpp
  - test/binary-search-tree/LazySplayTreeSequence-insert-erase.test.cpp
  - test/binary-search-tree/LazySplayTreeSequence-rsqrafq.test.cpp
  - test/binary-search-tree/LazySplayTreeSequence-reverse.test.cpp
documentation_of: lib/12-binary-search-tree/LazySplayTreeSequence.cpp
layout: document
redirect_from:
- /library/lib/12-binary-search-tree/LazySplayTreeSequence.cpp
- /library/lib/12-binary-search-tree/LazySplayTreeSequence.cpp.html
title: "LazySplayTreeSequence - \u9045\u5EF6\u8A55\u4FA1SplayTree\u5217"
---
### LazySplayTreeSequence
- 列ベースの、遅延伝播ができるsplay tree
  - 0-indexed

### 参考資料
- [C - データ構造](https://atcoder.jp/contests/arc033/tasks/arc033_3)
  - [提出](https://atcoder.jp/contests/arc033/submissions/41820033)

