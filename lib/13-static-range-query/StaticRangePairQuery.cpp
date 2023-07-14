/*
 * @title StaticRangePairQuery - 静的区間pairクエリ
 * @docs md/static-range-query/StaticRangePairQuery.md
 */
template<class T> class StaticRangePairQuery {
    vector<int> compressed;
    vector<vector<size_t>> sqrt_bucket_count;
    vector<vector<int>> acc;
    size_t length,bucket_size,val_size,pair_size;
    vector<size_t> tmp;
public:
    StaticRangePairQuery(const vector<T>& ar, const size_t pair_size, T pre=-1) : compressed(ar.size()), pair_size(pair_size) {
        length = ar.size();
        bucket_size = sqrt(length) + 1;
        //zarts
        {
            vector<pair<T,size_t>> ord(length);
            for(size_t i=0;i<length;++i) ord[i]={ar[i],i};
            sort(ord.begin(),ord.end());
            int inc=-1;
            for(size_t i=0;i<length;++i) {
                if(pre < ord[i].first) inc++;
                compressed[ord[i].second] = inc;
                pre = ord[i].first;
            }
            val_size = inc + 1;
            tmp.resize(val_size);
        }
        //sqrt bucket
        {
            sqrt_bucket_count.resize(bucket_size+1,vector<size_t>(bucket_size+1));
            for(size_t l = 0; l < length; l += bucket_size) {
                for(size_t i = 0; i < val_size; ++i) tmp[i]=0;

                size_t bl = l/bucket_size;
                for(size_t r = l; r < length; ++r) {
                    int val=compressed[r];
                    tmp[val]++;
                    if(tmp[val]==pair_size) {
                        tmp[val]=0;
                        size_t br = r/bucket_size + 1;
                        sqrt_bucket_count[bl][br]++;
                    }
                }
                for(size_t r = l+bucket_size; r < length; r += bucket_size) {
                    size_t br = r/bucket_size + 1;
                    sqrt_bucket_count[bl][br] += sqrt_bucket_count[bl][br-1];
                }
            }
            //queryで使い回すから0にしておく
            for(size_t i = 0; i < val_size; ++i) tmp[i]=0;
        }
        
        //acc
        {
            acc.resize(val_size, vector<int>(bucket_size+1, 0));
            for(size_t i = 0; i < length; ++i) acc[compressed[i]][i/bucket_size + 1]++;
            for(size_t i = 0; i < val_size; ++i) {
                for(size_t j = 0; j+1 < bucket_size+1; ++j) acc[i][j+1] += acc[i][j];
            }
        }
    }
    //[l,r) におけるA[i]のペアの数
    int get(int l, int r) {
        stack<size_t> st;
        int res = 0;

        //naive
        if(r - l <= bucket_size) {
            for(int i = l; i < r; ++i) {
                size_t val = compressed[i];
                st.push(val);
                tmp[val]++;
                if(tmp[val]==pair_size) {
                    tmp[val]=0;
                    res++;
                }
            }
            while(st.size()) {
                auto val = st.top(); st.pop();
                tmp[val]=0;
            }
            return res;
        }

        int bl = l/bucket_size + !!(l%bucket_size), br = r/bucket_size;

        int ml = bl * bucket_size, mr = br * bucket_size;
        ml = min(ml,r); mr = max(l,mr);
        res += sqrt_bucket_count[bl][br];    

        //左側の探索
        for(int i = l; i < ml; ++i) {
            size_t val = compressed[i];
            st.push(val);
            tmp[val]++;
            if(tmp[val]==pair_size) {
                tmp[val]=0;
                res++;
            }
        }
        //右側の探索
        for(int i = mr; i < r; ++i) {
            size_t val = compressed[i];
            st.push(val);
            tmp[val]++;
            if(tmp[val]==pair_size) {
                tmp[val]=0;
                res++;
            }
        }
        //余ってるものと、[ml,mr) で探索
        while(st.size()) {
            auto val = st.top(); st.pop();
            if(tmp[val]==0) continue;
            int cnt = (acc[val][br] - acc[val][bl]) % pair_size;
            //合計がpair_size以上なら、余ってるからインクリメント
            if(cnt + tmp[val] >= pair_size) res++;
            tmp[val]=0;
        }

        return res;
    }
};