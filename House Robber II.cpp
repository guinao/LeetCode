#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
	int helper(vector<int>& nums, int l, int r){
		int pre = 0, cur = 0;
		for(int i=l; i<r; ++i){
			int temp = max(pre+nums[i], cur);
			pre = cur;
			cur = temp;
		}
		return cur;
	}

public:
	int rob(vector<int>& nums) {
		if(nums.empty())
			return 0;

		if(nums.size() == 1)
			return nums[0];

		return max(helper(nums, 0, nums.size()-1), helper(nums, 1, nums.size()));
	}
};