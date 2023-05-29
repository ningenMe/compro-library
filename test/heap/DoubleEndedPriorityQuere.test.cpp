#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"

#include <iostream>
#include <queue>
using namespace std;
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/heap/DoubleEndedPriorityQuere.cpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N,Q; read(N);read(Q);
    DoubleEndedPriorityQuere<long long> pq;
    while(N--) {
        long long s; read(s); pq.push(s);
    }
    while(Q--) {
        int q; read(q); 
        if(q==0) {
            long long x; read(x);
            pq.push(x);
        }
        if(q==1) {
            long long x = pq.front(); pq.pop_front();
            cout << x << "\n";
        }
        if(q==2) {
            long long x = pq.back(); pq.pop_back();
            cout << x << "\n";
        }
    }
    return 0;
}
