//一点更新 区間最小
template<class T> struct MonoidRangeMulPointUpdate {
    using TypeNode = T;
    inline static TypeNode unit_node = TypeNode::E();
    inline static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return l*r;}
    inline static constexpr TypeNode func_operate(TypeNode l,TypeNode r){return r;}
    inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var > nodeVal;}
};