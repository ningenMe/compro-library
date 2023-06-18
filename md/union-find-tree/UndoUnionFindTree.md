### UndoUnionFindTree
- Undo付きunion find
- 経路圧縮をせず、mergeの履歴を持つことで、undoができるunion find

### コンストラクタ
- UndoUnionFindTree(int N = 1, T ini = 0)
  - Nは頂点数 
  
### メソッド
- inline bool connected(int n, int m)
  - 連結判定
  - $O(\log N)$
- bool merge(int n, int m)
  - $O(\log N)$
- inline int operator[](int n)
  - 頂点nの根を返す
- inline void print()
  - デバッグ用