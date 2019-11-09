template<class typeNode, class typeLazy, class Operator> class LazySegmentTree {
	size_t length;                                       //セグメント木の最下段の要素の数(vectorの要素の数を超える2べきの数)
	size_t height;                                       //セグメント木の高さ 
	typeNode unitNode;                                   //nodeの単位元
	typeLazy unitLazy;                                   //lazyの単位元
	vector<typeNode> node;                               //node
	vector<typeLazy> lazy;                               //lazy
	vector<int> width;                                   //width
    Operator Op;

public:

	//同じinitで初期化
	LazySegmentTree(const size_t num, const typeNode unitNode, const typeLazy unitLazy, const typeNode init)
    : unitNode(unitNode), unitLazy(unitLazy) {
		for (length = 1,height = 0; length < num; length *= 2, height++);
		node.resize(2 * length, unitNode);
		lazy.resize(2 * length, unitLazy);
		for (int i = 0; i < num; ++i) node[i + length] = init;
		for (int i = length - 1; i >= 0; --i) node[i] = Op.funcNode(node[(i<<1)+0],node[(i<<1)+1]);
		width.resize(2 * length, 0);
		for(int i = length; i < 2*length; ++i) for(int j = i, k = 1; j && !width[j] ; j >>= 1,k <<= 1) width[j] = k;
	}

	//unitで初期化
	LazySegmentTree(const size_t num, const typeNode unitNode, const typeLazy unitLazy)
    : unitNode(unitNode), unitLazy(unitLazy) {
		for (length = 1,height = 0; length < num; length *= 2, height++);
		node.resize(2 * length, unitNode);
		lazy.resize(2 * length, unitLazy);
		for (int i = 0; i < num; ++i) node[i + length] = unitNode;
		for (int i = length - 1; i >= 0; --i) node[i] = Op.funcNode(node[(i<<1)+0],node[(i<<1)+1]);
		width.resize(2 * length, 0);
		for(int i = length; i < 2*length; ++i) for(int j = i, k = 1; j && !width[j] ; j >>= 1,k <<= 1) width[j] = k;
	}

	//vectorで初期化
	LazySegmentTree(const vector<typeNode>& vec, const typeNode unitNode, const typeLazy unitLazy)
	 : unitNode(unitNode), unitLazy(unitLazy) {
		for (length = 1,height = 0; length < vec.size(); length *= 2, height++);
		node.resize(2 * length, unitNode);
		lazy.resize(2 * length, unitLazy);
		for (int i = 0; i < vec.size(); ++i) node[i + length] = vec[i];
		for (int i = length - 1; i >= 0; --i) node[i] = Op.funcNode(node[(i<<1)+0],node[(i<<1)+1]);
		width.resize(2 * length, 0);
		for(int i = length; i < 2*length; ++i) for(int j = i, k = 1; j && !width[j] ; j >>= 1,k <<= 1) width[j] = k;
	}


	void propagate(int k) {
		if(lazy[k] == unitLazy) return;
		node[k] = Op.funcMerge(node[k],lazy[k],width[k]);
		if(k < length) lazy[2*k+0] = Op.funcLazy(lazy[2*k+0],lazy[k]);
		if(k < length) lazy[2*k+1] = Op.funcLazy(lazy[2*k+1],lazy[k]);
		lazy[k] = unitLazy;
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
			if(lazy[l] == unitLazy) node[l] = Op.funcNode(Op.funcMerge(node[(l<<1)+0],lazy[(l<<1)+0],width[(l<<1)+0]),Op.funcMerge(node[(l<<1)+1],lazy[(l<<1)+1],width[(l<<1)+1]));
			if(lazy[r] == unitLazy) node[r] = Op.funcNode(Op.funcMerge(node[(r<<1)+0],lazy[(r<<1)+0],width[(r<<1)+0]),Op.funcMerge(node[(r<<1)+1],lazy[(r<<1)+1],width[(r<<1)+1]));
		}
    }

	//[l,r)
	typeNode get(int a, int b) {
		int l = a + length, r = b + length - 1;
		for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
		typeNode vl = unitNode, vr = unitNode;
		for(r++; l < r; l >>=1, r >>=1) {
			if(l&1) vl = Op.funcNode(vl,Op.funcMerge(node[l],lazy[l],width[l])),l++;
			if(r&1) r--,vr = Op.funcNode(Op.funcMerge(node[r],lazy[r],width[r]),vr);
		}
		return Op.funcNode(vl,vr);
	}

	void print(){
		cout << "node" << endl;
		for(int i = 1,j = 1; i < 2*length; ++i) {
			cout << node[i] << " ";
			if(i==((1<<j)-1) && ++j) cout << endl;
		}
		cout << "lazy" << endl;
		for(int i = 1,j = 1; i < 2*length; ++i) {
			cout << lazy[i] << " ";
			if(i==((1<<j)-1) && ++j) cout << endl;
		}
		// cout << "width" << endl;
		// for(int i = 1,j = 1; i < 2*length; ++i) {
		// 	cout << width[i] << " ";
		// 	if(i==((1<<j)-1) && ++j) cout << endl;
		// }
		// cout << "vector" << endl;
		// cout << "{ " << get(0,1);
		// for(int i = 1; i < length; ++i) cout << ", " << get(i,i+1);
		// cout << " }" << endl;
	}

};

