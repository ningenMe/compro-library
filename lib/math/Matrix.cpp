//Matrix_Repeated_Multiplication_Mod O((N^3)(logK))
template <class T,int N> class Matrix {
public:
    inline static constexpr array<array<T,N>,N> pow(array<array<T,N>,N> matrix, long long K){
        array<array<T,N>,N> res,tmp;
        for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) res[i][j] = (i == j);
        for (; K > 0; K /= 2) {
            if (K & 1) {
                for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) tmp[i][j] = 0;
                for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) for (int k = 0; k < N; ++k) tmp[i][j] += matrix[i][k] * res[k][j];
                res = tmp;
            }
            for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) tmp[i][j] = 0;
            for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) for (int k = 0; k < N; ++k) tmp[i][j] += matrix[i][k] * matrix[k][j];
            matrix = tmp;
        }
        return res;
    }
};

//verify  https://atcoder.jp/contests/dp/tasks/dp_r
