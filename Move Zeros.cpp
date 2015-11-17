#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int digit = 0, zero = 0;
		while(zero < nums.size()){
			if(nums[zero] != 0)
				++zero;
			else{
				for(digit=zero+1; digit<nums.size(); ++digit)
					if(nums[digit] != 0)
						break;
				if(digit < nums.size())
					swap(nums[digit], nums[zero]);
				zero = digit + 1;
			}
		}
	}
};