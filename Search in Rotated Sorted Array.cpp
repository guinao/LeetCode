#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		if(nums.size == 0)
			return false;
		if(nums.front() <= nums.back())
			return binary_search(nums.begin(), nums.end(), target);

		int lb = 0, ub = nums.size()-1;

		while(lb <= ub){
			int mid = ((long long)lb + ub)/2;
			if(nums[mid] == target || nums[ub]==target || nums[lb] ==target)
				return true;
			else if(nums[mid] > target){
				if(nums[mid] > nums[lb]){
					if(nums[lb] > target){
						lb = mid+1;
						ub = ub-1;
					}else{
						lb = lb+1;
						ub = mid-1;
					}
				}else{
					lb = lb+1;
					ub = mid - 1;
				}
			}else{//nums[mid] < target
				if(nums[mid] > nums[lb]){
					lb = mid+1;
					ub = ub-1;
				}else{
					if(nums[lb] > target){
						lb = mid+1;
						ub = ub - 1;
					}else{
						lb = lb+1;
						ub = mid-1;
					}
				}
			}
		}

		return false;
	}
};