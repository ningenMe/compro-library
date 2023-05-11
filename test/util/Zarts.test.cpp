#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A"

#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <map>
using namespace std;
#include "../../lib/util/Zarts.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<long long> x(N*2),y(N*2);
    for(int i=0;i<N;++i) {
        cin >> x[i*2+0];
        cin >> y[i*2+0];
        cin >> x[i*2+1];
        cin >> y[i*2+1];
    }
    Zarts<long long> Zx(x),Zy(y);
    vector<vector<long long>> grid(Zy.size(),vector<long long>(Zx.size(),0));
    for(int i=0;i<N;++i) {
        long long x1=Zx.compressed[i*2+0],y1=Zy.compressed[i*2+0],x2=Zx.compressed[i*2+1],y2=Zy.compressed[i*2+1];
        grid[y1][x1]++;
        grid[y1][x2]--;
        grid[y2][x1]--;
        grid[y2][x2]++;
    }    
    for(int i=0;i<Zy.size();++i) {
        for(int j=1;j<Zx.size();++j) {
            grid[i][j] += grid[i][j-1];
        }
    }
    for(int j=0;j<Zx.size();++j) {
        for(int i=1;i<Zy.size();++i) {
            grid[i][j] += grid[i-1][j];
        }
    }
    long long ans = 0;
    for(int i=0;i+1<Zy.size();++i) {
        for(int j=0;j+1<Zx.size();++j) {
            if(grid[i][j]) ans += (Zy.get_value(i+1)-Zy.get_value(i))*(Zx.get_value(j+1)-Zx.get_value(j));
        }
    }
    cout << ans << endl;
	return 0;
}