---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/segment/DynamicBinaryIndexedTree.cpp
    title: "DynamicBinaryIndexedTree - \u52D5\u7684BIT"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/789
    links:
    - https://yukicoder.me/problems/no/789
  bundledCode: "#line 1 \"test/segment/DynamicBinaryIndexedTree-rsqraq.test.cpp\"\n\
    #define PROBLEM \"https://yukicoder.me/problems/no/789\"\n\n#include <vector>\n\
    #include <iostream>\n#include <cassert>\n#include <unordered_map>\nusing namespace\
    \ std;\n#line 1 \"lib/segment/DynamicBinaryIndexedTree.cpp\"\n/*\n * @title DynamicBinaryIndexedTree\
    \ - \u52D5\u7684BIT\n * @docs md/segment/DynamicBinaryIndexedTree.md\n */\ntemplate<class\
    \ Operator> class DynamicBinaryIndexedTree {\n    using TypeNode = typename Operator::TypeNode;\n\
    \    using i64 = long long;\n    i64 length;\n\n    unordered_map<i64,TypeNode>\
    \ node;\npublic:\n    \n    //[0,N) constructed, inplace [0,1) + [1,N+1)\n   \
    \ //you can ignore inplace offset\n    DynamicBinaryIndexedTree(const i64 num)\
    \ {\n        for (length = 1; length < num; length *= 2);\n    }\n \n    //[idx,idx+1)\
    \ update \n    void update(i64 idx, TypeNode var) {\n        assert(0 <= idx &&\
    \ idx < length);\n        for (++idx; idx <= length; idx += idx & -idx) node[idx]\
    \ = Operator::func_node(node[idx],var);\n    }\n\n    //[0,idx) get\n    TypeNode\
    \ get(i64 idx) {\n        TypeNode ret = Operator::unit_node;\n        for (idx\
    \ = min(length,idx); idx > 0; idx -= idx & -idx) ret = Operator::func_node(ret,node[idx]);\n\
    \        return ret;\n    }\n\n    //[l,r) get\n    TypeNode get(i64 l, i64 r)\
    \ {\n        TypeNode val = get(r);\n        if(l>0) val = Operator::func_node_inv(val,get(l));\n\
    \        return val;\n    }\n\n    void print() {\n        cout << \"{ \" << get(1);\n\
    \        for(int i = 1; i < length; ++i) cout << \", \" << get(i+1);\n       \
    \ cout << \" }\" << endl;\n    }\n};\n\ntemplate<class T> struct NodePrefixSumPointAdd\
    \ {\n    using TypeNode = T;\n    inline static constexpr TypeNode unit_node =\
    \ 0;\n    inline static constexpr TypeNode func_node(const TypeNode& l,const TypeNode&\
    \ r){return l+r;}\n    inline static constexpr TypeNode func_node_inv(const TypeNode&\
    \ l,const TypeNode& r){return l-r;}\n};\n#line 9 \"test/segment/DynamicBinaryIndexedTree-rsqraq.test.cpp\"\
    \n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    DynamicBinaryIndexedTree<NodePrefixSumPointAdd<long\
    \ long>> seg(1000000010);\n    int N; cin >> N;\n    long long ans = 0;\n    while(N--)\
    \ {\n        int q,l,r; cin >> q >> l >> r;\n        if(q==0) seg.update(l,r);\n\
    \        else ans += seg.get(l,r+1);\n    }\n    cout << ans << endl;\n    return\
    \ 0; \n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/789\"\n\n#include <vector>\n\
    #include <iostream>\n#include <cassert>\n#include <unordered_map>\nusing namespace\
    \ std;\n#include \"../../lib/segment/DynamicBinaryIndexedTree.cpp\"\n\nint main(void){\n\
    \    cin.tie(0);ios::sync_with_stdio(false);\n    DynamicBinaryIndexedTree<NodePrefixSumPointAdd<long\
    \ long>> seg(1000000010);\n    int N; cin >> N;\n    long long ans = 0;\n    while(N--)\
    \ {\n        int q,l,r; cin >> q >> l >> r;\n        if(q==0) seg.update(l,r);\n\
    \        else ans += seg.get(l,r+1);\n    }\n    cout << ans << endl;\n    return\
    \ 0; \n}"
  dependsOn:
  - lib/segment/DynamicBinaryIndexedTree.cpp
  isVerificationFile: true
  path: test/segment/DynamicBinaryIndexedTree-rsqraq.test.cpp
  requiredBy: []
  timestamp: '2021-04-25 17:02:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segment/DynamicBinaryIndexedTree-rsqraq.test.cpp
layout: document
redirect_from:
- /verify/test/segment/DynamicBinaryIndexedTree-rsqraq.test.cpp
- /verify/test/segment/DynamicBinaryIndexedTree-rsqraq.test.cpp.html
title: test/segment/DynamicBinaryIndexedTree-rsqraq.test.cpp
---
