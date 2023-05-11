### ConvexHullTrickSegmentTree
- セグ木にchtをのせたもの
- 内部でrbstを利用してるので、傾き、クエリの単調性がいらない

### コンストラクタ
- ConvexHullTrickSegmentTree(const size_t num)
  - numの長さで確保する

### メソッド
- update(size_t idx, const TypeValue a, const TypeValue b)
  - 区間[idx,idx+1)に直線ax+bを追加
  - $O(\log(N)^2)$
- get(int l, int r, TypeValue x)
  - 区間[l,r)におけるxにおける最大/最小値を取得
  - $O(\log(N)^2)$
- get_line(int l, int r, TypeValue x)
  - 区間[l,r)におけるxにおける最大/最小値をとる直線を取得
  - $O(\log(N)^2)$


### 参考資料
- [Problem B](https://onlinejudge.u-aizu.ac.jp/beta/room.html#ACPC2020Day2/problems/B)
- [I - Ramen](https://atcoder.jp/contests/wupc2019/tasks/wupc2019_i)
