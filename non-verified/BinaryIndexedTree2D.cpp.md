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
  bundledCode: "#line 1 \"non-verified/BinaryIndexedTree2D.cpp\"\ntemplate<class T>\
    \ class BinaryIndexedTree2D {\n//\u62BD\u8C61\u5316\u3057\u3066\u306A\u3044\u3000\
    \u4E00\u70B9\u52A0\u7B97\u3001\u533A\u9593\u7DCF\u548C\u306E\u307F\n\tconst int\
    \ N,M;\n\tvector<vector<T>> node;\n\npublic:\n    //1-indexed\n    BinaryIndexedTree2D(const\
    \ int& N,const int& M):N(N),M(M),node(N+1,vector<T>(M+1,0)){\n        // do nothing\n\
    \    }\n \n    inline T getvar(const int i,const int j){\n        T res = 0;\n\
    \        for(int y=i;y>0;y-=(y&-y)) for(int x=j;x>0;x-=(x&-x)) {\n\t\t\tres +=\
    \ node[y][x];\n        }\n        return res;\n    }\n \n    // [x1,x2] * [y1,y2]\
    \ 1-indexed\n    inline T getvar(const int y1,const int y2,const int x1,const\
    \ int x2){\n        T res = 0;\n\t\tres += getvar(y1-1,x1-1);\n        res -=\
    \ getvar(y1-1,x2);\n        res -= getvar(y2,x1-1);\n        res += getvar(y2,x2);\n\
    \        return res;\n    }\n \n    //add\n    inline void update(const int i,const\
    \ int j,T val){\n        for(int y=i;y&&y<=N;y+=(y&-y)) for(int x=j;x&&x<=M;x+=(x&-x))\
    \ {\n            node[y][x]+=val;\n        }\n    } \n};\n\n//verify https://atcoder.jp/contests/abc130/tasks/abc130_e\n"
  code: "template<class T> class BinaryIndexedTree2D {\n//\u62BD\u8C61\u5316\u3057\
    \u3066\u306A\u3044\u3000\u4E00\u70B9\u52A0\u7B97\u3001\u533A\u9593\u7DCF\u548C\
    \u306E\u307F\n\tconst int N,M;\n\tvector<vector<T>> node;\n\npublic:\n    //1-indexed\n\
    \    BinaryIndexedTree2D(const int& N,const int& M):N(N),M(M),node(N+1,vector<T>(M+1,0)){\n\
    \        // do nothing\n    }\n \n    inline T getvar(const int i,const int j){\n\
    \        T res = 0;\n        for(int y=i;y>0;y-=(y&-y)) for(int x=j;x>0;x-=(x&-x))\
    \ {\n\t\t\tres += node[y][x];\n        }\n        return res;\n    }\n \n    //\
    \ [x1,x2] * [y1,y2] 1-indexed\n    inline T getvar(const int y1,const int y2,const\
    \ int x1,const int x2){\n        T res = 0;\n\t\tres += getvar(y1-1,x1-1);\n \
    \       res -= getvar(y1-1,x2);\n        res -= getvar(y2,x1-1);\n        res\
    \ += getvar(y2,x2);\n        return res;\n    }\n \n    //add\n    inline void\
    \ update(const int i,const int j,T val){\n        for(int y=i;y&&y<=N;y+=(y&-y))\
    \ for(int x=j;x&&x<=M;x+=(x&-x)) {\n            node[y][x]+=val;\n        }\n\
    \    } \n};\n\n//verify https://atcoder.jp/contests/abc130/tasks/abc130_e\n"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/BinaryIndexedTree2D.cpp
  requiredBy: []
  timestamp: '2020-04-26 16:29:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/BinaryIndexedTree2D.cpp
layout: document
redirect_from:
- /library/non-verified/BinaryIndexedTree2D.cpp
- /library/non-verified/BinaryIndexedTree2D.cpp.html
title: non-verified/BinaryIndexedTree2D.cpp
---
