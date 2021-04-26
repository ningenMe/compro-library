//node:最小　lazy:加算
template<class T, class U> struct MonoidRangeMinRangeAdd {
	using TypeNode = T;
	using TypeLazy = U;
	inline static constexpr TypeNode unit_node = 1234567890;
	inline static constexpr TypeLazy unit_lazy = 0;
	inline static constexpr TypeNode fucn_fold(TypeNode l,TypeNode r){return min(l,r);}
	inline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return old_lazy+new_lazy;}
	inline static constexpr TypeNode fucn_operate(TypeNode node,TypeLazy lazy,int l, int r){return node+lazy;}
};