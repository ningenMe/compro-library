/*
 * @title LongestIncreasingSubsequence
 * @docs md/util/LongestIncreasingSubsequence.md
 */
template<class T> inline static int LongestIncreasingSubsequence(const vector<T> & ar, T inf=3e18) {
	vector<T> dp(ar.size(), inf);
	for (int i = 0; i < ar.size(); ++i) *lower_bound(dp.begin(),dp.end(), ar[i]) = ar[i];
	return distance(dp.begin(), lower_bound(dp.begin(), dp.end(), inf));
}
