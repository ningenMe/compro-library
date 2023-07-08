---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/optimize/MaximumRectangle-1.test.cpp
    title: test/optimize/MaximumRectangle-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/optimize/MaximumRectangle-2.test.cpp
    title: test/optimize/MaximumRectangle-2.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/optimize/MaximumRectangle.md
    document_title: "MaximumRectangle - \u6700\u5927\u9577\u65B9\u5F62"
    links: []
  bundledCode: "#line 1 \"lib/60-optimize/MaximumRectangle.cpp\"\n/*\n * @title MaximumRectangle\
    \ - \u6700\u5927\u9577\u65B9\u5F62\n * @docs md/optimize/MaximumRectangle.md\n\
    \ */\nlong long MaximumRectangle(vector<long long> ar){\n\tar.push_back(0);\n\t\
    stack<pair<long long,long long>> st;\n\tlong long res = 0;\n\tfor(long long r\
    \ = 0; r < ar.size(); ++r){\n\t\tlong long vr = ar[r];\n\t\tlong long x = r;\t\
    \t\n\t\twhile(st.size() && st.top().first > vr) {\n\t\t\tauto [vl, l] = st.top();\
    \ st.pop();\n\t\t\tx = l;\n\t\t\tres = max(res,vl*(r - l));\n\t\t}\n\t\tif(st.empty()\
    \ || (st.size() && st.top().first < vr)) st.push({vr,x});\n\t}\n\treturn res;\n\
    }\n"
  code: "/*\n * @title MaximumRectangle - \u6700\u5927\u9577\u65B9\u5F62\n * @docs\
    \ md/optimize/MaximumRectangle.md\n */\nlong long MaximumRectangle(vector<long\
    \ long> ar){\n\tar.push_back(0);\n\tstack<pair<long long,long long>> st;\n\tlong\
    \ long res = 0;\n\tfor(long long r = 0; r < ar.size(); ++r){\n\t\tlong long vr\
    \ = ar[r];\n\t\tlong long x = r;\t\t\n\t\twhile(st.size() && st.top().first >\
    \ vr) {\n\t\t\tauto [vl, l] = st.top(); st.pop();\n\t\t\tx = l;\n\t\t\tres = max(res,vl*(r\
    \ - l));\n\t\t}\n\t\tif(st.empty() || (st.size() && st.top().first < vr)) st.push({vr,x});\n\
    \t}\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/60-optimize/MaximumRectangle.cpp
  requiredBy: []
  timestamp: '2023-07-09 00:53:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/optimize/MaximumRectangle-2.test.cpp
  - test/optimize/MaximumRectangle-1.test.cpp
documentation_of: lib/60-optimize/MaximumRectangle.cpp
layout: document
redirect_from:
- /library/lib/60-optimize/MaximumRectangle.cpp
- /library/lib/60-optimize/MaximumRectangle.cpp.html
title: "MaximumRectangle - \u6700\u5927\u9577\u65B9\u5F62"
---
### MaximumRectangle
- 最大長方形
- ヒストグラムの最大長方形を求める

### メソッド
- long long MaximumRectangle(vector<T> ar)
- 計算量はarのサイズを$N$として$O(N)$

### 参考資料
- [Flip and Rectangles](https://atcoder.jp/contests/arc081/tasks/arc081_d)