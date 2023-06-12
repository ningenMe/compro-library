---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/00-util/FastIO.cpp
    title: FastIO
  - icon: ':heavy_check_mark:'
    path: lib/10-segment-tree/RangeFrequencyQueryTree.cpp
    title: "RangeFrequencyQueryTree - \u533A\u9593freq"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_frequency
    links:
    - https://judge.yosupo.jp/problem/static_range_frequency
  bundledCode: "#line 1 \"test/segment-tree/RangeFrequencyQueryTree-range-freq.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\n\
    \n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <algorithm>\n\
    #include <numeric>\nusing namespace std;\n\n#line 1 \"lib/00-util/FastIO.cpp\"\
    \n/*\n * @title FastIO\n * @docs md/util/FastIO.md\n */\nclass FastIO{\nprivate:\n\
    \    inline static constexpr int ch_0='0';\n    inline static constexpr int ch_9='9';\n\
    \    inline static constexpr int ch_n='-';\n    inline static constexpr int ch_s='\
    \ ';\n    inline static constexpr int ch_l='\\n';\n    inline static void endline_skip(char&\
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
    #line 1 \"lib/10-segment-tree/RangeFrequencyQueryTree.cpp\"\n/*\n * @title RangeFrequencyQueryTree\
    \ - \u533A\u9593freq\n * @docs md/segment-tree/RangeFrequencyQueryTree.md\n */\n\
    template<class T> class RangeFrequencyQueryTree {\n    template<class U> class\
    \ BinarySearchTreeSet {\n        unsigned int x = 123456789, y = 362436069, z\
    \ = 521288629, w = 88675123;\n        unsigned int xor_shift() {\n           \
    \ unsigned int t = (x ^ (x << 11)); x = y; y = z; z = w;\n            return (w\
    \ = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));\n        }\n        struct Node {\n   \
    \     private:\n            void build() {left = right = nullptr;size = 1;}\n\
    \        public:\n            Node *left, *right;\n            U value;\n    \
    \        int size;\n            Node() {build();}\n            Node(U v) : value(v)\
    \ {build();}\n            friend ostream &operator<<(ostream &os, const Node*\
    \ node) {return os << \"{\" << node->value << \", \" << node->range_value << \"\
    , \" << node->size << \"}\";}\n        };\n        Node* root;\n        inline\
    \ int size(Node *node) const {return node==nullptr ? 0 : node->size;}\n      \
    \  inline Node* update(Node *node) {\n            node->size = size(node->left)\
    \ + size(node->right) + 1;\n            return node;\n        }\n        inline\
    \ Node* merge_impl(Node *left, Node *right) {\n            if (left==nullptr)\
    \  return right;\n            if (right==nullptr) return left;\n            if\
    \ (xor_shift() % (left->size + right->size) < left->size) {\n                left->right\
    \ = merge_impl(left->right, right);\n                return update(left);\n  \
    \          }\n            else {\n                right->left = merge_impl(left,\
    \ right->left);\n                return update(right);\n            }\n      \
    \  }\n        inline pair<Node*, Node*> split_impl(Node* node, int k) {\n    \
    \        if (node==nullptr) return make_pair(nullptr, nullptr);\n            if\
    \ (k <= size(node->left)) {\n                pair<Node*, Node*> sub = split_impl(node->left,\
    \ k);\n                node->left = sub.second;\n                return make_pair(sub.first,\
    \ update(node));\n            }\n            else {\n                pair<Node*,\
    \ Node*> sub = split_impl(node->right, k - 1 - size(node->left));\n          \
    \      node->right = sub.first;\n                return make_pair(update(node),\
    \ sub.second);\n            }\n        }\n        inline int lower_bound(Node\
    \ *node, U value) const {\n            if (node==nullptr) return 0;\n        \
    \    if (value <= node->value) return lower_bound(node->left, value);\n      \
    \      else return size(node->left) + lower_bound(node->right, value) + 1;\n \
    \       }\n        inline int upper_bound(Node *node, U value) const {\n     \
    \       if (node==nullptr) return 0;\n            if (value < node->value) return\
    \ upper_bound(node->left, value);\n            else return size(node->left) +\
    \ upper_bound(node->right, value) + 1;\n        }\n        inline void insert_impl(const\
    \ U value) {\n            pair<Node*, Node*> sub = split_impl(this->root, lower_bound(this->root,value));\n\
    \            this->root = this->merge_impl(this->merge_impl(sub.first, new Node(value)),\
    \ sub.second);\n        }\n        inline void erase_impl(const U value) {\n \
    \           int k1 = lower_bound(value), k2 = upper_bound(value);\n          \
    \  if(k1==k2) return;\n            auto sub = split_impl(this->root,k1);\n   \
    \         this->root = merge_impl(sub.first, split_impl(sub.second, 1).second);\n\
    \        }\n    public:\n        BinarySearchTreeSet() : root(nullptr) {}\n  \
    \      inline int size() {return size(this->root);}\n        inline int empty(void)\
    \ {return bool(size()==0);}\n        inline Node* merge(Node *left, Node *right)\
    \ {return merge_impl(left,right);}\n        inline pair<Node*, Node*> split(int\
    \ k) {return split_impl(this->root,k);}\n        inline void insert(const U value)\
    \ {insert_impl(value);}\n        inline void erase(const U value) {erase_impl(value);}\n\
    \        inline int lower_bound(U value) const {return lower_bound(this->root,value);}\n\
    \        inline int upper_bound(U value) const {return upper_bound(this->root,value);}\n\
    \        inline int count(U value) const {return upper_bound(value) - lower_bound(value);}\n\
    \    };\n    size_t length;\n    size_t num;\n    vector<BinarySearchTreeSet<T>>\
    \ node;\n    void insert_impl(size_t idx, const T var) {\n        if(idx < 0 ||\
    \ length <= idx) return;\n        idx += length;\n        node[idx].insert(var);\n\
    \        while(idx >>= 1) node[idx].insert(var);\n    }\n    void erase_impl(size_t\
    \ idx, const T var) {\n        if(idx < 0 || length <= idx) return;\n        idx\
    \ += length;\n        node[idx].erase(var);\n        while(idx >>= 1) node[idx].erase(var);\n\
    \    }\n    int range_freq_upper_impl(int l, int r, const T upper) const {\n \
    \       if (l < 0 || length <= l || r < 0 || length < r) return 0;\n        int\
    \ ret=0;\n        for(l += length, r += length; l < r; l >>=1, r >>=1) {\n   \
    \         if(l&1) ret += node[l++].lower_bound(upper);\n            if(r&1) ret\
    \ += node[--r].lower_bound(upper);\n        }\n        return ret;\n    }\n  \
    \  int range_freq_impl(int l, int r, const T val) const {\n        if (l < 0 ||\
    \ length <= l || r < 0 || length < r) return 0;\n        int ret=0;\n        for(l\
    \ += length, r += length; l < r; l >>=1, r >>=1) {\n            if(l&1) ret +=\
    \ node[l++].count(val);\n            if(r&1) ret += node[--r].count(val);\n  \
    \      }\n        return ret;\n    }\npublic:\n    //unit\u3067\u521D\u671F\u5316\
    \n    RangeFrequencyQueryTree(const vector<T> & vec) {\n        for (length =\
    \ 1; length <= vec.size(); length *= 2);\n        node.resize(2 * length, BinarySearchTreeSet<T>());\n\
    \        for (int i=0; i < vec.size(); ++i) {\n            insert_impl(i, vec[i]);\n\
    \        }\n    }\n    //idx\u756A\u76EE\u306E\u8981\u7D20\u3092update\n    void\
    \ update(const size_t idx, const T var) { erase_impl(idx, var); insert_impl(idx,\
    \ var);}\n    //[l,r) range freq of val (val < upper)\n    int range_freq_upper(const\
    \ int l, const int r, const T upper) const {return range_freq_upper_impl(l,r,upper);}\n\
    \    //[l,r) range freq of val (lower <= val < upper)\n    int range_freq_lower_upper(const\
    \ int l, const int r, const T lower, const T upper) const {return range_freq_upper_impl(l,r,upper)\
    \ - range_freq_upper_impl(l,r,lower);}\n    //[l,r) range freq of val\n    int\
    \ range_freq(const int l, const int r, const T val) const {return range_freq_impl(l,r,val);}\n\
    };\n#line 12 \"test/segment-tree/RangeFrequencyQueryTree-range-freq.test.cpp\"\
    \n\nint main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; read(N);\
    \ read(Q);\n    vector<long long> A(N);\n    for(int i=0;i<N;++i) read(A[i]);\n\
    \    RangeFrequencyQueryTree<long long> rfqt(A);\n    while(Q--) {\n        int\
    \ l,r,k; read(l); read(r); read(k);\n\t\tcout << rfqt.range_freq(l,r,k) << \"\\\
    n\";\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <algorithm>\n\
    #include <numeric>\nusing namespace std;\n\n#include \"../../lib/00-util/FastIO.cpp\"\
    \n#include \"../../lib/10-segment-tree/RangeFrequencyQueryTree.cpp\"\n\nint main()\
    \ {\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; read(N); read(Q);\n\
    \    vector<long long> A(N);\n    for(int i=0;i<N;++i) read(A[i]);\n    RangeFrequencyQueryTree<long\
    \ long> rfqt(A);\n    while(Q--) {\n        int l,r,k; read(l); read(r); read(k);\n\
    \t\tcout << rfqt.range_freq(l,r,k) << \"\\n\";\n    }\n    return 0;\n}"
  dependsOn:
  - lib/00-util/FastIO.cpp
  - lib/10-segment-tree/RangeFrequencyQueryTree.cpp
  isVerificationFile: true
  path: test/segment-tree/RangeFrequencyQueryTree-range-freq.test.cpp
  requiredBy: []
  timestamp: '2023-06-13 05:45:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segment-tree/RangeFrequencyQueryTree-range-freq.test.cpp
layout: document
redirect_from:
- /verify/test/segment-tree/RangeFrequencyQueryTree-range-freq.test.cpp
- /verify/test/segment-tree/RangeFrequencyQueryTree-range-freq.test.cpp.html
title: test/segment-tree/RangeFrequencyQueryTree-range-freq.test.cpp
---
