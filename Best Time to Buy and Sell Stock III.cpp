#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if(n <= 1)
			return 0;

		vector<int> a0(n,INT_MIN), a1(n, 0), a2(n, INT_MIN), a3(n, 0);
		a0[0] = -prices[0];
		for(int i=1; i<n; ++i)
			a0[i] = max(a0[i-1], -prices[i]);
		for(int i=1; i<n; ++i)
			a1[i] = max(a1[i-1], prices[i]+a0[i-1]);
		for(int i=1; i<n; ++i)
			a2[i] = max(a2[i-1], a1[i-1]-prices[i]);
		for(int i=1; i<n; ++i)
			a3[i] = max(a3[i-1], a2[i-1]+prices[i]);
		// for(int i=0; i<n; ++i)
		//     printf("%d %d %d %d\n", a0[i], a1[i], a2[i], a3[i]);

		return max(a3[n-1], a1[n-1]);
	}
};