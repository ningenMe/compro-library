---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/data-structure/PerisitentQueue.test.cpp
    title: test/data-structure/data-structure/PerisitentQueue.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/data-structure/data-structure/PersistentQueue.md
    document_title: "PersistentQueue - \u6C38\u7D9Aqueue"
    links: []
  bundledCode: "#line 1 \"lib/data-structure/data-structure/PersistentQueue.cpp\"\n\
    /*\n * @title PersistentQueue - \u6C38\u7D9Aqueue\n * @docs md/data-structure/data-structure/PersistentQueue.md\n\
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
    \ & 1) idx = tree[idx].parent[i];\n        return tree[idx].val;\n    }\n};\n"
  code: "/*\n * @title PersistentQueue - \u6C38\u7D9Aqueue\n * @docs md/data-structure/data-structure/PersistentQueue.md\n\
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
    \ & 1) idx = tree[idx].parent[i];\n        return tree[idx].val;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data-structure/data-structure/PersistentQueue.cpp
  requiredBy: []
  timestamp: '2021-04-26 23:05:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/data-structure/PerisitentQueue.test.cpp
documentation_of: lib/data-structure/data-structure/PersistentQueue.cpp
layout: document
redirect_from:
- /library/lib/data-structure/data-structure/PersistentQueue.cpp
- /library/lib/data-structure/data-structure/PersistentQueue.cpp.html
title: "PersistentQueue - \u6C38\u7D9Aqueue"
---
