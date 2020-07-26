/*
 * @title ConvexHullTrick
 */
template<class Operator> class ConvexHullTrick {
private:
	using TypeValue = typename Operator::TypeValue;
	struct NodePair {
		using TypeNode = pair<TypeValue,TypeValue>;
		inline static constexpr TypeNode unit_node = {0,0};
		inline static constexpr TypeNode func_node(TypeNode l,TypeNode c,TypeNode r){return {0,0};}
	};
	Rbst<NodePair> lines;

	//cが不必要かどうか判定する
	inline int is_not_required(const pair<TypeValue,TypeValue>& l, const pair<TypeValue,TypeValue>& c, const pair<TypeValue,TypeValue>& r) {
		return (c.first - l.first) * (r.second - c.second) >= (c.second - l.second) * (r.first - c.first);
	}
	
	//y=ax+bの値
	inline TypeValue y(const pair<TypeValue,TypeValue> line, TypeValue x) {
		return line.first * x + line.second;
	}

public:
	ConvexHullTrick() {
		// do nothing
	} 

	//ax+bを追加
	void insert(const TypeValue a, const TypeValue b) {
		insert({a,b});
	}
	void insert(const pair<TypeValue,TypeValue> line) {
		int i;
		i=lines.lower_bound(line);
		if(i) {
			auto l=lines.get(i-1);
			//傾きが同じものがあるとき、どちらかをerase
			if(l.first==line.first) {
				if(Operator::func_compare(l.second,line.second)) return;
				else lines.erase(l);
			}	
		}	
		i=lines.lower_bound(line);
		if(i!=lines.size()) {
			auto r=lines.get(i);
			//傾きが同じものがあるとき、どちらかをerase
			if(line.first==r.first) {
				if(Operator::func_compare(r.second,line.second)) return;
				else lines.erase(r);
			}	
		}
		//傾きが小さい側の不必要な直線を取り除く
		for(i=lines.lower_bound(line);i>=2&&is_not_required(lines.get(i-2), lines.get(i-1), line);i=lines.lower_bound(line)) lines.erase(lines.get(i-1));
		//傾きが大きい側の不必要な直線を取り除く
		for(i=lines.lower_bound(line);i+1<lines.size()&&is_not_required(lines.get(i+1), lines.get(i), line);i=lines.lower_bound(line)) lines.erase(lines.get(i));
		lines.insert(line);
	}
	
	TypeValue get(TypeValue x) {
		int ng = -1, ok = (int)lines.size()-1, md;
		while (ok - ng > 1) {
			md = (ok + ng) >> 1;
			( Operator::func_compare(y(lines.get(md),x),y(lines.get(md+1),x)) ?ok:ng)=md;
		}
		return y(lines.get(ok),x);
	}

	void print() {
		lines.print();
	}
};

//最小値クエリ
template<class T> struct ValueMin {
	using TypeValue = T;
	inline static constexpr bool func_compare(TypeValue l,TypeValue r){return l<r;}
};

//最大値クエリ
template<class T> struct ValueMax {
	using TypeValue = T;
	inline static constexpr bool func_compare(TypeValue l,TypeValue r){return l>r;}
};
