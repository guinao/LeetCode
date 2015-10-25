#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int> > dp[2];
		int cur=0, pre=1;
		for(int i=0; i<nums.size(); ++i){
			dp[cur].clear();
			for(int j=0; j<dp[pre].size(); ++j){
				vector<int> nxt(dp[pre][j]);
				dp[cur].push_back(nxt);
				nxt.push_back(nums[i]);
				dp[cur].push_back(nxt);
			}
			dp[cur].push_back(vector<int>(1, nums[i]));
			swap(cur, pre);
		}
		dp[pre].push_back(vector<int>());
		return dp[pre];
	}
};