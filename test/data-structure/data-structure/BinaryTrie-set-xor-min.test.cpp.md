---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data-structure/data-structure/BinaryTrie.cpp
    title: BinaryTrie
  - icon: ':heavy_check_mark:'
    path: lib/operator/monoid/MonoidRangeSumPointAdd.cpp
    title: "MonoidRangeSumPointAdd - [\u533A\u9593\u548C, \u4E00\u70B9\u52A0\u7B97\
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
    \ * @docs md/data-structure/data-structure/BinaryTrie.md\n */\ntemplate<class\
    \ Operator, int bit=60> class BinaryTrie{\n    using TypeNode = typename Operator::TypeNode;\n\
    public:\n    vector<TypeNode> node;\n    vector<vector<int>> ch;\n    BinaryTrie():node(1),ch(1,vector<int>(2,-1)){}\n\
    \    void operate(long long idx, const TypeNode var) {\n        int curr=0;\n\
    \        stack<int> st;\n        for(int i=bit-1; 0 <= i; --i) {\n           \
    \ st.push(curr);\n            int f=(idx>>i)&1;\n            if(ch[curr][f]==-1)\
    \ {\n                node.push_back(Operator::unit_node);\n                ch.push_back(vector<int>(2,-1));\n\
    \                ch[curr][f] = (int)node.size()-1;\n            }\n          \
    \  curr = ch[curr][f];\n        }\n        node[curr] = Operator::func_operate(node[curr],var);\n\
    \        while(st.size()) {\n            curr = st.top(); st.pop();\n        \
    \    node[curr]=Operator::unit_node;\n            if(ch[curr][0]!=-1)\tnode[curr]\
    \ = Operator::func_fold(node[ch[curr][0]],node[curr]);\n            if(ch[curr][1]!=-1)\t\
    node[curr] = Operator::func_fold(node[curr],node[ch[curr][1]]);\n        }\n \
    \   }\n    TypeNode fold(long long idx) {\n        int curr=0;\n        for(int\
    \ i=bit-1; 0 <= i; --i) {\n            int f=(idx>>i)&1;\n            if(ch[curr][f]!=-1)\
    \ curr = ch[curr][f];\n            else return Operator::unit_node;\n        }\n\
    \        return node[curr];\n    }\n    long long min_bitwise_xor(long long x)\
    \ {\n        int curr=0;\n        long long y=0;\n        for(int i=bit-1; 0 <=\
    \ i; --i) {\n            long long f=(x>>i)&1;\n            if(!node[curr]) break;\n\
    \            if(ch[curr][f]!=-1 && node[ch[curr][f]]) curr = ch[curr][f];\n  \
    \          else curr = ch[curr][f^=1];\n            y^=(f<<i);\n        }\n  \
    \      return y^x;\n    }\n};\n#line 1 \"lib/operator/monoid/MonoidRangeSumPointAdd.cpp\"\
    \n/*\n * @title MonoidRangeSumPointAdd - [\u533A\u9593\u548C, \u4E00\u70B9\u52A0\
    \u7B97]\n * @docs md/operator/monoid/MonoidRangeSumPointAdd.md\n */\ntemplate<class\
    \ T> struct MonoidRangeSumPointAdd {\n    using TypeNode = T;\n    inline static\
    \ constexpr TypeNode unit_node = 0;\n    inline static constexpr TypeNode func_fold(TypeNode\
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
  timestamp: '2023-05-12 04:20:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/data-structure/BinaryTrie-set-xor-min.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/data-structure/BinaryTrie-set-xor-min.test.cpp
- /verify/test/data-structure/data-structure/BinaryTrie-set-xor-min.test.cpp.html
title: test/data-structure/data-structure/BinaryTrie-set-xor-min.test.cpp
---
