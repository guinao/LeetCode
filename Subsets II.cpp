#include <vector>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
	void gao(vector<vector<int> >& ans, vector<pair<int,int>>& uni, int n)
	{
		if(n >= uni.size()){
			return ;
		}

		int c = uni[n].first;
		int k = ans.size();
		for(int j=0; j<ans.size(); ++j){
			vector<int> cur(ans[j]);
			for(int i=1; i<=uni[n].second; ++i){
				cur.push_back(c);
				ans.push_back(cur);
			}
		}
	}

public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> ans;
		if(nums.empty())
			return ans;
		sort(nums.begin(), nums.end());
		vector<pair<int,int> > uni;
		int cnt = 0;
		for(int i=0; i<nums.size(); ++i){
			if(i!=0 && nums[i-1]!=nums[i]){
				uni.push_back(make_pair(nums[i-1], cnt));
				cnt = 0;
			}
			++cnt;
		}
		ans.push_back(vector<int>());
		gao(ans, uni, 0);
		return ans;
	}
};