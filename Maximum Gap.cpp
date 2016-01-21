#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if(nums.size() < 2)
			return 0;

		int lb = nums[0], ub = nums[0];
		for(int i=0; i<nums.size(); ++i){
			lb = min(lb, nums[i]);
			ub = max(ub, nums[i]);
		}
		if(lb == ub)
			return 0;
		int range = (int)ceil((ub-lb)*1./(nums.size()-1));
		vector<int> bmin = vector<int>((ub-lb)/range+1, INT_MAX);
		vector<int> bmax = vector<int>((ub-lb)/range+1, INT_MIN);

		for(int i=0; i<nums.size(); ++i){
			int p = (nums[i] - lb) / range;
			bmin[p] = min(bmin[p], nums[i]);
			bmax[p] = max(bmax[p], nums[i]);
		}

		int pre = lb, ans = 0;
		for(int i=0; i<bmin.size(); ++i){
			if(bmin[i] != INT_MAX){
				ans = max(ans, bmin[i] - pre);
				pre = bmax[i];
			}
			// 			if(bmax[i] != INT_MIN){
			// 				ans = max(ans, bmax[i] - pre);
			// 				pre = bmax[i];
			// 			}
		}

		return ans;
	}
};