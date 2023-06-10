### WaveletMatrix
- 静的な列に対して、区間クエリを高速に処理するデータ構造

### コンストラクタ
- WaveletMatrix(const vector<T> &ar)
  - vectorを渡す。中で座圧するからlong longでもok

### メソッド
- T get(const u32 l)
  - [l,l+1) 番目の要素を返す。元の配列を保持してるなら使わないメソッド

    //[l,r) range k (0-indexed) th smallest number
- T range_kth_smallest(const u32 l, const u32 r, const u32 k) 
  - [l,r) の範囲の中で、k (0-indexed) 番目に小さい値を返す
- T range_kth_largest(const u32 l, const u32 r, const u32 k)
  - [l,r) の範囲の中で、k (0-indexed) 番目に大きい値を返す
- u32 range_freq_upper(const u32 l, const u32 r, const T upper) 
  - [l,r) の範囲の中で、upperより小さい要素の数を返す
- u32 range_freq_lower_upper(const u32 l, const u32 r, const T lower, const T upper) 
  - [l,r) の範囲の中で、lower以上、upperより小さい要素の数を返す [lower, upper)
- u32 range_freq(const u32 l, const u32 r, const T val) 
  - [l,r) の範囲の中で、valに等しい要素の数を返す