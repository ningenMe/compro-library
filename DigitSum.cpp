#include <bits/stdc++.h>
using namespace std;

//DigitSum
long long DigitSum(long long N, long long K) {
    long long sum = 0;
    for (; N > 0; N /= K) sum += N % K;
    return sum;
}