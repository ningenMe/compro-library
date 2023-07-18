---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/util/Rational.md
    document_title: "Rational - \u6709\u7406\u6570"
    links: []
  bundledCode: "#line 1 \"lib/00-util/Rational.cpp\"\n/*\n * @title Rational - \u6709\
    \u7406\u6570\n * @docs md/util/Rational.md\n */\nclass Rational {\n    long long\
    \ numerator, denominator;\npublic:\n    friend ostream &operator<<(ostream &os,\
    \ const Rational &rhs) {return os << rhs.numerator << \"/\" << rhs.denominator;}\n\
    \    constexpr Rational(const long long num, const long long den):numerator(num),denominator(den){\n\
    \        if(den<0) denominator*=(-1),numerator*=(-1);\n        if(den==0) numerator=1,denominator=0;\n\
    \    }\n    constexpr Rational(const long long val):Rational(val,1){}\n    constexpr\
    \ Rational(const int val):Rational((long long)val){}\n    constexpr Rational():Rational(0){}\n\
    \    inline static constexpr Rational inf() {\n        return Rational(1LL,0LL);\n\
    \    }\n    constexpr Rational &operator+=(const Rational &rhs) {\n        numerator=numerator*rhs.denominator+denominator*rhs.numerator;\
    \ \n        denominator*=rhs.denominator;\n        if(denominator==0) numerator=1;\n\
    \        return *this;\n    }\n    constexpr Rational &operator-=(const Rational\
    \ &rhs) {\n        numerator=numerator*rhs.denominator-denominator*rhs.numerator;\
    \ \n        denominator*=rhs.denominator;\n        if(denominator==0) numerator=1;\n\
    \        return *this;\n    }\n    constexpr Rational &operator*=(const Rational\
    \ &rhs) {\n        numerator*=rhs.numerator;\n        denominator*=rhs.denominator;\n\
    \        if(denominator==0) numerator=1;\n        return *this;\n    }\n    constexpr\
    \ Rational &operator/=(const Rational &rhs) {*this *= rhs.inv();return *this;}\n\
    \    constexpr Rational operator-() const {return Rational(-numerator, denominator);\
    \ }\n    constexpr Rational operator+(const Rational &rhs) const { return Rational(*this)\
    \ += rhs; }\n    constexpr Rational operator-(const Rational &rhs) const { return\
    \ Rational(*this) -= rhs; }\n    constexpr Rational operator*(const Rational &rhs)\
    \ const { return Rational(*this) *= rhs; }\n    constexpr Rational operator/(const\
    \ Rational &rhs) const { return Rational(*this) /= rhs; }\n    constexpr bool\
    \ operator<(const Rational &rhs) const { return numerator*rhs.denominator < denominator*rhs.numerator;\
    \ }\n    constexpr bool operator<=(const Rational &rhs) const { return numerator*rhs.denominator\
    \ <= denominator*rhs.numerator; }\n    constexpr bool operator>(const Rational\
    \ &rhs) const { return rhs < *this; }\n    constexpr bool operator>=(const Rational\
    \ &rhs) const { return rhs <= *this; }\n    constexpr bool operator==(const Rational\
    \ &rhs) const { return numerator*rhs.denominator == denominator*rhs.numerator;\
    \ }\n    constexpr bool operator!=(const Rational &rhs) const { return !(*this\
    \ == rhs); }\n    constexpr Rational inv() const {return (numerator==0?inf():Rational(denominator,numerator));}\n\
    };\n"
  code: "/*\n * @title Rational - \u6709\u7406\u6570\n * @docs md/util/Rational.md\n\
    \ */\nclass Rational {\n    long long numerator, denominator;\npublic:\n    friend\
    \ ostream &operator<<(ostream &os, const Rational &rhs) {return os << rhs.numerator\
    \ << \"/\" << rhs.denominator;}\n    constexpr Rational(const long long num, const\
    \ long long den):numerator(num),denominator(den){\n        if(den<0) denominator*=(-1),numerator*=(-1);\n\
    \        if(den==0) numerator=1,denominator=0;\n    }\n    constexpr Rational(const\
    \ long long val):Rational(val,1){}\n    constexpr Rational(const int val):Rational((long\
    \ long)val){}\n    constexpr Rational():Rational(0){}\n    inline static constexpr\
    \ Rational inf() {\n        return Rational(1LL,0LL);\n    }\n    constexpr Rational\
    \ &operator+=(const Rational &rhs) {\n        numerator=numerator*rhs.denominator+denominator*rhs.numerator;\
    \ \n        denominator*=rhs.denominator;\n        if(denominator==0) numerator=1;\n\
    \        return *this;\n    }\n    constexpr Rational &operator-=(const Rational\
    \ &rhs) {\n        numerator=numerator*rhs.denominator-denominator*rhs.numerator;\
    \ \n        denominator*=rhs.denominator;\n        if(denominator==0) numerator=1;\n\
    \        return *this;\n    }\n    constexpr Rational &operator*=(const Rational\
    \ &rhs) {\n        numerator*=rhs.numerator;\n        denominator*=rhs.denominator;\n\
    \        if(denominator==0) numerator=1;\n        return *this;\n    }\n    constexpr\
    \ Rational &operator/=(const Rational &rhs) {*this *= rhs.inv();return *this;}\n\
    \    constexpr Rational operator-() const {return Rational(-numerator, denominator);\
    \ }\n    constexpr Rational operator+(const Rational &rhs) const { return Rational(*this)\
    \ += rhs; }\n    constexpr Rational operator-(const Rational &rhs) const { return\
    \ Rational(*this) -= rhs; }\n    constexpr Rational operator*(const Rational &rhs)\
    \ const { return Rational(*this) *= rhs; }\n    constexpr Rational operator/(const\
    \ Rational &rhs) const { return Rational(*this) /= rhs; }\n    constexpr bool\
    \ operator<(const Rational &rhs) const { return numerator*rhs.denominator < denominator*rhs.numerator;\
    \ }\n    constexpr bool operator<=(const Rational &rhs) const { return numerator*rhs.denominator\
    \ <= denominator*rhs.numerator; }\n    constexpr bool operator>(const Rational\
    \ &rhs) const { return rhs < *this; }\n    constexpr bool operator>=(const Rational\
    \ &rhs) const { return rhs <= *this; }\n    constexpr bool operator==(const Rational\
    \ &rhs) const { return numerator*rhs.denominator == denominator*rhs.numerator;\
    \ }\n    constexpr bool operator!=(const Rational &rhs) const { return !(*this\
    \ == rhs); }\n    constexpr Rational inv() const {return (numerator==0?inf():Rational(denominator,numerator));}\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: lib/00-util/Rational.cpp
  requiredBy: []
  timestamp: '2023-07-19 05:26:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/00-util/Rational.cpp
layout: document
redirect_from:
- /library/lib/00-util/Rational.cpp
- /library/lib/00-util/Rational.cpp.html
title: "Rational - \u6709\u7406\u6570"
---
