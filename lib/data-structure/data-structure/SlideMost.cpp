/*
 * @title SlideMost - スライド最小値/最大値
 * @docs md/data-structure/data-structure/SlideMost.md
 */
template<class Operator> class SlideMost {
    using TypeValue = typename Operator::TypeValue;
public:
    SlideMost(void){
    }
    vector<TypeValue> window(vector<TypeValue>& vec, const int& width){
        vector<TypeValue> res(vec.size());
        deque<TypeValue> deq;
        for(int i = 0; i < vec.size(); ++i) {
            while(deq.size() && Operator::func_compare(vec[deq.back()],vec[i]) ) deq.pop_back();
            deq.push_back(i);
            res[i] = vec[deq.front()];
            if(i+1>=width && deq.front()==i+1-width) deq.pop_front();
        }
        return res;
    }
};
//最小値クエリ
template<class T> struct ValueMin {
    using TypeValue = T;
    inline static constexpr bool func_compare(TypeValue l,TypeValue r){return l>=r;}
};
//最大値クエリ
template<class T> struct ValueMax {
    using TypeValue = T;
    inline static constexpr bool func_compare(TypeValue l,TypeValue r){return l<=r;}
};
