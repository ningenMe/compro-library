---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/Matrix-pow.test.cpp
    title: test/math/Matrix-pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Matrix-det.test.cpp
    title: test/math/Matrix-det.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: md/math/Matrix.md
    document_title: "Matrix - \u884C\u5217\u6F14\u7B97"
    links: []
  bundledCode: "#line 1 \"lib/math/Matrix.cpp\"\n/*\n * @title Matrix - \u884C\u5217\
    \u6F14\u7B97\n * @docs md/math/Matrix.md\n */\ntemplate <class T, int H, int W\
    \ = H> class Matrix {\npublic:\n\tint h,w;\n\tarray<array<T,W>,H> a;\n\tMatrix():h(H),w(W){\n\
    \t\t// do nothing\n\t}\n\tMatrix(const vector<vector<T>>& vec):h(H),w(W) {\n\t\
    \tassert(vec.size()==H && vec.front().size()==W);\n\t\tfor(int i = 0; i < H; ++i)\
    \ for(int j = 0; j < W; ++j) a[i][j]=vec[i][j];\n\t}\n\tstatic Matrix E() {\n\t\
    \tassert(H==W);\n\t\tMatrix res = Matrix();\n\t\tfor(int i = 0; i < H; ++i) res[i][i]=1;\n\
    \t\treturn res;\n\t}\n\tMatrix &operator+=(const Matrix &r) {\n\t\tassert(H==r.h&&W==r.w);\n\
    \t\tfor(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) a[i][j]+=r[i][j];\n\t\
    \treturn *this;\n\t}\n\tMatrix &operator-=(const Matrix &r) {\n\t\tassert(H==r.h&&W==r.w);\n\
    \t\tfor(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) a[i][j]-=r[i][j];\n\t\
    \treturn *this;\n\t}\n\tMatrix &operator*=(const Matrix &r) {\n\t\tassert(W==r.h);\n\
    \t\tMatrix res = Matrix();\n\t\tfor(int i = 0; i < H; ++i) for(int j = 0; j <\
    \ r.w; ++j) for(int k = 0; k < W; ++k) res[i][j]+=(a[i][k])*(r[k][j]);\n\t\ta.swap(res.a);\n\
    \t\treturn *this;\n\t}\n\tMatrix operator+(const Matrix& r) const {\n\t\treturn\
    \ Matrix(*this) += r;\n\t}\n\tMatrix operator-(const Matrix& r) const {\n\t\t\
    return Matrix(*this) -= r;\n\t}\n\tMatrix operator*(const Matrix& r) const {\n\
    \t\treturn Matrix(*this) *= r;\n\t}\n\tinline array<T,W> &operator[](int i) {\
    \ \n\t\treturn a[i];\n\t}\n\tinline const array<T,W> &operator[](int i) const\
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
    }\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  code: "/*\n * @title Matrix - \u884C\u5217\u6F14\u7B97\n * @docs md/math/Matrix.md\n\
    \ */\ntemplate <class T, int H, int W = H> class Matrix {\npublic:\n\tint h,w;\n\
    \tarray<array<T,W>,H> a;\n\tMatrix():h(H),w(W){\n\t\t// do nothing\n\t}\n\tMatrix(const\
    \ vector<vector<T>>& vec):h(H),w(W) {\n\t\tassert(vec.size()==H && vec.front().size()==W);\n\
    \t\tfor(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) a[i][j]=vec[i][j];\n\
    \t}\n\tstatic Matrix E() {\n\t\tassert(H==W);\n\t\tMatrix res = Matrix();\n\t\t\
    for(int i = 0; i < H; ++i) res[i][i]=1;\n\t\treturn res;\n\t}\n\tMatrix &operator+=(const\
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
    }\n\t\t}\n\t\treturn res;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/Matrix.cpp
  requiredBy: []
  timestamp: '2020-09-26 16:29:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/Matrix-pow.test.cpp
  - test/math/Matrix-det.test.cpp
documentation_of: lib/math/Matrix.cpp
layout: document
redirect_from:
- /library/lib/math/Matrix.cpp
- /library/lib/math/Matrix.cpp.html
title: "Matrix - \u884C\u5217\u6F14\u7B97"
---
