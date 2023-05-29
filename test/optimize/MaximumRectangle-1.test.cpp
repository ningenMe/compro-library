#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B"

#include <vector>
#include <iostream>
#include <stack>
using namespace std;
#include "../../lib/60-optimize/MaximumRectangle.cpp"

int main(void){
    cin.tie(0);ios::sync_with_stdio(false);
    int H,W; cin >> H >> W;
    vector<vector<int>> c(H,vector<int>(W,0));
    vector<vector<int>> s(H,vector<int>(W,0));    
    for(int i=0;i<H;++i) {
        for(int j=0;j<W;++j) {
            cin >> c[i][j];
        }
    }
    for(int j=0;j<W;++j) {
        s[0][j]=(!c[0][j]);
        for(int i=1;i<H;++i) {
            if(c[i][j]) s[i][j]=0;
            else s[i][j]=s[i-1][j]+1;
        }
    }
    long long ans = 0;
    for(int i=0;i<H;++i) {
        ans=max(ans,MaximumRectangle(s[i]));
    }
    cout << ans << endl;
	return 0;
}