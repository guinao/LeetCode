#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int min3(int a, int b, int c){
		return min(min(a,b), c);
	}

	int maximalSquare(vector<vector<char>>& matrix){
		if(matrix.empty())
			return 0;

		int n = matrix.size();
		int m = matrix[0].size();
		int ans = 0;
		vector<int> dp(m+1, 0);

		for(int i=0; i<n; ++i){
			dp[m] = dp[0];
			dp[0] = matrix[i][0] - '0';
			ans = max(dp[0], ans);
			for(int j=1; j<m; ++j){
				int t = (min3(dp[j], dp[j-1], dp[m])+1)*(matrix[i][j] - '0');
				dp[m] = dp[j];
				dp[j] = t;
				ans = max(ans, dp[j]);
			}
		}

		return ans * ans;
	}
};