#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_set<int> s;
		int i;
		for(i=0; i<nums.size() && i<k; ++i){
			if(s.find(nums[i]) == s.end())
				s.insert(nums[i]);
			else
				return true;
		}

		for(; i<nums.size(); ++i){
			if(s.find(nums[i]) == s.end())
				s.insert(nums[i]);
			else
				return true;
			s.erase(nums[i-k]);
		}
		return false;
	}
};