#include <bits/stdc++.h>
using namespace std;

//Longest Increasing Subsequence O(NlogN)
template<class T> int Longest_Increasing_Subsequence(const vector<T> & ar, T inf) {
	vector<T> dp(ar.size(), inf);
	for (int i = 0; i < ar.size(); ++i) *lower_bound(dp.begin(),dp.end(), ar[i]) = ar[i];
	return distance(dp.begin(), lower_bound(dp.begin(), dp.end(), inf));
}

//verify https://atcoder.jp/contests/abc006/tasks/abc006_4