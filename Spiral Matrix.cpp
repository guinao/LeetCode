#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ans;
		if(matrix.empty())
			return ans;

		int left = 0;
		int right = matrix[0].size();
		int top = 0;
		int bottom = matrix.size();

		int directions[][2] = { {0,1}, {1,0}, {0, -1}, {-1,0} };
		int d = 0;

		int x = 0, y = 0;
		while(left < right && top < bottom){
			if(top<=x && x<bottom && left<=y && y<right){
				ans.push_back(matrix[x][y]);
			}else{
				if(y < left) --bottom;
				else if(y >= right) ++top;
				else if(x < top) ++left;
				else if(x >= bottom) --right;

				x -= directions[d][0];
				y -= directions[d][1];
				d = (d+1) % 4;
			}
			x += directions[d][0];
			y += directions[d][1];
		}

		return ans;
	}
};