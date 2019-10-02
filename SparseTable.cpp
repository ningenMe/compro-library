
template<class T> class SparseTable{
public:
	vector<vector<T>> node;
	vector<int> idx;
	function<T(T,T)> funcNode;

	SparseTable(const vector<T>& vec, function<T(T,T)>funcNode) : funcNode(funcNode) {
		int bit = 0, N = vec.size();
		for(;(1<<bit)<=vec.size();++bit);
		node.resize(bit,vector<T>(1<<bit));
		for(int i = 0; i < N; ++i) node[0][i] = vec[i];
		for(int i = 1; i < bit; ++i) for(int j = 0; j + (1<<i) < (1<<bit); ++j) node[i][j] = funcNode(node[i-1][j],node[i-1][j + (1 << (i-1))]);
		idx.resize(N+1);
		for(int i = 2; i < N+1; ++i) idx[i] = idx[i>>1] + 1;
	}

	//[l,r)
	T get(int l,int r) {
		int bit = idx[r-l];
		return funcNode(node[bit][l],node[bit][r - (1<<bit)]);
	}
};

//verify https://atcoder.jp/contests/joi2016ho/tasks/joi2016ho_a

	// function<ll(ll,ll)> funcNode1 = [&](ll l,ll r){return min(l,r);};
	// function<ll(ll,ll)> funcNode2 = [&](ll l,ll r){return max(l,r);};
	// SparseTable<ll> stMin(A,funcNode1),stMax(A,funcNode2);
