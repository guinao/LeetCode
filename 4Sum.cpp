#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		vector<vector<int> > ans;
		vector<int> rec(4);
		for(int i=0; i<nums.size(); ++i){
			int a = nums[i];
			for(int j=i+1; j<nums.size(); ++j){
				int b = nums[j];
				int lb = j+1;
				int ub = (int)nums.size() - 1;
				while(lb<ub){
					int val = a+b+nums[lb]+nums[ub];
					if(val == target){
						rec[0] = a;
						rec[1] = b;
						rec[2] = nums[lb];
						rec[3] = nums[ub];
						ans.push_back(rec);
						while(lb < ub){
							if(nums[lb+1]==nums[lb])
								++lb;
							else
								break;
						}
						++lb;
						while(lb < ub){
							if(nums[ub-1]==nums[ub])
								--ub;
							else
								break;
						}
						--ub;
					}else if(val > target){
						--ub;
					}else{
						++lb;
					}
				}
			}
		}
		return ans;
	}
};