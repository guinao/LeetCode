#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> set;
		for(int i=0; i<nums.size(); ++i){
			set.insert(nums[i]);
		}
		int ans = 0;
		for(int i=0; i<nums.size(); ++i){
			if(set.find(nums[i]) != set.end()){
				int cnt = 0;
				for(int j=nums[i]; set.find(j)!=set.end(); ++j){
					set.erase(j);
					++cnt;
				}
				for(int j=nums[i]-1; set.find(j)!=set.end(); --j){
					set.erase(j);
					++cnt;
				}
				ans = max(ans, cnt);
			}
		}
		return ans;
	}
};