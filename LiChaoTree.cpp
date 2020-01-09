
template<class T> class LiChaoTree{
	size_t length;
	T yInf;
	vector<double> coordinate;
	vector<pair<T,T>> node;
public:
	//取りうるxの値を先読みして渡す
	LiChaoTree(vector<T> x, T yInf) : yInf(yInf) {
		sort(x.begin(),x.end());
		double xInf = x.back() + 1;
		x.push_back(xInf);
		for (length = 1; length < x.size(); length *= 2);
		coordinate.resize(length, xInf);
		node.resize(2 * length, {0,yInf});
		for (int i = 0; i < x.size(); ++i) coordinate[i] = x[i];
	}
};