### LazyRandomizedBinarySearchTreeSequence
- 列ベースの、遅延伝播平衡二分探索木
  - 0-indexed

### コンストラクタ
- LazyRandomizedBinarySearchTreeSequence()
  - 引数なし

### メソッド
- size()
  - 列のサイズを返す
  - $O(1)$
- empty(void) 
  - 列が空かどうかを返す
  - $O(1)$
- get(size_t k) 
  - k番目の値を返す(単純に前からk番目。k番目に小さいものではない)
  - $O(\log N)$
- insert(const size_t k, const TypeNode value) 
  - k番目の値の手前に、valueを挿入する
    - k=0のときは、一番前に挿入される
    - k=Nのときは、一番後に挿入される
  - $O(\log N)$
- fold(int l, int r) 
  - 半開区間[l,r)をfoldした値を返す
  - $O(\log N)$
- operate(const int l, const int r, const TypeLazy lazy)
  - 半開区間[l,r)にlazyを作用させる
  - $O(\log N)$
- print() 
  - デバッグ用



### 参考資料
- [平衡二分木を使う問題](https://yosupo.hatenablog.com/entry/2014/12/09/222401)
- [B - カッコつけ](https://atcoder.jp/contests/code-festival-2014-exhibition-open/tasks/code_festival_exhibition_b)
  - [提出](https://atcoder.jp/contests/code-festival-2014-exhibition-open/submissions/22250302)
