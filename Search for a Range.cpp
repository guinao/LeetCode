#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ans(2,-1);
//		if(nums[0] > target || nums.back()<target)
//			return ans;
		int lb = lower_bound(nums.begin(), nums.end(), target)-nums.begin();
		int ub = upper_bound(nums.begin(), nums.end(), target)-nums.begin()-1;
		while(0<=lb && lb<nums.size() && nums[lb] < target) ++lb;
		while(0<=ub && ub<nums.size() && nums[ub] > target) --ub;
		if(lb<nums.size() && ub>=0 && lb<=ub)
			ans[0] = lb, ans[1] = ub;
		return ans;
	}
};