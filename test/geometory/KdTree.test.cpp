#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C"

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#include "../../lib/geometory/KdTree.cpp"

int main(void){
    int N; 
    scanf("%d",&N);
    vector<pair<int,int>> points(N);
    for(int i=0;i<N;++i) {
        int x,y;
        scanf("%d%d",&x,&y);
        points[i]={x,y};
    }
    KdTree<int> kdtree(points);
    int Q;
    scanf("%d",&Q);
    while(Q--) {
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
        auto v = kdtree.points_in_range(x1,x2,y1,y2);
        for(auto& e:v) cout << e.idx << "\n";
        cout << "\n";
    }
    return 0;
}