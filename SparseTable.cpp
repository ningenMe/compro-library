
template<class Operator> class SparseTable{
public:
	Operator Op;                           
	using typeNode = decltype(Op.unitNode);
	vector<typeNode> node;
	vector<int> idx;
	size_t depth;
	size_t length;

	SparseTable(const vector<typeNode>& vec) {
		for(depth = 0;(1<<depth)<=vec.size();++depth);
		length = (1<<depth);
		node.resize(depth*length);
		for(int i = 0; i < vec.size(); ++i) node[i] = vec[i];
		for(int i = 1; i < depth; ++i) for(int j = 0; j + (1<<i) < (1<<depth); ++j) node[i*length+j] = Op.funcNode(node[(i-1)*length+j],node[(i-1)*length+j + (1 << (i-1))]);
		idx.resize(vec.size()+1);
		for(int i = 2; i < vec.size()+1; ++i) idx[i] = idx[i>>1] + 1;
	}

	//[l,r)
	typeNode get(int l,int r) {
		int bit = idx[r-l];
		return Op.funcNode(node[bit*length+l],node[bit*length+r - (1<<bit)]);
	}
};

template<class typeNode> struct nodeGCD {
	typeNode unitNode = 0;
	typeNode funcNode(typeNode l,typeNode r){return r?funcNode(r,l%r):l;}
};
