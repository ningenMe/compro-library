#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"

#include <vector>
#include <iostream>
#include <array>
#include <cassert>
#include <unordered_map>
using namespace std;
#include "../../../lib/data-structure/data-structure/PersistentQueue.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false); 
    int Q; cin >> Q;
    PersistentQueue<int> pq(1e9+7);
    for(int i=0;i<Q;++i) {
        int q; cin >> q;
        if(q==0) {
            int t,x; cin >> t >> x;
            pq.push(t,i,x);
        }
        else {
            int t; cin >> t;
            cout << pq.pop(t,i) << "\n";
        }
    }
    return 0; 
}