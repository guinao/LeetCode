#include<vector>
using namespace std;

class Solution {
public:
	bool canWinNim(int n) {
		vector<bool> dp(n);
		dp[0] = dp[1] = dp[2] = true;
		for(int i=3; i<n; ++i){
			if(!(dp[i-2] && dp[i-1] && dp[i-3]))
				dp[i] = true;
		}
		return dp[n-1];
	}
};