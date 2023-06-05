---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/15-queue/RadixHeap.cpp
    title: "RadixHeap - \u975E\u8CA0\u6574\u6570heap"
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
  bundledCode: "#line 1 \"test/queue/RadixHeap-32bit.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0596\"\n\n#include <vector>\n\
    #include <iostream>\n#include <array>\n#include <algorithm>\nusing namespace std;\n\
    #line 1 \"lib/15-queue/RadixHeap.cpp\"\n\n/*\n * @title RadixHeap - \u975E\u8CA0\
    \u6574\u6570heap\n * @docs md/queue/RadixHeap.md\n */\ntemplate<class T, class\
    \ Key = unsigned long long> class RadixHeap{\n    using TypeNode = pair<Key, T>;\n\
    \    template<class InnerKey, class ZZ=InnerKey> class Inner{};\n    template<class\
    \ InnerKey> class Inner<InnerKey, unsigned long long>{\n        array<vector<TypeNode>,65>\
    \ vq;\n        unsigned long long size_num;\n        TypeNode last;\n        inline\
    \ int bit(unsigned long long a) { return a ? 64 - __builtin_clzll(a) : 0;}\n \
    \   public:\n        Inner(T mini) : size_num(0), last(make_pair(0, mini)) {}\n\
    \        inline bool empty() { return size_num == 0; }\n        inline size_t\
    \ size(){ return size_num; }\n        inline void push(TypeNode x){ ++size_num;\
    \ vq[bit(x.first^last.first)].push_back(x);}\n        inline void emplace(unsigned\
    \ long long key,T val){ ++size_num; vq[bit(key^last.first)].emplace_back(key,val);}\n\
    \        inline TypeNode pop() {\n            if(vq[0].empty()) {\n          \
    \      int i = 1;\n                while(vq[i].empty()) ++i;\n               \
    \ last = *min_element(vq[i].begin(),vq[i].end());\n                for(auto &p\
    \ : vq[i]) vq[bit(p.first ^ last.first)].push_back(p);\n                vq[i].clear();\n\
    \            }\n            --size_num;\n            auto res = vq[0].back();\
    \ vq[0].pop_back();\n            return res;\n        }\n    };\n    template<class\
    \ InnerKey> class Inner<InnerKey, unsigned int>{\n        array<vector<TypeNode>,33>\
    \ vq;\n        unsigned int size_num;\n        TypeNode last;\n        inline\
    \ int bit(unsigned int a) { return a ? 32 - __builtin_clz(a) : 0;}\n    public:\n\
    \        Inner(T mini) : size_num(0), last(make_pair(0, mini)) {}\n        inline\
    \ bool empty() { return size_num == 0; }\n        inline size_t size(){ return\
    \ size_num; }\n        inline void push(TypeNode x){ ++size_num; vq[bit(x.first^last.first)].push_back(x);}\n\
    \        inline void emplace(unsigned int key,T val){ ++size_num; vq[bit(key^last.first)].emplace_back(key,val);}\n\
    \        inline TypeNode pop() {\n            if(vq[0].empty()) {\n          \
    \      int i = 1;\n                while(vq[i].empty()) ++i;\n               \
    \ last = *min_element(vq[i].begin(),vq[i].end());\n                for(auto &p\
    \ : vq[i]) vq[bit(p.first ^ last.first)].push_back(p);\n                vq[i].clear();\n\
    \            }\n            --size_num;\n            auto res = vq[0].back();\
    \ vq[0].pop_back();\n            return res;\n        }\n    };\n    Inner<Key,Key>\
    \ inner;\npublic:\n    RadixHeap(T mini) : inner(mini) {}\n    inline bool empty()\
    \ { return inner.empty();}\n    inline size_t size(){ return inner.size();}\n\
    \    inline void push(TypeNode x){ inner.push(x);}\n    inline void emplace(unsigned\
    \ long long key,T val){ inner.emplace(key,val);}\n    inline TypeNode pop() {\
    \ return inner.pop(); }\n};\n#line 9 \"test/queue/RadixHeap-32bit.test.cpp\"\n\
    \nint main(void){\n\tcin.tie(0);ios::sync_with_stdio(false);\n\tint N,K; cin >>\
    \ N >> K;\n\tvector<int> C(N),R(N);\n\tfor(int i = 0; i < N; ++i) cin >> C[i]\
    \ >> R[i];\n\tvector<vector<int>> edge(N);\n\tfor(int i = 0; i < K; ++i) {\n\t\
    \tint A,B; cin >> A >> B;\n\t\tA--,B--;\n\t\tedge[A].push_back(B);\n\t\tedge[B].push_back(A);\n\
    \t}\n\tvector<vector<int>> dp(N,vector<int>(N+1,1<<30));\n\tdp[0][0] = 0;\n\t\
    RadixHeap<pair<int,int>, unsigned int> pq({0,0});\n\tpq.push({0,{0,0}});\n\twhile(pq.size()){\n\
    \t\tauto p = pq.pop();\n\t\tint from = p.second.first;\n\t\tint r = p.second.second;\n\
    \t\tif(r){\n\t\t\tfor(int to:edge[from]){\n\t\t\t\tif(dp[to][r-1]>dp[from][r]){\n\
    \t\t\t\t\tdp[to][r-1]=dp[from][r];\n\t\t\t\t\tpq.push({dp[to][r-1],{to,r-1}});\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tif(dp[from][R[from]]>dp[from][r]+C[from]){\n\t\t\
    \tdp[from][R[from]]=dp[from][r]+C[from];\n\t\t\tpq.push({dp[from][R[from]],{from,R[from]}});\n\
    \t\t}\n\t}\n\tcout << *min_element(dp[N-1].begin(),dp[N-1].end()) << endl;\n\t\
    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0596\"\
    \n\n#include <vector>\n#include <iostream>\n#include <array>\n#include <algorithm>\n\
    using namespace std;\n#include \"../../lib/15-queue/RadixHeap.cpp\"\n\nint main(void){\n\
    \tcin.tie(0);ios::sync_with_stdio(false);\n\tint N,K; cin >> N >> K;\n\tvector<int>\
    \ C(N),R(N);\n\tfor(int i = 0; i < N; ++i) cin >> C[i] >> R[i];\n\tvector<vector<int>>\
    \ edge(N);\n\tfor(int i = 0; i < K; ++i) {\n\t\tint A,B; cin >> A >> B;\n\t\t\
    A--,B--;\n\t\tedge[A].push_back(B);\n\t\tedge[B].push_back(A);\n\t}\n\tvector<vector<int>>\
    \ dp(N,vector<int>(N+1,1<<30));\n\tdp[0][0] = 0;\n\tRadixHeap<pair<int,int>, unsigned\
    \ int> pq({0,0});\n\tpq.push({0,{0,0}});\n\twhile(pq.size()){\n\t\tauto p = pq.pop();\n\
    \t\tint from = p.second.first;\n\t\tint r = p.second.second;\n\t\tif(r){\n\t\t\
    \tfor(int to:edge[from]){\n\t\t\t\tif(dp[to][r-1]>dp[from][r]){\n\t\t\t\t\tdp[to][r-1]=dp[from][r];\n\
    \t\t\t\t\tpq.push({dp[to][r-1],{to,r-1}});\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tif(dp[from][R[from]]>dp[from][r]+C[from]){\n\
    \t\t\tdp[from][R[from]]=dp[from][r]+C[from];\n\t\t\tpq.push({dp[from][R[from]],{from,R[from]}});\n\
    \t\t}\n\t}\n\tcout << *min_element(dp[N-1].begin(),dp[N-1].end()) << endl;\n\t\
    return 0;\n}"
  dependsOn:
  - lib/15-queue/RadixHeap.cpp
  isVerificationFile: true
  path: test/queue/RadixHeap-32bit.test.cpp
  requiredBy: []
  timestamp: '2023-06-05 21:57:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/queue/RadixHeap-32bit.test.cpp
layout: document
redirect_from:
- /verify/test/queue/RadixHeap-32bit.test.cpp
- /verify/test/queue/RadixHeap-32bit.test.cpp.html
title: test/queue/RadixHeap-32bit.test.cpp
---
