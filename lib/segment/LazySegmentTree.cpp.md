---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/segment/LazySegmentTree-rsqruq.test.cpp
    title: test/segment/LazySegmentTree-rsqruq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment/LazySegmentTree-rmqraq.test.cpp
    title: test/segment/LazySegmentTree-rmqraq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-rerooting.test.cpp
    title: test/graph/Tree-rerooting.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-eulertour.test.cpp
    title: test/graph/Tree-eulertour.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-hld-vertex.test.cpp
    title: test/graph/Tree-hld-vertex.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: md/segment/LazySegmentTree.md
    document_title: "LazySegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u9045\u5EF6\
      \u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 1 \"lib/segment/LazySegmentTree.cpp\"\n/*\n * @title LazySegmentTree\
    \ - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728\n * @docs md/segment/LazySegmentTree.md\n */\ntemplate<class\
    \ Operator> class LazySegmentTree {\n\tusing TypeNode = typename Operator::TypeNode;\
    \          \n\tusing TypeLazy = typename Operator::TypeLazy;\n\tsize_t num;  \
    \    \n\tsize_t length;                                   \n\tsize_t height; \
    \                                  \n\tvector<TypeNode> node;                \
    \           \n\tvector<TypeLazy> lazy;                           \n\tvector<pair<size_t,size_t>>\
    \ range;\n\n\tvoid propagate(int k) {\n\t\tif(lazy[k] == Operator::unit_lazy)\
    \ return;\n        node[k] = Operator::func_merge(node[k],lazy[k],range[k].first,range[k].second);\n\
    \t\tif(k < length) lazy[2*k+0] = Operator::func_lazy(lazy[2*k+0],lazy[k]);\n\t\
    \tif(k < length) lazy[2*k+1] = Operator::func_lazy(lazy[2*k+1],lazy[k]);\n\t\t\
    lazy[k] = Operator::unit_lazy;\n\t}\npublic:\n\n\t//unit\u3067\u521D\u671F\u5316\
    \n\tLazySegmentTree(const size_t num) : num(num) {\n\t\tfor (length = 1,height\
    \ = 0; length <= num; length *= 2, height++);\n\t\tnode.resize(2 * length, Operator::unit_node);\n\
    \t\tlazy.resize(2 * length, Operator::unit_lazy);\n\t\tfor (int i = 0; i < num;\
    \ ++i) node[i + length] = Operator::unit_node;\n\t\tfor (int i = length - 1; i\
    \ >= 0; --i) node[i] = Operator::func_node(node[(i<<1)+0],node[(i<<1)+1]);\n\t\
    \trange.resize(2 * length);\n\t\tfor (int i = 0; i < length; ++i) range[i+length]\
    \ = make_pair(i,i+1);\n\t\tfor (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \t}\n\n\t// //\u540C\u3058init\u3067\u521D\u671F\u5316\n\tLazySegmentTree(const\
    \ size_t num, const TypeNode init) : num(num) {\n\t\tfor (length = 1,height =\
    \ 0; length <= num; length *= 2, height++);\n\t\tnode.resize(2 * length, Operator::unit_node);\n\
    \t\tlazy.resize(2 * length, Operator::unit_lazy);\n\t\tfor (int i = 0; i < num;\
    \ ++i) node[i + length] = init;\n\t\tfor (int i = length - 1; i >= 0; --i) node[i]\
    \ = Operator::func_node(node[(i<<1)+0],node[(i<<1)+1]);\n\t\trange.resize(2 *\
    \ length);\n\t\tfor (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);\n\
    \t\tfor (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \t}\n\n\t//vector\u3067\u521D\u671F\u5316\n\tLazySegmentTree(const vector<TypeNode>&\
    \ vec) : num(vec.size()) {\n\t\tfor (length = 1,height = 0; length <= vec.size();\
    \ length *= 2, height++);\n\t\tnode.resize(2 * length, Operator::unit_node);\n\
    \t\tlazy.resize(2 * length, Operator::unit_lazy);\n\t\tfor (int i = 0; i < vec.size();\
    \ ++i) node[i + length] = vec[i];\n\t\tfor (int i = length - 1; i >= 0; --i) node[i]\
    \ = Operator::func_node(node[(i<<1)+0],node[(i<<1)+1]);\n\t\trange.resize(2 *\
    \ length);\n\t\tfor (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);\n\
    \t\tfor (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \t}\n\n\t//update [a,b)\n\tvoid update(int a, int b, TypeLazy x) {\n\t\tint l\
    \ = a + length, r = b + length - 1;\n\t\tfor (int i = height; 0 < i; --i) propagate(l\
    \ >> i), propagate(r >> i);\n\t\tfor(r++; l < r; l >>=1, r >>=1) {\n\t\t\tif(l&1)\
    \ lazy[l] = Operator::func_lazy(lazy[l],x), propagate(l),l++;\n\t\t\tif(r&1) --r,lazy[r]\
    \ = Operator::func_lazy(lazy[r],x), propagate(r);\n\t\t}\n\t\tl = a + length,\
    \ r = b + length - 1;\n\t\twhile ((l>>=1),(r>>=1),l) {\n            if(lazy[l]\
    \ == Operator::unit_lazy) node[l] = Operator::func_node(Operator::func_merge(node[(l<<1)+0],lazy[(l<<1)+0],range[(l<<1)+0].first,range[(l<<1)+0].second),Operator::func_merge(node[(l<<1)+1],lazy[(l<<1)+1],range[(l<<1)+1].first,range[(l<<1)+1].second));\n\
    \            if(lazy[r] == Operator::unit_lazy) node[r] = Operator::func_node(Operator::func_merge(node[(r<<1)+0],lazy[(r<<1)+0],range[(r<<1)+0].first,range[(r<<1)+0].second),Operator::func_merge(node[(r<<1)+1],lazy[(r<<1)+1],range[(r<<1)+1].first,range[(r<<1)+1].second));\n\
    \  \t\t}\n\t}\n\n\t//get [a,b)\n\tTypeNode get(int a, int b) {\n\t\tint l = a\
    \ + length, r = b + length - 1;\n\t\tfor (int i = height; 0 < i; --i) propagate(l\
    \ >> i), propagate(r >> i);\n\t\tTypeNode vl = Operator::unit_node, vr = Operator::unit_node;\n\
    \t\tfor(r++; l < r; l >>=1, r >>=1) {\n            if(l&1) vl = Operator::func_node(vl,Operator::func_merge(node[l],lazy[l],range[l].first,range[l].second)),l++;\n\
    \            if(r&1) r--,vr = Operator::func_node(Operator::func_merge(node[r],lazy[r],range[r].first,range[r].second),vr);\n\
    \ \t\t}\n\t\treturn Operator::func_node(vl,vr);\n\t}\n\n\t//return [0,length]\n\
    \tint prefix_binary_search(TypeNode var) {\n\t\tint l = length, r = 2*length -\
    \ 1;\n\t\tfor (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);\n\
    \t\tif(!Operator::func_check(node[1],var)) return num;\n\t\tTypeNode ret = Operator::unit_node;\n\
    \t\tsize_t idx = 2;\n\t\tfor(; idx < 2*length; idx<<=1){\n            if(!Operator::func_check(Operator::func_node(ret,Operator::func_merge(node[idx],lazy[idx],range[idx].first,range[idx].second)),var))\
    \ {\n                ret = Operator::func_node(ret,Operator::func_merge(node[idx],lazy[idx],range[idx].first,range[idx].second));\n\
    \                idx++;\n            }\n\t\t}\n\t\treturn min((idx>>1) - length,num);\n\
    \t}\n\n\t//range[l,r) return [l,r]\n\tint binary_search(size_t l, size_t r, TypeNode\
    \ var) {\n\t\tif (l < 0 || length <= l || r < 0 || length < r) return -1;\n\t\t\
    for (int i = height; 0 < i; --i) propagate((l+length) >> i), propagate((r+length-1)\
    \ >> i);\n\t\tTypeNode ret = Operator::unit_node;\n\t\tsize_t off = l;\n\t\tfor(size_t\
    \ idx = l+length; idx < 2*length && off < r; ){\n            if(range[idx].second<=r\
    \ && !Operator::func_check(Operator::func_node(ret,Operator::func_merge(node[idx],lazy[idx],range[idx].first,range[idx].second)),var))\
    \ {\n                ret = Operator::func_node(ret,Operator::func_merge(node[idx],lazy[idx],range[idx].first,range[idx].second));\n\
    \                off = range[idx++].second;\n                if(!(idx&1)) idx\
    \ >>= 1;\t\t\t\n            }\n            else{\n\t\t\t\tidx <<=1;\n\t\t\t}\n\
    \t\t}\n\t\treturn off;\n\t}\n\n\tvoid print(){\n\t\t// cout << \"node\" << endl;\n\
    \t\t// for(int i = 1,j = 1; i < 2*length; ++i) {\n\t\t// \tcout << node[i] <<\
    \ \" \";\n\t\t// \tif(i==((1<<j)-1) && ++j) cout << endl;\n\t\t// }\n\t\t// cout\
    \ << \"lazy\" << endl;\n\t\t// for(int i = 1,j = 1; i < 2*length; ++i) {\n\t\t\
    // \tcout << lazy[i] << \" \";\n\t\t// \tif(i==((1<<j)-1) && ++j) cout << endl;\n\
    \t\t// }\n\t\tcout << \"vector\" << endl;\n\t\tcout << \"{ \" << get(0,1);\n\t\
    \tfor(int i = 1; i < length; ++i) cout << \", \" << get(i,i+1);\n\t\tcout << \"\
    \ }\" << endl;\n\t}\n};\n\n//node:\u6700\u5C0F\u3000lazy:\u52A0\u7B97\ntemplate<class\
    \ T, class U> struct NodeMinRangeAdd {\n\tusing TypeNode = T;\n\tusing TypeLazy\
    \ = U;\n\tinline static constexpr TypeNode unit_node = 1234567890;\n\tinline static\
    \ constexpr TypeLazy unit_lazy = 0;\n\tinline static constexpr TypeNode func_node(TypeNode\
    \ l,TypeNode r){return min(l,r);}\n\tinline static constexpr TypeLazy func_lazy(TypeLazy\
    \ old_lazy,TypeLazy new_lazy){return old_lazy+new_lazy;}\n\tinline static constexpr\
    \ TypeNode func_merge(TypeNode node,TypeLazy lazy,int l, int r){return node+lazy;}\n\
    \t// LazySegmentTree<NodeMinRangeAdd<ll,ll>> Seg(N,0);\n};\n\n//node:\u7DCF\u548C\
    \u3000lazy:\u66F4\u65B0\ntemplate<class T, class U> struct NodeSumRangeUpdate\
    \ {\n\tusing TypeNode = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode\
    \ unit_node = 0;\n\tinline static constexpr TypeLazy unit_lazy = -2000;\n\tinline\
    \ static constexpr TypeNode func_node(TypeNode l,TypeNode r){return l+r;}\n\t\
    inline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return\
    \ new_lazy;}\n\tinline static constexpr TypeNode func_merge(TypeNode node,TypeLazy\
    \ lazy,int l, int r){return lazy!=-2000?lazy*(r-l):node;}\n\tinline static constexpr\
    \ bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}\n\t//\
    \ LazySegmentTree<NodeSumRangeUpdate<ll,ll>> Seg(N,0);\n};\n\n//node:\u7DCF\u548C\
    \u3000lazy:\u52A0\u7B97\ntemplate<class T, class U> struct NodeSumRangeAdd {\n\
    \tusing TypeNode = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode\
    \ unit_node = 0;\n\tinline static constexpr TypeLazy unit_lazy = 0;\n\tinline\
    \ static constexpr TypeNode func_node(TypeNode l,TypeNode r){return l+r;}\n\t\
    inline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return\
    \ old_lazy+new_lazy;}\n\tinline static constexpr TypeNode func_merge(TypeNode\
    \ node,TypeLazy lazy,int l, int r){return node+lazy*(r-l);}\n\tinline static constexpr\
    \ bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}\n\t//\
    \ LazySegmentTree<NodeSumRangeUpdate<ll,ll>> Seg(N,0);\n};\n\n//node:\u6700\u5C0F\
    \u3000lazy:\u7B49\u5DEE\u6570\u5217\u66F4\u65B0\ntemplate<class T, class U> struct\
    \ NodeMinRangeArithmeticUpdate {\n    using TypeNode = T;\n    using TypeLazy\
    \ = U;\n    inline static constexpr TypeNode unit_node = 1234567;\n    inline\
    \ static constexpr TypeLazy unit_lazy = {-2000,-2000};\n    inline static constexpr\
    \ TypeNode func_node(TypeNode l,TypeNode r){return min(l,r);}\n    inline static\
    \ constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return new_lazy;}\n\
    \    inline static constexpr TypeNode func_merge(TypeNode node,TypeLazy lazy,int\
    \ l,int r){ return (lazy.first==-2000?node:lazy.first + (l-lazy.second));}\n \
    \   inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return\
    \ var <= nodeVal;}\n};\n"
  code: "/*\n * @title LazySegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u9045\
    \u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @docs md/segment/LazySegmentTree.md\n\
    \ */\ntemplate<class Operator> class LazySegmentTree {\n\tusing TypeNode = typename\
    \ Operator::TypeNode;          \n\tusing TypeLazy = typename Operator::TypeLazy;\n\
    \tsize_t num;      \n\tsize_t length;                                   \n\tsize_t\
    \ height;                                   \n\tvector<TypeNode> node;       \
    \                    \n\tvector<TypeLazy> lazy;                           \n\t\
    vector<pair<size_t,size_t>> range;\n\n\tvoid propagate(int k) {\n\t\tif(lazy[k]\
    \ == Operator::unit_lazy) return;\n        node[k] = Operator::func_merge(node[k],lazy[k],range[k].first,range[k].second);\n\
    \t\tif(k < length) lazy[2*k+0] = Operator::func_lazy(lazy[2*k+0],lazy[k]);\n\t\
    \tif(k < length) lazy[2*k+1] = Operator::func_lazy(lazy[2*k+1],lazy[k]);\n\t\t\
    lazy[k] = Operator::unit_lazy;\n\t}\npublic:\n\n\t//unit\u3067\u521D\u671F\u5316\
    \n\tLazySegmentTree(const size_t num) : num(num) {\n\t\tfor (length = 1,height\
    \ = 0; length <= num; length *= 2, height++);\n\t\tnode.resize(2 * length, Operator::unit_node);\n\
    \t\tlazy.resize(2 * length, Operator::unit_lazy);\n\t\tfor (int i = 0; i < num;\
    \ ++i) node[i + length] = Operator::unit_node;\n\t\tfor (int i = length - 1; i\
    \ >= 0; --i) node[i] = Operator::func_node(node[(i<<1)+0],node[(i<<1)+1]);\n\t\
    \trange.resize(2 * length);\n\t\tfor (int i = 0; i < length; ++i) range[i+length]\
    \ = make_pair(i,i+1);\n\t\tfor (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \t}\n\n\t// //\u540C\u3058init\u3067\u521D\u671F\u5316\n\tLazySegmentTree(const\
    \ size_t num, const TypeNode init) : num(num) {\n\t\tfor (length = 1,height =\
    \ 0; length <= num; length *= 2, height++);\n\t\tnode.resize(2 * length, Operator::unit_node);\n\
    \t\tlazy.resize(2 * length, Operator::unit_lazy);\n\t\tfor (int i = 0; i < num;\
    \ ++i) node[i + length] = init;\n\t\tfor (int i = length - 1; i >= 0; --i) node[i]\
    \ = Operator::func_node(node[(i<<1)+0],node[(i<<1)+1]);\n\t\trange.resize(2 *\
    \ length);\n\t\tfor (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);\n\
    \t\tfor (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \t}\n\n\t//vector\u3067\u521D\u671F\u5316\n\tLazySegmentTree(const vector<TypeNode>&\
    \ vec) : num(vec.size()) {\n\t\tfor (length = 1,height = 0; length <= vec.size();\
    \ length *= 2, height++);\n\t\tnode.resize(2 * length, Operator::unit_node);\n\
    \t\tlazy.resize(2 * length, Operator::unit_lazy);\n\t\tfor (int i = 0; i < vec.size();\
    \ ++i) node[i + length] = vec[i];\n\t\tfor (int i = length - 1; i >= 0; --i) node[i]\
    \ = Operator::func_node(node[(i<<1)+0],node[(i<<1)+1]);\n\t\trange.resize(2 *\
    \ length);\n\t\tfor (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);\n\
    \t\tfor (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \t}\n\n\t//update [a,b)\n\tvoid update(int a, int b, TypeLazy x) {\n\t\tint l\
    \ = a + length, r = b + length - 1;\n\t\tfor (int i = height; 0 < i; --i) propagate(l\
    \ >> i), propagate(r >> i);\n\t\tfor(r++; l < r; l >>=1, r >>=1) {\n\t\t\tif(l&1)\
    \ lazy[l] = Operator::func_lazy(lazy[l],x), propagate(l),l++;\n\t\t\tif(r&1) --r,lazy[r]\
    \ = Operator::func_lazy(lazy[r],x), propagate(r);\n\t\t}\n\t\tl = a + length,\
    \ r = b + length - 1;\n\t\twhile ((l>>=1),(r>>=1),l) {\n            if(lazy[l]\
    \ == Operator::unit_lazy) node[l] = Operator::func_node(Operator::func_merge(node[(l<<1)+0],lazy[(l<<1)+0],range[(l<<1)+0].first,range[(l<<1)+0].second),Operator::func_merge(node[(l<<1)+1],lazy[(l<<1)+1],range[(l<<1)+1].first,range[(l<<1)+1].second));\n\
    \            if(lazy[r] == Operator::unit_lazy) node[r] = Operator::func_node(Operator::func_merge(node[(r<<1)+0],lazy[(r<<1)+0],range[(r<<1)+0].first,range[(r<<1)+0].second),Operator::func_merge(node[(r<<1)+1],lazy[(r<<1)+1],range[(r<<1)+1].first,range[(r<<1)+1].second));\n\
    \  \t\t}\n\t}\n\n\t//get [a,b)\n\tTypeNode get(int a, int b) {\n\t\tint l = a\
    \ + length, r = b + length - 1;\n\t\tfor (int i = height; 0 < i; --i) propagate(l\
    \ >> i), propagate(r >> i);\n\t\tTypeNode vl = Operator::unit_node, vr = Operator::unit_node;\n\
    \t\tfor(r++; l < r; l >>=1, r >>=1) {\n            if(l&1) vl = Operator::func_node(vl,Operator::func_merge(node[l],lazy[l],range[l].first,range[l].second)),l++;\n\
    \            if(r&1) r--,vr = Operator::func_node(Operator::func_merge(node[r],lazy[r],range[r].first,range[r].second),vr);\n\
    \ \t\t}\n\t\treturn Operator::func_node(vl,vr);\n\t}\n\n\t//return [0,length]\n\
    \tint prefix_binary_search(TypeNode var) {\n\t\tint l = length, r = 2*length -\
    \ 1;\n\t\tfor (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);\n\
    \t\tif(!Operator::func_check(node[1],var)) return num;\n\t\tTypeNode ret = Operator::unit_node;\n\
    \t\tsize_t idx = 2;\n\t\tfor(; idx < 2*length; idx<<=1){\n            if(!Operator::func_check(Operator::func_node(ret,Operator::func_merge(node[idx],lazy[idx],range[idx].first,range[idx].second)),var))\
    \ {\n                ret = Operator::func_node(ret,Operator::func_merge(node[idx],lazy[idx],range[idx].first,range[idx].second));\n\
    \                idx++;\n            }\n\t\t}\n\t\treturn min((idx>>1) - length,num);\n\
    \t}\n\n\t//range[l,r) return [l,r]\n\tint binary_search(size_t l, size_t r, TypeNode\
    \ var) {\n\t\tif (l < 0 || length <= l || r < 0 || length < r) return -1;\n\t\t\
    for (int i = height; 0 < i; --i) propagate((l+length) >> i), propagate((r+length-1)\
    \ >> i);\n\t\tTypeNode ret = Operator::unit_node;\n\t\tsize_t off = l;\n\t\tfor(size_t\
    \ idx = l+length; idx < 2*length && off < r; ){\n            if(range[idx].second<=r\
    \ && !Operator::func_check(Operator::func_node(ret,Operator::func_merge(node[idx],lazy[idx],range[idx].first,range[idx].second)),var))\
    \ {\n                ret = Operator::func_node(ret,Operator::func_merge(node[idx],lazy[idx],range[idx].first,range[idx].second));\n\
    \                off = range[idx++].second;\n                if(!(idx&1)) idx\
    \ >>= 1;\t\t\t\n            }\n            else{\n\t\t\t\tidx <<=1;\n\t\t\t}\n\
    \t\t}\n\t\treturn off;\n\t}\n\n\tvoid print(){\n\t\t// cout << \"node\" << endl;\n\
    \t\t// for(int i = 1,j = 1; i < 2*length; ++i) {\n\t\t// \tcout << node[i] <<\
    \ \" \";\n\t\t// \tif(i==((1<<j)-1) && ++j) cout << endl;\n\t\t// }\n\t\t// cout\
    \ << \"lazy\" << endl;\n\t\t// for(int i = 1,j = 1; i < 2*length; ++i) {\n\t\t\
    // \tcout << lazy[i] << \" \";\n\t\t// \tif(i==((1<<j)-1) && ++j) cout << endl;\n\
    \t\t// }\n\t\tcout << \"vector\" << endl;\n\t\tcout << \"{ \" << get(0,1);\n\t\
    \tfor(int i = 1; i < length; ++i) cout << \", \" << get(i,i+1);\n\t\tcout << \"\
    \ }\" << endl;\n\t}\n};\n\n//node:\u6700\u5C0F\u3000lazy:\u52A0\u7B97\ntemplate<class\
    \ T, class U> struct NodeMinRangeAdd {\n\tusing TypeNode = T;\n\tusing TypeLazy\
    \ = U;\n\tinline static constexpr TypeNode unit_node = 1234567890;\n\tinline static\
    \ constexpr TypeLazy unit_lazy = 0;\n\tinline static constexpr TypeNode func_node(TypeNode\
    \ l,TypeNode r){return min(l,r);}\n\tinline static constexpr TypeLazy func_lazy(TypeLazy\
    \ old_lazy,TypeLazy new_lazy){return old_lazy+new_lazy;}\n\tinline static constexpr\
    \ TypeNode func_merge(TypeNode node,TypeLazy lazy,int l, int r){return node+lazy;}\n\
    \t// LazySegmentTree<NodeMinRangeAdd<ll,ll>> Seg(N,0);\n};\n\n//node:\u7DCF\u548C\
    \u3000lazy:\u66F4\u65B0\ntemplate<class T, class U> struct NodeSumRangeUpdate\
    \ {\n\tusing TypeNode = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode\
    \ unit_node = 0;\n\tinline static constexpr TypeLazy unit_lazy = -2000;\n\tinline\
    \ static constexpr TypeNode func_node(TypeNode l,TypeNode r){return l+r;}\n\t\
    inline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return\
    \ new_lazy;}\n\tinline static constexpr TypeNode func_merge(TypeNode node,TypeLazy\
    \ lazy,int l, int r){return lazy!=-2000?lazy*(r-l):node;}\n\tinline static constexpr\
    \ bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}\n\t//\
    \ LazySegmentTree<NodeSumRangeUpdate<ll,ll>> Seg(N,0);\n};\n\n//node:\u7DCF\u548C\
    \u3000lazy:\u52A0\u7B97\ntemplate<class T, class U> struct NodeSumRangeAdd {\n\
    \tusing TypeNode = T;\n\tusing TypeLazy = U;\n\tinline static constexpr TypeNode\
    \ unit_node = 0;\n\tinline static constexpr TypeLazy unit_lazy = 0;\n\tinline\
    \ static constexpr TypeNode func_node(TypeNode l,TypeNode r){return l+r;}\n\t\
    inline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return\
    \ old_lazy+new_lazy;}\n\tinline static constexpr TypeNode func_merge(TypeNode\
    \ node,TypeLazy lazy,int l, int r){return node+lazy*(r-l);}\n\tinline static constexpr\
    \ bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}\n\t//\
    \ LazySegmentTree<NodeSumRangeUpdate<ll,ll>> Seg(N,0);\n};\n\n//node:\u6700\u5C0F\
    \u3000lazy:\u7B49\u5DEE\u6570\u5217\u66F4\u65B0\ntemplate<class T, class U> struct\
    \ NodeMinRangeArithmeticUpdate {\n    using TypeNode = T;\n    using TypeLazy\
    \ = U;\n    inline static constexpr TypeNode unit_node = 1234567;\n    inline\
    \ static constexpr TypeLazy unit_lazy = {-2000,-2000};\n    inline static constexpr\
    \ TypeNode func_node(TypeNode l,TypeNode r){return min(l,r);}\n    inline static\
    \ constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return new_lazy;}\n\
    \    inline static constexpr TypeNode func_merge(TypeNode node,TypeLazy lazy,int\
    \ l,int r){ return (lazy.first==-2000?node:lazy.first + (l-lazy.second));}\n \
    \   inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return\
    \ var <= nodeVal;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/segment/LazySegmentTree.cpp
  requiredBy: []
  timestamp: '2020-09-27 22:47:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segment/LazySegmentTree-rsqruq.test.cpp
  - test/segment/LazySegmentTree-rmqraq.test.cpp
  - test/graph/Tree-rerooting.test.cpp
  - test/graph/Tree-eulertour.test.cpp
  - test/graph/Tree-hld-vertex.test.cpp
documentation_of: lib/segment/LazySegmentTree.cpp
layout: document
redirect_from:
- /library/lib/segment/LazySegmentTree.cpp
- /library/lib/segment/LazySegmentTree.cpp.html
title: "LazySegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u9045\u5EF6\u8A55\u4FA1\
  \u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
