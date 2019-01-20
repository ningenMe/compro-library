#include <bits/stdc++.h>
using namespace std;

//Matrix_Repeated_Multiplication_Mod O((N^3)(logK))
vector<vector<long long>> Matrix_Repeated_Multiplication_Mod(vector<vector<long long>> mat, long long K, long long mod) {
    int N = mat.size();
    vector<vector<long long>> res(N, vector<long long>(N)), tmp(N, vector<long long>(N));

    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) res[i][j] = (i == j);
    for (; K > 0; K /= 2) {
        if (K & 1) {
            for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) tmp[i][j] = 0;
            for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) for (int k = 0; k < N; ++k) (tmp[i][j] += (mat[i][k] * res[k][j]) % mod) %= mod;
            res = tmp;
        }
        for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) tmp[i][j] = 0;
        for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) for (int k = 0; k < N; ++k) (tmp[i][j] += (mat[i][k] * mat[k][j]) % mod) %= mod;
        mat = tmp;
    }
    return res;
}

//verify  https://atcoder.jp/contests/dp/tasks/dp_r
