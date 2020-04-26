class RollingHash {
private:
    long long base1,base2;
    long long mod1,mod2;
    vector<long long> hash1,hash2,pow1,pow2;
 
public: 
    RollingHash(const string& S) : base1(1009), base2(1007), mod1(1000000007), mod2(1000000009) {
        int N = S.size();
        hash1.resize(N+1,0);
        hash2.resize(N+1,0);
        pow1.resize(N+1,1);
        pow2.resize(N+1,1);
 
        for(int i=1; i<=N; ++i) {
            hash1[i] = ((hash1[i-1]+S[i-1]) * base1) % mod1;
            hash2[i] = ((hash2[i-1]+S[i-1]) * base2) % mod2;
            pow1[i] = (pow1[i-1] * base1) % mod1;
            pow2[i] = (pow2[i-1] * base2) % mod2;
        }
    }

	//[l,r)
    pair<long long, long long> get(int l,int r) {
        long long t1 = ((hash1[r] - hash1[l] * pow1[r-l]) % mod1 + mod1) % mod1;
        long long t2 = ((hash2[r] - hash2[l] * pow2[r-l]) % mod2 + mod2) % mod2;
        return {t1,t2};
    }
};

//verify
//https://atcoder.jp/contests/abc141/tasks/abc141_e