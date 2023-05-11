---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/geometory/RectangleWeight.cpp
    title: "RectangleWeight - \u91CD\u307F\u3064\u304D\u77E9\u5F62"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B
  bundledCode: "#line 1 \"test/geometory/RectangleWeight.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\n\n#include\
    \ <iostream>\n#include <vector>\n#include <tuple>\nusing namespace std;\n#line\
    \ 1 \"lib/geometory/RectangleWeight.cpp\"\n/*\n * @title RectangleWeight - \u91CD\
    \u307F\u3064\u304D\u77E9\u5F62\n * @docs md/geometory/RectangleWeight.md\n */\n\
    template<class T> class RectangleWeight{\n    int H,W;\n    vector<tuple<int,int,int,int,T>>\
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
    \ T get(int y,int x) {\n        return grid[y*W+x];\n    }\n};\n#line 8 \"test/geometory/RectangleWeight.test.cpp\"\
    \n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N; cin\
    \ >> N;\n    int L = 1010;\n    RectangleWeight<int> rol(L,L);\n    while(N--)\
    \ {\n        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;\n        rol.make_query(y1,x1,y2,x2,1);\n\
    \    }\n    rol.solve();\n    int ans = 0;\n    for(int i=0;i<L;++i) for(int j=0;j<L;++j)\
    \ ans=max(ans,rol.get(i,j));\n    cout << ans << endl;\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\
    \n\n#include <iostream>\n#include <vector>\n#include <tuple>\nusing namespace\
    \ std;\n#include \"../../lib/geometory/RectangleWeight.cpp\"\n\nint main(void){\n\
    \    cin.tie(0);ios::sync_with_stdio(false);\n    int N; cin >> N;\n    int L\
    \ = 1010;\n    RectangleWeight<int> rol(L,L);\n    while(N--) {\n        int x1,y1,x2,y2;\
    \ cin >> x1 >> y1 >> x2 >> y2;\n        rol.make_query(y1,x1,y2,x2,1);\n    }\n\
    \    rol.solve();\n    int ans = 0;\n    for(int i=0;i<L;++i) for(int j=0;j<L;++j)\
    \ ans=max(ans,rol.get(i,j));\n    cout << ans << endl;\n\treturn 0;\n}"
  dependsOn:
  - lib/geometory/RectangleWeight.cpp
  isVerificationFile: true
  path: test/geometory/RectangleWeight.test.cpp
  requiredBy: []
  timestamp: '2023-05-12 02:04:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometory/RectangleWeight.test.cpp
layout: document
redirect_from:
- /verify/test/geometory/RectangleWeight.test.cpp
- /verify/test/geometory/RectangleWeight.test.cpp.html
title: test/geometory/RectangleWeight.test.cpp
---
