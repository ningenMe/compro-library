
//O(N) N: vec.size();
template<class T> vector<T> SlideMost(vector<T>& vec, const int& width, function<int(T,T)> funcCompare){
    vector<T> res(vec.size());
    deque<T> deq;
    for(int i = 0; i < vec.size(); ++i) {
        while(deq.size() && funcCompare(vec[deq.back()],vec[i]) ) deq.pop_back();
        deq.push_back(i);
        res[i] = vec[deq.front()];
        if(i+1>=width && deq.front()==i+1-width) deq.pop_front();
    }
    return res;
}

	// auto Amax = SlideMost<int>(A,K,[&](ll l,ll r){return l <= r;});
	// auto Amin = SlideMost<int>(A,K,[&](ll l,ll r){return l >= r;});

//verify https://atcoder.jp/contests/cf16-tournament-round3-open/tasks/asaporo_d
//verify https://atcoder.jp/contests/agc038/tasks/agc038_b