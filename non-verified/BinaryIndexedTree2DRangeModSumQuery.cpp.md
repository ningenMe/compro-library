---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc130/tasks/abc130_e
  bundledCode: "#line 1 \"non-verified/BinaryIndexedTree2DRangeModSumQuery.cpp\"\n\
    class BinaryIndexedTree2DRangeModSumQuery{\npublic:\n    const int N,M;\n    const\
    \ long long mod;\n    vector<vector<long long>> bit;\n \n    //1-indexed\n   \
    \ BinaryIndexedTree2DRangeModSumQuery(const int& N,const int& M, const long long&\
    \ mod):N(N),M(M),mod(mod),bit(N+1,vector<long long>(M+1,0)){\n        // do nothing\n\
    \    }\n \n    inline long long getvar(const int& i,const int& j){\n        long\
    \ long val = 0;\n        for(int y=i;y>0;y-=(y&-y)) for(int x=j;x>0;x-=(x&-x))\
    \ {\n            val += bit[y][x];\n            if(val >= mod) val -= mod;\n \
    \       }\n        return val;\n    }\n \n    // [x1,x2] * [y1,y2] 1-indexed\n\
    \    inline long long getvar(const int& y1,const int& y2,const int& x1,const int&\
    \ x2){\n        long long res = getvar(y1-1,x1-1);\n        res -= getvar(y1-1,x2);\n\
    \        if(res < 0) res += mod;\n        res -= getvar(y2,x1-1);\n        if(res\
    \ < 0) res += mod;\n        res += getvar(y2,x2);\n        if(res >= mod) res\
    \ -= mod;\n        return res;\n    }\n \n    //add\n    inline void update(const\
    \ int& i,const int& j,long long val){\n        if(i==0||j==0) return;\n      \
    \  if(val>=mod) val -= mod;\n        if(val < 0) val += mod;\n        for(int\
    \ y=i;y<=N;y+=(y&-y)) for(int x=j;x<=M;x+=(x&-x)) {\n            bit[y][x]+=val;\n\
    \            if(bit[y][x] >= mod) bit[y][x] -= mod;\n        }\n    }\n \n};\n\
    \n//verify https://atcoder.jp/contests/abc130/tasks/abc130_e\n"
  code: "class BinaryIndexedTree2DRangeModSumQuery{\npublic:\n    const int N,M;\n\
    \    const long long mod;\n    vector<vector<long long>> bit;\n \n    //1-indexed\n\
    \    BinaryIndexedTree2DRangeModSumQuery(const int& N,const int& M, const long\
    \ long& mod):N(N),M(M),mod(mod),bit(N+1,vector<long long>(M+1,0)){\n        //\
    \ do nothing\n    }\n \n    inline long long getvar(const int& i,const int& j){\n\
    \        long long val = 0;\n        for(int y=i;y>0;y-=(y&-y)) for(int x=j;x>0;x-=(x&-x))\
    \ {\n            val += bit[y][x];\n            if(val >= mod) val -= mod;\n \
    \       }\n        return val;\n    }\n \n    // [x1,x2] * [y1,y2] 1-indexed\n\
    \    inline long long getvar(const int& y1,const int& y2,const int& x1,const int&\
    \ x2){\n        long long res = getvar(y1-1,x1-1);\n        res -= getvar(y1-1,x2);\n\
    \        if(res < 0) res += mod;\n        res -= getvar(y2,x1-1);\n        if(res\
    \ < 0) res += mod;\n        res += getvar(y2,x2);\n        if(res >= mod) res\
    \ -= mod;\n        return res;\n    }\n \n    //add\n    inline void update(const\
    \ int& i,const int& j,long long val){\n        if(i==0||j==0) return;\n      \
    \  if(val>=mod) val -= mod;\n        if(val < 0) val += mod;\n        for(int\
    \ y=i;y<=N;y+=(y&-y)) for(int x=j;x<=M;x+=(x&-x)) {\n            bit[y][x]+=val;\n\
    \            if(bit[y][x] >= mod) bit[y][x] -= mod;\n        }\n    }\n \n};\n\
    \n//verify https://atcoder.jp/contests/abc130/tasks/abc130_e"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/BinaryIndexedTree2DRangeModSumQuery.cpp
  requiredBy: []
  timestamp: '2021-04-21 01:33:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/BinaryIndexedTree2DRangeModSumQuery.cpp
layout: document
redirect_from:
- /library/non-verified/BinaryIndexedTree2DRangeModSumQuery.cpp
- /library/non-verified/BinaryIndexedTree2DRangeModSumQuery.cpp.html
title: non-verified/BinaryIndexedTree2DRangeModSumQuery.cpp
---
