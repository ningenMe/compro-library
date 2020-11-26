---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/Tree-hld-path.test.cpp
    title: test/graph/Tree-hld-path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment/SegmentTree-prefix-binary-search.test.cpp
    title: test/segment/SegmentTree-prefix-binary-search.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment/SegmentTree-rcq.test.cpp
    title: test/segment/SegmentTree-rcq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment/SegmentTree-rmq.test.cpp
    title: test/segment/SegmentTree-rmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment/SegmentTree-rsq.test.cpp
    title: test/segment/SegmentTree-rsq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment/SegmentTree-suffix-binary-search.test.cpp
    title: test/segment/SegmentTree-suffix-binary-search.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: md/segment/SegmentTree.md
    document_title: "SegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u30BB\u30B0\
      \u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 1 \"lib/segment/SegmentTree.cpp\"\n/*\n * @title SegmentTree\
    \ - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n\
    \ * @docs md/segment/SegmentTree.md\n */\ntemplate<class Operator> class SegmentTree\
    \ {\n    using TypeNode = typename Operator::TypeNode; \n    size_t length;\n\
    \    size_t num;\n    vector<TypeNode> node;\n    vector<pair<int,int>> range;\n\
    \    inline void build() {\n        for (int i = length - 1; i >= 0; --i) node[i]\
    \ = Operator::func_node(node[(i<<1)+0],node[(i<<1)+1]);\n        range.resize(2\
    \ * length);\n        for (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);\n\
    \        for (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n\
    \    }\npublic:\n\n    //unit\u3067\u521D\u671F\u5316\n    SegmentTree(const size_t\
    \ num): num(num) {\n        for (length = 1; length <= num; length *= 2);\n  \
    \      node.resize(2 * length, Operator::unit_node);\n        build();\n    }\n\
    \n    //vector\u3067\u521D\u671F\u5316\n    SegmentTree(const vector<TypeNode>\
    \ & vec) : num(vec.size()) {\n        for (length = 1; length <= vec.size(); length\
    \ *= 2);\n        node.resize(2 * length, Operator::unit_node);\n        for (int\
    \ i = 0; i < vec.size(); ++i) node[i + length] = vec[i];\n        build();\n \
    \   }\n \n    //\u540C\u3058init\u3067\u521D\u671F\u5316\n    SegmentTree(const\
    \ size_t num, const TypeNode init) : num(num) {\n        for (length = 1; length\
    \ <= num; length *= 2);\n        node.resize(2 * length, Operator::unit_node);\n\
    \        for (int i = 0; i < length; ++i) node[i+length] = init;\n        build();\n\
    \    }\n    \n    //[idx,idx+1)\n    void update(size_t idx, const TypeNode var)\
    \ {\n        if(idx < 0 || length <= idx) return;\n        idx += length;\n  \
    \      node[idx] = Operator::func_merge(node[idx],var);\n        while(idx >>=\
    \ 1) node[idx] = Operator::func_node(node[(idx<<1)+0],node[(idx<<1)+1]);\n   \
    \ }\n\n    //[l,r)\n    TypeNode get(int l, int r) {\n        if (l < 0 || length\
    \ <= l || r < 0 || length < r) return Operator::unit_node;\n        TypeNode vl\
    \ = Operator::unit_node, vr = Operator::unit_node;\n        for(l += length, r\
    \ += length; l < r; l >>=1, r >>=1) {\n            if(l&1) vl = Operator::func_node(vl,node[l++]);\n\
    \            if(r&1) vr = Operator::func_node(node[--r],vr);\n        }\n    \
    \    return Operator::func_node(vl,vr);\n    }\n\n    //range[l,r) return [l,r]\
    \ search max right\n    int prefix_binary_search(int l, int r, TypeNode var) {\n\
    \        assert(0 <= l && l < length && 0 < r && r <= length);\n        TypeNode\
    \ ret = Operator::unit_node;\n        size_t off = l;\n        for(size_t idx\
    \ = l+length; idx < 2*length && off < r; ){\n            if(range[idx].second<=r\
    \ && !Operator::func_check(Operator::func_node(ret,node[idx]),var)) {\n      \
    \          ret = Operator::func_node(ret,node[idx]);\n                off = range[idx++].second;\n\
    \                if(!(idx&1)) idx >>= 1;\t\t\t\n            }\n            else{\n\
    \                idx <<=1;\n            }\n        }\n        return off;\n  \
    \  }\n\n    //range(l,r] return [l,r] search max left\n    int suffix_binary_search(const\
    \ int l, const int r, const TypeNode var) {\n        assert(-1 <= l && l < (int)length-1\
    \ && 0 <= r && r < length);\n        TypeNode ret = Operator::unit_node;\n   \
    \     int off = r;\n        for(size_t idx = r+length; idx < 2*length && l < off;\
    \ ){\n            if(l < range[idx].first && !Operator::func_check(Operator::func_node(node[idx],ret),var))\
    \ {\n                ret = Operator::func_node(node[idx],ret);\n             \
    \   off = range[idx--].first-1;\n                if(idx&1) idx >>= 1;\n      \
    \      }\n            else{\n                idx = (idx<<1)+1;\n            }\n\
    \        }\n        return off;\n    }\n\n    void print(){\n        // cout <<\
    \ \"node\" << endl;\n        // for(int i = 1,j = 1; i < 2*length; ++i) {\n  \
    \      // \tcout << node[i] << \" \";\n        // \tif(i==((1<<j)-1) && ++j) cout\
    \ << endl;\n        // }\n        cout << \"vector\" << endl;\n        cout <<\
    \ \"{ \" << get(0,1);\n        for(int i = 1; i < length; ++i) cout << \", \"\
    \ << get(i,i+1);\n        cout << \" }\" << endl;\n    }\n};\n\n//\u4E00\u70B9\
    \u66F4\u65B0 \u533A\u9593\u6700\u5C0F\ntemplate<class T> struct NodeMinPointUpdate\
    \ {\n    using TypeNode = T;\n    inline static constexpr TypeNode unit_node =\
    \ (1LL<<31)-1;\n    inline static constexpr TypeNode func_node(TypeNode l,TypeNode\
    \ r){return min(l,r);}\n    inline static constexpr TypeNode func_merge(TypeNode\
    \ l,TypeNode r){return r;}\n    inline static constexpr bool func_check(TypeNode\
    \ nodeVal,TypeNode var){return var > nodeVal;}\n};\n\n//\u4E00\u70B9\u52A0\u7B97\
    \ \u533A\u9593\u7DCF\u548C\ntemplate<class T> struct NodeSumPointAdd {\n    using\
    \ TypeNode = T;\n    inline static constexpr TypeNode unit_node = 0;\n    inline\
    \ static constexpr TypeNode func_node(TypeNode l,TypeNode r){return l+r;}\n  \
    \  inline static constexpr TypeNode func_merge(TypeNode l,TypeNode r){return l+r;}\n\
    \    inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return\
    \ var == nodeVal;}\n};\n\n//\u4E00\u6B21\u95A2\u6570\ntemplate<class T> struct\
    \ NodeCompositePointUpdate {\n    using TypeNode = T;\n    inline static constexpr\
    \ TypeNode unit_node = make_pair(1,0);\n    inline static constexpr TypeNode func_node(TypeNode\
    \ l,TypeNode r){return {r.first*l.first,r.first*l.second+r.second};}\n    inline\
    \ static constexpr TypeNode func_merge(TypeNode l,TypeNode r){return r;}\n   \
    \ inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return\
    \ var == nodeVal;}\n};\n"
  code: "/*\n * @title SegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\n * @docs md/segment/SegmentTree.md\n */\ntemplate<class\
    \ Operator> class SegmentTree {\n    using TypeNode = typename Operator::TypeNode;\
    \ \n    size_t length;\n    size_t num;\n    vector<TypeNode> node;\n    vector<pair<int,int>>\
    \ range;\n    inline void build() {\n        for (int i = length - 1; i >= 0;\
    \ --i) node[i] = Operator::func_node(node[(i<<1)+0],node[(i<<1)+1]);\n       \
    \ range.resize(2 * length);\n        for (int i = 0; i < length; ++i) range[i+length]\
    \ = make_pair(i,i+1);\n        for (int i = length - 1; i >= 0; --i) range[i]\
    \ = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);\n    }\npublic:\n\
    \n    //unit\u3067\u521D\u671F\u5316\n    SegmentTree(const size_t num): num(num)\
    \ {\n        for (length = 1; length <= num; length *= 2);\n        node.resize(2\
    \ * length, Operator::unit_node);\n        build();\n    }\n\n    //vector\u3067\
    \u521D\u671F\u5316\n    SegmentTree(const vector<TypeNode> & vec) : num(vec.size())\
    \ {\n        for (length = 1; length <= vec.size(); length *= 2);\n        node.resize(2\
    \ * length, Operator::unit_node);\n        for (int i = 0; i < vec.size(); ++i)\
    \ node[i + length] = vec[i];\n        build();\n    }\n \n    //\u540C\u3058init\u3067\
    \u521D\u671F\u5316\n    SegmentTree(const size_t num, const TypeNode init) : num(num)\
    \ {\n        for (length = 1; length <= num; length *= 2);\n        node.resize(2\
    \ * length, Operator::unit_node);\n        for (int i = 0; i < length; ++i) node[i+length]\
    \ = init;\n        build();\n    }\n    \n    //[idx,idx+1)\n    void update(size_t\
    \ idx, const TypeNode var) {\n        if(idx < 0 || length <= idx) return;\n \
    \       idx += length;\n        node[idx] = Operator::func_merge(node[idx],var);\n\
    \        while(idx >>= 1) node[idx] = Operator::func_node(node[(idx<<1)+0],node[(idx<<1)+1]);\n\
    \    }\n\n    //[l,r)\n    TypeNode get(int l, int r) {\n        if (l < 0 ||\
    \ length <= l || r < 0 || length < r) return Operator::unit_node;\n        TypeNode\
    \ vl = Operator::unit_node, vr = Operator::unit_node;\n        for(l += length,\
    \ r += length; l < r; l >>=1, r >>=1) {\n            if(l&1) vl = Operator::func_node(vl,node[l++]);\n\
    \            if(r&1) vr = Operator::func_node(node[--r],vr);\n        }\n    \
    \    return Operator::func_node(vl,vr);\n    }\n\n    //range[l,r) return [l,r]\
    \ search max right\n    int prefix_binary_search(int l, int r, TypeNode var) {\n\
    \        assert(0 <= l && l < length && 0 < r && r <= length);\n        TypeNode\
    \ ret = Operator::unit_node;\n        size_t off = l;\n        for(size_t idx\
    \ = l+length; idx < 2*length && off < r; ){\n            if(range[idx].second<=r\
    \ && !Operator::func_check(Operator::func_node(ret,node[idx]),var)) {\n      \
    \          ret = Operator::func_node(ret,node[idx]);\n                off = range[idx++].second;\n\
    \                if(!(idx&1)) idx >>= 1;\t\t\t\n            }\n            else{\n\
    \                idx <<=1;\n            }\n        }\n        return off;\n  \
    \  }\n\n    //range(l,r] return [l,r] search max left\n    int suffix_binary_search(const\
    \ int l, const int r, const TypeNode var) {\n        assert(-1 <= l && l < (int)length-1\
    \ && 0 <= r && r < length);\n        TypeNode ret = Operator::unit_node;\n   \
    \     int off = r;\n        for(size_t idx = r+length; idx < 2*length && l < off;\
    \ ){\n            if(l < range[idx].first && !Operator::func_check(Operator::func_node(node[idx],ret),var))\
    \ {\n                ret = Operator::func_node(node[idx],ret);\n             \
    \   off = range[idx--].first-1;\n                if(idx&1) idx >>= 1;\n      \
    \      }\n            else{\n                idx = (idx<<1)+1;\n            }\n\
    \        }\n        return off;\n    }\n\n    void print(){\n        // cout <<\
    \ \"node\" << endl;\n        // for(int i = 1,j = 1; i < 2*length; ++i) {\n  \
    \      // \tcout << node[i] << \" \";\n        // \tif(i==((1<<j)-1) && ++j) cout\
    \ << endl;\n        // }\n        cout << \"vector\" << endl;\n        cout <<\
    \ \"{ \" << get(0,1);\n        for(int i = 1; i < length; ++i) cout << \", \"\
    \ << get(i,i+1);\n        cout << \" }\" << endl;\n    }\n};\n\n//\u4E00\u70B9\
    \u66F4\u65B0 \u533A\u9593\u6700\u5C0F\ntemplate<class T> struct NodeMinPointUpdate\
    \ {\n    using TypeNode = T;\n    inline static constexpr TypeNode unit_node =\
    \ (1LL<<31)-1;\n    inline static constexpr TypeNode func_node(TypeNode l,TypeNode\
    \ r){return min(l,r);}\n    inline static constexpr TypeNode func_merge(TypeNode\
    \ l,TypeNode r){return r;}\n    inline static constexpr bool func_check(TypeNode\
    \ nodeVal,TypeNode var){return var > nodeVal;}\n};\n\n//\u4E00\u70B9\u52A0\u7B97\
    \ \u533A\u9593\u7DCF\u548C\ntemplate<class T> struct NodeSumPointAdd {\n    using\
    \ TypeNode = T;\n    inline static constexpr TypeNode unit_node = 0;\n    inline\
    \ static constexpr TypeNode func_node(TypeNode l,TypeNode r){return l+r;}\n  \
    \  inline static constexpr TypeNode func_merge(TypeNode l,TypeNode r){return l+r;}\n\
    \    inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return\
    \ var == nodeVal;}\n};\n\n//\u4E00\u6B21\u95A2\u6570\ntemplate<class T> struct\
    \ NodeCompositePointUpdate {\n    using TypeNode = T;\n    inline static constexpr\
    \ TypeNode unit_node = make_pair(1,0);\n    inline static constexpr TypeNode func_node(TypeNode\
    \ l,TypeNode r){return {r.first*l.first,r.first*l.second+r.second};}\n    inline\
    \ static constexpr TypeNode func_merge(TypeNode l,TypeNode r){return r;}\n   \
    \ inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return\
    \ var == nodeVal;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/segment/SegmentTree.cpp
  requiredBy: []
  timestamp: '2020-10-25 02:58:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/Tree-hld-path.test.cpp
  - test/segment/SegmentTree-prefix-binary-search.test.cpp
  - test/segment/SegmentTree-rsq.test.cpp
  - test/segment/SegmentTree-suffix-binary-search.test.cpp
  - test/segment/SegmentTree-rcq.test.cpp
  - test/segment/SegmentTree-rmq.test.cpp
