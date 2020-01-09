
template<class Operator> class LiChaoTree{
	Operator Op;                                         //Operator 演算子、型、単位元を持つ
	using typeValue = decltype(Op.unitValue);            //valueの型
	struct domain{typeValue l,c,r;};
	size_t length;
	typeValue yInf;
	vector<typeValue> x;
	vector<pair<typeValue,typeValue>> node;
	vector<domain> range;

public:
	//取りうるxの値を先読みして渡す
	LiChaoTree(vector<typeValue> argx) {
		sort(argx.begin(),argx.end());
		argx.erase(unique(argx.begin(),argx.end()),argx.end());
		typeValue maxi = argx.back() + 1;
		for (length = 1; length < argx.size(); length *= 2);
		x.resize(length + 1, maxi);
		node.resize(2 * length, {0,Op.unitValue});
		range.resize(2 * length,  {maxi,maxi,maxi});
		for (int i = 0; i < argx.size(); ++i) x[i] = argx[i];
		for (int i = 0; i < argx.size(); ++i) range[i + length] = {x[i],-1,x[i+1]};
		for (int i = length-1; 1 <= i; --i) range[i] = {range[(i<<1)+0].l,range[(i<<1)+0].r,range[(i<<1)+1].r};
	}

	//return y = ax+b
	inline typeValue f(pair<typeValue,typeValue>& line,typeValue& t)	{
		return line.first*t + line.second;
	}

	void update(pair<typeValue,typeValue> line,int i = 1) {
		while(i < 2*length){
			typeValue& xl = range[i].l;
			typeValue& xc = range[i].c;
			typeValue& xr = range[i].r;
			int flgl = Op.funcCompare(f(line,xl),f(node[i],xl));
			int flgc = Op.funcCompare(f(line,xc),f(node[i],xc));
			int flgr = Op.funcCompare(f(line,xr),f(node[i],xr));
			if(flgl && flgr) node[i] = line;
			if(flgl == flgr) break;
			if((flgl && flgc) || (flgc && flgr)) swap(node[i],line);
			if((flgl &&!flgc) || (flgc && flgr)) i = (i<<1)+0;
			if((flgl && flgc) || (!flgc&& flgr)) i = (i<<1)+1;
		}
	}

	// t is in {x}
	typeValue get(typeValue t) {
		int i = (lower_bound(x.begin(),x.end(),t) - x.begin()) + length;
		typeValue res = Op.unitValue;
		for(;1<=i;i>>=1) if(Op.funcCompare(f(node[i],t),res)) res = f(node[i],t);
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
template<class typeValue> struct valueMin {
	typeValue unitValue = 1000;
	bool funcCompare(typeValue l,typeValue r){return l<r;}
};

// verify https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c

