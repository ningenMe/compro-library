---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"non-verified/Median.cpp\"\n\ntemplate<class T> class Median{\n\
    \tmultiset<T, greater<>> stl;\n\tmultiset<T> str;\n    T init;\n\n    // \u8981\
    \u7D20\u306E\u5747\u8861\u3092\u4FDD\u3064\u95A2\u6570\n    inline void balance()\
    \ {\n        while(stl.size() < str.size()) {\n            stl.insert(*str.begin());\n\
    \            str.erase(str.begin());\n        }\n        while(stl.size() > str.size()+1)\
    \ {\n            str.insert(*stl.begin());\n            stl.erase(stl.begin());\n\
    \        }\n\n        if(!str.size()) return;\n\n        for(T tmpl = *stl.begin(),tmpr\
    \ = *str.begin(); tmpl>tmpr; tmpl = *stl.begin(), tmpr = *str.begin()) {\n   \
    \         stl.erase(stl.begin());\n            str.erase(str.begin());\n     \
    \       stl.insert(tmpr);\n            str.insert(tmpl);\n        }\n    }\npublic:\n\
    \    Median(T init):init(init){\n        //do nothing\n    }\n\n    void insert(T\
    \ val){\n        stl.insert(val);\n        balance();\n    }\n\n    int find(T\
    \ val){\n        return (stl.find(val)!=stl.end() || str.find(val)!=str.end());\n\
    \    }\n\n    void eraseItr(T val){\n        auto itr = stl.find(val);\n     \
    \   if(itr != stl.end()) {\n            stl.erase(itr);\n            balance();\n\
    \            return;\n        }\n        itr = str.find(val);\n        if(itr\
    \ != str.end()) {\n            str.erase(itr);\n            balance();\n     \
    \       return;\n        }\n    }\n\n    void eraseVal(T val){\n        stl.erase(val);\n\
    \        str.erase(val);\n        balance();\n    }\n\n    T get(){\n        return\
    \ (stl.empty()?init:*stl.begin());\n    }\n\n    size_t size(){\n        return\
    \ stl.size()+str.size();\n    }\n};\n\n"
  code: "\ntemplate<class T> class Median{\n\tmultiset<T, greater<>> stl;\n\tmultiset<T>\
    \ str;\n    T init;\n\n    // \u8981\u7D20\u306E\u5747\u8861\u3092\u4FDD\u3064\
    \u95A2\u6570\n    inline void balance() {\n        while(stl.size() < str.size())\
    \ {\n            stl.insert(*str.begin());\n            str.erase(str.begin());\n\
    \        }\n        while(stl.size() > str.size()+1) {\n            str.insert(*stl.begin());\n\
    \            stl.erase(stl.begin());\n        }\n\n        if(!str.size()) return;\n\
    \n        for(T tmpl = *stl.begin(),tmpr = *str.begin(); tmpl>tmpr; tmpl = *stl.begin(),\
    \ tmpr = *str.begin()) {\n            stl.erase(stl.begin());\n            str.erase(str.begin());\n\
    \            stl.insert(tmpr);\n            str.insert(tmpl);\n        }\n   \
    \ }\npublic:\n    Median(T init):init(init){\n        //do nothing\n    }\n\n\
    \    void insert(T val){\n        stl.insert(val);\n        balance();\n    }\n\
    \n    int find(T val){\n        return (stl.find(val)!=stl.end() || str.find(val)!=str.end());\n\
    \    }\n\n    void eraseItr(T val){\n        auto itr = stl.find(val);\n     \
    \   if(itr != stl.end()) {\n            stl.erase(itr);\n            balance();\n\
    \            return;\n        }\n        itr = str.find(val);\n        if(itr\
    \ != str.end()) {\n            str.erase(itr);\n            balance();\n     \
    \       return;\n        }\n    }\n\n    void eraseVal(T val){\n        stl.erase(val);\n\
    \        str.erase(val);\n        balance();\n    }\n\n    T get(){\n        return\
    \ (stl.empty()?init:*stl.begin());\n    }\n\n    size_t size(){\n        return\
    \ stl.size()+str.size();\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: non-verified/Median.cpp
  requiredBy: []
  timestamp: '2020-04-26 16:29:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: non-verified/Median.cpp
layout: document
redirect_from:
- /library/non-verified/Median.cpp
- /library/non-verified/Median.cpp.html
title: non-verified/Median.cpp
---