documentation_of: lib/segment/SegmentTree.cpp
layout: document
redirect_from:
- /library/lib/segment/SegmentTree.cpp
- /library/lib/segment/SegmentTree.cpp.html
title: "SegmentTree - \u975E\u518D\u5E30\u62BD\u8C61\u5316\u30BB\u30B0\u30E1\u30F3\
  \u30C8\u6728"
---
### SegmentTree
- 非再帰抽象化セグメント木
- 0-indexed
- モノイドのクラスをテンプレートで渡す必要がある
  - 下記が一例
```
//一点加算 区間総和
template<class T> struct NodeSumPointAdd {
	using TypeNode = T;
	inline static constexpr TypeNode unit_node = 0;
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return l+r;}
	inline static constexpr TypeNode func_merge(TypeNode l,TypeNode r){return l+r;}
	inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var == nodeVal;}
};
```
- モノイドのクラスは、get,updateに対する演算と単位元を必要とする。
- 二分探索は任意始点で左右両向きにできる
- 二分探索では`func_check`が初めてtrueになるようなindexを返す  

### コンストラクタ
- SegmentTree(const size_t num)
  - 単位元`unit_node`で初期化
  - $O(N)$
  - num:要素数
- SegmentTree(const vector<TypeNode> & vec)
  - vectorで初期化
  - $O(N)$
  - vec:初期化用vector
- SegmentTree(const size_t num, const TypeNode init)
  - `init`で初期化
  - $O(N)$
  - init:初期化用の値

### メソッド
- void update(size_t idx, const TypeNode var)
  - `idx`番目のデータに値`var`を与える
  - $O(logN)$
  - idx:添字 0-indexed
  - var:値
  - 更新や加算などが乗る
- TypeNode get(int l, int r)
  - 半開区間`[l,r)`をfoldした値を返す
  - $O(logN)$
  - l,r:添字 0-indexed
  - 総和や最大などが乗る
- int prefix_binary_search(int l, int r, TypeNode var)
  - 半開区間`[l,r)`のうち、lを始点とした二分探索
  - $O(logN)$
  - l,r:添字 0-indexed
  - 初めて`func_check(node[idx],var)`がtrueになるようなidxを返す。
  - `func_check(node[l],var)`はfalseである必要がある
- int suffix_binary_search(const int l, const int r, const TypeNode var)
  - 半開区間`(l,r]`のうち、rを始点とした二分探索
  - $O(logN)$
  - l,r:添字 0-indexed
  - 初めて`func_check(node[idx],var)`がtrueになるようなidxを返す。
  - `func_check(var,node[r])`はfalseである必要がある
- void print()
  - デバッグ用