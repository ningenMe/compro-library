---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/12-binary-search-tree/RandomizedBinarySearchTreeSet.cpp
    title: "RandomizedBinarySearchTree - \u30E9\u30F3\u30C0\u30E0\u5E73\u8861\u4E8C\
      \u5206\u63A2\u7D22\u6728set"
  - icon: ':question:'
    path: lib/99-operator/monoid/MonoidRangeSumPointAdd.cpp
    title: "MonoidRangeSumPointAdd - [\u533A\u9593\u548C, \u4E00\u70B9\u52A0\u7B97\
      ]"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/919
    links:
    - https://yukicoder.me/problems/no/919
  bundledCode: "#line 1 \"test/binary-search-tree/RandomizedBinarySearchTreeSet-med.test.cpp\"\
    \n#define PROBLEM \"https://yukicoder.me/problems/no/919\"\n\n#include <vector>\n\
    #include <iostream>\n#include <unordered_map>\n#include <algorithm>\n#include\
    \ <numeric>\n#include <cmath>\nusing namespace std;\n#line 1 \"lib/12-binary-search-tree/RandomizedBinarySearchTreeSet.cpp\"\
    \n/*\n * @title RandomizedBinarySearchTree - \u30E9\u30F3\u30C0\u30E0\u5E73\u8861\
    \u4E8C\u5206\u63A2\u7D22\u6728set\n * @docs md/binary-search-tree/RandomizedBinarySearchTree.md\n\
    \ */\ntemplate<class Monoid> class RandomizedBinarySearchTreeSet {\n    using\
    \ TypeNode = typename Monoid::TypeNode;\n    unsigned int x = 123456789, y = 362436069,\
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
    \   RandomizedBinarySearchTreeSet() : root(nullptr) {}\n    inline int size()\
    \ {return size(this->root);}\n    inline int empty(void) {return bool(size()==0);}\n\
    \    inline Node* merge(Node *left, Node *right) {return merge_impl(left,right);}\n\
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
    \ nodeVal,TypeNode var){return var == nodeVal;}\n};\n#line 12 \"test/binary-search-tree/RandomizedBinarySearchTreeSet-med.test.cpp\"\
    \n\ntemplate<class T> class Mo{\n    unordered_map<long long,int> mp;\n    long\
    \ long N;\n    int bucket;\n    vector<pair<int,int>> range;\n\tvector<int> idx;\n\
    public:\n\n    Mo(int N, const vector<pair<int,int>>& range) : N(N),range(range),idx(range.size()),bucket(sqrt(N))\
    \ {\n        iota(idx.begin(),idx.end(),0);\n        sort(idx.begin(),idx.end(),[&](int\
    \ a, int b){\n            auto  al = range[a].first/bucket;\n            auto\
    \  ar = range[a].second;\n            auto  bl = range[b].first/bucket;\n    \
    \        auto  br = range[b].second;\n            return (al != bl) ? (al < bl)\
    \ : ((al%2)?(ar > br):(ar < br));\n        });\n    }\n    \n    //\u53C2\u7167\
    \u3067vector\u3092\u6E21\u3057\u305F\u308A\u3059\u308B\u3068\u826F\u3044\n   \
    \ void solve(const vector<int>& A, RandomizedBinarySearchTreeSet<MonoidRangeSumPointAdd<long\
    \ long>>& med){\n        int l = 0, r = 0;\n        for(int& i:idx){\n       \
    \     auto& xl = range[i].first;\n            auto& xr = range[i].second;\n  \
    \          \n            //\u5DE6\u7AEF\u3092\u5E83\u3052\u308B\n            while(xl\
    \ < l){\n                l--;\n                med.insert(A[l]);\n           \
    \ }\n            //\u53F3\u7AEF\u3092\u5E83\u3052\u308B\n            while(r <\
    \ xr){\n                r++;\n                med.insert(A[r]);\n            }\n\
    \            //\u5DE6\u7AEF\u3092\u72ED\u3081\u308B\n            while(l < xl){\n\
    \t\t\t\tmed.erase(A[l]);\n                l++;\n            }\n            //\u53F3\
    \u7AEF\u3092\u72ED\u3081\u308B\n            while(xr < r){\n\t\t\t\tmed.erase(A[r]);\n\
    \                r--;\n            }\n            mp[xl*N+xr] = med.get((xr-xl)/2);\n\
    \        }\n    }\n\n    T& operator [] (pair<int,int> p) {\n        return mp[p.first*N+p.second];\n\
    \    }\n};\n\ntemplate <class T> void chmax(T& a, const T b){a=max(a,b);}\n\n\
    int main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n\tint N; cin >> N;\n\
    \    vector<int> A(N);\n\tfor(int i = 0; i < N; ++i) cin >> A[i];\n\n\t//\u30AF\
    \u30A8\u30EA\u533A\u9593\u3092\u5217\u6319\u3001\u8ABF\u548C\u7D1A\u6570\u306A\
    \u306E\u3067O(N*logN)\n\tvector<pair<int,int>> range;\n\tfor(int n = 1; n <= N;\
    \ ++n) {\n\t\tint M = N/n;\n\t\tfor(int i = 0;     i+n <= N; i+=n) range.push_back({i,i+n-1});\n\
    \t\tfor(int i = N-M*n; i+n <= N; i+=n) range.push_back({i,i+n-1});\n\t}\n\n\t\n\
    \t//Mo\u3067\u4E2D\u592E\u5024\u5217\u6319\u3000O(N*sqrt(N)*(logN)^2)\n    Mo<int>\
    \ mo(N,range);\n    RandomizedBinarySearchTree<MonoidRangeSumPointAdd<long long>>\
    \ med;\n    med.insert(A[0]);\n    mo.solve(A,med);\n\n\tlong long ans = 0;\n\t\
    int cnt = 0;\n\t//\u533A\u9593\u9577\u6C7A\u3081\u6253\u3061\u5168\u63A2\u7D22\
    O(N*logN)\n\tfor(long long n = 1; n <= N; ++n) {\n\t\tint M = N/n;\n\t\tvector<long\
    \ long> lSum(M,0),rSum(M,0);\n\t\tvector<pair<int, int>> lRange(M),rRange(M);\n\
    \t\t//\u533A\u9593\u53D6\u5F97 O(M)\n\t\tfor(int i = 0; i < M; ++i) {\n\t\t\t\
    lRange[i] = range[cnt + i];\n\t\t\tlSum[i]   = n*mo[lRange[i]];\n\t\t\trRange[i]\
    \ = range[cnt + i + M];\n\t\t\trSum[i]   = n*mo[rRange[i]];\n\t\t}\n\t\t//\u7D2F\
    \u7A4D\u548C O(M)\n\t\tfor(int i = 1;    i < M; ++i) lSum[i]  += lSum[i-1];\n\t\
    \tfor(int i = M-2; 0 <= i; --i) rSum[i]  += rSum[i+1];\n\t\t//\u7D2F\u7A4Dmax\
    \ O(M)\n\t\tfor(int i = 1;    i < M; ++i) chmax(lSum[i],lSum[i-1]);\n\t\tfor(int\
    \ i = M-2; 0 <= i; --i) chmax(rSum[i],rSum[i+1]);\n\n\t\tchmax(ans,lSum[M-1]);\n\
    \t\tchmax(ans,rSum[0]);\n\n\t\t//\u5C3A\u53D6\u308A\u3057\u306A\u304C\u3089\u5DE6\
    \u53F3\u6C7A\u3081\u6253\u3061\u5168\u63A2\u7D22 O(M)\n\t\tint j = 0;\n\t\tfor(int\
    \ i = 0; i < M; ++i) {\n\t\t\twhile(j < M && lRange[i].second >= rRange[j].first)\
    \ j++;\n\t\t\tif(j<M && lRange[i].second < rRange[j].first) {\n\t\t\t\tchmax(ans,lSum[i]+rSum[j]);\n\
    \t\t\t}\n\t\t}\n\t\tcnt += 2*M;\n\t}\n\tcout << ans << endl;\n\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/919\"\n\n#include <vector>\n\
    #include <iostream>\n#include <unordered_map>\n#include <algorithm>\n#include\
    \ <numeric>\n#include <cmath>\nusing namespace std;\n#include \"../../lib/12-binary-search-tree/RandomizedBinarySearchTreeSet.cpp\"\
    \n#include \"../../lib/99-operator/monoid/MonoidRangeSumPointAdd.cpp\"\n\ntemplate<class\
    \ T> class Mo{\n    unordered_map<long long,int> mp;\n    long long N;\n    int\
    \ bucket;\n    vector<pair<int,int>> range;\n\tvector<int> idx;\npublic:\n\n \
    \   Mo(int N, const vector<pair<int,int>>& range) : N(N),range(range),idx(range.size()),bucket(sqrt(N))\
    \ {\n        iota(idx.begin(),idx.end(),0);\n        sort(idx.begin(),idx.end(),[&](int\
    \ a, int b){\n            auto  al = range[a].first/bucket;\n            auto\
    \  ar = range[a].second;\n            auto  bl = range[b].first/bucket;\n    \
    \        auto  br = range[b].second;\n            return (al != bl) ? (al < bl)\
    \ : ((al%2)?(ar > br):(ar < br));\n        });\n    }\n    \n    //\u53C2\u7167\
    \u3067vector\u3092\u6E21\u3057\u305F\u308A\u3059\u308B\u3068\u826F\u3044\n   \
    \ void solve(const vector<int>& A, RandomizedBinarySearchTreeSet<MonoidRangeSumPointAdd<long\
    \ long>>& med){\n        int l = 0, r = 0;\n        for(int& i:idx){\n       \
    \     auto& xl = range[i].first;\n            auto& xr = range[i].second;\n  \
    \          \n            //\u5DE6\u7AEF\u3092\u5E83\u3052\u308B\n            while(xl\
    \ < l){\n                l--;\n                med.insert(A[l]);\n           \
    \ }\n            //\u53F3\u7AEF\u3092\u5E83\u3052\u308B\n            while(r <\
    \ xr){\n                r++;\n                med.insert(A[r]);\n            }\n\
    \            //\u5DE6\u7AEF\u3092\u72ED\u3081\u308B\n            while(l < xl){\n\
    \t\t\t\tmed.erase(A[l]);\n                l++;\n            }\n            //\u53F3\
    \u7AEF\u3092\u72ED\u3081\u308B\n            while(xr < r){\n\t\t\t\tmed.erase(A[r]);\n\
    \                r--;\n            }\n            mp[xl*N+xr] = med.get((xr-xl)/2);\n\
    \        }\n    }\n\n    T& operator [] (pair<int,int> p) {\n        return mp[p.first*N+p.second];\n\
    \    }\n};\n\ntemplate <class T> void chmax(T& a, const T b){a=max(a,b);}\n\n\
    int main() {\n    cin.tie(0);ios::sync_with_stdio(false);\n\tint N; cin >> N;\n\
    \    vector<int> A(N);\n\tfor(int i = 0; i < N; ++i) cin >> A[i];\n\n\t//\u30AF\
    \u30A8\u30EA\u533A\u9593\u3092\u5217\u6319\u3001\u8ABF\u548C\u7D1A\u6570\u306A\
    \u306E\u3067O(N*logN)\n\tvector<pair<int,int>> range;\n\tfor(int n = 1; n <= N;\
    \ ++n) {\n\t\tint M = N/n;\n\t\tfor(int i = 0;     i+n <= N; i+=n) range.push_back({i,i+n-1});\n\
    \t\tfor(int i = N-M*n; i+n <= N; i+=n) range.push_back({i,i+n-1});\n\t}\n\n\t\n\
    \t//Mo\u3067\u4E2D\u592E\u5024\u5217\u6319\u3000O(N*sqrt(N)*(logN)^2)\n    Mo<int>\
    \ mo(N,range);\n    RandomizedBinarySearchTree<MonoidRangeSumPointAdd<long long>>\
    \ med;\n    med.insert(A[0]);\n    mo.solve(A,med);\n\n\tlong long ans = 0;\n\t\
    int cnt = 0;\n\t//\u533A\u9593\u9577\u6C7A\u3081\u6253\u3061\u5168\u63A2\u7D22\
    O(N*logN)\n\tfor(long long n = 1; n <= N; ++n) {\n\t\tint M = N/n;\n\t\tvector<long\
    \ long> lSum(M,0),rSum(M,0);\n\t\tvector<pair<int, int>> lRange(M),rRange(M);\n\
    \t\t//\u533A\u9593\u53D6\u5F97 O(M)\n\t\tfor(int i = 0; i < M; ++i) {\n\t\t\t\
    lRange[i] = range[cnt + i];\n\t\t\tlSum[i]   = n*mo[lRange[i]];\n\t\t\trRange[i]\
    \ = range[cnt + i + M];\n\t\t\trSum[i]   = n*mo[rRange[i]];\n\t\t}\n\t\t//\u7D2F\
    \u7A4D\u548C O(M)\n\t\tfor(int i = 1;    i < M; ++i) lSum[i]  += lSum[i-1];\n\t\
    \tfor(int i = M-2; 0 <= i; --i) rSum[i]  += rSum[i+1];\n\t\t//\u7D2F\u7A4Dmax\
    \ O(M)\n\t\tfor(int i = 1;    i < M; ++i) chmax(lSum[i],lSum[i-1]);\n\t\tfor(int\
    \ i = M-2; 0 <= i; --i) chmax(rSum[i],rSum[i+1]);\n\n\t\tchmax(ans,lSum[M-1]);\n\
    \t\tchmax(ans,rSum[0]);\n\n\t\t//\u5C3A\u53D6\u308A\u3057\u306A\u304C\u3089\u5DE6\
    \u53F3\u6C7A\u3081\u6253\u3061\u5168\u63A2\u7D22 O(M)\n\t\tint j = 0;\n\t\tfor(int\
    \ i = 0; i < M; ++i) {\n\t\t\twhile(j < M && lRange[i].second >= rRange[j].first)\
    \ j++;\n\t\t\tif(j<M && lRange[i].second < rRange[j].first) {\n\t\t\t\tchmax(ans,lSum[i]+rSum[j]);\n\
    \t\t\t}\n\t\t}\n\t\tcnt += 2*M;\n\t}\n\tcout << ans << endl;\n\n    return 0;\n\
    }\n"
  dependsOn:
  - lib/12-binary-search-tree/RandomizedBinarySearchTreeSet.cpp
  - lib/99-operator/monoid/MonoidRangeSumPointAdd.cpp
  isVerificationFile: true
  path: test/binary-search-tree/RandomizedBinarySearchTreeSet-med.test.cpp
  requiredBy: []
  timestamp: '2023-06-03 15:39:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/binary-search-tree/RandomizedBinarySearchTreeSet-med.test.cpp
layout: document
redirect_from:
- /verify/test/binary-search-tree/RandomizedBinarySearchTreeSet-med.test.cpp
- /verify/test/binary-search-tree/RandomizedBinarySearchTreeSet-med.test.cpp.html
title: test/binary-search-tree/RandomizedBinarySearchTreeSet-med.test.cpp
---
