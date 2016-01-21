#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if(coins.size() < 1)
			return -1;

		if(coins.size()==1){
			if(amount % coins[0] == 0)
				return amount / coins[0];
			else
				return -1;
		}

		vector<int> dp(amount+1, amount+1);
		dp[0] = 0;
		sort(coins.begin(), coins.end());

		for(int i=coins.size()-1; i>=0; --i){
			for(int j = coins[i]; j<=amount; j+=coins[i])
				dp[j] = min(dp[j], dp[j-coins[i]]+1);
		}

		if(dp[amount] <= amount)
			return dp[amount];
		else
			return -1;
	}
};