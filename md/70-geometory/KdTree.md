### KdTree
- 2次元頂点分類木
- staticなクエリのみに対応
- 2次元座標の特定の領域に含まれる頂点集合を求めることができる
- これは他のライブラリと違って(x,y)で与える

### コンストラクタ
- KdTree(const vector<pair<T,T>>& arg_points)
  - arg_pointsは頂点集合のvector。(x,y)がたくさんある感じ
  - 計算量は$O(N(\logN)^2)
  
### メソッド
- vector<Point> points_in_range(const T& x1,const T& x2,const T& y1,const T& y2) 
  - x区間[x1,x2],y区間[y1,y2]両方に囲まれる領域内の頂点集合を返す x1<=x2 && y1 <= y2 を要請する。
  - Pointは{x,y,idx}の構造体。idxはコンストラクタに渡したときのindex
  - 計算量は頂点集合の個数を$K$としてO(\sqrt(N)+K)
- void print() 
  - デバッグ用