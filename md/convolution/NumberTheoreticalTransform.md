### NumberTheoreticalTransform
- 多項式の畳込みを行う

### コンストラクタ
- なし

### メソッド
- vector<ModInt<998244353>> convolution(const vector<ModInt<998244353>>& g,const vector<ModInt<998244353>>& h)
  - mod 998244353で良いときに畳み込みを返すメソッド。定数倍はふつう。
- vector<ModInt<1000000007>> convolution(const vector<ModInt<1000000007>>& g,const vector<ModInt<1000000007>>& h)
  - mod 1000000007で良いときに畳み込みを返すメソッド。内部的にはnttとgarnarを行っていて、3回畳み込んでいるため定数倍は重め。

### 参考資料
- [高速フーリエ変換](https://atcoder.jp/contests/atc001/tasks/fft_c)
- [Convolution](https://atcoder.github.io/ac-library/production/document_ja/convolution.html)