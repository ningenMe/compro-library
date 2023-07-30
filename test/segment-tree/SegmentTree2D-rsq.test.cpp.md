---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/00-util/FastIO.cpp
    title: FastIO
  - icon: ':heavy_check_mark:'
    path: lib/10-segment-tree/SegmentTree2D.cpp
    title: "SegmentTree2D - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u30BB\u30B0\u30E1\
      \u30F3\u30C8\u67282D"
  - icon: ':heavy_check_mark:'
    path: lib/99-operator/monoid/MonoidRangeSumPointAdd.cpp
    title: "MonoidRangeSumPointAdd - [\u533A\u9593\u548C, \u4E00\u70B9\u52A0\u7B97\
      ]"
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
  bundledCode: "#line 1 \"test/segment-tree/SegmentTree2D-rsq.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\
    \n\n#include <iostream>\n#include <vector>\n#include <tuple>\nusing namespace\
    \ std;\n#line 1 \"lib/00-util/FastIO.cpp\"\n/*\n * @title FastIO\n * @docs md/util/FastIO.md\n\
    \ */\nclass FastIO{\nprivate:\n    inline static constexpr int ch_0='0';\n   \
    \ inline static constexpr int ch_9='9';\n    inline static constexpr int ch_n='-';\n\
    \    inline static constexpr int ch_s=' ';\n    inline static constexpr int ch_l='\\\
    n';\n    inline static void endline_skip(char& ch) {\n        while(ch==ch_l)\
    \ ch=getchar();\n    }\n    template<typename T> inline static void read_integer(T\
    \ &x) {\n        int neg=0; char ch; x=0;\n        ch=getchar();\n        endline_skip(ch);\n\
    \        if(ch==ch_n) neg=1,ch=getchar();\n        for(;(ch_0 <= ch && ch <= ch_9);\
    \ ch = getchar()) x = x*10 + (ch-ch_0);\n        if(neg) x*=-1;\n    }\n    template<typename\
    \ T> inline static void read_unsigned_integer(T &x) {\n        char ch; x=0;\n\
    \        ch=getchar();\n        endline_skip(ch);\n        for(;(ch_0 <= ch &&\
    \ ch <= ch_9); ch = getchar()) x = x*10 + (ch-ch_0);\n    }\n    inline static\
    \ void read_string(string &x) {\n        char ch; x=\"\";\n        ch=getchar();\n\
    \        endline_skip(ch);\n        for(;(ch != ch_s && ch!=ch_l); ch = getchar())\
    \ x.push_back(ch);\n    }\n    inline static char ar[40];\n    inline static char\
    \ *ch_ar;\n    template<typename T> inline static void write_integer(T x) {\n\
    \        ch_ar=ar;\n        if(x< 0) putchar(ch_n), x=-x;\n        if(x==0) putchar(ch_0);\n\
    \        for(;x;x/=10) *ch_ar++=(ch_0+x%10);\n        while(ch_ar--!=ar) putchar(*ch_ar);\n\
    \    }\npublic:\n    inline static void read(int &x) {read_integer<int>(x);}\n\
    \    inline static void read(long long &x) {read_integer<long long>(x);}\n   \
    \ inline static void read(unsigned int &x) {read_unsigned_integer<unsigned int>(x);}\n\
    \    inline static void read(unsigned long long &x) {read_unsigned_integer<unsigned\
    \ long long>(x);}\n    inline static void read(string &x) {read_string(x);}\n\
    \    inline static void read(__int128_t &x) {read_integer<__int128_t>(x);}\n \
    \   inline static void write(__int128_t x) {write_integer<__int128_t>(x);}\n \
    \   inline static void write(char x) {putchar(x);}\n};\n#define read(arg) FastIO::read(arg)\n\
    #define write(arg) FastIO::write(arg)\n#line 1 \"lib/10-segment-tree/SegmentTree2D.cpp\"\
    \n/*\n * @title SegmentTree2D - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u67282D\n * @docs md/segment-tree/SegmentTree2D.md\n */\ntemplate<class\
    \ Monoid> class SegmentTree2D {\n    using TypeNode = typename Monoid::TypeNode;\n\
    \    class SegmentTree {\n        size_t length;\n        vector<TypeNode> node;\n\
    \    public:\n        //unit\u3067\u521D\u671F\u5316\n        SegmentTree(const\
    \ size_t num) {\n            for (length = 1; length <= num; length *= 2);\n \
    \           node.resize(2 * length, Monoid::unit_node);\n            for (int\
    \ i = length - 1; i >= 0; --i) node[i] = Monoid::func_fold(node[(i<<1)+0],node[(i<<1)+1]);\n\
    \        }\n        //[idx,idx+1)\n        void operate(size_t idx, const TypeNode\
    \ var) {\n            if(idx < 0 || length <= idx) return;\n            idx +=\
    \ length;\n            node[idx] = Monoid::func_operate(node[idx],var);\n    \
    \        while(idx >>= 1) node[idx] = Monoid::func_fold(node[(idx<<1)+0],node[(idx<<1)+1]);\n\
    \        }\n        //[l,r)\n        TypeNode fold(int l, int r) {\n         \
    \   if (l < 0 || length <= l || r < 0 || length < r) return Monoid::unit_node;\n\
    \            TypeNode vl = Monoid::unit_node, vr = Monoid::unit_node;\n      \
    \      for(l += length, r += length; l < r; l >>=1, r >>=1) {\n              \
    \  if(l&1) vl = Monoid::func_fold(vl,node[l++]);\n                if(r&1) vr =\
    \ Monoid::func_fold(node[--r],vr);\n            }\n            return Monoid::func_fold(vl,vr);\n\
    \        }\n        void print() {\n            cout << \"{\";\n            for(int\
    \ i=0; i < length; ++i) cout << fold(i,i+1) << \" }\"[i+1==length];\n        \
    \    cout << endl;\n        }\n    };\n    size_t height,width;\n    vector<SegmentTree>\
    \ node;\npublic:\n    SegmentTree2D(const size_t h, const size_t w):width(w) {\n\
    \        for (height = 1; height <= h; height *= 2);\n        SegmentTree seg(width);\n\
    \        node.resize(2 * height, seg);\n        for (int i = height - 1; i >=\
    \ 0; --i) {\n            for(int j=0; j < width; ++j) {\n                node[i].operate(j,\
    \ Monoid::func_fold(node[(i<<1)+0].fold(j,j+1),node[(i<<1)+1].fold(j,j+1)));\n\
    \            }\n        }\n    }\n    //[u,u+1)*[l,l+1) \u306B operate\n    void\
    \ operate(size_t u, size_t l, const TypeNode var) {\n        if(u < 0 || height\
    \ <= u || l < 0 || width <= l) return;\n        u += height;\n        node[u].operate(l,\
    \ var);\n        while(u >>= 1) node[u].operate(l, Monoid::func_fold(node[(u<<1)+0].fold(l,l+1),node[(u<<1)+1].fold(l,l+1)));\n\
    \    }\n    //[u,d),[l,r)\n    TypeNode fold(int u, int d, int l, int r) {\n \
    \       if(u < 0 || height <= u || d < 0 || height < d || l < 0 || width <= l\
    \ || r < 0 || width < r) return Monoid::unit_node;\n        TypeNode vu = Monoid::unit_node,\
    \ vd = Monoid::unit_node;\n        for(u += height, d += height; u < d; u >>=1,\
    \ d >>=1) {\n            if(u&1) vu = Monoid::func_fold(vu,node[u++].fold(l,r));\n\
    \            if(d&1) vd = Monoid::func_fold(node[--d].fold(l,r),vd);\n       \
    \ }\n        return Monoid::func_fold(vu,vd);\n    }\n    void print() {\n   \
    \     for(int i=height; i < 2*height; ++i) {\n            node[i].print();\n \
    \       }\n    }\n};\n#line 1 \"lib/99-operator/monoid/MonoidRangeSumPointAdd.cpp\"\
    \n/*\n * @title MonoidRangeSumPointAdd - [\u533A\u9593\u548C, \u4E00\u70B9\u52A0\
    \u7B97]\n * @docs md/operator/monoid/MonoidRangeSumPointAdd.md\n */\ntemplate<class\
    \ T> struct MonoidRangeSumPointAdd {\n    using TypeNode = T;\n    inline static\
    \ constexpr TypeNode unit_node = 0;\n    inline static constexpr TypeNode func_fold(TypeNode\
    \ l,TypeNode r){return l+r;}\n    inline static constexpr TypeNode func_operate(TypeNode\
    \ l,TypeNode r){return l+r;}\n    inline static constexpr bool func_check(TypeNode\
    \ nodeVal,TypeNode var){return var == nodeVal;}\n};\n#line 10 \"test/segment-tree/SegmentTree2D-rsq.test.cpp\"\
    \n\nint main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N; read(N);\n\
    \    int L = 1002;\n    SegmentTree2D<MonoidRangeSumPointAdd<int>> seg(L,L);\n\
    \    while(N--) {\n        int x1,y1,x2,y2; \n        read(x1),read(y1),read(x2),read(y2);\n\
    \        seg.operate(y1,x1, 1);\n        seg.operate(y1,x2,-1);\n        seg.operate(y2,x1,-1);\n\
    \        seg.operate(y2,x2, 1);\n    }\n    for(int i=0;i<L;++i) {\n        for(int\
    \ j=1;j<L;++j) {\n            seg.operate(i,j,seg.fold(i,i+1,j-1,j));\n      \
    \  }\n    }\n    for(int j=0;j<L;++j) {\n        for(int i=1;i<L;++i) {\n    \
    \        seg.operate(i,j,seg.fold(i-1,i,j,j+1));\n        }\n    }\n    int ans\
    \ = 0;\n    for(int i=0;i<L;++i) {\n        for(int j=0;j<L;++j) {\n         \
    \   ans=max(ans,seg.fold(i,i+1,j,j+1));\n        }\n    }\n    cout << ans <<\
    \ \"\\n\";\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\
    \n\n#include <iostream>\n#include <vector>\n#include <tuple>\nusing namespace\
    \ std;\n#include \"../../lib/00-util/FastIO.cpp\"\n#include \"../../lib/10-segment-tree/SegmentTree2D.cpp\"\
    \n#include \"../../lib/99-operator/monoid/MonoidRangeSumPointAdd.cpp\"\n\nint\
    \ main(void){\n    cin.tie(0);ios::sync_with_stdio(false);\n    int N; read(N);\n\
    \    int L = 1002;\n    SegmentTree2D<MonoidRangeSumPointAdd<int>> seg(L,L);\n\
    \    while(N--) {\n        int x1,y1,x2,y2; \n        read(x1),read(y1),read(x2),read(y2);\n\
    \        seg.operate(y1,x1, 1);\n        seg.operate(y1,x2,-1);\n        seg.operate(y2,x1,-1);\n\
    \        seg.operate(y2,x2, 1);\n    }\n    for(int i=0;i<L;++i) {\n        for(int\
    \ j=1;j<L;++j) {\n            seg.operate(i,j,seg.fold(i,i+1,j-1,j));\n      \
    \  }\n    }\n    for(int j=0;j<L;++j) {\n        for(int i=1;i<L;++i) {\n    \
    \        seg.operate(i,j,seg.fold(i-1,i,j,j+1));\n        }\n    }\n    int ans\
    \ = 0;\n    for(int i=0;i<L;++i) {\n        for(int j=0;j<L;++j) {\n         \
    \   ans=max(ans,seg.fold(i,i+1,j,j+1));\n        }\n    }\n    cout << ans <<\
    \ \"\\n\";\n\treturn 0;\n}"
  dependsOn:
  - lib/00-util/FastIO.cpp
  - lib/10-segment-tree/SegmentTree2D.cpp
  - lib/99-operator/monoid/MonoidRangeSumPointAdd.cpp
  isVerificationFile: true
  path: test/segment-tree/SegmentTree2D-rsq.test.cpp
  requiredBy: []
  timestamp: '2023-07-31 02:39:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segment-tree/SegmentTree2D-rsq.test.cpp
layout: document
redirect_from:
- /verify/test/segment-tree/SegmentTree2D-rsq.test.cpp
- /verify/test/segment-tree/SegmentTree2D-rsq.test.cpp.html
title: test/segment-tree/SegmentTree2D-rsq.test.cpp
---
