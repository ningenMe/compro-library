/*
 * @title Quotient - 商の集合
 * @docs md/math/Quotient.md
 */
inline static vector<pair<long long,long long>> Quotient(long long n) {
    assert(n > 0);
    long long b = sqrtl(n);
    long long l = b;
    while(n / l != b) ++l;
    vector<pair<long long,long long>> res = {{0,0}};
    for(long long i = 1; i <= l; ++i) {
        long long k = n / i;
        if(res.back().first == k) res.back().second++;
        else res.emplace_back(k,1);
    }
    for(long long i = b, r; 1 <= i; --i, l = r+1) {
        r = n / i;
        long long k = n / l;
        if(res.back().first == k) res.back().second = (r-l+1);
        else res.emplace_back(k,r-l+1);
    }
    reverse(res.begin(),res.end());
    res.pop_back();
    return res;
}