### ModInt
- 常にModを取り続ける値オブジェクト
- 実行前に決まる定数modである必要がある
- 入出力はそのまま行えるように定義している

### コンストラクタ
- int,long longなどのプリミティブ型と同様

### メソッド
- int x
  - ModInt<mod> 型であるaに対して、a.xでint型のaの値を取得できる。
- int,long long型との四則演算はModInt型を左辺にしないとエラーになる。
- ModInt型との四則演算はプリミティブ型と同じ。
  - 和,差,積: $O(1)$
  - 商: $O(\log mod)$
- ModInt inv()
  - 逆元を返す
  - $O(\log N)$
- ModInt pow(long long n)
  - n乗した値を返す。