---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/binary-search-tree/RandomizedBinarySearchTree.cpp
    title: "RandomizedBinarySearchTree - \u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728"
  - icon: ':heavy_check_mark:'
    path: lib/data-structure/convex-hull-trick/ConvexHullTrick.cpp
    title: "ConvexHullTrick - \u975E\u5358\u8ABFCHT"
  - icon: ':heavy_check_mark:'
    path: lib/operator/operator/ValueMin.cpp
    title: lib/operator/operator/ValueMin.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"test/data-structure/convex-hull-trick/ConvexHullTrick-no-monotone.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n#include\
    \ <iostream>\n#include <vector>\n#include <queue>\nusing namespace std;\n#line\
    \ 1 \"lib/binary-search-tree/RandomizedBinarySearchTree.cpp\"\n/*\n * @title RandomizedBinarySearchTree\
    \ - \u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728\n * @docs md/binary-search-tree/RandomizedBinarySearchTree.md\n\
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
    };\n#line 1 \"lib/operator/operator/ValueMin.cpp\"\n//\u6700\u5C0F\u5024\u30AF\
    \u30A8\u30EA\ntemplate<class T> struct ValueMin {\n\tusing TypeValue = T;\n\t\
    inline static constexpr TypeValue unit_value = 3e18;\n\tinline static constexpr\
    \ bool func_compare(TypeValue l,TypeValue r){return l<r;}\n};\n#line 1 \"lib/data-structure/convex-hull-trick/ConvexHullTrick.cpp\"\
    \n/*\n * @title ConvexHullTrick - \u975E\u5358\u8ABFCHT\n * @docs md/data-structure/convex-hull-trick/ConvexHullTrick.md\n\
    \ */\ntemplate<class Operator> class ConvexHullTrick {\nprivate:\n    using TypeValue\
    \ = typename Operator::TypeValue;\n    using Line = pair<TypeValue,TypeValue>;\n\
    \    struct Monoid {\n        using TypeNode = Line;\n        inline static constexpr\
    \ TypeNode unit_node = {0,0};\n        inline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return {0,0};}\n    };\n    RandomizedBinarySearchTree<Monoid>\
    \ lines;\n\n    //3\u76F4\u7DDA\u306B\u95A2\u3057\u3066line2\u304C\u5FC5\u8981\
    \u304B\u78BA\u8A8D (\u3053\u306E\u3068\u304D a1 < a2 < a3\u304C\u5FC5\u8981=rbst\u306E\
    \u9806\u305D\u306E\u307E\u307E)\n    inline int is_required(const Line& line1,\
    \ const Line& line2, const Line& line3) {\n        return Operator::func_compare((line2.second-line3.second)*(line2.first-line1.first),(line1.second-line2.second)*(line3.first-line2.first));\n\
    \    }\n\n    //y=ax+b\u306E\u5024\n    inline TypeValue y(const Line line, TypeValue\
    \ x) {\n        return line.first * x + line.second;\n    }\n\npublic:\n    ConvexHullTrick()\
    \ {\n        // do nothing\n    }\n\n    //ax+b\u3092\u8FFD\u52A0\n    void insert(const\
    \ TypeValue a, const TypeValue b) {\n        insert({a,b});\n    }\n    //ax+b\u3092\
    \u8FFD\u52A0 armortized O(log(N))\n    void insert(const Line line) {\n      \
    \  int k=lines.lower_bound(line), flg=1;\n        Line l,r;\n        if(0 <= k-1)\
    \ {\n            l = lines.get(k-1);\n            //l\u3068\u50BE\u304D\u304C\u540C\
    \u3058\u306A\u3089\u3001\u3069\u3061\u3089\u304B\u3092erase\n            if(l.first==line.first)\
    \ {\n                if(Operator::func_compare(l.second,line.second)) return;\n\
    \                else lines.erase(l);\n            }\n        }\n        if(k\
    \ < lines.size()) {\n            r = lines.get(k);\n            //r\u3068\u50BE\
    \u304D\u304C\u540C\u3058\u306A\u3089\u3001\u3069\u3061\u3089\u304B\u3092erase\n\
    \            if(r.first==line.first) {\n                if(Operator::func_compare(r.second,line.second))\
    \ return;\n                else lines.erase(r);\n            }\n        }\n  \
    \      //\u81EA\u8EAB\u304C\u5FC5\u8981\u304B\u5224\u5B9A\n        if(0 <= k-1\
    \ && k < lines.size() && !is_required(l,line,r)) return;\n        //\u50BE\u304D\
    \u304C\u5C0F\u3055\u3044\u5074\u306E\u4E0D\u5FC5\u8981\u306A\u76F4\u7DDA\u3092\
    \u53D6\u308A\u9664\u304F\n        for(k=lines.lower_bound(line);k>=2&&!is_required(lines.get(k-2),\
    \ lines.get(k-1), line);k=lines.lower_bound(line)) lines.erase(lines.get(k-1));\n\
    \        //\u50BE\u304D\u304C\u5927\u304D\u3044\u5074\u306E\u4E0D\u5FC5\u8981\u306A\
    \u76F4\u7DDA\u3092\u53D6\u308A\u9664\u304F\n        for(k=lines.lower_bound(line);k+1<lines.size()&&!is_required(line,lines.get(k),lines.get(k+1));k=lines.lower_bound(line))\
    \ lines.erase(lines.get(k));\n        lines.insert(line);\n    }\n\n    //O(log(N)^2)\n\
    \    TypeValue get(TypeValue x) {\n        int ng = -1, ok = (int)lines.size()-1,\
    \ md;\n        while (ok - ng > 1) {\n            md = (ok + ng) >> 1;\n     \
    \       ( Operator::func_compare(y(lines.get(md),x),y(lines.get(md+1),x)) ?ok:ng)=md;\n\
    \        }\n        return y(lines.get(ok),x);\n    }\n\n    //O(log(N)^2)\n \
    \   Line get_line(TypeValue x) {\n        int ng = -1, ok = (int)lines.size()-1,\
    \ md;\n        while (ok - ng > 1) {\n            md = (ok + ng) >> 1;\n     \
    \       ( Operator::func_compare(y(lines.get(md),x),y(lines.get(md+1),x)) ?ok:ng)=md;\n\
    \        }\n        return lines.get(ok);\n    }\n\n    void print() {\n     \
    \   lines.print();\n    }\n};\n#line 10 \"test/data-structure/convex-hull-trick/ConvexHullTrick-no-monotone.test.cpp\"\
    \n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; cin\
    \ >> N >> Q;\n\tConvexHullTrick<ValueMin<__int128_t>> cht;\n\twhile(N--){\n\t\t\
    long long a,b; cin >> a >> b;\n\t\tcht.insert(a,b);\n\t}\n\twhile(Q--){\n\t\t\
    int q; cin >> q;\n\t\tif(q){\n\t\t\tlong long p; cin >> p;\n\t\t\tlong long ans\
    \ = cht.get(p);\n\t\t\tcout << ans << endl;\n\t\t}\n\t\telse{\n\t\t\tlong long\
    \ a,b; cin >> a >> b;\n\t\t\tcht.insert(a,b);\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include <iostream>\n#include <vector>\n#include <queue>\nusing namespace std;\n\
    #include \"../../../lib/binary-search-tree/RandomizedBinarySearchTree.cpp\"\n\
    #include \"../../../lib/operator/operator/ValueMin.cpp\"\n#include \"../../../lib/data-structure/convex-hull-trick/ConvexHullTrick.cpp\"\
    \n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; cin\
    \ >> N >> Q;\n\tConvexHullTrick<ValueMin<__int128_t>> cht;\n\twhile(N--){\n\t\t\
    long long a,b; cin >> a >> b;\n\t\tcht.insert(a,b);\n\t}\n\twhile(Q--){\n\t\t\
    int q; cin >> q;\n\t\tif(q){\n\t\t\tlong long p; cin >> p;\n\t\t\tlong long ans\
    \ = cht.get(p);\n\t\t\tcout << ans << endl;\n\t\t}\n\t\telse{\n\t\t\tlong long\
    \ a,b; cin >> a >> b;\n\t\t\tcht.insert(a,b);\n\t\t}\n\t}\n\treturn 0;\n}"
  dependsOn:
  - lib/binary-search-tree/RandomizedBinarySearchTree.cpp
  - lib/operator/operator/ValueMin.cpp
  - lib/data-structure/convex-hull-trick/ConvexHullTrick.cpp
  isVerificationFile: true
  path: test/data-structure/convex-hull-trick/ConvexHullTrick-no-monotone.test.cpp
  requiredBy: []
  timestamp: '2023-05-29 04:58:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/convex-hull-trick/ConvexHullTrick-no-monotone.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/convex-hull-trick/ConvexHullTrick-no-monotone.test.cpp
- /verify/test/data-structure/convex-hull-trick/ConvexHullTrick-no-monotone.test.cpp.html
title: test/data-structure/convex-hull-trick/ConvexHullTrick-no-monotone.test.cpp
---
