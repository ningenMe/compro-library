### PotentializedUnionFindTree
- ポテンシャル付きunion find

### コンストラクタ
- PotentializedUnionFindTree(int N = 1, T ini = 0)
  - Nは頂点数 
  - Tはポテンシャルの初期値
  
### メソッド
- inline bool connected(int n, int m)
  - 連結判定
  - そこそこ高速
- bool merge(int n, int m, T d=0)
  - $ potential[m] = potential[n] + d $ となるようにマージする
  - そこそこ高速
  - 既に連結のときは未定義 falseが返る
- T diff(int n, int m)
  - potential[m] - potential[n]を計算
  - 連結ではないときは未定義
- inline int operator[](int n)
  - 頂点nの根を返す
- inline void print()
  - デバッグ用

### 参考資料
- [重み付き Union-Find 木とそれが使える問題のまとめ、および、牛ゲーについて](https://qiita.com/drken/items/cce6fc5c579051e64fab)
- [People on a Line](https://atcoder.jp/contests/abc087/tasks/arc090_b)