#include <cstdio>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > ans;

		if(num.size() < 3)
			return ans;

		vector<pair<int, int> > pps;
		vector<int> nums(num);
		set<vector<int> > uniset;

		sort(nums.begin(), nums.end());
		for(auto i=nums.begin(); i!=nums.end(); ++i){
			for(auto j=i+1; j!=nums.end(); ++j){
				int k = *i + *j;
				if(-k < *j) continue;
				if(binary_search(nums.begin(), nums.end(), -k)){
					vector<int> v;
					v.push_back(*i);
					v.push_back(*j);
					v.push_back(-k);
					if(uniset.count(v) == 0){
						ans.push_back(v);
						uniset.insert(v);
					}
				}
			}
		}
		return ans;
	}
};

int main()
{
	Solution s;
	int A[] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	vector<int> a(A, A+109);
	vector<vector<int> > ans = s.threeSum(a);
	return 0;
}