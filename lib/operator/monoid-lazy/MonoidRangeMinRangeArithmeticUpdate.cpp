//node:最小　lazy:等差数列更新
template<class T, class U> struct MonoidRangeMinRangeArithmeticUpdate {
    using TypeNode = T;
    using TypeLazy = U;
    inline static constexpr TypeNode unit_node = 1234567;
    inline static constexpr TypeLazy unit_lazy = {-2000,-2000};
    inline static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return min(l,r);}
    inline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return new_lazy;}
    inline static constexpr TypeNode func_operate(TypeNode node,TypeLazy lazy,int l,int r){ return (lazy.first==-2000?node:lazy.first + (l-lazy.second));}
    inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}
};