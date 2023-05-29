---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/70-geometory/RectangleWeight.test.cpp
    title: test/70-geometory/RectangleWeight.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/geometory/RectangleWeight.md
    document_title: "RectangleWeight - \u91CD\u307F\u3064\u304D\u77E9\u5F62"
    links: []
  bundledCode: "#line 1 \"lib/70-geometory/RectangleWeight.cpp\"\n/*\n * @title RectangleWeight\
    \ - \u91CD\u307F\u3064\u304D\u77E9\u5F62\n * @docs md/geometory/RectangleWeight.md\n\
    \ */\ntemplate<class T> class RectangleWeight{\n    int H,W;\n    vector<tuple<int,int,int,int,T>>\
    \ query;\n    vector<T> grid;\npublic:\n    RectangleWeight(int H,int W):H(H),W(W),grid(H*W){\n\
    \    }\n    //[y1,y2)*[x1,x2)\u306E\u77E9\u5F62\u3001\u5747\u8CEA\u91CD\u307F\
    w\n    void make_query(int y1,int x1,int y2,int x2,T w=1) {\n        query.emplace_back(y1,x1,y2,x2,w);\n\
    \    }\n    void solve() {\n        for(const auto& q:query) {\n            int\
    \ y1 = std::get<0>(q);\n            int x1 = std::get<1>(q);\n            int\
    \ y2 = std::get<2>(q);\n            int x2 = std::get<3>(q);\n            T  \
    \ w  = std::get<4>(q);\n            grid[y1*W+x1] += w;\n            grid[y1*W+x2]\
    \ -= w;\n            grid[y2*W+x1] -= w;\n            grid[y2*W+x2] += w;\n  \
    \      }\n        for(int y=0;y<H;++y) {\n            for(int x=0;x+1<W;++x) {\n\
    \                grid[y*W+x+1] += grid[y*W+x];\n            }\n        }\n   \
    \     for(int x=0;x<W;++x) {\n            for(int y=0;y+1<H;++y) {\n         \
    \       grid[(y+1)*W+x] += grid[y*W+x];\n            }\n        }\n    }\n   \
    \ T get(int y,int x) {\n        return grid[y*W+x];\n    }\n};\n"
  code: "/*\n * @title RectangleWeight - \u91CD\u307F\u3064\u304D\u77E9\u5F62\n *\
    \ @docs md/geometory/RectangleWeight.md\n */\ntemplate<class T> class RectangleWeight{\n\
    \    int H,W;\n    vector<tuple<int,int,int,int,T>> query;\n    vector<T> grid;\n\
    public:\n    RectangleWeight(int H,int W):H(H),W(W),grid(H*W){\n    }\n    //[y1,y2)*[x1,x2)\u306E\
    \u77E9\u5F62\u3001\u5747\u8CEA\u91CD\u307Fw\n    void make_query(int y1,int x1,int\
    \ y2,int x2,T w=1) {\n        query.emplace_back(y1,x1,y2,x2,w);\n    }\n    void\
    \ solve() {\n        for(const auto& q:query) {\n            int y1 = std::get<0>(q);\n\
    \            int x1 = std::get<1>(q);\n            int y2 = std::get<2>(q);\n\
    \            int x2 = std::get<3>(q);\n            T   w  = std::get<4>(q);\n\
    \            grid[y1*W+x1] += w;\n            grid[y1*W+x2] -= w;\n          \
    \  grid[y2*W+x1] -= w;\n            grid[y2*W+x2] += w;\n        }\n        for(int\
    \ y=0;y<H;++y) {\n            for(int x=0;x+1<W;++x) {\n                grid[y*W+x+1]\
    \ += grid[y*W+x];\n            }\n        }\n        for(int x=0;x<W;++x) {\n\
    \            for(int y=0;y+1<H;++y) {\n                grid[(y+1)*W+x] += grid[y*W+x];\n\
    \            }\n        }\n    }\n    T get(int y,int x) {\n        return grid[y*W+x];\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/70-geometory/RectangleWeight.cpp
  requiredBy: []
  timestamp: '2023-05-30 04:23:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/70-geometory/RectangleWeight.test.cpp
documentation_of: lib/70-geometory/RectangleWeight.cpp
layout: document
redirect_from:
- /library/lib/70-geometory/RectangleWeight.cpp
- /library/lib/70-geometory/RectangleWeight.cpp.html
title: "RectangleWeight - \u91CD\u307F\u3064\u304D\u77E9\u5F62"
---
### RectangleOverlapsWeight
- 重み付き矩形
- staticなクエリのみに対応
- 長方形区間に重み付けをして和を計算できる
- 0-indexed

### コンストラクタ
- RectangleWeight(int H,int W)
  - H,W グリッドの大きさ。
  
### メソッド
- void make_query(int y1,int x1,int y2,int x2,T w=1) 
  - 半開区間矩形[y1,y2)*[x1,x2)に一律重みwを加える。
- void solve() 
  - 実行
- T get(int y,int x) 
  - grid[y][x]の値を返す