### RangeModeQuery
- 区間最瀕値
  - 半開区間[l,r)に対する最瀕値となる頻度(freq)とその値(mode)が求まる。
  - クエリはオンラインでも可能。
  - 列の更新は出来ない。

### コンストラクタ
- RangeModeQuery(const vector<T>& ar, T pre=-1)
  - 列と、列に含まれない最小値preを渡す必要がある。
  - これは座圧を内部的に行うため、最小を定義する必要がある。
  - ソートできる列であれば何でも渡せる
  - $O(N\sqrt(N))$

### メソッド
- pair<size_t,T> get(int l, int r)
  - 半開区間[l,r)に対する最瀕値となる頻度(freq)とその値(mode)を返す

### 参考資料
- [Range Mode Query](https://scrapbox.io/data-structures/Range_Mode_Query)
- [Range Mode Query 空間 Θ(n) 構築 Θ(n√n) クエリ Θ(√n)](https://noshi91.hatenablog.com/entry/2020/10/26/140105)
- [range_mode_query.cpp](https://github.com/noshi91/Library/blob/master/data_structure/range_mode_query.cpp)
- [D. Cut and Stick](https://codeforces.com/contest/1514/problem/D)