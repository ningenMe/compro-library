//一点更新 区間最小
template<class T> struct MonoidRangeMinPointUpdate {
    using TypeNode = T;
    inline static constexpr TypeNode unit_node = (1LL<<31)-1;
    inline static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return min(l,r);}
    inline static constexpr TypeNode func_operate(TypeNode l,TypeNode r){return r;}
    inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var > nodeVal;}
};