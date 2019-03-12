#include <bits/stdc++.h>
using namespace std;


class Grid_Breadth_First_Dearch{
public:
	int H,W;
	vector<string> S;
	vector<vector<int>> dist;

	Grid_Breadth_First_Dearch(int H,int W):H(H),W(W),S(H),dist(H,vector<int>(W)){
		//do nothing
	}

	void solve(int sy,int sx){
		for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) dist[i][j] = -1;
		queue<pair<int,int>> q;
		dist[sy][sx] = 0;
		q.push({sy,sx});
		while(q.size()){
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			if(0 < y && S[y-1][x] == '.' && dist[y-1][x] == -1){
				dist[y-1][x] = dist[y][x] + 1;
				q.push({y-1,x});
			}
			if(y < H - 1 && S[y+1][x] == '.' && dist[y+1][x] == -1){
				dist[y+1][x] = dist[y][x] + 1;
				q.push({y+1,x});
			}
			if(0 < x && S[y][x-1] == '.' && dist[y][x-1] == -1){
				dist[y][x-1] = dist[y][x] + 1;
				q.push({y,x-1});
			}
			if(x < W - 1 && S[y][x+1] == '.' && dist[y][x+1] == -1){
				dist[y][x+1] = dist[y][x] + 1;
				q.push({y,x+1});
			}
		}
	}
};

//verify https://atcoder.jp/contests/agc014/tasks/agc014_c