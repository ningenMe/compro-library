#define PROBLEM "https://yukicoder.me/problems/no/1058"

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include "../../lib/30-math/Eratosthenes.cpp"

int main() {
    long long N;
    cin >> N;
    auto E = Eratosthenes(200000);
    vector<long long> A;
    for(int i = 100001; i < 100100; ++i) {
        if(E[i]) A.push_back(i);
    }
    vector<long long> B={1};
    for(auto& e1:A) for(auto& e2:A) B.push_back(e1*e2);
    sort(B.begin(),B.end());
    unique(B.begin(),B.end());
    cout << B[N-1] << endl;
    return 0;
}
