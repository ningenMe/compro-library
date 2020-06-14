/*
 * @title SegmentTreeBeats
 */
template<class T> class SegmentTreeBeats {
	T inf;
	size_t length;
	size_t height;
	vector<T>
	node_max_first,node_max_second,count_max_first,
	node_min_first,node_min_second,count_min_first,
	node_sum,lazy_add,lazy_update;
	vector<pair<int,int>> range;

	inline void internal_chmax(int k, long long x) {
		node_sum[k] += (x - node_max_first[k]) * count_max_first[k];
		if(node_max_first[k] == node_min_first[k]) node_max_first[k] = node_min_first[k] = x;
		else if(node_max_first[k] == node_min_second[k]) node_max_first[k] = node_min_second[k] = x;
		else node_max_first[k] = x;
		if(lazy_update[k] != inf && x < lazy_update[k]) lazy_update[k] = x;
	}
	inline void internal_chmin(int k, long long x) {
		node_sum[k] += (x - node_min_first[k]) * count_min_first[k];
		if(node_max_first[k] == node_min_first[k]) node_max_first[k] = node_min_first[k] = x;
		else if(node_max_second[k] == node_min_first[k]) node_min_first[k] = node_max_second[k] = x;
		else node_min_first[k] = x;
		if(lazy_update[k] != inf && lazy_update[k] < x) lazy_update[k] = x;
	}
	inline void internal_add(int k, long long x) {
		node_max_first[k] += x;
		if(node_max_second[k] != -inf) node_max_second[k] += x;
		node_min_first[k] += x;
		if(node_min_second[k] != inf) node_min_second[k] += x;
		node_sum[k] += x * (range[k].second - range[k].first);
		(lazy_update[k] != inf ? lazy_update[k]:lazy_add[k]) += x;
	}
	inline void internal_update(int k, long long x) {
		node_max_first[k] = x; node_max_second[k] = -inf;
		node_min_first[k] = x; node_min_second[k] = inf;
		count_max_first[k] = count_min_first[k] = (range[k].second - range[k].first);
		node_sum[k] = x * (range[k].second - range[k].first);
		lazy_update[k] = x;
		lazy_add[k] = 0;
	}
	inline void propagate(int k) {
		if(length-1 <= k) return;
		if(lazy_update[k] != inf) {
			internal_update(2*k+0, lazy_update[k]);
			internal_update(2*k+1, lazy_update[k]);
			lazy_update[k] = inf;
			return;
		}
		if(lazy_add[k] != 0) {
			internal_add(2*k+0, lazy_add[k]);
			internal_add(2*k+1, lazy_add[k]);
			lazy_add[k] = 0;
		}
		if(node_max_first[k] < node_max_first[2*k+0]) {
			internal_chmax(2*k+0, node_max_first[k]);
		}
		if(node_min_first[2*k+0] < node_min_first[k]) {
			internal_chmin(2*k+0, node_min_first[k]);
		}
		if(node_max_first[k] < node_max_first[2*k+1]) {
			internal_chmax(2*k+1, node_max_first[k]);
		}
		if(node_min_first[2*k+1] < node_min_first[k]) {
			internal_chmin(2*k+1, node_min_first[k]);
		}
	}
	inline void merge(int k) {
		node_sum[k] = node_sum[2*k+0] + node_sum[2*k+1];
		if(node_max_first[2*k+0] < node_max_first[2*k+1]) {
			node_max_first[k] = node_max_first[2*k+1];
			count_max_first[k] = count_max_first[2*k+1];
			node_max_second[k] = max(node_max_first[2*k+0], node_max_second[2*k+1]);
		}
		else if(node_max_first[2*k+0] > node_max_first[2*k+1]) {
			node_max_first[k] = node_max_first[2*k+0];
			count_max_first[k] = count_max_first[2*k+0];
			node_max_second[k] = max(node_max_second[2*k+0], node_max_first[2*k+1]);
		}
		else {
			node_max_first[k] = node_max_first[2*k+0];
			count_max_first[k] = count_max_first[2*k+0] + count_max_first[2*k+1];
			node_max_second[k] = max(node_max_second[2*k+0], node_max_second[2*k+1]);
		}
		if(node_min_first[2*k+0] < node_min_first[2*k+1]) {
			node_min_first[k] = node_min_first[2*k+0];
			count_min_first[k] = count_min_first[2*k+0];
			node_min_second[k] = min(node_min_second[2*k+0], node_min_first[2*k+1]);
		}
		else if(node_min_first[2*k+0] > node_min_first[2*k+1]) {
			node_min_first[k] = node_min_first[2*k+1];
			count_min_first[k] = count_min_first[2*k+1];
			node_min_second[k] = min(node_min_first[2*k+0], node_min_second[2*k+1]);
		}
		else {
			node_min_first[k] = node_min_first[2*k+0];
			count_min_first[k] = count_min_first[2*k+0] + count_min_first[2*k+1];
			node_min_second[k] = min(node_min_second[2*k+0], node_min_second[2*k+1]);
		}
	}
public:
	SegmentTreeBeats(const int num,const T inf = (1LL<<60)) {
		vector<T> a(num,0);
		SegmentTreeBeats(a,inf);
	}
	SegmentTreeBeats(const vector<T>& a,const T inf = (1LL<<60)) : inf(inf){
		int num = a.size();
		for (length = 1,height = 0; length <= num; length *= 2, height++);
		node_max_first.resize(2*length);
		node_max_second.resize(2*length);
		count_max_first.resize(2*length);
		node_min_first.resize(2*length);
		node_min_second.resize(2*length);
		count_min_first.resize(2*length);
		node_sum.resize(2*length);
		range.resize(2*length);
		lazy_add.resize(2*length);
		lazy_update.resize(2*length);

		for(int i=0; i<2*length; ++i) lazy_add[i] = 0, lazy_update[i] = inf;
		for(int i = 0; i < length; ++i) range[i+length] = make_pair(i,i+1);
		for(int i = length - 1; i >= 0; --i) range[i] = make_pair(range[(i<<1)+0].first,range[(i<<1)+1].second);

		for(int i=0; i<num; ++i) {
			node_max_first[length+i] = node_min_first[length+i] = node_sum[length+i] = a[i];
			node_max_second[length+i] = -inf;
			node_min_second[length+i] = inf;
			count_max_first[length+i] = count_min_first[length+i] = 1;
		}
		for(int i=num; i<length; ++i) {
			node_max_first[length+i] = node_max_second[length+i] = -inf;
			node_min_first[length+i] = node_min_second[length+i] = inf;
			count_max_first[length+i] = count_min_first[length+i] = 0;
		}
		for(int i=length-1; i; --i) merge(i);
	}

	void range_chmin(int a, int b, long long x,int k = 1) {
		if(b <= range[k].first || range[k].second <= a || node_max_first[k] <= x) return;
		if(a <= range[k].first && range[k].second <= b && node_max_second[k] < x) {
			internal_chmax(k, x);
			return;
		}
		propagate(k);
		range_chmin(a, b, x, 2*k+0);
		range_chmin(a, b, x, 2*k+1);
		merge(k);
	}
	void range_chmax(int a, int b, long long x,int k = 1) {
		if(b <= range[k].first || range[k].second <= a || x <= node_min_first[k]) return;
		if(a <= range[k].first && range[k].second <= b && x < node_min_second[k]) {
			internal_chmin(k, x);
			return;
		}
		propagate(k);
		range_chmax(a, b, x, 2*k+0);
		range_chmax(a, b, x, 2*k+1);
		merge(k);
	}
	inline void range_add(int a, int b, long long x,int k = 1) {
		if(b <= range[k].first || range[k].second <= a) return;
		if(a <= range[k].first && range[k].second <= b) {
			internal_add(k, x);
			return;
		}
		propagate(k);
		range_add(a, b, x, 2*k+0);
		range_add(a, b, x, 2*k+1);
		merge(k);
	}
	inline void range_update(int a, int b, long long x,int k = 1) {
		if(b <= range[k].first || range[k].second <= a) return;
		if(a <= range[k].first && range[k].second <= b) {
			internal_update(k, x);
			return;
		}
		propagate(k);
		range_update(a, b, x, 2*k+0);
		range_update(a, b, x, 2*k+1);
		merge(k);
	}

	inline T get_max(int a, int b, int k = 1) {
		if(b <= range[k].first || range[k].second <= a) return -inf;
		if(a <= range[k].first && range[k].second <= b) return node_max_first[k];
		propagate(k);
		T vl = get_max(a, b, 2*k+0);
		T vr = get_max(a, b, 2*k+1);
		return max(vl, vr);
	}

	inline T get_min(int a, int b, int k = 1) {
		if(b <= range[k].first || range[k].second <= a) return inf;
		if(a <= range[k].first && range[k].second <= b) return node_min_first[k];
		propagate(k);
		T vl = get_min(a, b, 2*k+0);
		T vr = get_min(a, b, 2*k+1);
		return min(vl, vr);
	}

	inline T get_sum(int a, int b, int k=1) {
		if(b <= range[k].first || range[k].second <= a) return 0;
		if(a <= range[k].first && range[k].second <= b) return node_sum[k];
		propagate(k);
		T vl = get_sum(a, b, 2*k+0);
		T vr = get_sum(a, b, 2*k+1);
		return vl + vr;
	}
};