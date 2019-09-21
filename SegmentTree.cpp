template<class T> class SegmentTree {
	size_t length; //セグメント木の最下段の要素の数(vectorの要素の数を超える2べきの数)
	T init;         //各ノードの初期値
	vector<T> node; //ノード
	function<T(T,T)> func;

public:
	//vectorで初期化
	SegmentTree(const vector<T> & vec, const T init, function<T(T,T)> func) : init(init), func(func) {
		for (length = 1; length < vec.size(); length *= 2);
		node.resize(2 * length, init);
		for (int i = 0; i < vec.size(); ++i) node[i + length] = vec[i];
		for (int i = length - 1; i >= 0; --i) node[i] = func(node[(i<<1)+0],node[(i<<1)+1]);
	}
 
	//lengthだけで初期化
	SegmentTree(const size_t num, const T init, function<T(T,T)> func) : init(init), func(func) {
		for (length = 1; length < num; length *= 2);
		node.resize(2 * length, init);
	}
	
	//idx : 0-indexed
	void update(size_t idx, const T var) {
		if(idx < 0 || length <= idx) return;
		idx += length;
		node[idx] = var;
		while(idx >>= 1) node[idx] = func(node[(idx<<1)+0],node[(idx<<1)+1]);
	}

	//idx : 0-indexed
	void add(size_t idx, const T var) {
		if(idx < 0 || length <= idx) return;
		idx += length;
		node[idx] += var;
		while(idx >>= 1) node[idx] = func(node[(idx<<1)+0],node[(idx<<1)+1]);
	}

	//[l,r)
	T get(int l, int r) {
		if (l < 0 || length <= l || r < 0 || length < r) return init;
		T vl = init, vr = init;
		for(l += length, r += length; l < r; l >>=1, r >>=1) {
			if(l&1) vl = func(vl,node[l++]);
			if(r&1) vr = func(vr,node[--r]);
		}
		return func(vl,vr);
	}
 
	void print(){
		cout << "{ " << get(0,1);
		for(int i = 1; i < length; ++i) cout << ", " << get(i,i+1);
		cout << " }" << endl;

		for(int i = 1,j = 1; i < 2*length; ++i) {
			cout << node[i] << " ";
			if(i==((1<<j)-1) && ++j) cout << endl;
		}
	}

};

//GCD
//verify https://atcoder.jp/contests/abc125/tasks/abc125_c

//SUM
//verify https://atcoder.jp/contests/arc077/tasks/arc077_c

//NIN
//verify https://atcoder.jp/contests/bitflyer2018-final-open/tasks/bitflyer2018_final_c

//NAX
//verify https://atcoder.jp/contests/wupc2019/tasks/wupc2019_d