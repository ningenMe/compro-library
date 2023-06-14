---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/segment-tree/IntegerRangeFrequencyQueryTree.md
    document_title: "IntegerRangeFrequencyQueryTree - integer\u5C02\u7528\u533A\u9593\
      freq"
    links: []
  bundledCode: "#line 1 \"lib/10-segment-tree/IntegerRangeFrequencyQueryTree.cpp\"\
    \n/*\n * @title IntegerRangeFrequencyQueryTree - integer\u5C02\u7528\u533A\u9593\
    freq\n * @docs md/segment-tree/IntegerRangeFrequencyQueryTree.md\n */\ntemplate<unsigned\
    \ int bit_length=20> class IntegerRangeFrequencyQueryTree {\n    using u64 = unsigned\
    \ long long;\n    class SimpleBinaryTrie {\n        struct Node {\n          \
    \  Node *left, *right;\n            u64 size;\n            Node(): size(0) {left=right=nullptr;}\n\
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
    };\n"
  code: "/*\n * @title IntegerRangeFrequencyQueryTree - integer\u5C02\u7528\u533A\u9593\
    freq\n * @docs md/segment-tree/IntegerRangeFrequencyQueryTree.md\n */\ntemplate<unsigned\
    \ int bit_length=20> class IntegerRangeFrequencyQueryTree {\n    using u64 = unsigned\
    \ long long;\n    class SimpleBinaryTrie {\n        struct Node {\n          \
    \  Node *left, *right;\n            u64 size;\n            Node(): size(0) {left=right=nullptr;}\n\
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
    };"
  dependsOn: []
  isVerificationFile: false
  path: lib/10-segment-tree/IntegerRangeFrequencyQueryTree.cpp
  requiredBy: []
  timestamp: '2023-06-14 05:14:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/10-segment-tree/IntegerRangeFrequencyQueryTree.cpp
layout: document
redirect_from:
- /library/lib/10-segment-tree/IntegerRangeFrequencyQueryTree.cpp
- /library/lib/10-segment-tree/IntegerRangeFrequencyQueryTree.cpp.html
title: "IntegerRangeFrequencyQueryTree - integer\u5C02\u7528\u533A\u9593freq"
---
### IntegerRangeFrequencyQueryTree
- 区間の中の値の頻度クエリを答えるセグ木
- unsigned integer専用
- 更新も対応できるはず (verifyできてない)
- セグメント木に、BinaryTrieを載せている log2個で定数倍重め。
- 値の更新がないならwavelet matrixを使うのが良い。


### メソッド
- IntegerRangeFrequencyQueryTree(const vector<T> & vec) 
  - コンストラクタ。列を渡す
- void update(const size_t idx, const T var)
  - 値を更新
- int range_freq_upper(const int l, const int r, const T upper) 
  - [l,r) の範囲の中で、upperより小さい要素の数を返す
- int range_freq_lower_upper(const int l, const int r, const T lower, const T upper)
  - [l,r) の範囲の中で、lower以上、upperより小さい要素の数を返す [lower, upper)
- int range_freq(const int l, const int r, const T val)
  - [l,r) の範囲の中で、valに等しい要素の数を返す

- 補足
  - [提出](https://atcoder.jp/contests/abc202/submissions/42244987)
