### RangeMexQuery
- 区間Mex
  - 半開区間[l,r)に対するmexを求める。
  - クエリはオフライン。オンラインでは出来ない。
  - 列の更新は出来ない。

### コンストラクタ
- なし

### メソッド
- map<pair<int,int>,int> static_range_mex_query(const vector<T>& A, const vector<pair<int,int>>& ranges, T offset = 0)
  - A: 列
  - ranges: クエリの半区間。[l,r)を渡す必要がある
  - offset: mexの最小値。デフォルトは0

### 参考資料
- [E. Complicated Computations](https://codeforces.com/contest/1436/problem/E)
- [のしさんのツイート](https://twitter.com/noshi91/status/1279594849826533377?s=20) 
```
  セグ木を持って a を左から舐めます
管理するのは「seg[i] = 数字 i が最後に現れた index」です
[l, r] の答えは r まで読んだ時に計算します
「seg[i] > l となる最小の i」が mex なので、max のセグ木をセグ木内二分探索すると O(log(N)) です
```
