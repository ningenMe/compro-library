#define PROBLEM "https://yukicoder.me/problems/no/1036"

#include <vector>
#include <iostream>
#include <stack>
using namespace std;
#include "../../../lib/data-structure/data-structure/Swag.cpp"

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
	long long N; cin >> N;
	vector<long long> A(N+1,1);
	for(int i = 0; i < N; ++i) cin >> A[i];
	Swag<NodeGcd<long long>> swag;
	long long ans=0;
	int r=0;
	swag.push(A[0]);
	for(int i=0; i<N; i++){
		while(r<i) {
			r++;
			swag.push(A[r]);
		}
		while(r<N){
			if(swag.fold()==1) break;
			r++;
			swag.push(A[r]);
		}
		ans+=N-r;
		swag.pop();
	}
	cout << ans << endl;
}