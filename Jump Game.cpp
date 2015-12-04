#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
		int lb = nums.size() - 1;
		for(int i=nums.size()-2; i>=0; --i){
			if(i+nums[i]>=lb)
				lb = i;
		}
		return lb == 0;
    }
};