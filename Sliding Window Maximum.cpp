#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> ans;
		deque<int> window;

		if(nums.size() == 0 || k==0)
			return ans;

		for(int i=0; i<k; ++i){
			while(!window.empty() && nums[i] >= nums[window.back()])
				window.pop_back();
			window.push_back(i);
		}
		ans.push_back(nums[window.front()]);
		for(int i=k; i<nums.size(); ++i){
			while(!window.empty() && window.front()<=i-k)
				window.pop_front();
			while(!window.empty() && nums[i] >= nums[window.back()])
				window.pop_back();
			window.push_back(i);
			ans.push_back(nums[window.front()]);
		}

		return ans;
	}
};