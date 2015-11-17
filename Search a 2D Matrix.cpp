#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int l = 0, r = matrix.size();
		while(l < r){
			int mid = ((long long)l+r) / 2;
			if(matrix[mid][0] == target)
				return true;
			if(matrix[mid][0] < target)
				l = mid;
			else 
				r = mid;
		}
		auto it = lower_bound(matrix[l].begin(), matrix[l].end(), target);
		return *it == target;
	}
};