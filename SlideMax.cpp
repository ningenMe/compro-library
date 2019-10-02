
//O(N) N: vec.size();
template<class T> vector<T> SlideMax(vector<T>& vec, const int& width){
    vector<T> res(vec.size());
    deque<T> deq;
    for(int i = 0; i < vec.size(); ++i) {
        while(deq.size() && vec[deq.back()]<=vec[i]) deq.pop_back();
        deq.push_back(i);
        res[i] = vec[deq.front()];
        if(i+1>=width && deq.front()==i+1-width) deq.pop_front();
    }
    return res;
}

//O(N) N: vec.size();
template<class T> vector<T> SlideMin(vector<T>& vec, const int& width){
    vector<T> res(vec.size());
    deque<T> deq;
    for(int i = 0; i < vec.size(); ++i) {
        while(deq.size() && vec[deq.back()]>=vec[i]) deq.pop_back();
        deq.push_back(i);
        res[i] = vec[deq.front()];
        if(i+1>=width && deq.front()==i+1-width) deq.pop_front();
    }
    return res;
}

//verify https://atcoder.jp/contests/cf16-tournament-round3-open/tasks/asaporo_d
