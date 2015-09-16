#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if(nums.size() == 0)
			return 0;

		if(nums.size() == 1)
			return nums[0];

		vector<int> dp;
		dp.resize(nums.size()+1);
		dp[1] = nums[0];
		for(int i=1; i<nums.size(); ++i){
			dp[i+1] = max(dp[i], dp[i-1]+nums[i]);
		}

		return dp[nums.size()];
	}
};