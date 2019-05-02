#include <bits/stdc++.h>
using namespace std;

string Longest_Common_Subsequence(const string& S, const string& T){
	int N = S.size(), M = T.size();
	vector<vector<int>> ar(N+1,vector<int>(M+1,0));
    for(size_t i = 0; i < N; i++)
    for(size_t j = 0; j < M; j++)
    ar[i+1][j+1] = (S[i] == T[j] ? ar[i][j] + 1 : max(ar[i][j + 1],ar[i + 1][j]) );

	string res = "";
	while(ar[N][M]>0){
		if(S[N-1]==T[M-1]){
			res.push_back(S[N-1]);
			N--,M--;
		}
		else{
			(ar[N-1][M]>ar[N][M-1]?N:M)--;
		}
	}

    reverse(res.begin(),res.end());
	return res;
}
//verify https://atcoder.jp/contests/dp/tasks/dp_f