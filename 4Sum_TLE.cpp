#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
private:
	void merge(set<vector<int> >& ans, vector<int>& nums, vector<pair<int,int>>& v1, vector<pair<int,int>>& v2)
	{
		for(int i=0; i<v1.size(); ++i){
			for(int j=0; j<v2.size(); ++j){
				if(v1[i].first!=v2[j].first && v1[i].first!=v2[j].second && v1[i].second!=v2[j].first && v1[i].second!=v2[j].second){
					vector<int> now;
					now.push_back(nums[v1[i].first]);
					now.push_back(nums[v1[i].second]);
					now.push_back(nums[v2[j].first]);
					now.push_back(nums[v2[j].second]);
					sort(now.begin(), now.end());
					ans.insert(now);
				}
			}
		}
	}

public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		set<vector<int>> ans;
		map<int, vector<pair<int,int>> > pp;
		vector<int> twosum;
		for(int i=0; i<nums.size(); ++i){
			for(int j=i+1; j<nums.size(); ++j){
				int tt = nums[i] + nums[j];
				if(pp.find(tt) == pp.end()){
					pp[tt] = vector<pair<int,int> >();
					twosum.push_back(tt);
				}
				pp[tt].push_back(make_pair(i, j));
			}
		}

		sort(twosum.begin(), twosum.end());
		for(int i=0; i<(int)twosum.size()-1; ++i){
			int first = twosum[i];
			auto it = lower_bound(twosum.begin()+i+1, twosum.end(), target-first);
			if(*it + first == target){
				merge(ans, nums, pp[first], pp[*it]);
			}
		}

		vector<vector<int>> trueans;
		for(auto i = ans.begin(); i!=ans.end(); ++i)
			trueans.push_back(*i);
		return trueans;
	}
};

//int main()
//{
//	Solution s;
//	int n;
//	vector<int> v;
//	while(EOF != scanf("%d", &n)){
//		int x;
//		v.resize(n);
//		for(int i=0; i<n; ++i){
//			scanf("%d", &x);
//			v[i] = x;
//		}
//		scanf("%d", &x);
//		printf("%d\n", s.fourSum(v, x).size());
//	}
//	return 0;
//}