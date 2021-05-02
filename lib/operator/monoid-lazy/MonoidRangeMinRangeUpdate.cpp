/*
 * @title MonoidRangeMinRangeUpdate - [区間min, 区間更新]
 * @docs md/operator/monoid-lazy/MonoidRangeMinRangeUpdate.md
 */
template<class T, class U> struct MonoidRangeMinRangeUpdate {
	using TypeNode = T;
	using TypeLazy = U;
	inline static constexpr TypeNode unit_node = 123456789;
	inline static constexpr TypeLazy unit_lazy = 123456789;
	inline static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return min(l,r);}
	inline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return new_lazy;}
	inline static constexpr TypeNode func_operate(TypeNode node,TypeLazy lazy,int l, int r){return lazy;}
	inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}
};
