#include <bits/stdc++.h>
using namespace std;

//Digit Sum
long long Digit_Sum(long long N, long long K) {
    long long sum = 0;
    for (; N > 0; N /= K) sum += N % K;
    return sum;
}