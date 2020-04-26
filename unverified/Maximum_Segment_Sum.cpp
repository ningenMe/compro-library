#include <bits/stdc++.h>
using namespace std;

//Maximum Segment Sum O(N)
template<class T> T Maximum_Segment_Sum(const vector<T> & ar, T inf) {
    T res = -inf, sum = 0;
    for (int i = 0; i < ar.size(); ++i) {
        sum = max(sum + ar[i], ar[i]);
        res = max(res, sum);
    }
    return res;
}

//verify 