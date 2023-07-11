/*
 * @title StaticRangeModeQuery - 静的区間最頻値クエリ
 * @docs md/static-range-query/StaticRangeModeQuery.md
 */
template<class T> class StaticRangeModeQuery {
    vector<size_t> compressed;
    vector<T> origin;
    vector<vector<size_t>> sqrt_bucket_freq;
    vector<vector<size_t>> sqrt_bucket_mode;
    vector<vector<size_t>> idx;
    vector<int> pos;
    size_t N,B;
public:
    StaticRangeModeQuery(const vector<T>& ar, T pre=-1)
            : compressed(ar.size()), origin(ar.size()), idx(ar.size()), pos(ar.size()) {
        N = ar.size();
        B = sqrt(N) + 1;
        //zarts
        {
            vector<pair<T,size_t>> ord(N);
            for(size_t i=0;i<N;++i) ord[i]={ar[i],i};
            sort(ord.begin(),ord.end());
            int inc=-1;
            for(size_t i=0;i<N;++i) {
                if(pre < ord[i].first) inc++;
                compressed[ord[i].second] = inc;
                pre = ord[i].first;
            }
            for(size_t i=0;i<N;++i) origin[compressed[i]] = ar[i];
        }
        //sqrt bucket
        {
            sqrt_bucket_freq.resize(B+1,vector<size_t>(B+1));
            sqrt_bucket_mode.resize(B+1,vector<size_t>(B+1));
            for(size_t bl=0;bl*B<=N;++bl) {
                vector<size_t> tmp(N,0);
                size_t maxi_freq = 0;
                size_t maxi_mode = 0;
                for(size_t br = bl+1; br*B<=N;++br) {
                    size_t l = (br-1)*B, r = br*B;
                    for(size_t i=l;i<r;++i) {
                        size_t a = compressed[i];
                        ++tmp[a];
                        if(maxi_freq < tmp[a]) {
                            maxi_freq = tmp[a];
                            maxi_mode = a;
                        }
                    }
                    sqrt_bucket_freq[bl][br] = maxi_freq;
                    sqrt_bucket_mode[bl][br] = maxi_mode;
                }
            }
        }
        //idx,pos
        {
            for(size_t i=0;i<N;++i) {
                const size_t& key = compressed[i];
                pos[i] = idx[key].size();
                idx[key].push_back(i);
            }
        }
    }
    //query [l,r)
    //return {freq,mode} ({頻度,元の配列における値})
    pair<size_t,T> get(int l, int r) {
        int bl = l / B + !!(l%B), br = r / B;
        int ml = bl * B, mr = br * B;
        ml = min(ml,r); mr = max(l,mr);
        size_t maxi_freq = sqrt_bucket_freq[bl][br];
        size_t maxi_mode = sqrt_bucket_mode[bl][br];
        for(int i = l; i < ml; ++i) {
            const size_t& key = compressed[i];
            int freq = maxi_freq;
            for(int j = pos[i] + freq; j < idx[key].size(); ++j) {
                if(idx[key][j] < r) {
                    maxi_freq = j - pos[i] + 1;
                    maxi_mode = key;
                }
                else break;
            }
        }
        for(int i = r-1; mr <= i; --i) {
            const size_t& key = compressed[i];
            int freq = maxi_freq;
            for(int j = pos[i] - freq; 0 <= j; --j) {
                if(l <= idx[key][j]) {
                    maxi_freq = pos[i] - j + 1;
                    maxi_mode = key;
                }
                else break;
            }
        }
        return {maxi_freq,origin[maxi_mode]};
    }
};