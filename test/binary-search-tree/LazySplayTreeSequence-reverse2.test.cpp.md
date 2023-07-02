---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/00-util/FastIO.cpp
    title: FastIO
  - icon: ':heavy_check_mark:'
    path: lib/12-binary-search-tree/LazySplayTreeSequence.cpp
    title: "LazySplayTreeSequence - \u9045\u5EF6\u8A55\u4FA1SplayTree\u5217"
  - icon: ':heavy_check_mark:'
    path: lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAdd.cpp
    title: "MonoidRangeSumRangeAdd - fold:\u533A\u9593\u548C, opearate:\u533A\u9593\
      \u52A0\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_reverse_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_reverse_range_sum
  bundledCode: "#line 1 \"test/binary-search-tree/LazySplayTreeSequence-reverse2.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_reverse_range_sum\"\n\
    \n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <queue>\n\
    using namespace std;\n#line 1 \"lib/00-util/FastIO.cpp\"\n/*\n * @title FastIO\n\
    \ * @docs md/util/FastIO.md\n */\nclass FastIO{\nprivate:\n    inline static constexpr\
    \ int ch_0='0';\n    inline static constexpr int ch_9='9';\n    inline static\
    \ constexpr int ch_n='-';\n    inline static constexpr int ch_s=' ';\n    inline\
    \ static constexpr int ch_l='\\n';\n    inline static void endline_skip(char&\
    \ ch) {\n        while(ch==ch_l) ch=getchar();\n    }\n    template<typename T>\
    \ inline static void read_integer(T &x) {\n        int neg=0; char ch; x=0;\n\
    \        ch=getchar();\n        endline_skip(ch);\n        if(ch==ch_n) neg=1,ch=getchar();\n\
    \        for(;(ch_0 <= ch && ch <= ch_9); ch = getchar()) x = x*10 + (ch-ch_0);\n\
    \        if(neg) x*=-1;\n    }\n    template<typename T> inline static void read_unsigned_integer(T\
    \ &x) {\n        char ch; x=0;\n        ch=getchar();\n        endline_skip(ch);\n\
    \        for(;(ch_0 <= ch && ch <= ch_9); ch = getchar()) x = x*10 + (ch-ch_0);\n\
    \    }\n    inline static void read_string(string &x) {\n        char ch; x=\"\
    \";\n        ch=getchar();\n        endline_skip(ch);\n        for(;(ch != ch_s\
    \ && ch!=ch_l); ch = getchar()) x.push_back(ch);\n    }\n    inline static char\
    \ ar[40];\n    inline static char *ch_ar;\n    template<typename T> inline static\
    \ void write_integer(T x) {\n        ch_ar=ar;\n        if(x< 0) putchar(ch_n),\
    \ x=-x;\n        if(x==0) putchar(ch_0);\n        for(;x;x/=10) *ch_ar++=(ch_0+x%10);\n\
    \        while(ch_ar--!=ar) putchar(*ch_ar);\n    }\npublic:\n    inline static\
    \ void read(int &x) {read_integer<int>(x);}\n    inline static void read(long\
    \ long &x) {read_integer<long long>(x);}\n    inline static void read(unsigned\
    \ int &x) {read_unsigned_integer<unsigned int>(x);}\n    inline static void read(unsigned\
    \ long long &x) {read_unsigned_integer<unsigned long long>(x);}\n    inline static\
    \ void read(string &x) {read_string(x);}\n    inline static void read(__int128_t\
    \ &x) {read_integer<__int128_t>(x);}\n    inline static void write(__int128_t\
    \ x) {write_integer<__int128_t>(x);}\n    inline static void write(char x) {putchar(x);}\n\
    };\n#define read(arg) FastIO::read(arg)\n#define write(arg) FastIO::write(arg)\n\
    #line 1 \"lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAdd.cpp\"\n\
    /*\n * @title MonoidRangeSumRangeAdd - fold:\u533A\u9593\u548C, opearate:\u533A\
    \u9593\u52A0\u7B97\n * @docs md/operator/monoid-lazy/MonoidRangeSumRangeAdd.md\n\
    \ */\ntemplate<class T, class U> struct MonoidRangeFoldSumRangeOperateAdd {\n\t\
    using TypeNode = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode\
    \ unit_node = 0;\n\tinline static constexpr TypeLazy unit_lazy = 0;\n\tinline\
    \ static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return l+r;}\n\t\
    inline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return\
    \ old_lazy+new_lazy;}\n\tinline static constexpr TypeNode func_operate(TypeNode\
    \ node,TypeLazy lazy,int l, int r){return node+lazy*(r-l);}\n\tinline static constexpr\
    \ bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}\n};\n\
    #line 1 \"lib/12-binary-search-tree/LazySplayTreeSequence.cpp\"\n/*\n * @title\
    \ LazySplayTreeSequence - \u9045\u5EF6\u8A55\u4FA1SplayTree\u5217\n * @docs md/binary-search-tree/LazySplayTreeSequence.md\n\
    \ */\ntemplate<class Monoid> class LazySplayTreeSequence {\n    using TypeNode\
    \ = typename Monoid::TypeNode;\n    using TypeLazy = typename Monoid::TypeLazy;\n\
    \    struct Node {\n    public:\n        Node *left, *right;\n        TypeNode\
    \ value, range_value;\n        TypeLazy range_lazy;\n        int rev;\n      \
    \  int size;\n        Node(const TypeNode v) : left(nullptr),right(nullptr),value(v),range_value(v),range_lazy(Monoid::unit_lazy),size(1),rev(0)\
    \ {}\n        friend ostream &operator<<(ostream &os, const Node* node) {return\
    \ os << \"{\" << node->value << \", \" << node->size << \"}\";}\n    };\n    struct\
    \ TupleNode {\n        Node *left, *center, *right;\n        TupleNode(Node *left,Node\
    \ *center,Node *right) : left(left), center(center), right(right) {}\n    };\n\
    \    Node* root;\n    inline int size(Node *node) {return node==nullptr ? 0 :\
    \ node->size;}\n    inline TypeNode range_value(Node *node) {return node==nullptr\
    \ ? Monoid::unit_node : node->range_value;}\n    inline void update(Node *node)\
    \ {\n        node->size = 1;\n        node->range_value = node->value;\n\t\tif(node->left\
    \ != nullptr) {\n            node->size = node->left->size + node->size;\n   \
    \         node->range_value = Monoid::func_fold(node->left->range_value, node->range_value);\n\
    \        }\n\t\tif(node->right != nullptr) {\n            node->size = node->size\
    \ + node->right->size;\n            node->range_value = Monoid::func_fold(node->range_value,\
    \ node->right->range_value);\n        }\n    }\n    inline void propagate(Node\
    \ *node) {\n        if(node==nullptr) return;\n        if(node->range_lazy !=\
    \ Monoid::unit_lazy) {\n            if(node->left  != nullptr) sync_lazy(node->left,\
    \ node->range_lazy);\n            if(node->right != nullptr) sync_lazy(node->right,\
    \ node->range_lazy);\n            node->range_lazy = Monoid::unit_lazy;\n    \
    \    }\n        if(node->rev) {\n            if(node->left  != nullptr) sync_rev(node->left);\n\
    \            if(node->right != nullptr) sync_rev(node->right);\n            node->rev\
    \ = 0;\n        }\n    }\n    inline void sync_lazy(Node *node, const TypeLazy\
    \ lazy) {\n        node->range_lazy = Monoid::func_lazy(node->range_lazy, lazy);\n\
    \        node->value = Monoid::func_operate(node->value, lazy, 0,1);\n       \
    \ node->range_value = Monoid::func_operate(node->range_value, lazy, 0, node->size);\n\
    \    }\n    inline void sync_rev(Node *node) {\n        swap(node->left, node->right);\n\
    \        node->rev ^= 1;\n    }\n    inline Node* rotate_left(Node* node){\n \
    \       Node* right = node->right;\n        node->right = right->left;\n     \
    \   right->left = node;\n        update(node);\n        update(right);\n     \
    \   return right;\n    }\n    inline Node* rotate_right(Node* node){\n       \
    \ Node* left = node->left;\n        node->left = left->right;\n        left->right\
    \ = node;\n        update(node);\n        update(left);\n        return left;\n\
    \    }\n\n    inline Node* splay(Node* node, size_t k){\n        auto p = splay_inner(node,\
    \ k);\n        node = p.first;\n        auto last = p.second;\n        if(node->left\
    \ == last) return rotate_right(node);\n        else if(node->right == last) return\
    \ rotate_left(node);\n        return node;\n    }\n    inline pair<Node*,Node*>\
    \ splay_inner(Node* node, size_t k){\n        propagate(node);\n        size_t\
    \ sz_l = size(node->left);\n        if(k == sz_l) return {node, node};\n     \
    \   if(k < sz_l) {\n            auto p = splay_inner(node->left, k);\n       \
    \     node->left = p.first;\n            auto last = p.second;\n            update(node);\n\
    \            if(node->left == last) return {node, last};\n            if(node->left->left\
    \ == last) node = rotate_right(node);\n            else node->left = rotate_left(node->left);\n\
    \            return {rotate_right(node), last};\n        }\n        else {\n \
    \           auto p = splay_inner(node->right, k - sz_l - 1);\n            node->right\
    \ = p.first;\n            auto last = p.second;\n            update(node);\n \
    \           if(node->right == last) return {node, last};\n            if(node->right->right\
    \ == last) node = rotate_left(node);\n            else node->right = rotate_right(node->right);\n\
    \            return {rotate_left(node), last};\n        }\n    }\n\n    //\u975E\
    \u518D\u5E30\u306F\u9045\u304B\u3063\u305F\n    // stack<pair<Node*, size_t>>\
    \ st;\n    // inline Node* splay(Node* node, size_t k){\n    //     Node* t_node\
    \ = node;\n    //     Node* last = nullptr;\n    //     while(last == nullptr)\
    \ {\n    //         propagate(t_node);\n    //         size_t sz_l = size(t_node->left);\n\
    \    //         if(k == sz_l) {\n    //             last = t_node;\n    //   \
    \          continue;\n    //         }\n    //         if(k < sz_l) {\n    //\
    \             st.emplace(t_node, 1);\n    //             t_node = t_node->left;\n\
    \    //         }\n    //         else {\n    //             st.emplace(t_node,\
    \ 0);\n    //             t_node = t_node->right;\n    //             k = (k -\
    \ sz_l - 1);\n    //         }\n    //     }\n    //     while(st.size()) {\n\
    \    //         auto [t_node,is_left] = st.top(); st.pop();\n    //         if(is_left)\
    \ {\n    //             t_node->left = last;\n    //             t_node = rotate_right(t_node);\n\
    \    //         }\n    //         else {\n    //             t_node->right = last;\n\
    \    //             t_node = rotate_left(t_node);\n    //         }\n    //  \
    \       update(t_node);\n    //         last = t_node;\n    //     }\n    // \
    \    return last;\n    // }\n\n    //    - parent\n    //   |\n    // left\n \
    \   //\u306E\u5F62\u3067\u30DE\u30FC\u30B8\n    Node* merge(Node* left, Node*\
    \ parent) {\n        if(left == nullptr) return parent;\n        if(parent ==\
    \ nullptr) return left;\n        parent = splay(parent, 0);\n        parent->left\
    \ = left;\n        update(parent);\n        return parent;\n    }\n    Node* merge(TupleNode*\
    \ tuple_node) {\n        Node* node = merge(tuple_node->center, tuple_node->right);\n\
    \        if(tuple_node->left == nullptr) return node;\n        tuple_node->left->right\
    \ = node;\n        update(tuple_node->left);\n        return tuple_node->left;\n\
    \    }\n    // [0,k),[k,n) \u3067split\n    pair<Node*,Node*> split(Node* node,\
    \ size_t k) {\n        if(k >= size(node)) return {node, nullptr};\n        Node*\
    \ right = splay(node, k);\n        Node* left = right->left;\n        right->left\
    \ = nullptr;\n        update(right);\n        return {left, right};\n    }\n \
    \   //[0,l),[l,r),[r,n) \u3067split\n    TupleNode* split(Node* node, size_t l,\
    \ size_t r) {\n        if(!l) {\n            auto [center,right] = split(node,\
    \ r);\n            return new TupleNode(nullptr, center, right);\n        }\n\
    \        Node* left = splay(node, l-1);\n        auto [center, right] = split(left->right,\
    \ r-l);\n        left->right = nullptr;\n        update(left);\n        return\
    \ new TupleNode(left, center, right);\n    }\n    void insert_impl(const size_t\
    \ k, const TypeNode value) {\n        Node* new_node = new Node(value);\n    \
    \    if(k == size(root)){\n            new_node->left = root;\n            update(new_node);\n\
    \            root = new_node;\n            return;\n        }\n        if(k ==\
    \ 0){\n            new_node->right = root;\n            update(new_node);\n  \
    \          root = new_node;\n            return;\n        }\n        Node* node\
    \ = splay(root, k);\n        new_node->left = node->left;\n        node->left\
    \ = new_node;\n        update(new_node);\n        update(node);\n        root\
    \ = node;\n        return;\n    }\n    void erase_impl(const size_t k){\n    \
    \    Node* node = splay(root, k);\n        root = merge(node->left,node->right);\n\
    \    }\n    TypeNode fold_impl(int l, int r) {\n        if (l < 0 || size(root)\
    \ <= l || r<=0 || r-l <= 0) return Monoid::unit_node;\n\t\tTupleNode* tuple_node\
    \ = split(root,l,r);\n        TypeNode res = tuple_node->center->range_value;\n\
    \        root = merge(tuple_node);\n        return res;\n    }\n    void operate_impl(int\
    \ l, int r, TypeLazy lazy) {\n        if(l < 0 || size(root) <= l || r <= 0 ||\
    \ r-l <= 0) return;\n\t\tTupleNode* tuple_node = split(root,l,r);\n        sync_lazy(tuple_node->center,\
    \ lazy);\n        root = merge(tuple_node);\n    }\n    void reverse_impl(int\
    \ l, int r) {\n        if (l < 0 || size(root) <= l || r<=0 || r-l <= 0) return;\n\
    \t\tTupleNode* tuple_node = split(root,l,r);\n        sync_rev(tuple_node->center);\n\
    \        root = merge(tuple_node);\n    }\n    void print_impl() {\n        size_t\
    \ N = size(root);\n        for(int i=0;i<N;++i) cout << get(i) << \" \";\n   \
    \     cout << endl;\n    }\npublic:\n    LazySplayTreeSequence(): root(nullptr)\
    \ {}\n    inline TypeNode get(const size_t k) {root = splay(root , k); return\
    \ root->value; }\n    inline int size() {return size(root); }\n    inline void\
    \ insert(const size_t k, const TypeNode value) {insert_impl(k,value);}\n    inline\
    \ void erase(const size_t k) { erase_impl(k);}\n    inline void operate(const\
    \ int l, const int r, const TypeLazy lazy) {operate_impl(l,r,lazy);}\n    inline\
    \ TypeNode fold(int l, int r) {return fold_impl(l,r); }\n    inline void reverse(int\
    \ l, int r) {reverse_impl(l,r);}\n    void print() {print_impl();}\n};\n#line\
    \ 11 \"test/binary-search-tree/LazySplayTreeSequence-reverse2.test.cpp\"\n\nint\
    \ main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; read(N);\
    \ read(Q);\n    LazySplayTreeSequence<MonoidRangeFoldSumRangeOperateAdd<long long,long\
    \ long>> st;\n    for(int i=0;i<N;++i) {\n        int a; read(a); st.insert(i,a);\n\
    \    }\n    while(Q--) {\n        int q; read(q);\n        int l,r; read(l); read(r);\n\
    \        if(q==0) {\n            st.reverse(l,r);\n        }\n        if(q==1)\
    \ {\n            cout << st.fold(l,r) << \"\\n\";\n        }\n    }\n    return\
    \ 0;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_reverse_range_sum\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <queue>\n\
    using namespace std;\n#include \"../../lib/00-util/FastIO.cpp\"\n#include \"../../lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAdd.cpp\"\
    \n#include \"../../lib/12-binary-search-tree/LazySplayTreeSequence.cpp\"\n\nint\
    \ main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; read(N);\
    \ read(Q);\n    LazySplayTreeSequence<MonoidRangeFoldSumRangeOperateAdd<long long,long\
    \ long>> st;\n    for(int i=0;i<N;++i) {\n        int a; read(a); st.insert(i,a);\n\
    \    }\n    while(Q--) {\n        int q; read(q);\n        int l,r; read(l); read(r);\n\
    \        if(q==0) {\n            st.reverse(l,r);\n        }\n        if(q==1)\
    \ {\n            cout << st.fold(l,r) << \"\\n\";\n        }\n    }\n    return\
    \ 0;\n}\n\n"
  dependsOn:
  - lib/00-util/FastIO.cpp
  - lib/99-operator/monoid-lazy/MonoidRangeFoldSumRangeOperateAdd.cpp
  - lib/12-binary-search-tree/LazySplayTreeSequence.cpp
  isVerificationFile: true
  path: test/binary-search-tree/LazySplayTreeSequence-reverse2.test.cpp
  requiredBy: []
  timestamp: '2023-07-02 22:00:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/binary-search-tree/LazySplayTreeSequence-reverse2.test.cpp
layout: document
redirect_from:
- /verify/test/binary-search-tree/LazySplayTreeSequence-reverse2.test.cpp
- /verify/test/binary-search-tree/LazySplayTreeSequence-reverse2.test.cpp.html
title: test/binary-search-tree/LazySplayTreeSequence-reverse2.test.cpp
---
