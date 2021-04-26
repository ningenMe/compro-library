//node:総和　lazy:加算
template<class T, class U> struct MonoidRangeEulerTourSumRangeAdd {
	using TypeNode = T;
	using TypeLazy = U;
	inline static constexpr TypeNode unit_node = {0,0};
	inline static constexpr TypeLazy unit_lazy = 0;
	inline static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return {l.first+r.first,l.second+r.second};}
	inline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return old_lazy+new_lazy;}
	inline static constexpr TypeNode func_operate(TypeNode node,TypeLazy lazy,int l, int r){return {node.first+node.second*lazy,node.second};}
	inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}
	// LazySegmentTree<NodeSumRangeUpdate<ll,ll>> Seg(N,0);
};
