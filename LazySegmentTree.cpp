template<class typeNode, class typeLazy> class LazySegmentTree {
	size_t length;                                       //セグメント木の最下段の要素の数(vectorの要素の数を超える2べきの数)
	size_t height;                                       //セグメント木の高さ 
	typeNode unitNode;                                   //nodeの単位元
	typeLazy unitLazy;                                   //lazyの単位元
	vector<typeNode> node;                               //node
	vector<typeLazy> lazy;                               //lazy
	vector<int> width;                                   //width
	function<typeNode(typeNode,typeNode)> funcNode;      //node同士の演算
	function<typeLazy(typeLazy,typeLazy)> funcLazy;      //lazy同士の演算
	function<typeNode(typeNode,typeLazy,int)> funcMerge; //nodeとlazyの演算

public:

	//vectorで初期化
	LazySegmentTree(const vector<typeNode> & vec, const typeNode unitNode, const typeLazy unitLazy, function<typeNode(typeNode,typeNode)> funcNode, function<typeLazy(typeLazy,typeLazy)> funcLazy,function<typeNode(typeNode,typeLazy,int)> funcMerge)
	 : unitNode(unitNode), unitLazy(unitLazy), funcNode(funcNode),funcLazy(funcLazy),funcMerge(funcMerge) {
		for (length = 1,height = 0; length < vec.size(); length *= 2, height++);
		node.resize(2 * length, unitNode);
		lazy.resize(2 * length, unitLazy);
		for (int i = 0; i < vec.size(); ++i) node[i + length] = vec[i];
		for (int i = length - 1; i >= 0; --i) node[i] = funcNode(node[(i<<1)+0],node[(i<<1)+1]);
		width.resize(2 * length, 0);
		for(int i = length; i < 2*length; ++i) for(int j = i, k = 1; j && !width[j] ; j >>= 1,k <<= 1) width[j] = k;
	}

	//同じinitで初期化
	LazySegmentTree(const size_t num, const typeNode unitNode, const typeLazy unitLazy, const typeNode init, function<typeNode(typeNode,typeNode)> funcNode, function<typeLazy(typeLazy,typeLazy)> funcLazy,function<typeNode(typeNode,typeLazy,int)> funcMerge)
	 : unitNode(unitNode), unitLazy(unitLazy), funcNode(funcNode),funcLazy(funcLazy),funcMerge(funcMerge) {
		for (length = 1,height = 0; length < num; length *= 2, height++);
		node.resize(2 * length, unitNode);
		lazy.resize(2 * length, unitLazy);
		for (int i = 0; i < num; ++i) node[i + length] = init;
		for (int i = length - 1; i >= 0; --i) node[i] = funcNode(node[(i<<1)+0],node[(i<<1)+1]);
		width.resize(2 * length, 0);
		for(int i = length; i < 2*length; ++i) for(int j = i, k = 1; j && !width[j] ; j >>= 1,k <<= 1) width[j] = k;
	}

    //unitで初期化
	LazySegmentTree(const size_t num, const typeNode unitNode, const typeLazy unitLazy, function<typeNode(typeNode,typeNode)> funcNode, function<typeLazy(typeLazy,typeLazy)> funcLazy,function<typeNode(typeNode,typeLazy,int)> funcMerge)
	 : unitNode(unitNode), unitLazy(unitLazy), funcNode(funcNode),funcLazy(funcLazy),funcMerge(funcMerge) {
		for (length = 1,height = 0; length < num; length *= 2, height++);
		node.resize(2 * length, unitNode);
		lazy.resize(2 * length, unitLazy);
		width.resize(2 * length, 0);
		for(int i = length; i < 2*length; ++i) for(int j = i, k = 1; j && !width[j] ; j >>= 1,k <<= 1) width[j] = k;
	}


	void propagate(int k) {
		if(lazy[k] == unitLazy) return;
		node[k] = funcMerge(node[k],lazy[k],width[k]);
		if(k < length) lazy[2*k+0] = funcLazy(lazy[2*k+0],lazy[k]);
		if(k < length) lazy[2*k+1] = funcLazy(lazy[2*k+1],lazy[k]);
		lazy[k] = unitLazy;
    }


	//idx : 0-indexed
    void update(int a, int b, typeLazy x) {
		int l = a + length, r = b + length - 1;
		for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
		for(r++; l < r; l >>=1, r >>=1) {
			if(l&1) lazy[l] = funcLazy(lazy[l],x), propagate(l),l++;
			if(r&1) --r,lazy[r] = funcLazy(lazy[r],x), propagate(r);
		}
		l = a + length, r = b + length - 1;
		while ((l>>=1),(r>>=1),l) {
			if(lazy[l] == unitLazy) node[l] = funcNode(funcMerge(node[(l<<1)+0],lazy[(l<<1)+0],width[(l<<1)+0]),funcMerge(node[(l<<1)+1],lazy[(l<<1)+1],width[(l<<1)+1]));
			if(lazy[r] == unitLazy) node[r] = funcNode(funcMerge(node[(r<<1)+0],lazy[(r<<1)+0],width[(r<<1)+0]),funcMerge(node[(r<<1)+1],lazy[(r<<1)+1],width[(r<<1)+1]));
		}
    }

	//[l,r)
	typeNode get(int a, int b) {
		int l = a + length, r = b + length - 1;
		for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
		typeNode vl = unitNode, vr = unitNode;
		for(r++; l < r; l >>=1, r >>=1) {
			if(l&1) vl = funcNode(vl,funcMerge(node[l],lazy[l],width[l])),l++;
			if(r&1) r--,vr = funcNode(funcMerge(node[r],lazy[r],width[r]),vr);
		}
		return funcNode(vl,vr);
	}

	void print(){
		// cout << "height" << " " << height << endl;
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
		// cout << "width" << endl;
		// for(int i = 1,j = 1; i < 2*length; ++i) {
		// 	cout << width[i] << " ";
		// 	if(i==((1<<j)-1) && ++j) cout << endl;
		// }
		cout << "vector" << endl;
		cout << "{ " << get(0,1);
		for(int i = 1; i < length; ++i) cout << ", " << get(i,i+1);
		cout << " }" << endl;
	}

};

    // 区間加算 + 区間最小
	// function<ll(ll,ll)> funcNode  = [&](ll l,ll r){return min(l,r);};
	// function<ll(ll,ll)> funcLazy  = [&](ll l,ll r){return l+r;};
	// function<ll(ll,ll,int)> funcMerge = [&](ll l,ll r,int c){return l+r;};
	// LazySegmentTree<ll,ll> Seg(N,inf,0,0,funcNode,funcLazy,funcMerge);
    // verify https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_H

    // 区間更新 + 区間GCD
    // verify https://atcoder.jp/contests/abc125/tasks/abc125_c


    // 区間加算 + 区間総和
	// function<ll(ll,ll)> funcNode  = [&](ll l,ll r){return l+r;};
	// function<ll(ll,ll)> funcLazy  = [&](ll l,ll r){return r;};
	// function<ll(ll,ll,int)> funcMerge = [&](ll l,ll r,int c){return r!=-2000?r*c:l;};
	// LazySegmentTree<ll,ll> Seg(N,0,-2000,0,funcNode,funcLazy,funcMerge);
    // verify https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I

    // 区間更新 + 区間総和
    // function<ll(ll,ll)> funcNode  = [&](ll l,ll r){return l+r;};
    // function<ll(ll,ll)> funcLazy  = [&](ll l,ll r){return r;};
    // function<ll(ll,ll,int)> funcMerge = [&](ll l,ll r,int c){return r!=-2000?r*c:l;};
    // LazySegmentTree<ll,ll> Seg(N,0,-2000,0,funcNode,funcLazy,funcMerge);

    // 区間更新 + 区間最大
	// function<ll(ll,ll)> funcNode  = [&](ll l,ll r){return max(l,r);};
	// function<ll(ll,ll)> funcLazy  = [&](ll l,ll r){return r;};
	// function<ll(ll,ll,int)> funcMerge = [&](ll l,ll r,int c){return r!=0?r:l;};
	// LazySegmentTree<ll,ll> Seg(N+2,0,0,funcNode,funcLazy,funcMerge);
    //verify https://atcoder.jp/contests/nikkei2019-final/tasks/nikkei2019_final_d

    // 区間更新 + 区間最小
	// function<ll(ll,ll)> funcNode  = [&](ll l,ll r){return min(l,r);};
	// function<ll(ll,ll)> funcLazy  = [&](ll l,ll r){return r;};
	// function<ll(ll,ll,int)> funcMerge = [&](ll l,ll r,int c){return r!=0?r:l;};
	// LazySegmentTree<ll,ll> Seg(N,HIGHINF,0,funcNode,funcLazy,funcMerge);
    //verify https://atcoder.jp/contests/code-festival-2018-final/tasks/code_festival_2018_final_e

	// 区間加算　区間総和 mod
	// function<ll(ll,ll)> funcNode  = [&](ll l,ll r){return (l+r) % MOD;};
	// function<ll(ll,ll)> funcLazy  = [&](ll l,ll r){return (l+r) % MOD;};
	// function<ll(ll,ll,int)> funcMerge = [&](ll l,ll r,int c){return (l+(r*c) % MOD) % MOD;};
	// LazySegmentTree<ll,ll> dp(N+3,0,0,funcNode,funcLazy,funcMerge);
    //verify https://atcoder.jp/contests/code-festival-2018-quala/tasks/code_festival_2018_quala_d

    //matrix
    //verify https://codeforces.com/problemset/problem/1252/K
