/*
 * @title ConvexHullTrick - 非単調CHT
 * @docs md/data-structure/convex-hull-trick/ConvexHullTrick.md
 */
template<class Operator> class ConvexHullTrick {
private:
	using TypeValue = typename Operator::TypeValue;
	using Line = pair<TypeValue,TypeValue>;
	struct NodePair {
		using TypeNode = Line;
		inline static constexpr TypeNode unit_node = {0,Operator::unit_value};
		inline static constexpr TypeNode func_node(TypeNode l,TypeNode c,TypeNode r){return {0,0};}
	};
	Rbst<NodePair> lines;

	//3直線に関してline2が必要か確認 (このとき a1 < a2 < a3が必要=rbstの順そのまま)
	inline int is_required(const Line& line1, const Line& line2, const Line& line3) {
		return Operator::func_compare((line2.second-line3.second)*(line2.first-line1.first),(line1.second-line2.second)*(line3.first-line2.first));
	}
	
	//y=ax+bの値
	inline TypeValue y(const Line line, TypeValue x) {
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
	void insert(const Line line) {
		int k=lines.lower_bound(line), flg=1;
		Line l,r;
		if(0 <= k-1) {
			l = lines.get(k-1);
			//lと傾きが同じなら、どちらかをerase
			if(l.first==line.first) {
				if(Operator::func_compare(l.second,line.second)) return;
				else lines.erase(l);
			}
		}
		if(k < lines.size()) {
			r = lines.get(k);
			//rと傾きが同じなら、どちらかをerase
			if(r.first==line.first) {
				if(Operator::func_compare(r.second,line.second)) return;
				else lines.erase(r);
			}	
		}
		//自身が必要か判定
		if(0 <= k-1 && k < lines.size() && !is_required(l,line,r)) return;
		//傾きが小さい側の不必要な直線を取り除く
		for(k=lines.lower_bound(line);k>=2&&!is_required(lines.get(k-2), lines.get(k-1), line);k=lines.lower_bound(line)) lines.erase(lines.get(k-1));
		//傾きが大きい側の不必要な直線を取り除く
		for(k=lines.lower_bound(line);k+1<lines.size()&&!is_required(line,lines.get(k),lines.get(k+1));k=lines.lower_bound(line)) lines.erase(lines.get(k));
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
	Line get_line(TypeValue x) {
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