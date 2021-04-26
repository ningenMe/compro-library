#define PROBLEM "https://yukicoder.me/problems/no/1074"

#include <vector>
#include <iostream>
#include <stack>
using namespace std;
#include "../../../lib/data-structure/segment-tree/SegmentTreeBeats.cpp"

int main(void){
    int N,M=20000; cin >> N;
    SegmentTreeBeats<long long> seg1(M),seg2(M),seg3(M),seg4(M);
    long long pre=0,sum=0;
    while(N--){
        int lx,ly,rx,ry;
        cin >> lx >> ly >> rx >> ry;
        seg1.range_chmax(0,rx,ry);
        seg2.range_chmax(0,rx,-ly);
        seg3.range_chmax(0,-lx,ry);
        seg4.range_chmax(0,-lx,-ly);
        sum=seg1.get_sum(0,M)+seg2.get_sum(0,M)+seg3.get_sum(0,M)+seg4.get_sum(0,M);
        cout << sum-pre << endl;
        pre=sum;
	}
	return 0;
}