/*
 * @title LazySegmentTree - 非再帰抽象化遅延評価セグメント木
 * @docs md/data-structure/segment-tree/LazySegmentTree.md
 */
template<class Operator> class LazySegmentTree {
	using TypeNode = typename Operator::TypeNode;          
	using TypeLazy = typename Operator::TypeLazy;
	size_t num;      
	size_t length;                                   
	size_t height;                                   
	vector<TypeNode> node;                           
	vector<TypeLazy> lazy;                           
	vector<pair<size_t,size_t>> range;

	void propagate(int k) {
		if(lazy[k] == Operator::unit_lazy) return;
        node[k] = Operator::func_merge(node[k],lazy[k],range[k].first,range[k].second);
		if(k < length) lazy[2*k+0] = Operator::func_lazy(lazy[2*k+0],lazy[k]);
		if(k < length) lazy[2*k+1] = Operator::func_lazy(lazy[2*k+1],lazy[k]);
		lazy[k] = Operator::unit_lazy;
	}
public:

	//unitで初期化
	LazySegmentTree(const size_t num) : num(num) {
		for (length = 1,height = 0; length <= num; length *= 2, height++);
		node.resize(2 * length, Operator::unit_node);
		lazy.resize(2 * length, Operator::unit_lazy);
		for (int i = 0; i < num; ++i) node[i + length] = Operator::unit_node;
		for (int i = length - 1; i >= 0; --i) node[i] = Operator::func_node(node[(i<<1)+0],node[(i<<1)+1]);
		range.resize(2 * length);
		for (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);
		for (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);
	}

	// //同じinitで初期化
	LazySegmentTree(const size_t num, const TypeNode init) : num(num) {
		for (length = 1,height = 0; length <= num; length *= 2, height++);
		node.resize(2 * length, Operator::unit_node);
		lazy.resize(2 * length, Operator::unit_lazy);
		for (int i = 0; i < num; ++i) node[i + length] = init;
		for (int i = length - 1; i >= 0; --i) node[i] = Operator::func_node(node[(i<<1)+0],node[(i<<1)+1]);
		range.resize(2 * length);
		for (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);
		for (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);
	}

	//vectorで初期化
	LazySegmentTree(const vector<TypeNode>& vec) : num(vec.size()) {
		for (length = 1,height = 0; length <= vec.size(); length *= 2, height++);
		node.resize(2 * length, Operator::unit_node);
		lazy.resize(2 * length, Operator::unit_lazy);
		for (int i = 0; i < vec.size(); ++i) node[i + length] = vec[i];
		for (int i = length - 1; i >= 0; --i) node[i] = Operator::func_node(node[(i<<1)+0],node[(i<<1)+1]);
		range.resize(2 * length);
		for (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);
		for (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);
	}

	//update [a,b)
	void update(int a, int b, TypeLazy x) {
		int l = a + length, r = b + length - 1;
		for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
		for(r++; l < r; l >>=1, r >>=1) {
			if(l&1) lazy[l] = Operator::func_lazy(lazy[l],x), propagate(l),l++;
			if(r&1) --r,lazy[r] = Operator::func_lazy(lazy[r],x), propagate(r);
		}
		l = a + length, r = b + length - 1;
		while ((l>>=1),(r>>=1),l) {
            if(lazy[l] == Operator::unit_lazy) node[l] = Operator::func_node(Operator::func_merge(node[(l<<1)+0],lazy[(l<<1)+0],range[(l<<1)+0].first,range[(l<<1)+0].second),Operator::func_merge(node[(l<<1)+1],lazy[(l<<1)+1],range[(l<<1)+1].first,range[(l<<1)+1].second));
            if(lazy[r] == Operator::unit_lazy) node[r] = Operator::func_node(Operator::func_merge(node[(r<<1)+0],lazy[(r<<1)+0],range[(r<<1)+0].first,range[(r<<1)+0].second),Operator::func_merge(node[(r<<1)+1],lazy[(r<<1)+1],range[(r<<1)+1].first,range[(r<<1)+1].second));
  		}
	}

	//get [a,b)
	TypeNode get(int a, int b) {
		int l = a + length, r = b + length - 1;
		for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
		TypeNode vl = Operator::unit_node, vr = Operator::unit_node;
		for(r++; l < r; l >>=1, r >>=1) {
            if(l&1) vl = Operator::func_node(vl,Operator::func_merge(node[l],lazy[l],range[l].first,range[l].second)),l++;
            if(r&1) r--,vr = Operator::func_node(Operator::func_merge(node[r],lazy[r],range[r].first,range[r].second),vr);
 		}
		return Operator::func_node(vl,vr);
	}

	//return [0,length]
	int prefix_binary_search(TypeNode var) {
		int l = length, r = 2*length - 1;
		for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
		if(!Operator::func_check(node[1],var)) return num;
		TypeNode ret = Operator::unit_node;
		size_t idx = 2;
		for(; idx < 2*length; idx<<=1){
            if(!Operator::func_check(Operator::func_node(ret,Operator::func_merge(node[idx],lazy[idx],range[idx].first,range[idx].second)),var)) {
                ret = Operator::func_node(ret,Operator::func_merge(node[idx],lazy[idx],range[idx].first,range[idx].second));
                idx++;
            }
		}
		return min((idx>>1) - length,num);
	}

	//range[l,r) return [l,r]
	int binary_search(size_t l, size_t r, TypeNode var) {
		if (l < 0 || length <= l || r < 0 || length < r) return -1;
		for (int i = height; 0 < i; --i) propagate((l+length) >> i), propagate((r+length-1) >> i);
		TypeNode ret = Operator::unit_node;
		size_t off = l;
		for(size_t idx = l+length; idx < 2*length && off < r; ){
            if(range[idx].second<=r && !Operator::func_check(Operator::func_node(ret,Operator::func_merge(node[idx],lazy[idx],range[idx].first,range[idx].second)),var)) {
                ret = Operator::func_node(ret,Operator::func_merge(node[idx],lazy[idx],range[idx].first,range[idx].second));
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
		// cout << "lazy" << endl;
		// for(int i = 1,j = 1; i < 2*length; ++i) {
		// 	cout << lazy[i] << " ";
		// 	if(i==((1<<j)-1) && ++j) cout << endl;
		// }
		cout << "vector" << endl;
		cout << "{ " << get(0,1);
		for(int i = 1; i < length; ++i) cout << ", " << get(i,i+1);
		cout << " }" << endl;
	}
};

//node:最小　lazy:加算
template<class T, class U> struct NodeMinRangeAdd {
	using TypeNode = T;
	using TypeLazy = U;
	inline static constexpr TypeNode unit_node = 1234567890;
	inline static constexpr TypeLazy unit_lazy = 0;
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return min(l,r);}
	inline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return old_lazy+new_lazy;}
	inline static constexpr TypeNode func_merge(TypeNode node,TypeLazy lazy,int l, int r){return node+lazy;}
	// LazySegmentTree<NodeMinRangeAdd<ll,ll>> Seg(N,0);
};

