#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		if(nums.size() <= 1)
			return 0;

		vector<int> dp(nums.size()+1, INT_MAX);
		dp[0] = 0;

		for(int i=0; i<nums.size(); ++i){
			int k = lower_bound(dp.begin(), dp.end(), i)-dp.begin();
			if(dp[k+1] == INT_MAX)
				dp[k+1] = i + nums[i];
			else
				dp[k+1] = max(dp[k+1], i+nums[i]);
			dp[k+1] = max(dp[k], dp[k+1]);
		}

		return lower_bound(dp.begin(), dp.end(), nums.size()-1) -  dp.begin();
	}
};