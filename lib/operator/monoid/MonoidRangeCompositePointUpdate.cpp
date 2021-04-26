
//一次関数
template<class T> struct MonoidRangeCompositePointUpdate {
    using TypeNode = T;
    inline static constexpr TypeNode unit_node = make_pair(1,0);
    inline static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return {r.first*l.first,r.first*l.second+r.second};}
    inline static constexpr TypeNode func_operate(TypeNode l,TypeNode r){return r;}
    inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var == nodeVal;}
};