//最大値クエリ
template<class T> struct ValueMax {
	using TypeValue = T;
	inline static constexpr TypeValue unit_value = -3e18;
	inline static constexpr bool func_compare(TypeValue l,TypeValue r){return l>r;}
};