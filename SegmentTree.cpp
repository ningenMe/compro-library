
template<class Operator> class SegmentTree {
	Operator Op;                            //Operator 演算子、型、単位元を持つ
	using typeNode = decltype(Op.unitNode); //nodeの型
	size_t length;                          //セグメント木の最下段の要素の数(vectorの要素の数を超える2べきの数)
	vector<typeNode> node;                  //ノード

public:

	//unitで初期化
	SegmentTree(const size_t num){
		for (length = 1; length < num; length *= 2);
		node.resize(2 * length, Op.unitNode);
	}

	//vectorで初期化
	SegmentTree(const vector<typeNode> & vec){
		for (length = 1; length < vec.size(); length *= 2);
		node.resize(2 * length, Op.unitNode);
		for (int i = 0; i < vec.size(); ++i) node[i + length] = vec[i];
		for (int i = length - 1; i >= 0; --i) node[i] = Op.funcNode(node[(i<<1)+0],node[(i<<1)+1]);
	}
 
	//同じinitで初期化
	SegmentTree(const size_t num, const typeNode init) {
		for (length = 1; length < num; length *= 2);
		node.resize(2 * length, init);
	}
	
	//idx : 0-indexed
	void update(size_t idx, const typeNode var) {
		if(idx < 0 || length <= idx) return;
		idx += length;
		node[idx] = Op.funcMerge(node[idx],var);
		while(idx >>= 1) node[idx] = Op.funcNode(node[(idx<<1)+0],node[(idx<<1)+1]);
	}

	//[l,r)
	typeNode get(int l, int r) {
		if (l < 0 || length <= l || r < 0 || length < r) return Op.unitNode;
		typeNode vl = Op.unitNode, vr = Op.unitNode;
		for(l += length, r += length; l < r; l >>=1, r >>=1) {
			if(l&1) vl = Op.funcNode(vl,node[l++]);
			if(r&1) vr = Op.funcNode(node[--r],vr);
		}
		return Op.funcNode(vl,vr);
	}
 
	void print(){
		cout << "{ " << get(0,1);
		for(int i = 1; i < length; ++i) cout << ", " << get(i,i+1);
		cout << " }" << endl;

		for(int i = 1,j = 1; i < 2*length; ++i) {
			cout << node[i] << " ";
			if(i==((1<<j)-1) && ++j) cout << endl;
		}
	}

};

//一点加算 区間最大
template<class typeNode> struct nodeSumRangeMax {
	typeNode unitNode = 0;
	typeNode funcNode(typeNode l,typeNode r){return max(l,r);}
	typeNode funcMerge(typeNode l,typeNode r){return l+r;}
};

//一点加算 区間総和
template<class typeNode> struct nodeSumRangeSum {
	typeNode unitNode = 0;
	typeNode funcNode(typeNode l,typeNode r){return l+r;}
	typeNode funcMerge(typeNode l,typeNode r){return l+r;}
};

//一点更新 区間最小
template<class typeNode> struct nodeUpdateRangeMin {
	typeNode unitNode = (1LL<<31)-1;
	typeNode funcNode(typeNode l,typeNode r){return min(l,r);}
	typeNode funcMerge(typeNode l,typeNode r){return r;}
};


