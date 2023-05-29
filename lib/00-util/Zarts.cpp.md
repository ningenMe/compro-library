---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/00-util/Zarts.test.cpp
    title: test/00-util/Zarts.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/00-util/Zarts.md
    document_title: "Zarts - \u5EA7\u6A19\u5727\u7E2E"
    links: []
  bundledCode: "#line 1 \"lib/00-util/Zarts.cpp\"\n/*\n * @title Zarts - \u5EA7\u6A19\
    \u5727\u7E2E\n * @docs md/00-util/Zarts.md\n */\ntemplate<class T> class Zarts{\n\
    \    vector<T> value;\n    map<T,int> key;\n    size_t sz;\npublic:\n    vector<int>\
    \ compressed;\n    Zarts(const vector<T> & ar, int light_flag = 0, T pre=-1) :\
    \ compressed(ar.size()) {\n        if(!light_flag) {\n            for (auto &e\
    \ : ar) key[e];\n            int cnt=0;\n            for (auto &e : key) e.second\
    \ = cnt++;\n            for (int i=0;i<ar.size();++i) compressed[i]=key[ar[i]];\n\
    \            value.resize(key.size());\n            for (auto &e : key) value[e.second]\
    \ = e.first;\n            sz = cnt;\n        }\n        else {\n            vector<pair<int,int>>\
    \ ord(ar.size());\n            for(int i=0;i<ar.size();++i) ord[i]={ar[i],i};\n\
    \            sort(ord.begin(),ord.end());\n            int cnt=-1;\n         \
    \   for(int i=0;i<ar.size();++i) {\n                if(pre < ord[i].first) cnt++;\n\
    \                compressed[ord[i].second] = cnt;\n                pre = ord[i].first;\n\
    \            }\n            sz = cnt+1;\n        }\n    }\n    T get_value(int\
    \ key) {\n        return value[key];\n    }\n    int get_key(T value) {\n    \
    \    assert(key.count(value));\n        return key[value];\n    }\n    size_t\
    \ size() {\n        return sz;\n    }\n};\n"
  code: "/*\n * @title Zarts - \u5EA7\u6A19\u5727\u7E2E\n * @docs md/00-util/Zarts.md\n\
    \ */\ntemplate<class T> class Zarts{\n    vector<T> value;\n    map<T,int> key;\n\
    \    size_t sz;\npublic:\n    vector<int> compressed;\n    Zarts(const vector<T>\
    \ & ar, int light_flag = 0, T pre=-1) : compressed(ar.size()) {\n        if(!light_flag)\
    \ {\n            for (auto &e : ar) key[e];\n            int cnt=0;\n        \
    \    for (auto &e : key) e.second = cnt++;\n            for (int i=0;i<ar.size();++i)\
    \ compressed[i]=key[ar[i]];\n            value.resize(key.size());\n         \
    \   for (auto &e : key) value[e.second] = e.first;\n            sz = cnt;\n  \
    \      }\n        else {\n            vector<pair<int,int>> ord(ar.size());\n\
    \            for(int i=0;i<ar.size();++i) ord[i]={ar[i],i};\n            sort(ord.begin(),ord.end());\n\
    \            int cnt=-1;\n            for(int i=0;i<ar.size();++i) {\n       \
    \         if(pre < ord[i].first) cnt++;\n                compressed[ord[i].second]\
    \ = cnt;\n                pre = ord[i].first;\n            }\n            sz =\
    \ cnt+1;\n        }\n    }\n    T get_value(int key) {\n        return value[key];\n\
    \    }\n    int get_key(T value) {\n        assert(key.count(value));\n      \
    \  return key[value];\n    }\n    size_t size() {\n        return sz;\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/00-util/Zarts.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:03:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/00-util/Zarts.test.cpp
documentation_of: lib/00-util/Zarts.cpp
layout: document
redirect_from:
- /library/lib/00-util/Zarts.cpp
- /library/lib/00-util/Zarts.cpp.html
title: "Zarts - \u5EA7\u6A19\u5727\u7E2E"
---
### Zarts
- 座標圧縮

### コンストラクタ
- Zarts(const vector<T> & ar, int light_flag = 0, T pre=-1)
- arには座圧したいvectorを渡す。
- light_flag=1のとき、mapを使わずに定数倍の速い座圧を行う。このときkey,valを逆変換するmapは生成されない。
- light_flag=1のときは比較ベースで座圧する。preの値はarに含まれない最小の値を渡す必要がある。(任意のar[i]に関して pre < a[i] が成り立つ必要がある)
- 計算量 $O(N\log N)$

### メソッド
- 座圧した配列に関しては、compressedはpublicメンバなので、直接アクセスして使用する
- T get_value(int key)
  - key番目に大きい値を返す 
  - $O(1)$
- int get_key(T value)
  - valueが座圧後何番目に大きいかのkeyを返す
  - $O(\log N)$
- size_t size()
  - 座圧後の値の種類数を返す
  - $O(1)$
