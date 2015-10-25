#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int ans = 0;
		if(height.size() < 2)
			return ans;

		int left = 0, right = height.size()-1;
		while(left < right){
			int cur = min(height[left], height[right])*(right-left);
			ans = max(cur, ans);
			if(height[left] < height[right])
				++left;
			else if(height[left] > height[right])
				--right;
			else
				++left, --right;
		}
		return ans;
	}
};