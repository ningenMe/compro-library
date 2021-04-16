### Polynomial
- Gcd添字畳み込み

### コンストラクタ
- なし

### メソッド
- vector<T> convolution(const vector<T>& a,const vector<T>& b) 
  - N = max(a.size(),b.size())として、$O(N\log\log N)$
  - c_n = Σ {n=gcd(i,j)} a_i*b_i を計算できる
  
### 参考資料
- [ゼータ変換・メビウス変換を理解する](https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5)
- [AtCoder AGC 038 C - LCMs (黄色, 700 点)](https://drken1215.hatenablog.com/entry/2020/11/06/031600)