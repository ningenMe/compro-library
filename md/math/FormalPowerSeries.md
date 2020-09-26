### FormalPowerSeries
- 形式的冪級数
- 具体的には下記の係数$a=(a0,...a_{n-1})$を保持するクラス
```
$f(x)=a0 + a_1*x^1 + a_2*x^2 + ... + a_{n-1}*x^{n-1}$
```
- 以下FormalPowerSeriesの型のことを`Fps`と称す。
- 0-indexed
  - `Fps f(N)`で初期化した場合は`N-1`項までが確保される
- `mod`をテンプレートで渡す必要がある
- 実装はvectorを継承しているので、`[]`演算子などが使える。

### コンストラクタ
- 基本的にはvectorに同じ
- FormalPowerSeries(vector< Mint > v)
  - ModInt型のvectorでも初期化できる
  
### メソッド
- int,long long,ModInt型とFpsとの四則演算は各要素に演算が行われる
  - 和,差,積: $O(N)$
  - 商: $O(N+\log mod)$
- Fps型どうしの四則演算は、和,差については各要素同士、積については畳み込みになる
  - 和,差: $O(N)$
  - 積,商: $O(N\log N)$
  - 積はnttによる畳込み
  - 商は形式的ニュートン法
- Fps prefix(size_t n)
  - Fpsのprefix
  - $O(N)$
  - Fpsの`0`項目から`n-1`項目までのコピーが返却される
- Fps pow(long long k,size_t n) 
  - 累乗$ f(x)^k$を返却する
  - $O(N\log N)$
  - nは打ち切りたい項数。指定しなかった場合は今のFps.size()*kの大きさで返却される
- Fps inv(size_t n)
  - 逆元$1/(f(x))$を返却する
  - $O(N\log N)$
  - nは打ち切りたい項数。指定しなかった場合は今のFpsと同じ大きさで返却される
- Fps diff(void) 
  - 微分$\( f'(x) \)$を返却する
  - $O(N)$
- Fps intg(void) 
  - 積分$\( \int f(x)dx \)$を返却する
  - $O(N)$
- Fps log(size_t n)
  - 対数$\log f(x)$を返却する
  - $O(NlogN)$
  - nは打ち切りたい項数。指定しなかった場合は今のFpsと同じ大きさで返却される
- Fps exp(size_t n) 
  - 指数$\exp f(x)$を返却する
  - $O(N\log N)$
  - nは打ち切りたい項数。指定しなかった場合は今のFpsと同じ大きさで返却される
- Mint nth_term(long long n,const Fps& numerator,const Fps& denominator)
  - f(x)のn項目が返却される
  - $O(N\log N \log n)$
  - nは求めたい項数
  - numeratorは分子のFps
  - denominatorは分母のFps

### 参考資料
- https://qiita.com/hotman78/items/f0e6d2265badd84d429a
- https://ei1333.github.io/luzhiled/snippets/math/formal-power-series.html
- https://maspypy.com/category/%e5%bd%a2%e5%bc%8f%e7%9a%84%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e8%a7%a3%e8%aa%ac
- https://sen-comp.hatenablog.com/entry/2019/12/07/142131
- https://www.hamayanhamayan.com/entry/2019/12/07/000441
- http://q.c.titech.ac.jp/docs/progs/polynomial_division.html