### Polynomial
- 多項式のライブラリ
  - 現状、多項式補間しかない
  - Fpsは別ライブラリなので、そっちを参照

### コンストラクタ
- なし

### メソッド
- vector<T> interpolation(const vector<T>& x,const vector<T>& y)
  - 多項式補間。
  - $O(N^2)$
- T interpolation_arithmetic(const T a0,const T d, const vector<T>& y,const T x)
  - 等差数列での多項式補間
  - f(x_i)=y_iとなるx_iが等差数列のときの多項式補間。より速いオーダーで解ける
  - $O(N /log mod)$
### 参考資料
- [ラグランジュ補間](https://ferin-tech.hatenablog.com/entry/2019/08/11/%E3%83%A9%E3%82%B0%E3%83%A9%E3%83%B3%E3%82%B8%E3%83%A5%E8%A3%9C%E9%96%93)
- [見たことのない多項式](https://atcoder.jp/contests/arc033/tasks/arc033_4)
- [Interpolation](https://snuke.hatenablog.com/entry/2014/08/14/031418)