---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/rectangle/IntersectRectangle.md
    document_title: "IntersectRectangle - \u9577\u65B9\u5F62\u306E\u4EA4\u5DEE\u306E\
      \u30AB\u30A6\u30F3\u30C8"
    links: []
  bundledCode: "#line 1 \"lib/17-rectangle/IntersectRectangle.cpp\"\n/*\n * @title\
    \ IntersectRectangle - \u9577\u65B9\u5F62\u306E\u4EA4\u5DEE\u306E\u30AB\u30A6\u30F3\
    \u30C8\n * @docs md/rectangle/IntersectRectangle.md\n */\ntemplate<class T> class\
    \ IntersectRectangle {\n    class BinaryIndexedTree {\n        size_t length;\
    \ vector<T> node;\n    public:\n        BinaryIndexedTree(const size_t num) {\
    \ for (length = 1; length < num; length *= 2); node.resize(length+1, 0);}\n  \
    \      void operate(size_t idx, T val) { for (++idx; idx <= length; idx += idx\
    \ & -idx) node[idx] += val; }\n        T fold(size_t idx) { T res = 0; for (idx\
    \ = min(length,idx); idx > 0; idx -= idx & -idx) res += node[idx]; return res;}\n\
    \        void clear() {for(size_t i = 0; i <= length; ++i) node[i] = 0;}\n   \
    \ };\n    size_t N;\n    vector<int> count;\n    void build(vector<T> vl, vector<T>\
    \ vr, vector<T> vd, vector<T> vu) {\n        N = vl.size();\n        assert(vr.size()\
    \ == N);\n        assert(vd.size() == N);\n        assert(vu.size() == N);\n \
    \       for(size_t i = 0; i < N; ++i) {\n            assert(vl[i] < vr[i] && vd[i]\
    \ < vu[i]);\n        }\n        //x,y\u305D\u308C\u305E\u308C\u3067\u5EA7\u5727\
    \n        vector<T> sorted_x(2*N),sorted_y(2*N);\n        for(size_t i=0;i<N;++i)\
    \ {\n            sorted_x[2*i+0]=vl[i];\n            sorted_x[2*i+1]=vr[i];\n\
    \            sorted_y[2*i+0]=vd[i];\n            sorted_y[2*i+1]=vu[i];\n    \
    \    }\n        sort(sorted_x.begin(), sorted_x.end());\n        sort(sorted_y.begin(),\
    \ sorted_y.end());\n        vector<size_t> zl(N),zr(N),zd(N),zu(N);\n        for(size_t\
    \ i=0;i<N;++i) {\n            zl[i] = lower_bound(sorted_x.begin(), sorted_x.end(),\
    \ vl[i]) - sorted_x.begin();\n            zr[i] = lower_bound(sorted_x.begin(),\
    \ sorted_x.end(), vr[i]) - sorted_x.begin();\n            zd[i] = lower_bound(sorted_y.begin(),\
    \ sorted_y.end(), vd[i]) - sorted_y.begin();\n            zu[i] = lower_bound(sorted_y.begin(),\
    \ sorted_y.end(), vu[i]) - sorted_y.begin();\n        }\n        //   |  | \n\
    \        // --|--|--\n        //   | s| \n        // --|--|--\n        //   |\
    \  |\n        // \u9818\u57DFs\u306B\u5BFE\u3057\u3066\u3001s\u3068\u5171\u6709\
    \u9818\u57DF\u3092\u6301\u305F\u306A\u3044\u3082\u306E\u3092\u5305\u9664\u539F\
    \u7406\u3067\u6570\u3048\u308B {\u5DE6|\u53F3|\u4E0A|\u4E0B} - {\u5DE6\u4E0A|\u5DE6\
    \u4E0B|\u53F3\u4E0A|\u53F3\u4E0B}\n        count.resize(N,0);\n        BinaryIndexedTree\
    \ bit(2*N);\n        {\n            for(size_t i=0;i<N;++i) bit.operate(zr[i]-1,1);\n\
    \            for(size_t i=0;i<N;++i) count[i] += bit.fold(zl[i]);\n          \
    \  bit.clear();\n            for(size_t i=0;i<N;++i) bit.operate(zl[i],1);\n \
    \           for(size_t i=0;i<N;++i) count[i] += N-bit.fold(zr[i]);\n         \
    \   bit.clear();\n            for(size_t i=0;i<N;++i) bit.operate(zu[i]-1,1);\n\
    \            for(size_t i=0;i<N;++i) count[i] += bit.fold(zd[i]);\n          \
    \  bit.clear();\n            for(size_t i=0;i<N;++i) bit.operate(zd[i],1);\n \
    \           for(size_t i=0;i<N;++i) count[i] += N-bit.fold(zu[i]);\n         \
    \   bit.clear();\n        }\n        vector<tuple<size_t,int,size_t>> sorted_zx;\n\
    \        BinaryIndexedTree bit_u(2*N),bit_d(2*N);\n        {\n            for(size_t\
    \ i=0;i<N;++i) sorted_zx.emplace_back(zl[i],1,i), sorted_zx.emplace_back(zr[i],0,i);\n\
    \            sort(sorted_zx.begin(), sorted_zx.end());\n        }\n        {\n\
    \            for(size_t j=0;j<2*N;++j) {\n                auto [_,lr,i] = sorted_zx[j];\n\
    \                if(lr == 1) {\n                    count[i] -= bit_u.fold(zd[i]);\n\
    \                    count[i] -= bit_d.fold(2*N)-bit_d.fold(zu[i]);\n        \
    \        }\n                if(lr == 0) {\n                    bit_d.operate(zd[i],1);\n\
    \                    bit_u.operate(zu[i]-1,1);\n                }\n          \
    \  }\n            bit_d.clear();\n            bit_u.clear();\n            for(size_t\
    \ j=2*N-1;;--j) {\n                auto [_,lr,i] = sorted_zx[j];\n           \
    \     if(lr == 1) {\n                    bit_d.operate(zd[i],1);\n           \
    \         bit_u.operate(zu[i]-1,1);\n                }\n                if(lr\
    \ == 0) {\n                    count[i] -= bit_u.fold(zd[i]);\n              \
    \      count[i] -= bit_d.fold(2*N)-bit_d.fold(zu[i]);\n                }\n   \
    \             if(j==0) break;\n            }\n        }\n    }\npublic:\n    //[l,r)\
    \ x [d,u) \u306E\u9577\u65B9\u5F62\u306E\u96C6\u5408\n    IntersectRectangle(const\
    \ vector<array<T,4>>& l_r_d_u){\n        size_t N = l_r_d_u.size();\n        vector<T>\
    \ vl(N),vr(N),vd(N),vu(N);\n        for(size_t i = 0; i < N; ++i) {\n        \
    \    auto [a,b,c,d]=l_r_d_u[i];\n            vl[i]=a,vr[i]=b,vd[i]=c,vu[i]=d;\n\
    \        }\n        build(vl,vr,vd,vu);\n    }\n    IntersectRectangle(const vector<T>&\
    \ vl, const vector<T>& vr, const vector<T>& vd, const vector<T>& vu) {\n     \
    \   build(vl,vr,vd,vu);\n    }\n    size_t size() { return N; }\n    int get(const\
    \ size_t i) { return N-1-count[i]; }\n};\n"
  code: "/*\n * @title IntersectRectangle - \u9577\u65B9\u5F62\u306E\u4EA4\u5DEE\u306E\
    \u30AB\u30A6\u30F3\u30C8\n * @docs md/rectangle/IntersectRectangle.md\n */\ntemplate<class\
    \ T> class IntersectRectangle {\n    class BinaryIndexedTree {\n        size_t\
    \ length; vector<T> node;\n    public:\n        BinaryIndexedTree(const size_t\
    \ num) { for (length = 1; length < num; length *= 2); node.resize(length+1, 0);}\n\
    \        void operate(size_t idx, T val) { for (++idx; idx <= length; idx += idx\
    \ & -idx) node[idx] += val; }\n        T fold(size_t idx) { T res = 0; for (idx\
    \ = min(length,idx); idx > 0; idx -= idx & -idx) res += node[idx]; return res;}\n\
    \        void clear() {for(size_t i = 0; i <= length; ++i) node[i] = 0;}\n   \
    \ };\n    size_t N;\n    vector<int> count;\n    void build(vector<T> vl, vector<T>\
    \ vr, vector<T> vd, vector<T> vu) {\n        N = vl.size();\n        assert(vr.size()\
    \ == N);\n        assert(vd.size() == N);\n        assert(vu.size() == N);\n \
    \       for(size_t i = 0; i < N; ++i) {\n            assert(vl[i] < vr[i] && vd[i]\
    \ < vu[i]);\n        }\n        //x,y\u305D\u308C\u305E\u308C\u3067\u5EA7\u5727\
    \n        vector<T> sorted_x(2*N),sorted_y(2*N);\n        for(size_t i=0;i<N;++i)\
    \ {\n            sorted_x[2*i+0]=vl[i];\n            sorted_x[2*i+1]=vr[i];\n\
    \            sorted_y[2*i+0]=vd[i];\n            sorted_y[2*i+1]=vu[i];\n    \
    \    }\n        sort(sorted_x.begin(), sorted_x.end());\n        sort(sorted_y.begin(),\
    \ sorted_y.end());\n        vector<size_t> zl(N),zr(N),zd(N),zu(N);\n        for(size_t\
    \ i=0;i<N;++i) {\n            zl[i] = lower_bound(sorted_x.begin(), sorted_x.end(),\
    \ vl[i]) - sorted_x.begin();\n            zr[i] = lower_bound(sorted_x.begin(),\
    \ sorted_x.end(), vr[i]) - sorted_x.begin();\n            zd[i] = lower_bound(sorted_y.begin(),\
    \ sorted_y.end(), vd[i]) - sorted_y.begin();\n            zu[i] = lower_bound(sorted_y.begin(),\
    \ sorted_y.end(), vu[i]) - sorted_y.begin();\n        }\n        //   |  | \n\
    \        // --|--|--\n        //   | s| \n        // --|--|--\n        //   |\
    \  |\n        // \u9818\u57DFs\u306B\u5BFE\u3057\u3066\u3001s\u3068\u5171\u6709\
    \u9818\u57DF\u3092\u6301\u305F\u306A\u3044\u3082\u306E\u3092\u5305\u9664\u539F\
    \u7406\u3067\u6570\u3048\u308B {\u5DE6|\u53F3|\u4E0A|\u4E0B} - {\u5DE6\u4E0A|\u5DE6\
    \u4E0B|\u53F3\u4E0A|\u53F3\u4E0B}\n        count.resize(N,0);\n        BinaryIndexedTree\
    \ bit(2*N);\n        {\n            for(size_t i=0;i<N;++i) bit.operate(zr[i]-1,1);\n\
    \            for(size_t i=0;i<N;++i) count[i] += bit.fold(zl[i]);\n          \
    \  bit.clear();\n            for(size_t i=0;i<N;++i) bit.operate(zl[i],1);\n \
    \           for(size_t i=0;i<N;++i) count[i] += N-bit.fold(zr[i]);\n         \
    \   bit.clear();\n            for(size_t i=0;i<N;++i) bit.operate(zu[i]-1,1);\n\
    \            for(size_t i=0;i<N;++i) count[i] += bit.fold(zd[i]);\n          \
    \  bit.clear();\n            for(size_t i=0;i<N;++i) bit.operate(zd[i],1);\n \
    \           for(size_t i=0;i<N;++i) count[i] += N-bit.fold(zu[i]);\n         \
    \   bit.clear();\n        }\n        vector<tuple<size_t,int,size_t>> sorted_zx;\n\
    \        BinaryIndexedTree bit_u(2*N),bit_d(2*N);\n        {\n            for(size_t\
    \ i=0;i<N;++i) sorted_zx.emplace_back(zl[i],1,i), sorted_zx.emplace_back(zr[i],0,i);\n\
    \            sort(sorted_zx.begin(), sorted_zx.end());\n        }\n        {\n\
    \            for(size_t j=0;j<2*N;++j) {\n                auto [_,lr,i] = sorted_zx[j];\n\
    \                if(lr == 1) {\n                    count[i] -= bit_u.fold(zd[i]);\n\
    \                    count[i] -= bit_d.fold(2*N)-bit_d.fold(zu[i]);\n        \
    \        }\n                if(lr == 0) {\n                    bit_d.operate(zd[i],1);\n\
    \                    bit_u.operate(zu[i]-1,1);\n                }\n          \
    \  }\n            bit_d.clear();\n            bit_u.clear();\n            for(size_t\
    \ j=2*N-1;;--j) {\n                auto [_,lr,i] = sorted_zx[j];\n           \
    \     if(lr == 1) {\n                    bit_d.operate(zd[i],1);\n           \
    \         bit_u.operate(zu[i]-1,1);\n                }\n                if(lr\
    \ == 0) {\n                    count[i] -= bit_u.fold(zd[i]);\n              \
    \      count[i] -= bit_d.fold(2*N)-bit_d.fold(zu[i]);\n                }\n   \
    \             if(j==0) break;\n            }\n        }\n    }\npublic:\n    //[l,r)\
    \ x [d,u) \u306E\u9577\u65B9\u5F62\u306E\u96C6\u5408\n    IntersectRectangle(const\
    \ vector<array<T,4>>& l_r_d_u){\n        size_t N = l_r_d_u.size();\n        vector<T>\
    \ vl(N),vr(N),vd(N),vu(N);\n        for(size_t i = 0; i < N; ++i) {\n        \
    \    auto [a,b,c,d]=l_r_d_u[i];\n            vl[i]=a,vr[i]=b,vd[i]=c,vu[i]=d;\n\
    \        }\n        build(vl,vr,vd,vu);\n    }\n    IntersectRectangle(const vector<T>&\
    \ vl, const vector<T>& vr, const vector<T>& vd, const vector<T>& vu) {\n     \
    \   build(vl,vr,vd,vu);\n    }\n    size_t size() { return N; }\n    int get(const\
    \ size_t i) { return N-1-count[i]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/17-rectangle/IntersectRectangle.cpp
  requiredBy: []
  timestamp: '2023-08-19 07:15:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/17-rectangle/IntersectRectangle.cpp
