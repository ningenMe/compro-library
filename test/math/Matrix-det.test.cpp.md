---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/util/ModInt.cpp
    title: ModInt
  - icon: ':x:'
    path: lib/math/Matrix.cpp
    title: "Matrix - \u884C\u5217\u6F14\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"test/math/Matrix-det.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\
    \n\n#include <vector>\n#include <iostream>\n#include <array>\n#include <cassert>\n\
    using namespace std;\n#line 1 \"lib/util/ModInt.cpp\"\n/*\n * @title ModInt\n\
    \ * @docs md/util/ModInt.md\n */\ntemplate<long long mod> class ModInt {\npublic:\n\
    \    long long x;\n    constexpr ModInt():x(0) {}\n    constexpr ModInt(long long\
    \ y) : x(y>=0?(y%mod): (mod - (-y)%mod)%mod) {}\n    ModInt &operator+=(const\
    \ ModInt &p) {if((x += p.x) >= mod) x -= mod;return *this;}\n    ModInt &operator+=(const\
    \ long long y) {ModInt p(y);if((x += p.x) >= mod) x -= mod;return *this;}\n  \
    \  ModInt &operator+=(const int y) {ModInt p(y);if((x += p.x) >= mod) x -= mod;return\
    \ *this;}\n    ModInt &operator-=(const ModInt &p) {if((x += mod - p.x) >= mod)\
    \ x -= mod;return *this;}\n    ModInt &operator-=(const long long y) {ModInt p(y);if((x\
    \ += mod - p.x) >= mod) x -= mod;return *this;}\n    ModInt &operator-=(const\
    \ int y) {ModInt p(y);if((x += mod - p.x) >= mod) x -= mod;return *this;}\n  \
    \  ModInt &operator*=(const ModInt &p) {x = (x * p.x % mod);return *this;}\n \
    \   ModInt &operator*=(const long long y) {ModInt p(y);x = (x * p.x % mod);return\
    \ *this;}\n    ModInt &operator*=(const int y) {ModInt p(y);x = (x * p.x % mod);return\
    \ *this;}\n    ModInt &operator^=(const ModInt &p) {x = (x ^ p.x) % mod;return\
    \ *this;}\n    ModInt &operator^=(const long long y) {ModInt p(y);x = (x ^ p.x)\
    \ % mod;return *this;}\n    ModInt &operator^=(const int y) {ModInt p(y);x = (x\
    \ ^ p.x) % mod;return *this;}\n    ModInt &operator/=(const ModInt &p) {*this\
    \ *= p.inv();return *this;}\n    ModInt &operator/=(const long long y) {ModInt\
    \ p(y);*this *= p.inv();return *this;}\n    ModInt &operator/=(const int y) {ModInt\
    \ p(y);*this *= p.inv();return *this;}\n    ModInt operator=(const int y) {ModInt\
    \ p(y);*this = p;return *this;}\n    ModInt operator=(const long long y) {ModInt\
    \ p(y);*this = p;return *this;}\n    ModInt operator-() const {return ModInt(-x);\
    \ }\n    ModInt operator++() {x++;if(x>=mod) x-=mod;return *this;}\n    ModInt\
    \ operator--() {x--;if(x<0) x+=mod;return *this;}\n    ModInt operator+(const\
    \ ModInt &p) const { return ModInt(*this) += p; }\n    ModInt operator-(const\
    \ ModInt &p) const { return ModInt(*this) -= p; }\n    ModInt operator*(const\
    \ ModInt &p) const { return ModInt(*this) *= p; }\n    ModInt operator/(const\
    \ ModInt &p) const { return ModInt(*this) /= p; }\n    ModInt operator^(const\
    \ ModInt &p) const { return ModInt(*this) ^= p; }\n    bool operator==(const ModInt\
    \ &p) const { return x == p.x; }\n    bool operator!=(const ModInt &p) const {\
    \ return x != p.x; }\n    ModInt inv() const {int a=x,b=mod,u=1,v=0,t;while(b\
    \ > 0) {t = a / b;swap(a -= t * b, b);swap(u -= t * v, v);} return ModInt(u);}\n\
    \    ModInt pow(long long n) const {ModInt ret(1), mul(x);for(;n > 0;mul *= mul,n\
    \ >>= 1) if(n & 1) ret *= mul;return ret;}\n    friend ostream &operator<<(ostream\
    \ &os, const ModInt &p) {return os << p.x;}\n    friend istream &operator>>(istream\
    \ &is, ModInt &a) {long long t;is >> t;a = ModInt<mod>(t);return (is);}\n};\n\
    //using modint = ModInt<MOD>;\n#line 1 \"lib/math/Matrix.cpp\"\n/*\n * @title\
    \ Matrix - \u884C\u5217\u6F14\u7B97\n * @docs md/math/Matrix.md\n */\ntemplate\
    \ <class T, int H, int W = H> class Matrix {\npublic:\n\tint h,w;\n\tarray<array<T,W>,H>\
    \ a;\n\tMatrix():h(H),w(W){\n\t\t// do nothing\n\t}\n\tMatrix(const vector<vector<T>>&\
    \ vec):h(H),w(W) {\n\t\tassert(vec.size()==H && vec.front().size()==W);\n\t\t\
    for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) a[i][j]=vec[i][j];\n\t}\n\
    \tstatic Matrix E() {\n\t\tassert(H==W);\n\t\tMatrix res = Matrix();\n\t\tfor(int\
    \ i = 0; i < H; ++i) res[i][i]=1;\n\t\treturn res;\n\t}\n\tMatrix &operator+=(const\
    \ Matrix &r) {\n\t\tassert(H==r.h&&W==r.w);\n\t\tfor(int i = 0; i < H; ++i) for(int\
    \ j = 0; j < W; ++j) a[i][j]+=r[i][j];\n\t\treturn *this;\n\t}\n\tMatrix &operator-=(const\
    \ Matrix &r) {\n\t\tassert(H==r.h&&W==r.w);\n\t\tfor(int i = 0; i < H; ++i) for(int\
    \ j = 0; j < W; ++j) a[i][j]-=r[i][j];\n\t\treturn *this;\n\t}\n\tMatrix &operator*=(const\
    \ Matrix &r) {\n\t\tassert(W==r.h);\n\t\tMatrix res = Matrix();\n\t\tfor(int i\
    \ = 0; i < H; ++i) for(int j = 0; j < r.w; ++j) for(int k = 0; k < W; ++k) res[i][j]+=(a[i][k])*(r[k][j]);\n\
    \t\ta.swap(res.a);\n\t\treturn *this;\n\t}\n\tMatrix operator+(const Matrix& r)\
    \ const {\n\t\treturn Matrix(*this) += r;\n\t}\n\tMatrix operator-(const Matrix&\
    \ r) const {\n\t\treturn Matrix(*this) -= r;\n\t}\n\tMatrix operator*(const Matrix&\
    \ r) const {\n\t\treturn Matrix(*this) *= r;\n\t}\n\tinline array<T,W> &operator[](int\
    \ i) { \n\t\treturn a[i];\n\t}\n\tinline const array<T,W> &operator[](int i) const\
    \ { \n\t\treturn a[i];\n\t}\n\tMatrix pow(long long K) const {\n\t\tassert(H ==\
    \ W);\n\t\tMatrix x(*this);\n\t\tMatrix res = this->E();\n\t\tfor (; K > 0; K\
    \ /= 2) {\n\t\t\tif (K & 1) res *= x;\n\t\t\tx *= x;\n\t\t}\n\t\treturn res;\n\
    \t}\n\tT determinant(void) const {\n\t\tassert(H==W);\n\t\tMatrix x(*this);\n\t\
    \tT res = 1;\n\t\tfor(int i = 0; i < H; i++) {\n\t\t\tint idx = -1;\n\t\t\tfor(int\
    \ j = i; j < W; j++) if(x[j][i] != 0) idx = j;\n\t\t\tif(idx == -1) return 0;\n\
    \t\t\tif(i != idx) {\n\t\t\t\tres *= -1;\n\t\t\t\tswap(x[i], x[idx]);\n\t\t\t\
    }\n\t\t\tres *= x[i][i];\n\t\t\tT tmp = x[i][i];\n\t\t\tfor(int j = 0; j < W;\
    \ ++j) x[i][j] /= tmp;\n\t\t\tfor(int j = i + 1; j < H; j++) {\n\t\t\t\ttmp =\
    \ x[j][i];\n\t\t\t\tfor(int k = 0; k < W; k++) x[j][k] -= x[i][k]*tmp;\n\t\t\t\
    }\n\t\t}\n\t\treturn res;\n\t}\n};\n#line 10 \"test/math/Matrix-det.test.cpp\"\
    \nconstexpr long long MOD = 998'244'353;\n\nint main(void){\n    using modint\
    \ = ModInt<MOD>;\n    Matrix<modint,500> m=Matrix<modint,500>::E();\n    int N;\
    \ cin >> N;\n    for(int i = 0; i < N; ++i) {\n        for(int j = 0; j < N; ++j)\
    \ {\n            cin >> m[i][j];\n        }\n    }\n    cout << m.determinant()\
    \ << endl;\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n\n#include\
    \ <vector>\n#include <iostream>\n#include <array>\n#include <cassert>\nusing namespace\
    \ std;\n#include \"../../lib/util/ModInt.cpp\"\n#include \"../../lib/math/Matrix.cpp\"\
    \nconstexpr long long MOD = 998'244'353;\n\nint main(void){\n    using modint\
    \ = ModInt<MOD>;\n    Matrix<modint,500> m=Matrix<modint,500>::E();\n    int N;\
    \ cin >> N;\n    for(int i = 0; i < N; ++i) {\n        for(int j = 0; j < N; ++j)\
    \ {\n            cin >> m[i][j];\n        }\n    }\n    cout << m.determinant()\
    \ << endl;\n\treturn 0;\n}"
  dependsOn:
  - lib/util/ModInt.cpp
  - lib/math/Matrix.cpp
  isVerificationFile: true
  path: test/math/Matrix-det.test.cpp
  requiredBy: []
  timestamp: '2020-09-26 17:01:19+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/Matrix-det.test.cpp
layout: document
redirect_from:
- /verify/test/math/Matrix-det.test.cpp
- /verify/test/math/Matrix-det.test.cpp.html
title: test/math/Matrix-det.test.cpp
---
