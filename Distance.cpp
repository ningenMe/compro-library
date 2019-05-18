#include <bits/stdc++.h>
using namespace std;

//Euclidean distance
template<class T> T EucDist(T x1, T y1, T x2, T y2) {
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

//Chebyshev distance
template<class T> T ChebDist(T x1, T y1, T x2, T y2) {
    return max(abs(x1 - x2),abs(y1 - y2));
}

//Manhattan distance
template<class T> T ManhDist(T x1, T y1, T x2, T y2) {
    return abs(x1 - x2)+abs(y1 - y2);
}

double Distance_Point_to_Line(const double& x,const double& y,const double& x1,const double& y1,const double& x2,const double& y2){
	double a = y2 - y1, b = -(x2 - x1), c = -(y2-y1)*x1+(x2-x1)*y1;
	return abs(a*x+b*y+c)/sqrt(a*a+b*b);
}

//verify 