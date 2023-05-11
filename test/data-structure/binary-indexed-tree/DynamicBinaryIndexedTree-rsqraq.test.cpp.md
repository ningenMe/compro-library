---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree.cpp
    title: "DynamicBinaryIndexedTree - \u52D5\u7684BIT"
  - icon: ':heavy_check_mark:'
    path: lib/operator/abel/AbelPrefixSumPointAdd.cpp
    title: AbelPrefixSumPointAdd
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
  bundledCode: "#line 1 \"test/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree-rsqraq.test.cpp\"\
    \n#define PROBLEM \"https://yukicoder.me/problems/no/789\"\n\n#include <vector>\n\
    #include <iostream>\n#include <cassert>\n#include <unordered_map>\nusing namespace\
    \ std;\n#line 1 \"lib/operator/abel/AbelPrefixSumPointAdd.cpp\"\n/*\n * @title\
    \ AbelPrefixSumPointAdd\n * @docs md/operator/abel/AbelPrefixSumPointAdd.md\n\
    \ */\ntemplate<class T> struct AbelPrefixSumPointAdd {\n    using TypeNode = T;\n\
    \    inline static constexpr TypeNode unit_node = 0;\n    inline static constexpr\
    \ TypeNode func_fold(const TypeNode& l,const TypeNode& r){return l+r;}\n    inline\
    \ static constexpr TypeNode func_fold_inv(const TypeNode& l,const TypeNode& r){return\
    \ l-r;}\n};\n#line 1 \"lib/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree.cpp\"\
    \n/*\n * @title DynamicBinaryIndexedTree - \u52D5\u7684BIT\n * @docs md/segment/DynamicBinaryIndexedTree.md\n\
    \ */\ntemplate<class Abel> class DynamicBinaryIndexedTree {\n    using TypeNode\
    \ = typename Abel::TypeNode;\n    using i64 = long long;\n    i64 length;\n\n\
    \    unordered_map<i64,TypeNode> node;\npublic:\n\n    //[0,N) constructed, inplace\
    \ [0,1) + [1,N+1)\n    //you can ignore inplace offset\n    DynamicBinaryIndexedTree(const\
    \ i64 num) {\n        for (length = 1; length < num; length *= 2);\n    }\n\n\
    \    //[idx,idx+1) operate\n    void operate(i64 idx, TypeNode var) {\n      \
    \  assert(0 <= idx && idx < length);\n        for (++idx; idx <= length; idx +=\
    \ idx & -idx) node[idx] = Abel::func_fold(node[idx],var);\n    }\n\n    //[0,idx)\
    \ fold\n    TypeNode fold(i64 idx) {\n        TypeNode ret = Abel::unit_node;\n\
    \        for (idx = min(length,idx); idx > 0; idx -= idx & -idx) ret = Abel::func_fold(ret,node[idx]);\n\
    \        return ret;\n    }\n\n    //[l,r) fold\n    TypeNode fold(i64 l, i64\
    \ r) {\n        return Abel::func_fold_inv(fold(r),fold(l));\n    }\n\n    void\
    \ print() {\n        cout << \"{ \" << fold(1);\n        for(int i = 1; i < length;\
    \ ++i) cout << \", \" << fold(i+1);\n        cout << \" }\" << endl;\n    }\n\
    };\n#line 10 \"test/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree-rsqraq.test.cpp\"\
    \n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    DynamicBinaryIndexedTree<AbelPrefixSumPointAdd<long\
    \ long>> seg(1000000010);\n    int N; cin >> N;\n    long long ans = 0;\n    while(N--)\
    \ {\n        int q,l,r; cin >> q >> l >> r;\n        if(q==0) seg.operate(l,r);\n\
    \        else ans += seg.fold(l,r+1);\n    }\n    cout << ans << endl;\n    return\
    \ 0; \n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/789\"\n\n#include <vector>\n\
    #include <iostream>\n#include <cassert>\n#include <unordered_map>\nusing namespace\
    \ std;\n#include \"../../../lib/operator/abel/AbelPrefixSumPointAdd.cpp\"\n#include\
    \ \"../../../lib/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree.cpp\"\
    \n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    DynamicBinaryIndexedTree<AbelPrefixSumPointAdd<long\
    \ long>> seg(1000000010);\n    int N; cin >> N;\n    long long ans = 0;\n    while(N--)\
    \ {\n        int q,l,r; cin >> q >> l >> r;\n        if(q==0) seg.operate(l,r);\n\
    \        else ans += seg.fold(l,r+1);\n    }\n    cout << ans << endl;\n    return\
    \ 0; \n}"
  dependsOn:
  - lib/operator/abel/AbelPrefixSumPointAdd.cpp
  - lib/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree.cpp
  isVerificationFile: true
  path: test/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree-rsqraq.test.cpp
  requiredBy: []
  timestamp: '2023-05-12 03:08:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree-rsqraq.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree-rsqraq.test.cpp
- /verify/test/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree-rsqraq.test.cpp.html
title: test/data-structure/binary-indexed-tree/DynamicBinaryIndexedTree-rsqraq.test.cpp
---
