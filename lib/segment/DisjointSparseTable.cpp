template<class Operator> class DisjointSparseTable{
public:
	using TypeNode = typename Operator::TypeNode;
	size_t depth;
	size_t length;
	vector<TypeNode> node;
	vector<size_t> msb;

	DisjointSparseTable(const vector<TypeNode>& vec) {
		for(depth = 0;(1<<depth)<=vec.size();++depth);
		length = (1<<depth);
		
		//msb
		msb.resize(length,0);
		for(int i = 0; i < length; ++i) for(int j = 0; j < depth; ++j) if(i>>j) msb[i] = j;

		//init value
		node.resize(depth*length,Operator::unit_node);
		for(int i = 0; i < vec.size(); ++i) node[i] = vec[i];

		for(int i = 1; i < depth; ++i) {
			for(int r = (1<<i),l = r-1; r < length; r += (2<<i),l = r-1){
				//init accumulate
				node[i*length+l] = node[l];
				node[i*length+r] = node[r];
				//accumulate
				for(int k = 1; k < (1<<i); ++k) {
					node[i*length+l-k] = Operator::func_node(node[i*length+l-k+1],node[l-k]);
					node[i*length+r+k] = Operator::func_node(node[i*length+r+k-1],node[r+k]);
				}
			}
		}
	}

	//[l,r)
	TypeNode get(int l,int r) {
		r--;
		return (l>r||l<0||length<=r) ? Operator::unit_node: (l==r ? node[l] : Operator::func_node(node[msb[l^r]*length+l],node[msb[l^r]*length+r]));
	}
};

//sum
template<class T> struct NodeSum {
    using TypeNode = T;
	inline static constexpr TypeNode unit_node = 0;
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return l+r;}
};
