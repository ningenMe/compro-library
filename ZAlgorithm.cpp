// O(N)
vector<int> ZAlgorithm(const string str) {
	int N = str.size();
	vector<int> res(N);
	for(int i = 1, j = 0; i < N; i++) {
		if(i + res[i - j] < j + res[j]) {
			res[i] = res[i - j];
		} 
		else {
			int k = max(0, j + res[j] - i);
			while(i + k < N && str[k] == str[i + k]) ++k;
			res[j = i] = k;
		}
	}
	res[0] = N;
	return res;
}
//verify https://atcoder.jp/contests/abc135/tasks/abc135_f