---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-eulertour.test.cpp
    title: test/graph/Tree-eulertour.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-hld-vertex-1.test.cpp
    title: test/graph/Tree-hld-vertex-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment-tree/LazySegmentTree-rmqraq.test.cpp
    title: test/segment-tree/LazySegmentTree-rmqraq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment-tree/LazySegmentTree-rsqruq.test.cpp
    title: test/segment-tree/LazySegmentTree-rsqruq.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/segment-tree/LazySegmentTree.md
    document_title: "LazySegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u9045\u5EF6\
      \u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 1 \"lib/10-segment-tree/LazySegmentTree.cpp\"\n/*\n * @title\
    \ LazySegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u9045\u5EF6\u8A55\u4FA1\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @docs md/segment-tree/LazySegmentTree.md\n\
    \ */\ntemplate<class Monoid> class LazySegmentTree {\n    using TypeNode = typename\
    \ Monoid::TypeNode;\n    using TypeLazy = typename Monoid::TypeLazy;\n    size_t\
    \ num;\n    size_t length;\n    size_t height;\n    vector<TypeNode> node;\n \
    \   vector<TypeLazy> lazy;\n    vector<pair<size_t,size_t>> range;\n\n    void\
    \ propagate(int k) {\n        if(lazy[k] == Monoid::unit_lazy) return;\n     \
    \   node[k] = Monoid::func_operate(node[k],lazy[k],range[k].first,range[k].second);\n\
    \        if(k < length) lazy[2*k+0] = Monoid::func_lazy(lazy[2*k+0],lazy[k]);\n\
    \        if(k < length) lazy[2*k+1] = Monoid::func_lazy(lazy[2*k+1],lazy[k]);\n\
    \        lazy[k] = Monoid::unit_lazy;\n    }\n\n    void build() {\n        for\
    \ (int i = length - 1; i >= 0; --i) node[i] = Monoid::func_fold(node[(i<<1)+0],node[(i<<1)+1]);\n\
    \        range.resize(2 * length);\n        for (int i = 0; i < length; ++i) range[i+length]\
    \ = make_pair(i,i+1);\n        for (int i = length - 1; i >= 0; --i) range[i]\
    \ = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n    }\npublic:\n\
    \n    //unit\u3067\u521D\u671F\u5316\n    LazySegmentTree(const size_t num) :\
    \ num(num) {\n        for (length = 1,height = 0; length <= num; length *= 2,\
    \ height++);\n        node.resize(2 * length, Monoid::unit_node);\n        lazy.resize(2\
    \ * length, Monoid::unit_lazy);\n        for (int i = 0; i < num; ++i) node[i\
    \ + length] = Monoid::unit_node;\n        build();\n    }\n\n    // //\u540C\u3058\
    init\u3067\u521D\u671F\u5316\n    LazySegmentTree(const size_t num, const TypeNode\
    \ init) : num(num) {\n        for (length = 1,height = 0; length <= num; length\
    \ *= 2, height++);\n        node.resize(2 * length, Monoid::unit_node);\n    \
    \    lazy.resize(2 * length, Monoid::unit_lazy);\n        for (int i = 0; i <\
    \ num; ++i) node[i + length] = init;\n        build();\n    }\n\n    //vector\u3067\
    \u521D\u671F\u5316\n    LazySegmentTree(const vector<TypeNode>& vec) : num(vec.size())\
    \ {\n        for (length = 1,height = 0; length <= vec.size(); length *= 2, height++);\n\
    \        node.resize(2 * length, Monoid::unit_node);\n        lazy.resize(2 *\
    \ length, Monoid::unit_lazy);\n        for (int i = 0; i < vec.size(); ++i) node[i\
    \ + length] = vec[i];\n        build();\n    }\n\n    //operate [a,b)\n    void\
    \ operate(int a, int b, TypeLazy x) {\n        int l = a + length, r = b + length\
    \ - 1;\n        for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r\
    \ >> i);\n        for(r++; l < r; l >>=1, r >>=1) {\n            if(l&1) lazy[l]\
    \ = Monoid::func_lazy(lazy[l],x), propagate(l),l++;\n            if(r&1) --r,lazy[r]\
    \ = Monoid::func_lazy(lazy[r],x), propagate(r);\n        }\n        l = a + length,\
    \ r = b + length - 1;\n        while ((l>>=1),(r>>=1),l) {\n            if(lazy[l]\
    \ == Monoid::unit_lazy) node[l] = Monoid::func_fold(Monoid::func_operate(node[(l<<1)+0],lazy[(l<<1)+0],range[(l<<1)+0].first,range[(l<<1)+0].second),Monoid::func_operate(node[(l<<1)+1],lazy[(l<<1)+1],range[(l<<1)+1].first,range[(l<<1)+1].second));\n\
    \            if(lazy[r] == Monoid::unit_lazy) node[r] = Monoid::func_fold(Monoid::func_operate(node[(r<<1)+0],lazy[(r<<1)+0],range[(r<<1)+0].first,range[(r<<1)+0].second),Monoid::func_operate(node[(r<<1)+1],lazy[(r<<1)+1],range[(r<<1)+1].first,range[(r<<1)+1].second));\n\
    \        }\n    }\n\n    //fold [a,b)\n    TypeNode fold(int a, int b) {\n   \
    \     int l = a + length, r = b + length - 1;\n        for (int i = height; 0\
    \ < i; --i) propagate(l >> i), propagate(r >> i);\n        TypeNode vl = Monoid::unit_node,\
    \ vr = Monoid::unit_node;\n        for(r++; l < r; l >>=1, r >>=1) {\n       \
    \     if(l&1) vl = Monoid::func_fold(vl,Monoid::func_operate(node[l],lazy[l],range[l].first,range[l].second)),l++;\n\
    \            if(r&1) r--,vr = Monoid::func_fold(Monoid::func_operate(node[r],lazy[r],range[r].first,range[r].second),vr);\n\
    \        }\n        return Monoid::func_fold(vl,vr);\n    }\n\n    //return [0,length]\n\
    \    int prefix_binary_search(TypeNode var) {\n        int l = length, r = 2*length\
    \ - 1;\n        for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r\
    \ >> i);\n        if(!Monoid::func_check(node[1],var)) return num;\n        TypeNode\
    \ ret = Monoid::unit_node;\n        size_t idx = 2;\n        for(; idx < 2*length;\
    \ idx<<=1){\n            if(!Monoid::func_check(Monoid::func_fold(ret,Monoid::func_operate(node[idx],lazy[idx],range[idx].first,range[idx].second)),var))\
    \ {\n                ret = Monoid::func_fold(ret,Monoid::func_operate(node[idx],lazy[idx],range[idx].first,range[idx].second));\n\
    \                idx++;\n            }\n        }\n        return min((idx>>1)\
    \ - length,num);\n    }\n\n    //range[l,r) return [l,r]\n    int binary_search(size_t\
    \ l, size_t r, TypeNode var) {\n        if (l < 0 || length <= l || r < 0 || length\
    \ < r) return -1;\n        for (int i = height; 0 < i; --i) propagate((l+length)\
    \ >> i), propagate((r+length-1) >> i);\n        TypeNode ret = Monoid::unit_node;\n\
    \        size_t off = l;\n        for(size_t idx = l+length; idx < 2*length &&\
    \ off < r; ){\n            if(range[idx].second<=r && !Monoid::func_check(Monoid::func_fold(ret,Monoid::func_operate(node[idx],lazy[idx],range[idx].first,range[idx].second)),var))\
    \ {\n                ret = Monoid::func_fold(ret,Monoid::func_operate(node[idx],lazy[idx],range[idx].first,range[idx].second));\n\
    \                off = range[idx++].second;\n                if(!(idx&1)) idx\
    \ >>= 1;\n            }\n            else{\n                idx <<=1;\n      \
    \      }\n        }\n        return off;\n    }\n\n    void print(){\n       \
    \ // cout << \"node\" << endl;\n        // for(int i = 1,j = 1; i < 2*length;\
    \ ++i) {\n        // \tcout << node[i] << \" \";\n        // \tif(i==((1<<j)-1)\
    \ && ++j) cout << endl;\n        // }\n        // cout << \"lazy\" << endl;\n\
    \        // for(int i = 1,j = 1; i < 2*length; ++i) {\n        // \tcout << lazy[i]\
    \ << \" \";\n        // \tif(i==((1<<j)-1) && ++j) cout << endl;\n        // }\n\
    \        cout << \"vector\" << endl;\n        cout << \"{ \" << fold(0,1);\n \
    \       for(int i = 1; i < length; ++i) cout << \", \" << fold(i,i+1);\n     \
    \   cout << \" }\" << endl;\n    }\n};\n"
  code: "/*\n * @title LazySegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u9045\
    \u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @docs md/segment-tree/LazySegmentTree.md\n\
    \ */\ntemplate<class Monoid> class LazySegmentTree {\n    using TypeNode = typename\
    \ Monoid::TypeNode;\n    using TypeLazy = typename Monoid::TypeLazy;\n    size_t\
    \ num;\n    size_t length;\n    size_t height;\n    vector<TypeNode> node;\n \
    \   vector<TypeLazy> lazy;\n    vector<pair<size_t,size_t>> range;\n\n    void\
    \ propagate(int k) {\n        if(lazy[k] == Monoid::unit_lazy) return;\n     \
    \   node[k] = Monoid::func_operate(node[k],lazy[k],range[k].first,range[k].second);\n\
    \        if(k < length) lazy[2*k+0] = Monoid::func_lazy(lazy[2*k+0],lazy[k]);\n\
    \        if(k < length) lazy[2*k+1] = Monoid::func_lazy(lazy[2*k+1],lazy[k]);\n\
    \        lazy[k] = Monoid::unit_lazy;\n    }\n\n    void build() {\n        for\
    \ (int i = length - 1; i >= 0; --i) node[i] = Monoid::func_fold(node[(i<<1)+0],node[(i<<1)+1]);\n\
    \        range.resize(2 * length);\n        for (int i = 0; i < length; ++i) range[i+length]\
    \ = make_pair(i,i+1);\n        for (int i = length - 1; i >= 0; --i) range[i]\
    \ = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n    }\npublic:\n\
    \n    //unit\u3067\u521D\u671F\u5316\n    LazySegmentTree(const size_t num) :\
    \ num(num) {\n        for (length = 1,height = 0; length <= num; length *= 2,\
    \ height++);\n        node.resize(2 * length, Monoid::unit_node);\n        lazy.resize(2\
    \ * length, Monoid::unit_lazy);\n        for (int i = 0; i < num; ++i) node[i\
    \ + length] = Monoid::unit_node;\n        build();\n    }\n\n    // //\u540C\u3058\
    init\u3067\u521D\u671F\u5316\n    LazySegmentTree(const size_t num, const TypeNode\
    \ init) : num(num) {\n        for (length = 1,height = 0; length <= num; length\
    \ *= 2, height++);\n        node.resize(2 * length, Monoid::unit_node);\n    \
    \    lazy.resize(2 * length, Monoid::unit_lazy);\n        for (int i = 0; i <\
    \ num; ++i) node[i + length] = init;\n        build();\n    }\n\n    //vector\u3067\
    \u521D\u671F\u5316\n    LazySegmentTree(const vector<TypeNode>& vec) : num(vec.size())\
    \ {\n        for (length = 1,height = 0; length <= vec.size(); length *= 2, height++);\n\
    \        node.resize(2 * length, Monoid::unit_node);\n        lazy.resize(2 *\
    \ length, Monoid::unit_lazy);\n        for (int i = 0; i < vec.size(); ++i) node[i\
    \ + length] = vec[i];\n        build();\n    }\n\n    //operate [a,b)\n    void\
    \ operate(int a, int b, TypeLazy x) {\n        int l = a + length, r = b + length\
    \ - 1;\n        for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r\
    \ >> i);\n        for(r++; l < r; l >>=1, r >>=1) {\n            if(l&1) lazy[l]\
    \ = Monoid::func_lazy(lazy[l],x), propagate(l),l++;\n            if(r&1) --r,lazy[r]\
    \ = Monoid::func_lazy(lazy[r],x), propagate(r);\n        }\n        l = a + length,\
    \ r = b + length - 1;\n        while ((l>>=1),(r>>=1),l) {\n            if(lazy[l]\
    \ == Monoid::unit_lazy) node[l] = Monoid::func_fold(Monoid::func_operate(node[(l<<1)+0],lazy[(l<<1)+0],range[(l<<1)+0].first,range[(l<<1)+0].second),Monoid::func_operate(node[(l<<1)+1],lazy[(l<<1)+1],range[(l<<1)+1].first,range[(l<<1)+1].second));\n\
    \            if(lazy[r] == Monoid::unit_lazy) node[r] = Monoid::func_fold(Monoid::func_operate(node[(r<<1)+0],lazy[(r<<1)+0],range[(r<<1)+0].first,range[(r<<1)+0].second),Monoid::func_operate(node[(r<<1)+1],lazy[(r<<1)+1],range[(r<<1)+1].first,range[(r<<1)+1].second));\n\
    \        }\n    }\n\n    //fold [a,b)\n    TypeNode fold(int a, int b) {\n   \
    \     int l = a + length, r = b + length - 1;\n        for (int i = height; 0\
    \ < i; --i) propagate(l >> i), propagate(r >> i);\n        TypeNode vl = Monoid::unit_node,\
    \ vr = Monoid::unit_node;\n        for(r++; l < r; l >>=1, r >>=1) {\n       \
    \     if(l&1) vl = Monoid::func_fold(vl,Monoid::func_operate(node[l],lazy[l],range[l].first,range[l].second)),l++;\n\
    \            if(r&1) r--,vr = Monoid::func_fold(Monoid::func_operate(node[r],lazy[r],range[r].first,range[r].second),vr);\n\
    \        }\n        return Monoid::func_fold(vl,vr);\n    }\n\n    //return [0,length]\n\
    \    int prefix_binary_search(TypeNode var) {\n        int l = length, r = 2*length\
    \ - 1;\n        for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r\
    \ >> i);\n        if(!Monoid::func_check(node[1],var)) return num;\n        TypeNode\
    \ ret = Monoid::unit_node;\n        size_t idx = 2;\n        for(; idx < 2*length;\
    \ idx<<=1){\n            if(!Monoid::func_check(Monoid::func_fold(ret,Monoid::func_operate(node[idx],lazy[idx],range[idx].first,range[idx].second)),var))\
    \ {\n                ret = Monoid::func_fold(ret,Monoid::func_operate(node[idx],lazy[idx],range[idx].first,range[idx].second));\n\
    \                idx++;\n            }\n        }\n        return min((idx>>1)\
    \ - length,num);\n    }\n\n    //range[l,r) return [l,r]\n    int binary_search(size_t\
    \ l, size_t r, TypeNode var) {\n        if (l < 0 || length <= l || r < 0 || length\
    \ < r) return -1;\n        for (int i = height; 0 < i; --i) propagate((l+length)\
    \ >> i), propagate((r+length-1) >> i);\n        TypeNode ret = Monoid::unit_node;\n\
    \        size_t off = l;\n        for(size_t idx = l+length; idx < 2*length &&\
    \ off < r; ){\n            if(range[idx].second<=r && !Monoid::func_check(Monoid::func_fold(ret,Monoid::func_operate(node[idx],lazy[idx],range[idx].first,range[idx].second)),var))\
    \ {\n                ret = Monoid::func_fold(ret,Monoid::func_operate(node[idx],lazy[idx],range[idx].first,range[idx].second));\n\
    \                off = range[idx++].second;\n                if(!(idx&1)) idx\
    \ >>= 1;\n            }\n            else{\n                idx <<=1;\n      \
    \      }\n        }\n        return off;\n    }\n\n    void print(){\n       \
    \ // cout << \"node\" << endl;\n        // for(int i = 1,j = 1; i < 2*length;\
    \ ++i) {\n        // \tcout << node[i] << \" \";\n        // \tif(i==((1<<j)-1)\
    \ && ++j) cout << endl;\n        // }\n        // cout << \"lazy\" << endl;\n\
    \        // for(int i = 1,j = 1; i < 2*length; ++i) {\n        // \tcout << lazy[i]\
    \ << \" \";\n        // \tif(i==((1<<j)-1) && ++j) cout << endl;\n        // }\n\
    \        cout << \"vector\" << endl;\n        cout << \"{ \" << fold(0,1);\n \
    \       for(int i = 1; i < length; ++i) cout << \", \" << fold(i,i+1);\n     \
    \   cout << \" }\" << endl;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/10-segment-tree/LazySegmentTree.cpp
  requiredBy: []
  timestamp: '2023-05-30 05:01:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segment-tree/LazySegmentTree-rsqruq.test.cpp
  - test/segment-tree/LazySegmentTree-rmqraq.test.cpp
  - test/graph/Tree-eulertour.test.cpp
  - test/graph/Tree-hld-vertex-1.test.cpp
documentation_of: lib/10-segment-tree/LazySegmentTree.cpp
layout: document
redirect_from:
- /library/lib/10-segment-tree/LazySegmentTree.cpp
- /library/lib/10-segment-tree/LazySegmentTree.cpp.html
title: "LazySegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u9045\u5EF6\u8A55\u4FA1\
  \u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
