/*
 * @title DynamicBinaryIndexedTree - 動的BIT
 * @docs md/segment/DynamicBinaryIndexedTree.md
 */
template<class Operator> class DynamicBinaryIndexedTree {
	using TypeNode = typename Operator::TypeNode;
    using i64 = long long;
	size_t depth;         
	i64 length;
	i64 num;

    unordered_map<i64,TypeNode> node;
public:
	
	//[0,N) constructed, inplace [0,1) + [1,N+1)
	//you can ignore inplace offset
	DynamicBinaryIndexedTree(const i64 num) : num(num) {
		for (depth = 1,length = 1; length < num; depth++,length *= 2);
	}
 
	//[idx,idx+1) update 
	void update(i64 idx, TypeNode var) {
		assert(0 <= idx && idx < length);
		for (++idx; idx <= length; idx += idx & -idx) node[idx] = Operator::func_node(node[idx],var);
	}

	//[0,idx) get
	TypeNode get(i64 idx) {
		TypeNode ret = Operator::unit_node;
		for (idx = min(length,idx); idx > 0; idx -= idx & -idx) ret = Operator::func_node(ret,node[idx]);
		return ret;
	}

	//[l,r) get
	TypeNode get(i64 l, i64 r) {
        TypeNode val = get(r);
        if(l>0) val = Operator::func_node_inv(val,get(l));
        return val;
	}

	void print() {
		cout << "{ " << get(1);
		for(int i = 1; i < length; ++i) cout << ", " << get(i+1);
		cout << " }" << endl;
	}
};

template<class T> struct NodePrefixSumPointAdd {
	using TypeNode = T;
	inline static constexpr TypeNode unit_node = 0;
	inline static constexpr TypeNode func_node(const TypeNode& l,const TypeNode& r){return l+r;}
	inline static constexpr TypeNode func_node_inv(const TypeNode& l,const TypeNode& r){return l-r;}
};