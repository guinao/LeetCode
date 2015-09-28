#include <cstdio>
#include <vector>
#include <algorithm>

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> ans(nums.size(), 1);

		int cnt = 1;
		for(int i=1; i<ans.size(); ++i){
			cnt *= nums[i-1];
			ans[i] *= cnt;
		}

		cnt = 1;
		for(int i=ans.size()-1; i>0; --i){
			cnt *= nums[i];
			ans[i-1] *= cnt;
		}

		return ans;
	}
};