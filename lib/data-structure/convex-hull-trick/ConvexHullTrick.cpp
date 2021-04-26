/*
 * @title ConvexHullTrick - 非単調CHT
 * @docs md/data-structure/convex-hull-trick/ConvexHullTrick.md
 */
template<class Operator> class ConvexHullTrick {
private:
	using TypeValue = typename Operator::TypeValue;
	struct NodePair {
		using TypeNode = pair<TypeValue,TypeValue>;
		inline static constexpr TypeNode unit_node = {0,Operator::unit_value};
		inline static constexpr TypeNode func_node(TypeNode l,TypeNode c,TypeNode r){return {0,0};}
	};
	Rbst<NodePair> lines;

	//3直線に関してline2が必要か確認 (このとき a1 < a2 < a3が必要=rbstの順そのまま)
	inline int is_required(const pair<TypeValue,TypeValue>& line1, const pair<TypeValue,TypeValue>& line2, const pair<TypeValue,TypeValue>& line3) {
		return Operator::func_compare((line2.second-line3.second)*(line2.first-line1.first),(line1.second-line2.second)*(line3.first-line2.first));
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
	//ax+bを追加 armortized O(log(N))
	void insert(const pair<TypeValue,TypeValue> line) {
		int i,flg=1;
		i=lines.lower_bound(line);
		auto l=lines.get(i-1);
		auto r=lines.get(i);
		//lと傾きが同じなら、どちらかをerase
		if(flg && l.second!=Operator::unit_value && l.first==line.first) {
			if(Operator::func_compare(l.second,line.second)) return;
			else lines.erase(l),flg=0;
		}	
		//rと傾きが同じなら、どちらかをerase
		if(flg && r.second!=Operator::unit_value && line.first==r.first) {
			if(Operator::func_compare(r.second,line.second)) return;
			else lines.erase(r),flg=0;
		}	
		//自身が必要か判定
		if(flg && l.second!=Operator::unit_value && r.second!=Operator::unit_value && !is_required(l,line,r)) return;
		//傾きが小さい側の不必要な直線を取り除く
		for(i=lines.lower_bound(line);i>=2&&!is_required(lines.get(i-2), lines.get(i-1), line);i=lines.lower_bound(line)) lines.erase(lines.get(i-1));
		//傾きが大きい側の不必要な直線を取り除く
		for(i=lines.lower_bound(line);i+1<lines.size()&&!is_required(line,lines.get(i),lines.get(i+1));i=lines.lower_bound(line)) lines.erase(lines.get(i));
		lines.insert(line);
	}
	
	//O(log(N)^2)
	TypeValue get(TypeValue x) {
		int ng = -1, ok = (int)lines.size()-1, md;
		while (ok - ng > 1) {
			md = (ok + ng) >> 1;
			( Operator::func_compare(y(lines.get(md),x),y(lines.get(md+1),x)) ?ok:ng)=md;
		}
		return y(lines.get(ok),x);
	}

	//O(log(N)^2)
	pair<TypeValue,TypeValue> get_line(TypeValue x) {
		int ng = -1, ok = (int)lines.size()-1, md;
		while (ok - ng > 1) {
			md = (ok + ng) >> 1;
			( Operator::func_compare(y(lines.get(md),x),y(lines.get(md+1),x)) ?ok:ng)=md;
		}
		return lines.get(ok);
	}

	void print() {
		lines.print();
	}
};