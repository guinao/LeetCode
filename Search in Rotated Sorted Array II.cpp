#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int head = 0;
		for(int i=1; i<nums.size(); ++i){
			if(nums[i] < nums[i-1])
				head = i;
		}
		return binary_search(nums.begin(), nums.begin()+head, target)
			|| binary_search(nums.begin()+head, nums.end(), target);
	}
};