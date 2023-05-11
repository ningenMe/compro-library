---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-hld-path.test.cpp
    title: test/graph/Tree-hld-path.test.cpp
  - icon: ':x:'
    path: test/math/Matrix-det.test.cpp
    title: test/math/Matrix-det.test.cpp
  - icon: ':x:'
    path: test/math/Matrix-pow.test.cpp
    title: test/math/Matrix-pow.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: md/math/Matrix.md
    document_title: "Matrix - \u884C\u5217\u6F14\u7B97"
    links: []
  bundledCode: "#line 1 \"lib/math/Matrix.cpp\"\n/*\n * @title Matrix - \u884C\u5217\
    \u6F14\u7B97\n * @docs md/math/Matrix.md\n */\ntemplate <class T, int H, int W\
    \ = H> class Matrix {\npublic:\n    int h,w;\n    array<array<T,W>,H> a;\n   \
    \ Matrix():h(H),w(W){\n        // do nothing\n    }\n    Matrix(const vector<vector<T>>&\
    \ vec):h(H),w(W) {\n        assert(vec.size()==H && vec.front().size()==W);\n\
    \        for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) a[i][j]=vec[i][j];\n\
    \    }\n    static Matrix E() {\n        assert(H==W);\n        Matrix res = Matrix();\n\
    \        for(int i = 0; i < H; ++i) res[i][i]=1;\n        return res;\n    }\n\
    \    Matrix &operator+=(const Matrix &r) {\n        assert(H==r.h&&W==r.w);\n\
    \        for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) a[i][j]+=r[i][j];\n\
    \        return *this;\n    }\n    Matrix &operator-=(const Matrix &r) {\n   \
    \     assert(H==r.h&&W==r.w);\n        for(int i = 0; i < H; ++i) for(int j =\
    \ 0; j < W; ++j) a[i][j]-=r[i][j];\n        return *this;\n    }\n    Matrix &operator*=(const\
    \ Matrix &r) {\n        assert(W==r.h);\n        Matrix res = Matrix();\n    \
    \    for(int i = 0; i < H; ++i) for(int j = 0; j < r.w; ++j) for(int k = 0; k\
    \ < W; ++k) res[i][j]+=(a[i][k])*(r[k][j]);\n        a.swap(res.a);\n        return\
    \ *this;\n    }\n    Matrix operator+(const Matrix& r) const {\n        return\
    \ Matrix(*this) += r;\n    }\n    Matrix operator-(const Matrix& r) const {\n\
    \        return Matrix(*this) -= r;\n    }\n    Matrix operator*(const Matrix&\
    \ r) const {\n        return Matrix(*this) *= r;\n    }\n    inline array<T,W>\
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
    \ -= x[i][k]*tmp;\n            }\n        }\n        return res;\n    }\n};\n"
  code: "/*\n * @title Matrix - \u884C\u5217\u6F14\u7B97\n * @docs md/math/Matrix.md\n\
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
    \ -= x[i][k]*tmp;\n            }\n        }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/Matrix.cpp
  requiredBy: []
  timestamp: '2021-09-21 19:35:58+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/math/Matrix-pow.test.cpp
  - test/math/Matrix-det.test.cpp
  - test/graph/Tree-hld-path.test.cpp
documentation_of: lib/math/Matrix.cpp
layout: document
redirect_from:
- /library/lib/math/Matrix.cpp
- /library/lib/math/Matrix.cpp.html
title: "Matrix - \u884C\u5217\u6F14\u7B97"
---
