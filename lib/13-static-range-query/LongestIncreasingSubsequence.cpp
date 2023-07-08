/*
 * @title LongestIncreasingSubsequence - LIS
 * @docs md/13-static-range-query/LongestIncreasingSubsequence.md
 */
template<class T> class LongestIncreasingSubsequence {
    size_t length;
    size_t sz;
    vector<size_t> dp_key;
    vector<T> dp_val;
    vector<size_t> pre;
public:
    LongestIncreasingSubsequence(const vector<T> & ar, T inf=3e18) {
        length = ar.size();
        dp_key.resize(length, length);
        dp_val.resize(length, inf);
        pre.resize(length);
        for (int i = 0; i < length; ++i) {
            int key = lower_bound(dp_val.begin(), dp_val.end(), ar[i]) - dp_val.begin();
            dp_val[key] = ar[i];
            dp_key[key] = i;
            pre[i] = (key ? dp_key[key-1] : length);
        };
        sz = lower_bound(dp_val.begin(), dp_val.end(), inf) - dp_val.begin();
    }

    int size() {
        return sz;
    }

    vector<int> index() {
        vector<int> res;
        for(size_t idx = dp_key[sz-1]; idx != length; idx = pre[idx]) {
            res.push_back(idx);
        }
        reverse(res.begin(), res.end());
        return res;
    }
 
};
