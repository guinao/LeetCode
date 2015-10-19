#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution{
public:
	int minPathSum(vector<vector<int> >& grid)
	{
		if(grid.empty())
			return 0;

		int ans = 0;
		int n = grid.size();
		int m = grid[0].size();
		vector<int> dp(m);

		partial_sum(grid[0].begin(), grid[0].end(), dp.begin());

		for(int i=1; i<n; ++i){
			dp[0] = dp[0] + grid[i][0];
			for(int j=1; j<m; ++j){
				dp[j] = min(dp[j-1], dp[j]) + grid[i][j];
			}
		}

		return dp[m-1];
	}
};
