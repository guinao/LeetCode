#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& height) {
		stack<int> s;
		int ans = 0, i=0;
		while(i < height.size()){
			if(s.empty() || height[s.top()]<height[i])
				s.push(i++);
			else{
				int h = height[s.top()];
				s.pop();
				int l = s.empty()? 0 : s.top()+1;
				ans = max(ans, h*(i-l));
			}
		}
		while(!s.empty()){
			int h = height[s.top()];
			s.pop();
			int l = s.empty()? 0 : s.top()+1;
			ans = max(ans, h*((int)height.size()-l));
		}
		return ans;
	}
};