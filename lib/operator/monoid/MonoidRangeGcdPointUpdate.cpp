/*
 * @title MonoidRangeGcdPointUpdate - [区間gcd, 点更新]
 * @docs md/operator/monoid/MonoidRangeGcdPointUpdate.md
 */
template<class T> struct MonoidRangeGcdPointUpdate {
	using TypeNode = T;
	inline static constexpr TypeNode unit_node = 0;
	inline static constexpr TypeNode func_fold(TypeNode l,TypeNode r){return Gcd::gcd(l,r);}
	inline static constexpr TypeNode func_operate(TypeNode l,TypeNode r){return r;}
	inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var == nodeVal;}
};