layout: document
redirect_from:
- /library/lib/17-rectangle/IntersectRectangle.cpp
- /library/lib/17-rectangle/IntersectRectangle.cpp.html
title: "IntersectRectangle - \u9577\u65B9\u5F62\u306E\u4EA4\u5DEE\u306E\u30AB\u30A6\
  \u30F3\u30C8"
---
### IntersectRectangle
- 長方形の交差のカウント
- 2次元平面上の $N$ 個の長方形が、各長方形について他の長方形といくつ交差しているか(共有面積があるか)をカウントする

### コンストラクタ
- IntersectRectangle(vector<T>& vl, vector<T>& vr, vector<T>& vd, vector<T>& vu)
  - $[l,r)$ x $[d,u)$ の区間の長方形 $N$ 個を 4つのvectorで渡す
  - $O(N \log N)$ (定数倍重め)
  - 内部的には、ある長方形目線で、上下左右の8方向に平面を分割し、共有領域を持たないものを包除原理で数える。{左|右|上|下} - {左上|左下|右上|右下}
  - {左上|左下|右上|右下} のカウントは、bitを用いて平面走査

### メソッド
- size()
  - 列のサイズを返す
  - $O(1)$
- int get(size_t i)
  - i番目の長方形が、他の長方形といくつ交差しているかのカウントを返却する
  - $O(1)$
  - 値域としては $0 \le count \le N-1 $

### 参考資料
- [提出](https://atcoder.jp/contests/abc312/submissions/44693062)