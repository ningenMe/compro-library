/*
 * @title LazySegmentTree - 非再帰抽象化遅延評価セグメント木
 * @docs md/data-structure/segment-tree/LazySegmentTree.md
 */
template<class Monoid> class LazySegmentTree {
	using TypeNode = typename Monoid::TypeNode;          
	using TypeLazy = typename Monoid::TypeLazy;
	size_t num;      
	size_t length;                                   
	size_t height;                                   
	vector<TypeNode> node;                           
	vector<TypeLazy> lazy;                           
	vector<pair<size_t,size_t>> range;

	void propagate(int k) {
		if(lazy[k] == Monoid::unit_lazy) return;
        node[k] = Monoid::func_operate(node[k],lazy[k],range[k].first,range[k].second);
		if(k < length) lazy[2*k+0] = Monoid::func_lazy(lazy[2*k+0],lazy[k]);
		if(k < length) lazy[2*k+1] = Monoid::func_lazy(lazy[2*k+1],lazy[k]);
		lazy[k] = Monoid::unit_lazy;
	}

	void build() {
		for (int i = length - 1; i >= 0; --i) node[i] = Monoid::func_fold(node[(i<<1)+0],node[(i<<1)+1]);
		range.resize(2 * length);
		for (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);
		for (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);
	}
public:

	//unitで初期化
	LazySegmentTree(const size_t num) : num(num) {
		for (length = 1,height = 0; length <= num; length *= 2, height++);
		node.resize(2 * length, Monoid::unit_node);
		lazy.resize(2 * length, Monoid::unit_lazy);
		for (int i = 0; i < num; ++i) node[i + length] = Monoid::unit_node;
		build();
	}

	// //同じinitで初期化
	LazySegmentTree(const size_t num, const TypeNode init) : num(num) {
		for (length = 1,height = 0; length <= num; length *= 2, height++);
		node.resize(2 * length, Monoid::unit_node);
		lazy.resize(2 * length, Monoid::unit_lazy);
		for (int i = 0; i < num; ++i) node[i + length] = init;
		build();
	}

	//vectorで初期化
	LazySegmentTree(const vector<TypeNode>& vec) : num(vec.size()) {
		for (length = 1,height = 0; length <= vec.size(); length *= 2, height++);
		node.resize(2 * length, Monoid::unit_node);
		lazy.resize(2 * length, Monoid::unit_lazy);
		for (int i = 0; i < vec.size(); ++i) node[i + length] = vec[i];
		build();
	}

	//operate [a,b)
	void operate(int a, int b, TypeLazy x) {
		int l = a + length, r = b + length - 1;
		for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
		for(r++; l < r; l >>=1, r >>=1) {
			if(l&1) lazy[l] = Monoid::func_lazy(lazy[l],x), propagate(l),l++;
			if(r&1) --r,lazy[r] = Monoid::func_lazy(lazy[r],x), propagate(r);
		}
		l = a + length, r = b + length - 1;
		while ((l>>=1),(r>>=1),l) {
            if(lazy[l] == Monoid::unit_lazy) node[l] = Monoid::func_fold(Monoid::func_operate(node[(l<<1)+0],lazy[(l<<1)+0],range[(l<<1)+0].first,range[(l<<1)+0].second),Monoid::func_operate(node[(l<<1)+1],lazy[(l<<1)+1],range[(l<<1)+1].first,range[(l<<1)+1].second));
            if(lazy[r] == Monoid::unit_lazy) node[r] = Monoid::func_fold(Monoid::func_operate(node[(r<<1)+0],lazy[(r<<1)+0],range[(r<<1)+0].first,range[(r<<1)+0].second),Monoid::func_operate(node[(r<<1)+1],lazy[(r<<1)+1],range[(r<<1)+1].first,range[(r<<1)+1].second));
  		}
	}

	//fold [a,b)
	TypeNode fold(int a, int b) {
		int l = a + length, r = b + length - 1;
		for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
		TypeNode vl = Monoid::unit_node, vr = Monoid::unit_node;
		for(r++; l < r; l >>=1, r >>=1) {
            if(l&1) vl = Monoid::func_fold(vl,Monoid::func_operate(node[l],lazy[l],range[l].first,range[l].second)),l++;
            if(r&1) r--,vr = Monoid::func_fold(Monoid::func_operate(node[r],lazy[r],range[r].first,range[r].second),vr);
 		}
		return Monoid::func_fold(vl,vr);
	}

	//return [0,length]
	int prefix_binary_search(TypeNode var) {
		int l = length, r = 2*length - 1;
		for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
		if(!Monoid::func_check(node[1],var)) return num;
		TypeNode ret = Monoid::unit_node;
		size_t idx = 2;
		for(; idx < 2*length; idx<<=1){
            if(!Monoid::func_check(Monoid::func_fold(ret,Monoid::func_operate(node[idx],lazy[idx],range[idx].first,range[idx].second)),var)) {
                ret = Monoid::func_fold(ret,Monoid::func_operate(node[idx],lazy[idx],range[idx].first,range[idx].second));
                idx++;
            }
		}
		return min((idx>>1) - length,num);
	}

	//range[l,r) return [l,r]
	int binary_search(size_t l, size_t r, TypeNode var) {
		if (l < 0 || length <= l || r < 0 || length < r) return -1;
		for (int i = height; 0 < i; --i) propagate((l+length) >> i), propagate((r+length-1) >> i);
		TypeNode ret = Monoid::unit_node;
		size_t off = l;
		for(size_t idx = l+length; idx < 2*length && off < r; ){
            if(range[idx].second<=r && !Monoid::func_check(Monoid::func_fold(ret,Monoid::func_operate(node[idx],lazy[idx],range[idx].first,range[idx].second)),var)) {
                ret = Monoid::func_fold(ret,Monoid::func_operate(node[idx],lazy[idx],range[idx].first,range[idx].second));
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
		cout << "{ " << fold(0,1);
		for(int i = 1; i < length; ++i) cout << ", " << fold(i,i+1);
		cout << " }" << endl;
	}
};
