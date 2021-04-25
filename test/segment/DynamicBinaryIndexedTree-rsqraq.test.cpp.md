---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/segment/DynamicBinaryIndexedTree.cpp
    title: DynamicBinaryIndexedTree
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
    \ std;\n#line 1 \"lib/segment/DynamicBinaryIndexedTree.cpp\"\n/*\n * @title DynamicBinaryIndexedTree\n\
    \ * @docs md/segment/DynamicBinaryIndexedTree.md\n */\ntemplate<class Operator>\
    \ class DynamicBinaryIndexedTree {\n\tusing TypeNode = typename Operator::TypeNode;\n\
    \    using i64 = long long;\n\tsize_t depth;         \n\ti64 length;\n\ti64 num;\n\
    \n    unordered_map<i64,TypeNode> node;\npublic:\n\t\n\t//[0,N) constructed, inplace\
    \ [0,1) + [1,N+1)\n\t//you can ignore inplace offset\n\tDynamicBinaryIndexedTree(const\
    \ i64 num) : num(num) {\n\t\tfor (depth = 1,length = 1; length < num; depth++,length\
    \ *= 2);\n\t}\n \n\t//[idx,idx+1) update \n\tvoid update(i64 idx, TypeNode var)\
    \ {\n\t\tassert(0 <= idx && idx < length);\n\t\tfor (++idx; idx <= length; idx\
    \ += idx & -idx) node[idx] = Operator::func_node(node[idx],var);\n\t}\n\n\t//[0,idx)\
    \ get\n\tTypeNode get(i64 idx) {\n\t\tTypeNode ret = Operator::unit_node;\n\t\t\
    for (idx = min(length,idx); idx > 0; idx -= idx & -idx) ret = Operator::func_node(ret,node[idx]);\n\
    \t\treturn ret;\n\t}\n\n\t//[l,r) get\n\tTypeNode get(i64 l, i64 r) {\n      \
    \  TypeNode val = get(r);\n        if(l>0) val = Operator::func_node_inv(val,get(l));\n\
    \        return val;\n\t}\n\n\tvoid print() {\n\t\tcout << \"{ \" << get(1);\n\
    \t\tfor(int i = 1; i < length; ++i) cout << \", \" << get(i+1);\n\t\tcout << \"\
    \ }\" << endl;\n\t}\n};\n\ntemplate<class T> struct NodePrefixSumPointAdd {\n\t\
    using TypeNode = T;\n\tinline static constexpr TypeNode unit_node = 0;\n\tinline\
    \ static constexpr TypeNode func_node(const TypeNode& l,const TypeNode& r){return\
    \ l+r;}\n\tinline static constexpr TypeNode func_node_inv(const TypeNode& l,const\
    \ TypeNode& r){return l-r;}\n};\n#line 9 \"test/segment/DynamicBinaryIndexedTree-rsqraq.test.cpp\"\
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
  timestamp: '2021-04-25 16:55:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segment/DynamicBinaryIndexedTree-rsqraq.test.cpp
layout: document
redirect_from:
- /verify/test/segment/DynamicBinaryIndexedTree-rsqraq.test.cpp
- /verify/test/segment/DynamicBinaryIndexedTree-rsqraq.test.cpp.html
title: test/segment/DynamicBinaryIndexedTree-rsqraq.test.cpp
---
