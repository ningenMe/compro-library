vector<long long> NBase(long long X,long long N) {
    assert(abs(N)>1);
    vector<long long> res;
    while(1) {
        long long b = (X%abs(N)+abs(N)) % abs(N);
        res.push_back(b);
        (X -= b) /= N;
        if(X==0) break;
    }
    return res;
}