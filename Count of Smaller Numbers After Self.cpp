#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
	vector<int> bit;

	int lowbit(int x){
		return x & (-x);
	}

	void add(int x){
		for(; x<bit.size(); x+=lowbit(x)){
			bit[x] += 1;
		}
	}

	int sum(int x){
		int ans = 0;
		for(; x>0; x-=lowbit(x))
			ans += bit[x];
		return ans;
	}

public:
	vector<int> countSmaller(vector<int>& nums) {
		if(nums.size()==0)
			return vector<int>();
		vector<int> ans(nums.size());
		vector<int> dup = nums;
		sort(dup.begin(), dup.end());
		dup.resize(distance(dup.begin(), unique(dup.begin(), dup.end())));

		for(int i=0; i<nums.size(); ++i)
			nums[i] = lower_bound(dup.begin(), dup.end(), nums[i]) - dup.begin() + 1;

		bit = vector<int>(dup.size()+1);
		add(nums.back());
		for(int i=2; i<=nums.size(); ++i){
			int x = nums.size() - i;
			ans[x] = sum(nums[x]-1);
			add(nums[x]);
		}

		return ans;
	}
};