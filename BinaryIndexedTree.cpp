
//Binary Indexed Tree
template<class Operator> class BinaryIndexedTree {
	Operator Op;                                         //Operator 演算子、型、単位元を持つ
	using typeNode = decltype(Op.unitNode);              //nodeの型
	int N;
	vector<typeNode> node;

public:
	BinaryIndexedTree(int N) : N(N), node(N + 1, Op.unitNode) {
		//do nothing
	}
 
	//[idx,idx+1)の値を更新
	void update(int idx, typeNode var) {
		for (++idx; idx <= N; idx += idx & -idx) node[idx] = Op.funcMerge(node[idx],var);
	}

	//[0,idx)の値を取得
	typeNode getvar(int idx) {
		typeNode ret = Op.unitNode;
		for (; idx >= 1; idx -= idx & -idx) ret = Op.funcMerge(ret,node[idx]);
		return ret;
	}
};

template<class typeNode> struct nodeAddRangeSum {
	typeNode unitNode = 0;
	typeNode funcNode(typeNode l,typeNode r){return l+r;}
	typeNode funcMerge(typeNode l,typeNode r){return l+r;}
};

//verify https://atcoder.jp/contests/chokudai_S001/tasks/chokudai_S001_j
