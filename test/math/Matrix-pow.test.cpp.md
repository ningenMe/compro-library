---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/00-util/ModInt.cpp
    title: ModInt
  - icon: ':heavy_check_mark:'
    path: lib/30-math/Matrix.cpp
    title: "Matrix - \u884C\u5217\u6F14\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/718
    links:
    - https://yukicoder.me/problems/no/718
  bundledCode: "#line 1 \"test/math/Matrix-pow.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/718\"\
    \n\n#include <vector>\n#include <iostream>\n#include <array>\n#include <cassert>\n\
    using namespace std;\n#line 1 \"lib/00-util/ModInt.cpp\"\n/*\n * @title ModInt\n\
    \ * @docs md/util/ModInt.md\n */\ntemplate<long long mod> class ModInt {\npublic:\n\
    \    long long x;\n    constexpr ModInt():x(0) {}\n    constexpr ModInt(long long\
    \ y) : x(y>=0?(y%mod): (mod - (-y)%mod)%mod) {}\n    constexpr ModInt &operator+=(const\
    \ ModInt &p) {if((x += p.x) >= mod) x -= mod;return *this;}\n    constexpr ModInt\
    \ &operator+=(const long long y) {ModInt p(y);if((x += p.x) >= mod) x -= mod;return\
    \ *this;}\n    constexpr ModInt &operator+=(const int y) {ModInt p(y);if((x +=\
    \ p.x) >= mod) x -= mod;return *this;}\n    constexpr ModInt &operator-=(const\
    \ ModInt &p) {if((x += mod - p.x) >= mod) x -= mod;return *this;}\n    constexpr\
    \ ModInt &operator-=(const long long y) {ModInt p(y);if((x += mod - p.x) >= mod)\
    \ x -= mod;return *this;}\n    constexpr ModInt &operator-=(const int y) {ModInt\
    \ p(y);if((x += mod - p.x) >= mod) x -= mod;return *this;}\n    constexpr ModInt\
    \ &operator*=(const ModInt &p) {x = (x * p.x % mod);return *this;}\n    constexpr\
    \ ModInt &operator*=(const long long y) {ModInt p(y);x = (x * p.x % mod);return\
    \ *this;}\n    constexpr ModInt &operator*=(const int y) {ModInt p(y);x = (x *\
    \ p.x % mod);return *this;}\n    constexpr ModInt &operator^=(const ModInt &p)\
    \ {x = (x ^ p.x) % mod;return *this;}\n    constexpr ModInt &operator^=(const\
    \ long long y) {ModInt p(y);x = (x ^ p.x) % mod;return *this;}\n    constexpr\
    \ ModInt &operator^=(const int y) {ModInt p(y);x = (x ^ p.x) % mod;return *this;}\n\
    \    constexpr ModInt &operator/=(const ModInt &p) {*this *= p.inv();return *this;}\n\
    \    constexpr ModInt &operator/=(const long long y) {ModInt p(y);*this *= p.inv();return\
    \ *this;}\n    constexpr ModInt &operator/=(const int y) {ModInt p(y);*this *=\
    \ p.inv();return *this;}\n    constexpr ModInt operator=(const int y) {ModInt\
    \ p(y);*this = p;return *this;}\n    constexpr ModInt operator=(const long long\
    \ y) {ModInt p(y);*this = p;return *this;}\n    constexpr ModInt operator-() const\
    \ {return ModInt(-x); }\n    constexpr ModInt operator++() {x++;if(x>=mod) x-=mod;return\
    \ *this;}\n    constexpr ModInt operator--() {x--;if(x<0) x+=mod;return *this;}\n\
    \    constexpr ModInt operator+(const ModInt &p) const { return ModInt(*this)\
    \ += p; }\n    constexpr ModInt operator-(const ModInt &p) const { return ModInt(*this)\
    \ -= p; }\n    constexpr ModInt operator*(const ModInt &p) const { return ModInt(*this)\
    \ *= p; }\n    constexpr ModInt operator/(const ModInt &p) const { return ModInt(*this)\
    \ /= p; }\n    constexpr ModInt operator^(const ModInt &p) const { return ModInt(*this)\
    \ ^= p; }\n    constexpr bool operator==(const ModInt &p) const { return x ==\
    \ p.x; }\n    constexpr bool operator!=(const ModInt &p) const { return x != p.x;\
    \ }\n    // ModInt inv() const {int a=x,b=mod,u=1,v=0,t;while(b > 0) {t = a /\
    \ b;swap(a -= t * b, b);swap(u -= t * v, v);} return ModInt(u);}\n    constexpr\
    \ ModInt inv() const {int a=x,b=mod,u=1,v=0,t=0,tmp=0;while(b > 0) {t = a / b;a-=t*b;tmp=a;a=b;b=tmp;u-=t*v;tmp=u;u=v;v=tmp;}\
    \ return ModInt(u);}\n    constexpr ModInt pow(long long n) const {ModInt ret(1),\
    \ mul(x);for(;n > 0;mul *= mul,n >>= 1) if(n & 1) ret *= mul;return ret;}\n  \
    \  friend ostream &operator<<(ostream &os, const ModInt &p) {return os << p.x;}\n\
    \    friend istream &operator>>(istream &is, ModInt &a) {long long t;is >> t;a\
    \ = ModInt<mod>(t);return (is);}\n};\nconstexpr long long MOD_998244353 = 998244353;\n\
    constexpr long long MOD_1000000007 = 1'000'000'000LL + 7; //'\n#line 1 \"lib/30-math/Matrix.cpp\"\
    \n/*\n * @title Matrix - \u884C\u5217\u6F14\u7B97\n * @docs md/math/Matrix.md\n\
    \ */\ntemplate <class T, int H, int W = H> class Matrix {\npublic:\n    int h,w;\n\
    \    array<array<T,W>,H> a;\n    Matrix():h(H),w(W){\n        // do nothing\n\
    \    }\n    Matrix(const vector<vector<T>>& vec):h(H),w(W) {\n        assert(vec.size()==H\
    \ && vec.front().size()==W);\n        for(int i = 0; i < H; ++i) for(int j = 0;\
    \ j < W; ++j) a[i][j]=vec[i][j];\n    }\n    static Matrix E() {\n        assert(H==W);\n\
    \        Matrix res = Matrix();\n        for(int i = 0; i < H; ++i) res[i][i]=1;\n\
    \        return res;\n    }\n    Matrix &operator+=(const Matrix &r) {\n     \
    \   assert(H==r.h&&W==r.w);\n        for(int i = 0; i < H; ++i) for(int j = 0;\
    \ j < W; ++j) a[i][j]+=r[i][j];\n        return *this;\n    }\n    Matrix &operator-=(const\
    \ Matrix &r) {\n        assert(H==r.h&&W==r.w);\n        for(int i = 0; i < H;\
    \ ++i) for(int j = 0; j < W; ++j) a[i][j]-=r[i][j];\n        return *this;\n \
    \   }\n    Matrix &operator*=(const Matrix &r) {\n        assert(W==r.h);\n  \
    \      Matrix res = Matrix();\n        for(int i = 0; i < H; ++i) for(int j =\
    \ 0; j < r.w; ++j) for(int k = 0; k < W; ++k) res[i][j]+=(a[i][k])*(r[k][j]);\n\
    \        a.swap(res.a);\n        return *this;\n    }\n    Matrix operator+(const\
    \ Matrix& r) const {\n        return Matrix(*this) += r;\n    }\n    Matrix operator-(const\
    \ Matrix& r) const {\n        return Matrix(*this) -= r;\n    }\n    Matrix operator*(const\
    \ Matrix& r) const {\n        return Matrix(*this) *= r;\n    }\n    inline array<T,W>\
    \ &operator[](int i) {\n        return a[i];\n    }\n    inline const array<T,W>\
    \ &operator[](int i) const {\n        return a[i];\n    }\n    Matrix pow(long\
    \ long K) const {\n        assert(H == W);\n        Matrix x(*this);\n       \
    \ Matrix res = this->E();\n        for (; K > 0; K /= 2) {\n            if (K\
    \ & 1) res *= x;\n            x *= x;\n        }\n        return res;\n    }\n\
    \    T determinant(void) const {\n        assert(H==W);\n        Matrix x(*this);\n\
    \        T res = 1;\n        for(int i = 0; i < H; i++) {\n            int idx\
    \ = -1;\n            for(int j = i; j < W; j++) if(x[j][i] != 0) idx = j;\n  \
    \          if(idx == -1) return 0;\n            if(i != idx) {\n             \
    \   res *= -1;\n                swap(x[i], x[idx]);\n            }\n         \
    \   res *= x[i][i];\n            T tmp = x[i][i];\n            for(int j = 0;\
    \ j < W; ++j) x[i][j] /= tmp;\n            for(int j = i + 1; j < H; j++) {\n\
    \                tmp = x[j][i];\n                for(int k = 0; k < W; k++) x[j][k]\
    \ -= x[i][k]*tmp;\n            }\n        }\n        return res;\n    }\n};\n\
    #line 10 \"test/math/Matrix-pow.test.cpp\"\nconstexpr long long MOD = 1000'000'007;\n\
    \nint main(void){\n    using modint = ModInt<MOD>;\n    vector<vector<modint>>\
    \ a(4,vector<modint>(4));\n    a[0] = {1,2,2,-1};\n    a[1] = {0,2,2,-1};\n  \
    \  a[2] = {0,1,0,0};\n    a[3] = {0,0,1,0};\n    long long N; cin >> N;\n    if(N==1){\n\
    \        cout << 1 << endl;\n        return 0;\n    }\n    if(N==2){\n       \
    \ cout << 2 << endl;\n        return 0;\n    }\n    Matrix<modint,4> b(a);\n \
    \   auto s = b.pow(N-2);\n    cout << s.a[0][0]*2+s.a[0][1]+s.a[0][2] << endl;\n\
    \treturn 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/718\"\n\n#include <vector>\n\
    #include <iostream>\n#include <array>\n#include <cassert>\nusing namespace std;\n\
    #include \"../../lib/00-util/ModInt.cpp\"\n#include \"../../lib/30-math/Matrix.cpp\"\
    \nconstexpr long long MOD = 1000'000'007;\n\nint main(void){\n    using modint\
    \ = ModInt<MOD>;\n    vector<vector<modint>> a(4,vector<modint>(4));\n    a[0]\
    \ = {1,2,2,-1};\n    a[1] = {0,2,2,-1};\n    a[2] = {0,1,0,0};\n    a[3] = {0,0,1,0};\n\
    \    long long N; cin >> N;\n    if(N==1){\n        cout << 1 << endl;\n     \
    \   return 0;\n    }\n    if(N==2){\n        cout << 2 << endl;\n        return\
    \ 0;\n    }\n    Matrix<modint,4> b(a);\n    auto s = b.pow(N-2);\n    cout <<\
    \ s.a[0][0]*2+s.a[0][1]+s.a[0][2] << endl;\n\treturn 0;\n}"
  dependsOn:
  - lib/00-util/ModInt.cpp
  - lib/30-math/Matrix.cpp
  isVerificationFile: true
  path: test/math/Matrix-pow.test.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:49:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/Matrix-pow.test.cpp
layout: document
redirect_from:
- /verify/test/math/Matrix-pow.test.cpp
- /verify/test/math/Matrix-pow.test.cpp.html
title: test/math/Matrix-pow.test.cpp
---