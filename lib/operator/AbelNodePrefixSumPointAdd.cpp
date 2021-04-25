/*
 * @title AbelNodePrefixSumPointAdd
 * @docs md/math/AbelNodePrefixSumPointAdd.md
 */
template<class T> struct AbelNodePrefixSumPointAdd {
    using TypeNode = T;
    inline static constexpr TypeNode unit_node = 0;
    inline static constexpr TypeNode func_fold(const TypeNode& l,const TypeNode& r){return l+r;}
    inline static constexpr TypeNode func_fold_inv(const TypeNode& l,const TypeNode& r){return l-r;}
};