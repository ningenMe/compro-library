
//Prime Factorization O(sqrt(N))
vector<pair<long long,long long>> PrimeFactorization(long long N) {
    vector<pair<long long,long long>> ret;
    if (N == 1) ret.push_back({1,0});
    for (long long i = 2,M = N; i*i <= M; ++i) {
        if (N%i == 0) {
            long long cnt = 0;
            while (N%i == 0) N /= i, cnt++;
            ret.push_back({i,cnt});
        }
    }
    if (N != 1) ret.push_back({N,1});
    return ret;
}
