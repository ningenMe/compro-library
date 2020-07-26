#define PROBLEM "https://yukicoder.me/problems/no/822"

#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;
#include "../../lib/segment/Rbst.cpp"

template<class T> struct NodePair {
	using TypeNode = T;
	inline static constexpr TypeNode unit_node = {0,0};
	inline static constexpr TypeNode func_node(TypeNode l,TypeNode c,TypeNode r){return {0,0};}
};

int main() {
    int N,K; cin >> N >> K;
    if(N+1 <= K){
		cout << "INF" << endl;
		return 0;
	}
    Rbst<NodePair<pair<int,int>>> st;
    for(int i = 0; i < (1<<20); ++i) {
        if((i&N) != N) continue;
        for(int j = -K; j <= K; ++j) {
            int a = i, b = i + j;
            if(a>b) swap(a,b);
            if(0<=b && b-a<=K && ((a&b)==N) && !st.count({a,b})) st.insert({a,b});
        }
    }
    cout << st.size() << endl;
    return 0;
}
