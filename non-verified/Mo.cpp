template<class T> class Mo{
    unordered_map<long long,int> mp;
    long long N;
    int bucket;
    vector<pair<int,int>> range;
	vector<int> idx;
public:

    Mo(long long N, const vector<pair<int,int>>& range) : N(N),range(range),idx(range.size()),bucket(sqrt(N)) {
        iota(idx.begin(),idx.end(),0);
        sort(idx.begin(),idx.end(),[&](int a, int b){
            auto  al = range[a].first/bucket;
            auto  ar = range[a].second;
            auto  bl = range[b].first/bucket;
            auto  br = range[b].second;
            return (al != bl) ? (al < bl) : ((al%2)?(ar > br):(ar < br));
        });
    }
    
    //参照でvectorを渡したりすると良い
    void solve(){
        int l = 0, r = 0;
        for(int& i:idx){
            auto& xl = range[i].first;
            auto& xr = range[i].second;
            
            //左端を広げる
            while(xl < l){
                l--;
                extend(l);
            }
            //右端を広げる
            while(r < xr){
                r++;
                extend(r);
            }
            //左端を狭める
            while(l < xl){
                shrink(l);
                l++;
            }
            //右端を狭める
            while(xr < r){
                shrink(r);
                r--;
            }
            mp[xl*N+xr] = get();
        }
    }

    T operator [] (pair<int,int> p) {
        return mp[p.first*N+p.second];
    }

private:
    
    //伸びるとき
    void extend(int k){
    }

    //縮むとき
    void shrink(int k){
    }

    //クエリ結果
    T get(){
        return;
    }
};
