
template<class T> class LazySegmentTree {
	size_t length;               //セグメント木の最下段の要素の数(vectorの要素の数を超える2べきの数)
	size_t height;               //セグメント木の高さ 
	T unitNode;                  //nodeの単位元
	T unitLazy;                  //lazyの単位元
	vector<T> node;              //node
	vector<T> lazy;              //lazy
	vector<int> width;           //width
	function<T(T,T)> funcNode;   //node同士の演算
	function<T(T,T)> funcLazy;   //lazy同士の演算
	function<T(T,T)> funcMerge;  //nodeとlazyの演算
	function<T(T,T)> funcRange;  //lazyの区間処理の演算

public:
	//vectorで初期化
	LazySegmentTree(const vector<T> & vec, const T unitNode, const T unitLazy, function<T(T,T)> funcNode, function<T(T,T)> funcLazy,function<T(T,T)> funcMerge, function<T(T,T)> funcRange)
	 : unitNode(unitNode), unitLazy(unitLazy), funcNode(funcNode),funcLazy(funcLazy),funcMerge(funcMerge), funcRange(funcRange) {
		for (length = 1,height = 0; length < vec.size(); length *= 2, height++);
		node.resize(2 * length, unitNode);
		lazy.resize(2 * length, unitLazy);
		for (int i = 0; i < vec.size(); ++i) node[i + length] = vec[i];
		for (int i = length - 1; i >= 0; --i) node[i] = funcNode(node[(i<<1)+0],node[(i<<1)+1]);
		width.resize(2 * length, 0);
		for(int i = length; i < 2*length; ++i) for(int j = i, k = 1; j && !width[j] ; j >>= 1,k <<= 1) width[j] = k;
	}

	//同じinitで初期化
	LazySegmentTree(const size_t num, const T unitNode, const T unitLazy, const T init, function<T(T,T)> funcNode, function<T(T,T)> funcLazy,function<T(T,T)> funcMerge, function<T(T,T)> funcRange)
	: unitNode(unitNode), unitLazy(unitLazy), funcNode(funcNode),funcLazy(funcLazy),funcMerge(funcMerge), funcRange(funcRange) {
		for (length = 1,height = 0; length < num; length *= 2, height++);
		node.resize(2 * length, unitNode);
		lazy.resize(2 * length, unitLazy);
		for (int i = 0; i < num; ++i) node[i + length] = init;
		for (int i = length - 1; i >= 0; --i) node[i] = funcNode(node[(i<<1)+0],node[(i<<1)+1]);
		width.resize(2 * length, 0);
		for(int i = length; i < 2*length; ++i) for(int j = i, k = 1; j && !width[j] ; j >>= 1,k <<= 1) width[j] = k;
	}
 
	//unitだけで初期化
	LazySegmentTree(const size_t num, const T unitNode, const T unitLazy, function<T(T,T)> funcNode, function<T(T,T)> funcLazy,function<T(T,T)> funcMerge, function<T(T,T)> funcRange)
	: unitNode(unitNode), unitLazy(unitLazy), funcNode(funcNode),funcLazy(funcLazy),funcMerge(funcMerge), funcRange(funcRange) {
		for (length = 1,height = 0; length < num; length *= 2, height++);
		node.resize(2 * length, unitNode);
		lazy.resize(2 * length, unitLazy);
		width.resize(2 * length, 0);
		for(int i = length; i < 2*length; ++i) for(int j = i, k = 1; j && !width[j] ; j >>= 1,k <<= 1) width[j] = k;
	}


	void propagate(int k) {
		if(lazy[k] == unitLazy) return;
		node[k] = funcMerge(node[k],funcRange(lazy[k],width[k]));
		if(k < length) lazy[2*k+0] = funcLazy(lazy[2*k+0],lazy[k]);
		if(k < length) lazy[2*k+1] = funcLazy(lazy[2*k+1],lazy[k]);
		lazy[k] = unitLazy;
    }


	//idx : 0-indexed
    void update(int a, int b, T x) {
		int l = a + length, r = b + length - 1;
		for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
		for(r++; l < r; l >>=1, r >>=1) {
			if(l&1) lazy[l] = funcLazy(lazy[l],x), propagate(l),l++;
			if(r&1) --r,lazy[r] = funcLazy(lazy[r],x), propagate(r);
		}
		l = a + length, r = b + length - 1;
		while ((l>>=1),(r>>=1),l) {
			if(lazy[l] == unitLazy) node[l] = funcNode(funcMerge(node[(l<<1)+0],funcRange(lazy[(l<<1)+0],width[(l<<1)+0])),funcMerge(node[(l<<1)+1],funcRange(lazy[(l<<1)+1],width[(l<<1)+1])));
			if(lazy[r] == unitLazy) node[r] = funcNode(funcMerge(node[(r<<1)+0],funcRange(lazy[(r<<1)+0],width[(r<<1)+0])),funcMerge(node[(r<<1)+1],funcRange(lazy[(r<<1)+1],width[(r<<1)+1])));
		}
    }

	//[l,r)
	T get(int a, int b) {
		int l = a + length, r = b + length - 1;
		for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
		T vl = unitNode, vr = unitNode;
		for(r++; l < r; l >>=1, r >>=1) {
			if(l&1) vl = funcNode(vl, funcMerge( node[l] , funcRange(lazy[l],width[l]) ) ),l++;
			if(r&1) r--,vr = funcNode(vr, funcMerge( node[r] , funcRange(lazy[r],width[r]) ) );
		}
		return funcNode(vl,vr);
	}

	void print(){
		cout << "height" << " " << height << endl;
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
		cout << "vector" << endl;
		cout << "{ " << get(0,1);
		for(int i = 1; i < length; ++i) cout << ", " << get(i,i+1);
		cout << " }" << endl;
	}

};

// 区間加算 + 区間最小
// function<ll(ll,ll)> funcNode  = [&](ll l,ll r){return min(l,r);};
// function<ll(ll,ll)> funcMerge = [&](ll l,ll r){return l+r;};
// function<ll(ll,ll)> funcLazy  = [&](ll l,ll r){return l+r;};
// function<ll(ll,ll)> funcRange = [&](ll l,ll r){return l;};
// LazySegmentTree<ll> Seg(N,inf,0,funcNode,funcLazy,funcMerge,funcRange);