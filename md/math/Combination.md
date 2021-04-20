### Combination
- 二項係数を返す

### コンストラクタ
- Combination(int N)
  - binom(N,K)を愚直に前計算する 

### メソッド
- T binom(int n, int k)
  - 二項係数nCkを返す
  - $O(1)$

- T lucas(int n, int k, long long p)
  - ルーカスの定理によって、nCk mod pを返す。
  - コンストラクタで渡したNに対して、p <= Nである必要がある
  - n,kの値はなんでもよい。(p < n, p < kでもok）
  - $O(\log(n))$
### 参考資料
- [C - ゲーマーじゃんけん](https://atcoder.jp/contests/dwango2015-prelims/tasks/dwango2015_prelims_3)
- [B - 123 Triangle](https://atcoder.jp/contests/agc043/tasks/agc043_b)
- [C - Tricolor Pyramid](https://atcoder.jp/contests/arc117/tasks/arc117_c)
