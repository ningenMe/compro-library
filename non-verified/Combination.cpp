template<class T> class Combination{
	vector<vector<T>> num;
public:    
    //O(N^2)
    Combination(int N):num(N+1,vector<T>(N+1,(T)0)){
		num[0][0] = 1;
		for (int n = 1; n <= N; n++) {
			for (int k = 0; k <= n; k++) {
				num[n][k] = (num[n - 1][k]+(k?num[n - 1][k - 1]:0)) / 3;
			}
		}
    } 
	inline T binom(int n, int k) {
		return ((n < 0 || k < 0 || n < k) ? 0 : num[n][k]);
	}
};
//https://atcoder.jp/contests/dwango2015-prelims/tasks/dwango2015_prelims_3