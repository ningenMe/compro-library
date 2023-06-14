### RangeIntegerFrequencyQuerySqrtTree
- 区間の中の値の頻度クエリを答える平方分割木
- unsigned integer専用
- 更新も対応できるはず (verifyできてない)
- 平方分割で、BinaryTrieを載せている sqrt(N)*log(N) の探索時間がかかる
- 値の更新がないならwavelet matrixを使うのが良い。


### メソッド
- RangeIntegerFrequencyQuerySqrtTree(const length) 
  - コンストラクタ。列のサイズを渡す
- void update(const size_t idx, const T var)
  - 値を更新
- int range_freq_upper(const int l, const int r, const T upper) 
  - [l,r) の範囲の中で、upperより小さい要素の数を返す
- int range_freq_lower_upper(const int l, const int r, const T lower, const T upper)
  - [l,r) の範囲の中で、lower以上、upperより小さい要素の数を返す [lower, upper)
- int range_freq(const int l, const int r, const T val)
  - [l,r) の範囲の中で、valに等しい要素の数を返す

- 補足
  - [提出](https://atcoder.jp/contests/abc202/submissions/42263827)
