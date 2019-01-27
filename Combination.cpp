#include <bits/stdc++.h>
using namespace std;

//Combination
class Combination {
public:
	vector<vector<long long>> num;
	
	Combination(int N):num (vector<vector<long long>>(N+1,vector<long long>(N+1,0))) {
		num[0][0] = 1;
		for (int i = 1; i <= N; ++i) for (int j = 0; j <= i; ++j) num[i][j] = ((j == 0) ? 0 : num[i - 1][j - 1]) + num[i - 1][j];		
	}
};

//verify 