/*
 * @title SegmentTree
 */
template<class Operator> class SegmentTree {
	using TypeNode = typename Operator::TypeNode; 
	size_t length;
	size_t num;
	vector<TypeNode> node;
	vector<pair<size_t,size_t>> range;
public:

	//unitで初期化
	SegmentTree(const size_t num): num(num) {
		for (length = 1; length <= num; length *= 2);
		node.resize(2 * length, Operator::unit_node);
		range.resize(2 * length);
		for (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);
		for (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);
	}

	//vectorで初期化
	SegmentTree(const vector<TypeNode> & vec) : num(vec.size()) {
		for (length = 1; length <= vec.size(); length *= 2);
		node.resize(2 * length, Operator::unit_node);
		for (int i = 0; i < vec.size(); ++i) node[i + length] = vec[i];
		for (int i = length - 1; i >= 0; --i) node[i] = Operator::func_node(node[(i<<1)+0],node[(i<<1)+1]);
		range.resize(2 * length);
		for (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);
		for (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);
	}
 
	//同じinitで初期化
	SegmentTree(const size_t num, const TypeNode init) : num(num) {
		for (length = 1; length <= num; length *= 2);
		node.resize(2 * length, Operator::unit_node);
		range.resize(2 * length);
		for (int i = 0; i < length; ++i) node[i+length] = init;
		for (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);
		for (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);
	}
	
	//[idx,idx+1)
	void update(size_t idx, const TypeNode var) {
		if(idx < 0 || length <= idx) return;
		idx += length;
		node[idx] = Operator::func_merge(node[idx],var);
		while(idx >>= 1) node[idx] = Operator::func_node(node[(idx<<1)+0],node[(idx<<1)+1]);
	}

	//[l,r)
	TypeNode get(int l, int r) {
		if (l < 0 || length <= l || r < 0 || length < r) return Operator::unit_node;
		TypeNode vl = Operator::unit_node, vr = Operator::unit_node;
		for(l += length, r += length; l < r; l >>=1, r >>=1) {
			if(l&1) vl = Operator::func_node(vl,node[l++]);
			if(r&1) vr = Operator::func_node(node[--r],vr);
		}
		return Operator::func_node(vl,vr);
	}

	//return [0,length]
	int prefix_binary_search(TypeNode var) {
		if(!Operator::func_check(node[1],var)) return num;
		TypeNode ret = Operator::unit_node;
		size_t idx = 2;
		for(; idx < 2*length; idx<<=1){
			if(!Operator::func_check(Operator::func_node(ret,node[idx]),var)) {
				ret = Operator::func_node(ret,node[idx]);
				idx++;
			}
		}
		return min((idx>>1) - length,num);
	}

	//range[l,r) return [l,r]
	int binary_search(size_t l, size_t r, TypeNode var) {
		if (l < 0 || length <= l || r < 0 || length < r) return -1;
		TypeNode ret = Operator::unit_node;
		size_t off = l;
		for(size_t idx = l+length; idx < 2*length && off < r; ){
			if(range[idx].second<=r && !Operator::func_check(Operator::func_node(ret,node[idx]),var)) {
				ret = Operator::func_node(ret,node[idx]);
				off = range[idx++].second;
				if(!(idx&1)) idx >>= 1;			
			}
			else{
				idx <<=1;
			}
		}
		return off;
	}

	
	void print(){
		// cout << "node" << endl;
		// for(int i = 1,j = 1; i < 2*length; ++i) {
		// 	cout << node[i] << " ";
		// 	if(i==((1<<j)-1) && ++j) cout << endl;
		// }
		cout << "vector" << endl;
		cout << "{ " << get(0,1);
		for(int i = 1; i < length; ++i) cout << ", " << get(i,i+1);
		cout << " }" << endl;
	}
};

//一点更新 区間最小
template<class T> struct NodeMinPointUpdate {
	using TypeNode = T;
	inline static constexpr TypeNode unit_node = (1LL<<31)-1;
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return min(l,r);}
	inline static constexpr TypeNode func_merge(TypeNode l,TypeNode r){return r;}
	inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var == nodeVal;}
};

//一点加算 区間総和
template<class T> struct NodeSumPointAdd {
	using TypeNode = T;
	inline static constexpr TypeNode unit_node = 0;
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return l+r;}
	inline static constexpr TypeNode func_merge(TypeNode l,TypeNode r){return l+r;}
	inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var == nodeVal;}
};

//一次関数
template<class T> struct NodeCompositePointUpdate {
	using TypeNode = T;
	inline static constexpr TypeNode unit_node = make_pair(1,0);
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return {r.first*l.first,r.first*l.second+r.second};}
	inline static constexpr TypeNode func_merge(TypeNode l,TypeNode r){return r;}
	inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var == nodeVal;}
};
