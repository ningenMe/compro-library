---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/binary-search-tree/RandomizedBinarySearchTreeSequence.cpp
    title: "RandomizedBinarySearchTreeSequence - \u5E73\u8861\u4E8C\u5206\u63A2\u7D22\
      \u6728\u5217"
  - icon: ':heavy_check_mark:'
    path: lib/operator/monoid/MonoidRangeMinPointUpdate.cpp
    title: "MonoidRangeMinPointUpdate - [\u533A\u9593min, \u70B9\u66F4\u65B0]"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508
  bundledCode: "#line 1 \"test/binary-search-tree/RandomizedBinarySearchTreeSequence-insert-erase.test.cpp\"\
    \n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <queue>\n\
    using namespace std;\n#line 1 \"lib/operator/monoid/MonoidRangeMinPointUpdate.cpp\"\
    \n/*\n * @title MonoidRangeMinPointUpdate - [\u533A\u9593min, \u70B9\u66F4\u65B0\
    ]\n * @docs md/operator/monoid/MonoidRangeMinPointUpdate.md\n */\ntemplate<class\
    \ T> struct MonoidRangeMinPointUpdate {\n    using TypeNode = T;\n    inline static\
    \ constexpr TypeNode unit_node = (1LL<<31)-1;\n    inline static constexpr TypeNode\
    \ func_fold(TypeNode l,TypeNode r){return min(l,r);}\n    inline static constexpr\
    \ TypeNode func_operate(TypeNode l,TypeNode r){return r;}\n    inline static constexpr\
    \ bool func_check(TypeNode nodeVal,TypeNode var){return var > nodeVal;}\n};\n\
    #line 1 \"lib/binary-search-tree/RandomizedBinarySearchTreeSequence.cpp\"\n/*\n\
    \ * @title RandomizedBinarySearchTreeSequence - \u5E73\u8861\u4E8C\u5206\u63A2\
    \u7D22\u6728\u5217\n * @docs md/binary-search-tree/RandomizedBinarySearchTreeSequence.md\n\
    \ */\ntemplate<class Monoid> class RandomizedBinarySearchTreeSequence {\n    using\
    \ TypeNode = typename Monoid::TypeNode;\n    unsigned int x = 123456789, y = 362436069,\
    \ z = 521288629, w = 88675123;\n    unsigned int xor_shift() {\n        unsigned\
    \ int t = (x ^ (x << 11)); x = y; y = z; z = w;\n        return (w = (w ^ (w >>\
    \ 19)) ^ (t ^ (t >> 8)));\n    }\n    struct Node {\n    private:\n        void\
    \ build() {left = right = nullptr;size = 1; rev=0;}\n    public:\n        Node\
    \ *left, *right;\n        TypeNode value, range_value;\n        int size,rev;\n\
    \        Node() : value(Monoid::unit_node), range_value(Monoid::unit_node) {build();}\n\
    \        Node(TypeNode v) : value(v), range_value(v) {build();}\n        friend\
    \ ostream &operator<<(ostream &os, const Node* node) {return os << \"{\" << node->value\
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
    \ void operate_impl(Node *node, int k, TypeNode value) {\n        if(k < 0 ||\
    \ size(node) <= k) return;\n        int sl = size(node->left);\n        if(k <\
    \ sl) operate_impl(node->left,k,value);\n        else if(k==sl) node->value =\
    \ Monoid::func_operate(node->value,value);\n        else operate_impl(node->right,k-1-sl,value);\n\
    \        update(node);\n    }\n    inline TypeNode fold_impl(Node *node, int l,\
    \ int r) {\n        if (l < 0 || size(node) <= l || r<=0 || r-l <= 0) return Monoid::unit_node;\n\
    \        if (l == 0 && r == size(node)) return range_value(node);\n        TypeNode\
    \ value = Monoid::unit_node;\n        int sl = size(node->left);\n        if(sl\
    \ > l) value = Monoid::func_fold(value,fold_impl(node->left,l,min(sl,r)));\n \
    \       l = max(l-sl,0), r -= sl;\n        if(l == 0 && r > 0) value = Monoid::func_fold(value,node->value);\n\
    \        l = max(l-1,0), r -= 1;\n        if(l >= 0 && r > l) value = Monoid::func_fold(value,fold_impl(node->right,l,r));\n\
    \        return value;\n    }\n    inline void insert_impl(const size_t k, const\
    \ TypeNode value) {\n        pair<Node*, Node*> sub = split_impl(this->root, k);\n\
    \        this->root = this->merge_impl(this->merge_impl(sub.first, new Node(value)),\
    \ sub.second);\n    }\n    inline void erase_impl(const size_t k) {\n        if(size(this->root)\
    \ <= k) return;\n        auto sub = split_impl(this->root,k);\n        this->root\
    \ = merge_impl(sub.first, split_impl(sub.second, 1).second);\n    }\npublic:\n\
    \    RandomizedBinarySearchTreeSequence() : root(nullptr) {}\n    inline int size()\
    \ {return size(this->root);}\n    inline int empty(void) {return bool(size()==0);}\n\
    \    inline Node* merge(Node *left, Node *right) {return merge_impl(left,right);}\n\
    \    inline pair<Node*, Node*> split(int k) {return split_impl(this->root,k);}\n\
    \    inline void insert(const size_t k, const TypeNode value) {insert_impl(k,value);}\n\
    \    inline void erase(const size_t k) {erase_impl(k);}\n    inline TypeNode get(size_t\
    \ k) {return get(this->root, k);}\n    inline void operate(const int k, const\
    \ TypeNode value) {operate_impl(this->root,k,value);}\n    inline TypeNode fold(int\
    \ l, int r) {return fold_impl(this->root,l,r);}\n    void print() {int m = size(this->root);\
    \ for(int i=0;i<m;++i) cout << get(i) << \" \\n\"[i==m-1];}\n};\n#line 10 \"test/binary-search-tree/RandomizedBinarySearchTreeSequence-insert-erase.test.cpp\"\
    \n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    RandomizedBinarySearchTreeSequence<MonoidRangeMinPointUpdate<long\
    \ long>> lbst;\n    int N,Q; cin >> N >> Q;\n    for(int i=0;i<N;++i) {\n    \
    \    int a; cin >> a;\n        lbst.insert(i,a);\n    }\n    while(Q--) {\n  \
    \      int x,y,z; cin >> x >> y >> z;\n        if(x==0) {\n            auto w\
    \ = lbst.get(z);\n            lbst.erase(z);\n            lbst.insert(y,w);\n\
    \        }\n        if(x==1) {\n            cout << lbst.fold(y,z+1) << \"\\n\"\
    ;\n        }\n        if(x==2) {\n            lbst.operate(y,z);\n        }\n\
    \    }\n    return 0; \n}\n\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <queue>\n\
    using namespace std;\n#include \"../../lib/operator/monoid/MonoidRangeMinPointUpdate.cpp\"\
    \n#include \"../../lib/binary-search-tree/RandomizedBinarySearchTreeSequence.cpp\"\
    \n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    RandomizedBinarySearchTreeSequence<MonoidRangeMinPointUpdate<long\
    \ long>> lbst;\n    int N,Q; cin >> N >> Q;\n    for(int i=0;i<N;++i) {\n    \
    \    int a; cin >> a;\n        lbst.insert(i,a);\n    }\n    while(Q--) {\n  \
    \      int x,y,z; cin >> x >> y >> z;\n        if(x==0) {\n            auto w\
    \ = lbst.get(z);\n            lbst.erase(z);\n            lbst.insert(y,w);\n\
    \        }\n        if(x==1) {\n            cout << lbst.fold(y,z+1) << \"\\n\"\
    ;\n        }\n        if(x==2) {\n            lbst.operate(y,z);\n        }\n\
    \    }\n    return 0; \n}\n\n"
  dependsOn:
  - lib/operator/monoid/MonoidRangeMinPointUpdate.cpp
  - lib/binary-search-tree/RandomizedBinarySearchTreeSequence.cpp
  isVerificationFile: true
  path: test/binary-search-tree/RandomizedBinarySearchTreeSequence-insert-erase.test.cpp
  requiredBy: []
  timestamp: '2023-05-29 03:23:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/binary-search-tree/RandomizedBinarySearchTreeSequence-insert-erase.test.cpp
layout: document
redirect_from:
- /verify/test/binary-search-tree/RandomizedBinarySearchTreeSequence-insert-erase.test.cpp
- /verify/test/binary-search-tree/RandomizedBinarySearchTreeSequence-insert-erase.test.cpp.html
title: test/binary-search-tree/RandomizedBinarySearchTreeSequence-insert-erase.test.cpp
---
