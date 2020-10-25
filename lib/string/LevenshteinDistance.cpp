/*
 * @title LevenshteinDistance - 編集距離
 * @docs md/util/LevenshteinDistance.md
 */
int LevenshteinDistance(string S, string T,char dummy='#') {
    int N = S.size();
    int M = T.size();
    S.push_back(dummy);T.push_back(dummy);
    vector<vector<int>> dp(N+2, vector<int>(M+2,N+M));
    dp[0][0]=0;
    for(int i=0;i<=N;++i) {
        for(int j=0;j<=M;++j) {
            //change
            dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j]+(S[i]!=T[j]));            
            //delete
            dp[i+1][j]   = min(dp[i+1][j],dp[i][j]+1);            
            //insert
            dp[i][j+1]   = min(dp[i][j+1],dp[i][j]+1);            
        }
    }
    return dp[N][M];
}