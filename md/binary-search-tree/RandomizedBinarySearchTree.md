### RandomizedBinarySearchTree
- setベースの、ランダム平衡二分探索木
  - 0-indexed

### コンストラクタ
- RandomizedBinarySearchTree()
  - 引数なし

### メソッド
- size()
  - 列のサイズを返す
  - $O(1)$
- empty(void) 
  - 列が空かどうかを返す
  - $O(1)$
- merge(Node *left, Node *right) 
  - 2個のノードをマージする
  - $O(\log N)$
- split(int k)
  - ノードを[0,k),[k,N)の2個にsplitする
  - $O(\log N)$
- insert(const TypeNode value) 
  - valueを挿入する
  - $O(\log N)$
- erase(const TypeNode value)
  - valueを1つ削除する
  - 要素が存在しないときは何もしない
  - $O(\log N)$
- get(size_t k) 
  - k番目の値を返す(重複ありでk番目に小さいもの)
  - $O(\log N)$
- fold(int l, int r) 
  - 半開区間[l,r)をfoldした値を返す
  - $O(\log N)$
- lower_bound(TypeNode value)
  - value以上の値を持つindexを返す
  - $O(\log N)$
- upper_bound(TypeNode value)
  - valueより大きいの値を持つindexを返す
  - $O(\log N)$
- count(TypeNode value)
  - valueの要素数を返す
  - $O(\log N)$
- print() 
  - デバッグ用

### 参考資料
- [平衡二分木を使う問題](https://yosupo.hatenablog.com/entry/2014/12/09/222401)
- [C - データ構造](https://atcoder.jp/contests/arc033/tasks/arc033_3)
  - [提出](https://atcoder.jp/contests/arc033/submissions/22264114)
