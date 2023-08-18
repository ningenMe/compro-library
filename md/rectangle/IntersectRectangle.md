### IntersectRectangle
- 長方形の交差のカウント
- 2次元平面上の $N$ 個の長方形が、各長方形について他の長方形といくつ交差しているか(共有面積があるか)をカウントする

### コンストラクタ
- IntersectRectangle(vector<T>& vl, vector<T>& vr, vector<T>& vd, vector<T>& vu)
  - $[l,r)$ x $[d,u)$ の区間の長方形 $N$ 個を 4つのvectorで渡す
  - $O(N \log N)$ (定数倍重め)
  - 内部的には、ある長方形目線で、上下左右の8方向に平面を分割し、共有領域を持たないものを包除原理で数える。{左|右|上|下} - {左上|左下|右上|右下}
  - {左上|左下|右上|右下} のカウントは、bitを用いて平面走査

### メソッド
- size()
  - 列のサイズを返す
  - $O(1)$
- int get(size_t i)
  - i番目の長方形が、他の長方形といくつ交差しているかのカウントを返却する
  - $O(1)$
  - 値域としては $0 \le count \le N-1 $

### 参考資料
- [提出](https://atcoder.jp/contests/abc312/submissions/44693062)