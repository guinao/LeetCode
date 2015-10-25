#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int> > ans(n, vector<int>(n));

		if(n == 0)
			return ans;

		int top = 0, bottom = n;
		int left = 0, right = n;

		int cnt = 0;
		while(top < bottom && left < right){
			for(int i=left; i<right; ++i)
				ans[top][i] = ++cnt;
			++top;
			for(int i=top; i<bottom; ++i)
				ans[i][right-1] = ++cnt;
			--right;

			if(top>=bottom || left>=right) break;

			for(int i=right-1; i>=left; --i)
				ans[bottom-1][i] = ++cnt;
			--bottom;
			for(int i=bottom-1; i>=top; --i)
				ans[i][left] = ++cnt;
			++left;
		}
		return ans;
	}
};