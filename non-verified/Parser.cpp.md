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
  bundledCode: "#line 1 \"non-verified/Parser.cpp\"\ntemplate<class T> class Parser\
    \ {\npublic:\n    int root;\n    vector<T> res;\n    vector<int> leftNode, rightNode;\
    \ //\u5DE6\u53F3\u306E\u5B50\u3078\u306Eindex\n\tvector<int> idx;//\u5143\u306E\
    index\n\n\tstring str;    //\u69CB\u6587\n\tvector<T> num; //\u6570\u5024\n  \
    \  \n\tParser(const string& str,const vector<T>& num):str(str),num(num){\n   \
    \     int p = 0;\n        root = expr(p);\n\t}\n\t\n\t//\u69CB\u6587\u6728\u306E\
    index\u306B\u5BFE\u3059\u308B\u6587\u5B57\u3092\u53D6\u308A\u51FA\u3059\n\tchar\
    \ getOperator(int q){\n\t\tassert(0 <= q && q <= str.size());\n\t\treturn str[idx[q]];\n\
    \t}\n\nprivate:\n\tint newNode(int i, int l, int r) {\n\t\tleftNode.push_back(l);\n\
    \t\trightNode.push_back(r);\n        T val;\n\t\tif (str[i] == 'a') {\n      \
    \      val = num[i];\n        }\n\t\telse if(str[i] == '(' || str[i] == ')'){\n\
    \            val = -1;\n\t\t}\n        else {\n            if (str[i] == '+')\
    \ val = res[l] + res[r];\n            if (str[i] == '-') val = res[l] - res[r];\n\
    \            if (str[i] == '*') val = res[l] * res[r];\n            if (str[i]\
    \ == '/') val = res[l] / res[r];\n        }\n\t\tres.push_back(val);\n\t\tidx.push_back(i);\n\
    \        return (int)res.size() - 1;\n    }\n    \n    int expr(int &p) {\n  \
    \      int l = factor(p);\n        while (p < (int)str.size() && (str[p] == '+'\
    \ || str[p] == '-')) {\n\t\t\tint i = p++;\n            int r = factor(p);\n \
    \           l = newNode(i, l, r);\n        }\n        return l;\n    }\n    \n\
    \    int factor(int &p) {\n        int l = value(p);\n        while (p < (int)str.size()\
    \ && (str[p]== '*' || str[p] == '/')) {\n\t\t\tint i = p++;\n            int r\
    \ = value(p);\n            l = newNode(i, l, r);\n        }\n        return l;\n\
    \    }\n    \n    int value(int &p) {\n        if (str[p] == '(') {\n        \
    \    newNode(p, -1, -1);  //'('\n\t\t\tp++;\n            int l = expr(p);\n  \
    \          newNode(p, -1, -1);  //')'\n            p++;\n\t\t\treturn l;\n   \
    \     }\n        else {\n\t\t\tint i = p++;\n            return newNode(i, -1,\
    \ -1);\n        }\n    }\n};\n"
  code: "template<class T> class Parser {\npublic:\n    int root;\n    vector<T> res;\n\
    \    vector<int> leftNode, rightNode; //\u5DE6\u53F3\u306E\u5B50\u3078\u306Eindex\n\
    \tvector<int> idx;//\u5143\u306Eindex\n\n\tstring str;    //\u69CB\u6587\n\tvector<T>\
    \ num; //\u6570\u5024\n    \n\tParser(const string& str,const vector<T>& num):str(str),num(num){\n\
    \        int p = 0;\n        root = expr(p);\n\t}\n\t\n\t//\u69CB\u6587\u6728\u306E\
    index\u306B\u5BFE\u3059\u308B\u6587\u5B57\u3092\u53D6\u308A\u51FA\u3059\n\tchar\
    \ getOperator(int q){\n\t\tassert(0 <= q && q <= str.size());\n\t\treturn str[idx[q]];\n\
    \t}\n\nprivate:\n\tint newNode(int i, int l, int r) {\n\t\tleftNode.push_back(l);\n\
    \t\trightNode.push_back(r);\n        T val;\n\t\tif (str[i] == 'a') {\n      \
    \      val = num[i];\n        }\n\t\telse if(str[i] == '(' || str[i] == ')'){\n\
    \            val = -1;\n\t\t}\n        else {\n            if (str[i] == '+')\
    \ val = res[l] + res[r];\n            if (str[i] == '-') val = res[l] - res[r];\n\
    \            if (str[i] == '*') val = res[l] * res[r];\n            if (str[i]\
    \ == '/') val = res[l] / res[r];\n        }\n\t\tres.push_back(val);\n\t\tidx.push_back(i);\n\
    \        return (int)res.size() - 1;\n    }\n    \n    int expr(int &p) {\n  \
    \      int l = factor(p);\n        while (p < (int)str.size() && (str[p] == '+'\
    \ || str[p] == '-')) {\n\t\t\tint i = p++;\n            int r = factor(p);\n \
    \           l = newNode(i, l, r);\n        }\n        return l;\n    }\n    \n\
    \    int factor(int &p) {\n        int l = value(p);\n        while (p < (int)str.size()\
    \ && (str[p]== '*' || str[p] == '/')) {\n\t\t\tint i = p++;\n            int r\
    \ = value(p);\n            l = newNode(i, l, r);\n        }\n        return l;\n\
    \    }\n    \n    int value(int &p) {\n        if (str[p] == '(') {\n        \
    \    newNode(p, -1, -1);  //'('\n\t\t\tp++;\n            int l = expr(p);\n  \
    \          newNode(p, -1, -1);  //')'\n            p++;\n\t\t\treturn l;\n   \
    \     }\n        else {\n\t\t\tint i = p++;\n            return newNode(i, -1,\
    \ -1);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/Parser.cpp
  requiredBy: []
  timestamp: '2020-04-26 16:29:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/Parser.cpp
layout: document
redirect_from:
- /library/non-verified/Parser.cpp
- /library/non-verified/Parser.cpp.html
title: non-verified/Parser.cpp
---
