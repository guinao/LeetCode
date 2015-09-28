#include <vector>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int ans = nums[0];
		int cnt = nums[0];
		for(int i=1; i<nums.size(); ++i){
			cnt = cnt >= 0? cnt+nums[i] : nums[i];
			if(ans < cnt)
				ans = cnt;
		}
		return ans;
	}
};
