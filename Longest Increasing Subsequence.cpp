#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> dp(nums.size()+1, INT_MAX);
		int ans = 0;
		for(int i=0; i<nums.size(); ++i){
			int pos = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
			dp[pos] = nums[i];
			if(pos+1 > ans)
				ans = pos + 1;
		}
		return ans;
	}
};