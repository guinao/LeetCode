#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int r = nums.size()-1;
		while(r>0){
			if(nums[r] > nums[r-1])
				break;
			--r;
		}
		int lb=r, ub = nums.size()-1;
		while(lb < ub){
			swap(nums[lb], nums[ub]);
			++lb,--ub;
		}
		if(r>0){
			--r;
			lb = r, ub = nums.size()-1;
			while(lb+1 < ub){
				int mid = ((long long)lb+ub) / 2;
				if(nums[mid]>nums[r])
					ub = mid;
				else
					lb = mid;
			}
			swap(nums[r], nums[ub]);
		}
	}
};