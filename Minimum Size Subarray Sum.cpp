#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int ans = nums.size() + 1;
		int sum = 0;
		int head = 0;
		for(int i=0; i<nums.size(); ++i){
			sum += nums[i];
			while(sum >= s){
				ans = min(i-head+1, ans);
				sum -= nums[head++];
			}
		}

		return ans>nums.size()? 0 : ans;
	}
};