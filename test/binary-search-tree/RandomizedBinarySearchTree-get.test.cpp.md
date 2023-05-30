---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/12-binary-search-tree/RandomizedBinarySearchTree.cpp
    title: "RandomizedBinarySearchTree - \u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728"
  - icon: ':question:'
    path: lib/99-operator/monoid/MonoidRangeSumPointAdd.cpp
    title: "MonoidRangeSumPointAdd - [\u533A\u9593\u548C, \u4E00\u70B9\u52A0\u7B97\
      ]"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/649
    links:
    - https://yukicoder.me/problems/no/649
  bundledCode: "#line 1 \"test/binary-search-tree/RandomizedBinarySearchTree-get.test.cpp\"\
    \n#define PROBLEM \"https://yukicoder.me/problems/no/649\"\n\n#include <vector>\n\
    #include <iostream>\n#include <unordered_map>\n#include <algorithm>\n#include\
    \ <numeric>\n#include <cmath>\nusing namespace std;\n#line 1 \"lib/12-binary-search-tree/RandomizedBinarySearchTree.cpp\"\
    \n/*\n * @title RandomizedBinarySearchTree - \u5E73\u8861\u4E8C\u5206\u63A2\u7D22\
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
    };\n#line 1 \"lib/99-operator/monoid/MonoidRangeSumPointAdd.cpp\"\n/*\n * @title\
    \ MonoidRangeSumPointAdd - [\u533A\u9593\u548C, \u4E00\u70B9\u52A0\u7B97]\n *\
    \ @docs md/operator/monoid/MonoidRangeSumPointAdd.md\n */\ntemplate<class T> struct\
    \ MonoidRangeSumPointAdd {\n    using TypeNode = T;\n    inline static constexpr\
    \ TypeNode unit_node = 0;\n    inline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return l+r;}\n    inline static constexpr TypeNode func_operate(TypeNode\
    \ l,TypeNode r){return l+r;}\n    inline static constexpr bool func_check(TypeNode\
    \ nodeVal,TypeNode var){return var == nodeVal;}\n};\n#line 12 \"test/binary-search-tree/RandomizedBinarySearchTree-get.test.cpp\"\
    \n\nint main(){\n    cin.tie(0);ios::sync_with_stdio(false);\n\tRandomizedBinarySearchTree<MonoidRangeSumPointAdd<long\
    \ long>> st;\n\tint Q,K; cin >> Q >> K;\n\twhile (Q--){\n\t\tint q; cin >> q;\n\
    \t\tif(q==1){\n\t\t\tlong long x; cin >> x;\n\t\t\tst.insert(x);\n\t\t}\n\t\t\
    else{\n\t\t\tlong long x=-1;\n\t\t\tif(st.size()>=K){\n\t\t\t\tx=st.get(K-1);\n\
    \t\t\t\tst.erase(x);\n\t\t\t}\n\t\t\tcout << x << endl;\n\t\t}\n\t}\n\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/649\"\n\n#include <vector>\n\
    #include <iostream>\n#include <unordered_map>\n#include <algorithm>\n#include\
    \ <numeric>\n#include <cmath>\nusing namespace std;\n#include \"../../lib/12-binary-search-tree/RandomizedBinarySearchTree.cpp\"\
    \n#include \"../../lib/99-operator/monoid/MonoidRangeSumPointAdd.cpp\"\n\nint\
    \ main(){\n    cin.tie(0);ios::sync_with_stdio(false);\n\tRandomizedBinarySearchTree<MonoidRangeSumPointAdd<long\
    \ long>> st;\n\tint Q,K; cin >> Q >> K;\n\twhile (Q--){\n\t\tint q; cin >> q;\n\
    \t\tif(q==1){\n\t\t\tlong long x; cin >> x;\n\t\t\tst.insert(x);\n\t\t}\n\t\t\
    else{\n\t\t\tlong long x=-1;\n\t\t\tif(st.size()>=K){\n\t\t\t\tx=st.get(K-1);\n\
    \t\t\t\tst.erase(x);\n\t\t\t}\n\t\t\tcout << x << endl;\n\t\t}\n\t}\n\n    return\
    \ 0;\n}"
  dependsOn:
  - lib/12-binary-search-tree/RandomizedBinarySearchTree.cpp
  - lib/99-operator/monoid/MonoidRangeSumPointAdd.cpp
  isVerificationFile: true
  path: test/binary-search-tree/RandomizedBinarySearchTree-get.test.cpp
  requiredBy: []
  timestamp: '2023-05-31 01:48:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/binary-search-tree/RandomizedBinarySearchTree-get.test.cpp
layout: document
redirect_from:
- /verify/test/binary-search-tree/RandomizedBinarySearchTree-get.test.cpp
- /verify/test/binary-search-tree/RandomizedBinarySearchTree-get.test.cpp.html
title: test/binary-search-tree/RandomizedBinarySearchTree-get.test.cpp
---
