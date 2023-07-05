### SortableSegmentTree
- ソート可能抽象化セグメント木
- 0-indexed
- keyはunsigned long long のみ。bit長を先に決める必要がある。

### コンストラクタ
- SegmentTree(const size_t num)
  - 単位元`unit_node`で初期化
- SegmentTree(const vector<TypeSortKey>& keys, const vector<TypeNode>& vals)
  - vectorで初期化
- SegmentTree(const size_t num, const TypeNode init)
  - `init`で初期化

### メソッド
- void operate(size_t idx, const TypeSortKey key, const TypeNode val)
  - `idx`番目のデータに値 (key, val) を作用させる
- TypeNode fold(int l, int r)
  - 半開区間`[l,r)`をfoldした値を返す
- TypeNode get(int idx)
  - 半開区間`[idx,idx+1)`の値を返す
- void sort_asc(int l, int r)
  - 半開区間`[l,r)`の値を `key` で昇順ソートする
- void sort_desc(int l, int r)
  - 半開区間`[l,r)`の値を `key` で降順ソートする
