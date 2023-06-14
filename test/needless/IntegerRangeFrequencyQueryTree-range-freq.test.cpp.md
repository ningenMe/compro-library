---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/00-util/FastIO.cpp
    title: FastIO
  - icon: ':heavy_check_mark:'
    path: lib/98-needless/IntegerRangeFrequencyQueryTree.cpp
    title: "IntegerRangeFrequencyQueryTree - integer\u5C02\u7528\u533A\u9593freq"
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
  bundledCode: "#line 1 \"test/needless/IntegerRangeFrequencyQueryTree-range-freq.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\n\
    \n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <algorithm>\n\
    #include <numeric>\n#include <stack>\nusing namespace std;\n\n#line 1 \"lib/00-util/FastIO.cpp\"\
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
    #line 1 \"lib/98-needless/IntegerRangeFrequencyQueryTree.cpp\"\n/*\n * @title\
    \ IntegerRangeFrequencyQueryTree - integer\u5C02\u7528\u533A\u9593freq\n * @docs\
    \ md/needless/IntegerRangeFrequencyQueryTree.md\n */\ntemplate<unsigned int bit_length=20>\
    \ class IntegerRangeFrequencyQueryTree {\n    using u64 = unsigned long long;\n\
    \    class SimpleBinaryTrie {\n        struct Node {\n            Node *left,\
    \ *right;\n            u64 size;\n            Node(): size(0) {left=right=nullptr;}\n\
    \        };\n        Node* root;\n        size_t size(Node* node) const {return\
    \ (node==nullptr ? 0 : node->size);}\n        bool empty(Node* node) const {return\
    \ size(node) == 0;}\n        void print(Node* node,u64 i, u64 val) {\n       \
    \     if(i == bit_length) {\n                cout << \"{\" << val << \":\" <<\
    \ size(node) << \":\" << size(node->left) << \":\" << size(node->right) << \"\
    } \";\n                return;\n            }\n            if(node->left != nullptr)\
    \ {\n                print(node->left, i+1, val);\n            }\n           \
    \ if(node->right != nullptr) {\n                print(node->right, i+1, (val |\
    \ (1UL<<(bit_length-1-i))) );\n            }\n        }\n    public:\n       \
    \ SimpleBinaryTrie(): root(new Node()) {}\n        void insert(const u64 val)\
    \ {\n            Node* curr = root; stack<Node*> st;\n            for(u64 i=0;\
    \ i < bit_length; ++i) {\n                u64 j = ((val>>(bit_length-1-i)) & 1UL);\n\
    \                st.push(curr);\n                if(j) {\n                   \
    \ if(curr->right != nullptr) { curr = curr->right;}\n                    else\
    \ {\n                        Node* next = new Node();\n                      \
    \  curr->right = next;\n                        curr = next;\n               \
    \     }\n                }\n                else {\n                    if(curr->left\
    \ != nullptr) curr = curr->left;\n                    else {\n               \
    \         Node* next = new Node();\n                        curr->left = next;\n\
    \                        curr = next;\n                    }\n               \
    \ }\n            }\n            curr->size += 1;\n            while(st.size())\
    \ {\n                auto node=st.top(); st.pop();\n                node->size\
    \ = size(node->left) + size(node->right);\n            }\n        }\n        void\
    \ erase(const u64 val) {\n            Node* curr = root; stack<Node*> st;\n  \
    \          for(u64 i=0; i < bit_length; ++i) {\n                u64 j = ((val>>(bit_length-1-i))\
    \ & 1UL);\n                st.push(curr);\n                if(j) {\n         \
    \           if(curr->right != nullptr) curr = curr->right;\n                 \
    \   else return;\n                }\n                else {\n                \
    \    if(curr->left != nullptr) curr = curr->left;\n                    else return;\n\
    \                }\n            }\n            if(empty(curr)) return;\n     \
    \       curr->size -= 1;\n            while(st.size()) {\n                auto\
    \ node=st.top(); st.pop();\n                node->size = size(node->left) + size(node->right);\n\
    \            }\n        }\n        size_t size() const {return size(root);}\n\
    \        bool empty() const {return empty(root);}\n        u64 kth_smallest(u64\
    \ k) const {\n            Node* curr = root; u64 val=0;\n            for(u64 i=0;\
    \ i < bit_length; ++i) {\n                u64 j = 1UL << (bit_length-1-i);\n \
    \               u64 sz_l = size(curr->left);\n                if(k<sz_l) curr\
    \ = curr->left;\n                else {\n                    val |= j;\n     \
    \               k -= sz_l;\n                    curr = curr->right;\n        \
    \        }\n            }\n            return val;\n        }\n        size_t\
    \ lower_bound(const u64 val) const {\n            Node* curr = root;\n       \
    \     u64 k=0;\n            for(u64 i=0; i < bit_length; ++i) {\n            \
    \    u64 j = ((val>>(bit_length-1-i)) & 1UL);\n                if(j) {\n     \
    \               k+=size(curr->left);\n                    if(curr->right != nullptr)\
    \ curr = curr->right;\n                    else break;\n                }\n  \
    \              else {\n                    if(curr->left != nullptr) curr = curr->left;\n\
    \                    else break;\n                }\n            }\n         \
    \   return k;\n        }\n        size_t count(const u64 val) const {\n      \
    \      Node* curr = root;\n            for(u64 i=0; i < bit_length; ++i) {\n \
    \               u64 j = ((val>>(bit_length-1-i)) & 1);\n                if(j)\
    \ {\n                    if(curr->right != nullptr) curr = curr->right;\n    \
    \                else return 0;\n                }\n                else {\n \
    \                   if(curr->left != nullptr) curr = curr->left;\n           \
    \         else return 0;\n                }\n            }\n            return\
    \ size(curr);\n        }\n        void print() {\n            cout << \"{\"; print(root,0,0);\
    \ cout << \"}\" << endl;\n        }\n    };\n    size_t length;\n    size_t num;\n\
    \    vector<SimpleBinaryTrie> node;\n    void insert_impl(size_t idx, const u64\
    \ val) {\n        if(idx < 0 || length <= idx) return;\n        idx += length;\n\
    \        node[idx].insert(val);\n        while(idx >>= 1) node[idx].insert(val);\n\
    \    }\n    void erase_impl(size_t idx) {\n        if(idx < 0 || length <= idx)\
    \ return;\n        idx += length;\n        if(node[idx].empty()) return;\n   \
    \     u64 val = node[idx].kth_smallest(0);\n        node[idx].erase(val);\n  \
    \      while(idx >>= 1) node[idx].erase(val);\n    }\n    int range_freq_upper_impl(int\
    \ l, int r, const u64 upper) const {\n        if (l < 0 || length <= l || r <\
    \ 0 || length < r) return 0;\n        int ret=0;\n        for(l += length, r +=\
    \ length; l < r; l >>=1, r >>=1) {\n            if(l&1) ret += node[l++].lower_bound(upper);\n\
    \            if(r&1) ret += node[--r].lower_bound(upper);\n        }\n       \
    \ return ret;\n    }\n    int range_freq_impl(int l, int r, const u64 val) const\
    \ {\n        if (l < 0 || length <= l || r < 0 || length < r) return 0;\n    \
    \    int ret=0;\n        for(l += length, r += length; l < r; l >>=1, r >>=1)\
    \ {\n            if(l&1) ret += node[l++].count(val);\n            if(r&1) ret\
    \ += node[--r].count(val);\n        }\n        return ret;\n    }\npublic:\n \
    \   IntegerRangeFrequencyQueryTree(const u64 num) {\n        for (length = 1;\
    \ length <= num; length *= 2);\n        node.resize(2 * length);\n    }\n    IntegerRangeFrequencyQueryTree(const\
    \ vector<u64> & vec) {\n        for (length = 1; length <= vec.size(); length\
    \ *= 2);\n        node.resize(2 * length);\n        for (int i=0; i < vec.size();\
    \ ++i) {\n            update(i, vec[i]);\n        }\n    }\n    //idx\u756A\u76EE\
    \u306E\u8981\u7D20\u3092update\n    void update(const size_t idx, const u64 val)\
    \ { erase_impl(idx); insert_impl(idx, val);}\n    //idx\u756A\u76EE\u306E\u8981\
    \u7D20\u3092erase\n    void erase(const size_t idx) { erase_impl(idx); }\n   \
    \ //[l,r) range freq of val (val < upper)\n    int range_freq_upper(const int\
    \ l, const int r, const u64 upper) const {return range_freq_upper_impl(l,r,upper);}\n\
    \    //[l,r) range freq of val (lower <= val < upper)\n    int range_freq_lower_upper(const\
    \ int l, const int r, const u64 lower, const u64 upper) const { return range_freq_upper_impl(l,r,upper)\
    \ - range_freq_upper_impl(l,r,lower);}\n    //[l,r) range freq of val\n    int\
    \ range_freq(const int l, const int r, const u64 val) const {return range_freq_impl(l,r,val);}\n\
    \    void print() { for(int i= length; i < 2*length; ++i) node[i].print();}\n\
    };\n#line 13 \"test/needless/IntegerRangeFrequencyQueryTree-range-freq.test.cpp\"\
    \n\nint main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; read(N);\
    \ read(Q);\n    vector<unsigned long long> A(N);\n    for(int i=0;i<N;++i) read(A[i]);\n\
    \    IntegerRangeFrequencyQueryTree<30> rfqt(A);\n    while(Q--) {\n        int\
    \ l,r,k; read(l); read(r); read(k);\n\t\tcout << rfqt.range_freq(l,r,k) << \"\\\
    n\";\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\
    \n\n#include <vector>\n#include <iostream>\n#include <cassert>\n#include <algorithm>\n\
    #include <numeric>\n#include <stack>\nusing namespace std;\n\n#include \"../../lib/00-util/FastIO.cpp\"\
    \n#include \"../../lib/98-needless/IntegerRangeFrequencyQueryTree.cpp\"\n\nint\
    \ main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N,Q; read(N);\
    \ read(Q);\n    vector<unsigned long long> A(N);\n    for(int i=0;i<N;++i) read(A[i]);\n\
    \    IntegerRangeFrequencyQueryTree<30> rfqt(A);\n    while(Q--) {\n        int\
    \ l,r,k; read(l); read(r); read(k);\n\t\tcout << rfqt.range_freq(l,r,k) << \"\\\
    n\";\n    }\n    return 0;\n}"
  dependsOn:
  - lib/00-util/FastIO.cpp
  - lib/98-needless/IntegerRangeFrequencyQueryTree.cpp
  isVerificationFile: true
  path: test/needless/IntegerRangeFrequencyQueryTree-range-freq.test.cpp
  requiredBy: []
  timestamp: '2023-06-15 04:20:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/needless/IntegerRangeFrequencyQueryTree-range-freq.test.cpp
layout: document
redirect_from:
- /verify/test/needless/IntegerRangeFrequencyQueryTree-range-freq.test.cpp
- /verify/test/needless/IntegerRangeFrequencyQueryTree-range-freq.test.cpp.html
title: test/needless/IntegerRangeFrequencyQueryTree-range-freq.test.cpp
---
