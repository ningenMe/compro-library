---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/12-binary-search-tree/SimpleBinaryTrie.md
    document_title: SimpleBinaryTrie
    links: []
  bundledCode: "#line 1 \"lib/12-binary-search-tree/SimpleBinaryTrie.cpp\"\n/*\n *\
    \ @title SimpleBinaryTrie\n * @docs md/12-binary-search-tree/SimpleBinaryTrie.md\n\
    \ */\ntemplate<size_t bit_length=20> class SimpleBinaryTrie {\n    using u32 =\
    \ unsigned int;\n    struct Node {\n        Node *left, *right;\n        u32 size;\n\
    \        Node(): size(0) {left=right=nullptr;}\n    };\n    Node* root;\n    u32\
    \ size(Node* node) const {return (node==nullptr ? 0 : node->size);}\n    u32 empty(Node*\
    \ node) const {return size(node) == 0;}\npublic:\n    SimpleBinaryTrie(): root(new\
    \ Node) {}\n    void insert(const u32 val) {\n        Node* curr = root;\n   \
    \     stack<Node*> st;\n        for(u32 i=0; i < bit_length; ++i) {\n        \
    \    u32 j = ((val>>(bit_length-1-i)) & 1);\n            st.push(curr);\n    \
    \        if(j) {\n                if(curr->right != nullptr) {\n             \
    \       curr = curr->right;\n                }\n                else {\n     \
    \               Node* next = new Node();\n                    curr->right = next;\n\
    \                    curr = next;\n                }\n            }\n        \
    \    else {\n                if(curr->left != nullptr) {\n                   \
    \ curr = curr->left;\n                }\n                else {\n            \
    \        Node* next = new Node();\n                    curr->left = next;\n  \
    \                  curr = next;\n                }\n            }\n        }\n\
    \        curr->size += 1;\n        while(st.size()) {\n            auto node=st.top();\
    \ st.pop();\n            node->size = size(node->left) + size(node->right);\n\
    \        }\n    }\n    void erase(const u32 val) {\n        Node* curr = root;\n\
    \        stack<Node*> st;\n        for(u32 i=0; i < bit_length; ++i) {\n     \
    \       u32 j = ((val>>(bit_length-1-i)) & 1);\n            st.push(curr);\n \
    \           if(j) {\n                if(curr->right != nullptr) {\n          \
    \          curr = curr->right;\n                }\n                else {\n  \
    \                  return;\n                }\n            }\n            else\
    \ {\n                if(curr->left != nullptr) {\n                    curr = curr->left;\n\
    \                }\n                else {\n                    return;\n    \
    \            }\n            }\n        }\n        if(empty(curr)) return;\n  \
    \      curr->size -= 1;\n        while(st.size()) {\n            auto node=st.top();\
    \ st.pop();\n            node->size = size(node->left) + size(node->right);\n\
    \        }\n    }\n    u32 size() const {return size(root);}\n    u32 kth_smallest(u32\
    \ k) {\n        Node* curr = root;\n        u32 val=0;\n        for(u32 i=0; i\
    \ < bit_length; ++i) {\n            u32 j = 1U << (bit_length-1-i);\n        \
    \    u32 sz_l = size(curr->left);\n            if(k<sz_l) {\n                curr\
    \ = curr->left;\n            }\n            else {\n                val |= j;\n\
    \                k -= sz_l;\n                curr = curr->right;\n           \
    \ }\n        }\n        return val;\n    }\n    u32 lower_bound(const u32 val)\
    \ {\n        Node* curr = root;\n        u32 k=0;\n        for(u32 i=0; i < bit_length;\
    \ ++i) {\n            u32 j = ((val>>(bit_length-1-i)) & 1);\n            if(j)\
    \ {\n                k+=size(curr->left);\n                if(curr->right != nullptr)\
    \ {\n                    curr = curr->right;\n                }\n            \
    \    else {\n                    return k;\n                }\n            }\n\
    \            else {\n                if(curr->left != nullptr) {\n           \
    \         curr = curr->left;\n                }\n                else {\n    \
    \                return k;\n                }\n            }\n        }\n    \
    \    return val;\n    }\n};\n"
  code: "/*\n * @title SimpleBinaryTrie\n * @docs md/12-binary-search-tree/SimpleBinaryTrie.md\n\
    \ */\ntemplate<size_t bit_length=20> class SimpleBinaryTrie {\n    using u32 =\
    \ unsigned int;\n    struct Node {\n        Node *left, *right;\n        u32 size;\n\
    \        Node(): size(0) {left=right=nullptr;}\n    };\n    Node* root;\n    u32\
    \ size(Node* node) const {return (node==nullptr ? 0 : node->size);}\n    u32 empty(Node*\
    \ node) const {return size(node) == 0;}\npublic:\n    SimpleBinaryTrie(): root(new\
    \ Node) {}\n    void insert(const u32 val) {\n        Node* curr = root;\n   \
    \     stack<Node*> st;\n        for(u32 i=0; i < bit_length; ++i) {\n        \
    \    u32 j = ((val>>(bit_length-1-i)) & 1);\n            st.push(curr);\n    \
    \        if(j) {\n                if(curr->right != nullptr) {\n             \
    \       curr = curr->right;\n                }\n                else {\n     \
    \               Node* next = new Node();\n                    curr->right = next;\n\
    \                    curr = next;\n                }\n            }\n        \
    \    else {\n                if(curr->left != nullptr) {\n                   \
    \ curr = curr->left;\n                }\n                else {\n            \
    \        Node* next = new Node();\n                    curr->left = next;\n  \
    \                  curr = next;\n                }\n            }\n        }\n\
    \        curr->size += 1;\n        while(st.size()) {\n            auto node=st.top();\
    \ st.pop();\n            node->size = size(node->left) + size(node->right);\n\
    \        }\n    }\n    void erase(const u32 val) {\n        Node* curr = root;\n\
    \        stack<Node*> st;\n        for(u32 i=0; i < bit_length; ++i) {\n     \
    \       u32 j = ((val>>(bit_length-1-i)) & 1);\n            st.push(curr);\n \
    \           if(j) {\n                if(curr->right != nullptr) {\n          \
    \          curr = curr->right;\n                }\n                else {\n  \
    \                  return;\n                }\n            }\n            else\
    \ {\n                if(curr->left != nullptr) {\n                    curr = curr->left;\n\
    \                }\n                else {\n                    return;\n    \
    \            }\n            }\n        }\n        if(empty(curr)) return;\n  \
    \      curr->size -= 1;\n        while(st.size()) {\n            auto node=st.top();\
    \ st.pop();\n            node->size = size(node->left) + size(node->right);\n\
    \        }\n    }\n    u32 size() const {return size(root);}\n    u32 kth_smallest(u32\
    \ k) {\n        Node* curr = root;\n        u32 val=0;\n        for(u32 i=0; i\
    \ < bit_length; ++i) {\n            u32 j = 1U << (bit_length-1-i);\n        \
    \    u32 sz_l = size(curr->left);\n            if(k<sz_l) {\n                curr\
    \ = curr->left;\n            }\n            else {\n                val |= j;\n\
    \                k -= sz_l;\n                curr = curr->right;\n           \
    \ }\n        }\n        return val;\n    }\n    u32 lower_bound(const u32 val)\
    \ {\n        Node* curr = root;\n        u32 k=0;\n        for(u32 i=0; i < bit_length;\
    \ ++i) {\n            u32 j = ((val>>(bit_length-1-i)) & 1);\n            if(j)\
    \ {\n                k+=size(curr->left);\n                if(curr->right != nullptr)\
    \ {\n                    curr = curr->right;\n                }\n            \
    \    else {\n                    return k;\n                }\n            }\n\
    \            else {\n                if(curr->left != nullptr) {\n           \
    \         curr = curr->left;\n                }\n                else {\n    \
    \                return k;\n                }\n            }\n        }\n    \
    \    return val;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/12-binary-search-tree/SimpleBinaryTrie.cpp
  requiredBy: []
  timestamp: '2023-06-17 04:07:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/12-binary-search-tree/SimpleBinaryTrie.cpp
layout: document
redirect_from:
- /library/lib/12-binary-search-tree/SimpleBinaryTrie.cpp
- /library/lib/12-binary-search-tree/SimpleBinaryTrie.cpp.html
title: SimpleBinaryTrie
---
