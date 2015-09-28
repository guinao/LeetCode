#include <vector>
#include <functional>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		vector<int> ans(2,0);

		int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());

		diff &= -diff;

		for(int i=0; i<nums.size(); ++i){
			if(nums[i] & diff){
				ans[0] ^= nums[i];
			}else{
				ans[1] ^= nums[i];
			}
		}

		return ans;
	}
};