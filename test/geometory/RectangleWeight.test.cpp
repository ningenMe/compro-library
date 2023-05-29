#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B"

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
#include "../../lib/70-geometory/RectangleWeight.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    int N; cin >> N;
    int L = 1010;
    RectangleWeight<int> rol(L,L);
    while(N--) {
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        rol.make_query(y1,x1,y2,x2,1);
    }
    rol.solve();
    int ans = 0;
    for(int i=0;i<L;++i) for(int j=0;j<L;++j) ans=max(ans,rol.get(i,j));
    cout << ans << endl;
	return 0;
}