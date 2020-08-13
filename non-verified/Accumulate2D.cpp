template<class T> class Accumulate2D {
	vector<vector<T>> acc;
public:
	//arg grid is 0-indexed 
	Accumulate2D(const vector<vector<T>>& grid)
	: acc(grid.size()+1,vector<T>(grid.front().size()+1)){
		for(int i = 1; i < acc.size(); ++i) {
			for(int j = 1; j < acc[i].size(); ++j) {
				acc[i][j]+=grid[i-1][j-1]+acc[i][j-1]+acc[i-1][j]-acc[i-1][j-1];
			}
		}
	}
	// 左上[y1,x1] 右下[y2,x2] 0-indexed
	inline T get(int y1,int x1,int y2,int x2) {
		y2++,x2++;
		return acc[y2][x2]-acc[y2][x1]-acc[y1][x2]+acc[y1][x1];
	}
};