//node:総和　lazy:更新
template<class T, class U> struct NodeSumRangeUpdate {
	using TypeNode = T;
	using TypeLazy = U;
	inline static constexpr TypeNode unit_node = 0;
	inline static constexpr TypeLazy unit_lazy = -2000;
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return l+r;}
	inline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return new_lazy;}
	inline static constexpr TypeNode func_merge(TypeNode node,TypeLazy lazy,int l, int r){return lazy!=-2000?lazy*(r-l):node;}
	inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}
	// LazySegmentTree<NodeSumRangeUpdate<ll,ll>> Seg(N,0);
};

//node:総和　lazy:加算
template<class T, class U> struct NodeSumRangeAdd {
	using TypeNode = T;
	using TypeLazy = U;
	inline static constexpr TypeNode unit_node = 0;
	inline static constexpr TypeLazy unit_lazy = 0;
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return l+r;}
	inline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return old_lazy+new_lazy;}
	inline static constexpr TypeNode func_merge(TypeNode node,TypeLazy lazy,int l, int r){return node+lazy*(r-l);}
	inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}
	// LazySegmentTree<NodeSumRangeUpdate<ll,ll>> Seg(N,0);
};

//node:最小　lazy:等差数列更新
template<class T, class U> struct NodeMinRangeArithmeticUpdate {
    using TypeNode = T;
    using TypeLazy = U;
    inline static constexpr TypeNode unit_node = 1234567;
    inline static constexpr TypeLazy unit_lazy = {-2000,-2000};
    inline static constexpr TypeNode func_node(TypeNode l,TypeNode r){return min(l,r);}
    inline static constexpr TypeLazy func_lazy(TypeLazy old_lazy,TypeLazy new_lazy){return new_lazy;}
    inline static constexpr TypeNode func_merge(TypeNode node,TypeLazy lazy,int l,int r){ return (lazy.first==-2000?node:lazy.first + (l-lazy.second));}
    inline static constexpr bool func_check(TypeNode nodeVal,TypeNode var){return var <= nodeVal;}
};