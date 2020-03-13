template<class Operator> class LazySegmentTree {
    Operator Op;                                       
	using typeNode = decltype(Op.unitNode);          
	using typeLazy = decltype(Op.unitLazy);          
	size_t length;                                   
	size_t height;                                   
	vector<typeNode> node;                           
	vector<typeLazy> lazy;                           
	vector<pair<size_t,size_t>> range;
public:

	//unitで初期化
	LazySegmentTree(const size_t num) {
		for (length = 1,height = 0; length < num; length *= 2, height++);
		node.resize(2 * length, Op.unitNode);
		lazy.resize(2 * length, Op.unitLazy);
		for (int i = 0; i < num; ++i) node[i + length] = Op.unitNode;
		for (int i = length - 1; i >= 0; --i) node[i] = Op.funcNode(node[(i<<1)+0],node[(i<<1)+1]);
		range.resize(2 * length);
		for (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);
		for (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);
	}

	// //同じinitで初期化
	LazySegmentTree(const size_t num, const typeNode init) {
		for (length = 1,height = 0; length < num; length *= 2, height++);
		node.resize(2 * length, Op.unitNode);
		lazy.resize(2 * length, Op.unitLazy);
		for (int i = 0; i < num; ++i) node[i + length] = init;
		for (int i = length - 1; i >= 0; --i) node[i] = Op.funcNode(node[(i<<1)+0],node[(i<<1)+1]);
		range.resize(2 * length);
		for (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);
		for (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);
	}

	//vectorで初期化
	LazySegmentTree(const vector<typeNode>& vec) {
		for (length = 1,height = 0; length < vec.size(); length *= 2, height++);
		node.resize(2 * length, Op.unitNode);
		lazy.resize(2 * length, Op.unitLazy);
		for (int i = 0; i < vec.size(); ++i) node[i + length] = vec[i];
		for (int i = length - 1; i >= 0; --i) node[i] = Op.funcNode(node[(i<<1)+0],node[(i<<1)+1]);
		range.resize(2 * length);
		for (int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);
		for (int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);
	}


	void propagate(int k) {
		if(lazy[k] == Op.unitLazy) return;
		node[k] = Op.funcMerge(node[k],lazy[k],range[k].second-range[k].first);
		if(k < length) lazy[2*k+0] = Op.funcLazy(lazy[2*k+0],lazy[k]);
		if(k < length) lazy[2*k+1] = Op.funcLazy(lazy[2*k+1],lazy[k]);
		lazy[k] = Op.unitLazy;
    }


	//idx : 0-indexed
    void update(int a, int b, typeLazy x) {
		int l = a + length, r = b + length - 1;
		for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
		for(r++; l < r; l >>=1, r >>=1) {
			if(l&1) lazy[l] = Op.funcLazy(lazy[l],x), propagate(l),l++;
			if(r&1) --r,lazy[r] = Op.funcLazy(lazy[r],x), propagate(r);
		}
		l = a + length, r = b + length - 1;
		while ((l>>=1),(r>>=1),l) {
			if(lazy[l] == Op.unitLazy) node[l] = Op.funcNode(Op.funcMerge(node[(l<<1)+0],lazy[(l<<1)+0],range[(l<<1)+0].second-range[(l<<1)+0].first),Op.funcMerge(node[(l<<1)+1],lazy[(l<<1)+1],range[(l<<1)+1].second-range[(l<<1)+1].first));
			if(lazy[r] == Op.unitLazy) node[r] = Op.funcNode(Op.funcMerge(node[(r<<1)+0],lazy[(r<<1)+0],range[(l<<1)+0].second-range[(l<<1)+0].first),Op.funcMerge(node[(r<<1)+1],lazy[(r<<1)+1],range[(l<<1)+1].second-range[(l<<1)+1].first));
		}
    }

	//[l,r)
	typeNode get(int a, int b) {
		int l = a + length, r = b + length - 1;
		for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
		typeNode vl = Op.unitNode, vr = Op.unitNode;
		for(r++; l < r; l >>=1, r >>=1) {
			if(l&1) vl = Op.funcNode(vl,Op.funcMerge(node[l],lazy[l],range[l].second-range[l].first)),l++;
			if(r&1) r--,vr = Op.funcNode(Op.funcMerge(node[r],lazy[r],range[r].second-range[r].first),vr);
		}
		return Op.funcNode(vl,vr);
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

//node:総和　lazy:加算
template<class typeNode, class typeLazy> struct nodeSumLazyAdd {
	typeNode unitNode = 0;
	typeLazy unitLazy = 0;
	typeNode funcNode(typeNode l,typeNode r){return l+r;}
	typeLazy funcLazy(typeLazy l,typeLazy r){return l+r;}
	typeNode funcMerge(typeNode l,typeLazy r,int len){return l+r*len;}
    // LazySegmentTree<nodeSumLazyPlus<ll,ll>> Seg(N,0);
};

//node:最小　lazy:加算
template<class typeNode, class typeLazy> struct nodeMinLazyAdd {
	typeNode unitNode = 1234567890;
	typeLazy unitLazy = 0;
	typeNode funcNode(typeNode l,typeNode r){return min(l,r);}
	typeLazy funcLazy(typeLazy l,typeLazy r){return l+r;}
	typeNode funcMerge(typeNode l,typeLazy r,int len){return l+r;}
    // LazySegmentTree<nodeMinLazyAdd<ll,ll>> Seg(N,0);
	//verify https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_H
};

//node:mod和　lazy:mod加算
template<class typeNode, class typeLazy> struct nodeModSumLazyModAdd {
	typeNode unitNode = 0;
	typeLazy unitLazy = 0;
	typeNode funcNode(typeNode l,typeNode r){return (l+r)%MOD;}
	typeLazy funcLazy(typeLazy l,typeLazy r){return (l+r)%MOD;}
	typeNode funcMerge(typeNode l,typeLazy r,int len){return (l+(r*len)%MOD)%MOD;}
	// LazySegmentTree<nodeModSumLazyModAdd<ll,ll>> dp(N+3,0);
    //verify https://atcoder.jp/contests/code-festival-2018-quala/tasks/code_festival_2018_quala_d
};

//node:最大　lazy:更新
template<class typeNode, class typeLazy> struct nodeMaxLazyUpdate {
	typeNode unitNode = 0;
	typeLazy unitLazy = 0;
	typeNode funcNode(typeNode l,typeNode r){return max(l,r);}
	typeLazy funcLazy(typeLazy l,typeLazy r){return r;}
	typeNode funcMerge(typeNode l,typeLazy r,int len){return r!=0?r*len:l;}
    // LazySegmentTree<nodeMaxLazyUpdate<ll,ll>> Seg(N+2,0);
    //verify https://atcoder.jp/contests/nikkei2019-final/tasks/nikkei2019_final_d
};

//node:最小　lazy:更新
template<class typeNode, class typeLazy> struct nodeMinLazyUpdate {
	typeNode unitNode = 12345678910;
	typeLazy unitLazy = 0;
	typeNode funcNode(typeNode l,typeNode r){return min(l,r);}
	typeLazy funcLazy(typeLazy l,typeLazy r){return r;}
	typeNode funcMerge(typeNode l,typeLazy r,int len){return r!=0?r*len:l;}
	//LazySegmentTree<ll,ll,nodeMinLazyUpdate<ll,ll>> Seg(N,HIGHINF,0);
    //verify https://atcoder.jp/contests/code-festival-2018-final/tasks/code_festival_2018_final_e
};

//node:GCD　lazy:更新
template<class typeNode, class typeLazy> struct nodeGCDLazyUpdate {
	typeNode unitNode = 0;
	typeLazy unitLazy = 0;
	typeNode funcNode(typeNode l,typeNode r){return ((r == 0) ? l : funcNode(r, l % r));}
	typeLazy funcLazy(typeLazy l,typeLazy r){return r;}
	typeNode funcMerge(typeNode l,typeLazy r,int len){return r!=0?r:l;}
    // LazySegmentTree<nodeGCDLazyUpdate<ll,ll>> Seg(A);
    //verify https://atcoder.jp/contests/abc125/tasks/abc125_c
};

//node:総和　lazy:更新
template<class typeNode, class typeLazy> struct nodeSumLazyUpdate {
	typeNode unitNode = 0;
	typeLazy unitLazy = -2000;
	typeNode funcNode(typeNode l,typeNode r){return l+r;}
	typeLazy funcLazy(typeLazy l,typeLazy r){return r;}
	typeNode funcMerge(typeNode l,typeLazy r,int len){return r!=-2000?r*len:l;}
	// LazySegmentTree<nodeSumLazyUpdate<ll,ll>> Seg(N,0,-2000,0);
    //verify https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I
};
