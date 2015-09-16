#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> ans;
		char buf[128];
		if(nums.empty())
			return ans;

		int s=nums[0], t=nums[0];
		for(int i=1; i<nums.size(); ++i){
			if(nums[i]-t == 1){
				t = nums[i];
			}else{
				if(s == t){
					sprintf(buf, "%d", t);
				}else{
					sprintf(buf, "%d->%d", s, t);
				}
				ans.push_back(buf);
				s = t = nums[i];
			}
		}

		if(s == t){
			sprintf(buf, "%d", t);
		}else{
			sprintf(buf, "%d->%d", s, t);
		}
		ans.push_back(buf);

		return ans;
	}
};