---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/optimize/MaximumRectangle.md
    document_title: "MaximumRectangle - \u6700\u5927\u9577\u65B9\u5F62"
    links: []
  bundledCode: "#line 1 \"lib/optimize/MaximumRectangle.cpp\"\n/*\n * @title MaximumRectangle\
    \ - \u6700\u5927\u9577\u65B9\u5F62\n * @docs md/optimize/MaximumRectangle.md\n\
    \ */\ntemplate<class T> long long MaximumRectangle(vector<T> ar){\n\tar.push_back(0);\n\
    \tstack<pair<long long,long long>> st;\n\tlong long res = 0;\n\tfor(long long\
    \ r = 0; r < ar.size(); ++r){\n\t\tlong long vr = ar[r];\n\t\tif(st.empty()){\n\
    \t\t\tst.push({vr,r});\n\t\t\tcontinue;\n\t\t}\n\n\t\tlong long vl = st.top().first,\
    \ l = st.top().second;\n\t\tif(vl < vr) st.push({vr,r});\n\t\tif(vl < vr || vl\
    \ == vr)\tcontinue;\n\t\t\n\t\twhile(vl > vr) {\n\t\t\tres = max(res,vl*(r - l));\n\
    \t\t\tst.pop();\n\n\t\t\tif(st.size() && st.top().first > vr) vl = st.top().first,\
    \ l = st.top().second;\n\t\t\telse break;\n\t\t}\n\t\tst.push({vr,l});\n\t}\n\t\
    ar.pop_back();\n\treturn res;\n}\n"
  code: "/*\n * @title MaximumRectangle - \u6700\u5927\u9577\u65B9\u5F62\n * @docs\
    \ md/optimize/MaximumRectangle.md\n */\ntemplate<class T> long long MaximumRectangle(vector<T>\
    \ ar){\n\tar.push_back(0);\n\tstack<pair<long long,long long>> st;\n\tlong long\
    \ res = 0;\n\tfor(long long r = 0; r < ar.size(); ++r){\n\t\tlong long vr = ar[r];\n\
    \t\tif(st.empty()){\n\t\t\tst.push({vr,r});\n\t\t\tcontinue;\n\t\t}\n\n\t\tlong\
    \ long vl = st.top().first, l = st.top().second;\n\t\tif(vl < vr) st.push({vr,r});\n\
    \t\tif(vl < vr || vl == vr)\tcontinue;\n\t\t\n\t\twhile(vl > vr) {\n\t\t\tres\
    \ = max(res,vl*(r - l));\n\t\t\tst.pop();\n\n\t\t\tif(st.size() && st.top().first\
    \ > vr) vl = st.top().first, l = st.top().second;\n\t\t\telse break;\n\t\t}\n\t\
    \tst.push({vr,l});\n\t}\n\tar.pop_back();\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/optimize/MaximumRectangle.cpp
  requiredBy: []
  timestamp: '2023-05-12 01:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/optimize/MaximumRectangle.cpp
layout: document
redirect_from:
- /library/lib/optimize/MaximumRectangle.cpp
- /library/lib/optimize/MaximumRectangle.cpp.html
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