### SlideMost
- スライド最小値/最大値
- 0-indexed
- 最大値か最小値のクラスをテンプレートで渡す必要がある
  - 下記が一例
```
template<class T> struct ValueMin {
    using TypeValue = T;
    inline static constexpr bool func_compare(TypeValue l,TypeValue r){return l>=r;}
};
```

### コンストラクタ
- SlideMost(void)

### メソッド
- vector<TypeValue> window(vector<TypeValue>& vec, const int& width)
  - vecをスライドした最小値/最大値を返す
  - $O(N)$
  - width 区間幅
  - [l,r]のスライドした値が`r`にセットされて返ってくる
