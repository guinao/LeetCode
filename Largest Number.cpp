#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(int x, int y)
{
	char sa[64], sb[64];
	sprintf(sa, "%d", x);
	sprintf(sb, "%d", y);

	string a = sa, b = sb;
	a.append(sb);
	b.append(sa);

	return a < b;
}

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end(), cmp);
		if(nums.back() == 0){
			return "0";
		}else{
			string ans;
			char buf[64];
			for(int i=nums.size()-1; i>=0; --i){
				sprintf(buf, "%d", nums[i]);
				ans.append(buf);
			}
			return ans;
		}
	}
};