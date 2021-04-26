/*
 * @title AbelPrefixSumPointAdd
 * @docs md/operator/Abel/AbelPrefixSumPointAdd.md
 */
template<class T> struct AbelPrefixSumPointAdd {
    using TypeNode = T;
    inline static constexpr TypeNode unit_node = 0;
    inline static constexpr TypeNode func_fold(const TypeNode& l,const TypeNode& r){return l+r;}
    inline static constexpr TypeNode func_fold_inv(const TypeNode& l,const TypeNode& r){return l-r;}
};