#include <vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		long long lb = -1, ub = nums.size();
		while(lb+1 < ub){
			int mid = (lb+ub)/2;
			if(nums[mid] < target){
				lb = mid;
			}else if(nums[mid] == target){
				return mid;
			}else{
				ub = mid;
			}
		}
		return ub;
	}
};