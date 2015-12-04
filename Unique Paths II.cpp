#include <vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if(obstacleGrid.empty())
			return 0;
		vector<int> dp(obstacleGrid.size());
		int m = obstacleGrid[0].size();
		int n = obstacleGrid.size();
		for(int i=0; i<n; ++i){
			if(obstacleGrid[i][0] == 1)
				dp[0] = 0;
			for(int j=1; j<m; ++j){
				dp[j] += dp[j-1];
				if(obstacleGrid[i][j] == 1)
					dp[j] = 0;
			}
		}
		return dp.back();
	}
};