template<class T> inline vector<pair<T,T>> CircleIntersection(pair<T,T> p1, T r1, pair<T,T> p2, T r2, T eps = 1e-6) {
	vector<pair<T,T>> res;
	T x1 = p1.first;
	T y1 = p1.second;
	T x2 = p2.first;
	T y2 = p2.second;
	if(abs(x1-x2) < eps && abs(y1-y2) < eps && abs(r1-r2) < eps) return res;
	if(r1 + r2 + eps < sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2))) return res;
	T a = 2*(x1-x2);
	T b = 2*(y1-y2);
	T c = -(x1*x1-x2*x2) - (y1*y1-y2*y2) + (r1*r1 - r2*r2);
	T d = a*x1+b*y1+c;
	T e = (a*a+b*b)*r1*r1-d*d;
	if(e<0) return res;
	e = sqrt(e);
	T x3 = (-a*d+b*e)/(a*a+b*b) + x1;
	T y3 = (-b*d-a*e)/(a*a+b*b) + y1;
	T x4 = (-a*d-b*e)/(a*a+b*b) + x1;
	T y4 = (-b*d+a*e)/(a*a+b*b) + y1;
	res.push_back({x3,y3});
	res.push_back({x4,y4});
	return res;
}
//verify https://atcoder.jp/contests/abc157/tasks/abc157_f