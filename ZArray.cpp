
// O(N)
template<class T> vector<int> ZArray(const vector<T> arr) {
	int N = arr.size();
	vector<int> res(N);
	for(int i = 1, j = 0; i < N; i++) {
		if(i + res[i - j] < j + res[j]) {
			res[i] = res[i - j];
		} 
		else {
			int k = max(0, j + res[j] - i);
			while(i + k < N && arr[k] == arr[i + k]) ++k;
			res[j = i] = k;
		}
	}
	res[0] = N;
	return res;
}
//verify https://atcoder.jp/contests/abc150/tasks/abc150_f