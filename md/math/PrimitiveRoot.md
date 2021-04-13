### PrimitiveRoot
- 原子根を返す

### コンストラクタ
- なし

### メソッド
- inline static long long root(long long p)
  - 素数pの原子根gを返す。
  - g^0,g^1,g^2,......,g^(p-2),の(p-1)個の数がユニークになる。
  - g^0 = g^(p-1) = 1 であることに注意。
  - gの冪乗の列にはg^x = 0になるようなxはないことに注意。

### 参考資料
- [primitive_root](https://qiita.com/R_olldIce/items/ff38ece900dd41d7178e#2-primitive_root)
- [C - Product Modulo](https://atcoder.jp/contests/agc047/submissions/21743413)
