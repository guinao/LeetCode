#include <cstdio>
#include <cstring>
#include <string>

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int> > ans;
		vector<int> mark(nums.size(), false);
		vector<int> cur;
		dfs(nums, mark, cur, ans);
		return ans;
	}

	void dfs(vector<int>& nums, vector<int>& mark, vector<int>& cur, vector<vector<int>>& ans)
	{
		bool finish = true;
		for(int i=0; i<mark.size(); ++i){
			if(!mark[i]){
				finish = false;
				mark[i] = true;
				cur.push_back(nums[i]);
				dfs(nums, mark, cur, ans);
				cur.pop_back();
				mark[i] = false;
			}
		}

		if(finish)
			ans.push_back(cur);
	}
};