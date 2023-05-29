/*
 * @title MonoidRangeFoldSumRangeOperateUpdate - fold:区間sum, operate:区間更新
 * @docs md/operator/monoid-lazy/MonoidRangeFoldMinRangeOperateUpdate.md
 */
template<class T, class U> struct MonoidRangeFoldSumRangeOperateUpdate {
	using TypeNode = T;
	using TypeLazy = U;
	inline static constexpr TypeNode unit_node = 0;
	inline static constexpr TypeLazy unit_lazy = -1;
	inline static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return l+r;}
	inline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return new_lazy;}
	inline static constexpr TypeNode func_operate(TypeNode node,TypeLazy lazy,int l, int r){return lazy==unit_lazy?node:lazy*(r-l);}
	inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}
};