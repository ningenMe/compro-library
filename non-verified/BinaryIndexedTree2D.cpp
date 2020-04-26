template<class T> class BinaryIndexedTree2D {
//抽象化してない　一点加算、区間総和のみ
	const int N,M;
	vector<vector<T>> node;

public:
    //1-indexed
    BinaryIndexedTree2D(const int& N,const int& M):N(N),M(M),node(N+1,vector<T>(M+1,0)){
        // do nothing
    }
 
    inline T getvar(const int i,const int j){
        T res = 0;
        for(int y=i;y>0;y-=(y&-y)) for(int x=j;x>0;x-=(x&-x)) {
			res += node[y][x];
        }
        return res;
    }
 
    // [x1,x2] * [y1,y2] 1-indexed
    inline T getvar(const int y1,const int y2,const int x1,const int x2){
        T res = 0;
		res += getvar(y1-1,x1-1);
        res -= getvar(y1-1,x2);
        res -= getvar(y2,x1-1);
        res += getvar(y2,x2);
        return res;
    }
 
    //add
    inline void update(const int i,const int j,T val){
        for(int y=i;y&&y<=N;y+=(y&-y)) for(int x=j;x&&x<=M;x+=(x&-x)) {
            node[y][x]+=val;
        }
    } 
};

//verify https://atcoder.jp/contests/abc130/tasks/abc130_e
