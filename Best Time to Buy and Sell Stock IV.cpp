#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		int ans = 0;

		if(k >= prices.size()/2)
			return fastSolve(k, prices);

		vector<vector<int> > dp(prices.size(), vector<int>(k+1,0));

		for(int j=1; j<=k; ++j){
			int tempMax = -prices[0];
			for(int i=1; i<prices.size(); ++i){
				dp[i][j] = max(dp[i-1][j], tempMax+prices[i]);
				tempMax = max(tempMax, dp[i-1][j-1]-prices[i]);
			}
		}
		
		for(int i=0; i<=k; ++i)
			ans = max(ans, dp[prices.size()][i]);

		return ans;
	}

	int fastSolve(int k, vector<int>& prices) {
		int ans = 0;
		for(int i=1; i<prices.size(); ++i){
			ans += max(prices[i] - prices[i-1], 0);
		}
		return ans;
	}
};