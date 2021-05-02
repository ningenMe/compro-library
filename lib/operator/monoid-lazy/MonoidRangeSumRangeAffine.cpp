template<class T, class U> struct MonoidRangeSumRangeAffine {
	using TypeNode = T;
	using TypeLazy = U;
	inline static constexpr TypeNode unit_node = 0;
	inline static constexpr TypeLazy unit_lazy = {1,0};
	inline static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return l+r;}
	inline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return {new_lazy.first*old_lazy.first,new_lazy.first*old_lazy.second+new_lazy.second};}
	inline static constexpr TypeNode func_operate(TypeNode node,TypeLazy lazy,int l, int r){return {node*lazy.first+lazy.second*(r-l)};}
	inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}
};
