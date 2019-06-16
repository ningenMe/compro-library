class BinaryIndexedTree2DRangeModSumQuery{
public:
    const int N,M;
    const long long mod;
    vector<vector<long long>> bit;
 
    //1-indexed
    BinaryIndexedTree2DRangeModSumQuery(const int& N,const int& M, const long long& mod):N(N),M(M),mod(mod),bit(N+1,vector<long long>(M+1,0)){
        // do nothing
    }
 
    inline long long getvar(const int& i,const int& j){
        long long val = 0;
        for(int y=i;y>0;y-=(y&-y)) for(int x=j;x>0;x-=(x&-x)) {
            val += bit[y][x];
            if(val >= mod) val -= mod;
        }
        return val;
    }
 
    // [x1,x2] * [y1,y2] 1-indexed
    inline long long getvar(const int& y1,const int& y2,const int& x1,const int& x2){
        long long res = getvar(y1-1,x1-1);
        res -= getvar(y1-1,x2);
        if(res < 0) res += mod;
        res -= getvar(y2,x1-1);
        if(res < 0) res += mod;
        res += getvar(y2,x2);
        if(res >= mod) res -= mod;
        return res;
    }
 
    //add
    inline void update(const int& i,const int& j,long long val){
        if(i==0||j==0) return;
        if(val>=mod) val -= mod;
        if(val < 0) val += mod;
        for(int y=i;y<=N;y+=(y&-y)) for(int x=j;x<=M;x+=(x&-x)) {
            bit[y][x]+=val;
            if(bit[y][x] >= mod) bit[y][x] -= mod;
        }
    }
 
};

//verify https://atcoder.jp/contests/abc130/tasks/abc130_e