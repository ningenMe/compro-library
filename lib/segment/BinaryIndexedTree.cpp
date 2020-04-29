//Binary Indexed Tree
template<class Operator> class BinaryIndexedTree {
	using TypeNode = typename Operator::TypeNode;
	size_t depth;         
	size_t length;
	size_t num;
	vector<TypeNode> node;
public:
	BinaryIndexedTree(const size_t num) : num(num) {
		for (depth = 1,length = 1; length < num; depth++,length *= 2);
		node.resize(length+1, Operator::unit_node);
	}
 
	//[idx,idx+1) update
	void update(size_t idx, TypeNode var) {
		assert(0 <= idx && idx < length);
		for (++idx; idx <= length; idx += idx & -idx) node[idx] = Operator::func_node(node[idx],var);
	}

	//[0,idx) get
	TypeNode get(size_t idx) {
		TypeNode ret = Operator::unit_node;
		for (idx = min(length,idx); idx > 0; idx -= idx & -idx) ret = Operator::func_node(ret,node[idx]);
		return ret;
	}

	//return [0,length]
	int binary_search(TypeNode var) {
		if(!Operator::func_check(node.back(),var)) return num;
		TypeNode ret = Operator::unit_node;
		size_t off = 0;
		for(size_t idx = length; idx; idx >>= 1){
			if(off + idx <= length && !Operator::func_check(Operator::func_node(ret,node[off+idx]),var)) {
				off += idx;
				ret = Operator::func_node(ret,node[off]);
			}
		}
		return min(off,num);
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
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return l+r;}
	// Binary Search for first index where func_check is true
	inline static constexpr bool func_check(TypeNode nodeVal,TypeNode val){return val <= nodeVal;}
};

template<class TypeNode> struct nodeUpdatePrefixGCD {
	TypeNode unit_node = 0;
	TypeNode func_node(TypeNode l,TypeNode r){return ((r == 0) ? l : func_node(r, l % r));}
	// Binary Search for first index at where func_check is true
	bool func_check(TypeNode nodeVal,TypeNode var){return var == nodeVal;}
};

//verify https://atcoder.jp/contests/chokudai_S001/tasks/chokudai_S001_j
//verify https://atcoder.jp/contests/abc130/tasks/abc130_d
