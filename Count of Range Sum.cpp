#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		vector<pair<long long,int> > ps;
		long long s = 0;
		ps.push_back(make_pair(0, -1));
		for(int i=0; i<nums.size(); ++i){
			s+=nums[i];
			ps.push_back(make_pair(s, i));
		}
		sort(ps.begin(), ps.end());

		int ans = 0;
		for(int i=0; i<ps.size(); ++i){
			pair<long long,int> pp(ps[i].first + lower, 0);
			int x1 = lower_bound(ps.begin(), ps.end(), pp)- ps.begin();
			pp = make_pair(ps[i].first+upper, ps.size());
			int x2 = upper_bound(ps.begin(), ps.end(), pp)- ps.begin();
			for(int j=x1; j<x2; ++j){
				if(ps[j].second > ps[i].second)
					++ans;
			}
		}

		return ans;
	}
};