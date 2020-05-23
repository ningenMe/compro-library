/*
 * @title Eratosthenes
 * @docs md/math/Eratosthenes.md
 */
inline static vector<int> Eratosthenes(int N) {
    vector<int> res(N + 1, 1);
    res[0] = res[1%(N+1)] = 0;
    for (int i = 1; i*i <= N; i++) if (res[i]) for (int j = 2 * i; j <= N; j += i) res[j] = 0;
    return res;
}
