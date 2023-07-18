---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/geometory/RationalLine.md
    document_title: "RationalLine - \u6709\u7406\u6570\u76F4\u7DDA"
    links: []
  bundledCode: "#line 1 \"lib/70-geometory/RationalLine.cpp\"\n/*\n * @title RationalLine\
    \ - \u6709\u7406\u6570\u76F4\u7DDA\n * @docs md/geometory/RationalLine.md\n */\n\
    class RationalLine {\n    pair<Rational,Rational> p;\npublic:\n    constexpr RationalLine(const\
    \ long long x1,const long long y1,const long long x2,const long long y2) {\n \
    \       Rational slope(y2-y1,x2-x1), intercept(y1*x2-x1*y2,x2-x1);\n        if(slope\
    \ == Rational::inf()) intercept = x1;\n        p.first=slope;\n        p.second=intercept;\n\
    \    }\n    constexpr bool operator<(const RationalLine &rhs) const { return p\
    \ < rhs.p; }\n    constexpr bool operator<=(const RationalLine &rhs) const { return\
    \ p <= rhs.p; }\n    constexpr bool operator>(const RationalLine &rhs) const {\
    \ return rhs.p < p; }\n    constexpr bool operator>=(const RationalLine &rhs)\
    \ const { return rhs.p <= p; }\n    constexpr bool operator==(const RationalLine\
    \ &rhs) const { return p == rhs.p; }\n    constexpr bool operator!=(const RationalLine\
    \ &rhs) const { return p != rhs.p; }\n    friend ostream &operator<<(ostream &os,\
    \ const RationalLine &rhs) {return os << \"{\" << rhs.p.first << \",\" << rhs.p.second\
    \ << \"}\";}\n};\n"
  code: "/*\n * @title RationalLine - \u6709\u7406\u6570\u76F4\u7DDA\n * @docs md/geometory/RationalLine.md\n\
    \ */\nclass RationalLine {\n    pair<Rational,Rational> p;\npublic:\n    constexpr\
    \ RationalLine(const long long x1,const long long y1,const long long x2,const\
    \ long long y2) {\n        Rational slope(y2-y1,x2-x1), intercept(y1*x2-x1*y2,x2-x1);\n\
    \        if(slope == Rational::inf()) intercept = x1;\n        p.first=slope;\n\
    \        p.second=intercept;\n    }\n    constexpr bool operator<(const RationalLine\
    \ &rhs) const { return p < rhs.p; }\n    constexpr bool operator<=(const RationalLine\
    \ &rhs) const { return p <= rhs.p; }\n    constexpr bool operator>(const RationalLine\
    \ &rhs) const { return rhs.p < p; }\n    constexpr bool operator>=(const RationalLine\
    \ &rhs) const { return rhs.p <= p; }\n    constexpr bool operator==(const RationalLine\
    \ &rhs) const { return p == rhs.p; }\n    constexpr bool operator!=(const RationalLine\
    \ &rhs) const { return p != rhs.p; }\n    friend ostream &operator<<(ostream &os,\
    \ const RationalLine &rhs) {return os << \"{\" << rhs.p.first << \",\" << rhs.p.second\
    \ << \"}\";}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/70-geometory/RationalLine.cpp
  requiredBy: []
  timestamp: '2023-07-19 05:26:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/70-geometory/RationalLine.cpp
layout: document
redirect_from:
- /library/lib/70-geometory/RationalLine.cpp
- /library/lib/70-geometory/RationalLine.cpp.html
title: "RationalLine - \u6709\u7406\u6570\u76F4\u7DDA"
---
### RationalLine
- 有理数直線クラス
- [提出](https://atcoder.jp/contests/abc248/submissions/43734271)