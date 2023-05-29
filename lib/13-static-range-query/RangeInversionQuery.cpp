/*
 * @title RangeInversionQuery - 区間転倒数
 * @docs md/static-range-query/RangeInversionQuery.md
 */
template<class T> class RangeInversionQuery {
    vector<size_t> compressed;
    vector<long long> prefix_inv;
    vector<long long> suffix_inv;
    vector<vector<long long>> sqrt_bucket_freq;
    vector<long long> sqrt_bucket_inv;
    vector<vector<size_t>> sqrt_bucket_sort_index;
    vector<long long> sqrt_bucket_size;
    size_t N,B,M;
public:
    RangeInversionQuery(const vector<T>& ar, T pre=-1)
            : compressed(ar.size()),prefix_inv(ar.size()),suffix_inv(ar.size()) {
        N = ar.size();
        B = sqrt(N) + 1; // bucket size
        M = N / B + 1;   // bucket num
        //zarts
        {
            vector<pair<T,size_t>> ord(N);
            for(size_t i=0;i<N;++i) ord[i]={ar[i],i};
            sort(ord.begin(),ord.end());
            size_t inc=0;
            for(size_t i=0;i<N;++i) {
                if(pre < ord[i].first) inc++;
                compressed[ord[i].second] = inc;
                pre = ord[i].first;
            }
        }
        //freq
        {
            sqrt_bucket_freq.resize(M);
            vector<long long> freq(N+1,0);
            for(size_t i=0;i<M;++i) {
                size_t l = i*B, r = min((i+1)*B,N);
                for(size_t j=l;j<r;++j) freq[compressed[j]]++;
                sqrt_bucket_freq[i] = freq;
                for(size_t j=1;j<=N;++j) sqrt_bucket_freq[i][j]+=sqrt_bucket_freq[i][j-1];
            }
        }
        //prefix,suffix inv
        {
            BinaryIndexedTree<AbelPrefixSumPointAdd<long long>> bit(N+1);
            for(size_t i=0;i<M;++i) {
                int l = i*B, r = min((i+1)*B,N);
                //prefix
                {
                    long long inv = 0;
                    for(size_t j=l;j<r;++j) {
                        inv += bit.fold(N+1)-bit.fold(compressed[j]+1);
                        prefix_inv[j]=inv;
                        bit.operate(compressed[j],1);
                    }
                    for(size_t j=l;j<r;++j) {
                        bit.operate(compressed[j],-1);
                    }
                }
                //suffix
                {
                    long long inv = 0;
                    for(int j=r-1;l<=j;--j) {
                        inv += bit.fold(compressed[j]);
                        suffix_inv[j]=inv;
                        bit.operate(compressed[j],1);
                    }
                    for(size_t j=l;j<r;++j) {
                        bit.operate(compressed[j],-1);
                    }
                }
            }
        }
        //sqrt bucket inv
        {
            sqrt_bucket_inv.resize(M*M,0);
            for(size_t i=0;i<M;++i) {
                size_t l = i*B, r = min((i+1)*B,N);
                if(l<r) sqrt_bucket_inv[i*M+i] = prefix_inv[r-1];
            }
            for(size_t k=1;k<M;++k) {
                for(size_t i=0;i+k<M;++i) {
                    sqrt_bucket_inv[i*M+i+k] += sqrt_bucket_inv[i*M+i]+sqrt_bucket_inv[(i+1)*M+i+k];
                    size_t l = i*B, r = min((i+1)*B,N);
                    for(size_t j=l;j<r;++j) {
                        size_t& c = compressed[j];
                        sqrt_bucket_inv[i*M+i+k] += (sqrt_bucket_freq[i+k][c-1]-sqrt_bucket_freq[i][c-1]);
                    }
                }
            }
        }
        //sort
        {
            sqrt_bucket_sort_index.resize(M);
            sqrt_bucket_size.resize(M,0);
            size_t sz = 0;
            for(size_t i=0;i<M;++i) {
                int l = i*B, r = min((i+1)*B,N);
                sz += max(0,(r-l));
                sqrt_bucket_size[i] = sz;
                if(r-l<1) continue;
                sqrt_bucket_sort_index[i].resize(r-l);
                for(size_t j=l;j<r;++j) sqrt_bucket_sort_index[i][j-l]=j;
                sort(sqrt_bucket_sort_index[i].begin(),sqrt_bucket_sort_index[i].end(),
                     [&](size_t l,size_t r){return compressed[l]==compressed[r]?l<r:compressed[l]<compressed[r];});
            }
        }
    }
    //query [l,r)
    //return {freq,mode} ({頻度,元の配列における値})
    long long fold(int l, int r) {
        int bl = l/B + 1, br = (r-1)/B - 1;
        long long inv = 0;
        //同じbucketにl,rがあるとき
        if(bl > br + 1) {
            inv += prefix_inv[r-1];
            if(l%B) inv -= prefix_inv[l-1];
            long long sum = 0;
            for(size_t i: sqrt_bucket_sort_index[l/B]) {
                if(r <= i) continue;
                if(l <= i) sum++;
                else inv -= sum;
            }
        }
        else {
            inv += sqrt_bucket_inv[bl*M+br];
            inv += suffix_inv[l];
            inv += prefix_inv[r-1];
            size_t ml = bl*B;
            for(size_t i=l;i<ml;++i) {
                size_t& c = compressed[i];
                inv += sqrt_bucket_freq[br][c-1]-sqrt_bucket_freq[bl-1][c-1];
            }
            size_t mr = (br+1)*B;
            for(size_t i=mr;i<r;++i) {
                size_t& c = compressed[i];
                inv += (sqrt_bucket_size[br]-sqrt_bucket_freq[br][c])-(sqrt_bucket_size[bl-1]-sqrt_bucket_freq[bl-1][c]);
            }
            int ir = 0, nr = sqrt_bucket_sort_index[br+1].size();
            long long sum = 0;
            for(auto& xl:sqrt_bucket_sort_index[bl-1]) {
                if(xl < l) continue;
                for(;ir<nr;++ir) {
                    auto& xr = sqrt_bucket_sort_index[br+1][ir];
                    if(xr >= r) continue;
                    if(compressed[xl] > compressed[xr]) sum++;
                    else break;
                }
                inv += sum;
            }
        }
        return inv;
    }
};
