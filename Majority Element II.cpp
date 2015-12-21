#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int n1=0, n2=1;
		int cnt1=0,cnt2 = 0;

		for(int i=0; i<nums.size(); ++i){
			if(n1 == nums[i])
				++cnt1;
			else if(n2==nums[i])
				++cnt2;
			else if(cnt1 == 0)
				n1 = nums[i], ++cnt1;
			else if(cnt2 == 0)
				n2 = nums[i], ++cnt2;
			else
				--cnt1, --cnt2;
		}

		vector<int> ans;
		cnt1 = 0, cnt2 = 0;
		for(int i=0; i<nums.size(); ++i){
			if(n1 == nums[i])
				++cnt1;
			else if(n2 == nums[i])
				++cnt2;
		}
		if(cnt1 > nums.size() / 3)
			ans.push_back(n1);
		if(cnt2 > nums.size() / 3)
			ans.push_back(n2);

		return ans;
	}
};