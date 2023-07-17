### StaticRangeInversionQuery
- 区間転倒数
  - 半開区間[l,r)に対する転倒数を求める。
  - クエリはオンラインでも可。
  - 列の更新は出来ない。

### コンストラクタ
- RangeInversionQuery(const vector<T>& ar, T pre=-1)
  - 列と、列に含まれない最小値preを渡す必要がある。
  - これは座圧を内部的に行うため、最小を定義する必要がある。
  - ソートできる列であれば何でも渡せる
  - $O(N\sqrt(N))$

### メソッド
- long long get(int l, int r)
  - 半開区間[l,r)に対する転倒数を返す
  - $O(\sqrt(N))$

### 参考資料
- なし
- 軽い理論は下記
- 前計算パート
  - 座圧
  - バケット内で、prefix,suffixの転倒数を求める(これはBITでリセットしながらやるだけ)
  - 各数のfreqを、バケットごとに区切って求めて累積和をとっておく(ここややこしい)
    - 感覚的には、O(N)のfreqのメモがsqrt(N)個ある感じ。
    - これを小さい数から累積和取っておく(ある数以下の分布の総和をO(1)で求めたいため)
  - 平方分割して、各バケット連続区間の転倒数を求める
    - 区間数O(sqrt(N)* sqrt(N)) = O(N)のやつ
    - うまくやると、1区間 O(sqrt(N)) で求まるので、全体でO(N \sqrt(N))
    - 転倒数のマージを思い出して、区間dpチックにやろう。
- クエリパート
  - 中側のバケット部分は雑に取得
  - 左右のバケットからはみ出た部分を、処理する。
  - 左側から、中側のバケット部分への寄与はO(\sqrt(N))
  - 右側から、中側のバケット部分への寄与もO(\sqrt(N))
  - 左側から右側、ここが難しいけどちゃんと考えるとO(\sqrt(N))
  - バケット内で値でソートしたindexの列を前計算しておく
    - 左右の列両方見ながら、値が小さいやつを処理していって、indexで区間[l,r)に入ってるか確認すると転倒数寄与が出せる。
- [l,r)の転倒数 = [l,c)の転倒数 + [c,r)の転倒数 + [l,c)の[c,r)に対する寄与
  - 基本的にはこれだけ。