
template<class T> class Median{
	multiset<T, greater<>> stl;
	multiset<T> str;
    T init;

    // 要素の均衡を保つ関数
    inline void balance() {
        while(stl.size() < str.size()) {
            stl.insert(*str.begin());
            str.erase(str.begin());
        }
        while(stl.size() > str.size()+1) {
            str.insert(*stl.begin());
            stl.erase(stl.begin());
        }

        if(!str.size()) return;

        for(T tmpl = *stl.begin(),tmpr = *str.begin(); tmpl>tmpr; tmpl = *stl.begin(), tmpr = *str.begin()) {
            stl.erase(stl.begin());
            str.erase(str.begin());
            stl.insert(tmpr);
            str.insert(tmpl);
        }
    }
public:
    Median(T init):init(init){
        //do nothing
    }

    void insert(T val){
        stl.insert(val);
        balance();
    }

    int find(T val){
        return (stl.find(val)!=stl.end() || str.find(val)!=str.end());
    }

    void eraseItr(T val){
        auto itr = stl.find(val);
        if(itr != stl.end()) {
            stl.erase(itr);
            balance();
            return;
        }
        itr = str.find(val);
        if(itr != str.end()) {
            str.erase(itr);
            balance();
            return;
        }
    }

    void eraseVal(T val){
        stl.erase(val);
        str.erase(val);
        balance();
    }

    T get(){
        return (stl.empty()?init:*stl.begin());
    }

    size_t size(){
        return stl.size()+str.size();
    }
};

