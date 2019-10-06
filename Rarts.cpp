
vector<pair<char,long long>> Rarts(string S){
	S = S + ".";
	int cnt = 1;
	vector<pair<char,long long>> res;
 	for(int i = 0; i+1 < S.size(); ++i){
		 if(S[i]==S[i+1]) {
			 cnt++;
		 }
		 else{
			 res.push_back({S[i],cnt});
			 cnt = 1;
		 }
	}
	return res;
}

//verify https://atcoder.jp/contests/agc039/tasks/agc039_a