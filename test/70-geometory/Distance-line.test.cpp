#define PROBLEM "https://yukicoder.me/problems/no/1041"

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#include "../../lib/70-geometory/Distance.cpp"

int main(void){
    int N; cin >> N;
    vector<double> x(N),y(N);
    for(int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i];
    }
    int ans = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = i+1; j < N; ++j) {
            int cnt = 2;
            for(int k = 0; k < N; ++k){
                if(k==i || k == j) continue;
                if(Distance<long double>::between_point_and_line(x[i],y[i],x[j],y[j],x[k],y[k]) < 1e-3 ) cnt++;
            }
            ans = max(ans,cnt);
        }
    }
    cout << ans << endl;
	return 0;
}