/*
 * @title ZobristHash - Zobrist Hashing
 * @docs md/util/ZobristHash.md
 */
template<class T> class ZobristHash {
public:
    class Table {
        class XorShift64{
            unsigned long long s;
        public:
            XorShift64():s(17364570149295320492UL){}
            unsigned long long rand() {
                s = s ^ (s<<13);
                s = s ^ (s>>7);
                s = s ^ (s<<17);
                return s;
            }
        };
        XorShift64 xor_shift;
        map<T, unsigned long long> table;
    public:
        Table():xor_shift(){}
        void set(const T val) {
            if(table.count(val)) return;
            table[val] = xor_shift.rand();
        }    
        size_t count(const T val) const {
            return table.count(val);
        }
        unsigned long long get(const T val) {
            return table[val];
        }
    };
    class Set {
        Table& table;
        unsigned long long hash;
        set<unsigned long long> st;
    public:        
        Set(Table& table):table(table),hash(0){}
        void insert(const T val) {
            assert(table.count(val));
            unsigned long long key = table.get(val);
            if(st.count(key)) return;
            st.insert(key);
            hash ^= key;
        }
        void erase(const T val) {
            assert(table.count(val));
            unsigned long long key = table.get(val);
            if(!st.count(key)) return;
            st.erase(key);
            hash ^= key;
        }
        unsigned long long get() {
            return hash;
        }
    };
};