//node:総和　lazy:加算
template<class typeNode, class typeLazy> struct nodeSumLazyAdd {
	typeNode funcNode(typeNode l,typeNode r){
        return l+r;
    }
	typeLazy funcLazy(typeLazy l,typeLazy r){
        return l+r;
    }
	typeNode funcMerge(typeNode l,typeLazy r,int len){
        return l+r*len;
    }
    //example
    //LazySegmentTree<ll,ll,nodeSumLazyPlus<ll,ll>> Seg(N,0,0,0);
};

//node:最小　lazy:加算
template<class typeNode, class typeLazy> struct nodeMinLazyAdd {
	typeNode funcNode(typeNode l,typeNode r){
        return min(l,r);
    }
	typeLazy funcLazy(typeLazy l,typeLazy r){
        return l+r;
    }
	typeNode funcMerge(typeNode l,typeLazy r,int len){
        return l+r;
    }
    //example
    //LazySegmentTree<ll,ll,nodeMinLazyAdd<ll,ll>> Seg(N,inf,0,0);
	//verify https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_H
};

//node:GCD　lazy:更新
template<class typeNode, class typeLazy> struct nodeGCDLazyUpdate {
	typeNode funcNode(typeNode l,typeNode r){
        return ((r == 0) ? l : funcNode(r, l % r));
    }
	typeLazy funcLazy(typeLazy l,typeLazy r){
        return r;
    }
	typeNode funcMerge(typeNode l,typeLazy r,int len){
        return r!=0?r:l;
    }
    //example
    //LazySegmentTree<ll,ll,nodeGCDLazyUpdate<ll,ll>> Seg(A,0,0);
    //verify https://atcoder.jp/contests/abc125/tasks/abc125_c
};

//node:総和　lazy:更新
template<class typeNode, class typeLazy> struct nodeSumLazyUpdate {
	typeNode funcNode(typeNode l,typeNode r){
        return l+r;
    }
	typeLazy funcLazy(typeLazy l,typeLazy r){
        return r;
    }
	typeNode funcMerge(typeNode l,typeLazy r,int len){
        return r!=-2000?r*len:l;
    }
    //example
	//LazySegmentTree<ll,ll,nodeSumLazyUpdate<ll,ll>> Seg(N,0,-2000,0);
    //verify https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I
};

//node:最大　lazy:更新
template<class typeNode, class typeLazy> struct nodeMaxLazyUpdate {
	typeNode funcNode(typeNode l,typeNode r){
        return max(l,r);
    }
	typeLazy funcLazy(typeLazy l,typeLazy r){
        return r;
    }
	typeNode funcMerge(typeNode l,typeLazy r,int len){
        return r!=0?r*len:l;
    }
    //example
	//LazySegmentTree<ll,ll,nodeMaxLazyUpdate<ll,ll>> Seg(N+2,0,0);
    //verify https://atcoder.jp/contests/nikkei2019-final/tasks/nikkei2019_final_d
};

//node:最大　lazy:更新
template<class typeNode, class typeLazy> struct nodeMinLazyUpdate {
	typeNode funcNode(typeNode l,typeNode r){
        return min(l,r);
    }
	typeLazy funcLazy(typeLazy l,typeLazy r){
        return r;
    }
	typeNode funcMerge(typeNode l,typeLazy r,int len){
        return r!=0?r*len:l;
    }
    //example
	//LazySegmentTree<ll,ll,nodeMinLazyUpdate<ll,ll>> Seg(N,HIGHINF,0);
    //verify https://atcoder.jp/contests/code-festival-2018-final/tasks/code_festival_2018_final_e
};

//node:mod和　lazy:mod加算
template<class typeNode, class typeLazy> struct nodeModSumLazyModAdd {
	typeNode funcNode(typeNode l,typeNode r){
        return (l+r)%MOD;
    }
	typeLazy funcLazy(typeLazy l,typeLazy r){
        return (l+r)%MOD;
    }
	typeNode funcMerge(typeNode l,typeLazy r,int len){
        return (l+(r*len)%MOD)%MOD;
    }
    //example
	//LazySegmentTree<ll,ll,nodeMinLazyUpdate<ll,ll>> Seg(N,HIGHINF,0);
    //verify https://atcoder.jp/contests/code-festival-2018-quala/tasks/code_festival_2018_quala_d
};
