template<class Operator> class LiChaoTree{
	using TypeValue = typename Operator::TypeValue;
	struct domain{TypeValue l,c,r;};
	size_t length;
	TypeValue yInf;
	vector<TypeValue> x;
	vector<pair<TypeValue,TypeValue>> node;
	vector<domain> range;

public:
	//取りうるxの値を先読みして渡す
	LiChaoTree(vector<TypeValue> argx) {
		sort(argx.begin(),argx.end());
		argx.erase(unique(argx.begin(),argx.end()),argx.end());
		TypeValue maxi = argx.back() + 1;
		for (length = 1; length < argx.size(); length *= 2);
		x.resize(length + 1, maxi);
		node.resize(2 * length, {0,Operator::unit_value});
		range.resize(2 * length,  {maxi,maxi,maxi});
		for (int i = 0; i < argx.size(); ++i) x[i] = argx[i];
		for (int i = 0; i < argx.size(); ++i) range[i + length] = {x[i],-1,x[i+1]};
		for (int i = length-1; 1 <= i; --i) range[i] = {range[(i<<1)+0].l,range[(i<<1)+0].r,range[(i<<1)+1].r};
	}

	//return y = ax+b
	inline TypeValue f(pair<TypeValue,TypeValue>& line,TypeValue& t)	{
		return line.first*t + line.second;
	}

	//直線追加　ax + b  O(logN)
	void update(pair<TypeValue,TypeValue> line,int i = 1) {
		while(i < 2*length){
			TypeValue& xl = range[i].l;
			TypeValue& xc = range[i].c;
			TypeValue& xr = range[i].r;
			int flgl = Operator::funcCompare(f(line,xl),f(node[i],xl));
			int flgc = Operator::funcCompare(f(line,xc),f(node[i],xc));
			int flgr = Operator::funcCompare(f(line,xr),f(node[i],xr));
			if(flgl && flgr) node[i] = line;
			if(flgl == flgr) break;
			if((flgl && flgc) || (flgc && flgr)) swap(node[i],line);
			if((flgl &&!flgc) || (flgc && flgr)) i = (i<<1)+0;
			if((flgl && flgc) || (!flgc&& flgr)) i = (i<<1)+1;
		}
	}

	//線分追加　y = ax + b [l,r) O((logN)^2)
	void update(pair<TypeValue,TypeValue> line, TypeValue L, TypeValue R) {
		int l = (lower_bound(x.begin(),x.end(),L) - x.begin()) + length;
		int r = (lower_bound(x.begin(),x.end(),R) - x.begin()) + length - 1;
		for(r++; l < r; l >>=1, r >>=1) {
			if(l&1) update(line,l),l++;
			if(r&1) --r,update(line,r);
		}
	}

	//値を取得 t is in {x}
	TypeValue get(TypeValue t) {
		int i = (lower_bound(x.begin(),x.end(),t) - x.begin()) + length;
		TypeValue res = Operator::unit_value;
		for(;1<=i;i>>=1) if(Operator::funcCompare(f(node[i],t),res)) res = f(node[i],t);
		return res; 
	}

	void print(){
		// cout << "{ " << get(0,1);
		// for(int i = 1; i < length; ++i) cout << ", " << get(i,i+1);
		// cout << " }" << endl;
		for(int i = 1,j = 1; i < 2*length; ++i) {
			cout << node[i] << " ";
			if(i==((1<<j)-1) && ++j) cout << endl;
		}
		for(int i = 1,j = 1; i < 2*length; ++i) {
			cout << "{" << range[i].l << ", " << range[i].c << ", " << range[i].r << "}" << " ";
			if(i==((1<<j)-1) && ++j) cout << endl;
		}
	}
};

//最小値クエリ
template<class T> struct valueMin {
	using TypeValue = T;
	inline static constexpr TypeValue unit_value = 3e18;
	inline static constexpr bool funcCompare(TypeValue l,TypeValue r){return l<r;}
};