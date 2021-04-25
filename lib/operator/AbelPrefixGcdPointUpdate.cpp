template<class TypeNode> struct AbelPrefixGcdPointUpdate {
	TypeNode unit_node = 0;
	TypeNode func_node(const TypeNode& l,const TypeNode& r){return ((r == 0) ? l : func_node(r, l % r));}
	// Binary Search for first index at where func_check is true
	bool func_check(const TypeNode nodeVal,const TypeNode& var){return var == nodeVal;}
};