#include <bits/stdc++.h>
using namespace std;

int Longest_Common_Subsequence_Size(const string& S, const string& T){
	vector<vector<int>> res(S.size()+1,vector<int>(T.size()+1,0));
    for(size_t i = 0; i < S.size(); i++)
    for(size_t j = 0; j < T.size(); j++)
    res[i+1][j+1] = (S[i] == T[j] ? res[i][j] + 1 : max(res[i][j + 1],res[i + 1][j]) );
    return res[S.size()][T.size()];
}

//verify https://atcoder.jp/contests/iroha2019-day2/tasks/iroha2019_day2_a