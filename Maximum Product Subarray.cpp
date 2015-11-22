#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if(nums.empty())
			return 0;
		int m1 = 1;
		int maxv = nums[0];
		for(int i=0; i<nums.size(); ++i){
			m1 = m1==0? nums[i] : m1 * nums[i];
			maxv = max(m1, maxv);
		}
		m1 = 1;
		for(int i=nums.size()-1; i>=0; --i){
			m1 = m1==0? nums[i] : m1 * nums[i];
			maxv = max(m1, maxv);
		}
		return maxv;
	}
};