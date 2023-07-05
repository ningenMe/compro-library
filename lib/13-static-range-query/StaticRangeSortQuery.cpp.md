---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/segment-tree/StaticRangeSortQuery.md
    document_title: "StaticRangeSortQuery - \u9759\u7684\u533A\u9593sort\u30AF\u30A8\
      \u30EA"
    links: []
  bundledCode: "#line 1 \"lib/13-static-range-query/StaticRangeSortQuery.cpp\"\n/*\n\
    \ * @title StaticRangeSortQuery - \u9759\u7684\u533A\u9593sort\u30AF\u30A8\u30EA\
    \n * @docs md/segment-tree/StaticRangeSortQuery.md\n */\ntemplate<size_t bit_length,\
    \ class Monoid> class StaticRangeSortQuery {\n    using TypeNode = typename Monoid::TypeNode;\n\
    \    using TypeSortKey = unsigned long long;\n    class InnerTreeSet {\n     \
    \   struct Node {\n            Node *left, *right; size_t size; TypeNode value;\n\
    \            Node(): size(0),value(Monoid::unit_node) {left=right=nullptr;}\n\
    \            Node(Node* _left, Node* _right):size(0),value(Monoid::unit_node),left(_left),right(_right)\
    \ {}\n            void clear(){ left=right=nullptr; size=0;value=Monoid::unit_node;\
    \ }\n            void init(TypeNode val) {size=1,value=val;}\n        };\n   \
    \     int rev;\n        Node* root;\n        size_t size(Node* node) const {return\
    \ (node==nullptr ? 0 : node->size);}\n        TypeNode value(Node* node) const\
    \ {return (node==nullptr ? Monoid::unit_node: node->value);}\n        void update(Node*\
    \ node) {\n            size_t sz_l = size(node->left);\n            size_t sz_r\
    \ = size(node->right);\n            if(!sz_l && node->left != nullptr) node->left\
    \ = nullptr;\n            if(!sz_r && node->right != nullptr) node->right = nullptr;\n\
    \            node->size = sz_l + sz_r;\n        }\n        void insert(Node* node,\
    \ int i, const TypeSortKey key, const TypeNode val) {\n            if(i<0) { node->init(val);\
    \ return;}\n            const TypeSortKey j = ((key>>i) & 1);\n            if(j)\
    \ { if(node->right == nullptr) node->right = new Node(); insert(node->right, i-1,\
    \ key, val);} \n            else { if(node->left == nullptr) node->left = new\
    \ Node(); insert(node->left, i-1, key, val);}\n            update(node);\n   \
    \     }\n        void erase(Node* node, int i, const TypeSortKey key) {\n    \
    \        if(i<0) { node->clear(); return; }\n            const TypeSortKey j =\
    \ ((key>>i) & 1);\n            if(j) { if(node->right != nullptr) erase(node->right,\
    \ i-1, key);}\n            else { if(node->left != nullptr) erase(node->left,\
    \ i-1, key);}\n            update(node);\n        }\n        pair<TypeSortKey,\
    \ TypeNode> kth_smallest(Node* node, int i, size_t k) {\n            if(i<0) {\
    \ return {0, value(node)};}\n            const TypeSortKey j = (1ULL<<i);\n  \
    \          size_t sz_l = size(node->left);\n            if(k<sz_l) { return kth_smallest(node->left,i-1,k);}\n\
    \            else { auto p = kth_smallest(node->right,i-1,k-sz_l); p.first |=\
    \ j; return p;}\n        }\n        Node* merge(Node* node_x, Node* node_y) {\n\
    \            if(node_x == nullptr) return node_y;\n            if(node_y == nullptr)\
    \ return node_x;\n            node_x->left = merge(node_x->left, node_y->left);\n\
    \            node_x->right = merge(node_x->right, node_y->right);\n          \
    \  node_y->clear();\n            update(node_x);\n            return node_x;\n\
    \        }\n        //[0,k),[k,size) \u3067split\n        pair<Node*, Node*> split(Node*\
    \ node, size_t k) {\n            if(k==0) return {nullptr, node};\n          \
    \  if(k==size(node)) return {node, nullptr};\n            size_t sz_l = size(node->left);\n\
    \            if(k<sz_l) {\n                auto [tmp_left, tmp_right] = split(node->left,\
    \ k);\n                node->left = tmp_right;\n                Node* left = new\
    \ Node(tmp_left, nullptr);\n                update(left), update(node);\n    \
    \            return {left, node};\n            }\n            else {\n       \
    \         auto [tmp_left, tmp_right] = split(node->right, k - sz_l);\n       \
    \         node->right = tmp_left;\n                Node* right = new Node(nullptr,\
    \ tmp_right);\n                update(node), update(right);\n                return\
    \ {node, right};\n            }\n        }\n        InnerTreeSet(Node* node, int\
    \ rev=0): root(node), rev(rev){}\n    public:\n        InnerTreeSet(int rev=0):\
    \ root(new Node),rev(rev) {}\n        void insert(const TypeSortKey key, const\
    \ TypeNode val) {insert(root,bit_length-1,key,val);}\n        void erase(const\
    \ TypeSortKey key) {erase(root,bit_length-1,key);}\n        size_t size() const\
    \ {return size(root);}\n        pair<TypeSortKey, TypeNode> kth_smallest(size_t\
    \ k) { return kth_smallest(root, bit_length-1, (rev?size()-1-k:k));}\n       \
    \ TypeNode fold_all() {return value(root);}\n        void merge(InnerTreeSet st)\
    \ { merge(root, st.root); rev=0; st.clear();}\n        pair<InnerTreeSet, InnerTreeSet>\
    \ split(size_t k) { \n            if(rev) { auto [node_x, node_y] = split(root,\
    \ size() - k); return {InnerTreeSet(node_y, rev), InnerTreeSet(node_x, rev)};\
    \ }\n            else { auto [node_x, node_y] = split(root, k); return {InnerTreeSet(node_x,\
    \ rev), InnerTreeSet(node_y, rev)}; }\n        }\n        void clear() { root=new\
    \ Node(); rev=0; }\n        void sort_asc() {rev=0;}\n        void sort_desc()\
    \ {rev=1;}\n    };\n\n    size_t length;\n    vector<InnerTreeSet> leaf;\n   \
    \ set<size_t> range;\n    //[i,i+1) \u306E leaf\u306B\u30A2\u30AF\u30BB\u30B9\u3067\
    \u304D\u308B\u3088\u3046\u306B\u3059\u308B\n    inline void prepare_access(int\
    \ i) {\n        if(length <= i) return;\n        auto itr = range.lower_bound(i);\n\
    \        int r = *itr;\n        if(r == i) return;\n        --itr;\n        int\
    \ l = *itr;\n        //[l,r) \u306E\u533A\u9593\u3092 [l,i),[i,r) \u306Bsplit\u3059\
    \u308B\n        auto [st_l, st_r] = leaf[l].split(i-l);\n        leaf[l] = st_l;\
    \ leaf[i] = st_r;\n        range.insert(i);\n    }\n    void sort_impl(int l,\
    \ int r, int rev) {\n        prepare_access(l);\n        prepare_access(r);\n\
    \        while(1) {\n            size_t c = *range.upper_bound(l);\n         \
    \   if(c == r) break;\n            leaf[l].merge(leaf[c]);\n            range.erase(c);\
    \ \n        }\n        if(rev) leaf[l].sort_desc();\n        else leaf[l].sort_asc();\n\
    \    }\npublic:\n    //vector\u3067\u521D\u671F\u5316\n    StaticRangeSortQuery(const\
    \ vector<TypeSortKey>& keys, const vector<TypeNode>& vals) {\n        assert(keys.size()\
    \ == vals.size());\n        length = keys.size();\n        leaf.resize(length);\n\
    \        for (int i = 0; i <= length; ++i) range.insert(i);\n        for (int\
    \ i = 0; i <  length; ++i) leaf[i].insert(keys[i], vals[i]);\n    }\n    void\
    \ sort_asc(int l, int r) { sort_impl(l,r,0); }\n    void sort_desc(int l, int\
    \ r) { sort_impl(l,r,1); }\n    //[idx,idx+1)\n    TypeNode get(size_t idx) {\n\
    \        if(idx < 0 || length <= idx) return Monoid::unit_node;\n        prepare_access(idx);\n\
    \        return leaf[idx].kth_smallest(0).second;\n    }\n    void print(){\n\
    \        cout << \"{ \";\n        for(int i = 0; i < length; ++i) cout << leaf[i].fold_all()\
    \ << \", \";\n        cout << \" }\" << endl;\n    }\n};\n\ntemplate<class T>\
    \ struct MonoidInt {\n    using TypeNode = T;\n    inline static constexpr TypeNode\
    \ unit_node = 0;\n};\n"
  code: "/*\n * @title StaticRangeSortQuery - \u9759\u7684\u533A\u9593sort\u30AF\u30A8\
    \u30EA\n * @docs md/segment-tree/StaticRangeSortQuery.md\n */\ntemplate<size_t\
    \ bit_length, class Monoid> class StaticRangeSortQuery {\n    using TypeNode =\
    \ typename Monoid::TypeNode;\n    using TypeSortKey = unsigned long long;\n  \
    \  class InnerTreeSet {\n        struct Node {\n            Node *left, *right;\
    \ size_t size; TypeNode value;\n            Node(): size(0),value(Monoid::unit_node)\
    \ {left=right=nullptr;}\n            Node(Node* _left, Node* _right):size(0),value(Monoid::unit_node),left(_left),right(_right)\
    \ {}\n            void clear(){ left=right=nullptr; size=0;value=Monoid::unit_node;\
    \ }\n            void init(TypeNode val) {size=1,value=val;}\n        };\n   \
    \     int rev;\n        Node* root;\n        size_t size(Node* node) const {return\
    \ (node==nullptr ? 0 : node->size);}\n        TypeNode value(Node* node) const\
    \ {return (node==nullptr ? Monoid::unit_node: node->value);}\n        void update(Node*\
    \ node) {\n            size_t sz_l = size(node->left);\n            size_t sz_r\
    \ = size(node->right);\n            if(!sz_l && node->left != nullptr) node->left\
    \ = nullptr;\n            if(!sz_r && node->right != nullptr) node->right = nullptr;\n\
    \            node->size = sz_l + sz_r;\n        }\n        void insert(Node* node,\
    \ int i, const TypeSortKey key, const TypeNode val) {\n            if(i<0) { node->init(val);\
    \ return;}\n            const TypeSortKey j = ((key>>i) & 1);\n            if(j)\
    \ { if(node->right == nullptr) node->right = new Node(); insert(node->right, i-1,\
    \ key, val);} \n            else { if(node->left == nullptr) node->left = new\
    \ Node(); insert(node->left, i-1, key, val);}\n            update(node);\n   \
    \     }\n        void erase(Node* node, int i, const TypeSortKey key) {\n    \
    \        if(i<0) { node->clear(); return; }\n            const TypeSortKey j =\
    \ ((key>>i) & 1);\n            if(j) { if(node->right != nullptr) erase(node->right,\
    \ i-1, key);}\n            else { if(node->left != nullptr) erase(node->left,\
    \ i-1, key);}\n            update(node);\n        }\n        pair<TypeSortKey,\
    \ TypeNode> kth_smallest(Node* node, int i, size_t k) {\n            if(i<0) {\
    \ return {0, value(node)};}\n            const TypeSortKey j = (1ULL<<i);\n  \
    \          size_t sz_l = size(node->left);\n            if(k<sz_l) { return kth_smallest(node->left,i-1,k);}\n\
    \            else { auto p = kth_smallest(node->right,i-1,k-sz_l); p.first |=\
    \ j; return p;}\n        }\n        Node* merge(Node* node_x, Node* node_y) {\n\
    \            if(node_x == nullptr) return node_y;\n            if(node_y == nullptr)\
    \ return node_x;\n            node_x->left = merge(node_x->left, node_y->left);\n\
    \            node_x->right = merge(node_x->right, node_y->right);\n          \
    \  node_y->clear();\n            update(node_x);\n            return node_x;\n\
    \        }\n        //[0,k),[k,size) \u3067split\n        pair<Node*, Node*> split(Node*\
    \ node, size_t k) {\n            if(k==0) return {nullptr, node};\n          \
    \  if(k==size(node)) return {node, nullptr};\n            size_t sz_l = size(node->left);\n\
    \            if(k<sz_l) {\n                auto [tmp_left, tmp_right] = split(node->left,\
    \ k);\n                node->left = tmp_right;\n                Node* left = new\
    \ Node(tmp_left, nullptr);\n                update(left), update(node);\n    \
    \            return {left, node};\n            }\n            else {\n       \
    \         auto [tmp_left, tmp_right] = split(node->right, k - sz_l);\n       \
    \         node->right = tmp_left;\n                Node* right = new Node(nullptr,\
    \ tmp_right);\n                update(node), update(right);\n                return\
    \ {node, right};\n            }\n        }\n        InnerTreeSet(Node* node, int\
    \ rev=0): root(node), rev(rev){}\n    public:\n        InnerTreeSet(int rev=0):\
    \ root(new Node),rev(rev) {}\n        void insert(const TypeSortKey key, const\
    \ TypeNode val) {insert(root,bit_length-1,key,val);}\n        void erase(const\
    \ TypeSortKey key) {erase(root,bit_length-1,key);}\n        size_t size() const\
    \ {return size(root);}\n        pair<TypeSortKey, TypeNode> kth_smallest(size_t\
    \ k) { return kth_smallest(root, bit_length-1, (rev?size()-1-k:k));}\n       \
    \ TypeNode fold_all() {return value(root);}\n        void merge(InnerTreeSet st)\
    \ { merge(root, st.root); rev=0; st.clear();}\n        pair<InnerTreeSet, InnerTreeSet>\
    \ split(size_t k) { \n            if(rev) { auto [node_x, node_y] = split(root,\
    \ size() - k); return {InnerTreeSet(node_y, rev), InnerTreeSet(node_x, rev)};\
    \ }\n            else { auto [node_x, node_y] = split(root, k); return {InnerTreeSet(node_x,\
    \ rev), InnerTreeSet(node_y, rev)}; }\n        }\n        void clear() { root=new\
    \ Node(); rev=0; }\n        void sort_asc() {rev=0;}\n        void sort_desc()\
    \ {rev=1;}\n    };\n\n    size_t length;\n    vector<InnerTreeSet> leaf;\n   \
    \ set<size_t> range;\n    //[i,i+1) \u306E leaf\u306B\u30A2\u30AF\u30BB\u30B9\u3067\
    \u304D\u308B\u3088\u3046\u306B\u3059\u308B\n    inline void prepare_access(int\
    \ i) {\n        if(length <= i) return;\n        auto itr = range.lower_bound(i);\n\
    \        int r = *itr;\n        if(r == i) return;\n        --itr;\n        int\
    \ l = *itr;\n        //[l,r) \u306E\u533A\u9593\u3092 [l,i),[i,r) \u306Bsplit\u3059\
    \u308B\n        auto [st_l, st_r] = leaf[l].split(i-l);\n        leaf[l] = st_l;\
    \ leaf[i] = st_r;\n        range.insert(i);\n    }\n    void sort_impl(int l,\
    \ int r, int rev) {\n        prepare_access(l);\n        prepare_access(r);\n\
    \        while(1) {\n            size_t c = *range.upper_bound(l);\n         \
    \   if(c == r) break;\n            leaf[l].merge(leaf[c]);\n            range.erase(c);\
    \ \n        }\n        if(rev) leaf[l].sort_desc();\n        else leaf[l].sort_asc();\n\
    \    }\npublic:\n    //vector\u3067\u521D\u671F\u5316\n    StaticRangeSortQuery(const\
    \ vector<TypeSortKey>& keys, const vector<TypeNode>& vals) {\n        assert(keys.size()\
    \ == vals.size());\n        length = keys.size();\n        leaf.resize(length);\n\
    \        for (int i = 0; i <= length; ++i) range.insert(i);\n        for (int\
    \ i = 0; i <  length; ++i) leaf[i].insert(keys[i], vals[i]);\n    }\n    void\
    \ sort_asc(int l, int r) { sort_impl(l,r,0); }\n    void sort_desc(int l, int\
    \ r) { sort_impl(l,r,1); }\n    //[idx,idx+1)\n    TypeNode get(size_t idx) {\n\
    \        if(idx < 0 || length <= idx) return Monoid::unit_node;\n        prepare_access(idx);\n\
    \        return leaf[idx].kth_smallest(0).second;\n    }\n    void print(){\n\
    \        cout << \"{ \";\n        for(int i = 0; i < length; ++i) cout << leaf[i].fold_all()\
    \ << \", \";\n        cout << \" }\" << endl;\n    }\n};\n\ntemplate<class T>\
    \ struct MonoidInt {\n    using TypeNode = T;\n    inline static constexpr TypeNode\
    \ unit_node = 0;\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/13-static-range-query/StaticRangeSortQuery.cpp
  requiredBy: []
  timestamp: '2023-07-06 00:00:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/13-static-range-query/StaticRangeSortQuery.cpp
layout: document
redirect_from:
- /library/lib/13-static-range-query/StaticRangeSortQuery.cpp
- /library/lib/13-static-range-query/StaticRangeSortQuery.cpp.html
title: "StaticRangeSortQuery - \u9759\u7684\u533A\u9593sort\u30AF\u30A8\u30EA"
---
