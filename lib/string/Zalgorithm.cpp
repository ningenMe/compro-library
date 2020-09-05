/*
 * @title Zalgorithm
 */
class Zalgorithm{
    vector<int> zarray;
    template<class T> void init(const vector<T>& ar) {
        int N = ar.size();
        for(int i = 1, j = 0; i < N; ++i) {
            if(i + zarray[i - j] < j + zarray[j]) {
                zarray[i] = zarray[i - j];
            } 
            else {
                int k = max(0, j + zarray[j] - i);
                while(i + k < N && ar[k] == ar[i + k]) ++k;
                zarray[j = i] = k;
            }
        }
        zarray[0] = N;
    }
public:
    template<class T> Zalgorithm(const vector<T>& ar) : zarray(ar.size()) {
        init(ar);
    }
    Zalgorithm(const string& s) : zarray(s.size()) {
        vector<char> ar(s.size());
        for(int i=0; i<s.size(); ++i) ar[i]=s[i];
        init(ar);
    }
	inline int operator[](int idx) {
		return zarray[idx];
	}
};
