/*
 * @title MaximumRectangle - 最大長方形
 * @docs md/optimize/MaximumRectangle.md
 */
long long MaximumRectangle(vector<long long> ar){
	ar.push_back(0);
	stack<pair<long long,long long>> st;
	long long res = 0;
	for(long long r = 0; r < ar.size(); ++r){
		long long vr = ar[r];		
		while(st.size() && st.top().first > vr) {
			auto [vl, l] = st.top(); st.pop();
			res = max(res,vl*(r - l));
		}
		if(st.empty() || (st.size() && st.top().first < vr)) st.push({vr,r});
	}
	return res;
}
