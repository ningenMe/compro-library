### RectangleOverlapsWeight
- 重み付き矩形
- staticなクエリのみに対応
- 長方形区間に重み付けをして和を計算できる

### コンストラクタ
- RectangleWeight(int H,int W)
  - H,W グリッドの大きさ
  
### メソッド
- void make_query(int y1,int x1,int y2,int x2,T w=1) 
  - 半開区間矩形[y1,y2)*[x1,x2)に一律重みwを加える。
- void solve() 
  - 実行
- T get(int y,int x) 
  - grid[y][x]の値を返す