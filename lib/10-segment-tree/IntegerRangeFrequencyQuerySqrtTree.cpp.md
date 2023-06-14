---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/segment-tree/IntegerRangeFrequencyQuerySqrtTree-range-freq.test.cpp
    title: test/segment-tree/IntegerRangeFrequencyQuerySqrtTree-range-freq.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/segment-tree/IntegerRangeFrequencyQuerySqrtTree.md
    document_title: "IntegerRangeFrequencyQuerySqrtTree - integer\u5C02\u7528\u533A\
      \u9593freq"
    links: []
  bundledCode: "#line 1 \"lib/10-segment-tree/IntegerRangeFrequencyQuerySqrtTree.cpp\"\
    \n/*\n * @title IntegerRangeFrequencyQuerySqrtTree - integer\u5C02\u7528\u533A\
    \u9593freq\n * @docs md/segment-tree/IntegerRangeFrequencyQuerySqrtTree.md\n */\n\
    template<unsigned int bit_length=20> class IntegerRangeFrequencyQuerySqrtTree\
    \ {\n    using u64 = unsigned long long;\n    class SimpleBinaryTrie {\n     \
    \   struct Node {\n            Node *left, *right;\n            u64 size;\n  \
    \          Node(): size(0) {left=right=nullptr;}\n        };\n        Node* root;\n\
    \        size_t size(Node* node) const {return (node==nullptr ? 0 : node->size);}\n\
    \        bool empty(Node* node) const {return size(node) == 0;}\n        void\
    \ print(Node* node,u64 i, u64 val) {\n            if(i == bit_length) {\n    \
    \            cout << \"{\" << val << \":\" << size(node) << \"} \";\n        \
    \        return;\n            }\n            if(node->left != nullptr) {\n   \
    \             print(node->left, i+1, val);\n            }\n            if(node->right\
    \ != nullptr) {\n                print(node->right, i+1, (val | (1UL<<(bit_length-1-i)))\
    \ );\n            }\n        }\n    public:\n        SimpleBinaryTrie(): root(new\
    \ Node()) {}\n        void insert(const u64 val) {\n            Node* curr = root;\
    \ stack<Node*> st;\n            for(u64 i=0; i < bit_length; ++i) {\n        \
    \        u64 j = ((val>>(bit_length-1-i)) & 1UL);\n                st.push(curr);\n\
    \                if(j) {\n                    if(curr->right != nullptr) { curr\
    \ = curr->right;}\n                    else {\n                        Node* next\
    \ = new Node();\n                        curr->right = next;\n               \
    \         curr = next;\n                    }\n                }\n           \
    \     else {\n                    if(curr->left != nullptr) curr = curr->left;\n\
    \                    else {\n                        Node* next = new Node();\n\
    \                        curr->left = next;\n                        curr = next;\n\
    \                    }\n                }\n            }\n            curr->size\
    \ += 1;\n            while(st.size()) {\n                auto node=st.top(); st.pop();\n\
    \                node->size = size(node->left) + size(node->right);\n        \
    \    }\n        }\n        void erase(const u64 val) {\n            Node* curr\
    \ = root; stack<Node*> st;\n            for(u64 i=0; i < bit_length; ++i) {\n\
    \                u64 j = ((val>>(bit_length-1-i)) & 1UL);\n                st.push(curr);\n\
    \                if(j) {\n                    if(curr->right != nullptr) curr\
    \ = curr->right;\n                    else return;\n                }\n      \
    \          else {\n                    if(curr->left != nullptr) curr = curr->left;\n\
    \                    else return;\n                }\n            }\n        \
    \    if(empty(curr)) return;\n            curr->size -= 1;\n            while(st.size())\
    \ {\n                auto node=st.top(); st.pop();\n                node->size\
    \ = size(node->left) + size(node->right);\n            }\n        }\n        size_t\
    \ size() const {return size(root);}\n        bool empty() const {return empty(root);}\n\
    \        u64 kth_smallest(u64 k) const {\n            Node* curr = root; u64 val=0;\n\
    \            for(u64 i=0; i < bit_length; ++i) {\n                u64 j = 1UL\
    \ << (bit_length-1-i);\n                u64 sz_l = size(curr->left);\n       \
    \         if(k<sz_l) curr = curr->left;\n                else {\n            \
    \        val |= j;\n                    k -= sz_l;\n                    curr =\
    \ curr->right;\n                }\n            }\n            return val;\n  \
    \      }\n        size_t lower_bound(const u64 val) const {\n            Node*\
    \ curr = root;\n            u64 k=0;\n            for(u64 i=0; i < bit_length;\
    \ ++i) {\n                u64 j = ((val>>(bit_length-1-i)) & 1UL);\n         \
    \       if(j) {\n                    k+=size(curr->left);\n                  \
    \  if(curr->right != nullptr) curr = curr->right;\n                    else break;\n\
    \                }\n                else {\n                    if(curr->left\
    \ != nullptr) curr = curr->left;\n                    else break;\n          \
    \      }\n            }\n            return k;\n        }\n        size_t count(const\
    \ u64 val) const {\n            Node* curr = root;\n            for(u64 i=0; i\
    \ < bit_length; ++i) {\n                u64 j = ((val>>(bit_length-1-i)) & 1);\n\
    \                if(j) {\n                    if(curr->right != nullptr) curr\
    \ = curr->right;\n                    else return 0;\n                }\n    \
    \            else {\n                    if(curr->left != nullptr) curr = curr->left;\n\
    \                    else return 0;\n                }\n            }\n      \
    \      return size(curr);\n        }\n        void print() {\n            cout\
    \ << \"{\"; print(root,0,0); cout << \"} \";\n        }\n    };\n    size_t length;\n\
    \    size_t bucket_size;\n    vector<SimpleBinaryTrie> node0;\n    vector<u64>\
    \ node1;\n    inline static constexpr u64 inf = 1UL << bit_length;\n    void insert_impl(size_t\
    \ idx, const u64 val) {\n        if(idx < 0 || length <= idx) return;\n      \
    \  node0[idx/bucket_size].insert(val);\n        node1[idx]=val;\n    }\n    void\
    \ erase_impl(size_t idx) {\n        if(idx < 0 || length <= idx) return;\n   \
    \     if(node1[idx]==inf) return;\n        u64 val = node1[idx];\n        node0[idx/bucket_size].erase(val);\n\
    \        node1[idx]=inf;\n    }\n    int range_freq_upper_impl(int l, int r, const\
    \ u64 upper) const {\n        if (l < 0 || length <= l || r < 0 || length < r)\
    \ return 0;\n\n        int ret=0;\n        if(r-l <= bucket_size) {\n        \
    \    for(int i=l; i<r; ++i) ret += (node1[i] < upper);\n            return ret;\
    \         \n        }\n        int bl0 = l / bucket_size + !!(l%bucket_size),\
    \ br0 = r / bucket_size;\n        int bl1 = bl0 * bucket_size, br1 = br0 * bucket_size;\n\
    \n        for(int i=l; i < min(bl1,r); ++i) ret += (node1[i] < upper);\n     \
    \   for(int i=bl0; i < br0; ++i) ret += node0[i].lower_bound(upper);\n       \
    \ for(int i=max(br1,l); i < r; ++i) ret += (node1[i] < upper);\n\n        return\
    \ ret;\n    }\n    int range_freq_impl(int l, int r, const u64 val) const {\n\
    \        if (l < 0 || length <= l || r < 0 || length < r) return 0;\n        int\
    \ ret=0;\n        if(r-l <= bucket_size) {\n            for(int i=l; i<r; ++i)\
    \ ret += (node1[i] == val);\n            return ret;         \n        }\n   \
    \     int bl0 = l / bucket_size + !!(l%bucket_size), br0 = r / bucket_size;\n\
    \        int bl1 = bl0 * bucket_size, br1 = br0 * bucket_size;\n\n        for(int\
    \ i=l; i < min(bl1,r); ++i) ret += (node1[i] == val);\n        for(int i=bl0;\
    \ i < br0; ++i) ret += node0[i].count(val);\n        for(int i=max(br1,l); i <\
    \ r; ++i) ret += (node1[i] == val);\n\n        return ret;\n    }\npublic:\n \
    \   IntegerRangeFrequencyQuerySqrtTree(const u64 length): length(length), node1(length,inf)\
    \ {\n        bucket_size = 5*sqrt(length);\n        if(!bucket_size) bucket_size=1;\n\
    \        node0.resize(length / bucket_size + 1);\n    }\n    //idx\u756A\u76EE\
    \u306E\u8981\u7D20\u3092update\n    void update(const size_t idx, const u64 val)\
    \ { erase_impl(idx); insert_impl(idx, val);}\n    //idx\u756A\u76EE\u306E\u8981\
    \u7D20\u3092erase\n    void erase(const size_t idx) { erase_impl(idx); }\n   \
    \ //[l,r) range freq of val (val < upper)\n    int range_freq_upper(const int\
    \ l, const int r, const u64 upper) const {return range_freq_upper_impl(l,r,upper);}\n\
    \    //[l,r) range freq of val (lower <= val < upper)\n    int range_freq_lower_upper(const\
    \ int l, const int r, const u64 lower, const u64 upper) const { return range_freq_upper_impl(l,r,upper)\
    \ - range_freq_upper_impl(l,r,lower);}\n    //[l,r) range freq of val\n    int\
    \ range_freq(const int l, const int r, const u64 val) const {return range_freq_impl(l,r,val);}\n\
    \    void print() { \n        cout << length << \" \" << bucket_size << endl;\n\
    \        for(int i= 0; i < length / bucket_size + 1; ++i) node0[i].print();\n\
    \        cout << endl;\n        for(int i= 0; i < length; ++i) cout << node1[i]\
    \ << \" \\n\"[i==length-1];\n        cout << endl;\n    }\n};\n"
  code: "/*\n * @title IntegerRangeFrequencyQuerySqrtTree - integer\u5C02\u7528\u533A\
    \u9593freq\n * @docs md/segment-tree/IntegerRangeFrequencyQuerySqrtTree.md\n */\n\
    template<unsigned int bit_length=20> class IntegerRangeFrequencyQuerySqrtTree\
    \ {\n    using u64 = unsigned long long;\n    class SimpleBinaryTrie {\n     \
    \   struct Node {\n            Node *left, *right;\n            u64 size;\n  \
    \          Node(): size(0) {left=right=nullptr;}\n        };\n        Node* root;\n\
    \        size_t size(Node* node) const {return (node==nullptr ? 0 : node->size);}\n\
    \        bool empty(Node* node) const {return size(node) == 0;}\n        void\
    \ print(Node* node,u64 i, u64 val) {\n            if(i == bit_length) {\n    \
    \            cout << \"{\" << val << \":\" << size(node) << \"} \";\n        \
    \        return;\n            }\n            if(node->left != nullptr) {\n   \
    \             print(node->left, i+1, val);\n            }\n            if(node->right\
    \ != nullptr) {\n                print(node->right, i+1, (val | (1UL<<(bit_length-1-i)))\
    \ );\n            }\n        }\n    public:\n        SimpleBinaryTrie(): root(new\
    \ Node()) {}\n        void insert(const u64 val) {\n            Node* curr = root;\
    \ stack<Node*> st;\n            for(u64 i=0; i < bit_length; ++i) {\n        \
    \        u64 j = ((val>>(bit_length-1-i)) & 1UL);\n                st.push(curr);\n\
    \                if(j) {\n                    if(curr->right != nullptr) { curr\
    \ = curr->right;}\n                    else {\n                        Node* next\
    \ = new Node();\n                        curr->right = next;\n               \
    \         curr = next;\n                    }\n                }\n           \
    \     else {\n                    if(curr->left != nullptr) curr = curr->left;\n\
    \                    else {\n                        Node* next = new Node();\n\
    \                        curr->left = next;\n                        curr = next;\n\
    \                    }\n                }\n            }\n            curr->size\
    \ += 1;\n            while(st.size()) {\n                auto node=st.top(); st.pop();\n\
    \                node->size = size(node->left) + size(node->right);\n        \
    \    }\n        }\n        void erase(const u64 val) {\n            Node* curr\
    \ = root; stack<Node*> st;\n            for(u64 i=0; i < bit_length; ++i) {\n\
    \                u64 j = ((val>>(bit_length-1-i)) & 1UL);\n                st.push(curr);\n\
    \                if(j) {\n                    if(curr->right != nullptr) curr\
    \ = curr->right;\n                    else return;\n                }\n      \
    \          else {\n                    if(curr->left != nullptr) curr = curr->left;\n\
    \                    else return;\n                }\n            }\n        \
    \    if(empty(curr)) return;\n            curr->size -= 1;\n            while(st.size())\
    \ {\n                auto node=st.top(); st.pop();\n                node->size\
    \ = size(node->left) + size(node->right);\n            }\n        }\n        size_t\
    \ size() const {return size(root);}\n        bool empty() const {return empty(root);}\n\
    \        u64 kth_smallest(u64 k) const {\n            Node* curr = root; u64 val=0;\n\
    \            for(u64 i=0; i < bit_length; ++i) {\n                u64 j = 1UL\
    \ << (bit_length-1-i);\n                u64 sz_l = size(curr->left);\n       \
    \         if(k<sz_l) curr = curr->left;\n                else {\n            \
    \        val |= j;\n                    k -= sz_l;\n                    curr =\
    \ curr->right;\n                }\n            }\n            return val;\n  \
    \      }\n        size_t lower_bound(const u64 val) const {\n            Node*\
    \ curr = root;\n            u64 k=0;\n            for(u64 i=0; i < bit_length;\
    \ ++i) {\n                u64 j = ((val>>(bit_length-1-i)) & 1UL);\n         \
    \       if(j) {\n                    k+=size(curr->left);\n                  \
    \  if(curr->right != nullptr) curr = curr->right;\n                    else break;\n\
    \                }\n                else {\n                    if(curr->left\
    \ != nullptr) curr = curr->left;\n                    else break;\n          \
    \      }\n            }\n            return k;\n        }\n        size_t count(const\
    \ u64 val) const {\n            Node* curr = root;\n            for(u64 i=0; i\
    \ < bit_length; ++i) {\n                u64 j = ((val>>(bit_length-1-i)) & 1);\n\
    \                if(j) {\n                    if(curr->right != nullptr) curr\
    \ = curr->right;\n                    else return 0;\n                }\n    \
    \            else {\n                    if(curr->left != nullptr) curr = curr->left;\n\
    \                    else return 0;\n                }\n            }\n      \
    \      return size(curr);\n        }\n        void print() {\n            cout\
    \ << \"{\"; print(root,0,0); cout << \"} \";\n        }\n    };\n    size_t length;\n\
    \    size_t bucket_size;\n    vector<SimpleBinaryTrie> node0;\n    vector<u64>\
    \ node1;\n    inline static constexpr u64 inf = 1UL << bit_length;\n    void insert_impl(size_t\
    \ idx, const u64 val) {\n        if(idx < 0 || length <= idx) return;\n      \
    \  node0[idx/bucket_size].insert(val);\n        node1[idx]=val;\n    }\n    void\
    \ erase_impl(size_t idx) {\n        if(idx < 0 || length <= idx) return;\n   \
    \     if(node1[idx]==inf) return;\n        u64 val = node1[idx];\n        node0[idx/bucket_size].erase(val);\n\
    \        node1[idx]=inf;\n    }\n    int range_freq_upper_impl(int l, int r, const\
    \ u64 upper) const {\n        if (l < 0 || length <= l || r < 0 || length < r)\
    \ return 0;\n\n        int ret=0;\n        if(r-l <= bucket_size) {\n        \
    \    for(int i=l; i<r; ++i) ret += (node1[i] < upper);\n            return ret;\
    \         \n        }\n        int bl0 = l / bucket_size + !!(l%bucket_size),\
    \ br0 = r / bucket_size;\n        int bl1 = bl0 * bucket_size, br1 = br0 * bucket_size;\n\
    \n        for(int i=l; i < min(bl1,r); ++i) ret += (node1[i] < upper);\n     \
    \   for(int i=bl0; i < br0; ++i) ret += node0[i].lower_bound(upper);\n       \
    \ for(int i=max(br1,l); i < r; ++i) ret += (node1[i] < upper);\n\n        return\
    \ ret;\n    }\n    int range_freq_impl(int l, int r, const u64 val) const {\n\
    \        if (l < 0 || length <= l || r < 0 || length < r) return 0;\n        int\
    \ ret=0;\n        if(r-l <= bucket_size) {\n            for(int i=l; i<r; ++i)\
    \ ret += (node1[i] == val);\n            return ret;         \n        }\n   \
    \     int bl0 = l / bucket_size + !!(l%bucket_size), br0 = r / bucket_size;\n\
    \        int bl1 = bl0 * bucket_size, br1 = br0 * bucket_size;\n\n        for(int\
    \ i=l; i < min(bl1,r); ++i) ret += (node1[i] == val);\n        for(int i=bl0;\
    \ i < br0; ++i) ret += node0[i].count(val);\n        for(int i=max(br1,l); i <\
    \ r; ++i) ret += (node1[i] == val);\n\n        return ret;\n    }\npublic:\n \
    \   IntegerRangeFrequencyQuerySqrtTree(const u64 length): length(length), node1(length,inf)\
    \ {\n        bucket_size = 5*sqrt(length);\n        if(!bucket_size) bucket_size=1;\n\
    \        node0.resize(length / bucket_size + 1);\n    }\n    //idx\u756A\u76EE\
    \u306E\u8981\u7D20\u3092update\n    void update(const size_t idx, const u64 val)\
    \ { erase_impl(idx); insert_impl(idx, val);}\n    //idx\u756A\u76EE\u306E\u8981\
    \u7D20\u3092erase\n    void erase(const size_t idx) { erase_impl(idx); }\n   \
    \ //[l,r) range freq of val (val < upper)\n    int range_freq_upper(const int\
    \ l, const int r, const u64 upper) const {return range_freq_upper_impl(l,r,upper);}\n\
    \    //[l,r) range freq of val (lower <= val < upper)\n    int range_freq_lower_upper(const\
    \ int l, const int r, const u64 lower, const u64 upper) const { return range_freq_upper_impl(l,r,upper)\
    \ - range_freq_upper_impl(l,r,lower);}\n    //[l,r) range freq of val\n    int\
    \ range_freq(const int l, const int r, const u64 val) const {return range_freq_impl(l,r,val);}\n\
    \    void print() { \n        cout << length << \" \" << bucket_size << endl;\n\
    \        for(int i= 0; i < length / bucket_size + 1; ++i) node0[i].print();\n\
    \        cout << endl;\n        for(int i= 0; i < length; ++i) cout << node1[i]\
    \ << \" \\n\"[i==length-1];\n        cout << endl;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/10-segment-tree/IntegerRangeFrequencyQuerySqrtTree.cpp
  requiredBy: []
  timestamp: '2023-06-15 03:54:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segment-tree/IntegerRangeFrequencyQuerySqrtTree-range-freq.test.cpp
documentation_of: lib/10-segment-tree/IntegerRangeFrequencyQuerySqrtTree.cpp
layout: document
redirect_from:
- /library/lib/10-segment-tree/IntegerRangeFrequencyQuerySqrtTree.cpp
- /library/lib/10-segment-tree/IntegerRangeFrequencyQuerySqrtTree.cpp.html
title: "IntegerRangeFrequencyQuerySqrtTree - integer\u5C02\u7528\u533A\u9593freq"
---
