#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;
#include "../../lib/geometory/Argument.cpp"

int main(void){
    int N; cin >> N;
    vector<pair<long long,long long>> points(N);
    for(int i = 0; i < N; ++i) {
        long long a,b; cin >> a >> b;
        points[i] = {a,b};
    }
    auto idx = Argument::sort_by_atan2l<long long>(points);
    for(int i = 0; i < N; ++i) {
        cout << points[idx[i]].first << " " << points[idx[i]].second << endl; 
    }
	return 0;
}