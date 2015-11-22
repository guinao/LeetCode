#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		candidates.resize(unique(candidates.begin(), candidates.end())-candidates.begin());
		vector<vector<int>> ans;
		vector<int> cur;
		dfs(ans, cur, candidates, target, 0);
		return ans;
	}

	void dfs(vector<vector<int>>& ans, vector<int>& cur, vector<int>& candi, int target, int pos){
		if(pos >= candi.size())
			return;

		if(target == candi[pos]){
			cur.push_back(candi[pos]);
			ans.push_back(cur);
			cur.pop_back();
		}else if(target > candi[pos]){
			dfs(ans, cur, candi, target, pos+1);
			cur.push_back(candi[pos]);
			dfs(ans, cur, candi, target-candi[pos], pos);
			cur.pop_back();
		}
	}
};

int main()
{
	Solution s;
	vector<int> v;
	int n, x;
	while(EOF != scanf("%d", &n)){
		for(int i=0; i<n; ++i){
			scanf("%d", &x);
			v.push_back(x);
		}
		scanf("%d", &x);
		vector<vector<int> > ans = s.combinationSum(v, x);
	}

	return 0;
}