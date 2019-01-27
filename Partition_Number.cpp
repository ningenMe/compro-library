#include <bits/stdc++.h>
using namespace std;

//Partition_Number
class Partition_Number {
public:
	vector<vector<long long>> num;	//nをk個に分ける分割数
	Partition_Number(int N, int K, long long mod) :num(vector<vector<long long>>(N + 1, vector<long long>(K + 1, 0))) {
		num[0][0] = 1;
		for (int i = 0; i <= N; ++i) for (int j = 1; j <= K; ++j) num[i][j] = (num[i][j - 1] + ((i >= j) ? num[i - j][j] : 0)) % mod;
	}
};


//verify https://atcoder.jp/contests/dwacon2018-prelims/tasks/dwacon2018_prelims_c