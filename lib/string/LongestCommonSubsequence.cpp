/*
 * @title LongestCommonSubsequence - LCS
 * @docs md/string/LongestCommonSubsequence.md
 */
string LongestCommonSubsequence(const string& S, const string& T){
	int N = S.size(), M = T.size();
	vector<int> dp((N+1)*(M+1),0);
    for(size_t i = 0; i < N; i++) {
        for(size_t j = 0; j < M; j++) {
            dp[(i+1)*(M+1)+j+1] = (S[i] == T[j] ? dp[i*(M+1)+j] + 1 : max(dp[i*(M+1)+j + 1],dp[(i+1)*(M+1)+j]) );
        }
    }
    int a=N,b=M;
	string res = "";
	while(dp[a*(M+1)+b]>0) {
		if(S[a-1]==T[b-1]) res.push_back(S[a-1]),a--,b--;
		else (dp[(a-1)*(M+1)+b]>dp[a*(M+1)+b-1]?a:b)--;
	}
    reverse(res.begin(),res.end());
	return res;
}
