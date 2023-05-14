/*
 * @title DoubleEndedPriorityQuere - 両端priority queue
 * @docs md/heap/DoubleEndedPriorityQuere.md
 */
template<class T> class DoubleEndedPriorityQuere {
	std::priority_queue<T> max_pq,poped_max_pq;
	std::priority_queue<T, vector<T>, greater<T> > min_pq, poped_min_pq;
public:
	DoubleEndedPriorityQuere() {
    }
	inline void push(const T &v) {
		max_pq.push(v);
		min_pq.push(v);
	}
	inline T front() {
        while(poped_min_pq.size() && min_pq.top()==poped_min_pq.top()) min_pq.pop(),poped_min_pq.pop();
		return min_pq.top();
	}
	inline T back() {
        while(poped_max_pq.size() && max_pq.top()==poped_max_pq.top()) max_pq.pop(),poped_max_pq.pop();
		return max_pq.top();
	}
	inline void pop_front() {
        while(poped_min_pq.size() && min_pq.top()==poped_min_pq.top()) min_pq.pop(),poped_min_pq.pop();
		poped_max_pq.push(min_pq.top());
		min_pq.pop();
	}
	inline void pop_back() {
        while(poped_max_pq.size() && max_pq.top()==poped_max_pq.top()) max_pq.pop(),poped_max_pq.pop();
		poped_min_pq.push(max_pq.top());
		max_pq.pop();
	}
	inline size_t size() const { return max_pq.size(); }
};
