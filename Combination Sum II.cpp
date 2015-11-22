#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
	void dfs(vector<vector<int>>& ans, vector<int>& cur, vector<int>& candi, int pos, int target)
	{
		if(pos >= candi.size())
			return;

		if(target == candi[pos]){
			cur.push_back(target);
			ans.push_back(cur);
			cur.pop_back();
		}else if(target > candi[pos]){
			cur.push_back(candi[pos]);
			dfs(ans, cur, candi, pos+1, target-candi[pos]);
			cur.pop_back();
			for(++pos; pos<candi.size(); ++pos)
				if(candi[pos] > candi[pos-1])
					break;
			dfs(ans, cur, candi, pos, target);
		}
	}

public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> ans;
		vector<int> cur;
		dfs(ans, cur, candidates, 0, target);
		return ans;
	}
};