/*
 * @title ConvexHullTrick
 */
template<class Operator> class ConvexHullTrick {
private:
    using TypeValue = typename Operator::TypeValue;
    deque<pair<TypeValue,TypeValue>> lines;

	//cが必要かどうか判定する
    inline int isRequired(const pair<TypeValue,TypeValue>& l, const pair<TypeValue,TypeValue>& c, const pair<TypeValue,TypeValue>& r) {
        return (c.first - l.first) * (r.second - c.second) >= (c.second - l.second) * (r.first - c.first);
    }
    
	//k番目のax+bの値
    inline TypeValue value(int k, TypeValue x) {
        return lines[k].first * x + lines[k].second;
    }

public:
	ConvexHullTrick() {
		// do nothing
	} 

	//傾きの大きさが単調な順にax+bを追加
	void insert(TypeValue a, TypeValue b) {
		//insertの必要がないとき
        if(lines.size() && lines.back().first == a && !Operator::func_compare(lines.back().second,b)) return;
		// 直前の直線の傾きが同じ　かつ　それが必要ないとき
		if(lines.size() && lines.back().first == a && Operator::func_compare(b,lines.back().second)) lines.pop_back();
		//不必要な直線を取り除く
		while (lines.size() > 1 && isRequired(lines[lines.size()-2], lines[lines.size()-1], {a,b})) lines.pop_back();
		lines.push_back({a,b});
    }
    
    TypeValue get(TypeValue x) {
        int ng = -1, ok = (int)lines.size()-1, md;
        while (ok - ng > 1) {
            md = (ok + ng) >> 1;
            ( Operator::func_compare(value(md, x),value(md + 1, x)) ?ok:ng)=md;
        }
        return value(ok, x);
    }
    
    // クエリの単調性も成り立つ場合 (x が単調増加)
    TypeValue getMonotone(TypeValue x) {
        while (lines.size() >= 2 && value(0, x) >= value(1, x)) lines.pop_front();
        return lines[0].first * x + lines[0].second;
    }

};

//最小値クエリ
template<class T> struct ValueMin {
	using TypeValue = T;
	inline static constexpr bool func_compare(TypeValue l,TypeValue r){return l<r;}
};
//傾きがa1>=a2>=a3...となるようにinsertする

//最大値クエリ
template<class T> struct ValueMax {
	using TypeValue = T;
	inline static constexpr bool func_compare(TypeValue l,TypeValue r){return l>r;}
};
//傾きがa1<=a2<=a3...となるようにinsertする