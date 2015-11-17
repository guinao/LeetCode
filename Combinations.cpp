#include <vector>
using namespace std;

class Solution {
public:
	void dfs(vector<vector<int>> &ans, vector<int>& cur, int n, int k, int x)
	{
		if(k == 0){
			ans.push_back(cur);
		}else if(n == x+k){
			for(int i=x+1; i<=n; ++i)
				cur.push_back(i);
			ans.push_back(cur);
			for(int i=x+1; i<=n; ++i)
				cur.pop_back();
		}else{
			cur.push_back(x+1);
			dfs(ans, cur, n, k-1, x+1);
			cur.pop_back();
			dfs(ans, cur, n, k, x+1);
		}
	}

	vector<vector<int>> combine(int n, int k) {
		vector<vector<int> > ans;
		vector<int> tmp;
		dfs(ans, tmp, n, k, 0);
		return ans;
	}
};