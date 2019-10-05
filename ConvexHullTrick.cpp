
template<class T> class ConvexHullTrick {
private:
    deque<pair<T,T>> lines;
	function<int(T,T)> funcCompare;

	//cが必要かどうか判定する
    inline int isRequired(const pair<T,T>& l, const pair<T,T>& c, const pair<T,T>& r) {
        return (c.first - l.first) * (r.second - c.second) >= (c.second - l.second) * (r.first - c.first);
    }
    
	//k番目のax+bの値
    inline T value(int k, T x) {
        return lines[k].first * x + lines[k].second;
    }

public:
	ConvexHullTrick(function<int(T,T)> funcCompare) : funcCompare(funcCompare) {
		// do nothing
	} 

	//傾きの大きさが単調な順にax+bを追加
	void insert(T a, T b) {
		//insertの必要がないとき
        if(lines.size() && lines.back().first == a && lines.back().second <= b) return;
		// 直前の直線の傾きが同じ　かつ　それが必要ないとき
		if(lines.size() && lines.back().first == a && lines.back().second > b ) lines.pop_back();
		//不必要な直線を取り除く
		while (lines.size() > 1 && isRequired(lines[lines.size()-2], lines[lines.size()-1], {a,b})) lines.pop_back();
		lines.push_back({a,b});
    }
    
    T get(T x) {
        int ng = -1, ok = (int)lines.size()-1, md;
        while (ok - ng > 1) {
            md = (ok + ng) >> 1;
            ( funcCompare(value(md, x),value(md + 1, x)) ?ok:ng)=md;
        }
        return value(ok, x);
    }
    
    // クエリの単調性も成り立つ場合 (x が単調増加)
    T getMonotone(T x) {
        while (lines.size() >= 2 && value(0, x) >= value(1, x)) lines.pop_front();
        return lines[0].first * x + lines[0].second;
    }

};

//最小値クエリの時
//ConvexHullTrick<ll> cht([&](ll l, ll r){return l < r;});
//傾きがa1>=a2>=a3...となるようにinsertする

//最大値クエリの時
//ConvexHullTrick<ll> cht([&](ll l, ll r){return l > r;});
//傾きがa1<=a2<=a3...となるようにinsertする

//verify
//https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c
