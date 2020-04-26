template<class Operator> class DisjointSparseTable{
public:
	Operator Op;                           
	using typeNode = decltype(Op.unitNode);
	size_t depth;
	size_t length;
	vector<typeNode> node;
	vector<size_t> msb;

	DisjointSparseTable(const vector<typeNode>& vec) {
		for(depth = 0;(1<<depth)<=vec.size();++depth);
		length = (1<<depth);
		
		//msb
		msb.resize(length,0);
		for(int i = 0; i < length; ++i) for(int j = 0; j < depth; ++j) if(i>>j) msb[i] = j;

		//init value
		node.resize(depth*length,Op.unitNode);
		for(int i = 0; i < vec.size(); ++i) node[i] = vec[i];

		for(int i = 1; i < depth; ++i) {
			for(int r = (1<<i),l = r-1; r < length; r += (2<<i),l = r-1){
				//init accumulate
				node[i*length+l] = node[l];
				node[i*length+r] = node[r];
				//accumulate
				for(int k = 1; k < (1<<i); ++k) {
					node[i*length+l-k] = Op.funcNode(node[i*length+l-k+1],node[l-k]);
					node[i*length+r+k] = Op.funcNode(node[i*length+r+k-1],node[r+k]);
				}
			}
		}
	}

	//[l,r)
	typeNode get(int l,int r) {
		r--;
		return (l>r||l<0||length<=r) ? Op.unitNode: (l==r ? node[l] : Op.funcNode(node[msb[l^r]*length+l],node[msb[l^r]*length+r]));
	}
};

//区間GCD
template<class typeNode> struct nodeGCD {
	typeNode unitNode = 0;
	typeNode funcNode(typeNode l,typeNode r){return ((r == 0) ? l : funcNode(r, l % r));}
};

//区間最大
template<class typeNode> struct nodeMax {
	typeNode unitNode = 0;
	typeNode funcNode(typeNode l,typeNode r){return max(l,r);}
};

//区間最小
template<class typeNode> struct nodeMin {
	typeNode unitNode = LOWINF;
	typeNode funcNode(typeNode l,typeNode r){return min(l,r);}
};

