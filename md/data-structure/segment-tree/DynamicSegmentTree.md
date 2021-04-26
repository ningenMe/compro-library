### DynamicSegmentTree
- 非再帰抽象化動的セグメント木
- ポインタベースで、必要な部分だけ作成するセグメント木
  - 普通のセグ木と違って、区間の幅を1e9で持ったり出来る
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
};
```
- モノイドのクラスは、get,updateに対する演算と単位元を必要とする。

### コンストラクタ
- DynamicSegmentTree()
  - 単位元`unit_node`で初期化

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
- void print()
  - デバッグ用