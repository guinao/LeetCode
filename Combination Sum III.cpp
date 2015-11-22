#include <algorithm>
#include <vector>
using namespace std;

class Solution {
	void dfs(vector<vector<int>>& ans, vector<int>& cur, int pos, int k, int n){
		if(pos+k > 10)
			return;

		if(pos == n){
			cur.push_back(n);
			ans.push_back(cur);
			cur.pop_back();
		}else if(pos < n){
			cur.push_back(pos);
			dfs(ans, cur, pos+1, k-1, n-pos);
			cur.pop_back();
			dfs(ans, cur, pos+1, k, n);
		}
	}

public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> ans;
		vector<int> cur;
		dfs(ans, cur, 1, k, n);
		return ans;
	}
};