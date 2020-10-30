### Zarts
- 座標圧縮

### コンストラクタ
- Zarts(const vector<T> & ar, int light_flag = 0, T pre=-1)
- arには座圧したいvectorを渡す。
- light_flag=1のとき、mapを使わずに定数倍の速い座圧を行う。このときkey,valを逆変換するmapは生成されない。
- light_flag=1のときは比較ベースで座圧する。preの値はarに含まれない最小の値を渡す必要がある。(任意のar[i]に関して pre < a[i] が成り立つ必要がある)
- 計算量 $O(N\logN)$

### メソッド
- 座圧した配列に関しては、compressedはpublicメンバなので、直接アクセスして使用する
- T get_value(int key)
  - key番目に大きい値を返す 
  - $O(1)$
- int get_key(T value)
  - valueが座圧後何番目に大きいかのkeyを返す
  - $O(\logN)$
- size_t size()
  - 座圧後の値の種類数を返す
  - $O(1)$
