#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if(triangle.empty())
			return 0;

		vector<int> dp(triangle.size());
		int tmp = 0;

		dp[0] = triangle[0][0];
		for(int i=0; i<triangle.size(); ++i){
			tmp = dp[0];
			dp[0] += triangle[i][0];
			for(int j=1; j<triangle[i].size()-1; ++j){
				int t = dp[j];
				dp[j] = min(tmp, t) + triangle[i][j];
				tmp = t;
			}
			dp[triangle[i].size()-1] = tmp + triangle[i].back();
		}

		int ans = dp[0];
		for(int i=1; i<triangle.size(); ++i){
			ans = min(ans, dp[i]);
		}
		return ans;
	}
};