#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"

#include <iostream>
#include <array>
using namespace std;
#include "../../../lib/util/FastIO.cpp"
#include "../../../lib/data-structure/data-structure/WordSizeTreeSet.cpp"

/**
 * @url 
 * @est
 */ 
int main() {
    cin.tie(0);ios::sync_with_stdio(false);

    int N,Q; read(N);read(Q);
    string T; read(T);
    WordSizeTreeSet wsts;
    for(int i=0;i<N;++i) if(T[i]=='1') wsts.insert(i);
    while(Q--) {
        unsigned long long q,k;
        read(q); read(k);
        if(q==0) {
            wsts.insert(k);
        }
        if(q==1) {
            wsts.erase(k);
        }
        if(q==2) {
            cout << wsts.count(k) << "\n";
        }
        if(q==3) {
            unsigned long long t = wsts.next_lower_bound(k);
            long long v = (t==WordSizeTreeSet::max_length ? -1 : (long long)t);
            cout << v << "\n";
        }
        if(q==4) {
            unsigned long long t = wsts.prev_lower_bound(k);
            long long v = (t==WordSizeTreeSet::max_length ? -1 : (long long)t);
            cout << v << "\n";
        }
    }

    return 0;
}
