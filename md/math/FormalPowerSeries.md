### FormalPowerSeries
- 形式的冪級数
- 具体的には下記の係数$a=(a_0,...a_{n-1})$を保持するクラス
  - $f(x)=a_0 + a_1x^1 + a_2x^2 + ... + a_{n-1}x^{n-1}$

- 以下FormalPowerSeriesの型のことを`Fps`と称す。
- 0-indexed
  - `Fps f(N)`で初期化した場合は`N-1`項までが確保される
- `ModInt`あるいは`RuntimeModInt`をテンプレートで渡す必要がある
- 実装はvectorを継承しているので、`[]`演算子などが使える。
- ntt-friendlyでないmod(1000'000'007など)でも対応。使い方は同じ。
  - 内部でgarnerを使うかどうかを制御している。
- 実行時modにも対応。使い方は同じ。

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
- [【競技プログラミング】形式的冪級数の応用テクニック(前編)](https://qiita.com/hotman78/items/f0e6d2265badd84d429a)
- [形式的冪級数(Formal-Power-Series) / Luzhiled’s memo](https://ei1333.github.io/luzhiled/snippets/math/formal-power-series.html)
- [形式的べき級数解説 / maspyのHP](https://maspypy.com/category/%e5%bd%a2%e5%bc%8f%e7%9a%84%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e8%a7%a3%e8%aa%ac)
- [(形式的)べき級数と数え上げの写像12相との関係性　前編 - Senの競技プログラミング備忘録](https://sen-comp.hatenablog.com/entry/2019/12/07/142131)
- [今年中に理解する！多項式、母関数、形式的べき級数の競プロでの実践的使い方 - はまやんはまやんはまやん](https://www.hamayanhamayan.com/entry/2019/12/07/000441)
- [線形漸化式を満たす数列の N 項目を計算するアルゴリズム](http://q.c.titech.ac.jp/docs/progs/polynomial_division.html)
- [形式的冪級数（FPS）の inv，log，exp，pow の定数倍の軽いアルゴリズム](https://opt-cp.com/fps-fast-algorithms/)
- [多項式を使うテクニックたち](https://yukicoder.me/wiki/polynomial_techniques)
- [非再帰で多項式の多点評価をするよ](https://rsk0315.hatenablog.com/entry/2020/04/05/190941)
- [非再帰で補間多項式を求めるよ](https://rsk0315.hatenablog.com/entry/2020/04/05/203210)