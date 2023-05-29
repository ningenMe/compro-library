---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/14-data-structure/PersistentQueue.cpp
    title: "PersistentQueue - \u6C38\u7D9Aqueue"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_queue
    links:
    - https://judge.yosupo.jp/problem/persistent_queue
  bundledCode: "#line 1 \"test/data-structure/PerisitentQueue.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\n\n#include <vector>\n\
    #include <iostream>\n#include <array>\n#include <cassert>\n#include <unordered_map>\n\
    using namespace std;\n#line 1 \"lib/14-data-structure/PersistentQueue.cpp\"\n\
    /*\n * @title PersistentQueue - \u6C38\u7D9Aqueue\n * @docs md/data-structure/PersistentQueue.md\n\
    \ */\ntemplate<class T,size_t bit=20> class PersistentQueue{\nprivate:\n    struct\
    \ Node{\n        array<size_t,bit> parent;\n        T val;\n        size_t length;\n\
    \        Node(T val,size_t length):val(val),length(length){}\n    };\n    vector<Node>\
    \ tree;\n    unordered_map<int,size_t> mp;\npublic:\n    PersistentQueue(T inf)\
    \ {\n        Node root(inf,0);\n        for(size_t i=0;i<bit;++i) root.parent[i]=0;\n\
    \        mp[-1]=0;\n        tree.push_back(root);\n    }\n    void push(int target_id,\
    \ int pushed_id, T val) {\n        size_t idx = mp[target_id];\n        size_t\
    \ length = tree[idx].length + 1;\n        Node leaf(val,length);\n        leaf.parent[0]=idx;\n\
    \        for(size_t i=1;i<bit;++i) leaf.parent[i]=tree[leaf.parent[i-1]].parent[i-1];\n\
    \        mp[pushed_id] = tree.size();\n        tree.push_back(leaf);\n    }\n\
    \    T pop(int target_id,int pushed_id) {\n        size_t idx = mp[target_id];\n\
    \        auto node = tree[idx];\n        size_t& length = node.length;\n     \
    \   assert(length > 0);\n        length-=1;\n        mp[pushed_id] = tree.size();\n\
    \        tree.push_back(node);\n        for(int i=bit-1; 0<=i; --i) if((length>>i)\
    \ & 1) idx = tree[idx].parent[i];\n        return tree[idx].val;\n    }\n};\n\
    #line 10 \"test/data-structure/PerisitentQueue.test.cpp\"\n\nint main(void){\n\
    \    cin.tie(0);ios::sync_with_stdio(false); \n    int Q; cin >> Q;\n    PersistentQueue<int>\
    \ pq(1e9+7);\n    for(int i=0;i<Q;++i) {\n        int q; cin >> q;\n        if(q==0)\
    \ {\n            int t,x; cin >> t >> x;\n            pq.push(t,i,x);\n      \
    \  }\n        else {\n            int t; cin >> t;\n            cout << pq.pop(t,i)\
    \ << \"\\n\";\n        }\n    }\n    return 0; \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\n\n\
    #include <vector>\n#include <iostream>\n#include <array>\n#include <cassert>\n\
    #include <unordered_map>\nusing namespace std;\n#include \"../../lib/14-data-structure/PersistentQueue.cpp\"\
    \n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false); \n    int Q;\
    \ cin >> Q;\n    PersistentQueue<int> pq(1e9+7);\n    for(int i=0;i<Q;++i) {\n\
    \        int q; cin >> q;\n        if(q==0) {\n            int t,x; cin >> t >>\
    \ x;\n            pq.push(t,i,x);\n        }\n        else {\n            int\
    \ t; cin >> t;\n            cout << pq.pop(t,i) << \"\\n\";\n        }\n    }\n\
    \    return 0; \n}"
  dependsOn:
  - lib/14-data-structure/PersistentQueue.cpp
  isVerificationFile: true
  path: test/data-structure/PerisitentQueue.test.cpp
  requiredBy: []
  timestamp: '2023-05-30 05:01:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/PerisitentQueue.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/PerisitentQueue.test.cpp
- /verify/test/data-structure/PerisitentQueue.test.cpp.html
title: test/data-structure/PerisitentQueue.test.cpp
---
