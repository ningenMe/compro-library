---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/segment-tree/LazySegmentTree-rmqraq.test.cpp
    title: test/data-structure/segment-tree/LazySegmentTree-rmqraq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/segment-tree/LazySegmentTree-rsqruq.test.cpp
    title: test/data-structure/segment-tree/LazySegmentTree-rsqruq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-eulertour.test.cpp
    title: test/graph/Tree-eulertour.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-hld-vertex-1.test.cpp
    title: test/graph/Tree-hld-vertex-1.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/data-structure/segment-tree/LazySegmentTree.md
    document_title: "LazySegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u9045\u5EF6\
      \u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 1 \"lib/data-structure/segment-tree/LazySegmentTree.cpp\"\n\
    /*\n * @title LazySegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u9045\u5EF6\
    \u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @docs md/data-structure/segment-tree/LazySegmentTree.md\n\
    \ */\ntemplate<class Monoid> class LazySegmentTree {\n\tusing TypeNode = typename\
    \ Monoid::TypeNode;          \n\tusing TypeLazy = typename Monoid::TypeLazy;\n\
    \tsize_t num;      \n\tsize_t length;                                   \n\tsize_t\
    \ height;                                   \n\tvector<TypeNode> node;       \
    \                    \n\tvector<TypeLazy> lazy;                           \n\t\
    vector<pair<size_t,size_t>> range;\n\n\tvoid propagate(int k) {\n\t\tif(lazy[k]\
    \ == Monoid::unit_lazy) return;\n        node[k] = Monoid::func_operate(node[k],lazy[k],range[k].first,range[k].second);\n\
    \t\tif(k < length) lazy[2*k+0] = Monoid::func_lazy(lazy[2*k+0],lazy[k]);\n\t\t\
    if(k < length) lazy[2*k+1] = Monoid::func_lazy(lazy[2*k+1],lazy[k]);\n\t\tlazy[k]\
    \ = Monoid::unit_lazy;\n\t}\n\n\tvoid build() {\n\t\tfor (int i = length - 1;\
    \ i >= 0; --i) node[i] = Monoid::func_fold(node[(i<<1)+0],node[(i<<1)+1]);\n\t\
    \trange.resize(2 * length);\n\t\tfor (int i = 0; i < length; ++i) range[i+length]\
    \ = make_pair(i,i+1);\n\t\tfor (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \t}\npublic:\n\n\t//unit\u3067\u521D\u671F\u5316\n\tLazySegmentTree(const size_t\
    \ num) : num(num) {\n\t\tfor (length = 1,height = 0; length <= num; length *=\
    \ 2, height++);\n\t\tnode.resize(2 * length, Monoid::unit_node);\n\t\tlazy.resize(2\
    \ * length, Monoid::unit_lazy);\n\t\tfor (int i = 0; i < num; ++i) node[i + length]\
    \ = Monoid::unit_node;\n\t\tbuild();\n\t}\n\n\t// //\u540C\u3058init\u3067\u521D\
    \u671F\u5316\n\tLazySegmentTree(const size_t num, const TypeNode init) : num(num)\
    \ {\n\t\tfor (length = 1,height = 0; length <= num; length *= 2, height++);\n\t\
    \tnode.resize(2 * length, Monoid::unit_node);\n\t\tlazy.resize(2 * length, Monoid::unit_lazy);\n\
    \t\tfor (int i = 0; i < num; ++i) node[i + length] = init;\n\t\tbuild();\n\t}\n\
    \n\t//vector\u3067\u521D\u671F\u5316\n\tLazySegmentTree(const vector<TypeNode>&\
    \ vec) : num(vec.size()) {\n\t\tfor (length = 1,height = 0; length <= vec.size();\
    \ length *= 2, height++);\n\t\tnode.resize(2 * length, Monoid::unit_node);\n\t\
    \tlazy.resize(2 * length, Monoid::unit_lazy);\n\t\tfor (int i = 0; i < vec.size();\
    \ ++i) node[i + length] = vec[i];\n\t\tbuild();\n\t}\n\n\t//operate [a,b)\n\t\
    void operate(int a, int b, TypeLazy x) {\n\t\tint l = a + length, r = b + length\
    \ - 1;\n\t\tfor (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >>\
    \ i);\n\t\tfor(r++; l < r; l >>=1, r >>=1) {\n\t\t\tif(l&1) lazy[l] = Monoid::func_lazy(lazy[l],x),\
    \ propagate(l),l++;\n\t\t\tif(r&1) --r,lazy[r] = Monoid::func_lazy(lazy[r],x),\
    \ propagate(r);\n\t\t}\n\t\tl = a + length, r = b + length - 1;\n\t\twhile ((l>>=1),(r>>=1),l)\
    \ {\n            if(lazy[l] == Monoid::unit_lazy) node[l] = Monoid::func_fold(Monoid::func_operate(node[(l<<1)+0],lazy[(l<<1)+0],range[(l<<1)+0].first,range[(l<<1)+0].second),Monoid::func_operate(node[(l<<1)+1],lazy[(l<<1)+1],range[(l<<1)+1].first,range[(l<<1)+1].second));\n\
    \            if(lazy[r] == Monoid::unit_lazy) node[r] = Monoid::func_fold(Monoid::func_operate(node[(r<<1)+0],lazy[(r<<1)+0],range[(r<<1)+0].first,range[(r<<1)+0].second),Monoid::func_operate(node[(r<<1)+1],lazy[(r<<1)+1],range[(r<<1)+1].first,range[(r<<1)+1].second));\n\
    \  \t\t}\n\t}\n\n\t//fold [a,b)\n\tTypeNode fold(int a, int b) {\n\t\tint l =\
    \ a + length, r = b + length - 1;\n\t\tfor (int i = height; 0 < i; --i) propagate(l\
    \ >> i), propagate(r >> i);\n\t\tTypeNode vl = Monoid::unit_node, vr = Monoid::unit_node;\n\
    \t\tfor(r++; l < r; l >>=1, r >>=1) {\n            if(l&1) vl = Monoid::func_fold(vl,Monoid::func_operate(node[l],lazy[l],range[l].first,range[l].second)),l++;\n\
    \            if(r&1) r--,vr = Monoid::func_fold(Monoid::func_operate(node[r],lazy[r],range[r].first,range[r].second),vr);\n\
    \ \t\t}\n\t\treturn Monoid::func_fold(vl,vr);\n\t}\n\n\t//return [0,length]\n\t\
    int prefix_binary_search(TypeNode var) {\n\t\tint l = length, r = 2*length - 1;\n\
    \t\tfor (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);\n\t\
    \tif(!Monoid::func_check(node[1],var)) return num;\n\t\tTypeNode ret = Monoid::unit_node;\n\
    \t\tsize_t idx = 2;\n\t\tfor(; idx < 2*length; idx<<=1){\n            if(!Monoid::func_check(Monoid::func_fold(ret,Monoid::func_operate(node[idx],lazy[idx],range[idx].first,range[idx].second)),var))\
    \ {\n                ret = Monoid::func_fold(ret,Monoid::func_operate(node[idx],lazy[idx],range[idx].first,range[idx].second));\n\
    \                idx++;\n            }\n\t\t}\n\t\treturn min((idx>>1) - length,num);\n\
    \t}\n\n\t//range[l,r) return [l,r]\n\tint binary_search(size_t l, size_t r, TypeNode\
    \ var) {\n\t\tif (l < 0 || length <= l || r < 0 || length < r) return -1;\n\t\t\
    for (int i = height; 0 < i; --i) propagate((l+length) >> i), propagate((r+length-1)\
    \ >> i);\n\t\tTypeNode ret = Monoid::unit_node;\n\t\tsize_t off = l;\n\t\tfor(size_t\
    \ idx = l+length; idx < 2*length && off < r; ){\n            if(range[idx].second<=r\
    \ && !Monoid::func_check(Monoid::func_fold(ret,Monoid::func_operate(node[idx],lazy[idx],range[idx].first,range[idx].second)),var))\
    \ {\n                ret = Monoid::func_fold(ret,Monoid::func_operate(node[idx],lazy[idx],range[idx].first,range[idx].second));\n\
    \                off = range[idx++].second;\n                if(!(idx&1)) idx\
    \ >>= 1;\t\t\t\n            }\n            else{\n\t\t\t\tidx <<=1;\n\t\t\t}\n\
    \t\t}\n\t\treturn off;\n\t}\n\n\tvoid print(){\n\t\t// cout << \"node\" << endl;\n\
    \t\t// for(int i = 1,j = 1; i < 2*length; ++i) {\n\t\t// \tcout << node[i] <<\
    \ \" \";\n\t\t// \tif(i==((1<<j)-1) && ++j) cout << endl;\n\t\t// }\n\t\t// cout\
    \ << \"lazy\" << endl;\n\t\t// for(int i = 1,j = 1; i < 2*length; ++i) {\n\t\t\
    // \tcout << lazy[i] << \" \";\n\t\t// \tif(i==((1<<j)-1) && ++j) cout << endl;\n\
    \t\t// }\n\t\tcout << \"vector\" << endl;\n\t\tcout << \"{ \" << fold(0,1);\n\t\
    \tfor(int i = 1; i < length; ++i) cout << \", \" << fold(i,i+1);\n\t\tcout <<\
    \ \" }\" << endl;\n\t}\n};\n"
  code: "/*\n * @title LazySegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u9045\
    \u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @docs md/data-structure/segment-tree/LazySegmentTree.md\n\
    \ */\ntemplate<class Monoid> class LazySegmentTree {\n\tusing TypeNode = typename\
    \ Monoid::TypeNode;          \n\tusing TypeLazy = typename Monoid::TypeLazy;\n\
    \tsize_t num;      \n\tsize_t length;                                   \n\tsize_t\
    \ height;                                   \n\tvector<TypeNode> node;       \
    \                    \n\tvector<TypeLazy> lazy;                           \n\t\
    vector<pair<size_t,size_t>> range;\n\n\tvoid propagate(int k) {\n\t\tif(lazy[k]\
    \ == Monoid::unit_lazy) return;\n        node[k] = Monoid::func_operate(node[k],lazy[k],range[k].first,range[k].second);\n\
    \t\tif(k < length) lazy[2*k+0] = Monoid::func_lazy(lazy[2*k+0],lazy[k]);\n\t\t\
    if(k < length) lazy[2*k+1] = Monoid::func_lazy(lazy[2*k+1],lazy[k]);\n\t\tlazy[k]\
    \ = Monoid::unit_lazy;\n\t}\n\n\tvoid build() {\n\t\tfor (int i = length - 1;\
    \ i >= 0; --i) node[i] = Monoid::func_fold(node[(i<<1)+0],node[(i<<1)+1]);\n\t\
    \trange.resize(2 * length);\n\t\tfor (int i = 0; i < length; ++i) range[i+length]\
    \ = make_pair(i,i+1);\n\t\tfor (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \t}\npublic:\n\n\t//unit\u3067\u521D\u671F\u5316\n\tLazySegmentTree(const size_t\
    \ num) : num(num) {\n\t\tfor (length = 1,height = 0; length <= num; length *=\
    \ 2, height++);\n\t\tnode.resize(2 * length, Monoid::unit_node);\n\t\tlazy.resize(2\
    \ * length, Monoid::unit_lazy);\n\t\tfor (int i = 0; i < num; ++i) node[i + length]\
    \ = Monoid::unit_node;\n\t\tbuild();\n\t}\n\n\t// //\u540C\u3058init\u3067\u521D\
    \u671F\u5316\n\tLazySegmentTree(const size_t num, const TypeNode init) : num(num)\
    \ {\n\t\tfor (length = 1,height = 0; length <= num; length *= 2, height++);\n\t\
    \tnode.resize(2 * length, Monoid::unit_node);\n\t\tlazy.resize(2 * length, Monoid::unit_lazy);\n\
    \t\tfor (int i = 0; i < num; ++i) node[i + length] = init;\n\t\tbuild();\n\t}\n\
    \n\t//vector\u3067\u521D\u671F\u5316\n\tLazySegmentTree(const vector<TypeNode>&\
    \ vec) : num(vec.size()) {\n\t\tfor (length = 1,height = 0; length <= vec.size();\
    \ length *= 2, height++);\n\t\tnode.resize(2 * length, Monoid::unit_node);\n\t\
    \tlazy.resize(2 * length, Monoid::unit_lazy);\n\t\tfor (int i = 0; i < vec.size();\
    \ ++i) node[i + length] = vec[i];\n\t\tbuild();\n\t}\n\n\t//operate [a,b)\n\t\
    void operate(int a, int b, TypeLazy x) {\n\t\tint l = a + length, r = b + length\
    \ - 1;\n\t\tfor (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >>\
    \ i);\n\t\tfor(r++; l < r; l >>=1, r >>=1) {\n\t\t\tif(l&1) lazy[l] = Monoid::func_lazy(lazy[l],x),\
    \ propagate(l),l++;\n\t\t\tif(r&1) --r,lazy[r] = Monoid::func_lazy(lazy[r],x),\
    \ propagate(r);\n\t\t}\n\t\tl = a + length, r = b + length - 1;\n\t\twhile ((l>>=1),(r>>=1),l)\
    \ {\n            if(lazy[l] == Monoid::unit_lazy) node[l] = Monoid::func_fold(Monoid::func_operate(node[(l<<1)+0],lazy[(l<<1)+0],range[(l<<1)+0].first,range[(l<<1)+0].second),Monoid::func_operate(node[(l<<1)+1],lazy[(l<<1)+1],range[(l<<1)+1].first,range[(l<<1)+1].second));\n\
    \            if(lazy[r] == Monoid::unit_lazy) node[r] = Monoid::func_fold(Monoid::func_operate(node[(r<<1)+0],lazy[(r<<1)+0],range[(r<<1)+0].first,range[(r<<1)+0].second),Monoid::func_operate(node[(r<<1)+1],lazy[(r<<1)+1],range[(r<<1)+1].first,range[(r<<1)+1].second));\n\
    \  \t\t}\n\t}\n\n\t//fold [a,b)\n\tTypeNode fold(int a, int b) {\n\t\tint l =\
    \ a + length, r = b + length - 1;\n\t\tfor (int i = height; 0 < i; --i) propagate(l\
    \ >> i), propagate(r >> i);\n\t\tTypeNode vl = Monoid::unit_node, vr = Monoid::unit_node;\n\
    \t\tfor(r++; l < r; l >>=1, r >>=1) {\n            if(l&1) vl = Monoid::func_fold(vl,Monoid::func_operate(node[l],lazy[l],range[l].first,range[l].second)),l++;\n\
    \            if(r&1) r--,vr = Monoid::func_fold(Monoid::func_operate(node[r],lazy[r],range[r].first,range[r].second),vr);\n\
    \ \t\t}\n\t\treturn Monoid::func_fold(vl,vr);\n\t}\n\n\t//return [0,length]\n\t\
    int prefix_binary_search(TypeNode var) {\n\t\tint l = length, r = 2*length - 1;\n\
    \t\tfor (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);\n\t\
    \tif(!Monoid::func_check(node[1],var)) return num;\n\t\tTypeNode ret = Monoid::unit_node;\n\
    \t\tsize_t idx = 2;\n\t\tfor(; idx < 2*length; idx<<=1){\n            if(!Monoid::func_check(Monoid::func_fold(ret,Monoid::func_operate(node[idx],lazy[idx],range[idx].first,range[idx].second)),var))\
    \ {\n                ret = Monoid::func_fold(ret,Monoid::func_operate(node[idx],lazy[idx],range[idx].first,range[idx].second));\n\
    \                idx++;\n            }\n\t\t}\n\t\treturn min((idx>>1) - length,num);\n\
    \t}\n\n\t//range[l,r) return [l,r]\n\tint binary_search(size_t l, size_t r, TypeNode\
    \ var) {\n\t\tif (l < 0 || length <= l || r < 0 || length < r) return -1;\n\t\t\
    for (int i = height; 0 < i; --i) propagate((l+length) >> i), propagate((r+length-1)\
    \ >> i);\n\t\tTypeNode ret = Monoid::unit_node;\n\t\tsize_t off = l;\n\t\tfor(size_t\
    \ idx = l+length; idx < 2*length && off < r; ){\n            if(range[idx].second<=r\
    \ && !Monoid::func_check(Monoid::func_fold(ret,Monoid::func_operate(node[idx],lazy[idx],range[idx].first,range[idx].second)),var))\
    \ {\n                ret = Monoid::func_fold(ret,Monoid::func_operate(node[idx],lazy[idx],range[idx].first,range[idx].second));\n\
    \                off = range[idx++].second;\n                if(!(idx&1)) idx\
    \ >>= 1;\t\t\t\n            }\n            else{\n\t\t\t\tidx <<=1;\n\t\t\t}\n\
    \t\t}\n\t\treturn off;\n\t}\n\n\tvoid print(){\n\t\t// cout << \"node\" << endl;\n\
    \t\t// for(int i = 1,j = 1; i < 2*length; ++i) {\n\t\t// \tcout << node[i] <<\
    \ \" \";\n\t\t// \tif(i==((1<<j)-1) && ++j) cout << endl;\n\t\t// }\n\t\t// cout\
    \ << \"lazy\" << endl;\n\t\t// for(int i = 1,j = 1; i < 2*length; ++i) {\n\t\t\
    // \tcout << lazy[i] << \" \";\n\t\t// \tif(i==((1<<j)-1) && ++j) cout << endl;\n\
    \t\t// }\n\t\tcout << \"vector\" << endl;\n\t\tcout << \"{ \" << fold(0,1);\n\t\
    \tfor(int i = 1; i < length; ++i) cout << \", \" << fold(i,i+1);\n\t\tcout <<\
    \ \" }\" << endl;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data-structure/segment-tree/LazySegmentTree.cpp
  requiredBy: []
  timestamp: '2021-04-26 18:07:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/segment-tree/LazySegmentTree-rmqraq.test.cpp
  - test/data-structure/segment-tree/LazySegmentTree-rsqruq.test.cpp
  - test/graph/Tree-eulertour.test.cpp
  - test/graph/Tree-hld-vertex-1.test.cpp
documentation_of: lib/data-structure/segment-tree/LazySegmentTree.cpp
layout: document
redirect_from:
- /library/lib/data-structure/segment-tree/LazySegmentTree.cpp
- /library/lib/data-structure/segment-tree/LazySegmentTree.cpp.html
title: "LazySegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u9045\u5EF6\u8A55\u4FA1\
  \u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
