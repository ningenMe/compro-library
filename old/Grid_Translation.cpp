#include <bits/stdc++.h>
using namespace std;

class Grid_Translation {
	int H,W;
public:
	Grid_Translation(const int& H,const int& W):H(H),W(W){
		// do nothing
	}

	int YXtoN(const int& y,const int& x){
		return y*W+x;
	}

	int NtoY(const int& N){
		return N/W;
	}

	int NtoX(const int& N){
		return N%W;
	}
};

//verify https://codeforces.com/contest/1130/problem/C