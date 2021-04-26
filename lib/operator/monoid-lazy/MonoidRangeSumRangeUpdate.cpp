//node:総和　lazy:更新
template<class T, class U> struct MonoidRangeSumRangeUpdate {
	using TypeNode = T;
	using TypeLazy = U;
	inline static constexpr TypeNode unit_node = 0;
	inline static constexpr TypeLazy unit_lazy = -2000;
	inline static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return l+r;}
	inline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return new_lazy;}
	inline static constexpr TypeNode func_operate(TypeNode node,TypeLazy lazy,int l, int r){return lazy!=-2000?lazy*(r-l):node;}
	inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}
};