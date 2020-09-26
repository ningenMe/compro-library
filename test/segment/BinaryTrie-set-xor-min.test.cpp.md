---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/segment/BinaryTrie.cpp
    title: BinaryTrie
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/segment/BinaryTrie-set-xor-min.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include <vector>\n\
    #include <iostream>\n#include <stack>\nusing namespace std;\n#line 1 \"lib/segment/BinaryTrie.cpp\"\
    \n/*\n * @title BinaryTrie\n * @docs md/segment/BinaryTrie.md\n */\ntemplate<class\
    \ Operator, int bit=60> class BinaryTrie{\n\tusing TypeNode = typename Operator::TypeNode;\
    \ \npublic:\n\tvector<TypeNode> node;\n\tvector<vector<int>> ch;\n\tBinaryTrie():node(1),ch(1,vector<int>(2,-1)){}\n\
    \tvoid update(long long idx, const TypeNode var) {\n\t\tint curr=0;\n\t\tstack<int>\
    \ st;\n\t\tfor(int i=bit-1; 0 <= i; --i) {\n\t\t\tst.push(curr);\n\t\t\tint f=(idx>>i)&1;\n\
    \t\t\tif(ch[curr][f]==-1) {\n\t\t\t\tnode.push_back(Operator::unit_node);\n\t\t\
    \t\tch.push_back(vector<int>(2,-1));\n\t\t\t\tch[curr][f] = (int)node.size()-1;\n\
    \t\t\t}\n\t\t\tcurr = ch[curr][f];\n\t\t}\n\t\tnode[curr] = Operator::func_merge(node[curr],var);\n\
    \t\twhile(st.size()) {\n\t\t\tcurr = st.top(); st.pop();\n\t\t\tnode[curr]=Operator::unit_node;\n\
    \t\t\tif(ch[curr][0]!=-1)\tnode[curr] = Operator::func_node(node[ch[curr][0]],node[curr]);\n\
    \t\t\tif(ch[curr][1]!=-1)\tnode[curr] = Operator::func_node(node[curr],node[ch[curr][1]]);\n\
    \t\t}\n\t}\n\tTypeNode get(long long idx) {\n\t\tint curr=0;\n\t\tfor(int i=bit-1;\
    \ 0 <= i; --i) {\n\t\t\tint f=(idx>>i)&1;\n\t\t\tif(ch[curr][f]!=-1) curr = ch[curr][f];\n\
    \t\t\telse return Operator::unit_node;\n\t\t}\n\t\treturn node[curr];\n\t}\n\t\
    long long min_bitwise_xor(long long x) {\n\t\tint curr=0;\n\t\tlong long y=0;\n\
    \t\tfor(int i=bit-1; 0 <= i; --i) {\n\t\t\tlong long f=(x>>i)&1;\n\t\t\tif(!node[curr])\
    \ break;\n\t\t\tif(ch[curr][f]!=-1 && node[ch[curr][f]]) curr = ch[curr][f];\n\
    \t\t\telse curr = ch[curr][f^=1];\n\t\t\ty^=(f<<i);\n\t\t}\n\t\treturn y^x;\n\t\
    }\n};\n\n//\u4E00\u70B9\u52A0\u7B97 \u533A\u9593\u548C\ntemplate<class T> struct\
    \ NodeSumPointAdd {\n\tusing TypeNode = T;\n\tinline static constexpr TypeNode\
    \ unit_node = 0;\n\tinline static constexpr TypeNode func_node(TypeNode l,TypeNode\
    \ r){return l+r;}\n\tinline static constexpr TypeNode func_merge(TypeNode l,TypeNode\
    \ r){return l+r;}\n};\n#line 8 \"test/segment/BinaryTrie-set-xor-min.test.cpp\"\
    \n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\tBinaryTrie<NodeSumPointAdd<int>,30>\
    \ trie;\n\tint Q; cin >> Q;\n\twhile (Q--){\n\t\tint q; cin >> q;\n\t\tlong long\
    \ x; cin >> x;\n\t\tif(q==0) {\n\t\t\tlong long y=trie.get(x);\n\t\t\tif(!y) trie.update(x,1);\n\
    \t\t}\n\t\tif(q==1) {\n\t\t\tlong long y=trie.get(x);\n\t\t\tif(y) trie.update(x,-1);\n\
    \t\t}\n\t\tif(q==2) {\n\t\t\tcout << trie.min_bitwise_xor(x) << endl;\n\t\t}\n\
    \t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ <vector>\n#include <iostream>\n#include <stack>\nusing namespace std;\n#include\
    \ \"../../lib/segment/BinaryTrie.cpp\"\n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\
    \tBinaryTrie<NodeSumPointAdd<int>,30> trie;\n\tint Q; cin >> Q;\n\twhile (Q--){\n\
    \t\tint q; cin >> q;\n\t\tlong long x; cin >> x;\n\t\tif(q==0) {\n\t\t\tlong long\
    \ y=trie.get(x);\n\t\t\tif(!y) trie.update(x,1);\n\t\t}\n\t\tif(q==1) {\n\t\t\t\
    long long y=trie.get(x);\n\t\t\tif(y) trie.update(x,-1);\n\t\t}\n\t\tif(q==2)\
    \ {\n\t\t\tcout << trie.min_bitwise_xor(x) << endl;\n\t\t}\n\t}\n}"
  dependsOn:
  - lib/segment/BinaryTrie.cpp
  isVerificationFile: true
  path: test/segment/BinaryTrie-set-xor-min.test.cpp
  requiredBy: []
  timestamp: '2020-09-26 17:01:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segment/BinaryTrie-set-xor-min.test.cpp
layout: document
redirect_from:
- /verify/test/segment/BinaryTrie-set-xor-min.test.cpp
- /verify/test/segment/BinaryTrie-set-xor-min.test.cpp.html
title: test/segment/BinaryTrie-set-xor-min.test.cpp
---
