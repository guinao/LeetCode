#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int> > ans;
		if(nums.size() == 0)
			return ans;

		sort(nums.begin(), nums.end());

		bool flag = true;
		while(flag){
			flag = false;
			for(int i=nums.size()-1; i>0; --i){
				if(nums[i] > nums[i-1]){
					swap(nums[i], nums[i-1]);
					ans.push_back(nums);
					flag = true;
					break;
				}
			}
		}

		return ans;
	}
};