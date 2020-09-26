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
- TypeNode get(int l, int r)
- int prefix_binary_search(int l, int r, TypeNode var)
- int suffix_binary_search(const int l, const int r, const TypeNode var)
- void print()