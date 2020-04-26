#include <bits/stdc++.h>
using namespace std;

class  Union_Find_Tree_Persistence{
public:
    vector<map<int,int>> parent;
    vector<int> rank,last;
    int cnt = 0;

    Union_Find_Tree_Persistence(int N):parent(N),rank(N,1),last(N,0){
        for(int i = 0; i < N; ++i) parent[i][0] = i;
    }

    //O(logN)
    int root(int n, int t) {
        return ( (t >= last[n] && parent[n][last[n]] != n) ? root(parent[n][last[n]], t) : n);
    }
 
    //O(logN)
    void unite(int n, int m) {
        n = root(n, cnt);
        m = root(m, cnt);
        cnt++;
        if(n == m) return;
        
        if(rank[n] < rank[m]) {
            parent[n][cnt] = m;
            last[n] = cnt;
        }
        else {
        parent[m][cnt] = n;
        last[m] = cnt;
        if(rank[n] == rank[m]) rank[n]++;
        }
    }
 
    bool same(int n, int m, int t) { 
        return root(n, t) == root(m, t);
    }
};

//verify https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h