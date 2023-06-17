/*
 * @title Eratosthenes - エラトステネスの篩
 * @docs md/math/Eratosthenes.md
 */
class Eratosthenes {
    unsigned int sz;
public:
    vector<unsigned int> sieve;
    vector<long long> prime;
    Eratosthenes(unsigned int N):sz(N+1),sieve(N+1, 1) {
        sieve[0]=sieve[1]=0;
        for(int i=1; i <= N/i; ++i) if(sieve[i]) for(int j=2*i;j<=N;j+=i) sieve[j]=0;
        for(int i=1; i <= N  ; ++i) if(sieve[i]) prime.push_back(i);
    }
    size_t size() const {
        return sz;
    }
};
