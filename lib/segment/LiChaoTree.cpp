template <typename Operator> class LiChaoTree{
	using TypeValue = typename Operator::TypeValue;
	using Line = pair<TypeValue,TypeValue>;
	vector<TypeValue> x;
	vector<Line> node;
	vector<int> clz;
	size_t length;
	const size_t bit;
public:	
	LiChaoTree(const size_t bit=30):bit(bit){
		//do nothing
	}
	inline void build(){
		sort(x.begin(),x.end());
		x.erase(unique(x.begin(),x.end()),x.end());
		TypeValue maxi = x.back() + 1;
		for (length = 1; length < x.size(); length *= 2);
		x.resize(length, maxi);
		node.resize(2*length,make_pair(0,Operator::unit_value));
		clz.resize(2*length,32);
		for(size_t i = 1; i < 2*length; ++i) {
			// for(int j = 0; j < bit; ++j) if(i&(1<<j)) clz[i] = 31-j;
			clz[i] = __builtin_clz(i);
		}
	}

	void x_push_back(TypeValue argx){
		x.push_back(argx);
	}

	//return y = ax+b
	inline static constexpr TypeValue f(Line& line,TypeValue& t)	{
		return line.first*t + line.second;
	}
		
	inline void update(Line line,int i = 1){
		while(i < 2*length){
			int l = (i<<(clz[i]-clz[length]))-length;
			int r = l + (length>>(31-clz[i])) - 1;
			int m = (l+r)>>1;
			bool flgl = Operator::func_compare(f(line,x[l]),f(node[i],x[l]));
			bool flgm = Operator::func_compare(f(line,x[m]),f(node[i],x[m]));
			bool flgr = Operator::func_compare(f(line,x[r]),f(node[i],x[r]));

			if(flgl&&flgr) node[i] = line;
			if(flgl==flgr) break;
			if(flgm) swap(node[i],line),swap(flgl,flgr);
			i = (i<<1)+flgr;
		}
	}
	inline void update(Line line,TypeValue l,TypeValue r){
		l = distance(x.begin(),lower_bound(x.begin(),x.end(),l))+length;
		r = distance(x.begin(),lower_bound(x.begin(),x.end(),r))+length;
		for(; l < r; l >>=1, r >>=1) {
			if(l&1) update(line,l),l++;
			if(r&1) --r,update(line,r);
		}
	}
	
	inline TypeValue get(TypeValue t){
		int i = distance(x.begin(),lower_bound(x.begin(),x.end(),t))+length;
		TypeValue res = Operator::unit_value;
		for(;1<=i;i>>=1) if(!Operator::func_compare(res,f(node[i],t))) res = f(node[i],t);
		return res;
	}
};

//最小値クエリ
template<class T> struct ValueMin {
	using TypeValue = T;
	inline static constexpr TypeValue unit_value = 3e18;
	inline static constexpr bool func_compare(TypeValue l,TypeValue r){return l<r;}
};
