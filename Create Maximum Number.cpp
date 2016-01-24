#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
private:
	vector<int> getMax(vector<int>& nums, int n){
		vector<int> ret(n);
		int j = 0;
		for(int i=0; i<nums.size(); ++i){
			while(j>0 && ret[j-1]<nums[i] && nums.size()-i>n-j)
				--j;

			if(j < n)
				ret[j++] = nums[i];
		}
		return ret;
	}

	vector<int> merge(vector<int>& nums1, vector<int>& nums2){
		vector<int> ret;

		for(int i=0, j = 0; i<nums1.size()||j<nums2.size(); ){
			if(greater(nums1, i, nums2, j)){
				ret.push_back(nums1[i++]);
			}else{
				ret.push_back(nums2[j++]);
			}
		}

		return ret;
	}

	bool greater(const vector<int>& nums1, int i, const vector<int>& nums2, int j){
		while(i<nums1.size() && j<nums2.size() && nums1[i]==nums2[j])
			++i, ++j;

		if(j == nums2.size())
			return true;
		else if(i<nums1.size() && nums1[i]>nums2[j])
			return  true;
		else
			return false;
	}
public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<int> ans;
		int n = nums1.size(), m = nums2.size();
		for(int i=max(0, k-m); i<=min(k, n); ++i){
			vector<int> a1 = getMax(nums1, i);
			vector<int> a2 = getMax(nums2, k-i);
			vector<int> tmp = merge(a1, a2);
			if(greater(tmp, 0, ans, 0))
				ans = tmp;
		}
		return ans;
	}
};

int main()
{
	Solution s;
	int m, n, k;
	while(EOF != scanf("%d %d %d", &m, &n, &k)){
		vector<int> nums1(m), nums2(n);
		int x;
		for(int i=0; i<m; ++i){
			scanf("%d", &x);
			nums1[i] = x;
		}

		for(int i=0; i<n; ++i){
			scanf("%d", &x);
			nums2[i] = x;
		}
		s.maxNumber(nums1, nums2, k);
	}
	return 0;
}