
//Binary Indexed Tree
template<class Operator> class BinaryIndexedTree {
	Operator Op;                                         
	using typeNode = decltype(Op.unitNode);
	size_t depth;         
	size_t length;
	size_t num;
	vector<typeNode> node;

public:
	BinaryIndexedTree(const size_t num) : num(num) {
		for (depth = 1,length = 1; length < num; depth++,length *= 2);
		node.resize(length+1, Op.unitNode);
	}
 
	//[idx,idx+1) update
	void update(size_t idx, typeNode var) {
		assert(0 <= idx && idx < length);
		for (++idx; idx <= length; idx += idx & -idx) node[idx] = Op.funcNode(node[idx],var);
	}

	//[0,idx) get
	typeNode get(size_t idx) {
		typeNode ret = Op.unitNode;
		for (idx = min(length,idx); idx > 0; idx -= idx & -idx) ret = Op.funcNode(ret,node[idx]);
		return ret;
	}

	//return [0,length]
	int BinarySearch(typeNode var) {
		if(!Op.funcCheck(node.back(),var)) return num;
		typeNode ret = Op.unitNode;
		size_t off = 0;
		for(size_t idx = length; idx; idx >>= 1){
			if(off + idx <= length && !Op.funcCheck(Op.funcNode(ret,node[off+idx]),var)) {
				off += idx;
				ret = Op.funcNode(ret,node[off]);
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

template<class typeNode> struct nodeAddPrefixSum {
	typeNode unitNode = 0;
	typeNode funcNode(typeNode l,typeNode r){return l+r;}
	// Binary Search for first index where funcCheck is true
	bool funcCheck(typeNode nodeVal,typeNode val){return val <= nodeVal;}
};

template<class typeNode> struct nodeUpdatePrefixGCD {
	typeNode unitNode = 0;
	typeNode funcNode(typeNode l,typeNode r){return ((r == 0) ? l : funcNode(r, l % r));}
	// Binary Search for first index at where funcCheck is true
	bool funcCheck(typeNode nodeVal,typeNode var){return var == nodeVal;}
};

//verify https://atcoder.jp/contests/chokudai_S001/tasks/chokudai_S001_j
//verify https://atcoder.jp/contests/abc130/tasks/abc130_d