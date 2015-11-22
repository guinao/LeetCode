#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if(nums.empty())
			return 0;
		int pre = 0;
		int cnt = 1;
		for(int i=1; i<nums.size(); ++i){
			if(nums[i] == nums[pre] && cnt == 1){
				swap(nums[pre+1], nums[i]);
				++pre;
				cnt = 2;
			}else if(nums[i] > nums[pre]){
				swap(nums[pre+1], nums[i]);
				++pre;
				cnt = 1;
			}
		}
		return pre+1;
	}
};
