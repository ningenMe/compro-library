---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data-structure/data-structure/BinaryTrie.cpp
    title: BinaryTrie
  - icon: ':heavy_check_mark:'
    path: lib/operator/monoid/MonoidRangeSumPointAdd.cpp
    title: "MonoidRangeSumPointAdd - [\u533A\u9593\u548C, \u4E00\u70B9\u66F4\u65B0\
      ]"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/data-structure/data-structure/BinaryTrie-set-xor-min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ <vector>\n#include <iostream>\n#include <stack>\nusing namespace std;\n#line\
    \ 1 \"lib/data-structure/data-structure/BinaryTrie.cpp\"\n/*\n * @title BinaryTrie\n\
    \ * @docs md/segment/BinaryTrie.md\n */\ntemplate<class Operator, int bit=60>\
    \ class BinaryTrie{\n\tusing TypeNode = typename Operator::TypeNode; \npublic:\n\
    \tvector<TypeNode> node;\n\tvector<vector<int>> ch;\n\tBinaryTrie():node(1),ch(1,vector<int>(2,-1)){}\n\
    \tvoid operate(long long idx, const TypeNode var) {\n\t\tint curr=0;\n\t\tstack<int>\
    \ st;\n\t\tfor(int i=bit-1; 0 <= i; --i) {\n\t\t\tst.push(curr);\n\t\t\tint f=(idx>>i)&1;\n\
    \t\t\tif(ch[curr][f]==-1) {\n\t\t\t\tnode.push_back(Operator::unit_node);\n\t\t\
    \t\tch.push_back(vector<int>(2,-1));\n\t\t\t\tch[curr][f] = (int)node.size()-1;\n\
    \t\t\t}\n\t\t\tcurr = ch[curr][f];\n\t\t}\n\t\tnode[curr] = Operator::func_operate(node[curr],var);\n\
    \t\twhile(st.size()) {\n\t\t\tcurr = st.top(); st.pop();\n\t\t\tnode[curr]=Operator::unit_node;\n\
    \t\t\tif(ch[curr][0]!=-1)\tnode[curr] = Operator::func_fold(node[ch[curr][0]],node[curr]);\n\
    \t\t\tif(ch[curr][1]!=-1)\tnode[curr] = Operator::func_fold(node[curr],node[ch[curr][1]]);\n\
    \t\t}\n\t}\n\tTypeNode fold(long long idx) {\n\t\tint curr=0;\n\t\tfor(int i=bit-1;\
    \ 0 <= i; --i) {\n\t\t\tint f=(idx>>i)&1;\n\t\t\tif(ch[curr][f]!=-1) curr = ch[curr][f];\n\
    \t\t\telse return Operator::unit_node;\n\t\t}\n\t\treturn node[curr];\n\t}\n\t\
    long long min_bitwise_xor(long long x) {\n\t\tint curr=0;\n\t\tlong long y=0;\n\
    \t\tfor(int i=bit-1; 0 <= i; --i) {\n\t\t\tlong long f=(x>>i)&1;\n\t\t\tif(!node[curr])\
    \ break;\n\t\t\tif(ch[curr][f]!=-1 && node[ch[curr][f]]) curr = ch[curr][f];\n\
    \t\t\telse curr = ch[curr][f^=1];\n\t\t\ty^=(f<<i);\n\t\t}\n\t\treturn y^x;\n\t\
    }\n};\n#line 1 \"lib/operator/monoid/MonoidRangeSumPointAdd.cpp\"\n/*\n * @title\
    \ MonoidRangeSumPointAdd - [\u533A\u9593\u548C, \u4E00\u70B9\u66F4\u65B0]\n *\
    \ @docs md/operator/monoid/MonoidRangeSumPointAdd.md\n */\ntemplate<class T> struct\
    \ MonoidRangeSumPointAdd {\n    using TypeNode = T;\n    inline static constexpr\
    \ TypeNode unit_node = 0;\n    inline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return l+r;}\n    inline static constexpr TypeNode func_operate(TypeNode\
    \ l,TypeNode r){return l+r;}\n    inline static constexpr bool func_check(TypeNode\
    \ nodeVal,TypeNode var){return var == nodeVal;}\n};\n#line 9 \"test/data-structure/data-structure/BinaryTrie-set-xor-min.test.cpp\"\
    \nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\tBinaryTrie<MonoidRangeSumPointAdd<int>,30>\
    \ trie;\n\tint Q; cin >> Q;\n\twhile (Q--){\n\t\tint q; cin >> q;\n\t\tlong long\
    \ x; cin >> x;\n\t\tif(q==0) {\n\t\t\tlong long y=trie.fold(x);\n\t\t\tif(!y)\
    \ trie.operate(x,1);\n\t\t}\n\t\tif(q==1) {\n\t\t\tlong long y=trie.fold(x);\n\
    \t\t\tif(y) trie.operate(x,-1);\n\t\t}\n\t\tif(q==2) {\n\t\t\tcout << trie.min_bitwise_xor(x)\
    \ << endl;\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ <vector>\n#include <iostream>\n#include <stack>\nusing namespace std;\n#include\
    \ \"../../../lib/data-structure/data-structure/BinaryTrie.cpp\"\n#include \"../../../lib/operator/monoid/MonoidRangeSumPointAdd.cpp\"\
    \nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\tBinaryTrie<MonoidRangeSumPointAdd<int>,30>\
    \ trie;\n\tint Q; cin >> Q;\n\twhile (Q--){\n\t\tint q; cin >> q;\n\t\tlong long\
    \ x; cin >> x;\n\t\tif(q==0) {\n\t\t\tlong long y=trie.fold(x);\n\t\t\tif(!y)\
    \ trie.operate(x,1);\n\t\t}\n\t\tif(q==1) {\n\t\t\tlong long y=trie.fold(x);\n\
    \t\t\tif(y) trie.operate(x,-1);\n\t\t}\n\t\tif(q==2) {\n\t\t\tcout << trie.min_bitwise_xor(x)\
    \ << endl;\n\t\t}\n\t}\n}"
  dependsOn:
  - lib/data-structure/data-structure/BinaryTrie.cpp
  - lib/operator/monoid/MonoidRangeSumPointAdd.cpp
  isVerificationFile: true
  path: test/data-structure/data-structure/BinaryTrie-set-xor-min.test.cpp
  requiredBy: []
  timestamp: '2021-04-26 18:11:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/data-structure/BinaryTrie-set-xor-min.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/data-structure/BinaryTrie-set-xor-min.test.cpp
- /verify/test/data-structure/data-structure/BinaryTrie-set-xor-min.test.cpp.html
title: test/data-structure/data-structure/BinaryTrie-set-xor-min.test.cpp
---
