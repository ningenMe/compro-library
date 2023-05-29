#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#include <iostream>
using namespace std;
#include "../../lib/30-math/FloorSum.cpp"

int main() {
    cin.tie(nullptr);ios::sync_with_stdio(false);
    int Q; cin >> Q;
    while(Q--){
        long long N,M,A,B; cin >> N >> M >> A >> B;
        cout << FloorSum(N,M,A,B) << "\n";
    }
    return 0;
}