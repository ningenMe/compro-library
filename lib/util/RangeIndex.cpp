/*
 * @title RangeIndex
 */
/*
 * @title RangeIndex
 */
class RangeIndex{
	int length;
public:
	RangeIndex(const int N) {
		for (length = 1; length <= N; length *= 2);
	}
	//[l,r)
	vector<int> range(int l,int r) {
		vector<int> res;
		for(l += length, r += length; l < r; l >>=1, r >>=1) {
			if(l&1) res.push_back(l++);
			if(r&1) res.push_back(--r);
		}
		return res;
	}
	// ranges that include x
	vector<int> include_range(int x) {
		vector<int> res;
        for(int i=x+length; i; i >>= 1) res.push_back(i);
		return res;
	}
	inline int operator[](int idx) {
		return idx+length;
	}
	inline size_t size(void){
		return 2*length;
	}
};
