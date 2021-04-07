---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"non-verified/XorShift.cpp\"\nclass XorShift{\n\tunsigned\
    \ int x,y,z,w;\npublic:\n\tXorShift():x(123456789),y(362436069),z(521288629),w(88675123){}\n\
    \tunsigned int rand() {\n\t\tunsigned int t = (x ^ (x << 11)); x = y; y = z; z\
    \ = w;\n\t\treturn (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));\n\t}\n};\n"
  code: "class XorShift{\n\tunsigned int x,y,z,w;\npublic:\n\tXorShift():x(123456789),y(362436069),z(521288629),w(88675123){}\n\
    \tunsigned int rand() {\n\t\tunsigned int t = (x ^ (x << 11)); x = y; y = z; z\
    \ = w;\n\t\treturn (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/XorShift.cpp
  requiredBy: []
  timestamp: '2020-10-24 05:46:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/XorShift.cpp
layout: document
redirect_from:
- /library/non-verified/XorShift.cpp
- /library/non-verified/XorShift.cpp.html
title: non-verified/XorShift.cpp
---
