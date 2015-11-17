#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int,int> m, m2;
		vector<int> ans(2);
		for(int i=0; i<nums.size(); ++i){
			if(m.find(nums[i]) == m.end())
				m[nums[i]] = i;
			else
				m2[nums[i]] = i;
		}

		sort(nums.begin(), nums.end());

		for(int i=0; i<nums.size()-1; ++i){
			int first = nums[i];
			auto it = lower_bound(nums.begin()+i+1, nums.end(), target-first);
			if(*it + first == target){
				if(*it != first)
					ans[0] = m[first], ans[1] = m[*it];
				else
					ans[0] = m[first], ans[1] = m2[first];
				if(ans[0] > ans[1])
					swap(ans[0], ans[1]);
				break;
			}
		}
		return ans;
	}
};