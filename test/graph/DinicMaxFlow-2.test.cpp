#define PROBLEM "https://yukicoder.me/problems/no/957"

#include <vector>
#include <iostream>
#include <queue>
using namespace std;
#include "../../lib/00-util/FastIO.cpp"
#include "../../lib/40-graph/DinicMaxFlow.cpp"

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int H,W; read(H),read(W);
    vector<vector<long long>> grid(H,vector<long long>(W));
    for(int i=0;i<H;++i) for(int j=0;j<W;++j) read(grid[i][j]);    
    vector<long long> R(H),C(W);
    for(int i=0;i<H;++i) read(R[i]);
    for(int j=0;j<W;++j) read(C[j]);    

    //行/列に対して「植える」:0, 「植えない」:1 ,と割り当てる
    //加えて、問題の性質的にi行目に関してはフローを流す前に貪欲に選んでしまう
    //そうすることで、辺の数が2乗オーダーから落ちる
    DinicMaxFlow<long long> di(H+W+2);
    int S = H+W, G = H+W+1;

    long long ans = 0;
    for(int i=0;i<H;++i) {
        //i行目を全部植えたときのコストを計算
        long long cost = 0;
        for(int j=0;j<W;++j) cost += grid[i][j];        
        //差分が正のとき
        if(R[i]-cost >= 0) ans += R[i]-cost;
        //差分が負のとき→ iが0のとき|cost-R[i]|失う
        else di.make_edge(i,G,abs(R[i]-cost));
    }
    for(int j=0;j<W;++j) {
        //j列目を全部植えたときのコスト
        long long cost = C[j];
        //jが0のとき|cost|得る
        ans += cost, di.make_edge(S,j+H,cost);
    }
    for(int i=0;i<H;++i) for(int j=0;j<W;++j) {
        //iが1,jが0のとき、grid[i][j]失う
        di.make_edge(j+H,i,grid[i][j]);
    }
    cout << ans - di.flow(S,G) << endl;
    return 0;
}