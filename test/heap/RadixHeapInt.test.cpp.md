---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/heap/RadixHeapInt.cpp
    title: "RadixHeapInt - 32bit\u578B\u975E\u8CA0\u6574\u6570heap"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0596
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0596
  bundledCode: "#line 1 \"test/heap/RadixHeapInt.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0596\"\
    \n\n#include <vector>\n#include <iostream>\n#include <algorithm>\n#include <array>\n\
    using namespace std;\n#line 1 \"lib/heap/RadixHeapInt.cpp\"\n/*\n * @title RadixHeapInt\
    \ - 32bit\u578B\u975E\u8CA0\u6574\u6570heap\n * @docs md/heap/RadixHeapInt.md\n\
    \ */\ntemplate<class T> class RadixHeapInt{\n    using TypeNode = pair<unsigned\
    \ int, T>;\n    array<vector<TypeNode>,33> vq;\n    unsigned int size_num;\n \
    \   TypeNode last;\n    inline int bit(int a) {\n        return a ? 32 - __builtin_clz(a)\
    \ : 0;\n    }\npublic:\n    RadixHeapInt(T mini) : size_num(0), last(make_pair(0,mini))\
    \ {\n        // do nothing\n    }\n    inline bool empty() {\n        return size_num\
    \ == 0;\n    }\n    inline size_t size(){\n        return size_num;\n    }\n \
    \   inline void push(TypeNode x){\n        ++size_num;\n        vq[bit(x.first^last.first)].push_back(x);\n\
    \    }\n    inline void emplace(unsigned int key,T val){\n        ++size_num;\n\
    \        vq[bit(key^last.first)].emplace_back(key,val);\n    }\n    inline TypeNode\
    \ pop() {\n        if(vq[0].empty()) {\n            int i = 1;\n            while(vq[i].empty())\
    \ ++i;\n            last = *min_element(vq[i].begin(),vq[i].end());\n        \
    \    for(auto &p : vq[i]) vq[bit(p.first ^ last.first)].push_back(p);\n      \
    \      vq[i].clear();\n        }\n        --size_num;\n        auto res = vq[0].back();\n\
    \        vq[0].pop_back();\n        return res;\n    }\n};\n#line 9 \"test/heap/RadixHeapInt.test.cpp\"\
    \n\nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\tint N,K; cin\
    \ >> N >> K;\n\tvector<int> C(N),R(N);\n\tfor(int i = 0; i < N; ++i) cin >> C[i]\
    \ >> R[i];\n\tvector<vector<int>> edge(N);\n\tfor(int i = 0; i < K; ++i) {\n\t\
    \tint A,B; cin >> A >> B;\n\t\tA--,B--;\n\t\tedge[A].push_back(B);\n\t\tedge[B].push_back(A);\n\
    \t}\n\tvector<vector<int>> dp(N,vector<int>(N+1,1<<30));\n\tdp[0][0] = 0;\n\t\
    RadixHeapInt<pair<int,int>> pq({0,0});\n\tpq.push({0,{0,0}});\n\twhile(pq.size()){\n\
    \t\tauto p = pq.pop();\n\t\tint from = p.second.first;\n\t\tint r = p.second.second;\n\
    \t\tif(r){\n\t\t\tfor(int to:edge[from]){\n\t\t\t\tif(dp[to][r-1]>dp[from][r]){\n\
    \t\t\t\t\tdp[to][r-1]=dp[from][r];\n\t\t\t\t\tpq.push({dp[to][r-1],{to,r-1}});\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tif(dp[from][R[from]]>dp[from][r]+C[from]){\n\t\t\
    \tdp[from][R[from]]=dp[from][r]+C[from];\n\t\t\tpq.push({dp[from][R[from]],{from,R[from]}});\n\
    \t\t}\n\t}\n\tcout << *min_element(dp[N-1].begin(),dp[N-1].end()) << endl;\n\t\
    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0596\"\
    \n\n#include <vector>\n#include <iostream>\n#include <algorithm>\n#include <array>\n\
    using namespace std;\n#include \"../../lib/heap/RadixHeapInt.cpp\"\n\nint main(void){\n\
    \tcin.tie(0);ios::sync_with_stdio(false);\n\tint N,K; cin >> N >> K;\n\tvector<int>\
    \ C(N),R(N);\n\tfor(int i = 0; i < N; ++i) cin >> C[i] >> R[i];\n\tvector<vector<int>>\
    \ edge(N);\n\tfor(int i = 0; i < K; ++i) {\n\t\tint A,B; cin >> A >> B;\n\t\t\
    A--,B--;\n\t\tedge[A].push_back(B);\n\t\tedge[B].push_back(A);\n\t}\n\tvector<vector<int>>\
    \ dp(N,vector<int>(N+1,1<<30));\n\tdp[0][0] = 0;\n\tRadixHeapInt<pair<int,int>>\
    \ pq({0,0});\n\tpq.push({0,{0,0}});\n\twhile(pq.size()){\n\t\tauto p = pq.pop();\n\
    \t\tint from = p.second.first;\n\t\tint r = p.second.second;\n\t\tif(r){\n\t\t\
    \tfor(int to:edge[from]){\n\t\t\t\tif(dp[to][r-1]>dp[from][r]){\n\t\t\t\t\tdp[to][r-1]=dp[from][r];\n\
    \t\t\t\t\tpq.push({dp[to][r-1],{to,r-1}});\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tif(dp[from][R[from]]>dp[from][r]+C[from]){\n\
    \t\t\tdp[from][R[from]]=dp[from][r]+C[from];\n\t\t\tpq.push({dp[from][R[from]],{from,R[from]}});\n\
    \t\t}\n\t}\n\tcout << *min_element(dp[N-1].begin(),dp[N-1].end()) << endl;\n\t\
    return 0;\n}"
  dependsOn:
  - lib/heap/RadixHeapInt.cpp
  isVerificationFile: true
  path: test/heap/RadixHeapInt.test.cpp
  requiredBy: []
  timestamp: '2023-05-12 02:04:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/heap/RadixHeapInt.test.cpp
layout: document
redirect_from:
- /verify/test/heap/RadixHeapInt.test.cpp
- /verify/test/heap/RadixHeapInt.test.cpp.html
title: test/heap/RadixHeapInt.test.cpp
---
