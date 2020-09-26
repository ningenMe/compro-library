### FloorSum
- Σi:[0,n) floor((a*i+b)/m)を計算する
### メソッド
- long long FloorSum(long long n, long long m, long long a, long long b)
  - O(log(n+m+a+b))
  - n,m,a,b:はそれぞれ下記に対応
    - $\sum_{i=0}^{n-1} \floor {a*i+b}/m
### 参考資料
- https://min-25.hatenablog.com/entry/2018/04/27/225535
- https://min-25.hatenablog.com/entry/2018/05/03/145505
