#include <cstring>

class Solution {
public:
	int uniquePaths(int m, int n) {
		int dp[2][128];
		int *cur=dp[0], *pre=dp[1];
		memset(dp, 0, sizeof dp);

		pre[0] = 1;
		for(int i=1; i<m; ++i){
			cur[0] = pre[0];
			for(int j=1; j<n; ++j)
				cur[j] = cur[j-1]+pre[j];
			int *tmp = cur;
			cur = pre;
			pre = cur;
		}

		return pre[n-1];
	}
};