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
  bundledCode: "#line 1 \"non-verified/BinaryColumnEchelonFormalize.cpp\"\n\n// Column_01Echelon_Formalize\
    \ O(N)\u3000\u5B9A\u6570\u500D\u91CD\u3081\nvector<long long>  BinaryColumnEchelonFormalize(vector<long\
    \ long> vec){\n\tfor(int i = 59,idx = -1; 0 <= i; --i,idx = -1){\n\t\tsort(vec.begin(),vec.end(),greater<long\
    \ long>());\n\t\tfor(int j = 0,flg = 1; j < vec.size(); ++j,flg = 0){\n\t\t\t\
    if( !((vec[j]>>i) & 1) ) continue;\n\t\t\tfor(int k = 59; i < k; --k) if((vec[j]>>k)\
    \ & 1) flg = 1;\n\t\t\tif(flg) continue;\n\t\t\tidx = j;\n\t\t\tbreak;\n\t\t}\n\
    \t\tfor(int j = 0; idx != -1 && j < vec.size(); ++j) if(idx != j && ((vec[j]>>i)\
    \ & 1)) vec[j] ^= vec[idx];\n\t}\n\n\treturn vec;\n}\n"
  code: "\n// Column_01Echelon_Formalize O(N)\u3000\u5B9A\u6570\u500D\u91CD\u3081\n\
    vector<long long>  BinaryColumnEchelonFormalize(vector<long long> vec){\n\tfor(int\
    \ i = 59,idx = -1; 0 <= i; --i,idx = -1){\n\t\tsort(vec.begin(),vec.end(),greater<long\
    \ long>());\n\t\tfor(int j = 0,flg = 1; j < vec.size(); ++j,flg = 0){\n\t\t\t\
    if( !((vec[j]>>i) & 1) ) continue;\n\t\t\tfor(int k = 59; i < k; --k) if((vec[j]>>k)\
    \ & 1) flg = 1;\n\t\t\tif(flg) continue;\n\t\t\tidx = j;\n\t\t\tbreak;\n\t\t}\n\
    \t\tfor(int j = 0; idx != -1 && j < vec.size(); ++j) if(idx != j && ((vec[j]>>i)\
    \ & 1)) vec[j] ^= vec[idx];\n\t}\n\n\treturn vec;\n}"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/BinaryColumnEchelonFormalize.cpp
  requiredBy: []
  timestamp: '2020-04-26 16:29:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/BinaryColumnEchelonFormalize.cpp
layout: document
redirect_from:
- /library/non-verified/BinaryColumnEchelonFormalize.cpp
- /library/non-verified/BinaryColumnEchelonFormalize.cpp.html
title: non-verified/BinaryColumnEchelonFormalize.cpp
---
