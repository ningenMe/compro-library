---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data-structure/binary-indexed-tree/BinaryIndexedTree.cpp
    title: BinaryIndexedTree - BIT
  - icon: ':heavy_check_mark:'
    path: lib/operator/AbelPrefixSumPointAdd.cpp
    title: AbelPrefixSumPointAdd
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/742
    links:
    - https://yukicoder.me/problems/no/742
  bundledCode: "#line 1 \"test/data-structure/binary-indexed-tree/BinaryIndexedTree-rsqraq.test.cpp\"\
    \n#define PROBLEM \"https://yukicoder.me/problems/no/742\"\n\n#include <vector>\n\
    #include <iostream>\n#include <cassert>\nusing namespace std;\n#line 1 \"lib/operator/AbelPrefixSumPointAdd.cpp\"\
    \n/*\n * @title AbelPrefixSumPointAdd\n * @docs md/operator/AbelPrefixSumPointAdd.md\n\
    \ */\ntemplate<class T> struct AbelPrefixSumPointAdd {\n    using TypeNode = T;\n\
    \    inline static constexpr TypeNode unit_node = 0;\n    inline static constexpr\
    \ TypeNode func_fold(const TypeNode& l,const TypeNode& r){return l+r;}\n    inline\
    \ static constexpr TypeNode func_fold_inv(const TypeNode& l,const TypeNode& r){return\
    \ l-r;}\n};\n#line 1 \"lib/data-structure/binary-indexed-tree/BinaryIndexedTree.cpp\"\
    \n/*\n * @title BinaryIndexedTree - BIT\n * @docs md/data-structure/binary-indexed-tree/BinaryIndexedTree.md\n\
    \ */\ntemplate<class Abel> class BinaryIndexedTree {\n\tusing TypeNode = typename\
    \ Abel::TypeNode;\n\tsize_t length;\n\tsize_t num;\n\tvector<TypeNode> node;\n\
    public:\n\t\n\t//[0,N) constructed, inplace [0,1) + [1,N+1)\n\t//you can ignore\
    \ inplace offset\n\tBinaryIndexedTree(const size_t num) : num(num) {\n\t\tfor\
    \ (length = 1; length < num; length *= 2);\n\t\tnode.resize(length+1, Abel::unit_node);\n\
    \t}\n \n\t//[idx,idx+1) operate \n\tvoid operate(size_t idx, TypeNode var) {\n\
    \t\tassert(0 <= idx && idx < length);\n\t\tfor (++idx; idx <= length; idx += idx\
    \ & -idx) node[idx] = Abel::func_fold(node[idx],var);\n\t}\n\n\t//[0,idx) fold\n\
    \tTypeNode fold(size_t idx) {\n\t\tTypeNode ret = Abel::unit_node;\n\t\tfor (idx\
    \ = min(length,idx); idx > 0; idx -= idx & -idx) ret = Abel::func_fold(ret,node[idx]);\n\
    \t\treturn ret;\n\t}\n\n\t//return [0,length]\n\tint binary_search(TypeNode var)\
    \ {\n\t\tif(!Abel::func_check(node.back(),var)) return num;\n\t\tTypeNode ret\
    \ = Abel::unit_node;\n\t\tsize_t off = 0;\n\t\tfor(size_t idx = length; idx; idx\
    \ >>= 1){\n\t\t\tif(off + idx <= length && !Abel::func_check(Abel::func_fold(ret,node[off+idx]),var))\
    \ {\n\t\t\t\toff += idx;\n\t\t\t\tret = Abel::func_fold(ret,node[off]);\n\t\t\t\
    }\n\t\t}\n\t\treturn min(off,num);\n\t}\n\n\tvoid print() {\n\t\tcout << \"{ \"\
    \ << fold(1);\n\t\tfor(int i = 1; i < length; ++i) cout << \", \" << fold(i+1);\n\
    \t\tcout << \" }\" << endl;\n\t}\n};\n#line 9 \"test/data-structure/binary-indexed-tree/BinaryIndexedTree-rsqraq.test.cpp\"\
    \n\nint main(void){\n    int N; cin >> N;\n    vector<int> A(N+1,0);\n    for(int\
    \ i = 1; i <= N; ++i) {\n        cin >> A[i];\n    }\n    BinaryIndexedTree<AbelPrefixSumPointAdd<int>>\
    \ bit(N+1);\n    int ans = 0;\n    for(int i = N; 1 <= i; --i) {\n        ans\
    \ += bit.fold(A[i]);\n        bit.operate(A[i],1);\n    }\n    cout << ans <<\
    \ endl;\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/742\"\n\n#include <vector>\n\
    #include <iostream>\n#include <cassert>\nusing namespace std;\n#include \"../../../lib/operator/AbelPrefixSumPointAdd.cpp\"\
    \n#include \"../../../lib/data-structure/binary-indexed-tree/BinaryIndexedTree.cpp\"\
    \n\nint main(void){\n    int N; cin >> N;\n    vector<int> A(N+1,0);\n    for(int\
    \ i = 1; i <= N; ++i) {\n        cin >> A[i];\n    }\n    BinaryIndexedTree<AbelPrefixSumPointAdd<int>>\
    \ bit(N+1);\n    int ans = 0;\n    for(int i = N; 1 <= i; --i) {\n        ans\
    \ += bit.fold(A[i]);\n        bit.operate(A[i],1);\n    }\n    cout << ans <<\
    \ endl;\n\treturn 0;\n}"
  dependsOn:
  - lib/operator/AbelPrefixSumPointAdd.cpp
  - lib/data-structure/binary-indexed-tree/BinaryIndexedTree.cpp
  isVerificationFile: true
  path: test/data-structure/binary-indexed-tree/BinaryIndexedTree-rsqraq.test.cpp
  requiredBy: []
  timestamp: '2021-04-26 08:53:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/binary-indexed-tree/BinaryIndexedTree-rsqraq.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/binary-indexed-tree/BinaryIndexedTree-rsqraq.test.cpp
- /verify/test/data-structure/binary-indexed-tree/BinaryIndexedTree-rsqraq.test.cpp.html
title: test/data-structure/binary-indexed-tree/BinaryIndexedTree-rsqraq.test.cpp
---
