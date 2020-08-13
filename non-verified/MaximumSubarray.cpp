template<class T> vector<T> MaximumSubarray(const vector<T>& vec, T unit=0) {
	assert(!vec.empty());
	vector<T> dp(vec.size());
	dp[0] = max(vec[0],unit);
	for(int i = 1; i < vec.size(); ++i) dp[i] = max(dp[i-1]+vec[i],unit);
	return dp;
}