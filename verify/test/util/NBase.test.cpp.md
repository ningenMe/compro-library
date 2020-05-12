---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/util/NBase.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#b474f495c8582ac5f92778a42ae814fa">test/util</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/util/NBase.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-13 02:48:46+09:00


* see: <a href="https://yukicoder.me/problems/no/699">https://yukicoder.me/problems/no/699</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/lib/util/NBase.cpp.html">NBase</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/699"

#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
#include "../../lib/util/NBase.cpp"

int main(void){
	int N; cin >> N;
    vector<long long> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];
    sort(A.begin(),A.end());
    vector<long long> B(N/2),C(N/2);
    long long ans = 0;
    for(int i = 0; i < (1<<N); ++i) {
        if(i&1 || NBase::digit_sum(i,2)!=N/2) continue;
        int b=0,c=0;
        for(int j = 0; j < N; ++j) {
            if(i&(1<<j)) B[b++]=A[j];
            else C[c++]=A[j];
        }
        do{
            long long sum = 0;
            for(int j = 0; j < N/2; ++j) {
                sum ^= (B[j]+C[j]);
            }
			ans = max(ans,sum);
        }while (next_permutation(B.begin(),B.end()));
    }
    cout << ans << endl;

	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/util/NBase.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/699"

#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
#line 1 "lib/util/NBase.cpp"
/*
 * @title NBase
 */
class NBase{
public:
	inline static vector<long long> translate(long long X,long long N) {
		assert(abs(N)>1);
		vector<long long> res;
		while(1) {
			long long b = (X%abs(N)+abs(N)) % abs(N);
			res.push_back(b);
			(X -= b) /= N;
			if(X==0) break;
		}
		return res;
	}
	//Digit Sum
	inline static constexpr long long digit_sum(long long N, long long K) {
		long long sum = 0;
		for (; N > 0; N /= K) sum += N % K;
		return sum;
	}
};
#line 9 "test/util/NBase.test.cpp"

int main(void){
	int N; cin >> N;
    vector<long long> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];
    sort(A.begin(),A.end());
    vector<long long> B(N/2),C(N/2);
    long long ans = 0;
    for(int i = 0; i < (1<<N); ++i) {
        if(i&1 || NBase::digit_sum(i,2)!=N/2) continue;
        int b=0,c=0;
        for(int j = 0; j < N; ++j) {
            if(i&(1<<j)) B[b++]=A[j];
            else C[c++]=A[j];
        }
        do{
            long long sum = 0;
            for(int j = 0; j < N/2; ++j) {
                sum ^= (B[j]+C[j]);
            }
			ans = max(ans,sum);
        }while (next_permutation(B.begin(),B.end()));
    }
    cout << ans << endl;

	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

