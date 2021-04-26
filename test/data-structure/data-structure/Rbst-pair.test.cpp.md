---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data-structure/data-structure/Rbst.cpp
    title: "Rbst - \u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728"
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
  bundledCode: "#line 1 \"test/data-structure/data-structure/Rbst-pair.test.cpp\"\n\
    #define PROBLEM \"https://yukicoder.me/problems/no/822\"\n\n#include <vector>\n\
    #include <iostream>\n#include <unordered_map>\n#include <algorithm>\n#include\
    \ <numeric>\n#include <cmath>\nusing namespace std;\n#line 1 \"lib/data-structure/data-structure/Rbst.cpp\"\
    \n/*\n * @title Rbst - \u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728\n * @docs md/segment/Rbst.md\n\
    \ */\ntemplate<class Operator> class Rbst {\n\tusing TypeNode = typename Operator::TypeNode;\n\
    \tunsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;\n\t\
    unsigned int xor_shift() {\n\t\tunsigned int t = (x ^ (x << 11)); x = y; y = z;\
    \ z = w;\n\t\treturn (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));\n\t}\n\tstruct Node\
    \ {\n\t\tNode *left, *right;\n\t\tTypeNode val;\n\t\tint size;\n\t\tTypeNode sum;\n\
    \n\t\tNode() : val(Operator::unit_node), size(1), sum(Operator::unit_node) {\n\
    \t\t\tleft = right = nullptr;\n\t\t}\n\t\tNode(TypeNode v) : val(v), size(1),\
    \ sum(v) {\n\t\t\tleft = right = nullptr;\n\t\t}\n\t};\n\tNode* root;\n\tinline\
    \ int size(Node *node) {\n\t\treturn node==nullptr ? 0 : node->size;\n\t}\n\t\
    inline TypeNode sum(Node *node) {\n\t\treturn node==nullptr ? Operator::unit_node\
    \ : node->sum;\n\t}\n\tinline Node* update(Node *node) {\n\t\tnode->size = size(node->left)\
    \ + size(node->right) + 1;\n\t\tnode->sum = Operator::func_node(sum(node->left),sum(node->right),node->val);\n\
    \t\treturn node;\n\t}\n\tinline TypeNode get(Node *node, int k) {\n\t\tif (node==nullptr)\
    \ return Operator::unit_node;\n\t\tif (k == size(node->left)) return node->val;\n\
    \t\tif (k < size(node->left)) return get(node->left, k);\n\t\telse return get(node->right,\
    \ k-1 - size(node->left));\n\t}\n\tinline int lower_bound(Node *node, TypeNode\
    \ val) {\n\t\tif (node==nullptr) return 0;\n\t\tif (val <= node->val) return lower_bound(node->left,\
    \ val);\n\t\telse return size(node->left) + lower_bound(node->right, val) + 1;\n\
    \t}\n\tinline int upper_bound(Node *node, TypeNode val) {\n\t\tif (node==nullptr)\
    \ return 0;\n\t\tif (val >= node->val) return size(node->left) + upper_bound(node->right,\
    \ val) + 1;\n\t\telse return upper_bound(node->left, val);\n\t}\n\tNode* merge(Node\
    \ *left, Node *right) {\n\t\tif (left==nullptr)  return right;\n\t\tif (right==nullptr)\
    \ return left;\n\t\tif (xor_shift() % (left->size + right->size) < left->size)\
    \ {\n\t\t\tleft->right = merge(left->right, right);\n\t\t\treturn update(left);\n\
    \t\t}\n\t\telse {\n\t\t\tright->left = merge(left, right->left);\n\t\t\treturn\
    \ update(right);\n\t\t}\n\t}\n\tpair<Node*, Node*> split(Node* node, int k) {\n\
    \t\tif (node==nullptr) return make_pair(node, node);\n\t\tif (k <= size(node->left))\
    \ {\n\t\t\tpair<Node*, Node*> sub = split(node->left, k);\n\t\t\tnode->left =\
    \ sub.second;\n\t\t\treturn make_pair(sub.first, update(node));\n\t\t}\n\t\telse\
    \ {\n\t\t\tpair<Node*, Node*> sub = split(node->right, k-1 - size(node->left));\n\
    \t\t\tnode->right = sub.first;\n\t\t\treturn make_pair(update(node), sub.second);\n\
    \t\t}\n\t}\n\tvoid print(Node *node) {\n\t\tif (node==nullptr) return;\n\t\tprint(node->left);\n\
    \t\tcout << node->val << \" \";\n\t\tprint(node->right);\n\t}\n\tRbst(Node* node):root(node){}\n\
    public:\n\tRbst() : root(nullptr) {}\n\tinline int size() {\n\t\treturn size(this->root);\n\
    \t}\n\tinline TypeNode sum() {\n\t\treturn sum(this->root);\n\t}\n\tinline int\
    \ lower_bound(TypeNode val) {\n\t\treturn lower_bound(this->root, val);\n\t}\n\
    \tinline int upper_bound(TypeNode val) {\n\t\treturn upper_bound(this->root, val);\n\
    \t}\n\tinline int empty(void) {\n\t\treturn bool(size()==0);\n\t}\n\tinline int\
    \ count(TypeNode val) {\n\t\treturn upper_bound(val) - lower_bound(val);\n\t}\n\
    \tinline TypeNode get(int k) {\n\t\treturn get(this->root, k);\n\t}\n\tinline\
    \ TypeNode get_median() {\n\t\t//\u5947\u6570\u306E\u6642N/2\n\t\treturn get(this->root,\
    \ (size()-1)/2);\n\t}\n\tvoid merge(Rbst another) {\n\t\troot = merge(this->root,\
    \ another.root);\n\t}\n\tvoid insert(const TypeNode val) {\n\t\tpair<Node*, Node*>\
    \ sub = split(this->root, this->lower_bound(val));\n\t\tthis->root = this->merge(this->merge(sub.first,\
    \ new Node(val)), sub.second);\n\t}\n\tvoid erase(const TypeNode val) {\n\t\t\
    if (!this->count(val)) return;\n\t\tpair<Node*, Node*> sub = this->split(this->root,\
    \ this->lower_bound(val));\n\t\tthis->root = this->merge(sub.first, this->split(sub.second,\
    \ 1).second);\n\t}\n\tvoid print() {\n\t\tcout << \"{\";\n\t\tprint(this->root);\n\
    \t\tcout << \"}\" << endl;\n\t}\n};\n//https://atcoder.jp/contests/abc154/tasks/abc154_c\n\
    //https://atcoder.jp/contests/arc033/tasks/arc033_3\n//https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_c\n\
    //https://yukicoder.me/problems/no/919\n//https://yukicoder.me/problems/no/649\n\
    //https://yukicoder.me/problems/no/822\n\ntemplate<class T> struct NodeSum {\n\
    \tusing TypeNode = T;\n\tinline static constexpr TypeNode unit_node = 0;\n\tinline\
    \ static constexpr TypeNode func_node(TypeNode l,TypeNode c,TypeNode r){return\
    \ l+c+r;}\n};\n\ntemplate<class T> struct NodeSimple {\n\tusing TypeNode = T;\n\
    \tinline static constexpr TypeNode unit_node = 0;\n\tinline static constexpr TypeNode\
    \ func_node(TypeNode l,TypeNode c,TypeNode r){return 0;}\n};\n#line 11 \"test/data-structure/data-structure/Rbst-pair.test.cpp\"\
    \n\ntemplate<class T> struct NodePair {\n\tusing TypeNode = T;\n\tinline static\
    \ constexpr TypeNode unit_node = {0,0};\n\tinline static constexpr TypeNode func_node(TypeNode\
    \ l,TypeNode c,TypeNode r){return {0,0};}\n};\n\nint main() {\n    int N,K; cin\
    \ >> N >> K;\n    if(N+1 <= K){\n\t\tcout << \"INF\" << endl;\n\t\treturn 0;\n\
    \t}\n    Rbst<NodePair<pair<int,int>>> st;\n    for(int i = 0; i < (1<<20); ++i)\
    \ {\n        if((i&N) != N) continue;\n        for(int j = -K; j <= K; ++j) {\n\
    \            int a = i, b = i + j;\n            if(a>b) swap(a,b);\n         \
    \   if(0<=b && b-a<=K && ((a&b)==N) && !st.count({a,b})) st.insert({a,b});\n \
    \       }\n    }\n    cout << st.size() << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/822\"\n\n#include <vector>\n\
    #include <iostream>\n#include <unordered_map>\n#include <algorithm>\n#include\
    \ <numeric>\n#include <cmath>\nusing namespace std;\n#include \"../../../lib/data-structure/data-structure/Rbst.cpp\"\
    \n\ntemplate<class T> struct NodePair {\n\tusing TypeNode = T;\n\tinline static\
    \ constexpr TypeNode unit_node = {0,0};\n\tinline static constexpr TypeNode func_node(TypeNode\
    \ l,TypeNode c,TypeNode r){return {0,0};}\n};\n\nint main() {\n    int N,K; cin\
    \ >> N >> K;\n    if(N+1 <= K){\n\t\tcout << \"INF\" << endl;\n\t\treturn 0;\n\
    \t}\n    Rbst<NodePair<pair<int,int>>> st;\n    for(int i = 0; i < (1<<20); ++i)\
    \ {\n        if((i&N) != N) continue;\n        for(int j = -K; j <= K; ++j) {\n\
    \            int a = i, b = i + j;\n            if(a>b) swap(a,b);\n         \
    \   if(0<=b && b-a<=K && ((a&b)==N) && !st.count({a,b})) st.insert({a,b});\n \
    \       }\n    }\n    cout << st.size() << endl;\n    return 0;\n}\n"
  dependsOn:
  - lib/data-structure/data-structure/Rbst.cpp
  isVerificationFile: true
  path: test/data-structure/data-structure/Rbst-pair.test.cpp
  requiredBy: []
  timestamp: '2021-04-26 18:11:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/data-structure/Rbst-pair.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/data-structure/Rbst-pair.test.cpp
- /verify/test/data-structure/data-structure/Rbst-pair.test.cpp.html
title: test/data-structure/data-structure/Rbst-pair.test.cpp
---
