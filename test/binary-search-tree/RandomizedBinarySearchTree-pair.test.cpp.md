---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data-structure/binary-search-tree/RandomizedBinarySearchTree.cpp
    title: "RandomizedBinarySearchTree - \u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/822
    links:
    - https://yukicoder.me/problems/no/822
  bundledCode: "#line 1 \"test/binary-search-tree/RandomizedBinarySearchTree-pair.test.cpp\"\
    \n#define PROBLEM \"https://yukicoder.me/problems/no/822\"\n\n#include <vector>\n\
    #include <iostream>\n#include <unordered_map>\n#include <algorithm>\n#include\
    \ <numeric>\n#include <cmath>\nusing namespace std;\n#line 1 \"lib/data-structure/binary-search-tree/RandomizedBinarySearchTree.cpp\"\
    \n/*\n * @title RandomizedBinarySearchTree - \u5E73\u8861\u4E8C\u5206\u63A2\u7D22\
    \u6728\n * @docs md/data-structure/binary-search-tree/RandomizedBinarySearchTree.md\n\
    \ */\ntemplate<class Monoid> class RandomizedBinarySearchTree {\n    using TypeNode\
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
    };\n#line 11 \"test/binary-search-tree/RandomizedBinarySearchTree-pair.test.cpp\"\
    \n\ntemplate<class T> struct Monoid {\n\tusing TypeNode = T;\n\tinline static\
    \ constexpr TypeNode unit_node = {0,0};\n\tinline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return {0,0};}\n};\n\nint main() {\n    int N,K; cin >> N >> K;\n\
    \    if(N+1 <= K){\n\t\tcout << \"INF\" << endl;\n\t\treturn 0;\n\t}\n    RandomizedBinarySearchTree<Monoid<pair<int,int>>>\
    \ st;\n    for(int i = 0; i < (1<<20); ++i) {\n        if((i&N) != N) continue;\n\
    \        for(int j = -K; j <= K; ++j) {\n            int a = i, b = i + j;\n \
    \           if(a>b) swap(a,b);\n            if(0<=b && b-a<=K && ((a&b)==N) &&\
    \ !st.count({a,b})) st.insert({a,b});\n        }\n    }\n    cout << st.size()\
    \ << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/822\"\n\n#include <vector>\n\
    #include <iostream>\n#include <unordered_map>\n#include <algorithm>\n#include\
    \ <numeric>\n#include <cmath>\nusing namespace std;\n#include \"../../lib/data-structure/binary-search-tree/RandomizedBinarySearchTree.cpp\"\
    \n\ntemplate<class T> struct Monoid {\n\tusing TypeNode = T;\n\tinline static\
    \ constexpr TypeNode unit_node = {0,0};\n\tinline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return {0,0};}\n};\n\nint main() {\n    int N,K; cin >> N >> K;\n\
    \    if(N+1 <= K){\n\t\tcout << \"INF\" << endl;\n\t\treturn 0;\n\t}\n    RandomizedBinarySearchTree<Monoid<pair<int,int>>>\
    \ st;\n    for(int i = 0; i < (1<<20); ++i) {\n        if((i&N) != N) continue;\n\
    \        for(int j = -K; j <= K; ++j) {\n            int a = i, b = i + j;\n \
    \           if(a>b) swap(a,b);\n            if(0<=b && b-a<=K && ((a&b)==N) &&\
    \ !st.count({a,b})) st.insert({a,b});\n        }\n    }\n    cout << st.size()\
    \ << endl;\n    return 0;\n}\n"
  dependsOn:
  - lib/data-structure/binary-search-tree/RandomizedBinarySearchTree.cpp
  isVerificationFile: true
  path: test/binary-search-tree/RandomizedBinarySearchTree-pair.test.cpp
  requiredBy: []
  timestamp: '2023-05-29 03:17:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/binary-search-tree/RandomizedBinarySearchTree-pair.test.cpp
layout: document
redirect_from:
- /verify/test/binary-search-tree/RandomizedBinarySearchTree-pair.test.cpp
- /verify/test/binary-search-tree/RandomizedBinarySearchTree-pair.test.cpp.html
title: test/binary-search-tree/RandomizedBinarySearchTree-pair.test.cpp
---
