---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/segment-tree/SegmentTree2D.md
    document_title: "SegmentTree2D - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u30BB\u30B0\
      \u30E1\u30F3\u30C8\u67282D"
    links: []
  bundledCode: "#line 1 \"lib/10-segment-tree/SegmentTree2D.cpp\"\n/*\n * @title SegmentTree2D\
    \ - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u30BB\u30B0\u30E1\u30F3\u30C8\u67282D\n\
    \ * @docs md/segment-tree/SegmentTree2D.md\n */\ntemplate<class Monoid> class\
    \ SegmentTree2D {\n    using TypeNode = typename Monoid::TypeNode;\n    class\
    \ SegmentTree {\n        size_t length;\n        vector<TypeNode> node;\n    public:\n\
    \        //unit\u3067\u521D\u671F\u5316\n        SegmentTree(const size_t num)\
    \ {\n            for (length = 1; length <= num; length *= 2);\n            node.resize(2\
    \ * length, Monoid::unit_node);\n            for (int i = length - 1; i >= 0;\
    \ --i) node[i] = Monoid::func_fold(node[(i<<1)+0],node[(i<<1)+1]);\n        }\n\
    \        //[idx,idx+1)\n        void operate(size_t idx, const TypeNode var) {\n\
    \            if(idx < 0 || length <= idx) return;\n            idx += length;\n\
    \            node[idx] = Monoid::func_operate(node[idx],var);\n            while(idx\
    \ >>= 1) node[idx] = Monoid::func_fold(node[(idx<<1)+0],node[(idx<<1)+1]);\n \
    \       }\n        //[l,r)\n        TypeNode fold(int l, int r) {\n          \
    \  if (l < 0 || length <= l || r < 0 || length < r) return Monoid::unit_node;\n\
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
    \       }\n    }\n};\n"
  code: "/*\n * @title SegmentTree2D - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u30BB\u30B0\
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
    \       }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/10-segment-tree/SegmentTree2D.cpp
  requiredBy: []
  timestamp: '2023-06-26 04:05:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/10-segment-tree/SegmentTree2D.cpp
layout: document
redirect_from:
- /library/lib/10-segment-tree/SegmentTree2D.cpp
- /library/lib/10-segment-tree/SegmentTree2D.cpp.html
title: "SegmentTree2D - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u30BB\u30B0\u30E1\u30F3\
  \u30C8\u67282D"
---
### SegmentTree2D
- [提出](https://atcoder.jp/contests/abc228/submissions/42967851)
- 空間: $O(H*W)$
- operate, fold: $O(\log H \log W)$
